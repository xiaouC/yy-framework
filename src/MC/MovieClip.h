#pragma once
#include "cocos2d.h"
#include "anim.pb.h"

USING_NS_CC;

class StaticUIMC : public CCNodeRGBA
{
public:
	CCRect mcBoundingBox;

	StaticUIMC();
	virtual ~StaticUIMC();

	bool init( const framework::Layer* layer );

protected:
	CCRect mcOriginBoundingBox;

	CCSpriteBatchNode* m_pkStaticUIBatchNode;

public:
	static void setStaticUITextureFile( const std::string& strTextureName ) { m_strTextureName = strTextureName; }

protected:
	static std::string m_strTextureName;
};

typedef void(CCObject::*PlayEndCallbackFuncPtr)( unsigned long ulUserData );

class MovieClip : public CCNodeRGBA
{
public:
	CCRect mcOriginBoundingBox;
	CCRect mcBoundingBox;

	MovieClip( bool bAsync );
	virtual ~MovieClip();

	static MovieClip* createWithName( const char* mcName, bool bAsync = false );

	bool initWithName( const char* mcName );

	virtual void update( float dt );

    virtual void setScaleX(float fScaleX);
    virtual void setScaleY(float fScaleY);
    virtual void setScale(float scale);

public:
	bool initWithSymbol( const framework::Symbol* sym );

	 /**
     * @startFrame      ����һ֡��ʼ
     * @durationFrame   ������֡��-1��ʾ�����ƣ�0��ʾ�����Ŷ���
     * @loop            ѭ������ -1��ʾ����ѭ��, 0 ��ѭ��, ������ʾѭ������
     */
    void play( int startFrame, int durationFrame, int loopCount = 0, bool reverse = false );
	void start();
	void pause();
	void setAutoClear(bool reset) { m_autoClear = reset; }
	bool getAutoClear() { return m_autoClear; }
	bool getResetKeyframe() { return m_resetKeyframe; }
	bool setResetKeyframe(bool reset) { m_resetKeyframe = reset; return true; }
	//void setWrapAround(bool wrapAround) { m_wrapAround = wrapAround; }
	//bool getWrapAround() { return m_wrapAround; }
	void setFrameRate(int rate) { m_frameRate = rate; };
	int getFrameRate() { return m_frameRate; }
	const framework::Symbol* getSymbolInfo() { return m_symbolInfo; };
	virtual void removeAllChildrenWithCleanup(bool cleanup);

	float getTimeLength( int nFrameRate = -1 );
    int getFrameCount();

public:
	bool m_bAsync;
	bool m_bPlay;

	bool getIsPlaying() const { return m_playing; }

private:
	const framework::Symbol* m_symbolInfo; // ������Ϣ
	int m_frameRate;            // ֡�� (1���Ӳ�����֡��ÿ֡ʱ�� 1/֡��)

	float m_startTime;          // ��ʼ֡ʱ��
	float m_endTime;            // ����֡ʱ��
	float m_elapsed;            // ��ȥ��ʱ��

	std::vector<CCArray*> m_layers;         // ͼ������
	std::vector<int> m_currentKeyFrames;    // ��ǰ�ؼ�֡����

	int m_loopCount;              // ѭ������
	bool m_reverse;                // �Ƿ񵹲�
	bool m_autoClear;        // �ڹؼ�֡�Ƿ������ӽڵ�
	//bool m_wrapAround;        // ������ѭ�����ŵĶ������������֡�Ĳ��䡣
	bool m_playing;             // ���ڲ���
	bool m_resetKeyframe;       // �Ƿ��ڹؼ�֡��ʱ���ؽ�Ԫ��

	void setKeyframe(CCArray* keyframes, int keyframeIdx, float progress);
	void resetLayer(int iLayer, int iKeyframe);
	void updateLayer(int iLayer);
	void updateKeyframe(int iLayer, int keyframeIdx, float progress);
	void clear();
	void addLayerChild(int iLayer, CCNode *pNode);
	void removeLayerChild(int iLayer, CCNode *pNode, bool cleanup);
	
public:
	bool RegisterPlayEndCallbackHandler( int nPlayEndHandler );

	bool RegisterPlayEndCallback( CCObject* pCallbackObject, PlayEndCallbackFuncPtr pPlayEndCallFuncPtr, unsigned long ulUserData = 0xFFFFFFFF );

protected:
	int m_nPlayEndHandler;

	//////////////////////////////////////////////////////////////////////////
	CCObject* m_pPlayEndCallbackObject;
	PlayEndCallbackFuncPtr m_pPlayEndCallFuncPtr;
	unsigned long m_ulUserData;
};

