#include "manager.h"
#include "orderHandler.h"

manager::manager(void)
{
}


manager::~manager(void)
{
}

void manager::setup()
{
	ui.setup();
	hardControl.setup();
	orderReceiver.Create();
	orderReceiver.Bind(PORT_CENTER_IPAD_CMD);
	orderReceiver.SetNonBlocking(true);

	lastTime = 0.0f;
}

void manager::update()
{
	ui.update();
	//中控软件本机指令

	queue<int> & orders = orderHandler::getInstance().getOrderQueue();
	while (orders.size())
	{
		int order = orders.front();
		ofLogNotice()<<"mac:"<<order<<endl;
		hardControl.addOrder(order);

		orders.pop();
	}

	//ipad发送过来的中控指令
	char msg[100] = "";
	orderReceiver.Receive(msg,100);
	string str = msg;
	if (str != "")
	{
		int order = ofToInt(str);
		if (order >= MAIN_PAGE_ALL_CONTROL && order <= ALL_NUMS)
		{
			ofLogNotice() << "ipad:" << order << endl;
			hardControl.addOrder(order);
		}
	}

	hardControl.update();
}

void manager::draw()
{
	ui.draw();
}

void manager::keyPressed(int key)
{
	ui.keyPressed(key);
}

void manager::keyReleased(int key)
{
	ui.keyReleased(key);
}

void manager::mouseMoved(int x, int y)
{
	ui.mouseMoved(x, y);
}

void manager::mouseDragged(int x, int y, int button)
{
	ui.mouseDragged(x, y, button);
}

void manager::mousePressed(int x, int y, int button)
{
	ui.mousePressed(x, y, button);
}

void manager::mouseReleased(int x, int y, int button)
{
	ui.mouseReleased(x, y, button);
}

void manager::shutdown()
{
	hardControl.addOrder(MANAGE_PAGE_ALL_OFF);
}