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
	{ STR_MAINMENU_TITLE                  	, "主页频道"                },
	{ STR_MAINMENU_NUMBER					, "电视号 50010011"         },

	{ STR_MAINMENU_TV						, "电视" 		            },
	{ STR_MAINMENU_RADIO					, "广播" 		            },
	{ STR_MAINMENU_MEDIA					, "多媒体"		            },
	{ STR_MAINMENU_BILLING					, "账户充值"	            },
	{ STR_MAINMENU_EPG						, "信息服务"   		        },	
	{ STR_MAINMENU_SYSTEM					, "系统设置"	            },
	
	{ STR_SYSTEM_TITLE						, "中国有线" 	            },	
	{ STR_SYSTEM_AUTO_SEARCH				, "自动搜索" 	            },
	{ STR_SYSTEM_MANUAL_SEARCH				, "手动搜索"           		}, 
	{ STR_SYSTEM_SETTING					, "参数配置"          		},
	{ STR_SYSTEM_UPDATE						, "手动升级"               	},
	{ STR_SYSTEM_FACTORY					, "恢复出厂设置"         	},			
	{ STR_SYSTEM_NETWORK_SETTING			, "网络设置"         		},
	{ STR_SYSTEM_VERSION					, "版本信息"                },
	{ STR_SYSTEM_CACARD						, "智能卡信息"              },
	{ STR_VOLUME_TITLE						, "音量"					},
 	{ STR_VOLUME_MUTE                     	, "静 音"                   },
	{ STR_SOUND_LEFT                     	, "左声道"                  },
	{ STR_SOUND_RIGHT                     	, "右声道"                  },
	{ STR_SOUND_STEREO                     	, "立体声"                  },
 	{ STR_LANGUAGE_ENGLISH                	, "英文"                    },
 	{ STR_LANGUAGE_CHINESE                	, "中文"                    },
 	{ STR_MENU_MAX                        	, "" 	                    }
};
