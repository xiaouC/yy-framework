#pragma once
#include "cocos2d.h"

USING_NS_CC;

struct chatTexInfo
{
    CCRect rcUV;
};

class TLLabelRichTex;
class TLFontTex
{
    friend class TLLabelRichTex;
public:
	TLFontTex();
	~TLFontTex();

	static TLFontTex* sharedTLFontTex();

	CCSpriteBatchNode* newBatchNode();

public:
	void initFontTexture( const char* pFile, int nRow, int nCol, const char* szShaderName, const char* szFontShaderName=NULL );

	chatTexInfo* getChatTextInfo( const char* p );
	float getFontScale( float fInFontSize );
    void getColorTextureCoords( int nColorIndex, float& ul, float& vt, float& ur, float&vb );
    CCGLProgram* getColorTextureShaderProgram();
    CCGLProgram* getFontShaderProgram();

	void saveFontTexture( const char* szFilePath );

protected:
    GLint m_nOldFBO;
    GLuint m_uFBO;

    CCTexture2D* m_pFontTex;
    float m_nCurrentLineHeight;

	float m_nOffsetX, m_nOffsetY;
	std::map<unsigned int,chatTexInfo> m_mapAllChat;
	std::vector<std::string> m_orderAllChat;

    // color texture
    CCTexture2D* m_pColorTex;
    int m_nRow, m_nCol;
    std::string m_strShaderName;
    std::string m_strFontShaderName;

protected:
    chatTexInfo* createOneCharEdge( const char* p );

public:
	static float getCommonLineHeight() { return ms_fCommonLineHeight; }
	static void resetCommonLineHeight();

	static void setFontOriginSize( float fFontOriginSize ) { ms_fFontOriginSize = fFontOriginSize; resetCommonLineHeight(); }
	static void setFontName( const std::string& strFontName ) { ms_strFontName = strFontName; resetCommonLineHeight(); }

    static void setParseRichTextHandler( int nParseHandle ) { ms_nParseHandle = nParseHandle; }

protected:
	static float ms_fCommonLineHeight;
	static float ms_fFontOriginSize;
	static std::string ms_strFontName;

    static int ms_nParseHandle;
};

