#include "global.h"
#include "configs.h"
#include "cheats.h"

extern	u32					threadStack[0x1000];
extern	Handle				fsUserHandle;
extern	FS_archive			sdmcArchive;
extern	u32					IospoilerPad;
extern	enum language		langue;
extern	enum MENU			current_menu;
extern	u16					mode;
extern	u8					cheatEnabled[64];
extern	int					isNewNtr;
extern	GAME_PLUGIN_MENU	gamePluginMenu;
extern	t_menu				menu[8];
extern	unsigned int		after;


void	create_base_menu()
{
	t_spoil		spoiler;
	t_spoil		midspoil;

	add_activate_menu(BASE, "Activate Cheat (R + UP)");
	add_separator_menu(BASE);
	spoiler = add_head_spoiler_menu(BASE, "Exploration's cheats");
	midspoil = add_head_child_spoiler_menu(spoiler, "MAX Codes");
	add_child_spoiler_menu(midspoil, "Infinite HP", infinite_health);
	add_child_spoiler_menu(midspoil, "Infinite AP", infinite_AP);
	add_child_spoiler_menu(midspoil, "Resonance MAX", resonance_x999);
	midspoil = add_head_child_spoiler_menu(spoiler, "Refill Codes");
	add_child_spoiler_menu(midspoil, "Refill HP (L + LEFT)", refill_health);
	add_child_spoiler_menu(midspoil, "Refill AP (L + RIGHT)", refill_AP);
	add_child_spoiler_menu(midspoil, "Resonance MAX  (L + UP)", resonance_trigger);
	add_sharp_child_spoiler_menu(spoiler, "No skills cooldown", no_cooldown);
	add_sharp_child_spoiler_menu(spoiler, "Freeze time quest", freeze_time);
	spoiler = add_head_spoiler_menu(BASE, "Inventory's cheats");
	add_sharp_child_spoiler_menu(spoiler, "Gils MAX", gils_max);
	add_sharp_child_spoiler_menu(spoiler, "CP MAX", cp_max);
	add_sharp_child_spoiler_menu(spoiler, "All consumables x99", consumables_x99);
	add_sharp_child_spoiler_menu(spoiler, "All Atmaliths and Magicites x99", atma_magi_x99);
	add_sharp_child_spoiler_menu(spoiler, "All Materials x99", materials_x99);
	spoiler = add_head_spoiler_menu(BASE, "Monsters's cheats");
	add_child_spoiler_menu(spoiler, "Monster #1 Infinite HP (R + Left)", monster_1_health);
	add_child_spoiler_menu(spoiler, "Monster #2 Infinite HP (R + Right)", monster_2_health);
	add_child_spoiler_menu(spoiler, "Monster #3 Infinite HP (R + Down)", monster_3_health);
	add_separator_menu(BASE);
	add_sharp_menu(BASE, "Unlock DLC Quests", unlock_dlc);
	add_separator_menu(BASE);//24
	add_sharp_menu(BASE, "Switch mode", switch_mode);
	if (mode == 0)
		add_space_menu(BASE, "Current mode: 1", NULL);
	else
		add_space_menu(BASE, "  Current mode: 2", NULL);
	//add_separator_menu(BASE);
	//add_sharp_menu(BASE, "/// DEBUG /\\ TESTS \\\\\\", show_debug);
}

void	create_adding_menu(char *item, int addr, enum TYPE type)
{
	char				buf[40];
	unsigned int	current;

	current = read(addr, type);
	after = current;
	memset(&(menu[ADDING]), 0, sizeof(menu[ADDING]));
	menu[ADDING].status = 1;

	add_nothing_menu(ADDING, "Apply", NULL);
	add_nothing_menu(ADDING, "Cancel", show_base);
	add_line_menu(ADDING);

	xsprintf(buf, "Editing:  %s", item);
	add_nothing_menu(ADDING, buf, NULL);
	add_line_menu(ADDING);

	memset(buf, '\0', 40);
	xsprintf(buf, "Current:  %d", current);
	add_space_menu(ADDING, buf, NULL);
	memset(buf, '\0', 40);
	xsprintf(buf, "After:  %d", after);
	add_space_menu(ADDING, buf, NULL);
}

void	create_address_menu(char *item)
{
	char				buf[40];

	memset(&(menu[ADDING]), 0, sizeof(menu[ADDING]));
	menu[ADDING].status = 1;

	add_nothing_menu(ADDING, "Go back", show_base);
	add_line_menu(ADDING);

	xsprintf(buf, "%s", item);
	add_nothing_menu(ADDING, buf, get_address);
	add_line_menu(ADDING);
}

void	create_debug_menu()
{
	menu[DEBUG].status = 1;
	add_nothing_menu(DEBUG, "Go back", show_base);
	add_separator_menu(DEBUG);
	add_sharp_menu(DEBUG, "Get Monsters address", get_address);
	add_separator_menu(DEBUG);
	add_sharp_menu(DEBUG, "Edit Gils", set_gils);
	add_sharp_menu(DEBUG, "Edit CP", NULL);
	add_separator_menu(DEBUG);
	add_line_menu(DEBUG);
	add_sharp_menu(DEBUG, "!!! Reset !!!", create_reset_menu);
	add_separator_menu(DEBUG);
}

void	create_reset_menu()
{
	memset(&(menu[ADDING]), 0, sizeof(menu[ADDING]));
	menu[ADDING].status = 1;

	add_nothing_menu(ADDING, "Go back", show_base);
	add_line_menu(ADDING);
	add_nothing_menu(ADDING, "!!! Attention !!!", NULL);
	add_nothing_menu(ADDING, "By pressing Reset, you'll lost all", NULL);
	add_nothing_menu(ADDING, "your inventory objects except", NULL);
	add_nothing_menu(ADDING, "your equipments !!!", NULL);
	add_line_menu(ADDING);
	add_sharp_menu(ADDING, "Reset", reset);
	show_menu(ADDING);
}