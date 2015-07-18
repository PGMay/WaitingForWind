/* Waiting For Wind

   统一命名规则：
   1.类名首字母大写
   2.方法名（函数名）首字母小写，接下来的每个独立单词首字母大写，如： addChild(), runAction()等等
   3.变量名全小写，单词间用下划线分割，如：x_position, y_position等等。*/

#ifndef GAME_SCENE2_H
#define GAME_SCENE2_H

#include "BasicScene.h"

class GameScene2 : public BasicScene
{
public:
	virtual bool init();
	static Scene* createScene();
	void resetHatPosition();
	CREATE_FUNC(GameScene2);
};

#endif

