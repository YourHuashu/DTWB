#ifndef __Block_H_
#define __Block_H_
#include "cocos2d.h"
USING_NS_CC;
class Block :public CCSprite
{
public:
	//�ֱ��ʾ���С������ɫ�����е��ַ������ֵĴ�С����ɫ
	static Block * create(CCSize size, ccColor3B color,
		CCString str, float strSize, ccColor3B strColor);
	bool init(CCSize size, ccColor3B color,
		CCString str, float strSize, ccColor3B strColor);

	//�洢����
	static CCArray *array;
	//array
	static CCArray * getBlocksArray();
	//ÿһ������һ���кŵ�����,����һ��get������set����
	CC_SYNTHESIZE(int, _lineIndex, LineIndex);

	void moveDownAndCleanUp();
};

#endif