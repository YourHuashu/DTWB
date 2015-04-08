#ifndef __Block_H_
#define __Block_H_
#include "cocos2d.h"
USING_NS_CC;
class Block :public CCSprite
{
public:
	//分别表示块大小，块颜色，块中的字符串，字的大小，颜色
	static Block * create(CCSize size, ccColor3B color,
		CCString str, float strSize, ccColor3B strColor);
	bool init(CCSize size, ccColor3B color,
		CCString str, float strSize, ccColor3B strColor);

	//存储数据
	static CCArray *array;
	//array
	static CCArray * getBlocksArray();
	//每一个都有一个行号的属性,设置一个get方法和set方法
	CC_SYNTHESIZE(int, _lineIndex, LineIndex);

	void moveDownAndCleanUp();
};

#endif