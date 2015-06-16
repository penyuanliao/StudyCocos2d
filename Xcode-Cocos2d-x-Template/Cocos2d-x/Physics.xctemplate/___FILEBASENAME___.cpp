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
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
    // 'layer' is an autorelease object
    auto layer = ___FILEBASENAMEASIDENTIFIER___::create();
    
    layer->setPhysicsWorld( scene->getPhysicsWorld());
    
    scene->addChild(layer);
    
    return scene;
}

bool ___FILEBASENAMEASIDENTIFIER___::init()
{
    // super init first
    if ( !Layer::init() ) return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // Default Physics Engine chipmunk (or change Box2D)
    auto edgeBody = PhysicsBody::createEdgeBox( visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    // Create a static PhysicsBody
    edgeBody->setDynamic(false);
    // Create Physics 邊界
    auto edgeNode = Node::create();
    edgeNode->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
    
    return true;
}