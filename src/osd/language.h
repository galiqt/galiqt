////////////////////////// UI language ///////////////////////
typedef enum
{
	LANGUAGE_CHINESE =0,
	LANGUAGE_ENGLISH,
	LANGUAGE_MAX,
}UI_LANGUAGE_E;

typedef enum
{
	STR_MENU_EMPTY=0,
	STR_MAINMENU_TITLE,
	STR_MAINMENU_NUMBER,
	STR_MAINMENU_TV,
	STR_MAINMENU_RADIO,
	STR_MAINMENU_MEDIA,
	STR_MAINMENU_BILLING,
	STR_MAINMENU_EPG,
	STR_MAINMENU_SYSTEM,
	
	STR_SYSTEM_TITLE,
	STR_SYSTEM_AUTO_SEARCH,
	STR_SYSTEM_MANUAL_SEARCH,	
	STR_SYSTEM_SETTING,
	STR_SYSTEM_UPDATE,
	STR_SYSTEM_FACTORY,
	STR_SYSTEM_NETWORK_SETTING,
	STR_SYSTEM_VERSION,
	STR_SYSTEM_CACARD,
	
	STR_VOLUME_TITLE,
	STR_VOLUME_MUTE,
	STR_SOUND_LEFT,
	STR_SOUND_RIGHT,
	STR_SOUND_STEREO,
	
	STR_LANGUAGE_ENGLISH,
	STR_LANGUAGE_CHINESE,
	
	STR_MENU_MAX,
}STR_LANGUAGE_E;

typedef struct
{
    int   	idx;
    const char*	str;

} UI_OSD_LANGUAGE_S;

extern int UI_language;
extern UI_OSD_LANGUAGE_S lng_english_str[];
extern UI_OSD_LANGUAGE_S lng_chinese_str[];

void UI_language_set(int language);
int UI_language_get();
const char* UI_language_getStringByID(int id);

#define __(id) (QObject::tr(UI_language_getStringByID(id)))

