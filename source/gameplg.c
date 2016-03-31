#include "global.h"
#include "configs.h"
#include "cheats.h"


Handle fsUserHandle;
FS_archive sdmcArchive;
u32 IoBasePad = 0xFFFD4000;
enum language	langue = 0;
enum MENU		current_menu;
u16  mode;
u8 cheatEnabled[64];
int isNewNtr = 0;
GAME_PLUGIN_MENU gamePluginMenu;
t_menu	menu[MENU_COUNT];
unsigned int	after;

// detect language (0: english)
int detectLanguage()
{
	// unimplemented
	return 0;
}

// this function will be called when the state of cheat item changed
void onCheatItemChanged(int id, int enable)
{
	if (current_menu == BASE && id == 0)
		activate_menu();
	else
		change_state(get_real_id(id));
}

void switch_mode()
{
	if (mode)
	{
		change_text(BASE, find_id(BASE, "Switch mode") + 1, "  Current mode: 1");
		mode = 0;
	}
	else
	{
		change_text(BASE, find_id(BASE, "Switch mode") + 1, "  Current mode: 2");
		mode = 1;
	}
	show_base();
}

void key_trigger(int key)
{
	(key == (R + DU)) ? change_menu_status(BASE), waitKeyChange(key) : key + 0;
	(key == (L + R + DU)) ? change_menu_status(ADDING) : key + 0;
	(key == (R + DL)) ? change_state(find_id(BASE, "Monster #1 Infinite HP (R + Left)")), waitKeyChange(key) : key + 0;
	(key == (R + DR)) ? change_state(find_id(BASE, "Monster #2 Infinite HP (R + Right)")), waitKeyChange(key) : key + 0;
	(key == (R + DD)) ? change_state(find_id(BASE, "Monster #3 Infinite HP (R + Down)")), waitKeyChange(key) : key + 0;
	
}

void gamePluginEntry()
{
	u32 ret, key;
	u32 i = 0;
	INIT_SHARED_FUNC(plgGetIoBase, 8);
	INIT_SHARED_FUNC(copyRemoteMemory, 9);
	svc_sleepThread(5000000000);
	
	mode = 0;
	if (((NS_CONFIG*)(NS_CONFIGURE_ADDR))->sharedFunc[8])
	{
		isNewNtr = 1;
	} 
	else
	{
		isNewNtr = 0;
	}
	
	if (isNewNtr)
	{
		IoBasePad = plgGetIoBase(IO_BASE_PAD);
	}
	rtReleaseLock(&((NS_CONFIG*)(NS_CONFIGURE_ADDR))->debugBufferLock);
	plgGetSharedServiceHandle("fs:USER", &fsUserHandle);
	updateMenu();
	current_menu = BASE;
	init_menu();
	create_base_menu();
	show_menu(BASE);
	while (1)
	{
		key = getKey();
		if (key == BUTTON_ST + BUTTON_SE)
		{
			show_menu(BASE);
			waitKeyUp();
		}
		key_trigger(key);
		svc_sleepThread(10000000);
		scanCheatMenu();
		do_all_action();		
	}
}