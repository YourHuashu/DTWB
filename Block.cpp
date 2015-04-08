#include "Block.h"
#include "AppMacros.h"

//�洢����
CCArray *Block::array = NULL;

//�����create���������init������create�еĲ�����init�е�
//������һ����
Block * Block::create(CCSize size, ccColor3B color,
	CCString str, float strSize, ccColor3B strColor)
{
	//ֻ��array����һ��
	if (array == NULL)
	{
		array = CCArray::create();
		//��Ϊarray�ߵĲ�����Ⱦ��������Ҫ����ratain()
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
	//ע�⣬����Ŀ���һ������
	CCSprite::init();

	//���ÿ�Ĵ�С
	setContentSize(size);
	//������Ⱦ�Ĵ�С
	setTextureRect(CCRectMake(0, 0, size.width, size.height));
	//�����ɫ
	setColor(color);
	//���ÿ��ê��
	setAnchorPoint(ccp(0, 0));

	//���ÿ��е����֣�����create������и�ֵ����ΪĬ�ϵ��������Щ
	CCLabelTTF * label = CCLabelTTF::create();
	//����label���ַ���
	label->setString(str.getCString());
	//��������Ĵ�С
	label->setFontSize(strSize);
	//�����������ɫ
	label->setColor(strColor);
	//�����ֵ�λ��
	label->setPosition(ccp(size.width / 2, size.height / 2));
	addChild(label);

	return true;
}

//ȡarray
CCArray * Block::getBlocksArray()
{
	return array;
}

void Block::moveDownAndCleanUp()
{
	//�кż�һ
	_lineIndex--;
	//������һ����
	CCMoveTo * to = CCMoveTo::create(0.01,
		ccp(getPositionX(), getPositionY() - winSize.height / 4));
	this->runAction(to);

	//�ӽڵ�������
	if (_lineIndex < 0)
	{
		//������������,���ｫ���ü�����1��������Ӱ����Ⱦ��������
		array->removeObject(this);
		removeFromParentAndCleanup(true);
	}
}