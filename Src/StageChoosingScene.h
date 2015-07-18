/* Waiting For Wind  @ Team WDLang

   ͳһ��������
   1.��������ĸ��д
   2.��������������������ĸСд����������ÿ��������������ĸ��д���磺 addChild(), runAction()�ȵ�
   3.������ȫСд�����ʼ����»��߷ָ�磺x_position, y_position�ȵȡ�
   
   StageChoosingScene�������ʦ��֪��
   1.����������ѡ��ؿ���
   2.�������ʦ����Ϊÿ��ѡ��ť��ӻص���������ͬʱ������Ӧ�Ĺؿ�������
   3.�˳���������ӷ��ذ�ť����Ϊ��ע��ص�������
   */

#ifndef STAGECHOOSINGSCENE
#define STAGECHOOSINGSCENE

#include "cocos2d.h"
#include "DramaScene.h"
#include "DramaScene2.h"
#include "DramaScene4.h"

USING_NS_CC;

class StageChoosingScene : public Layer
{
public:
	static int stageNum;

public:
	static Scene* createScene();

	virtual bool init();


	void initMenu();


	void onLuffyStage1(Ref* pSender);
	void onLuffyStage2(Ref* pSender);
	void onWindComesStage1(Ref* pSender);
	void onBack(Ref* pSender);

	CREATE_FUNC(StageChoosingScene);
};

#endif

