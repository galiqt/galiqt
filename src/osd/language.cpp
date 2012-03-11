#include "globe.h"
#include "UIKit.h"

int UI_language;

UI_OSD_LANGUAGE_S lng_english_str[] =
{
	{ STR_MENU_EMPTY						, ""                        },
	{ STR_MAINMENU_TITLE					, "Main Menu"               },
	{ STR_MAINMENU_NUMBER					, "NO. 50010011"	        },	

	{ STR_MAINMENU_TV						, "TV" 			            },
	{ STR_MAINMENU_RADIO					, "Radio" 		            },
	{ STR_MAINMENU_MEDIA					, "Media"		            },
	{ STR_MAINMENU_BILLING					, "Billing"		            },
	{ STR_MAINMENU_EPG						, "EPG"     		        },	
	{ STR_MAINMENU_SYSTEM					, "System" 		            },
		
	{ STR_SYSTEM_TITLE						, "China Cable"             },
	{ STR_SYSTEM_AUTO_SEARCH				, "Auto Search"             },
	{ STR_SYSTEM_MANUAL_SEARCH				, "Manual Search"           }, 
	{ STR_SYSTEM_SETTING					, "System Setting"          },
	{ STR_SYSTEM_UPDATE						, "Update"                  },
	{ STR_SYSTEM_FACTORY					, "Factory setting"         },			
	{ STR_SYSTEM_NETWORK_SETTING			, "Network setting"         },
	{ STR_SYSTEM_VERSION					, "Version"                 },
	{ STR_SYSTEM_CACARD						, "CA Card"                 },	  
	{ STR_VOLUME_TITLE						, "Volume"					},
	{ STR_VOLUME_MUTE                     	, "Mute"                    },
	{ STR_SOUND_LEFT                     	, "Left"                    },
	{ STR_SOUND_RIGHT                     	, "Right"                   },
	{ STR_SOUND_STEREO                     	, "Stereo"                  },	
	{ STR_LANGUAGE_ENGLISH                	, "English"                 },
	{ STR_LANGUAGE_CHINESE                	, "Chinese"                 },
	{ STR_MENU_MAX                        	, ""                        }
};


UI_OSD_LANGUAGE_S lng_chinese_str[] =
{
	{ STR_MENU_EMPTY                      	, ""    	                },
	{ STR_MAINMENU_TITLE                  	, "��ҳƵ��"                },
	{ STR_MAINMENU_NUMBER					, "���Ӻ� 50010011"         },

	{ STR_MAINMENU_TV						, "����" 		            },
	{ STR_MAINMENU_RADIO					, "�㲥" 		            },
	{ STR_MAINMENU_MEDIA					, "��ý��"		            },
	{ STR_MAINMENU_BILLING					, "�˻���ֵ"	            },
	{ STR_MAINMENU_EPG						, "��Ϣ����"   		        },	
	{ STR_MAINMENU_SYSTEM					, "ϵͳ����"	            },
	
	{ STR_SYSTEM_TITLE						, "�й�����" 	            },	
	{ STR_SYSTEM_AUTO_SEARCH				, "�Զ�����" 	            },
	{ STR_SYSTEM_MANUAL_SEARCH				, "�ֶ�����"           		}, 
	{ STR_SYSTEM_SETTING					, "��������"          		},
	{ STR_SYSTEM_UPDATE						, "�ֶ�����"               	},
	{ STR_SYSTEM_FACTORY					, "�ָ���������"         	},			
	{ STR_SYSTEM_NETWORK_SETTING			, "��������"         		},
	{ STR_SYSTEM_VERSION					, "�汾��Ϣ"                },
	{ STR_SYSTEM_CACARD						, "���ܿ���Ϣ"              },
	{ STR_VOLUME_TITLE						, "����"					},
 	{ STR_VOLUME_MUTE                     	, "�� ��"                   },
	{ STR_SOUND_LEFT                     	, "������"                  },
	{ STR_SOUND_RIGHT                     	, "������"                  },
	{ STR_SOUND_STEREO                     	, "������"                  },
 	{ STR_LANGUAGE_ENGLISH                	, "Ӣ��"                    },
 	{ STR_LANGUAGE_CHINESE                	, "����"                    },
 	{ STR_MENU_MAX                        	, "" 	                    }
};
