#include "MultiplayerScene.h"

USING_NS_CC;

Scene* MultiplayerScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = MultiplayerScreen::create();

	scene->addChild(layer);

	return scene;
}

bool MultiplayerScreen::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto pauseItem =
		MenuItemImage::create("GameScreen/Pause_Button.png",
		"GameScreen/Pause_Button(Click).png",
		CC_CALLBACK_1(MultiplayerScreen::activatePauseScene, this));
	auto findGameItem =
		MenuItemImage::create("MultiplayerScreen/FindGame.png",
		"MultiplayerScreen/FindGameClicked.png",
		CC_CALLBACK_1(MultiplayerScreen::findGame, this));
	auto createGameItem =
		MenuItemImage::create("MultiplayerScreen/CreateGame.png",
		"MultiplayerScreen/CreateGameClicked.png",
		CC_CALLBACK_1(MultiplayerScreen::findGame, this));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));

	findGameItem->setPosition(120, 350);

	createGameItem->setPosition(360, 350);


	auto menu = Menu::create(pauseItem, findGameItem, createGameItem, NULL);

	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	addBackGroundSprite(visibleSize, origin);

	this->scheduleUpdate(); // add this

	return true;
}

void MultiplayerScreen::activatePauseScene(Ref *pSender)
{
	auto scene = PauseScene::createScene();
	//auto scene = GameOverScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void MultiplayerScreen::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MultiplayerScreen::findGame(Ref *pSender)
{
	Director::getInstance()->popScene();
}

void MultiplayerScreen::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto multiplayerbackgroundSprite = Sprite::create(ptr->m_multiplayerBackgroundTextureFile);

	multiplayerbackgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

	this->addChild(multiplayerbackgroundSprite, -1);
}

void MultiplayerScreen::update(float dt)
{
	switch (m_gameState)
	{
	case GameStates::GameInit:
		addEvents();    // add this
		break;
	case GameStates::GameRunning:
		break;
	default:
		break;
	}
}



void MultiplayerScreen::addEvents()
{
	//Create a "one by one" touch event listener (processes one touch at a time)
	auto listener1 = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener1->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	listener1->onTouchBegan = [this](Touch* touch, Event* event){
		Vec2 pos = touch->getLocation();
		return true;
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener1, 30);
}