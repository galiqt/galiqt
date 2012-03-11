#include "globe.h"
#include "UIKit.h"
#include <stdio.h>

//////////////////////////////////////// menu root /////////////////////////////////////

bool on_menuRoot_key_press(QKeyEvent *event)
{
    switch (event->key()){
        case KEY_RC_UP:
			qDebug("Root Key_Up");
            break;
        case KEY_RC_DOWN:
			qDebug("Root Key_Down");
            break;
        case KEY_RC_LEFT:
			if(UI_nVolume>=0){UI_nVolume--;}
			UI_MenuVolume_setVolume(UI_nVolume);        	
            UI_menu_entry(UI_ID_VOLUME);
            break;						
        case KEY_RC_RIGHT:
            if(UI_nVolume<=100){UI_nVolume++;}
            UI_MenuVolume_setVolume(UI_nVolume);        	
            UI_menu_entry(UI_ID_VOLUME);
            break;
		case KEY_RC_MUTE:
			UI_bIsMute=!UI_bIsMute;
			if(UI_bIsMute)
			{
				UI_menu_entry(UI_ID_SOUND);
			}else
			{
				UI_MenuVolume_setVolume(UI_nVolume);
				UI_menu_entry(UI_ID_VOLUME);	
			}	
			break;
        case KEY_RC_RED:
        	if(UI_nSoundChannel<(UI_SOUND_MAX-1))
        	{
        		UI_nSoundChannel++;
        	}else
        	{
        		UI_nSoundChannel=UI_SOUND_STEREO;
        	}	
        	UI_MenuSound_set(UI_nSoundChannel);
        	UI_menu_entry(UI_ID_SOUND);
        	break;
        case KEY_RC_POWER:
			g_qAPP->quit();
			break;
        case KEY_RC_OK:
			UI_menu_entry(UI_ID_CHANNEL_LIST);
			break;		
        case KEY_RC_MENU:	
            UI_menu_entry(UI_ID_MAIN_MENU);
            break;
		case KEY_RC_INFO:	
            UI_menu_entry(UI_ID_INFORBAR);
            break;

        default:
			qDebug("keyPress [%d]",event->key());
    }
	
	return TRUE;
}

//////////////////////////////////////// menu main /////////////////////////////////////

bool on_menuMain_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
//			qDebug("Main Key_Up");
            break;
        case KEY_RC_DOWN:
//			qDebug("Main Key_Down");
            break;
        case KEY_RC_LEFT:
//			qDebug("Main Key_Left");
            break;
        case KEY_RC_RIGHT:
//			qDebug("Main Key_Right");
            break;
        case KEY_RC_RED:
			UI_menu_hide(UI_ID_MAIN_MENU);
			UI_menu_show(UI_ID_VIDEO_SET);
			UI_menu_entry(UI_ID_CONFIG);
			break;            
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_MAIN_MENU);
            UI_menu_back();
            break;

        default:
			qDebug("keyPress [%d]",event->key());
    }
    return TRUE;	
}

void MenuMain_on_TVClicked()
{
	qDebug("on_MenuMain_TVClicked");	
}

void MenuMain_on_RadioClicked()
{
	qDebug("on_MenuMain_RadioClicked");	
}

void MenuMain_on_MediaClicked()
{
	qDebug("on_MenuMain_MediaClicked");	
}

void MenuMain_on_BillingClicked()
{
	qDebug("on_MenuMain_BillingClicked");	
}

void MenuMain_on_EPGClicked()
{
	qDebug("on_MenuMain_EPGClicked");	
}

void MenuMain_on_SystemClicked()
{
	qDebug("on_MenuMain_SystemClicked");
	UI_menu_hide(UI_ID_MAIN_MENU);
//	UI_menu_show(UI_ID_VIDEO_SET);
	UI_menu_entry(UI_ID_CONFIG);		
}

//////////////////////////////////////// menu system /////////////////////////////////////

bool on_MenuSystem_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
			qDebug("System Key_Up");
			break;
        case KEY_RC_DOWN:
			qDebug("System Key_Down");
			break;
        case KEY_RC_LEFT:
			qDebug("System Key_Left");
			break;
        case KEY_RC_RIGHT:
			qDebug("System Key_Right");
			break;
        case KEY_RC_RED:
//			UI_menu_entry(UI_ID_VIDEO_SET);
//        	UI_menu_present(UI_ID_VIDEO_SET);
        	break;
		case KEY_RC_GREEN:
//			UI_menu_entry(UI_ID_VERSION);
//			UI_menu_present(UI_ID_VERSION);
			break; 
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_VERSION);
            UI_menu_hide(UI_ID_VIDEO_SET);
            UI_menu_hide(UI_ID_CONFIG);
            UI_menu_back();
            break;

        default:
        		qDebug("keyPress [%d]",event->key());
    }
	return TRUE;	
}

void on_MenuSystem_CACardClicked()
{
	qDebug("on_CACardClicked");
	UI_menu_entry(UI_ID_CA);
//	UI_menu_present(UI_ID_CA);
}

void on_MenuSystem_VersionClicked()
{
	qDebug("on_VersionClicked");
//	UI_menu_show(UI_ID_VERSION);
//	UI_menu_present(UI_ID_CONFIG);
	UI_menu_entry(UI_ID_VERSION);
}

void on_MenuSystem_NetworkSettingClicked()
{
	qDebug("on_NetworkSettingClicked");
	UI_menu_entry(UI_ID_NETWORK);
//	UI_menu_present(UI_ID_NETWORK);
}

void on_MenuSystem_FactoryClicked()
{
	qDebug("on_FactoryClicked");
	UI_menu_entry(UI_ID_FACTORY);
}

void on_MenuSystem_UpdateClicked()
{
	qDebug("on_UpdateClicked");
	UI_menu_entry(UI_ID_UPDATE);
}

void on_MenuSystem_SystemSettingClicked()
{
	qDebug("on_SystemSettingClicked");
	UI_menu_entry(UI_ID_AV_SETUP);
//	UI_menu_present(UI_ID_AV_SETUP);		
}

void on_MenuSystem_ManualSearchClicked()
{
	qDebug("on_ManualSearchClicked");
	UI_menu_entry(UI_ID_MANUAL_SEARCH);
}

void on_MenuSystem_AutoSearchClicked()
{
	qDebug("on_AutoSearchClicked");
	UI_menu_entry(UI_ID_AUTO_SEARCH);
//	UI_menu_present(UI_ID_AUTO_SEARCH);
}

//////////////////////////////////////// menu volume /////////////////////////////////////

bool on_MenuVolume_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
			qDebug("Volume Key_Up");
            break;
        case KEY_RC_DOWN:
			qDebug("Volume Key_Down");
            break;
        case KEY_RC_LEFT:
			qDebug("Volume Key_Left");
			if(UI_nVolume>=0){UI_nVolume--;}
			UI_MenuVolume_setVolume(UI_nVolume);	
            break;
        case KEY_RC_RIGHT:
			qDebug("Volume Key_Right");
            if(UI_nVolume<=100){UI_nVolume++;}
            UI_MenuVolume_setVolume(UI_nVolume);
            break;
        case KEY_RC_EXIT:
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_VOLUME);
            UI_menu_back();
            break;

        default:
			qDebug("Volume keyPress [%d]",event->key());
    }
	return TRUE;
}

//////////////////////////////////////// menu sound /////////////////////////////////////

bool on_MenuSound_key_press(QKeyEvent *event)
{
    switch (event->key()){
		case KEY_RC_MUTE:
			UI_bIsMute=!UI_bIsMute;	
			UI_menu_hide(UI_ID_SOUND);
            UI_menu_back();		
        case KEY_RC_EXIT:
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_SOUND);
            UI_menu_back();
            break;
		case KEY_RC_RED:
        	if(UI_nSoundChannel<(UI_SOUND_MAX-1))
        	{
        		UI_nSoundChannel++;
        	}else
        	{
        		UI_nSoundChannel=UI_SOUND_STEREO;
        	}	
        	UI_MenuSound_set(UI_nSoundChannel);			
			break;

        default:
			qDebug("Sound keyPress [%d]",event->key());
    }
	return TRUE;
}

//////////////////////////////////////// menu auto search /////////////////////////////////////
bool MenuAutoSearch_comfirm()
{
	QMessageBox mb( "Scan Stop Confirm",
        "Do you want to stop?",
        QMessageBox::Information,
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::No  | QMessageBox::Escape, 
        QMessageBox::NoButton );
	
	mb.setWindowFlags(Qt::FramelessWindowHint);
	
	switch( mb.exec() )
	{
    	case QMessageBox::Yes:
			return true;
		case QMessageBox::No:
			return false;
	}
	return false;
}

bool MenuAutoSearch_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
//			qDebug("Main Key_Up");
            break;
        case KEY_RC_DOWN:
//			qDebug("Main Key_Down");
            break;
        case KEY_RC_LEFT:
//			qDebug("Main Key_Left");
            break;
        case KEY_RC_RIGHT:
//			qDebug("Main Key_Right");
            break;
        case KEY_RC_RED:
			if(MenuAutoSearch_comfirm())
			{
				qDebug("yes");
				UI_menu_hide(UI_ID_AUTO_SEARCH);
            	UI_menu_back();					
			}else
			{
				qDebug("no");
			}
        	break;
        case KEY_RC_GREEN:
        	UI_MenuAutoSearch_setProgress(20);
        	break;
        case KEY_RC_YELLOW:
        	UI_MenuAutoSearch_setProgress(80);
        	break;
        case KEY_RC_BLUE:
        	UI_MenuAutoSearch_setTVNumber(100);
        	UI_MenuAutoSearch_setRadioNumber(200);
        	UI_MenuAutoSearch_setOtherNumber(300);
        	UI_MenuAutoSearch_setTitle(UI_ID_MANUAL_SEARCH);
        	break;
	          
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_AUTO_SEARCH);
            UI_menu_back();
            break;
        default:
			qDebug("keyPress [%d]",event->key());
    }
    return TRUE;	
}

//////////////////////////////////////// menu manual search /////////////////////////////////////

bool MenuManualSearch_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
//			qDebug("Main Key_Up");
            break;
        case KEY_RC_DOWN:
//			qDebug("Main Key_Down");
            break;
        case KEY_RC_LEFT:
//			qDebug("Main Key_Left");
            break;
        case KEY_RC_RIGHT:
//			qDebug("Main Key_Right");
            break;         
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_MANUAL_SEARCH);
            UI_menu_back();
            break;

        default:
			qDebug("keyPress [%d]",event->key());
    }
    return TRUE;	
}

void MenuManualSearch_on_scanClicked()
{
//	int a=0,b=0 ,c=0 ,d=0;
//	UI_ManualSearch_get(&a,&b,&c,&d);
//	qDebug("ManualSearch get [%d] [%d] [%d] [%d]",a,b,c,d);

	UI_ManualSearch_set(100,200,300,UI_QAM_MAX);
	
	UI_menu_hide(UI_ID_MANUAL_SEARCH);
    UI_menu_back();
    UI_MenuAutoSearch_setTitle(UI_ID_MANUAL_SEARCH);
	UI_menu_entry(UI_ID_AUTO_SEARCH);
//	qDebug("MenuManualSearch_on_scanClicked");
}

//////////////////////////////////////// menu update /////////////////////////////////////

bool MenuUpdate_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
//			qDebug("Main Key_Up");
            break;
        case KEY_RC_DOWN:
//			qDebug("Main Key_Down");
            break;
        case KEY_RC_LEFT:
//			qDebug("Main Key_Left");
            break;
        case KEY_RC_RIGHT:
//			qDebug("Main Key_Right");
            break;         
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_UPDATE);
            UI_menu_back();
            break;

        default:
			qDebug("keyPress [%d]",event->key());
    }
    return TRUE;	
}

//////////////////////////////////////// menu factory /////////////////////////////////////

bool MenuFactory_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
//			qDebug("Main Key_Up");
            break;
        case KEY_RC_DOWN:
//			qDebug("Main Key_Down");
            break;
        case KEY_RC_LEFT:
//			qDebug("Main Key_Left");
            break;
        case KEY_RC_RIGHT:
//			qDebug("Main Key_Right");
            break;         
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_FACTORY);
            UI_menu_back();
            break;

        default:
			qDebug("keyPress [%d]",event->key());
    }
    return TRUE;	
}
