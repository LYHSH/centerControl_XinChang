#pragma once
/************************************************************************/
/* project name:铅山非遗馆
/* file describe:
/* date:2018.3.2
/* author:hui

/* 中控软件此版本较之前版本更新：界面获取更新为以ID为识别号
/* update:2018.3.20(增加串口短信监听模块-远程一键闭馆)
/************************************************************************/
#include "manager.h"
#include "ofMain.h"
//#define MD5_CHECK
#ifdef MD5_CHECK
#include "md5Connection.h"
#endif // MD5_CHECK
//#define SMS_LISTENING
#ifdef SMS_LISTENING
#include "ofxSMSlistening.h"
#endif



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();

		manager mainApp;
#ifdef MD5_CHECK
		void md5Event(md5ConnectionEventArgs & e);
		md5Connection md5Test;
#endif // MD5_CHECK

#ifdef SMS_LISTENING
		void smsEvent(ofxSMSlisteningEventArgs & e);
#endif // SMS_LISTENING
		
};
