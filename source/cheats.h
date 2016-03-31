#ifndef CHEATS_H
#define CHEATS_H
#include "global.h"
#include "configs.h"

#define MENU_COUNT 3

enum language	{	EN, FR };
enum TYPE		{	T8, T16, T32};
enum MENU		{	BASE, DEBUG, ADDING };

u32		plgGetIoBase(u32 IoType);
Handle	getCurrentProcessHandle();
u32		getCurrentProcessId();
void	onCheatItemChanged(int id, int enable);

typedef struct	s_offset
{
	enum TYPE	type;
	int			addr;
}				t_offset;

typedef struct	s_spoil
{
	int			id;
	int			space;
	enum MENU	m;
}				t_spoil;

typedef struct	s_spoiler
{
	char		visibility;
	char		is_spoilable;
	int			id;
	int			parent_id;
	char		active;
}				t_spoiler;

typedef struct	s_menu
{
	int			count;
	char		status;
	char		state[64];
	char		freeze[64];
	void		(*f[64])();
	int			args[64];
	char		text[64][45];
	t_spoiler	spoiler[64];
	t_offset	*offset;
}				t_menu;

void switch_mode();

/*
**cheats.c
*/
void	unlock_dlc();
void	infinite_health();
void	infinite_AP();
void	refill_health();
void	refill_AP();
void	resonance_x999();
void	resonance_trigger();
void	no_cooldown();
void	freeze_time();
void	gils_max();
void	gils_add();
void	cp_max();
void	cp_add();
void	consumables_x99();
void	atma_magi_x99();
void	material_x50();
void	materials_x99();
void	material1_x99();
void	material2_x99();
void	material3_x99();
void	monster_1_health();
void	monster_2_health();
void	monster_3_health();
void	monster1_set_exp();
void	monster2_set_exp();
void	monster3_set_exp();
void	set_gils();
void	get_address();
void	reset();

/*
**menu.c
*/

void	create_base_menu();
void	create_adding_menu(char *item, int addr, enum TYPE type);
void	create_address_menu(char *item);
void	create_debug_menu();
void	create_reset_menu();

/*
**common_functions.c
*/

void	waitKeyUp();
void	waitKeyChange(int key);
int		read(int addr, enum TYPE type);
void	str_replace(char *str, char a, char b);
void	str_add_space(char *str, int n);


/*
**menu_display.c
*/

void	updateCheatEnableDisplay(int id);
void	updateAllCheatEnableDisplay();
void	addCheatMenuEntry(u8* str);
void	addSCheatMenuEntry(u8* str);
void	add_menu(enum MENU m, char *text, void(*f)());
void	add_nothing_menu(enum MENU m, char *text, void(*f)());
void	add_activate_menu(enum MENU m, char *text);
void	add_sharp_menu(enum MENU m, char *text, void(*f)());
void	add_space_menu(enum MENU m, char *text, void(*f)());
void	add_number_menu(enum MENU m, char *text, void(*f)());
void	add_separator_menu(enum MENU m);
void	add_line_menu(enum MENU m);
void	change_text(enum MENU m, int line, char	*text);
void	add_text(enum MENU m, int line, char	*text);

/*
**menu_functions.c
*/

void	initMenu();
void    initCheatMenu();
void	addMenuEntry(u8* str);
u32		updateMenu();
int		scanMenu();
void	scanCheatMenu();
void    disableCheat(int index);
void	init_menu();
void	activate_menu();
void	change_menu_status(enum MENU m);
void	show_menu(enum MENU m);
void	show_base();
void	show_debug();
void	do_action(t_menu *menu, int id);
void	do_all_action();
void	change_state(int id);
int		find_id(enum MENU me, char *name);
int		get_real_id(int id);

/*
** spoiler_display.c
*/

t_spoil	add_head_spoiler_menu(enum MENU m, char *text);
t_spoil	add_head_child_spoiler_menu(t_spoil parent, char *text);

void	add_child_spoiler_menu(t_spoil parent, char *text, void(*f)());
void	add_nothing_child_spoiler_menu(t_spoil parent, char *text, void(*f)());
void	add_activate_child_spoiler_menu(t_spoil parent, char *text);
void	add_sharp_child_spoiler_menu(t_spoil parent, char *text, void(*f)());
void	add_space_child_spoiler_menu(t_spoil parent, char *text, void(*f)());
void	add_number_child_spoiler_menu(t_spoil parent, char *text, void(*f)());
void	add_separator_child_spoiler_menu(t_spoil parent, char *text);
void	add_line_child_spoiler_menu(t_spoil parent);

/*
** spoilers_functions.c
*/
void	spoil(enum MENU m, int id);
void	un_spoil(enum MENU m, int id);
void	change_spoiler_state(enum MENU m, int id);
void	active_spoiler(int id);
void	show_only_spoiler(enum MENU m, int id);

int		get_next_id(enum MENU m);

#endif