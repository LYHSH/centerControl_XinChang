/************************************************************************/
/* project name:湖南怀化科技馆
/* file describe：UI管理器
/* date:2017.9.27
/* author:hui
/************************************************************************/
#ifndef UI_MANAGER_H
#define UI_MANAGER_H
#include "pageBase.h"

class UImanager
{
public:
	UImanager(void);
	~UImanager(void);

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

private:

	void pageBegin(int _pageId);
	pageBase * tempPage;
	void addTouchId(int _id,PAGE_SWITCH_MODE _mode);
	void setControlIndex(int _index);
	void pageEnd();
	
};
#endif


