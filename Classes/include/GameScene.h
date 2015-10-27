#pragma once

#include "cocos2d.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "GameData.h"
#include "GameStates.h"
#include <string>

class GameScreen : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	// Called when user pauses game play.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);
	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);

	CREATE_FUNC(GameScreen);
	void update(float dt);	// dt = delta time - the time between frames
	void addEvents();
private:
	GameStates m_gameState; // add this
};