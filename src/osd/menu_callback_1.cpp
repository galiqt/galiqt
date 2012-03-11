#include "globe.h"
#include "UIKit.h"
#include <stdio.h>

bool on_menuAVSetup_get(int *videoIdx, int *audioIdx, int *sizeIdx)
{
    //dummy
    (*videoIdx) = 0;
    (*audioIdx) = 1;
    (*sizeIdx) = 1;
    return TRUE;
}

bool on_menuAVSetup_videoSet(int row)
{
    qDebug("on_menuAVSetup_videoSet(%d)",row);
    switch(row)
    {
        case MENU_AV_VIDEO_576I:
            break;
        case MENU_AV_VIDEO_576P:
            break;
        case MENU_AV_VIDEO_720P:
            break;
        case MENU_AV_VIDEO_1080I:
            break;
        default:
            break;
    }
    return TRUE;
}

bool on_menuAVSetup_audioSet(int row)
{
    qDebug("on_menuAVSetup_audioSet(%d)",row);
    switch(row)
    {
        case MENU_AV_AUDIO_LEFT:
            break;
        case MENU_AV_AUDIO_RIGHT:
            break;
        case MENU_AV_AUDIO_STEREO:
            break;
        default:
            break;
    }
    return TRUE;
}

bool on_menuAVSetup_sizeSet(int row)
{
    qDebug("on_menuAVSetup_sizeSet(%d)",row);
    switch(row)
    {
        case MENU_AV_SIZE_4_3:
            break;
        case MENU_AV_SIZE_16_9:
            break;
        default:
            break;
    }
    return TRUE;
}

bool on_menuAVSetup_set(int videoIdx, int audioIdx, int sizeIdx)
{
    return TRUE;
}

bool on_menuVersion_get(char *num, int numLen,
                        char *model, int modelLen,
                        char *date, int dateLen,
                        char *hw, int hwLen,
                        char *sw, int swLen,
                        char *loader, int loaderLen,
                        char *face, int faceLen,
                        char *app, int appLen,
                        char *area, int areaLen)
{
    //dummy
    const char *numData = {"04001010111148810751"};
    const char *modelData = {"9399C-DYE-LAN"};
    const char *dateData = {"2012-03-08"};
    const char *hwData = {"147"};
    const char *swData = {"3.147.7.9.20"};
    const char *loaderData = {"1.1.20"};
    const char *faceData = {"87"};
    const char *appData = {"HAINAN"};
    const char *areaData = {"2"};

    strncpy(num, numData, numLen);
    strncpy(model, modelData, modelLen);
    strncpy(date, dateData, dateLen);
    strncpy(hw, hwData, hwLen);
    strncpy(sw, swData, swLen);
    strncpy(loader, loaderData, loaderLen);
    strncpy(face, faceData, faceLen);
    strncpy(app, appData, appLen);
    strncpy(area, areaData, areaLen);

    return TRUE;
}

bool on_menuNetwork_get(char *ip, int ipLen, char *mask, int maskLen,
                         char *gateway, int gatewayLen, char *dns, int dnsLen)
{
    //dummy
    const char *ipData = {"192.168.0.118"};
    const char *maskData = {"255.255.255.0"};
    const char *gatewayData = {"192.168.0.1"};
    const char *dnsData = {"192.168.0.10"};

    strncpy(ip, ipData, ipLen);
    strncpy(mask, maskData, maskLen);
    strncpy(gateway, gatewayData, gatewayLen);
    strncpy(dns, dnsData, dnsLen);

    return TRUE;
}

bool on_menuNetwork_set(const char *ip, int ipLen, const char *mask, int maskLen,
                        const char *gateway, int gatewayLen, const char *dns, int dnsLen)
{
    return TRUE;
}

bool on_menuNetwork_dhcp(void)
{
    return TRUE;
}

bool on_menuCa_get(char *usr, int usrLen, char *card, int cardLen, char *pair, int pairLen)
{
    //dummy
    const char *usrData = {"超级用户"};
    const char *cardData = {"71180200714C6C36"};
    const char *pairData = {"已配对"};

    strncpy(usr, usrData, usrLen);
    strncpy(card, cardData, cardLen);
    strncpy(pair, pairData, pairLen);

    return TRUE;
}

bool on_menuInfobar_get(char *id, int idLen,
                        char *programName, int programNameLen,
                        char *num, int numLen,
                        char *pEventName, int pEventNameLen,
                        char *pEventTime, int pEventTimeLen,
                        char *fEventName, int fEventNameLen,
                        char *fEventTime, int fEventTimeLen)
{
    //dummy
    const char *idData = {"27"};
    const char *programNameData = {"哈哈少儿"};
    const char *numData = {"50011008"};
    const char *pEventNameData = {"喜洋洋与灰太狼"};
    const char *pEventTimeData = {"19:30-20:00"};
    const char *fEventNameData = {"超级变变变"};
    const char *fEventTimeData = {"20:30-21:00"};

    strncpy(id, idData, idLen);
    strncpy(programName, programNameData, programNameLen);
    strncpy(num, numData, numLen);
    strncpy(pEventName, pEventNameData, pEventNameLen);
    strncpy(pEventTime, pEventTimeData, pEventTimeLen);
    strncpy(fEventName, fEventNameData, fEventNameLen);
    strncpy(fEventTime, fEventTimeData, fEventTimeLen);

    return TRUE;
}

void on_menuInfobar_num_select(int id)
{
    qDebug("num select(%d)",id);
}

void on_menuInfobar_direct_select(int direct)
{
    qDebug("direct select(%d)",direct);
}

bool on_MenuPin_checkPassword(const char *password)
{
    qDebug("password(%s)",password);
    return false;
}
