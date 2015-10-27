#include "PauseScene.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* PauseScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = PauseScene::create();

	scene->addChild(layer);

	return scene;
}

bool PauseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto resumeItem =
		MenuItemImage::create("PauseScreen/Resume_Button.png",
		"PauseScreen/Resume_Button(Click).png",
		CC_CALLBACK_1(PauseScene::resume, this));
	auto retryItem =
		MenuItemImage::create("PauseScreen/Retry_Button.png",
		"PauseScreen/Retry_Button(Click).png",
		CC_CALLBACK_1(PauseScene::retry, this));
	auto mainMenuItem =
		MenuItemImage::create("PauseScreen/Menu_Button.png",
		"PauseScreen/Menu_Button(Click).png",
		CC_CALLBACK_1(PauseScene::activateMainMenuScene, this));
	auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 12);
	menu->setPosition(390, 680);
	this->addChild(menu);

	Point origin = Director::getInstance()->getVisibleOrigin();
	addBackGroundSprite(visibleSize, origin);

	return true;
}
void PauseScene::resume(Ref *pSender)
{
	Director::getInstance()->popScene();
}

void PauseScene::activateMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseScene::retry(Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);

}

void PauseScene::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto pauseSprite = Sprite::create(ptr->m_pauseTextureFile);

	pauseSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

	this->addChild(pauseSprite, -1);
}