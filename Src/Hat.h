/* Waiting For Wind @ Team WDLang

   ͳһ��������
   1.��������ĸ��д
   2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�*/

#ifndef HAT_H
#define HAT_H

#include "cocos2d.h"

USING_NS_CC;

class Hat : public Sprite
{
public:
	Hat(void);
	~Hat(void);

	void setVelocity(Vec2 velocity);
	void onRemove();
	void removeItself();
	void comeOut();

	static Hat* create(int hat_num);

	int hat_num;
};

#endif

