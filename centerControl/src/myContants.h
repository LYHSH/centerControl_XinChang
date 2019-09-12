/************************************************************************/
/* project name:张纯-智慧医疗展厅
/* file describe:全局常量定义声明
/* date:2018.8.23
/* author:hui
/************************************************************************/
#ifndef MY_CONTANTS_H
#define MY_CONTANTS_H

//#define MAIN_PAGE_H				//主界面

#define MANAGER_PAGE_H				//管理模式界面


#define MAC_CONTORL_PAGE_H				//主机控制界面
#define MAC_CONTORL_PAGE_1_H			//主机控制界面一
#define MAC_CONTORL_PAGE_2_H			//主机控制界面二
#define MAC_CONTORL_PAGE_3_H			//主机控制界面三

#define PJ_CONTORL_PAGE_H				//投影控制界面
#define PJ_CONTORL_PAGE_1_H			//投影控制界面一
#define PJ_CONTORL_PAGE_2_H			//投影控制界面二

#define LED_CONTORL_PAGE_H				//LED控制界面
#define LED_CONTORL_PAGE_1_H			//LED控制界面一
#define LED_CONTORL_PAGE_2_H			//LED控制界面二

#define SPLICING_SCREEN_CONTORL_PAGE_H				//拼接控制界面
#define SPLICING_SCREEN_CONTORL_PAGE_1_H			//拼接屏控制界面一
#define SPLICING_SCREEN_CONTORL_PAGE_2_H			//拼接屏控制界面二

#define LIGHT_CONTROL_PAGE_H			//照明灯光控制界面
#define LIGHT_CONTORL_PAGE_1_H			//灯光控制界面一
#define LIGHT_CONTORL_PAGE_2_H			//灯光控制界面二
#define LIGHT_CONTORL_PAGE_3_H			//灯光控制界面二

#define VISIT_CONTROL_PAGE_H
#define VISIT_CONTORL_PAGE_1_H			//参观模式控制界面一
#define VISIT_CONTORL_PAGE_2_H			//参观模式控制界面二
#define VISIT_CONTORL_PAGE_3_H			//参观模式控制界面三
//ipad屏幕尺寸
static int const IPAD_SCREEN_WIDTH = 2048;
static int const IPAD_SCREEN_HEIGHT = 1536;

//
static int const DEFAULT_TOUCH_ORDER = -10000;

static float const SCALE_X = 0.4f;
static float const SCALE_Y = 0.4f;

static int const PORT_CENTER_IPAD_CMD = 10000;		 //中控端ipad指令监听端口

static int const INDEX_SINGLE_NULL_PAGE = -8888;

enum
{
#pragma region 主页面
	MAIN_PAGE_BEGIN = 3000,
	MAIN_PAGE_ALL_CONTROL,
	MAIN_PAGE_ITEM_CONTROL,
	MAIN_PAGE_END = 3999,
#pragma endregion

#pragma region 管理模式页面
	MANAGE_PAGE_BEGIN = 4000,
	MANAGE_PAGE_ALL_ON,					//一键开馆
	MANAGE_PAGE_ALL_OFF,					//一键闭馆
#ifdef MAC_CONTORL_PAGE_H
	MANAGE_PAGE_MAC_CONTROL,				//主机控制
#endif
#ifdef PJ_CONTORL_PAGE_H
	MANAGE_PAGE_PROJECT_CONTROL,			//投影控制
#endif
#ifdef LED_CONTORL_PAGE_H
	MANAGE_PAGE_LED_CONTROL,				//LED控制
#endif
#ifdef SPLICING_SCREEN_CONTORL_PAGE_H
	MANAGE_PAGE_PINJIE_CONTROL,			//拼接屏控制
#endif
#ifdef LIGHT_CONTROL_PAGE_H
	MANAGE_PAGE_LIGHT_CONTROL,			//灯光控制
#endif
#ifdef VISIT_CONTROL_PAGE_H
	MANAGE_PAGE_VIDEO_CONTROL,			//视频控制
#endif
	

	WHOLE_PAGE_END = 4999,
#pragma endregion

#pragma region 主机控制
#ifdef MAC_CONTORL_PAGE_H
	MAC_PAGE_BEGIN = 5000,
	MAC_PAGE_RETURN,
	MAC_CONTROL_ALL_ON,
	MAC_CONTROL_ALL_OFF,
	MAC_PAGE_1,
	MAC_PAGE_2,
	MAC_PAGE_3,




#ifdef MAC_CONTORL_PAGE_1_H
	MAC_CONTROL_PAGE_1_BEGIN = 5100,
	MAC_CONTROL_PAGE_1_END = 5199,
#endif

#ifdef MAC_CONTORL_PAGE_2_H
	MAC_CONTROL_PAGE_2_BEGIN = 5200,
	MAC_CONTROL_PAGE_2_END = 5299,
#endif

#ifdef MAC_CONTORL_PAGE_3_H
	MAC_CONTROL_PAGE_3_BEGIN = 5300,
	MAC_CONTROL_PAGE_3_END = 5399,
#endif

	MAC_PAGE_END = 5999,
#endif

#pragma endregion 主机控制

#ifdef PJ_CONTORL_PAGE_H
#pragma region 投影控制
	PROJECT_CONTROL_PAGE_BEGIN = 6000,
	PROJECT_CONTROL_PAGE_RETURN,
	PROJECT_CONTROL_PAGE_ALL_ON,
	PROJECT_CONTROL_PAGE_ALL_OFF,
	PROJECT_PAGE_1,
	PROJECT_PAGE_2,
	PROJECT_PAGE_3,

#ifdef PJ_CONTORL_PAGE_1_H
	PJ_CONTROL_PAGE_1_BEGIN = 6100,
	PJ_CONTROL_PAGE_1_END = 6199,
#endif
#ifdef PJ_CONTORL_PAGE_2_H
	PJ_CONTROL_PAGE_2_BEGIN = 6200,
	PJ_CONTROL_PAGE_2_END = 6299,
#endif

	PROJECT_CONTROL_PAGE_END = 6999,
#pragma endregion 投影控制
#endif

#ifdef LED_CONTORL_PAGE_H
#pragma region LED控制
	LED_CONTROL_PAGE_BEGIN = 7000,
	LED_CONTROL_PAGE_RETURN,
	LED_CONTROL_PAGE_ALL_ON,
	LED_CONTROL_PAGE_ALL_OFF,
	LED_PAGE_1,
	LED_PAGE_2,
	LED_PAGE_3,
#ifdef LED_CONTORL_PAGE_1_H
	LED_CONTROL_PAGE_1_BEGIN = 7100,
	LED_CONTROL_PAGE_1_END = 7199,
#endif
#ifdef LED_CONTORL_PAGE_2_H
		LED_CONTROL_PAGE_2_BEGIN = 7200,
		LED_CONTROL_PAGE_2_END = 7299,
#endif

	LED_CONTROL_PAGE_END = 7999,
#pragma endregion LED控制
#endif


#pragma region 拼接屏控制
#ifdef SPLICING_SCREEN_CONTORL_PAGE_H
	SPLICING_SCREEN_CONTROL_PAGE_BEGIN = 8000,
	SPLICING_SCREEN_CONTROL_PAGE_RETURN,
	SPLICING_SCREEN_CONTROL_PAGE_ALL_ON,
	SPLICING_SCREEN_CONTROL_PAGE_ALL_OFF,
	SPLICING_SCREEN_PAGE_1,
	SPLICING_SCREEN_PAGE_2,
	SPLICING_SCREEN_PAGE_3,
#ifdef SPLICING_SCREEN_CONTORL_PAGE_1_H
	SPLICING_SCREEN_CONTROL_PAGE_1_BEGIN = 8100,
	SPLICING_SCREEN_CONTROL_PAGE_1_END = 8199,
#endif

	SPLICING_SCREEN_CONTROL_PAGE_END = 8999,
#endif
	
#pragma endregion 拼接屏控制


#ifdef LIGHT_CONTROL_PAGE_H
#pragma region 灯光控制
	LIGHT_PAGE_BEGIN = 9000,
	LIGHT_PAGE_RETURN,
	LIGHT_PAGE_ALL_ON,
	LIGHT_PAGE_ALL_OFF,
	LIGHT_PAGE_1,
	LIGHT_PAGE_2,
#ifdef LIGHT_CONTORL_PAGE_1_H
		LIGHT_CONTORL_PAGE_1_BEGIN = 9100,
		LIGHT_CONTORL_PAGE_1_END = 9199,
#endif
#ifdef LIGHT_CONTORL_PAGE_2_H
		LIGHT_CONTORL_PAGE_2_BEGIN = 9200,
		LIGHT_CONTORL_PAGE_2_END = 9299,
#endif


	LIGHT_PAGE_END = 9999,
#pragma endregion 灯光控制
#endif


#pragma region 参观模式
#ifdef VISIT_CONTROL_PAGE_H
		VISIT_PAGE_BEGIN = 11000,
		VISIT_CONTROL_PAGE_RETURN,
		VISIT_CONTROL_PAGE_1,
		VISIT_CONTROL_PAGE_2,
		VISIT_CONTROL_PAGE_3,

#ifdef VISIT_CONTORL_PAGE_1_H
		VISIT_CONTROL_PAGE_1_BEGIN = 11100,
		VISIT_CONTROL_PAGE_1_GONG_YE_PLAY,
		VISIT_CONTROL_PAGE_1_GONG_YE_STOP,

		VISIT_CONTROL_PAGE_1_XU_TING_MOVIE_1,
		VISIT_CONTROL_PAGE_1_XU_TING_MOVIE_2,
		VISIT_CONTROL_PAGE_1_END = 11199,
#endif

#ifdef VISIT_CONTORL_PAGE_2_H
		VISIT_CONTROL_PAGE_2_BEGIN = 11200,
//		VISIT_CONTROL_PAGE_2_VIDEO_1,
//		VISIT_CONTROL_PAGE_2_VIDEO_2,
//		VISIT_CONTROL_PAGE_2_VIDEO_PLAY,
//		VISIT_CONTROL_PAGE_2_VIDEO_PAUSE,
//		VISIT_CONTROL_PAGE_2_VIDEO_STOP,
//		VISIT_CONTROL_PAGE_2_VIDEO_VOLUME_ADD,
//		VISIT_CONTROL_PAGE_2_VIDEO_VOLUME_SUB,
		VISIT_CONTROL_PAGE_2_END = 11299,
#endif

#ifdef VISIT_CONTORL_PAGE_3_H
		VISIT_CONTROL_PAGE_3_BEGIN = 11300,
		VISIT_CONTROL_PAGE_3_VIDEO_1,
		VISIT_CONTROL_PAGE_3_VIDEO_2,
		VISIT_CONTROL_PAGE_3_VIDEO_PLAY,
		VISIT_CONTROL_PAGE_3_VIDEO_PAUSE,
		VISIT_CONTROL_PAGE_3_VIDEO_STOP,
		VISIT_CONTROL_PAGE_3_VIDEO_VOLUME_ADD,
		VISIT_CONTROL_PAGE_3_VIDEO_VOLUME_SUB,
		VISIT_CONTROL_PAGE_3_END = 11399,
#endif
		VISIT_PAGE_END = 11999,
#endif

	
#pragma endregion 参观模式 
	ALL_NUMS
};
#endif // !MY_CONTANTS_H

