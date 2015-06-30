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

bool ___FILEBASENAMEASIDENTIFIER___::init()
{
    if ( !Layer::init() ) return false;
    
    //Welcome Message
    auto windowSize = Director::getInstance()->getWinSize();
    
    return true;
}

int ___FILEBASENAMEASIDENTIFIER___::hellworld(int i)
{
    return i + 1;
}