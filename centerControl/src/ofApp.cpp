#include "ofApp.h"
#include "wordButton.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_NOTICE);
	ofLogToConsole();
//	ofLogToFile("log.log",true);

#ifdef MD5_CHECK
	md5Test.setup();
	ofAddListener(md5Connection::md5connectionLostEvent, this, &ofApp::md5Event);
#endif // MD5_CHECK

#ifdef SMS_LISTENING
	ofAddListener(ofxSMSlistening::centerConnectionLostEvent, this, &ofApp::smsEvent);
	//ofxSMSlistening::instance().start();
#endif // SMS_LISTENING
	

	mainApp.setup();
	ofSetWindowShape(IPAD_SCREEN_WIDTH * SCALE_X,IPAD_SCREEN_HEIGHT * SCALE_Y);
	ofSetFrameRate(60);


	ofSetWindowTitle("CentralControlSystem v1.0");
	//FreeConsole();
}

//--------------------------------------------------------------
void ofApp::update(){
	mainApp.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mainApp.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	mainApp.keyPressed(key);

	if (key == 'd')
	{
		static bool flag = false;
		flag = !flag;
		flag?ofLogToConsole():ofLogToFile("log.log");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	mainApp.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	x /= SCALE_X;
	y /= SCALE_Y;
	mainApp.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	x /= SCALE_X;
	y /= SCALE_Y;
	mainApp.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	x /= SCALE_X;
	y /= SCALE_Y;
	mainApp.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	x /= SCALE_X;
	y /= SCALE_Y;
	mainApp.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	ofSetWindowShape(IPAD_SCREEN_WIDTH * SCALE_X,IPAD_SCREEN_HEIGHT * SCALE_Y);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


void ofApp::exit()
{
#ifdef MD5_CHECK
	ofRemoveListener(md5Connection::md5connectionLostEvent, this, &ofApp::md5Event);
#endif // MD5_CHECK
	
#ifdef SMS_LISTENING
	ofRemoveListener(ofxSMSlistening::centerConnectionLostEvent, this, &ofApp::smsEvent);
#endif // SMS_LISTENING
}

#ifdef MD5_CHECK
void ofApp::md5Event(md5ConnectionEventArgs & e)
{
	if (e.ptrSender == &md5Test)
	{
		ofLogError() << "server check connection failed" << endl;

		mainApp.shutdown();
	}
}
#endif // MD5_CHECK

#ifdef SMS_LISTENING
void ofApp::smsEvent(ofxSMSlisteningEventArgs & e)
{
	ofLogError() << "SMS stop work" << endl;
	mainApp.shutdown();
}
#endif // SMS_LISTENING

  