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
    auto scene = Scene::create();
    auto layer = ___FILEBASENAMEASIDENTIFIER___::create();
    scene->addChild(layer);
    
    return scene;
}

bool ___FILEBASENAMEASIDENTIFIER___::init()
{
    if ( !Layer::init() ) return false;
    
    //Welcome Message
    auto windowSize = Director::getInstance()->getWinSize();
    auto label = LabelTTF::create("___FILEBASENAMEASIDENTIFIER___", "Arial", 24);
    label->setPosition(windowSize.width / 2, windowSize.height / 2);
    this->addChild(label);
    
    return true;
}