#pragma once
/************************************************************************/
/* project name:
/* file describe������ʵ����
/* date:2018/1/30
/* author:hui
/************************************************************************/
#define POCO_NO_UNWINDOWS
#include "ofxMacMgr.h"
#include "ofxPjMgr.h"
#include "ofxRemoteVideoControlMgr.h"
#include "myContants.h"
#include "ofxNetwork.h"
#include "ofxXmlSettings.h"
#include "ofMain.h"
#include "ofxRelaysMgr.h"
#include "ofxHexCmdsMgr.h"
#include "ofxRelayLoopMgr.h"

#define PJ_IR_CONTROL

class controlClass : public ofThread
{
public:
	controlClass(void);
	~controlClass(void);

	void setup();
	void update();
	void getMessage(int msg);
	void addOrder(int order);

	void threadedFunction();
	void exit(ofEventArgs &e);

	void keyPressed(int key);

	bool sendUdpCmd(string _ip,int port,string _cmd);		//����UDPָ��
private:
	void macControl(int _startIndex,int _nums,bool _on);
	void pjControl(int _startIndex, int _nums, bool _on);
	void splicingControl(int _index,bool _state);
	void ledControl(int _index, bool _state);

	void movieControl(int _index,int _cmdType);
	void splicingScreenControl(int _index, int _cmdType);

	string convertEncryStr(string _source);

	static string const dir;
	queue<int> orders;						//ָ������


	//��������
	ofxMacMgr macMgr;
	//ͶӰ��
	ofxPjMgr pjMgr;
	//��Ƶ����
	ofxRemoteVideoControlMgr videoMgr;

	//UDP���緢����
	ofxUDPManager udpConnection;	

	ofxHexCmdsMgr cmdsMgr;			//���ڶ����ָ���

	ofxRelayLoopMgr relayLoopMgr;		//�̵���������
};

