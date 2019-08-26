#include "controlHandler.h"
#include "ofxNetwork.h"
#include "ofxSerial.h"
#include "ofxUdpDataSender.h"
#include "ofxTcpDataSender.h"
#include "ofxSerialDataSender.h"
#include "ofxScreenCmd.h"
#include "ofxRelayFactory.h"


controlHandler::controlHandler()
{
	setup();
}


controlHandler::~controlHandler()
{
}

controlHandler & controlHandler::getInstance()
{
	static controlHandler mgr;
	return mgr;
}

void controlHandler::onOffLED(bool _state)
{
	static const unsigned char onCmd[] = {
		0x55,0xaa,0x00,0x4d,
		0xfe,0x00,0x00,0x00,
		0x00,0x00,0x01,0x00,
		0x10,0x00,0x00,0x05,
		0x01,0x00,0x00,0xb7,
		0x56 };
	static const unsigned char offCmd[] = {
		0x55,0xaa,0x00,0x4f,
		0xfe,0x00,0x00,0x00,
		0x00,0x00,0x01,0x00,
		0x10,0x00,0x00,0x05,
		0x01,0x00,0x01,0xba,
		0x56 };

	//static const unsigned char onCmd[] = {
	//	0x55,0xaa,0x00,0x4d,
	//	0xfe,0x00,0x00,0x00,
	//	0x00,0x00,0x01,0x00,
	//	0x10,0x00,0x00,0x05,
	//	0x01,0x00,0x00,0xb7,
	//	0x56 };
	//static const unsigned char offCmd[] = {
	//	0xaa,0x55,0x00,0x4f,
	//	0x00,0xfe,0x00,0x00,
	//	0x00,0x00,0x01,0x00,
	//	0x10,0x00,0x00,0x05,
	//	0x00,0x00,0xb8,0x56,
 //};

	static int const numLedCom = 13;
	static int const nBaudLedCom = 115200;
	if (_state)
	{
		sendSerialCmd(numLedCom, nBaudLedCom, (char *)onCmd,sizeof(onCmd)/sizeof(char));
	}
	else
	{
		sendSerialCmd(numLedCom, nBaudLedCom, (char *)offCmd, sizeof(offCmd) / sizeof(char));
	}
}

void controlHandler::onOffLED(int _index, bool _state)
{

}

void controlHandler::onOffLight(int _index, bool _state)
{
	if (_index >= 0 && _index < lightIndexs.size())
	{
		onOffLight(lightIndexs[_index], _state);
	}
}

void controlHandler::onOffAllLight(bool _state)
{
	for (int i = 0;i < lightIndexs.size(); i++)
	{
		onOffLight(lightIndexs[i], _state);
		Sleep(1000);
	}
}

void controlHandler::singleOnOffLight(int _relayIndex, int _loopIndex,int _state)
{
	relayMgr.begin(_relayIndex);
	_state ? relayMgr.setOn(_loopIndex) : relayMgr.setOff(_loopIndex);
	relayMgr.end();
}


void controlHandler::setup()
{
	relayMgr.setup("control/relay.xml");

	loadLightSetting();
}

bool controlHandler::sendTcpCmd(string _ip, int _port, string _cmd)
{
	return sendTcpCmd(_ip,_port,_cmd.c_str(), _cmd.size());
}

bool controlHandler::sendTcpCmd(string _ip, int _port, const char *_data, int _size)
{
	static ofxTcpDataSender sender;

	sender.setup(_ip, _port);
	return sender.sendData(_data, _size);
}

bool controlHandler::sendUdpCmd(string _ip, int _port, string _cmd)
{
	return sendUdpCmd(_ip, _port, _cmd.c_str(), _cmd.size());
}

bool controlHandler::sendUdpCmd(string _ip, int _port, const char *_data, int _size)
{
	static ofxUdpDataSender sender;
	ofLogNotice("controlHandler") << "[UDP]" << "ip:" << _ip << "port:" << _port << "cmd:" << _data << endl;

	sender.setup(_ip, _port);
	return sender.sendData(_data, _size);
}

bool controlHandler::sendSerialCmd(int _nCom, int _nBaud, const char *_cmd, int _size)
{
	static ofxSerialDataSender sender;

	sender.close();
	Sleep(100);

	ofLogNotice() <<"[SERIAL]"<< "com" << _nCom << ",baud" << _nBaud << " send:" << _cmd << endl;
	if (!sender.setup(_nCom, _nBaud))
	{
		ofLogError("controlHandler") << "com" << _nCom << "   open error" << endl;
		return false;
	}

	return sender.sendData(_cmd, _size);
}

void controlHandler::onOffLight(const vector<lightNode> & _indexs, bool _state)
{
	int nums = _indexs.size();

	if (_state)
	{
		for (int i = 0; i < nums; i++)
		{
			lightNode  node = _indexs[i];
			relayMgr.begin(node.relayIndex);
			relayMgr.setOn(node.loopIndex);
			relayMgr.end();
		}
	}
	else
	{
		for (int i = 0; i < nums; i++)
		{
			lightNode  node = _indexs[i];
			relayMgr.begin(node.relayIndex);
			relayMgr.setOff(node.loopIndex);
			relayMgr.end();
		}
	}

	relayMgr.end();
}

void controlHandler::loadLightSetting()
{
	ofxXmlSettings xml;
	xml.load("control/light.xml");

	int nums = xml.getNumTags("light");

	for (int i = 0; i < nums; i++)
	{
		xml.pushTag("light", i);

		vector<lightNode> indexArr;
		int nodeNums = xml.getNumTags("node");
		indexArr.resize(nodeNums);

		for (int nodeIndex = 0; nodeIndex < nodeNums; nodeIndex++)
		{
			xml.pushTag("node", nodeIndex);
			indexArr[nodeIndex].relayIndex = xml.getValue("relay_index", 0);
			indexArr[nodeIndex].loopIndex = xml.getValue("loop_index", 0);
			xml.popTag();
		}

		lightIndexs[i] = indexArr;												//´æ´¢µ½ÄÚ´æ
		xml.popTag();
	}
}
