	
#ifndef _UI_KIT_
#define _UI_KIT_
#include "language.h"
#include "menu_callback.h"
#include "menu_callback_1.h"
#include "menu_callback_2.h"
#include "menu_root.h"
#include "menu_main.h"
#include "menu_system.h"
#include "menu_channellist.h"
#include "menu_videoset.h"
#include "menu_volume.h"
#include "menu_sound.h"
#include "menu_av_setup.h"
#include "menu_version.h"
#include "menu_network.h"
#include "menu_ca.h"
#include "menu_infobar.h"
#include "menu_pin.h"
#include "menu_servicelist.h"
#include "menu_favormanager.h"
#include "menu_autosearch.h"
#include "menu_manualsearch.h"
#include "menu_update.h"
#include "menu_factory.h"

//////////////////////////// globe define /////////////////////////////
extern QApplication *g_qAPP;

typedef enum
{
    UI_ID_ROOT = 0,
    UI_ID_MAIN_MENU,
    UI_ID_CONFIG,
    UI_ID_CHANNEL_LIST,
    UI_ID_VIDEO_SET,
    UI_ID_AV_SETUP,
    UI_ID_VERSION,
    UI_ID_NETWORK,
    UI_ID_CA,
    UI_ID_INFORBAR,
    UI_ID_PIN,
    UI_ID_VOLUME,
    UI_ID_SOUND,
    UI_ID_UPDATE,
    UI_ID_FACTORY,
    UI_ID_MUTE,
    UI_ID_AUTO_SEARCH,
    UI_ID_MANUAL_SEARCH,
    UI_ID_SEARCHING,
    UI_ID_EPG,
    UI_ID_MEDIA,
    UI_ID_INFORMATION,
    UI_ID_MEIDA_PLAYER,
    UI_ID_WEBKIT,
    UI_ID_FAVOR_MANAGER,
    UI_ID_MAX
}UI_ID_E;

typedef enum
{
    UI_STYLESHEET_COMMON = 0,
    UI_STYLESHEET_ROOT,
    UI_STYLESHEET_LABEL_TITLE,
    UI_STYLESHEET_AV_SETUP,
    UI_STYLESHEET_NETWORK,
    UI_STYLESHEET_INFOBAR,
    UI_STYLESHEET_PIN,
    UI_STYLESHEET_TITLEBAR,
    UI_STYLESHEET_MAX
}UI_ID_STYLESHEET;

#define DESKTOP_WIDTH	960
#define DESKTIP_HEIGHT	540

////////////////////////// public interface ////////////////////////////
bool UI_init_pos();
bool UI_init_styleSheet();
QString* UI_styleSheet_get(UI_ID_STYLESHEET styleSheet_id);
bool UI_create();
int	UI_menu_getx(UI_ID_E menu_id);
int	UI_menu_gety(UI_ID_E menu_id);
int	UI_menu_getw(UI_ID_E menu_id);
int	UI_menu_geth(UI_ID_E menu_id);

/////////////////////////// menu manage interface //////////////////////
bool UI_menu_entry(UI_ID_E menu_id);
bool UI_menu_present(UI_ID_E menu_id);
bool UI_menu_show(UI_ID_E menu_id);
bool UI_menu_hide(UI_ID_E menu_id);
bool UI_menu_back();

////////////////////////// menu root public interface /////////////////////////
extern MenuRoot *UI_pMenuRoot;
MenuRoot* UI_menuRoot_create();
void UI_menuRoot_show();
void UI_menuRoot_hide();

////////////////////////// menu main public interface /////////////////////////
extern MenuMain *UI_pMenuMain;
MenuMain* UI_menuMain_create();
void UI_menuMain_show();
void UI_menuMain_hide();

////////////////////////// menu system public interface /////////////////////////
extern MenuSystem *UI_pMenuSystem;
MenuSystem* UI_MenuSystem_create();
void UI_MenuSystem_show();
void UI_MenuSystem_hide();

////////////////////////// menu system public interface /////////////////////////
extern MenuChannelList *UI_pMenuChannelList;
MenuChannelList* UI_MenuChannelList_create();
void UI_MenuChannelList_show();
void UI_MenuChannelList_hide();

////////////////////////// menu video set public interface /////////////////////////
extern MenuVideoSet *UI_pMenuVideoSet;
MenuVideoSet* UI_MenuVideoSet_create();
void UI_MenuVideoSet_show();
void UI_MenuVideoSet_hide();

////////////////////////// menu Volume set public interface /////////////////////////
extern MenuVolume *UI_pMenuVolume;
extern int	UI_nVolume;
MenuVolume* UI_MenuVolume_create();
void UI_MenuVolume_show();
void UI_MenuVolume_hide();
void UI_MenuVolume_setVolume(int volume);

////////////////////////// menu Sound set public interface /////////////////////////
typedef enum
{
	UI_SOUND_STEREO,
	UI_SOUND_LEFT,
	UI_SOUND_RIGHT,
	UI_SOUND_MAX
}UI_SOUND_ID_E;
extern MenuSound *UI_pMenuSound;
extern bool	UI_bIsMute;
extern int	UI_nSoundChannel;
MenuSound*	UI_MenuSound_create();
void UI_MenuSound_show();
void UI_MenuSound_hide();
void UI_MenuSound_set(int id);

////////////////////////// menu av setup public interface /////////////////////////
extern MenuAVSetupWidget *UI_pMenuAVSetup;
MenuAVSetupWidget* UI_MenuAVSetup_create();
void UI_MenuAVSetup_show();
void UI_MenuAVSetup_hide();
void UI_MenuAVSetup_update();

////////////////////////// menu version public interface /////////////////////////
extern MenuVersionWidget *UI_pMenuVersion;
MenuVersionWidget* UI_MenuVersion_create();
void UI_MenuVersion_show();
void UI_MenuVersion_hide();
void UI_MenuVersion_update();

////////////////////////// menu network public interface /////////////////////////
extern MenuNetworkWidget *UI_pMenuNetwork;
MenuNetworkWidget* UI_MenuNetwork_create();
void UI_MenuNetwork_show();
void UI_MenuNetwork_hide();
void UI_MenuNetwork_update();

////////////////////////// menu ca public interface /////////////////////////
extern MenuCaWidget *UI_pMenuCa;
MenuCaWidget* UI_MenuCa_create();
void UI_MenuCa_show();
void UI_MenuCa_hide();
void UI_MenuCa_update();

////////////////////////// menu infobar public interface /////////////////////////
extern MenuInfobarWidget *UI_pMenuInfobar;
MenuInfobarWidget* UI_MenuInfobar_create();
void UI_MenuInfobar_show();
void UI_MenuInfobar_hide();
void UI_MenuInfobar_update();

////////////////////////// menu pin public interface /////////////////////////
extern MenuPinWidget *UI_pMenuPin;
MenuPinWidget* UI_MenuPin_create();
void UI_MenuPin_show();
void UI_MenuPin_hide();

////////////////////////// menu service list public interface /////////////////////////
extern MenuServiceList *UI_pMenuServiceList;
MenuServiceList* UI_MenuServiceList_create();
void UI_MenuServiceList_show();
void UI_MenuServiceList_hide();

////////////////////////// menu favorManager public interface /////////////////////////
extern MenuFavorManager *UI_pMenuFavorManager;
MenuFavorManager* UI_MenuFavorManager_create();
void UI_MenuFavorManager_show();
void UI_MenuFavorManager_hide();

////////////////////////// menu auto search interface /////////////////////////
extern MenuAutoSearch *UI_pMenuAutoSearch;
MenuAutoSearch* UI_MenuAutoSearch_create();
void UI_MenuAutoSearch_show();
void UI_MenuAutoSearch_hide();
void UI_MenuAutoSearch_setTVNumber(int number);
void UI_MenuAutoSearch_setRadioNumber(int number);
void UI_MenuAutoSearch_setOtherNumber(int number);
void UI_MenuAutoSearch_setTitle(int index);
void UI_MenuAutoSearch_setProgress(int progress);

////////////////////////// menu manual search interface /////////////////////////
typedef enum
{
	UI_QAM_NONE=0,
	UI_QAM_QPSK,
	UI_QAM_QPSK_S2,
	UI_QAM_8PSK,
	UI_QAM_16,
	UI_QAM_32,
	UI_QAM_64,
	UI_QAM_128,
	UI_QAM_256,
	UI_QAM_AUTO,
}UI_QAM_E;
#define	UI_QAM_MIN UI_QAM_16 
#define	UI_QAM_MAX UI_QAM_AUTO 
extern MenuManualSearch *UI_pMenuManualSearch;
MenuManualSearch* UI_MenuManualSearch_create();
void UI_MenuManualSearch_show();
void UI_MenuManualSearch_hide();
bool UI_ManualSearch_set(int nStartFreq, int nEndFreq ,int nSearchSymbol ,int nSearchQAM);
bool UI_ManualSearch_get(int *nStartFreq, int *nEndFreq ,int *nSearchSymbol ,int *nSearchQAM);

////////////////////////// menu update interface /////////////////////////
extern MenuUpdate *UI_pMenuUpdate;
MenuUpdate* UI_MenuUpdate_create();
void UI_MenuUpdate_show();
void UI_MenuUpdate_hide();

////////////////////////// menu factory interface /////////////////////////
extern MenuFactory *UI_pMenuFactory;
MenuFactory* UI_MenuFactory_create();
void UI_MenuFactory_show();
void UI_MenuFactory_hide();

#endif

