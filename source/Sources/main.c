#include "global.h"
#include "configs.h"
#include "cheats.h"

Handle fsUserHandle;
FS_archive sdmcArchive = { 0x9, (FS_path) { PATH_EMPTY, 1, (u8*)"" } };
u32 threadStack[0x1000];
u32 IoBaseLcd;
u32 IoBasePad;
int isNewNtr;

void gamePluginEntry();

int	main()
{
	Handle		hThread;
	u32			ret;

	initSharedFunc();
	ret = svc_createThread(&hThread, gamePluginEntry, 0, &threadStack[0x1000], 0x3F, 0xFFFFFFFE);
}