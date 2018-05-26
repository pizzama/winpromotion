//
//  luaShadeCCBLayer.cpp
//  miniDotaClient
//
//  Created by 李 兆诚 on 13-2-20.
//
//

#include "luaShadeCCBLayer.h"

luaShadeCCBLayer::luaShadeCCBLayer() : m_bIsTouchEnabled(true), m_bIsFullScreen(false)
{
    
}
luaShadeCCBLayer::~luaShadeCCBLayer()
{
   
}
luaShadeCCBLayer* luaShadeCCBLayer::create()
{
    luaShadeCCBLayer* node = new luaShadeCCBLayer();
    if(node->init())
    {
        CCSize size = CCDirector::sharedDirector()->getWinSize();
//        node->setAnchorPoint(CCPoint(0.5, 0.5));
//        node->setPosition(CCPoint(size.width * 0.5, size.height * 0.5));
        node->autorelease();
        return node;
    }
    delete node;
    return NULL;
}


bool luaShadeCCBLayer::init()
{
    if (luaCCBNode::init()) {
       

      return true;
    }
    return false;
}

void luaShadeCCBLayer::setIsTouchEnabled(bool isTouchEnabled)
{
    m_bIsTouchEnabled = isTouchEnabled;
}
bool luaShadeCCBLayer::getIsTOuchEnabled()
{
    return m_bIsTouchEnabled;
}
bool luaShadeCCBLayer::isTouchEnabled()
{
    return m_bIsTouchEnabled;
}

void luaShadeCCBLayer::onEnter()
{
    //该层是一个屏蔽层 凡是点击范围在该层范围内 点击事件就被吞掉
    //跟ccControlbutton一个级别 但是由于是根节点 所以会先执行子节点中包含的cccontrolbutton
    if (m_bIsTouchEnabled)
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
    CCNode::onEnter();
}
void luaShadeCCBLayer::onExit()
{
    if (m_bIsTouchEnabled)
        CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCNode::onExit();
}

bool luaShadeCCBLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!isRunning()) {
        return false;
    }
    if (isTouchInside(pTouch)) {
        CCLog("在点击范围内");
        return true;
    }
     CCLog("不在点击范围内 事件继续传递");
    return false;
}


bool luaShadeCCBLayer::isTouchInside(CCTouch* touch)
{
    CCPoint touchLocation = touch->getLocation(); // Get the touch position
    touchLocation = this->getParent()->convertToNodeSpace(touchLocation);
    CCRect bBox=boundingBox();
    return bBox.containsPoint(touchLocation);
}



bool luaShadeCCBLayer::openCCBFile(const char* pCCBFileName, bool isFullScreen)
{
    m_bIsFullScreen = isFullScreen;
   
    return  openCCBFile(pCCBFileName);
}

bool luaShadeCCBLayer::openCCBFile(const char* pCCBFileName)
{
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("luaCCBLayer", luaCCBLoader::loader());
    
    cocos2d::extension::CCBReader *ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    CCNode *node = ccbReader->readNodeGraphFromFile(pCCBFileName,this);
    node->setTag(0);
//    if(node == NULL)
//    {
//        ccbReader->release();
//        return false;
//    }
//    
//    ccbReader->release();
    if (m_bIsFullScreen) {
        setContentSize(CCDirector::sharedDirector()->getWinSize());
    } else
    {
        setContentSize(node->getContentSize());
    }
//    
   
//    CCLayerColor* layer = CCLayerColor::create(ccc4(100, 100, 100, 160));
//    layer->setContentSize(node->getContentSize());
//    layer->setPosition(CCPointZero);
      setPosition(node->getPosition());
    node->setPosition(CCPointZero);
//    addChild(layer);
  
    this->addChild(node);
    return true;
}

