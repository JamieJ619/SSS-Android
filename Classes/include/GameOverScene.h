#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "MainMenu.h"

class GameOverScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	// Called when retry is selected 
	void activateGameScene(Ref *pSender);
	// Called when main menu is selected 
	void activateMainMenuScene(Ref *pSender);

	CREATE_FUNC(GameOverScene);
};