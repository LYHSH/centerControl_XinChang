#include "controlClass.h"
#include "controlHandler.h"
#include "cmdConverter.h"
const string controlClass::dir = "control/";

#define CENTER_DEBUG 0
controlClass::controlClass(void)
{
}


controlClass::~controlClass(void)
{
}

void controlClass::setup(){
	ofxXmlSettings xml;
#pragma region ����
	macMgr.setup(dir + "computer.xml");
#pragma endregion ����
	
#pragma region ͶӰ��
	pjMgr.setup(dir + "projector.xml");
#pragma endregion ͶӰ��

#pragma region ��Ƶ���ſ���
	videoMgr.setup(dir + "video.xml");
#pragma endregion ��Ƶ���ſ���

#pragma region ƴ��������
//	splicingScreenMgr.setup(dir + "splicingScreen.xml");
#pragma endregion ƴ��������

#pragma region LED������
//	myLedMgr.setup(dir + "led.xml");
#pragma endregion LED������

#pragma region �����豸
//	cmdsMgr.setup("control/hexCmds.xml");
#pragma endregion 

#pragma region �̵���������
	relayLoopMgr.setup();
#pragma endregion �̵���������
	

	//udpָ���
	udpConnection.Create();
	udpConnection.SetNonBlocking(true);

	ofAddListener(ofEvents().exit,this, &controlClass::exit);				
	startThread();
}

void controlClass::update(){
	
}

void controlClass::getMessage(int msg){	

#pragma region �������
	if (msg == MANAGE_PAGE_ALL_ON)								//ȫ������
	{
		ofLogNotice() << "ALL_ON : " << endl;
		//�̵���ȫ��
		controlHandler::getInstance().onOffAllLight(true);
		//ͶӰ��ȫ��
		int const sendNums = 1;
		for (int i = 0; i < sendNums;i++)
		{
			pjMgr.setAllOn();
		}

		//LEDȫ��
	//	myLedMgr.setAllOn();
		//ƴ����ȫ��
	//	splicingScreenMgr.setAllOn();
		//����ȫ��	
		macMgr.setAllOn();
		
	//	cmdsMgr.setAllOn();

	}
	else if (msg == MANAGE_PAGE_ALL_OFF)						//ȫ���ر�
	{
		ofLogNotice() << "ALL_OFF : " << endl;
		//����ȫ��
		macMgr.setAllOff();
	//	cmdsMgr.setAllOff();
//		cmdsMgr.setAllOff();
		//ͶӰ��ȫ��
		int const sendNums = 1;
		for (int i = 0; i < sendNums; i++)
		{
			pjMgr.setAllOff();
		}
		

		//LEDȫ��
	//	myLedMgr.setAllOff();
		//ƴ����ȫ��
	//	splicingScreenMgr.setAllOff();
	//�̵���ȫ��
		controlHandler::getInstance().onOffAllLight(false);
	}
#pragma endregion �������
	
#pragma region ��������
#ifdef MAC_CONTORL_PAGE_1_H
	else if (msg > MAC_PAGE_BEGIN && msg < MAC_PAGE_END)
	{
		if (MAC_CONTROL_ALL_ON == msg)
		{
			macMgr.setAllOn();
	//		cmdsMgr.setAllOn();
		}
		else if (MAC_CONTROL_ALL_OFF == msg)
		{
			macMgr.setAllOff();
	//		cmdsMgr.setAllOff();
		}
#ifdef MAC_CONTORL_PAGE_1_H
		else if(msg > MAC_CONTROL_PAGE_1_BEGIN && msg < MAC_CONTROL_PAGE_1_END)
		{
			int temp = msg - MAC_CONTROL_PAGE_1_BEGIN - 1;
			int macIndex = temp / 2;
			bool onoff = !(temp % 2);

			macControl(macIndex, 1, onoff);
		}
#endif
#ifdef MAC_CONTORL_PAGE_2_H
		else if (msg > MAC_CONTROL_PAGE_2_BEGIN && msg < MAC_CONTROL_PAGE_2_END)
		{
			int temp = msg - MAC_CONTROL_PAGE_2_BEGIN - 1;
			int macIndex = temp / 2 + 14;
			bool onoff = !(temp % 2);

			macControl(macIndex, 1, onoff);
		}
#endif

#ifdef MAC_CONTORL_PAGE_3_H
		else if (msg > MAC_CONTROL_PAGE_3_BEGIN && msg < MAC_CONTROL_PAGE_3_END)
		{
			int temp = msg - MAC_CONTROL_PAGE_3_BEGIN - 1;
			int macIndex = temp / 2 + 14 * 2;
			bool onoff = !(temp % 2);

			macControl(macIndex, 1, onoff);
		}
#endif
		
	}
#endif
	

	
#pragma endregion ��������

#pragma region ͶӰ����
#ifdef PJ_CONTORL_PAGE_H
	else if (msg > PROJECT_CONTROL_PAGE_BEGIN && msg < PROJECT_CONTROL_PAGE_END)
	{
		if (PROJECT_CONTROL_PAGE_ALL_ON == msg)
		{
			pjMgr.setAllOn();
		}
		else if (PROJECT_CONTROL_PAGE_ALL_OFF == msg)
		{
			pjMgr.setAllOff();
		}
		else
		{
#ifdef PJ_CONTORL_PAGE_1_H
			if (msg > PJ_CONTROL_PAGE_1_BEGIN && msg < PJ_CONTROL_PAGE_1_END)
			{
				int temp = msg - PJ_CONTROL_PAGE_1_BEGIN - 1;
				int index = temp / 2;
				bool onoff = !(temp % 2);

				pjControl(index, 1, onoff);
			}
#endif
			
		}

	}
#endif
	
#pragma endregion ͶӰ����

#pragma region LED����
#ifdef LED_CONTORL_PAGE_H
	else if (msg > LED_CONTROL_PAGE_BEGIN && msg < LED_CONTROL_PAGE_END)
	{
#ifdef LED_CONTORL_PAGE_1_H
		if (msg > LED_CONTROL_PAGE_1_BEGIN && msg < LED_CONTROL_PAGE_1_END)
		{
			int temp = msg - LED_CONTROL_PAGE_1_BEGIN - 1;
			int index = temp / 2;
			bool onoff = !(temp % 2);

 			ledControl(index, onoff);
		}
#endif
	}
#endif
	
#pragma endregion LED����

#pragma region ƴ�ӿ���
#ifdef SPLICING_SCREEN_CONTORL_PAGE_H
	else if (msg > SPLICING_SCREEN_CONTROL_PAGE_BEGIN && msg < SPLICING_SCREEN_CONTROL_PAGE_END)
	{
#ifdef SPLICING_SCREEN_CONTORL_PAGE_1_H
		if (msg > SPLICING_SCREEN_CONTROL_PAGE_1_BEGIN && msg < SPLICING_SCREEN_CONTROL_PAGE_1_END)
		{
			int temp = msg - SPLICING_SCREEN_CONTROL_PAGE_1_BEGIN - 1;
			int index = temp / 2;
			bool onoff = !(temp % 2);

			//splicingControl(index, onoff);
			onoff ? cmdsMgr.setOn(index) : cmdsMgr.setOff(index);
		}
#endif
	}
#endif
#pragma endregion ƴ�ӿ���

#ifdef LIGHT_CONTROL_PAGE_H
#pragma region ��������
	else if (msg >= LIGHT_PAGE_BEGIN && msg < LIGHT_PAGE_END)
	{
		if (LIGHT_PAGE_ALL_ON == msg)
		{
			relayLoopMgr.setAllOn();
		}
		else if (LIGHT_PAGE_ALL_OFF == msg)
		{
			relayLoopMgr.setAllOff();
		}
		else if (msg > LIGHT_CONTORL_PAGE_1_BEGIN && msg < LIGHT_CONTORL_PAGE_1_END)
		{
			int temp = msg - LIGHT_CONTORL_PAGE_1_BEGIN - 1;
			int index = temp / 2;
			bool onoff = !(temp % 2);

			onoff ? relayLoopMgr.setOn(index) : relayLoopMgr.setOff(index);
		}
		else if (msg > LIGHT_CONTORL_PAGE_2_BEGIN && msg < LIGHT_CONTORL_PAGE_2_END)
		{
			int temp = msg - LIGHT_CONTORL_PAGE_2_BEGIN - 1;
			int index = temp / 2 + 14;
			bool onoff = !(temp % 2);

			onoff ? relayLoopMgr.setOn(index) : relayLoopMgr.setOff(index);
		}
	}
#pragma endregion ��������
#endif



#pragma region �ιۿ���
#ifdef VISIT_CONTROL_PAGE_H
	else if (msg > VISIT_PAGE_BEGIN && msg < VISIT_PAGE_END)
	{
#ifdef VISIT_CONTORL_PAGE_1_H
		if (msg > VISIT_CONTROL_PAGE_1_BEGIN && msg < VISIT_CONTROL_PAGE_1_END)
		{
			if(msg > VISIT_CONTROL_PAGE_1_BEGIN && msg < VISIT_CONTROL_PAGE_1_END)
			{
				if (VISIT_CONTROL_PAGE_1_GONG_YE_PLAY == msg)
				{
					static int port = 14666;
					static string cmd = "CMD_GOTO_SWITCH";
					vector<string> ips = videoMgr.getIPs(0);
					for (int i = 0; i < ips.size(); i++)
					{
						sendUdpCmd(ips[i], port, cmd);
					}
				}
				else if (VISIT_CONTROL_PAGE_1_GONG_YE_STOP == msg)
				{
					static int port = 14666;
					static string cmd = "CMD_GOTO_LOOP";
					vector<string> ips = videoMgr.getIPs(0);
					for (int i = 0; i < ips.size(); i++)
					{
						sendUdpCmd(ips[i], port, cmd);
					}
				}
				else if (msg >= VISIT_CONTROL_PAGE_1_XU_TING_MOVIE_1 && msg <= VISIT_CONTROL_PAGE_1_XU_TING_MOVIE_2)
				{
					int movieIndex = msg - VISIT_CONTROL_PAGE_1_XU_TING_MOVIE_1;

					videoMgr.play(2, movieIndex);				//�������ڵ�����
				}
				else
				{
					int index = 1;
					int temp = msg - VISIT_CONTROL_PAGE_1_XU_TING_MOVIE_2 - 1;

					int cmdType = temp % 5;
					index += temp / 5;
					movieControl(index, cmdType);
				}
			}
			
		}
#endif // VISIT_CONTORL_PAGE_1_H
#ifdef VISIT_CONTORL_PAGE_2_H
		else if (msg > VISIT_CONTROL_PAGE_2_BEGIN && msg < VISIT_CONTROL_PAGE_2_END)
		{
			int index = 5;
			int temp = msg - VISIT_CONTROL_PAGE_2_BEGIN - 1;
			index += temp / 5;
			int cmdType = temp % 5;
			movieControl(index, cmdType);
		}
#endif // VISIT_CONTORL_PAGE_2_H
#ifdef VISIT_CONTORL_PAGE_3_H
		else if (msg > VISIT_CONTROL_PAGE_3_BEGIN && msg < VISIT_CONTROL_PAGE_3_END)
		{
			int index = 10;
			if (msg >= VISIT_CONTROL_PAGE_3_VIDEO_1 && msg <= VISIT_CONTROL_PAGE_3_VIDEO_2)
			{
				int temp = msg - VISIT_CONTROL_PAGE_3_VIDEO_1;
				videoMgr.play(index, temp);
			}
			else if (msg >= VISIT_CONTROL_PAGE_3_VIDEO_PLAY && msg <= VISIT_CONTROL_PAGE_3_VIDEO_VOLUME_SUB)
			{
				int temp = msg - VISIT_CONTROL_PAGE_3_VIDEO_PLAY;

				int cmdType = temp % 5;
				movieControl(index, cmdType);
			}
		}
#endif // VISIT_CONTORL_PAGE_3_H
	}
#endif
	
#pragma endregion �ιۿ���
}

void controlClass::addOrder(int order){
	lock();
	orders.push(order);
	unlock();
}

void controlClass::threadedFunction(){
	while (isThreadRunning())
	{
		if (orders.size()>0)
		{
			lock();
			int order = orders.front();
			orders.pop();
			unlock();
			getMessage(order);
		}
	}
}

void controlClass::exit(ofEventArgs &e){
	waitForThread();

	ofRemoveListener(ofEvents().exit,this,&controlClass::exit);
}

void controlClass::keyPressed(int key)
{
	
}

bool controlClass::sendUdpCmd(string _ip,int _port,string _cmd)
{
	ofLogNotice()<<"ip:"<<_ip<<"port:"<<_port<<"cmd:"<<_cmd<<endl;

	int res = 0;
	udpConnection.Connect(_ip.c_str(),_port);
	res = udpConnection.Send(_cmd.c_str(),_cmd.size());
	return res;
}

void controlClass::macControl(int _startIndex, int _nums, bool _on)
{
	for (int i = 0; i < _nums; i++)
	{
		int macIndex = i + _startIndex;
		if (macIndex >= macMgr.size())
		{
			ofLogError() << "mac index out of range" << endl;
			return;
		}
		if (_on)
		{
			if (!CENTER_DEBUG)
			{
				macMgr.setOn(macIndex);
		//		cmdsMgr.setOn(macIndex);
			}
			else
			{
				ofLogNotice() << macMgr.getMAC(macIndex) << ":on" << endl;
			}
		}
		else
		{
			if (!CENTER_DEBUG)
			{
				macMgr.setOff(macIndex);

		//		cmdsMgr.setOff(macIndex);
			}
			else
			{
				ofLogNotice() << macMgr.getIP(macIndex) << ":off" << endl;
			}
		}
	}
}

void controlClass::pjControl(int _startIndex, int _nums, bool _on)
{
	for (int i = 0; i < _nums; i++)
	{
		int pjIndex = i + _startIndex;
		if (pjIndex >= pjMgr.size())
		{
			ofLogError() << "pj index out of range" << endl;
			return;
		}
		if (_on)
		{
			if (!CENTER_DEBUG)
			{
 				pjMgr.setOn(pjIndex);
			}
			else
			{
				ofLogNotice() << pjMgr.getIP(pjIndex) << ":on" << endl;
			}
		}
		else
		{
			if (!CENTER_DEBUG)
			{
				pjMgr.setOff(pjIndex);
			}
			else
			{
				ofLogNotice() << pjMgr.getIP(pjIndex) << ":off" << endl;
			}
		}
	}
}

void controlClass::ledControl(int _index, bool _state)
{
//	_state ? myLedMgr.setOn(_index) : myLedMgr.setOff(_index);
}

void controlClass::splicingControl(int _index, bool _state)
{
// 	_state ? splicingScreenMgr.setOn(_index) : splicingScreenMgr.setOff(_index);
}


void controlClass::movieControl(int _index, int _cmdType)
{
	if (_cmdType == 0)
	{
		videoMgr.play(_index);
	}
	else if (_cmdType == 1)
	{
		videoMgr.pause(_index);
	}
	else if (_cmdType == 2)
	{
		videoMgr.stop(_index);
	}
	else if (_cmdType == 3)
	{
		videoMgr.volumeAdd(_index);
	}
	else if (_cmdType == 4)
	{
		videoMgr.volumeSub(_index);
	}
}

void controlClass::splicingScreenControl(int _index, int _cmdType)
{
	if (_cmdType == 0)
	{
//		splicingScreenMgr.setOn(_index);
	}
	else if (_cmdType == 1)
	{
//		splicingScreenMgr.setOff(_index);
	}
}

string controlClass::convertEncryStr(string _source)
{
	string resStr = cmdConverter::getEncryCmd(_source);
	return resStr;
}