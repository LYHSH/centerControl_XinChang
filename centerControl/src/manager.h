/************************************************************************/
/* project name:��������չ��
/* file describe����������
/* date:2017.9.27
/* author:hui
/************************************************************************/
#ifndef MANAGER_H
#define MANAGER_H
#include "controlClass.h"
#include "UImanager.h"
#include "ofxNetwork.h"

class manager
{
public:
	manager(void);
	~manager(void);

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	void shutdown();

	UImanager ui;

	controlClass hardControl;

	ofxUDPManager orderReceiver;				//ipad ָ�����


	float lastTime;
};
#endif // !MANAGER_H


