#include "Block.h"
#include "AppMacros.h"

//存储数据
CCArray *Block::array = NULL;

//这里的create依赖下面的init，所以create中的参数和init中的
//参数是一样的
Block * Block::create(CCSize size, ccColor3B color,
	CCString str, float strSize, ccColor3B strColor)
{
	//只让array生成一次
	if (array == NULL)
	{
		array = CCArray::create();
		//因为array走的不是渲染树，所以要加上ratain()
		array->retain();
	}
	Block * pRet = new Block();
	if (pRet && pRet->init(size, color, str, strSize, strColor))
	{
		pRet->autorelease();
		array->addObject(pRet);
	}
	else
	{
		delete pRet;
		pRet = NULL;
	}
	return pRet;
}

bool Block::init(CCSize size, ccColor3B color,
	CCString str, float strSize, ccColor3B strColor)
{
	//注意，这里的块是一个精灵
	CCSprite::init();

	//设置块的大小
	setContentSize(size);
	//设置渲染的大小
	setTextureRect(CCRectMake(0, 0, size.width, size.height));
	//块的颜色
	setColor(color);
	//设置块的锚点
	setAnchorPoint(ccp(0, 0));

	//设置块中的文字，不在create里面进行赋值是因为默认的字体更好些
	CCLabelTTF * label = CCLabelTTF::create();
	//设置label的字符串
	label->setString(str.getCString());
	//设置字体的大小
	label->setFontSize(strSize);
	//设置字体的颜色
	label->setColor(strColor);
	//设置字的位置
	label->setPosition(ccp(size.width / 2, size.height / 2));
	addChild(label);

	return true;
}

//取array
CCArray * Block::getBlocksArray()
{
	return array;
}

void Block::moveDownAndCleanUp()
{
	//行号减一
	_lineIndex--;
	//往下走一个格
	CCMoveTo * to = CCMoveTo::create(0.01,
		ccp(getPositionX(), getPositionY() - winSize.height / 4));
	this->runAction(to);

	//从节点中拿走
	if (_lineIndex < 0)
	{
		//从数组中拿走,这里将引用计数减1，让它不影响渲染树的问题
		array->removeObject(this);
		removeFromParentAndCleanup(true);
	}
}