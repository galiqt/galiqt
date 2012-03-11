
#include "dtv.h"
#include "osd/globe.h"
QApplication *g_qAPP;

int main(int argc,char *argv[])
{
#ifdef _PLATFORM_ARM_
	QWSServer::setBackground(QColor(0,0,0,0));
	QApplication a(argc, argv, QApplication::GuiServer);
	QWSServer::setCursorVisible(FALSE);
#endif

#ifdef _PLATFORM_WIN32_
	QApplication a(argc, argv);
#endif
	g_qAPP = &a;
	
	DTV_Entry();
	
 	return a.exec();
}
