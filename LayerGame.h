#ifndef __LayerGame_H__
#define __LayerGame_H__

#include "cocos2d.h"
USING_NS_CC;



class LayerGame :public CCLayer
{
public:
	static CCScene * scene();
	CREATE_FUNC(LayerGame);
	bool init();

	CC_SYNTHESIZE(int, _lineCount, LineCount);

	void StartGame();
	void addStartLineBlocks();
	void addEndLineBlocks();
	void addNormalBlocks(int lineIndex);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);

	void moveDown();

	bool showEnd;

	void startTimer();
	void stopTimer();

	int startTime;
	void update(float dt);

	CCLabelTTF * timer;

	bool isRunning;

	void keyBackClicked(void);
};
#endif



