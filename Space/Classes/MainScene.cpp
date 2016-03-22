#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = MainScene::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Device::setKeepScreenOn(true);
    Device::setAccelerometerEnabled(true);
    Device::setAccelerometerInterval(1.0 / 60);
    
    // auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    // auto edgeNode = Node::create();
    // edgeNode->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    // edgeNode->setPhysicsBody(body);
    // this->addChild(edgeNode);

    sprite = Aircraft::create();
    addChild(sprite, 0);
    box = this->getBoundingBox();

    ui::Button* left = ui::Button::create("res/Controls/shadedLight05.png");
    left->setTouchEnabled(true);
    left->setPosition(Point(visibleSize.width / 7.9f, visibleSize.height / 6.5f));   
    left->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
                case ui::Widget::TouchEventType::BEGAN:
                    sprite->makeRotation('-');
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    sprite->makeRotation('-');
                    break;
                default:
                    break;
        }
    });   
    this->addChild(left, 10);

    ui::Button* right = ui::Button::create("res/Controls/shadedLight06.png");
    right->setTouchEnabled(true);
    right->setPosition(Point(visibleSize.width / 5.0f, visibleSize.height / 6.5f));
    right->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
                case ui::Widget::TouchEventType::BEGAN:
                    sprite->makeRotation('+');
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    sprite->makeRotation('+');
                    break;
                default:
                    break;
        }
    });     
    this->addChild(right, 10);


    ui::Button* up = ui::Button::create("res/Controls/shadedLight03.png");
    up->setTouchEnabled(true);
    up->setPosition(Point(visibleSize.width /6.1f, visibleSize.height / 4.8f));
    up->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
                case ui::Widget::TouchEventType::BEGAN:
                    sprite->makeMove();
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    sprite->makeMove();
                    break;
                default:
                    break;
        }
    });        
    this->addChild(up, 10);

    this->scheduleUpdate();
    return true;
}

void MainScene::update(float delta)
{
    launchMeteors(7);
    Meteor* meteor = sprite->shotCollision(meteors);
    if(meteor){
        removeMeteor(meteor);
    }
}

void MainScene::launchMeteors(unsigned int num)
{
    if(meteors.size()<num){
        Meteor* meteor = Meteor::create();
        addMeteor(meteor);
        meteor->toMove();
    }
    for(Meteor* meteor: meteors){
        if(!box.containsPoint(meteor->getPosition()))
        {
            if(meteor->getAnimed()){            
                removeMeteor(meteor);
            }
        }
    }
}

void MainScene::addMeteor(Meteor* meteor)
{
    meteors.push_back(meteor);
    this->addChild(meteor, -1);
}

void MainScene::removeMeteor(Meteor* meteor)
{
    if(findMeteor(meteor)){    
        meteors.erase(std::remove(meteors.begin(), meteors.end(), meteor), meteors.end());
        meteor->removeFromParent();
        meteor->release();
   }
}

bool MainScene::findMeteor(Meteor* meteor)
{
    if ( std::find(meteors.begin(), meteors.end(), meteor) != meteors.end() ){
        return true;
    }else{
       return false;
    }
}
