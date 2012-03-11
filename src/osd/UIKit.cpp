#include "globe.h"
#include "UIKit.h"


UI_ID_E g_menuid_stack[UI_ID_MAX];
int  		g_menuid_index;

typedef struct
{
	int x;
	int y;
	int w;
	int h;
}UI_MENU_POS_S;

UI_MENU_POS_S	g_menupos_stack[UI_ID_MAX];

QString g_stylesheet_stack[UI_STYLESHEET_MAX];
//#define LIVE_VIDEO_USE
bool UI_init_pos()
{
#ifdef LIVE_VIDEO_USE
	g_menupos_stack[UI_ID_ROOT].x			=	960;			g_menupos_stack[UI_ID_ROOT].y			=	0;
	g_menupos_stack[UI_ID_ROOT].w			=	10;				g_menupos_stack[UI_ID_ROOT].h			=	10;
#else	
    g_menupos_stack[UI_ID_ROOT].x			=	0+OFFSET_X;		g_menupos_stack[UI_ID_ROOT].y			=	0+OFFSET_Y;
    g_menupos_stack[UI_ID_ROOT].w			=	960;			g_menupos_stack[UI_ID_ROOT].h			=	540;
#endif
	g_menupos_stack[UI_ID_MAIN_MENU].x		=	0+OFFSET_X;		g_menupos_stack[UI_ID_MAIN_MENU].y		=	320+OFFSET_Y;
	g_menupos_stack[UI_ID_MAIN_MENU].w		=	960;			g_menupos_stack[UI_ID_MAIN_MENU].h		=	150;
    g_menupos_stack[UI_ID_CONFIG].x			=	0+OFFSET_X;		g_menupos_stack[UI_ID_CONFIG].y			=	0+OFFSET_Y;
    g_menupos_stack[UI_ID_CONFIG].w			=	960;			g_menupos_stack[UI_ID_CONFIG].h			=	540;
	g_menupos_stack[UI_ID_CHANNEL_LIST].x	=	100+OFFSET_X;	g_menupos_stack[UI_ID_CHANNEL_LIST].y	=	50+OFFSET_Y;
	g_menupos_stack[UI_ID_CHANNEL_LIST].w	=	288;			g_menupos_stack[UI_ID_CHANNEL_LIST].h	=	430;
	g_menupos_stack[UI_ID_VIDEO_SET].x		=	360+OFFSET_X;	g_menupos_stack[UI_ID_VIDEO_SET].y		=	0+OFFSET_Y;
	g_menupos_stack[UI_ID_VIDEO_SET].w		=	600;			g_menupos_stack[UI_ID_VIDEO_SET].h		=	540;
	g_menupos_stack[UI_ID_AV_SETUP].x		=	360+OFFSET_X;	g_menupos_stack[UI_ID_AV_SETUP].y		=	0+OFFSET_Y;
	g_menupos_stack[UI_ID_AV_SETUP].w		=	600;			g_menupos_stack[UI_ID_AV_SETUP].h		=	540;
	g_menupos_stack[UI_ID_VERSION].x		=	360+OFFSET_X;	g_menupos_stack[UI_ID_VERSION].y		=	0+OFFSET_Y;
	g_menupos_stack[UI_ID_VERSION].w		=	600;			g_menupos_stack[UI_ID_VERSION].h		=	540;
    g_menupos_stack[UI_ID_NETWORK].x		=	360+OFFSET_X;	g_menupos_stack[UI_ID_NETWORK].y		=	0+OFFSET_Y;
    g_menupos_stack[UI_ID_NETWORK].w		=	600;			g_menupos_stack[UI_ID_NETWORK].h		=	540;
    g_menupos_stack[UI_ID_CA].x             =	360+OFFSET_X;	g_menupos_stack[UI_ID_CA].y             =	0+OFFSET_Y;
    g_menupos_stack[UI_ID_CA].w             =	600;			g_menupos_stack[UI_ID_CA].h             =	540;
    g_menupos_stack[UI_ID_INFORBAR].x		=	210+OFFSET_X;	g_menupos_stack[UI_ID_INFORBAR].y		=	372+OFFSET_Y;
	g_menupos_stack[UI_ID_INFORBAR].w		=	570;			g_menupos_stack[UI_ID_INFORBAR].h		=	148;
    g_menupos_stack[UI_ID_PIN].x             =	325+OFFSET_X;	g_menupos_stack[UI_ID_PIN].y            =	150+OFFSET_Y;
    g_menupos_stack[UI_ID_PIN].w             =	310;			g_menupos_stack[UI_ID_PIN].h            =	240;
	g_menupos_stack[UI_ID_VOLUME].x			=	230+OFFSET_X;	g_menupos_stack[UI_ID_VOLUME].y			=	400+OFFSET_Y;
	g_menupos_stack[UI_ID_VOLUME].w			=	540;			g_menupos_stack[UI_ID_VOLUME].h			=	60;
	g_menupos_stack[UI_ID_SOUND].x			=	700+OFFSET_X;	g_menupos_stack[UI_ID_SOUND].y			=	50+OFFSET_Y;
	g_menupos_stack[UI_ID_SOUND].w			=	100;			g_menupos_stack[UI_ID_SOUND].h			=	40;
	g_menupos_stack[UI_ID_MUTE].x			=	100+OFFSET_X;	g_menupos_stack[UI_ID_MUTE].y			=	50+OFFSET_Y;
	g_menupos_stack[UI_ID_MUTE].w			=	270;			g_menupos_stack[UI_ID_MUTE].h			=	420;
	g_menupos_stack[UI_ID_AUTO_SEARCH].x	=	360+OFFSET_X;	g_menupos_stack[UI_ID_AUTO_SEARCH].y	=	0+OFFSET_Y;
	g_menupos_stack[UI_ID_AUTO_SEARCH].w	=	600;			g_menupos_stack[UI_ID_AUTO_SEARCH].h	=	540;
	g_menupos_stack[UI_ID_MANUAL_SEARCH].x	=	360+OFFSET_X;	g_menupos_stack[UI_ID_MANUAL_SEARCH].y	=	0+OFFSET_Y;
	g_menupos_stack[UI_ID_MANUAL_SEARCH].w	=	600;			g_menupos_stack[UI_ID_MANUAL_SEARCH].h	=	540;
	g_menupos_stack[UI_ID_SEARCHING].x		=	100+OFFSET_X;	g_menupos_stack[UI_ID_SEARCHING].y		=	50+OFFSET_Y;
	g_menupos_stack[UI_ID_SEARCHING].w		=	440;			g_menupos_stack[UI_ID_SEARCHING].h		=	360;
	g_menupos_stack[UI_ID_EPG].x			=	100+OFFSET_X;	g_menupos_stack[UI_ID_EPG].y			=	50+OFFSET_Y;
	g_menupos_stack[UI_ID_EPG].w			=	760;			g_menupos_stack[UI_ID_EPG].h			=	440;
	g_menupos_stack[UI_ID_MEDIA].x			=	40+OFFSET_X;	g_menupos_stack[UI_ID_MEDIA].y			=	20+OFFSET_Y;
	g_menupos_stack[UI_ID_MEDIA].w			=	300;			g_menupos_stack[UI_ID_MEDIA].h			=	500;
	g_menupos_stack[UI_ID_INFORMATION].x	=	-1+OFFSET_X;	g_menupos_stack[UI_ID_INFORMATION].y	=	-1+OFFSET_Y;
	g_menupos_stack[UI_ID_INFORMATION].w	=	400;			g_menupos_stack[UI_ID_INFORMATION].h	=	400;
	g_menupos_stack[UI_ID_MEIDA_PLAYER].x	=	230+OFFSET_X;	g_menupos_stack[UI_ID_MEIDA_PLAYER].y	=	380+OFFSET_Y;
	g_menupos_stack[UI_ID_MEIDA_PLAYER].w	=	520;			g_menupos_stack[UI_ID_MEIDA_PLAYER].h	=	150;
	g_menupos_stack[UI_ID_WEBKIT].x			=	20+OFFSET_X;	g_menupos_stack[UI_ID_WEBKIT].y			=	20+OFFSET_Y;
	g_menupos_stack[UI_ID_WEBKIT].w			=	940;			g_menupos_stack[UI_ID_WEBKIT].h			=	500;
	
	return TRUE;
}

int	UI_menu_getx(UI_ID_E menu_id)
{
	if(menu_id<UI_ID_MAX)
	{
		return g_menupos_stack[menu_id].x	;
	}else
	{
		return 0;	
	}	
}

int	UI_menu_gety(UI_ID_E menu_id)
{
	if(menu_id<UI_ID_MAX)
	{
		return g_menupos_stack[menu_id].y	;
	}else
	{
		return 0;	
	}		
}

int	UI_menu_getw(UI_ID_E menu_id)
{
	if(menu_id<UI_ID_MAX)
	{
		return g_menupos_stack[menu_id].w	;
	}else
	{
		return 0;	
	}		
}

int	UI_menu_geth(UI_ID_E menu_id)
{
	if(menu_id<UI_ID_MAX)
	{
		return g_menupos_stack[menu_id].h	;
	}else
	{
		return 0;	
	}		
}

/////////////////////////// ui language ///////////////
void UI_language_set(int language)
{
	if(language < LANGUAGE_MAX)
	{
		UI_language = language;
	}
}

int UI_language_get()
{
	return 	UI_language;
}

const char* UI_language_getStringByID(int id)
{
	if(id>=STR_MENU_MAX){return NULL;}

	if(UI_language==LANGUAGE_ENGLISH)
	{
		return lng_english_str[id].str;
	}else
	{
		return lng_chinese_str[id].str;	
	}
	
}

////////////////////////// ui style sheet ///////////		
bool UI_init_styleSheet()
{
	QFile fileCommon(STYLE_SHEET_COMMON);
	fileCommon.open(QFile::ReadOnly);
	QTextStream fileTextCommon(&fileCommon);
	g_stylesheet_stack[UI_STYLESHEET_COMMON] = fileTextCommon.readAll();
	fileCommon.close(); 
	qDebug("qss common len [%d]",g_stylesheet_stack[UI_STYLESHEET_COMMON].length());
	 
	QFile fileRoot(STYLE_SHEET_ROOT);
	fileRoot.open(QFile::ReadOnly);
	QTextStream fileTextRoot(&fileRoot);
 	g_stylesheet_stack[UI_STYLESHEET_ROOT]= fileTextRoot.readAll();
	qDebug("qss root len = [%d]",g_stylesheet_stack[UI_STYLESHEET_ROOT].length() );
	fileRoot.close();
	
	QFile fileLabelTitle(STYLE_SHEET_LABEL_TITLE);
	fileLabelTitle.open(QFile::ReadOnly);
	QTextStream fileTextLabelTitle(&fileLabelTitle);
	g_stylesheet_stack[UI_STYLESHEET_LABEL_TITLE]= fileTextLabelTitle.readAll();
	qDebug("qss label title len = [%d]",g_stylesheet_stack[UI_STYLESHEET_LABEL_TITLE].length() );
    fileLabelTitle.close();

    QFile fileAvSetup(STYLE_SHEET_AV_SETUP);
    fileAvSetup.open(QFile::ReadOnly);
    QTextStream fileTextAvSetup(&fileAvSetup);
    g_stylesheet_stack[UI_STYLESHEET_AV_SETUP]= fileTextAvSetup.readAll();
    qDebug("qss av setup len = [%d]",g_stylesheet_stack[UI_STYLESHEET_AV_SETUP].length() );
    fileAvSetup.close();

    QFile fileNetwork(STYLE_SHEET_NETWORK);
    fileNetwork.open(QFile::ReadOnly);
    QTextStream fileTextNetwork(&fileNetwork);
    g_stylesheet_stack[UI_STYLESHEET_NETWORK]= fileTextNetwork.readAll();
    qDebug("qss network len = [%d]",g_stylesheet_stack[UI_STYLESHEET_NETWORK].length() );
    fileNetwork.close();

    QFile fileInfobar(STYLE_SHEET_INFOBAR);
    fileInfobar.open(QFile::ReadOnly);
    QTextStream fileTextInfobar(&fileInfobar);
    g_stylesheet_stack[UI_STYLESHEET_INFOBAR]= fileTextInfobar.readAll();
    qDebug("qss infobar len = [%d]",g_stylesheet_stack[UI_STYLESHEET_INFOBAR].length() );
    fileInfobar.close();

    QFile filePin(STYLE_SHEET_PIN);
    filePin.open(QFile::ReadOnly);
    QTextStream fileTextPin(&filePin);
    g_stylesheet_stack[UI_STYLESHEET_PIN]= fileTextPin.readAll();
    qDebug("qss pin len = [%d]",g_stylesheet_stack[UI_STYLESHEET_PIN].length() );
    filePin.close();

    QFile file1(STYLE_SHEET_TITLEBAR);
    file1.open(QFile::ReadOnly);
    QTextStream fileText1(&file1);
    g_stylesheet_stack[UI_STYLESHEET_TITLEBAR]= fileText1.readAll();
    qDebug("qss title bar len = [%d]",g_stylesheet_stack[UI_STYLESHEET_TITLEBAR].length() );
    file1.close();

	return TRUE;
}

QString* UI_styleSheet_get(UI_ID_STYLESHEET styleSheet_id)
{
	if(styleSheet_id<UI_STYLESHEET_MAX)
	{
		return &(g_stylesheet_stack[styleSheet_id]);
	}else
	{
		return NULL;	
	}	
	
}

bool UI_create()
{
	MenuRoot *pMenuRoot=0;
	pMenuRoot = UI_menuRoot_create();
	if(!pMenuRoot)
	{
		return FALSE;  
	}
	
	(void)UI_menuMain_create();
	(void)UI_MenuChannelList_create();
	(void)UI_MenuVideoSet_create();
	(void)UI_MenuVolume_create();
	(void)UI_MenuSound_create();
	(void)UI_MenuAVSetup_create();
	(void)UI_MenuVersion_create();
	(void)UI_MenuNetwork_create();
	(void)UI_MenuCa_create();
	(void)UI_MenuInfobar_create();
	(void)UI_MenuPin_create();
	(void)UI_MenuServiceList_create();
	(void)UI_MenuFavorManager_create();
	(void)UI_MenuAutoSearch_create();
	(void)UI_MenuManualSearch_create();
	(void)UI_MenuUpdate_create();
	(void)UI_MenuFactory_create();	
	(void)UI_MenuSystem_create();// need last

	return TRUE;
}

void  print_menu_id(UI_ID_E menu_id)
{
	switch(menu_id)
	{
		case UI_ID_ROOT:
			printf("menu ROOT");
			break;  	
    	case UI_ID_MAIN_MENU:
    		printf("menu MAIN_MENU");
    		break;
    	case UI_ID_CONFIG:   
    		printf("menu CONFIG"); 		
    		break;    		
    	case UI_ID_CHANNEL_LIST:
    		printf("menu CHANNEL_LIST");
    		break;
    	case UI_ID_VIDEO_SET:
    		printf("menu VIDEO_SET");
    		break;    		
		case UI_ID_AV_SETUP:
    		printf("menu UI_ID_AV_SETUP");
    		break;
		case UI_ID_VERSION:
    		printf("menu UI_ID_VERSION");
    		break;
        case UI_ID_NETWORK:
            printf("menu UI_ID_NETWORK");
    		break;
		case UI_ID_CA:
    		printf("menu UI_ID_CA_INFO");
    		break;
		case UI_ID_PIN:
    		printf("menu UI_ID_PIN");
    		break;
    	case UI_ID_INFORBAR:
    		printf("menu INFORBAR");
    		break;
    	case UI_ID_VOLUME:
    		printf("menu VOLUME");
    		break;
    	case UI_ID_SOUND:
    		printf("menu SOUND");
    		break;	
    	case UI_ID_MUTE:
    		printf("menu MUTE");
    		break;    		
    	case UI_ID_AUTO_SEARCH:
    		printf("menu AUTO_SEARCH");
    		break;
    	case UI_ID_MANUAL_SEARCH:
    		printf("menu MANUAL_SEARCH");
    		break;    		
    	case UI_ID_SEARCHING:
    		printf("menu SEARCHING");
    		break;
    	case UI_ID_EPG:
    		printf("menu EPG");
    		break;    		
    	case UI_ID_MEDIA:   
    		printf("menu MEDIA"); 		
    		break;
    	case UI_ID_INFORMATION:   
    		printf("menu MSG_OK_CANCEL"); 		
    		break; 
    	case UI_ID_MEIDA_PLAYER:
    		printf("menu UI_ID_MEIDA_PLAYER"); 		
    		break;  
    	case UI_ID_WEBKIT:
    		printf("menu UI_ID_WEBKIT"); 				
    		break;
    	case UI_ID_FAVOR_MANAGER:
    	    qDebug("menu UI_ID_FAVOR_MANAGER");
    	    break;				
		case UI_ID_UPDATE:
			printf("menu UI_ID_UPDATE");
			break;		
		case UI_ID_FACTORY:
			printf("menu UI_ID_FACTORY");
			break;				   		
		default:
			printf("menu UNKNOWN");
				
	}
}

UI_ID_E UI_menu_getcurrent()
{	
	int i;

	if(g_menuid_index==0)
	{	
		printf(">>menu_stack:[%d]",0);
		print_menu_id(g_menuid_stack[g_menuid_index]);
		printf("\n");
		return UI_ID_ROOT;
	}
	printf(">>menu_stack:");
	for(i=0;i<(g_menuid_index+1);i++)
	{
			printf("[%d]",i);
			print_menu_id(g_menuid_stack[i]);
			printf(" ");	
	}
	printf("\n");
	
	return g_menuid_stack[g_menuid_index];
}

bool UI_menu_present(UI_ID_E menu_id)
{
    if(menu_id<UI_ID_MAX)
    {
        UI_menu_hide(menu_id);
        UI_menu_show(menu_id);
    }
    return TRUE;
}

bool UI_menu_entry(UI_ID_E menu_id)
{
    if(menu_id<UI_ID_MAX)
    {
        switch(menu_id)
        {
            case UI_ID_ROOT:
                    g_menuid_index=0;
                    break;
            default:
                    g_menuid_index++;
                    break;
        }

        g_menuid_stack[g_menuid_index]=menu_id;
        UI_menu_show(menu_id);
        UI_menu_getcurrent();
        return TRUE;

    }
    return FALSE;
}

bool UI_menu_back()
{
    if(g_menuid_index>UI_ID_ROOT)
    {
        g_menuid_index--;

        UI_menu_show(g_menuid_stack[g_menuid_index]);

        UI_menu_getcurrent();

        return TRUE;
    }
    return FALSE;
}

bool UI_menu_show(UI_ID_E menu_id)
{
	if(menu_id<UI_ID_MAX)
	{
		switch(menu_id)
		{
			case UI_ID_ROOT:
				UI_menuRoot_show(); 
				break;	
			case UI_ID_MAIN_MENU:
				UI_menuMain_show();
				break;
			case UI_ID_CONFIG:
				UI_MenuSystem_show();
				break;
			case UI_ID_CHANNEL_LIST:
			    UI_MenuServiceList_show();
				break;
			case UI_ID_VIDEO_SET:
				UI_MenuVideoSet_show();
				break;
			case UI_ID_VOLUME:
				UI_MenuVolume_show();
				break;
			case UI_ID_SOUND:
				UI_MenuSound_show();
				break;
			case UI_ID_AV_SETUP:
			    UI_MenuAVSetup_show();
			    break;
			case UI_ID_VERSION:
			    UI_MenuVersion_show();
			    break;
			case UI_ID_NETWORK:
			    UI_MenuNetwork_show();
			    break;
			case UI_ID_CA:
			    UI_MenuCa_show();
			    break;
			case UI_ID_INFORBAR:
				UI_MenuInfobar_show();
				break;
			case UI_ID_PIN:
				UI_MenuPin_show();
				break;
            case UI_ID_FAVOR_MANAGER:
                UI_MenuFavorManager_show();
				break;
			case UI_ID_AUTO_SEARCH:
			    UI_MenuAutoSearch_show();
			    break;
			case UI_ID_MANUAL_SEARCH:
			    UI_MenuManualSearch_show();
			    break;
			case UI_ID_UPDATE:
			    UI_MenuUpdate_show();
			    break;
			case UI_ID_FACTORY:
			    UI_MenuFactory_show();
			    break;			    			    	    		    
			default:
				break;	
		}
	}
	return TRUE;
}

bool UI_menu_hide(UI_ID_E menu_id)
{
    if(menu_id<UI_ID_MAX)
	{
		switch(menu_id)
		{
			case UI_ID_ROOT:
				UI_menuRoot_hide(); 
				break;	
			case UI_ID_MAIN_MENU:
				UI_menuMain_hide();
				break;
			case UI_ID_CONFIG:
				UI_MenuSystem_hide();
				break;
			case UI_ID_CHANNEL_LIST:
			    UI_MenuServiceList_hide();
				break;
			case UI_ID_VIDEO_SET:
				UI_MenuVideoSet_hide();
				break;															
			case UI_ID_VOLUME:
				UI_MenuVolume_hide();
				break;
			case UI_ID_SOUND:
				UI_MenuSound_hide();
				break;					
			case UI_ID_AV_SETUP:
			    UI_MenuAVSetup_hide();
			    break;
			case UI_ID_VERSION:
			    UI_MenuVersion_hide();
			    break;
			case UI_ID_NETWORK:
			    UI_MenuNetwork_hide();
			    break;
			case UI_ID_CA:
			    UI_MenuCa_hide();
			    break;
			case UI_ID_INFORBAR:
				UI_MenuInfobar_hide();
				break;
			case UI_ID_PIN:
				UI_MenuPin_hide();
				break;		    	
	        case UI_ID_FAVOR_MANAGER:
	            UI_MenuFavorManager_hide();
	            break;
			case UI_ID_AUTO_SEARCH:
			    UI_MenuAutoSearch_hide();
			    break;
			case UI_ID_MANUAL_SEARCH:
			    UI_MenuManualSearch_hide();
			    break;
			case UI_ID_UPDATE:
			    UI_MenuUpdate_hide();
			    break;
			case UI_ID_FACTORY:
			    UI_MenuFactory_hide();
			    break;			    		    		    
			default:
				break;	
		}
	}
	return TRUE;	
}

