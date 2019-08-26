#include "ofxHexCmdsMgr.h"

const string ofxHexCmdsMgr::str_hex_name = "STR_HEX";
const string ofxHexCmdsMgr::str_char_name = "STR_CHAR";
ofxHexCmdsMgr::ofxHexCmdsMgr()
{
}


ofxHexCmdsMgr::~ofxHexCmdsMgr()
{
}

void ofxHexCmdsMgr::setup()
{
	loadSetting("control/hexCmds.xml");
	senderMgr.setup("control/hexCmds.xml");
	if (senderMgr.size())
	{
		sender = senderMgr.getSender(0);
	}
	else
	{
		sender = ofxDataSenderFacory::createSerialSender(comStr, nBaud);
	}
}

void ofxHexCmdsMgr::setup(string _filename)
{
	loadSetting(_filename);
	senderMgr.setup(_filename);
	if (senderMgr.size())
	{
		sender = senderMgr.getSender(0);
	}
	else
	{
		sender = ofxDataSenderFacory::createSerialSender(comStr, nBaud);
	}
}

void ofxHexCmdsMgr::setOn(int _index)
{
	if (!checkOut(_index))return;
	
	ofLogNotice(OF_FUNCTION_NAME) <<_index<<":          on" << endl;
	sendMsgByType(hexCmds[_index].type,hexCmds[_index].onHexCmd);
}

void ofxHexCmdsMgr::setOff(int _index)
{
	if (!checkOut(_index))return;
	ofLogNotice(OF_FUNCTION_NAME) << _index << ":          off" << endl;
	sendMsgByType(hexCmds[_index].type, hexCmds[_index].offHexCmd);
}

void ofxHexCmdsMgr::setAllOn()
{
	for (int i = 0; i < hexCmds.size(); i++)
	{
		sendMsgByType(hexCmds[i].type, hexCmds[i].onHexCmd);
		Sleep(100);
	}
}

void ofxHexCmdsMgr::setAllOff()
{
	for (int i = 0; i < hexCmds.size(); i++)
	{
		sendMsgByType(hexCmds[i].type, hexCmds[i].offHexCmd);
		Sleep(100);
	}
}

int ofxHexCmdsMgr::size()
{
	return hexCmds.size();
}

void ofxHexCmdsMgr::loadSetting(string _file)
{
	ofxXmlSettings xml;
	xml.loadFile(_file);

	comStr = xml.getValue("COM", "");
	nBaud = xml.getValue("BAUD", 115200);

	int nums = xml.getNumTags("node");
	hexCmds.resize(nums);
	for (int i = 0; i < nums; i++)
	{
		xml.pushTag("node", i);
		hexCmds[i].onHexCmd = xml.getValue("on", "");
		hexCmds[i].offHexCmd = xml.getValue("off", "");
		string strType = xml.getValue("type", str_hex_name);
		if (strType == str_hex_name)
		{
			hexCmds[i].type = STR_HEX;
		}
		else if (strType == str_char_name)
		{
			hexCmds[i].type = STR_CHAR;
		}
		else
		{
			hexCmds[i].type = STR_HEX;
		}
		xml.popTag();
	}
}

bool ofxHexCmdsMgr::checkOut(int _index)
{
	bool res = true;
	res &= _index >= 0;
	res &= _index < hexCmds.size();
	return res;
}

void ofxHexCmdsMgr::sendHexMsg(string _hexMsg)
{
	string msg = ofHexToString(_hexMsg);
	sender->sendData(msg.c_str(), msg.size());
}

void ofxHexCmdsMgr::sendMsg(string _msg)
{
	string msg = _msg;
	sender->sendData(msg.c_str(), msg.size());
}

void ofxHexCmdsMgr::sendMsgByType(STR_TYPE _type, string _msg)
{
	switch (_type)
	{
	case ofxHexCmdsMgr::STR_HEX:
		sendHexMsg(_msg);
		break;
	case ofxHexCmdsMgr::STR_CHAR:
		sendMsg(_msg);
		break;
	default:
		break;
	}
}