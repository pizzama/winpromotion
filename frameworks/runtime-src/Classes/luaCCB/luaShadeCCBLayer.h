//
//  luaShadeCCBLayer.h
//  miniDotaClient
//
//  Created by 李 兆诚 on 13-2-20.
//
//

#ifndef __miniDotaClient__luaShadeCCBLayer__
#define __miniDotaClient__luaShadeCCBLayer__
#include "cocos2d.h"
#include "luaCCBLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;
class luaShadeCCBLayer : public luaCCBNode, public CCTouchDelegate
{
public:
    luaShadeCCBLayer();
     ~luaShadeCCBLayer();
     bool init();
     virtual void onEnter();
       virtual void onExit();
     
    bool openCCBFile(const char* pCCBFileName);
    bool openCCBFile(const char* pCCBFileName, bool isFullScreen);
    static luaShadeCCBLayer* create();
    bool isTouchInside(CCTouch* touch);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    void setIsTouchEnabled(bool isTouchEnabled);
    bool getIsTOuchEnabled();
    bool isTouchEnabled();
private:
    bool m_bIsTouchEnabled;
    bool m_bIsFullScreen;
    };

#endif /* defined(__miniDotaClient__luaShadeCCBLayer__) */
