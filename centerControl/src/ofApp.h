#pragma once
/************************************************************************/
/* project name:Ǧɽ���Ź�
/* file describe:
/* date:2018.3.2
/* author:hui

/* �п�����˰汾��֮ǰ�汾���£������ȡ����Ϊ��IDΪʶ���
/* update:2018.3.20(���Ӵ��ڶ��ż���ģ��-Զ��һ���չ�)
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
