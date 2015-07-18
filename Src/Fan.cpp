#include "Fan.h"

Fan::Fan(void)
{
}


Fan::~Fan(void)
{
}

Fan* Fan::create(const int direction)
{
	/* To do �������������Ҫ��ӵĴ���*/
	auto fan = new Fan();

	auto str = String::createWithFormat("Fan.png", direction);

	if (fan != nullptr && fan->initWithFile(str->getCString()))
	{
		// ˵����÷��ȵķ���
		fan->setDirection(direction);
		
		//touch��Ҫ��Ӽ�����
		auto listener = EventListenerTouchOneByOne::create();
		
		//������
		listener->setSwallowTouches(true);

		//�����Ļص�����
		listener->onTouchBegan = CC_CALLBACK_2(Fan::onTouchBegan, fan);
		listener->onTouchEnded = CC_CALLBACK_2(Fan::onTouchEnded, fan);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, fan);

		// Create PhysicsBody
		// ��ȷ�Ǹ����������Զ�����
		auto body = PhysicsBody::createEdgeBox(fan->getContentSize());
		fan->setPhysicsBody(body);

		// Rotate fan
		fan->setRotation((direction-1)*45);

		fan->autorelease();

	}
	else
	{
		delete fan;
		fan = nullptr;
	}
	return fan;
}



void Fan::setDirection(int d)
{

	direction = d;
}

bool Fan::onTouchBegan(Touch *pTouch, Event *pEvent)  {

	auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
	
	Vec2 locationInNode = target->convertToNodeSpace(pTouch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	int windWidth = this->getContentSize().width;
	int windHeight = 600;
	int windSpeed = 100;

	// ͨ���жϵ����Χ�Ƿ��ڷ��ȵ�������ȷ���Ƿ�㵽����
	if (rect.containsPoint(locationInNode))
	{
		auto fanPos = this->getPosition();

		// ������8�������׼��λ
		int dir[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };

		// ����tag���ҵ�ñ��
		auto hat = this->getParent()->getChildByTag(0);

		// ñ�ӵ�����
		auto hatPos = hat->getPosition();

		// ��ת�Ӷ�Ӧ�ĽǶ�
		// ���������б�ģ� �����Ⱥ�ñ����ת������
		// Ȼ���ж�ֻ���жϾ��εı߿򼴿ɣ�
		// �൱����ת������ϵ�� ������Ĵ���
		auto g = hatPos.rotateByAngle(fanPos, 3.14 / 4 * (direction - 1));

		// ֻ���ж���ת֮��������Ƿ��ڳ��紦
		if (abs(g.x - fanPos.x) < windWidth / 2 && g.y - fanPos.y < windHeight && g.y > fanPos.y) {
			hat->getPhysicsBody()->setVelocity(Vec2(dir[direction - 1][0] * windSpeed, dir[direction - 1][1] * windSpeed));
		}
	}
	return false;

}

void Fan::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//����д����������Ҫʵ�ֵĹ���  
}
