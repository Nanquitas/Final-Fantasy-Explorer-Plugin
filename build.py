#!/usr/bin/python
import sys
import os
import ftplib
import glob


def allFile(pattern):
    s = "";
    for file in glob.glob(pattern):
        s += file + " ";
    return s;

def allFolderFile(pattern, ext):
	s = "";
	for dirpath, dirnames, filenames in os.walk(pattern):
		for filename in [f for f in filenames if f.endswith(ext)]:
			s+= os.path.join(dirpath, filename) + ' '
	return s;

	
NAME = 'FFEXP'
COPYTOPATH = NAME + '.plg'

CC 			= "arm-none-eabi-gcc"
CP 			= "arm-none-eabi-g++"
OC			= "arm-none-eabi-objcopy" 
LD 			= "arm-none-eabi-ld"
CTRULIB 	= '../libctru'
DEVKITARM 	= 'c:/devkitPro/devkitARM'
LIBPATH 	= '-L ./lib '

ARCH 		= ' -march=armv6 -mlittle-endian '
CFLAGS		= ' -Os -g -c ' + ARCH
ASFLAGS		= ' -Os -c -s ' + ARCH
LIBFLAGS 	= " -lc -lgcc --nostdlib "
LDFLAGS		= ' -pie --print-gc-sections -T 3ds.ld -Map=' + NAME +'.map '

INCLUDES 	= " -I include -I source -I include/libntrplg "
CFILES		= allFolderFile(".\\source\\", ".c")
ASFILES		= allFolderFile(".\\source\\", ".s")





def run(cmd):
	#print(cmd);
	os.system(cmd)

cwd = os.getcwd() 
run("rm obj/*.o")
run("rm bin/*.elf")
print("Compiling C files");
print(CC +  CFLAGS + INCLUDES + CFILES);
run(CC +  CFLAGS + INCLUDES + CFILES);
print("")

print("Compiling S files");
print(CC + ASFLAGS + ASFILES);
run(CC + ASFLAGS + ASFILES);
print("")

OFILES = allFile("*.o") + " " + allFile("lib/*.o")
print("Compiling " + COPYTOPATH);
print(LD + LDFLAGS + ' ' + LIBPATH  + OFILES + LIBFLAGS )
run(LD + LDFLAGS + ' ' + LIBPATH  + OFILES + LIBFLAGS )
print("")

run("cp -r *.o obj/ ")
run("cp a.out bin/homebrew.elf ")
run(OC+" -O binary a.out payload.bin -S")
run("rm *.o")
run("rm *.out")
run('copy payload.bin ' + COPYTOPATH);
