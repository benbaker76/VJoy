#define DIRECTINPUT_VERSION 0x0700

#include "StdAfx.h"
#include <dinput.h>

struct KeyCode
{
	PCHAR Name;
	PCHAR NameCode;
	int DIKCode;
	int VKCode;
	int ASCIICode;
};

#define KEY_CODES_COUNT		121

extern const KeyCode key_codes[KEY_CODES_COUNT];

int VK2DIK(int vk);
PCHAR VK2Name(int vk);
PCHAR VK2NameCode(int vk);
int DIK2VK(int dik);
int NameCode2VK(PCHAR name);
int NameCode2DIK(PCHAR name);
int NameCode2Joy(PCHAR name);
