#include "GameOverScene.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameOverScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameOverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto menuTitle =
		MenuItemImage::create("GameOverScreen/Game_Over.png",
		"GameOverScreen/Game_Over.png");
	auto retryItem =
		MenuItemImage::create("GameOverScreen/Retry_Button.png",
		"GameOverScreen/Retry_Button(Click).png",
		CC_CALLBACK_1(GameOverScene::activateGameScene, this));
	auto mainMenuItem =
		MenuItemImage::create("GameOverScreen/Menu_Button.png",
		"GameOverScreen/Menu_Button(Click).png",
		CC_CALLBACK_1(GameOverScene::activateMainMenuScene, this));
	auto menu = Menu::create(menuTitle, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);

	return true;
}

void GameOverScene::activateGameScene(cocos2d::Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOverScene::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}