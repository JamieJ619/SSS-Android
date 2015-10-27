#pragma once

#include "cocos2d.h"
#include "GameScene.h"

class MainMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void activateGameScene(Ref * pSender);

	CREATE_FUNC(MainMenu);
	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);
	void activateMultiplayerScene(Ref *pSender);
};