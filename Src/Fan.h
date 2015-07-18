/* Waiting For Wind

ͳһ��������
1.��������ĸ��д
2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�

������Fan
Fan��������ʦ��֪���¹���
1.��λ�õ�ǰLayer��Hatʵ���� �涨Hatʵ����tag=0��ֻ�����this->getParent()->getChildByTag(0);
2.Fan�����create���������������ṩ�κνӿڣ���������к��������ɳ������ʦ�Լ��涨��
*/

#ifndef FAN_H
#define FAN_H

#include "cocos2d.h"

USING_NS_CC;

/* Fan����ʵ�����¹���
1.�ַ�����¼���ʵ���С�
2.�ڵ����Ӧ�����У����㴵�緶Χ������Χ�ڵ�Hat���𣬲�ִ�д��Ķ�����
3.����ģ�Fan����Ҫ�ṩ�κζ���ӿ�
4.����������ʦ�Ķ���create�ӿڣ����֪*/

class Fan : public Sprite
{
public:
	Fan(void);
	~Fan(void);

	/* create�����������£�
	���������direction������������ӦͼƬ��Fanʵ����*/
	static Fan* create(const int direction);
	
	//��ʼ����  
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	//��������  
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

	
	// ָʾ����
	static const int NORTH = 1;
	static const int NORTH_EAST = 2;
	static const int EAST = 3;
	static const int SOUTH_EAST = 4;
	static const int SOUTH = 5;
	static const int SOUTH_WEST = 6;
	static const int WEST = 7;
	static const int NORTH_WEST = 8;
	void setDirection(int d);

private:
	int direction;
};

#endif

