/* Waiting For Wind

   ͳһ��������
   1.��������ĸ��д
   2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�
   
   �������ʦ��֪��
   1.��Ҫ�Ķ��������ķ������ƣ���Ķ������֪
   */

#ifndef MAIN_GAME_MENU_H
#define MAIN_GAME_MENU_H

#include "cocos2d.h"
#include "BasicScene.h"

USING_NS_CC;

class MainGameMenu
{
public:
	MainGameMenu(void) : game_menu(nullptr) {}
	~MainGameMenu(void);

	// ��ʼ��game_menu����game_menu�����MenuItem����ΪMenuItemע��ص�����
	bool init();

	Menu* getGameMenu();

	void onBackItem(Ref* pSender);
	void onReplayItem(Ref* pSender);

private:
	Menu* game_menu;
};

#endif

