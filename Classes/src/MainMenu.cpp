#include "MainMenu.h"
#include "MultiplayerScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);

	return scene;
}

bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// Returns visible size of OpenGL window in points.
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto playSingleItem =
		MenuItemImage::create("MainMenuScreen/SPButton.png",
		"MainMenuScreen/SPButtonPressed.png",
		CC_CALLBACK_1(MainMenu::activateGameScene, this));

	auto playMultiItem =
		MenuItemImage::create("MainMenuScreen/MPButton.png",
		"MainMenuScreen/MPButtonPressed.png",
		CC_CALLBACK_1(MainMenu::activateMultiplayerScene, this));
	auto menu = Menu::create(playMultiItem, playSingleItem, NULL);

	playSingleItem->setPosition(-120, -158);
	playMultiItem->setPosition(116, -158);

	//menu->setPosition(visibleSize.width / 2, 268);

	Point origin = Director::getInstance()->getVisibleOrigin();
	addBackGroundSprite(visibleSize, origin);

	this->addChild(menu);


	return true;
}

void MainMenu::activateGameScene(Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MainMenu::activateMultiplayerScene(Ref *pSender)
{
	auto scene = MultiplayerScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MainMenu::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto menuSprite = Sprite::create(ptr->m_menuTextureFile);

	menuSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

	this->addChild(menuSprite, -1);
}
