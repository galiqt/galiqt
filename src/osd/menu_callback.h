#include "globe.h"

bool on_menuRoot_key_press(QKeyEvent *event);
bool on_menuMain_key_press(QKeyEvent *event);
bool on_MenuSystem_key_press(QKeyEvent *event);
bool on_MenuVolume_key_press(QKeyEvent *event);
bool on_MenuSound_key_press(QKeyEvent *event);

void MenuMain_on_TVClicked();
void MenuMain_on_RadioClicked();
void MenuMain_on_MediaClicked();
void MenuMain_on_BillingClicked();
void MenuMain_on_EPGClicked();
void MenuMain_on_SystemClicked();

void on_MenuSystem_AutoSearchClicked();
void on_MenuSystem_ManualSearchClicked();
void on_MenuSystem_SystemSettingClicked();
void on_MenuSystem_UpdateClicked();
void on_MenuSystem_FactoryClicked();
void on_MenuSystem_NetworkSettingClicked();
void on_MenuSystem_VersionClicked();
void on_MenuSystem_CACardClicked();

bool MenuAutoSearch_key_press(QKeyEvent *event);

bool MenuManualSearch_key_press(QKeyEvent *event);
void MenuManualSearch_on_scanClicked();

bool MenuUpdate_key_press(QKeyEvent *event);
bool MenuFactory_key_press(QKeyEvent *event);