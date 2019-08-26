#pragma once
#include "ofMain.h"
#include "ofxRelaysBase.h"
#include "ofxXmlSettings.h"
#include "ofxRelaysMgr.h"
/************************************************************************/
/* describe:都匀三线展厅
/* file describe:控制处理类
/* author:hui
/* date:2017.9.27
/************************************************************************/
class controlHandler
{
public:
	~controlHandler();

	struct lightNode
	{
		int relayIndex;
		int loopIndex;
	};

	static controlHandler & getInstance();

	void onOffLED(bool _state);
	void onOffLED(int _index, bool _state);

	void onOffLight(int _index, bool _state);
	void onOffAllLight(bool _state);

	void singleOnOffLight(int _relayIndex,int _loopIndex,int _state);
private:
	controlHandler();
	void setup();

	bool sendTcpCmd(string _ip, int _port, string _cmd);		//发送TCP指令
	bool sendTcpCmd(string _ip,int _port,const char *_data, int _size);
	bool sendUdpCmd(string _ip, int _port, string _cmd);		//发送UDP指令
	bool sendUdpCmd(string _ip, int _port, const char *_data, int _size);
	bool sendSerialCmd(int _nCom, int _nBaud, const char *_cmd, int _size);	//发送串口指令


	enum 
	{
		RELAY_LIGHT,
		
		RELAY_NUMS
	};

	ofxRelaysMgr relayMgr;

	void onOffLight(const vector<lightNode> & _indexs, bool _state);


	enum {
		INDEXS_ONE_AREA_LIGHT,
		INDEXS_TWO_AREA_LIGHT,
		INDEXS_THREE_AREA_LIGHT,
		NUMS_LIGHT_INDEX,
	};
	map<int, vector<lightNode>> lightIndexs;
	void loadLightSetting();
};

