//
//  HelloWorld.cpp
//  cocos2dLua
//
//  Created by mobile on 2015/6/10.
//
//

#include "HelloWorld.h"
#include "ui/UIButton.h"



Scene * HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    //debug hide view.
    scene->getPhysicsWorld()->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
    
    scene->getPhysicsWorld()->setGravity( Vect(0, -98.0f));
    
    auto layer = HelloWorld::create();
    
    layer->setPhysicsWorld( scene->getPhysicsWorld());
    
    scene->addChild(layer);
    
    CCLOG("createScene");
    
    
    
    return scene;
}
// 重力
void HelloWorld::setGravityScene( PhysicsWorld *world )
{
    Vect gravity;
    gravity.setPoint(0, -50);
    world->setGravity(gravity);
    world->setSpeed(6.0f);
}
/**
void HelloWorld::update(float dt)
{
    CCLOG("Update");
}
**/
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
//    createPhyical();
    
    createPlistFile();
    
    return true;
    
}

void HelloWorld::createPhyical()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // Default Physics Engine chipmunk (or change Box2D)
    auto edgeBody = PhysicsBody::createEdgeBox( visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    // Create Physics 邊界
    auto edgeNode = Node::create();
    edgeNode->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
    
    // Create a sprite
    for (int i = 0; i < 6; i++) {
        createSprite(i);
    }
    this->scheduleUpdate();
}

bool HelloWorld::createSprite(int tag)
{
    //1. 建立物件
    auto sprite = Sprite::create("res/icon_1.png");
    sprite->setPosition(cocos2d::random(300,800), cocos2d::random(300,800));
    
    //2. 建立碰撞邊緣
    auto spriteBody = PhysicsBody::createBox(sprite->getContentSize());
//    auto spriteBody = PhysicsBody::createCircle(sprite->getContentSize().width / 2, PhysicsMaterial(0, 1, 0));
    
    spriteBody->setTag(tag);
    
    sprite->setPhysicsBody(spriteBody);
    
    this->addChild(sprite);
    
//    addSpriteContactListener(sprite);
    
//    addTouchEvents();
    

    
//    particleSystem();
    
    auto btn = Button::create();
    btn->loadTextures("Spin_tw0001.png", "Spin_tw0003.png","");
    btn->setAnchorPoint(Vec2(0, 0));
//    btn->addTouchEventListener(this, toucheventselector(HelloWorld::touchEvent));
    btn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touchEvent, this));
    this->addChild(btn);
    
    return true;
}

// 監聽碰撞事件 //
void HelloWorld::addSpriteContactListener(Sprite *sp)
{
    //增加碰撞偵測mask區域
    sp->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
    sp->getPhysicsBody()->setCollisionBitmask(0x01);
    //新增碰撞事件
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}
bool HelloWorld::onContactBegin(PhysicsContact& contact)
{
    
    CCLOG("onContactBegin()");
    
    return true;
}
// 按鈕事件狀態 //
void HelloWorld::addTouchEvents()
{
    auto touchEvent = EventListenerTouchOneByOne::create();
    // Trigger when Push Down
    touchEvent->onTouchBegan = [](Touch* touch, Event* evt) {
        CCLOG("onTouchBegan");
        return true;
    };
    // Trigger when moving touch
    touchEvent->onTouchMoved = [](Touch* touch, Event* evt) { CCLOG("onTouchMoved"); };
    // Trigger when you let up
    touchEvent->onTouchEnded = [](Touch* touch, Event* evt) { CCLOG("onTouchEnded"); };
    // Trigger when you Cancel
    touchEvent->onTouchCancelled = [](Touch* touch, Event* evt) { CCLOG("onTouchCancelled"); };
    // Add listener for target
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, this);
}

void HelloWorld::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
    string _type;
    
    switch (type) {
        case Widget::TouchEventType::BEGAN:
            _type = "Began";
            break;
        case Widget::TouchEventType::ENDED:
            _type = "Ended";
            break;
        case Widget::TouchEventType::MOVED:
            _type = "Moved";
            break;
        default:
            break;
    }
    
    CCLOG("::touchEvent(%s)",_type.c_str());
}
void HelloWorld::particleSystem()
{
    CCLOG(__func__);
    auto m_emitter = ParticleSystemQuad::createWithTotalParticles(1);
    m_emitter->setTexture(Director::getInstance()->getTextureCache()->addImage("fire.png"));
    m_emitter->setPosition(Vec2(300, 300));
    m_emitter->setDuration(-1);
    m_emitter->setGravity(Vec2(0, -240));
    m_emitter->setAngle( 90 );
    m_emitter->setAngleVar( 360 );
    m_emitter->setRadialAccel( 50 );
    m_emitter->setRadialAccelVar( 0 );
    m_emitter->setTangentialAccel( 30 );
    m_emitter->setTangentialAccelVar( 0 );
    m_emitter->setPosVar( Point( 400, 0 ) );
    m_emitter->setLife( 4 );
    m_emitter->setLifeVar( 2 );
    m_emitter->setStartSpin( 30 );
    m_emitter->setStartSpinVar( 60 );
    m_emitter->setEndSpin( 60 );
    m_emitter->setEndSpinVar( 60 );
    m_emitter->setStartColor( Color4F( 255, 255, 255, 1 ) );
    m_emitter->setStartColorVar( Color4F( 0, 0, 0, 0 ) );
    m_emitter->setEndColor( Color4F( 255, 255, 255, 1 ) );
    m_emitter->setEndColorVar( Color4F( 0, 0, 0, 0 ) );
    m_emitter->setStartSize( 30 );
    m_emitter->setStartSizeVar( 0 );
    m_emitter->setEndSize( 20.0f );
    m_emitter->setEndSizeVar( 0 );
    m_emitter->setEmissionRate( 100 );
    
    
    addChild(m_emitter, 10);
    
    auto fire = ParticleFire::create();
    addChild(fire);
    fire->setPosition(Vec2(300, 300));
    fire->setScaleX(0.5);
    fire->setScaleY(0.5);
    
}
#define NUMBER_OF_CARDS 10
const char *CARD_NAME[] = {"clubs","diamonds","hearts","spades"};

void HelloWorld::createPlistFile()
{
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cards.classic.plist");
    
    for (int count = 0; count < 1; count++)
    {
        string name;
        name.assign(CARD_NAME[cocos2d::random(0,3)]);
        string cardName = name + "." + to_string(cocos2d::random(1, 13) ) + ".png";
        auto card = Sprite::createWithSpriteFrameName(cardName);
        card->setAnchorPoint(Vec2(0, 0));
        
        auto bark = Sprite::createWithSpriteFrameName("back.blue.png");
        
//        card->setPosition(Vec2(count * card->getContentSize().width, 300));
//        this->addChild(card);
        
        auto menuItem = MenuItemSprite::create(bark, card, [](Ref* sender) { CCLOG("show this msg."); });
        
        auto menu = Menu::create(menuItem, NULL);
        this->addChild(menu);
    }
    
    
//    auto listener = cocos2d::EventListenerTouchOneByOne::create();
//    listener->setSwallowTouches(true);
//    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
//    {
//        Sprite *sp = (Sprite *)touch;
//        CCLOG("touch sprite");
//        return true;
//    };
//    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
    
}

void HelloWorld::addEventListener(string event, const std::function<void(EventCustom*)>& callback)
{
    const auto Callback = [](EventCustom *evt) { CCLOG("catch an custom event!!"); }; // 事件
    const int Priority = 12; // 觸發事件優先權
    cocos2d::EventListenerCustom *customEvt = EventListenerCustom::create(event, Callback);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(customEvt, Priority);
}

void HelloWorld::dispatchevent(string event)
{
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(event);
}

