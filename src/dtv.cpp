#include "dtv.h"
#include "osd/globe.h"
#include "osd/UIKit.h"

bool DTV_Entry()
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK")); 
	
	UI_init_styleSheet();
	QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_COMMON);
	if (pStyleSheet)
	{
		g_qAPP->setStyleSheet(*pStyleSheet);	
	}		
	UI_init_pos();
  
  bool rtn = UI_create();
  if(!rtn)
  {
  	qDebug("create MenuRoot failed");
  	return FALSE;  
  }
  
  UI_menu_entry(UI_ID_ROOT);
  
	return TRUE;

}
