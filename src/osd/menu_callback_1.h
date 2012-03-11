#include "globe.h"

//menu av setup abstract layer interface
enum
{
    MENU_AV_VIDEO_576I = 0,
    MENU_AV_VIDEO_576P,
    MENU_AV_VIDEO_720P,
    MENU_AV_VIDEO_1080I
};

enum
{
    MENU_AV_AUDIO_LEFT = 0,
    MENU_AV_AUDIO_RIGHT,
    MENU_AV_AUDIO_STEREO
};

enum
{
    MENU_AV_SIZE_4_3 = 0,
    MENU_AV_SIZE_16_9
};
bool on_menuAVSetup_get(int *videoIdx, int *audioIdx, int *sizeIdx);
bool on_menuAVSetup_set(int videoIdx, int audioIdx, int sizeIdx);
bool on_menuAVSetup_videoSet(int row);
bool on_menuAVSetup_audioSet(int row);
bool on_menuAVSetup_sizeSet(int row);

//menu version abstract layer interface
bool on_menuVersion_get(char *num, int numLen,
                        char *model, int modelLen,
                        char *date, int dateLen,
                        char *hw, int hwLen,
                        char *sw, int swLen,
                        char *loader, int loaderLen,
                        char *face, int faceLen,
                        char *app, int appLen,
                        char *area, int areaLen);

//menu network abstract layer interface
bool on_menuNetwork_get(char *ip, int ipLen, char *mask, int maskLen,
                        char *gateway, int gatewayLen, char *dns, int dnsLen);
bool on_menuNetwork_set(const char *ip, int ipLen, const char *mask, int maskLen,
                        const char *gateway, int gatewayLen, const char *dns, int dnsLen);
bool on_menuNetwork_dhcp(void);

//menu ca abstract layer interface
bool on_menuCa_get(char *usr, int usrLen, char *card, int cardLen, char *pair, int pairLen);

//menu infobar abstract layer interface
enum
{
    MENU_INFOBAR_UP_SELECT = 0,
    MENU_INFOBAR_DOWN_SELECT
};

bool on_menuInfobar_get(char *id, int idLen,
                        char *programName, int programNameLen,
                        char *num, int numLen,
                        char *pEventName, int pEventNameLen,
                        char *pEventTime, int pEventTimeLen,
                        char *fEventName, int fEventNameLen,
                        char *fEventTime, int fEventTimeLen);
void on_menuInfobar_num_select(int id);
void on_menuInfobar_direct_select(int direct);

//menu pin abstract layer interface
bool on_MenuPin_checkPassword(const char *password);
