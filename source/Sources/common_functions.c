#include "global.h"
#include "configs.h"
#include "cheats.h"

extern	u32 threadStack[0x1000];
extern	Handle fsUserHandle;
extern	FS_archive sdmcArchive;
extern	u32 IoBasePad;
extern	enum language langue;
extern	enum MENU		current_menu;
extern	u16  mode;
extern	u8 cheatEnabled[64];
extern	int isNewNtr;
extern	GAME_PLUGIN_MENU gamePluginMenu;
extern	t_menu	menu[8];

void	debounceKey() 
{
	vu32 t;

	for (t = 0; t < 0x100000; t++) {}
}

u32		getKey() 
{
	return (*(vu32*)(IoBasePad) ^ 0xFFF) & 0xFFF;
}

u32		waitKey() 
{
	u32 key;
	// wait key to be released
	while (getKey() != 0);
	while (1) 
	{
		key = getKey();
		if (key != 0) 
		{
			break;
		}
	}
	debounceKey();
	return key;
}

void	waitKeyUp()
{
	while (getKey() != 0)
		svc_sleepThread(100000);
}

void	waitKeyChange(int key)
{
	while (getKey() == key) {}
}

void	str_replace(char *str, char a, char b)
{
	while (*str != '\0')
		if (*str++ == a)
			*(str -1) = b;
}

void	str_add_space(char *str, int n)
{
	char	buf[40];
	char	*s = buf;

	while (n-- > 0)
		*s++ = ' ';
	xsprintf(s, "%s", str);
	xsprintf(str, "%s", buf);
}

int		read(int addr, enum TYPE type)
{
	if (type == T8)
		return(READU8(addr));
	if (type == T16)
		return(READU16(addr));
	if (type == T32)
		return(READU32(addr));
}
