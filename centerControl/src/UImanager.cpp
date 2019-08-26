#include "UImanager.h"
#include "pageControler.h"
#include "staticMgr.h"
#include "secondTipPage.h"
#include "pageBase.h"
#include "myContants.h"
#include "btnsShowPage.h"
UImanager::UImanager(void)
{
}


UImanager::~UImanager(void)
{
}

void UImanager::setup()
{
	wordButton::setBtnFontSize(28);
	wordButton::setSleepTimeLen(15.0f);

	map<int, string> pages;
#ifdef MAIN_PAGE_H
	pages[MAIN_PAGE_BEGIN] = "mainPage.xml";
#endif

#ifdef MANAGER_PAGE_H
	pages[MANAGE_PAGE_BEGIN] = "managePage.xml";
#endif
	
#ifdef MAC_CONTORL_PAGE_H
	pages[MAC_PAGE_BEGIN] = "macPage.xml";
#ifdef MAC_CONTORL_PAGE_1_H
	pages[MAC_CONTROL_PAGE_1_BEGIN] = "macPage1.xml";
#endif
#ifdef MAC_CONTORL_PAGE_2_H
	pages[MAC_CONTROL_PAGE_2_BEGIN] = "macPage2.xml";
#endif
#ifdef MAC_CONTORL_PAGE_3_H
	pages[MAC_CONTROL_PAGE_3_BEGIN] = "macPage3.xml";
#endif
#endif

#ifdef PJ_CONTORL_PAGE_H
	pages[PROJECT_CONTROL_PAGE_BEGIN] = "pjPage.xml";

#ifdef PJ_CONTORL_PAGE_1_H
	pages[PJ_CONTROL_PAGE_1_BEGIN] = "pjPage1.xml";
#endif
#ifdef PJ_CONTORL_PAGE_2_H
	pages[PJ_CONTROL_PAGE_2_BEGIN] = "pjPage2.xml";
#endif

#endif
#ifdef LED_CONTORL_PAGE_H
	pages[LED_CONTROL_PAGE_BEGIN] = "ledPage.xml";

#ifdef LED_CONTORL_PAGE_1_H
	pages[LED_CONTROL_PAGE_1_BEGIN] = "ledPage1.xml";
#endif
#ifdef LED_CONTORL_PAGE_2_H
	pages[LED_CONTROL_PAGE_2_BEGIN] = "ledPage2.xml";
#endif

#endif
#ifdef SPLICING_SCREEN_CONTORL_PAGE_H
	pages[SPLICING_SCREEN_CONTROL_PAGE_BEGIN] = "splicingPage.xml";

#ifdef SPLICING_SCREEN_CONTORL_PAGE_1_H
	pages[SPLICING_SCREEN_CONTROL_PAGE_1_BEGIN] = "splicingPage1.xml";
#endif

#endif	
#ifdef LIGHT_CONTROL_PAGE_H
	pages[LIGHT_PAGE_BEGIN] = "lightPage.xml";

#ifdef LIGHT_CONTORL_PAGE_1_H
		pages[LIGHT_CONTORL_PAGE_1_BEGIN] = "lightPage1.xml";
#endif
#ifdef LIGHT_CONTORL_PAGE_2_H
		pages[LIGHT_CONTORL_PAGE_2_BEGIN] = "lightPage2.xml";
#endif

#endif
#ifdef VISIT_CONTROL_PAGE_H
	pages[VISIT_PAGE_BEGIN] = "visitPage.xml";
#ifdef VISIT_CONTORL_PAGE_1_H
	pages[VISIT_CONTROL_PAGE_1_BEGIN] = "visitPage1.xml";
#endif

#ifdef VISIT_CONTORL_PAGE_2_H
	pages[VISIT_CONTROL_PAGE_2_BEGIN] = "visitPage2.xml";
#endif
#ifdef VISIT_CONTORL_PAGE_3_H
	pages[VISIT_CONTROL_PAGE_3_BEGIN] = "visitPage3.xml";
#endif
#endif
	int nums = pages.size();

	int const mainIndex = 0;
	int const secondIndex = 1;
	for (auto ite = pages.begin(); ite != pages.end(); ite++)
	{
		btnsShowPage * page = new btnsShowPage();
		page->setup("xml/" + ite->second, ite->first + 1);
		page->setId(ite->first);
		page->setControlIndex(mainIndex);
		page->setStageRect(ofRectangle(0,0,IPAD_SCREEN_WIDTH,IPAD_SCREEN_HEIGHT));
		staticMgr::getInstance().push(page->getId(), page);
	}

#pragma region 界面切换设置
	/*pageBegin(MAIN_PAGE_BEGIN);
	addTouchId(MANAGE_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(VISIT_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	pageEnd();*/


	pageBegin(MANAGE_PAGE_BEGIN);
	//addTouchId(MAIN_PAGE_ALL_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	addTouchId(MAC_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(PROJECT_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(LED_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(SPLICING_SCREEN_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(LIGHT_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(VISIT_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	pageEnd();

#ifdef MAC_CONTORL_PAGE_H
	pageBegin(MAC_PAGE_BEGIN);
	addTouchId(MANAGE_PAGE_MAC_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	pageEnd();

#ifdef MAC_CONTORL_PAGE_1_H
	pageBegin(MAC_CONTROL_PAGE_1_BEGIN);
	addTouchId(MANAGE_PAGE_MAC_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	addTouchId(MAC_PAGE_1, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif


#ifdef MAC_CONTORL_PAGE_2_H
	pageBegin(MAC_CONTROL_PAGE_2_BEGIN);
	addTouchId(MAC_PAGE_2, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif

#ifdef MAC_CONTORL_PAGE_3_H
	pageBegin(MAC_CONTROL_PAGE_3_BEGIN);
	addTouchId(MAC_PAGE_3, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
#endif
	

#ifdef PJ_CONTORL_PAGE_H
	pageBegin(PROJECT_CONTROL_PAGE_BEGIN);
	addTouchId(MANAGE_PAGE_PROJECT_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	pageEnd();

#ifdef PJ_CONTORL_PAGE_1_H
	pageBegin(PJ_CONTROL_PAGE_1_BEGIN);
	addTouchId(MANAGE_PAGE_PROJECT_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	addTouchId(PROJECT_PAGE_1, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
#ifdef PJ_CONTORL_PAGE_2_H
	pageBegin(PJ_CONTROL_PAGE_2_BEGIN);
	addTouchId(PROJECT_PAGE_2, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
#endif
	

#ifdef LED_CONTORL_PAGE_H
	pageBegin(LED_CONTROL_PAGE_BEGIN);
	addTouchId(MANAGE_PAGE_LED_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	pageEnd();

#ifdef LED_CONTORL_PAGE_1_H
	pageBegin(LED_CONTROL_PAGE_1_BEGIN);
	addTouchId(MANAGE_PAGE_LED_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
#endif
	
#ifdef SPLICING_SCREEN_CONTORL_PAGE_H
	pageBegin(SPLICING_SCREEN_CONTROL_PAGE_BEGIN);
	addTouchId(MANAGE_PAGE_PINJIE_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	pageEnd();

#ifdef SPLICING_SCREEN_CONTORL_PAGE_1_H
	pageBegin(SPLICING_SCREEN_CONTROL_PAGE_1_BEGIN);
	addTouchId(MANAGE_PAGE_PINJIE_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
#endif

#ifdef LIGHT_CONTROL_PAGE_H
	pageBegin(LIGHT_PAGE_BEGIN);
	addTouchId(MANAGE_PAGE_LIGHT_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	pageEnd();
#endif

#ifdef LIGHT_CONTORL_PAGE_1_H
	pageBegin(LIGHT_CONTORL_PAGE_1_BEGIN);
	addTouchId(MANAGE_PAGE_LIGHT_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	addTouchId(LIGHT_PAGE_1, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif

#ifdef LIGHT_CONTORL_PAGE_2_H
	pageBegin(LIGHT_CONTORL_PAGE_2_BEGIN);
	addTouchId(LIGHT_PAGE_2, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
	
#ifdef VISIT_CONTROL_PAGE_H
	pageBegin(VISIT_PAGE_BEGIN);
	addTouchId(MANAGE_PAGE_VIDEO_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	pageEnd();

#ifdef VISIT_CONTORL_PAGE_1_H
	pageBegin(VISIT_CONTROL_PAGE_1_BEGIN);
	addTouchId(MANAGE_PAGE_VIDEO_CONTROL, LEFT_LEAVE_SWITCH_MODE);
	addTouchId(VISIT_CONTROL_PAGE_1, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif

#ifdef VISIT_CONTORL_PAGE_2_H
	pageBegin(VISIT_CONTROL_PAGE_2_BEGIN);
	addTouchId(VISIT_CONTROL_PAGE_2, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
#ifdef VISIT_CONTORL_PAGE_3_H
	pageBegin(VISIT_CONTROL_PAGE_3_BEGIN);
	addTouchId(VISIT_CONTROL_PAGE_3, NO_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();
#endif
#endif
	

	

	
#pragma endregion 界面切换设置

	


	pageControler::getInstance().noSwitch(staticMgr::getInstance().findUIobject(MANAGE_PAGE_BEGIN), mainIndex);
	pageBase * nullObj = new pageBase();
	nullObj->setId(INDEX_SINGLE_NULL_PAGE);
	staticMgr::getInstance().push(nullObj->getId(), nullObj);

	pageBegin(INDEX_SINGLE_NULL_PAGE);
	addTouchId(VISIT_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(MAC_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(PROJECT_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(LIGHT_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(LED_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	addTouchId(SPLICING_SCREEN_CONTROL_PAGE_RETURN, RIGHT_LEAVE_SWITCH_MODE);
	setControlIndex(secondIndex);
	pageEnd();

	pageControler::getInstance().noSwitch(staticMgr::getInstance().findUIobject(INDEX_SINGLE_NULL_PAGE), secondIndex);

	secondTipPage::addSecondConfirmId(MANAGE_PAGE_ALL_ON);
	secondTipPage::addSecondConfirmId(MANAGE_PAGE_ALL_OFF);

	secondTipPage::addSecondConfirmId(LIGHT_PAGE_ALL_ON);
	secondTipPage::addSecondConfirmId(LIGHT_PAGE_ALL_OFF);

	secondTipPage::addSecondConfirmId(MAC_CONTROL_ALL_ON);
	secondTipPage::addSecondConfirmId(MAC_CONTROL_ALL_OFF);

	secondTipPage::addSecondConfirmId(PROJECT_CONTROL_PAGE_ALL_ON);
	secondTipPage::addSecondConfirmId(PROJECT_CONTROL_PAGE_ALL_OFF);
}

void UImanager::update()
{
	pageControler::getInstance().update();
}

void UImanager::draw()
{
	ofScale(SCALE_X,SCALE_Y);
	
	pageControler::getInstance().draw();
	secondTipPage::draw();
}

void UImanager::keyPressed(int key)
{
	if (!secondTipPage::isActiving())
	{
		pageControler::getInstance().keyPressed(key);
	}
}

void UImanager::keyReleased(int key)
{
	if (!secondTipPage::isActiving())
	{
		pageControler::getInstance().keyReleased(key);
	}
}

void UImanager::mouseMoved(int x, int y)
{
	if (!secondTipPage::isActiving())
	{
		pageControler::getInstance().mouseMoved(x, y);
	}
}

void UImanager::mouseDragged(int x, int y, int button)
{
// 	if (!secondTipPage::isActiving())
// 	{
// 		pageControler::getInstance().mouseDragged(x, y, button);
// 	}
}

void UImanager::mousePressed(int x, int y, int button)
{
	if (!secondTipPage::isActiving())
	{
		pageControler::getInstance().mousePressed(x, y, button);
	}
	
	secondTipPage::mousePressed(x, y);
}

void UImanager::mouseReleased(int x, int y, int button)
{
	if (!secondTipPage::isActiving())
	{
		pageControler::getInstance().mouseReleased(x, y, button);
	}
	secondTipPage::mouseReleased(x, y);
}

void UImanager::pageBegin(int _pageId)
{
	tempPage = staticMgr::getInstance().findUIobject(_pageId);
}

void UImanager::addTouchId(int _id, PAGE_SWITCH_MODE _mode)
{
	if (!tempPage)return;

	tempPage->addTouchId(_id, _mode);
}

void UImanager::setControlIndex(int _index)
{
	if (!tempPage)return;

	tempPage->setControlIndex(_index);
}

void UImanager::pageEnd()
{
	tempPage = NULL;
}
