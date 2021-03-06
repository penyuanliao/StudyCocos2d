//
//  ___FILENAME___
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//___COPYRIGHT___
//

#include "___FILEBASENAME___.h"

USING_NS_CC;

___FILEBASENAMEASIDENTIFIER___::___FILEBASENAMEASIDENTIFIER___()
{
}

___FILEBASENAMEASIDENTIFIER___::~___FILEBASENAMEASIDENTIFIER___()
{
}

Scene* ___FILEBASENAMEASIDENTIFIER___::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = ___FILEBASENAMEASIDENTIFIER___::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool ___FILEBASENAMEASIDENTIFIER___::init()
{
    // super init first
    if ( !Layer::init() ) return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    //Welcome Message
    auto windowSize = Director::getInstance()->getWinSize();
    auto label = LabelTTF::create("___FILEBASENAMEASIDENTIFIER___", "Arial", 24);
    label->setPosition(windowSize.width / 2, windowSize.height / 2);
    this->addChild(label);
    
    return true;
}