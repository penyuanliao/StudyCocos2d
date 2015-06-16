//
//  HelloWorld.h
//  cocos2dLua
//
//  Created by mobile on 2015/6/10.
//
//

#ifndef __cocos2dLua__HelloWorld__
#define __cocos2dLua__HelloWorld__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/UIWidget.h"

using namespace cocos2d;
using namespace std;
using namespace ui;

//需要繼承Ref
class HelloWorld : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(HelloWorld);
    
private:
    cocos2d::PhysicsWorld *sceneWrold;
    void setPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWrold = world; };
    void setGravityScene(cocos2d::PhysicsWorld *world);
    void createPhyical();
    bool createSprite(int tag);
    
    //void update(float dt);
    
    // Create Contact EventListener //
    void addSpriteContactListener(cocos2d::Sprite *sp);
    void addTouchEvents();
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void particleSystem();
    void createPlistFile();
    
    // Custom Event //
    void addEventListener(std::string event, const std::function<void(EventCustom*)>& callback);
    void dispatchevent(std::string event);
    
    
};
#endif /* defined(__cocos2dLua__HelloWorld__) */
