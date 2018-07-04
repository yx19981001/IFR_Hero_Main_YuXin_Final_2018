#ifndef __BULLET_ROTATE_H_
#define __BULLET_ROTATE_H_

#include "stm32f4xx.h"


#define BULLETROTATE_POSITION_PID_KP            10.5f//10//9//8//7//110//120
#define BULLETROTATE_POSITION_PID_KI            0//0.01f//0.01f
#define BULLETROTATE_POSITION_PID_KD            0//0.015	//0
#define BULLETROTATE_POSITION_PID_MER					1700
#define BULLETROTATE_POSITION_PID_I_MAX				0.0f
#define BULLETROTATE_POSITION_PID_MAXIN        2000
#define BULLETROTATE_POSITION_MAXOUT           10000	//12000

#define BULLETROTATE_SPEED_PID_KP           7.5f//7//5	//0.32
#define BULLETROTATE_SPEED_PID_KI           0.04f	//0.002
#define BULLETROTATE_SPEED_PID_KD           0.05f 
#define BULLETROTATE_SPEED_PID_MER					6000//7000	//4000
#define BULLETROTATE_SPEED_PID_I_MAX 			3000.0f/BULLETROTATE_SPEED_PID_KI//3000.0f/SHOOT_SPEED_PID_KI
#define BULLETROTATE_SPEED_PID_MAXIN       10000//12000
#define BULLETROTATE_SPEED_MAXOUT      	  14000

//取弹旋转电机位置环PID参数
#define PID_BULLETROTATE_POSITION_DEFAULT \
{\
	BULLETROTATE_POSITION_PID_KP,\
	BULLETROTATE_POSITION_PID_KI,\
  BULLETROTATE_POSITION_PID_KD,\
	BULLETROTATE_POSITION_PID_MER,\
	-BULLETROTATE_POSITION_PID_MAXIN,\
	0,\
	-BULLETROTATE_POSITION_MAXOUT,\
	BULLETROTATE_POSITION_MAXOUT,\
	BULLETROTATE_POSITION_PID_I_MAX,\
	{0.0,0.0},\
	0.0,\
	0.0,\
	0.0,\
	0,\
}\


//取弹旋转电机速度环PID参数
#define PID_BULLETROTATE_SPEED_DEFAULT \
{\
	BULLETROTATE_SPEED_PID_KP,\
	BULLETROTATE_SPEED_PID_KI,\
  BULLETROTATE_SPEED_PID_KD,\
	BULLETROTATE_SPEED_PID_MER,\
	-BULLETROTATE_SPEED_PID_MAXIN,\
	BULLETROTATE_SPEED_PID_MAXIN,\
	-BULLETROTATE_SPEED_MAXOUT,\
	BULLETROTATE_SPEED_MAXOUT,\
	BULLETROTATE_SPEED_PID_I_MAX,\
	{0.0,0.0},\
	0.0,\
	0.0,\
	0.0,\
	0,\
}\



typedef struct
{
	/*fdbp:当前机械角度
  fdbv:当前转速
  Tarp:目标机械角度
  Tarv:目标转速*/
	s32 fdbP;	//处理后的数据
	
	s32 fdbV;
	
	s32 tarP;
	s32 tarV;
	
	s32 offsetP;

  float output;
}BULLETROTATE_DATA;

#define BULLETROTATE_DATA_DEFAULT	\
{\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
}\

void BulletRotate_Task(void);
u8 BulletRotate_OffSetInit(void);	//初始OFFSET	//在cali(output为0时)状态下进行标定

#endif
