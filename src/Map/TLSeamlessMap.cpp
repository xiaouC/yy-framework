#include "Map/TLSeamlessMap.h"
#include "Map/TLMapBlock.h"
#include "MC/AssetsManager.h"
#include "protocol/src/map.pb.h"

const float g_fLoadNewBlockFlag = 0.2f;
TLSeamlessMap::TLSeamlessMap( const std::string& strSeamlessMapFile, float x, float y )
: m_fCurX(x)
, m_fCurY(y)
, m_nBlockRow(0)
, m_nBlockCol(0)
, m_nGridWidth(0)
, m_nGridHeight(0)
, m_nBlockWidth(0)
, m_nBlockHeight(0)
, m_nNextBlockIndex(0)
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
    m_strSeamlessMapFile = "map/" + strSeamlessMapFile;
#else
    m_strSeamlessMapFile = strSeamlessMapFile;
#endif

    for( int i=BLOCK_INDEX_CENTER; i < BLOCK_INDEX_MAX; ++i )
    {
        m_kBlocks[i].pMapBlock = NULL;
        m_kBlocks[i].x = 0.0f;
        m_kBlocks[i].y = 0.0f;

        m_kOldBlocks[i].pMapBlock = NULL;
        m_kOldBlocks[i].x = 0.0f;
        m_kOldBlocks[i].y = 0.0f;
    }
}

TLSeamlessMap::~TLSeamlessMap()
{
    std::list<BlockInfo*>::iterator iter = m_listAllBlocks.begin();
    std::list<BlockInfo*>::iterator iter_end = m_listAllBlocks.end();
    for( ; iter != iter_end; ++iter )
    {
        BlockInfo* pBlockInfo = (*iter);
        delete pBlockInfo;
    }
    m_listAllBlocks.clear();
}

TLSeamlessMap* TLSeamlessMap::create( const std::string& strSeamlessMapFile, float x, float y )
{
    std::string strTemp = strSeamlessMapFile;

	int nLength = strSeamlessMapFile.length();
	if( nLength > 3 )
	{
		if( strSeamlessMapFile.at( nLength - 1 ) == 'm' &&
			strSeamlessMapFile.at( nLength - 2 ) == 's' &&
			strSeamlessMapFile.at( nLength - 3 ) == '.' )
		{
			strTemp = strSeamlessMapFile.substr( 0, nLength - 3 );
		}
	}

    //unsigned int nPos = strSeamlessMapFile.find_last_of( ".sm" );
    //if( nPos != std::string::npos )
    //    strTemp = strSeamlessMapFile.substr( 0, nPos - 2 );

    TLSeamlessMap * pRet = new TLSeamlessMap( strTemp, x, y );
    if( pRet && pRet->init() )
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

TLSeamlessMap* TLSeamlessMap::newSeamlessMap( const std::string& strSeamlessMapFile, const std::string& strBlockName, int nBlockRow, int nBlockCol, int nGridWidth, int nGridHeight, const std::string& strMaterial )
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
    std::string strSMFileName = strSeamlessMapFile + ".sm";

    FILE* fp = fopen( strSMFileName.c_str(), "wb" );
    if( fp == NULL )
        return NULL;

    framework::SeamlessMap smData;
    smData.set_blockrow( nBlockRow );
    smData.set_blockcol( nBlockCol );
    smData.set_gridwidth( nGridWidth );
    smData.set_gridheight( nGridHeight );
    smData.set_nextblockindex( 0 );

    std::string strBuffer;
    smData.SerializeToString( &strBuffer );

    fwrite( strBuffer.c_str(), strBuffer.length(), 1, fp );

    // 
    fclose( fp );

    TLSeamlessMap* pkRetSMNode = TLSeamlessMap::create( strSeamlessMapFile, 0.0f, 0.0f );
    if( pkRetSMNode != NULL )
    {
        pkRetSMNode->addBlock( strBlockName, 0.0f, 0.0f, strMaterial );
        pkRetSMNode->save();
    }

    return pkRetSMNode;
#else
    return NULL;
#endif
}

bool TLSeamlessMap::save()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
    std::string strSMFileName = m_strSeamlessMapFile + ".sm";
    FILE* fp = fopen( strSMFileName.c_str(), "wb" );
    if( fp == NULL )
        return false;

	for( int i=BLOCK_INDEX_CENTER; i < BLOCK_INDEX_MAX; ++i )
    {
		if( m_kBlocks[i].pMapBlock != NULL )
			m_kBlocks[i].pMapBlock->save();
	}

    framework::SeamlessMap smData;
    smData.set_blockrow( m_nBlockRow );
    smData.set_blockcol( m_nBlockCol );
    smData.set_gridwidth( m_nGridWidth );
    smData.set_gridheight( m_nGridHeight );
    smData.set_nextblockindex( m_nNextBlockIndex );

	std::list<BlockInfo*>::iterator iter = m_listAllBlocks.begin();
	std::list<BlockInfo*>::iterator iter_end = m_listAllBlocks.end();
	for( ; iter != iter_end; ++iter )
	{
		BlockInfo* pBlockInfo = (*iter);

		framework::BlockInfo* bi = smData.add_blocks();
		bi->set_file( pBlockInfo->strBlockFileName );
		bi->set_x( pBlockInfo->x );
		bi->set_y( pBlockInfo->y );
	}

    std::string strBuffer;
    smData.SerializeToString( &strBuffer );

    fwrite( strBuffer.c_str(), strBuffer.length(), 1, fp );

    // 
    fclose( fp );

	return true;
#else
    return false;
#endif
}

bool TLSeamlessMap::init()
{
    if( !CCNode::init() )
        return false;

    std::string strSMFileName = m_strSeamlessMapFile + ".sm";

    unsigned long iSize = 0;
	unsigned char* pBuffer = AssetsManager::sharedAssetsManager()->getFileContent( strSMFileName.c_str(), "rb", &iSize );
    if( pBuffer == NULL )
        return false;

    framework::SeamlessMap smData;
	smData.ParseFromArray( (void*)pBuffer, iSize );

	delete[] pBuffer;

    m_nBlockRow = smData.blockrow();
    m_nBlockCol = smData.blockcol();
    m_nGridWidth = smData.gridwidth();
    m_nGridHeight = smData.gridheight();
    m_nNextBlockIndex = smData.nextblockindex();

    m_nBlockWidth = m_nBlockCol * m_nGridWidth;
    m_nBlockHeight = m_nBlockRow * m_nGridHeight;

    for( int i=0; i < smData.blocks_size(); ++i )
    {
        const framework::BlockInfo& bi = smData.blocks( i );

        BlockInfo* pBlockInfo = new BlockInfo;
        pBlockInfo->strBlockFileName = bi.file();
        pBlockInfo->x = bi.x();
        pBlockInfo->y = bi.y();
        m_listAllBlocks.push_back( pBlockInfo );
    }

    updateBlock();

    return true;
}

TLMapBlock* TLSeamlessMap::loadBlock( const std::string& strFileName )
{
    return TLMapBlock::create( strFileName );
}

void TLSeamlessMap::updateBlock()
{
    // 当前块的中心坐标
    float fCurCenterX = m_fCurX;
    float fCurCenterY = m_fCurY;
    correctCoordinate( fCurCenterX, fCurCenterY );

    // 先备份
    for( int i=BLOCK_INDEX_CENTER; i < BLOCK_INDEX_MAX; ++i )
    {
        m_kOldBlocks[i] = m_kBlocks[i];

        m_kBlocks[i].pMapBlock = NULL;
        m_kBlocks[i].strBlockFileName.clear();
        m_kBlocks[i].x = 0.0f;
        m_kBlocks[i].y = 0.0f;
    }

    // 当前位置的
    BlockInfo* pCenterBlockInfo = getBlockInfo( m_fCurX, m_fCurY );
    updateBlock( BLOCK_INDEX_CENTER, pCenterBlockInfo );

    float fLeftFlag = ( m_fCurX - ( fCurCenterX - m_nBlockWidth * 0.5f ) ) / m_nBlockWidth;
    float fRightFlag = ( ( fCurCenterX + m_nBlockWidth * 0.5f ) - m_fCurX ) / m_nBlockWidth;
    float fTopFlag = ( ( fCurCenterY + m_nBlockHeight * 0.5f ) - m_fCurY ) / m_nBlockHeight;
    float fBottomFlag = ( m_fCurY - ( fCurCenterY - m_nBlockHeight * 0.5f ) ) / m_nBlockHeight;

    // 左
    if( fLeftFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX - m_nBlockWidth, m_fCurY );
        updateBlock( BLOCK_INDEX_LEFT, pBlockInfo );
    }

    // 右
    if( fRightFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX - m_nBlockWidth, m_fCurY );
        updateBlock( BLOCK_INDEX_RIGHT, pBlockInfo );
    }

    // 上
    if( fTopFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX, m_fCurY + m_nBlockHeight );
        updateBlock( BLOCK_INDEX_TOP, pBlockInfo );
    }

    // 下
    if( fBottomFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX, m_fCurY - m_nBlockHeight );
        updateBlock( BLOCK_INDEX_BOTTOM, pBlockInfo );
    }

    // 左上
    if( fLeftFlag <= g_fLoadNewBlockFlag && fTopFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX - m_nBlockWidth, m_fCurY + m_nBlockHeight );
        updateBlock( BLOCK_INDEX_LEFT_TOP, pBlockInfo );
    }

    // 左下
    if( fLeftFlag <= g_fLoadNewBlockFlag && fBottomFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX - m_nBlockWidth, m_fCurY - m_nBlockHeight );
        updateBlock( BLOCK_INDEX_LEFT_BOTTOM, pBlockInfo );
    }

    // 右上
    if( fRightFlag <= g_fLoadNewBlockFlag && fTopFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX + m_nBlockWidth, m_fCurY + m_nBlockHeight );
        updateBlock( BLOCK_INDEX_RIGHT_TOP, pBlockInfo );
    }

    // 右下
    if( fRightFlag <= g_fLoadNewBlockFlag && fBottomFlag <= g_fLoadNewBlockFlag )
    {
        BlockInfo* pBlockInfo = getBlockInfo( m_fCurX + m_nBlockWidth, m_fCurY - m_nBlockHeight );
        updateBlock( BLOCK_INDEX_RIGHT_BOTTOM, pBlockInfo );
    }

    // 把备份删掉
    for( int i=BLOCK_INDEX_CENTER; i < BLOCK_INDEX_MAX; ++i )
    {
        if( m_kOldBlocks[i].pMapBlock != NULL )
        {
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
			m_kOldBlocks[i].pMapBlock->save();
#endif
            m_kOldBlocks[i].pMapBlock->removeFromParentAndCleanup( true );

            m_kOldBlocks[i].pMapBlock = NULL;
            m_kOldBlocks[i].strBlockFileName.clear();
            m_kOldBlocks[i].x = 0.0f;
            m_kOldBlocks[i].y = 0.0f;
        }
    }
}

void TLSeamlessMap::updateBlock( int nIndex, BlockInfo* pBlockInfo )
{
    if( pBlockInfo == NULL )
        return;

	int nOldIndex = 0;
	TLMapBlock* pMapBlock = getMapBlockFromOldBlocks( pBlockInfo->x, pBlockInfo->y, nOldIndex );
	if( pMapBlock != NULL )
	{
		m_kBlocks[nIndex] = m_kOldBlocks[nOldIndex];

        m_kOldBlocks[nOldIndex].pMapBlock = NULL;
        m_kOldBlocks[nOldIndex].strBlockFileName.clear();
        m_kOldBlocks[nOldIndex].x = 0.0f;
        m_kOldBlocks[nOldIndex].y = 0.0f;

        return;
	}

    // 备份里面没有，只好重新加载了
    m_kBlocks[nIndex].pMapBlock = loadBlock( pBlockInfo->strBlockFileName );
    m_kBlocks[nIndex].strBlockFileName = pBlockInfo->strBlockFileName;
    m_kBlocks[nIndex].x = pBlockInfo->x;
    m_kBlocks[nIndex].y = pBlockInfo->y;

    addChild( m_kBlocks[nIndex].pMapBlock, -1000 );
}

BlockInfo* TLSeamlessMap::getBlockInfo( float x, float y )
{
    // 修正坐标
    correctCoordinate( x, y );

    std::list<BlockInfo*>::iterator iter = m_listAllBlocks.begin();
    std::list<BlockInfo*>::iterator iter_end = m_listAllBlocks.end();
    for( ; iter != iter_end; ++iter )
    {
        BlockInfo* pBlockInfo = (*iter);
        if( pBlockInfo->x - m_nBlockWidth * 0.5f <= x &&
                pBlockInfo->x + m_nBlockWidth * 0.5f >= x &&
                pBlockInfo->y - m_nBlockHeight * 0.5f <= y &&
                pBlockInfo->y + m_nBlockHeight * 0.5f >= y )
        {
            return pBlockInfo;
        }
    }

    return NULL;
}

TLMapBlock* TLSeamlessMap::getMapBlock( float x, float y )
{
	correctCoordinate( x, y );

	for( int i=BLOCK_INDEX_CENTER; i < BLOCK_INDEX_MAX; ++i )
	{
		MBInfo mbInfo = m_kBlocks[i];
		if( mbInfo.pMapBlock == NULL )
			continue;

        if( mbInfo.x - m_nBlockWidth * 0.5f <= x &&
            mbInfo.x + m_nBlockWidth * 0.5f >= x &&
            mbInfo.y - m_nBlockHeight * 0.5f <= y &&
            mbInfo.y + m_nBlockHeight * 0.5f >= y )
        {
            return mbInfo.pMapBlock;
        }
	}

	return NULL;
}

TLMapBlock* TLSeamlessMap::getMapBlockFromOldBlocks( float x, float y, int& nOldIndex )
{
	correctCoordinate( x, y );

	for( int i=BLOCK_INDEX_CENTER; i < BLOCK_INDEX_MAX; ++i )
	{
		MBInfo mbInfo = m_kOldBlocks[i];
		if( mbInfo.pMapBlock == NULL )
			continue;

        if( mbInfo.x - m_nBlockWidth * 0.5f <= x &&
            mbInfo.x + m_nBlockWidth * 0.5f >= x &&
            mbInfo.y - m_nBlockHeight * 0.5f <= y &&
            mbInfo.y + m_nBlockHeight * 0.5f >= y )
        {
			nOldIndex = i;

            return mbInfo.pMapBlock;
        }
	}

	return NULL;
}

void TLSeamlessMap::setCurXY( float x, float y )
{
    m_fCurX = x;
    m_fCurY = y;

    updateBlock();
}

void TLSeamlessMap::setIsEnablePass( float world_x, float world_y, bool bIsEnable )
{
    TLMapBlock* pMapBlock = getMapBlock( world_x, world_y );
    if( pMapBlock != NULL )
        pMapBlock->setIsEnablePass( world_x, world_y, bIsEnable );
}

bool TLSeamlessMap::getIsEnablePass( float world_x, float world_y )
{
    TLMapBlock* pMapBlock = getMapBlock( world_x, world_y );
    if( pMapBlock != NULL )
        return pMapBlock->getIsEnablePass( world_x, world_y );

    return false;
}

void TLSeamlessMap::setIsEnablePlant( float world_x, float world_y, bool bIsEnable )
{
    TLMapBlock* pMapBlock = getMapBlock( world_x, world_y );
    if( pMapBlock != NULL )
        pMapBlock->setIsEnablePlant( world_x, world_y, bIsEnable );
}

bool TLSeamlessMap::getIsEnablePlant( float world_x, float world_y )
{
    TLMapBlock* pMapBlock = getMapBlock( world_x, world_y );
    if( pMapBlock != NULL )
        return pMapBlock->getIsEnablePlant( world_x, world_y );

    return false;
}

void TLSeamlessMap::setIsEnableFillWater( float world_x, float world_y, bool bIsEnable )
{
    TLMapBlock* pMapBlock = getMapBlock( world_x, world_y );
    if( pMapBlock != NULL )
        pMapBlock->setIsEnableFillWater( world_x, world_y, bIsEnable );
}

bool TLSeamlessMap::getIsEnableFillWater( float world_x, float world_y )
{
    TLMapBlock* pMapBlock = getMapBlock( world_x, world_y );
    if( pMapBlock != NULL )
        return pMapBlock->getIsEnableFillWater( world_x, world_y );

    return false;
}

void TLSeamlessMap::addBlock( const std::string& strBlockName, float x, float y, const std::string& strMaterial )
{
    char szBuf[1024];
    sprintf( szBuf, "%s%d", m_strSeamlessMapFile.c_str(), m_nNextBlockIndex );
    std::string strBlockFileName = szBuf;
    ++m_nNextBlockIndex;

    if( !TLMapBlock::newMapBlock( strBlockFileName, strBlockName, m_nBlockRow, m_nBlockCol, m_nGridWidth, m_nGridHeight, strMaterial ) )
        return;

    // 在修正前，先记录下来，作为当前的坐标
    m_fCurX = x;
    m_fCurY = y;

    // 修正坐标
    correctCoordinate( x, y );

    // 不能重复
    removeBlock( x, y );

    // 
    BlockInfo* pBlockInfo = new BlockInfo;
    pBlockInfo->strBlockFileName = strBlockFileName;
    pBlockInfo->x = x;
    pBlockInfo->y = y;
    m_listAllBlocks.push_back( pBlockInfo );

    // 更新
    updateBlock();
}

void TLSeamlessMap::removeBlock( float x, float y )
{
    // 修正坐标
    correctCoordinate( x, y );

    std::list<BlockInfo*>::iterator iter = m_listAllBlocks.begin();
    std::list<BlockInfo*>::iterator iter_end = m_listAllBlocks.end();
    for( ; iter != iter_end; ++iter )
    {
        BlockInfo* pBlockInfo = (*iter);
        if( pBlockInfo->x - m_nBlockWidth * 0.5f <= x &&
            pBlockInfo->x + m_nBlockWidth * 0.5f >= x &&
            pBlockInfo->y - m_nBlockHeight * 0.5f <= y &&
            pBlockInfo->y + m_nBlockHeight * 0.5f >= y )
        {
            m_listAllBlocks.erase( iter );

            delete pBlockInfo;

            break;
        }
    }
}

void TLSeamlessMap::correctCoordinate( float& x, float& y )
{
    int xTempX = ( x + m_nBlockWidth * 0.5f ) / m_nBlockWidth;
    x = xTempX * m_nBlockWidth;

    int nTempY = ( y + m_nBlockHeight * 0.5f ) / m_nBlockHeight;
    y = nTempY * m_nBlockHeight;
}
