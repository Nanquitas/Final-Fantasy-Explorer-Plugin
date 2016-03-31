#include "global.h"
#include "configs.h"
#include "cheats.h"

extern	enum language	langue;
extern	enum MENU		current_menu;
extern	t_menu			menu[8];
extern	u16				mode;
extern	unsigned int	after;

void	infinite_health()
{
	int pointer;
	
	if(READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2404);
		if ((READU32(pointer) == 0x006DDEEC))
		{
			WRITEU32(pointer + 0x88, 0x270F);
		}
	}
} 

void	infinite_AP()
{
	int pointer;
	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2404);
		if ((READU32(pointer) == 0x006DDEEC))
		{
			WRITEU32(pointer + 0x8C, 0x270F);
		}
	}
}

void	refill_health()
{
	int pointer;
	int key;

	if((key = getKey()) == BUTTON_L + BUTTON_DL)
	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2404);
		if ((READU32(pointer) == 0x006DDEEC))
		{
			WRITEU32(pointer + 0x88, 0x270F);
		}
	}
}

void	refill_AP()
{
	int pointer;
	int key;

	if ((key = getKey()) == BUTTON_L + BUTTON_DR)
	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2404);
		if ((READU32(pointer) == 0x006DDEEC))
		{
			WRITEU32(pointer + 0x8C, 0x270F);
		}
	}
}

void	no_cooldown()
{	
	if(READU32(0x004491E8) ==  0xED800A80)
	{
		rtCheckRemoteMemoryRegionSafeForWrite ( getCurrentProcessHandle(), 0x004491E8,  4 );
		WRITEU32(0x004491E8, 0xA0E10000);
	}		
}

void	freeze_time()
{
	if(READU32(0x0050D2E1) == 0x06ED800A)
	{
		rtCheckRemoteMemoryRegionSafeForWrite ( getCurrentProcessHandle(), 0x0050D2E1,  4 );
		WRITEU32(0x0050D2E1, 0x06E1A000);
	}		
}

void	resonance_x999()
{
	if(mode == 0)
		WRITEU32(0x0809D7A4, 0x47C34F80);
	else
		WRITEU32(0x08099CF4, 0x47C34F80);
}

void	resonance_trigger()
{
	int key;

	if ((key = getKey()) == BUTTON_L + BUTTON_DU)
		resonance_x999();
}

void	gils_max()
{
	int base_pointer = READU32(0x0072E168);
	if (base_pointer != 0x0)
	{
		WRITEU32(base_pointer + 0xFFFFFFBC, 0x98967F);
	}
}

void	unlock_dlc()
{
	int base_pointer = READU32(0x0072E168);
	if (base_pointer != 0x0)
	{
		WRITEU32(base_pointer + 0xFFFF2828, 0x01E0);
	}
}

void	gils_add()
{
	int base_pointer = READU32(0x0072E168);
	if (base_pointer != 0x0)
	{
		WRITEU32(base_pointer + 0xFFFFFFBC, READU32(base_pointer + 0xFFFFFFBC) + 0x2710);
	}
}

void	cp_max()
{
	int base_pointer = READU32(0x0072E168);
	if (base_pointer != 0x0)
	{
		WRITEU32(base_pointer + 0xFFFFFFC4, 0x98967F);
	}
}

void	cp_add()
{
	int base_pointer = READU32(0x0072E168);
	if (base_pointer != 0x0)
	{
		WRITEU32(base_pointer + 0xFFFFFFC4, READU32(base_pointer + 0xFFFFFFC4) + 0x3e8);
	}
}

void	consumables_x99()
{
	int base_pointer = READU32(0x0072E168);
	int pointer = base_pointer;
	if (base_pointer != 0x0)
	{
		pointer += 0xFFFF1CD8;
		int i = 0;
		for (i = 0; i < 29; i++)
		{
			WRITEU8(pointer, 0x63);
			pointer++;
		}
	}
}

void	atma_magi_x99()
{
	int base_pointer = READU32(0x0072E168);
	int pointer = base_pointer;
	if (base_pointer != 0x0)
	{
		pointer += 0xFFFFECC0;
		int i = 0;
		for (i = 0; i < 55; i++)
		{
			WRITEU8(pointer, 0x63);
			pointer++;
		}
	}
}

void	material_x50()
{
	static int i = 0;
	
	int base_pointer = READU32(0x0072E168);
	int pointer = base_pointer;
	if (base_pointer != 0x0)
	{
		pointer += 0xFFFFEB30;
		WRITEU8(pointer + i, 0x32);
		i++;
	}
	if (i == 311)
		i = 0;
}

void	materials_x99()
{
	material1_x99();
	material2_x99();
	material3_x99();
}

void	material1_x99()
{
	int base_pointer = READU32(0x0072E168);
	int pointer = base_pointer;
	if (base_pointer != 0x0)
	{
		pointer += 0xFFFFEB30;
		int i = 0;
		for (i = 0; i < 97; i++)
		{
			WRITEU8(pointer, 0x63);
			pointer++;
		}
	}
}

void	material2_x99()
{
	int base_pointer = READU32(0x0072E168);
	int pointer = base_pointer;
	if (base_pointer != 0x0)
	{
		pointer += 0xFFFFEB93;
		int i = 0;
		for (i = 0; i < 201; i++)
		{
			WRITEU8(pointer, 0x63);
			pointer++;
		}
	}
}

void	material3_x99()
{
	int base_pointer = READU32(0x0072E168);
	int pointer = base_pointer;
	if (base_pointer != 0x0)
	{
		pointer += 0xFFFFEC7A;
		int i = 0;
		for (i = 0; i < 12; i++)
		{
			WRITEU8(pointer, 0x63);
			pointer++;
		}
	}
}


void	monster_1_health()
{
	int			pointer;
	static int	p = 0;

	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2424);
		if(p == 0)
			p = pointer;
		else
		{
			if (p != pointer)
			{
				disableCheat(find_id(BASE, "Monster #1 Infinite HP (R + Left)"));
				p = 0;
				return;
			}
		}
		if (pointer == 0)
		{
			disableCheat(find_id(BASE, "Monster #1 Infinite HP (R + Left)"));
			return;
		}
		if (READU32(pointer) == 0x006DEA60)
		{
			WRITEU32(pointer + 0x88, 0x1869F);
		}
		else
			disableCheat(find_id(BASE, "Monster #1 Infinite HP (R + Left)"));
	}
	else
		disableCheat(find_id(BASE, "Monster #1 Infinite HP (R + Left)"));

}

void	monster_2_health()
{
	int pointer;
	static int	p = 0;

	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D242C);
		if (p == 0)
			p = pointer;
		else
		{
			if (p != pointer)
			{
				disableCheat(find_id(BASE, "Monster #2 Infinite HP (R + Right)"));
				p = 0;
				return;
			}
		}
		if (pointer == 0)
		{
			disableCheat(find_id(BASE, "Monster #2 Infinite HP (R + Right)"));
			return;
		}
		if (READU32(pointer) == 0x006DEA60)
		{
			WRITEU32(pointer + 0x88, 0x1869F);
		}
		else
			disableCheat(find_id(BASE, "Monster #2 Infinite HP (R + Right)"));
	}
	else
		disableCheat(find_id(BASE, "Monster #2 Infinite HP (R + Right)"));
}

void	monster_3_health()
{
	int pointer;
	static int	p = 0;

	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2434);
		if (p == 0)
			p = pointer;
		else
		{
			if (p != pointer)
			{
				disableCheat(find_id(BASE, "Monster #3 Infinite HP (R + Down)"));
				p = 0;
				return;
			}
		}
		if (pointer == 0)
		{
			disableCheat(find_id(BASE, "Monster #3 Infinite HP (R + Down)"));
			return;
		}
		if (READU32(pointer) == 0x006DEA60)
		{
			WRITEU32(pointer + 0x88, 0x1869F);
		}
		else
			disableCheat(find_id(BASE, "Monster #3 Infinite HP (R + Down)"));
	}
	else
		disableCheat(find_id(BASE, "Monster #3 Infinite HP (R + Down)"));
}


void	monster1_set_exp()
{
	int pointer;

	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2424);
		if (READU32(pointer) == 0x006DEA60)
		{
			create_adding_menu("Monster #1 Exp.", pointer + 0x5268, T32);
			show_menu(ADDING);
		}
	}
}

void	monster2_set_exp()
{
	int pointer;

	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D242C);
		if (READU32(pointer) == 0x006DEA60)
		{
			create_adding_menu("Monster #2 Exp.", pointer + 0x5268, T32);
			show_menu(ADDING);
		}
	}
}

void	monster3_set_exp()
{
	int pointer;

	if (READU32(0x080D2404) != 0x0)
	{
		pointer = READU32(0x080D2434);
		if (READU32(pointer) == 0x006DEA60)
		{
			create_adding_menu("Monster #3 Exp.", pointer + 0x5268, T32);
			show_menu(ADDING);
		}
	}
}

void	get_address()
{
	int		pointer;
	char	buf[40];

	pointer = READU32(0x080D2424);
	create_address_menu("Get Monsters Adress");
	xsprintf(buf, "Monster #1 0x%08x", pointer);
	add_nothing_menu(ADDING, buf, NULL);
	memset(buf, '\0', 40);
	pointer = READU32(0x080D242C);
	xsprintf(buf, "Monster #2 0x%08x", pointer);
	add_nothing_menu(ADDING, buf, NULL);
	memset(buf, '\0', 40);
	pointer = READU32(0x080D2434);
	xsprintf(buf, "Monster #3 0x%08x", pointer);
	add_nothing_menu(ADDING, buf, NULL);
	show_menu(ADDING);
	menu[ADDING].status = 1;
}

void	set_gils()
{
	unsigned int	current;
	char	buf[40];
	
	int base_pointer = READU32(0x0072E168);

	if (base_pointer != 0x0)
	{
		current = READU32(base_pointer + 0xFFFFFFBC);
	}
	create_adding_menu("Gils", base_pointer + 0xFFFFFFBC, T32);
	show_menu(ADDING);
}

void	reset()
{
	int base_pointer = READU32(0x0072E168);
	int pointer = base_pointer;
	int i = 0;

	if (base_pointer != 0x0)
	{
		WRITEU32(base_pointer + 0xFFFFFFBC, 0x00000000);
		WRITEU32(base_pointer + 0xFFFFFFC4, 0x00000000);
		pointer += 0xFFFF1CD8;
		for (i = 0; i < 29; i++)
		{
			WRITEU8(pointer, 0x00);
			pointer++;
		}
		pointer = base_pointer;
		pointer += 0xFFFFECC0;
		for (i = 0; i < 55; i++)
		{
			WRITEU8(pointer, 0x00);
			pointer++;
		}
		pointer = base_pointer;
		pointer += 0xFFFFEB30;
		for (i = 0; i < 312; i++)
		{
			WRITEU8(pointer, 0x00);
			pointer++;
		}
	}
	show_base();
}