#pragma once
#include "ofxDataSenderFacory.h"
#include "ofxXmlSettings.h"
#include "ofxDataSenderMgr.h"
class ofxHexCmdsMgr
{
public:
	ofxHexCmdsMgr();
	~ofxHexCmdsMgr();

	void setup();
	void setup(string _filename);

	void setOn(int _index);
	void setOff(int _index);

	void setAllOn();
	void setAllOff();

	int size();

	static string const str_hex_name;
	static string const str_char_name;
	enum STR_TYPE
	{
		STR_HEX,
		STR_CHAR,
	};

	struct HexCmdNode 
	{
		string onHexCmd;
		string offHexCmd;
		STR_TYPE type;
		
	};

private:
	void loadSetting(string _file);
	bool checkOut(int _index);
	void sendHexMsg(string _hexMsg);
	void sendMsg(string _msg);
	void sendMsgByType(STR_TYPE _type, string _msg);
	ofxDataSenderMgr senderMgr;
	ofxDataSender * sender;
	string comStr;
	int nBaud;

	vector<HexCmdNode> hexCmds;
};

