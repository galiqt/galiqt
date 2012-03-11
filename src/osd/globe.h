#ifndef GLOBE_H
#define GLOBE_H

#include <QtGui>
#define DEBUG_MODE
#define _PLATFORM_WIN32_

#ifndef _PLATFORM_WIN32_
#define _PLATFORM_ARM_
#endif

#ifdef _PLATFORM_WIN32_
#define KEY_RC_POWER        (Qt::Key_P)
#define KEY_RC_MUTE         (Qt::Key_U)
#define KEY_RC_0		        0x30
#define KEY_RC_1		        0x31
#define KEY_RC_2		        0x32
#define KEY_RC_3		        0x33
#define KEY_RC_4		        0x34
#define KEY_RC_5		        0x35
#define KEY_RC_6		        0x36
#define KEY_RC_7		        0x37
#define KEY_RC_8		        0x38
#define KEY_RC_9		        0x39
#define KEY_RC_EPG		      0x45
#define KEY_RC_TV		        0x56
#define KEY_RC_VOLUME_UP	  0x4F
#define KEY_RC_VOLUME_DOWN	0x5A
#define KEY_RC_MENU		      (Qt::Key_M)
#define KEY_RC_INFO		      (Qt::Key_I)
#define KEY_RC_PAGE_UP		  0x1000016
#define KEY_RC_PAGE_DOWN	  0x1000017
#define KEY_RC_LEFT		      (Qt::Key_Left)
#define KEY_RC_UP		        (Qt::Key_Up)
#define KEY_RC_RIGHT		    (Qt::Key_Right)
#define KEY_RC_DOWN		      (Qt::Key_Down)
#define KEY_RC_OK		        (Qt::Key_Return)
#define KEY_RC_BACK		      0x58
#define KEY_RC_EXIT		     (Qt::Key_X)
#define KEY_RC_RED		       (Qt::Key_R)
#define KEY_RC_GREEN		    (Qt::Key_G)
#define KEY_RC_YELLOW		    (Qt::Key_Y)
#define KEY_RC_BLUE		       (Qt::Key_B)
#define KEY_RC_STOP		      0x1000034
#define KEY_RC_PLAY		      0x1000035
#define KEY_RC_PAUSE		    0x1000036
#define KEY_RC_REC		      0x1000037
#define KEY_RC_FF		        0x52
#define KEY_RC_REW		      0x43
#define KEY_RC_SLO_PLUS		  0x44
#define KEY_RC_SLO_SUB		  0x46
#define KEY_RC_F5		        0x55
#define KEY_RC_F6		        0x53
#define KEY_RC_TEXT		      0x54
#define KEY_RC_OPT		      0x50
#define KEY_RC_F1		        0x1000030
#define KEY_RC_F2		        0x1000031
#define KEY_RC_F3		        0x1000032
#define KEY_RC_F4		        0x1000033
#endif

#ifdef _PLATFORM_ARM_
#define KEY_RC_POWER        0x41
#define KEY_RC_MUTE         0x1000071
#define KEY_RC_0		        0x30
#define KEY_RC_1		        0x31
#define KEY_RC_2		        0x32
#define KEY_RC_3		        0x33
#define KEY_RC_4		        0x34
#define KEY_RC_5		        0x35
#define KEY_RC_6		        0x36
#define KEY_RC_7		        0x37
#define KEY_RC_8		        0x38
#define KEY_RC_9		        0x39
#define KEY_RC_EPG		      0x45
#define KEY_RC_TV		        0x56
#define KEY_RC_VOLUME_UP	  0x4F
#define KEY_RC_VOLUME_DOWN	0x5A
#define KEY_RC_MENU		      0x4D
#define KEY_RC_INFO		      0x49
#define KEY_RC_PAGE_UP		  0x1000016
#define KEY_RC_PAGE_DOWN	  0x1000017
#define KEY_RC_LEFT		      0x1000012
#define KEY_RC_UP		        0x1000013
#define KEY_RC_RIGHT		    0x1000014
#define KEY_RC_DOWN		      0x1000015
#define KEY_RC_OK		        0x1000004
#define KEY_RC_BACK		      0x58
#define KEY_RC_EXIT		      0x42
#define KEY_RC_RED		      0x52
#define KEY_RC_GREEN		    0x47
#define KEY_RC_YELLOW		    0x59
#define KEY_RC_BLUE		      0x4C
#define KEY_RC_STOP		      0x1000034
#define KEY_RC_PLAY		      0x1000035
#define KEY_RC_PAUSE		    0x1000036
#define KEY_RC_REC		      0x1000037
#define KEY_RC_FF		        0x52
#define KEY_RC_REW		      0x43
#define KEY_RC_SLO_PLUS		  0x44
#define KEY_RC_SLO_SUB		  0x46
#define KEY_RC_F5		        0x55
#define KEY_RC_F6		        0x53
#define KEY_RC_TEXT		      0x54
#define KEY_RC_OPT		      0x50
#define KEY_RC_F1		        0x1000030
#define KEY_RC_F2		        0x1000031
#define KEY_RC_F3		        0x1000032
#define KEY_RC_F4		      (Qt::Key_F4)//0x1000033
#endif

#ifdef _PLATFORM_WIN32_
#define OFFSET_X	50
#define OFFSET_Y	50
#define DATADIR ":"
#endif

#ifdef _PLATFORM_ARM_
#define OFFSET_X	0
#define OFFSET_Y	0
#define DATADIR ":"
#endif

#define CLEAR_TIME_INFORBAR	5000 //unit ms
#define CLEAR_TIME_VOLUME		3000 //unit ms
#define CLEAR_TIME_NUMBER		2000 //unit ms

#define STYLE_SHEET_COMMON (DATADIR"/stylesheet_common.qss")
#define STYLE_SHEET_ROOT 	 (DATADIR"/stylesheet_root.qss")
#define STYLE_SHEET_LABEL_TITLE	(DATADIR"/stylesheet_label_title.qss")
#define STYLE_SHEET_AV_SETUP	(DATADIR"/stylesheet_av_setup.qss")
#define STYLE_SHEET_NETWORK	(DATADIR"/stylesheet_network.qss")
#define STYLE_SHEET_INFOBAR	(DATADIR"/stylesheet_infobar.qss")
#define STYLE_SHEET_PIN	(DATADIR"/stylesheet_pin.qss")
#define STYLE_SHEET_TITLEBAR	(DATADIR"/stylesheet_titlebar.qss")
#endif