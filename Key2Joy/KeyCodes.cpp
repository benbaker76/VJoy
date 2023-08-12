#include "stdafx.h"
#include "KeyCodes.h"

#define ARRAY_LENGTH(x)		(sizeof(x) / sizeof(x[0]))

const KeyCode key_codes[KEY_CODES_COUNT] =
{
	// name				code name			dinput key			virtual key		ascii
	{ "None",			"",					0,					0,	 			0 },
	{ "Escape",			"KEY_ESC",			DIK_ESCAPE,			VK_ESCAPE,	 	27 },
	{ "1",				"KEY_1",			DIK_1,				'1',			'1' },
	{ "2",				"KEY_2",			DIK_2,				'2',			'2' },
	{ "3",				"KEY_3",			DIK_3,				'3',			'3' },
	{ "4",				"KEY_4",			DIK_4,				'4',			'4' },
	{ "5",				"KEY_5",			DIK_5,				'5',			'5' },
	{ "6",				"KEY_6",			DIK_6,				'6',			'6' },
	{ "7",				"KEY_7",			DIK_7,				'7',			'7' },
	{ "8",				"KEY_8",			DIK_8,				'8',			'8' },
	{ "9",				"KEY_9",			DIK_9,				'9',			'9' },
	{ "0",				"KEY_0",			DIK_0,				'0',			'0' },
	{ "-",				"KEY_MINUS",		DIK_MINUS, 			VK_OEM_MINUS,	'-' },
	{ "=",				"KEY_EQUALS",		DIK_EQUALS,		 	VK_OEM_PLUS,	'=' },
	{ "Backspace",		"KEY_BACKSPACE",	DIK_BACK, 			VK_BACK, 		8 },
	{ "Tab",			"KEY_TAB",			DIK_TAB, 			VK_TAB, 		9 },
	{ "Q",				"KEY_Q",			DIK_Q,				'Q',			'Q' },
	{ "W",				"KEY_W",			DIK_W,				'W',			'W' },
	{ "E",				"KEY_E",			DIK_E,				'E',			'E' },
	{ "R",				"KEY_R",			DIK_R,				'R',			'R' },
	{ "T",				"KEY_T",			DIK_T,				'T',			'T' },
	{ "Y",				"KEY_Y",			DIK_Y,				'Y',			'Y' },
	{ "U",				"KEY_U",			DIK_U,				'U',			'U' },
	{ "I",				"KEY_I",			DIK_I,				'I',			'I' },
	{ "O",				"KEY_O",			DIK_O,				'O',			'O' },
	{ "P",				"KEY_P",			DIK_P,				'P',			'P' },
	{ "[",				"KEY_OPENBRACE",	DIK_LBRACKET, 		VK_OEM_4,		'[' },
	{ "]",				"KEY_CLOSEBRACE",	DIK_RBRACKET, 		VK_OEM_6,		']' },
	{ "Enter",			"KEY_ENTER",		DIK_RETURN, 		VK_RETURN, 		13 },
	{ "Left Ctrl",		"KEY_LCONTROL",		DIK_LCONTROL, 		VK_LCONTROL, 	0 },
	{ "A",				"KEY_A",			DIK_A,				'A',			'A' },
	{ "S",				"KEY_S",			DIK_S,				'S',			'S' },
	{ "D",				"KEY_D",			DIK_D,				'D',			'D' },
	{ "F",				"KEY_F",			DIK_F,				'F',			'F' },
	{ "G",				"KEY_G",			DIK_G,				'G',			'G' },
	{ "H",				"KEY_H",			DIK_H,				'H',			'H' },
	{ "J",				"KEY_J",			DIK_J,				'J',			'J' },
	{ "K",				"KEY_K",			DIK_K,				'K',			'K' },
	{ "L",				"KEY_L",			DIK_L,				'L',			'L' },
	{ ";",				"KEY_COLON",		DIK_SEMICOLON,		VK_OEM_1,		';' },
	{ "'",				"KEY_QUOTE",		DIK_APOSTROPHE,		VK_OEM_7,		'\'' },
	{ "`",				"KEY_TILDE",		DIK_GRAVE, 			VK_OEM_3,		'`' },
	{ "Left Shift",		"KEY_LSHIFT",		DIK_LSHIFT, 		VK_LSHIFT, 		0 },
	{ "\\",				"KEY_BACKSLASH",	DIK_BACKSLASH, 		VK_OEM_5,		'\\' },
	{ "Z",				"KEY_Z",			DIK_Z,				'Z',			'Z' },
	{ "X",				"KEY_X",			DIK_X,				'X',			'X' },
	{ "C",				"KEY_C",			DIK_C,				'C',			'C' },
	{ "V",				"KEY_V",			DIK_V,				'V',			'V' },
	{ "B",				"KEY_B",			DIK_B,				'B',			'B' },
	{ "N",				"KEY_N",			DIK_N,				'N',			'N' },
	{ "M",				"KEY_M",			DIK_M,				'M',			'M' },
	{ ",",				"KEY_COMMA",		DIK_COMMA,			VK_OEM_COMMA,	',' },
	{ ".",				"KEY_STOP",			DIK_PERIOD, 		VK_OEM_PERIOD,	'.' },
	{ "/",				"KEY_SLASH",		DIK_SLASH, 			VK_OEM_2,		'/' },
	{ "Right Shift",	"KEY_RSHIFT",		DIK_RSHIFT, 		VK_RSHIFT, 		0 },
	{ "*",				"KEY_ASTERISK",		DIK_MULTIPLY, 		VK_MULTIPLY,	'*' },
	{ "Left Alt",		"KEY_LALT",			DIK_LMENU, 			VK_LMENU, 		0 },
	{ "Spacebar",		"KEY_SPACE",		DIK_SPACE, 			VK_SPACE,		' ' },
	{ "Caps Lock",		"KEY_CAPSLOCK",		DIK_CAPITAL, 		VK_CAPITAL, 	0 },
	{ "F1",				"KEY_F1",			DIK_F1,				VK_F1, 			0 },
	{ "F2",				"KEY_F2",			DIK_F2,				VK_F2, 			0 },
	{ "F3",				"KEY_F3",			DIK_F3,				VK_F3, 			0 },
	{ "F4",				"KEY_F4",			DIK_F4,				VK_F4, 			0 },
	{ "F5",				"KEY_F5",			DIK_F5,				VK_F5, 			0 },
	{ "F6",				"KEY_F6",			DIK_F6,				VK_F6, 			0 },
	{ "F7",				"KEY_F7",			DIK_F7,				VK_F7, 			0 },
	{ "F8",				"KEY_F8",			DIK_F8,				VK_F8, 			0 },
	{ "F9",				"KEY_F9",			DIK_F9,				VK_F9, 			0 },
	{ "F10",			"KEY_F10",			DIK_F10,			VK_F10, 		0 },
	{ "Num Lock",		"KEY_NUMLOCK",		DIK_NUMLOCK,		VK_NUMLOCK, 	0 },
	{ "Scroll Lock",	"KEY_SCRLOCK",		DIK_SCROLL,			VK_SCROLL, 		0 },
	{ "Numpad 7",		"KEY_7PAD",			DIK_NUMPAD7,		VK_NUMPAD7, 	0 },
	{ "Numpad 8",		"KEY_8PAD",			DIK_NUMPAD8,		VK_NUMPAD8, 	0 },
	{ "Numpad 9",		"KEY_9PAD",			DIK_NUMPAD9,		VK_NUMPAD9, 	0 },
	{ "Numpad -",		"KEY_MINUSPAD",		DIK_SUBTRACT,		VK_SUBTRACT, 	0 },
	{ "Numpad 4",		"KEY_4PAD",			DIK_NUMPAD4,		VK_NUMPAD4, 	0 },
	{ "Numpad 5",		"KEY_5PAD",			DIK_NUMPAD5,		VK_NUMPAD5, 	0 },
	{ "Numpad 6",		"KEY_6PAD",			DIK_NUMPAD6,		VK_NUMPAD6, 	0 },
	{ "Numpad +",		"KEY_PLUSPAD",		DIK_ADD,			VK_ADD, 		0 },
	{ "Numpad 1",		"KEY_1PAD",			DIK_NUMPAD1,		VK_NUMPAD1, 	0 },
	{ "Numpad 2",		"KEY_2PAD",			DIK_NUMPAD2,		VK_NUMPAD2, 	0 },
	{ "Numpad 3",		"KEY_3PAD",			DIK_NUMPAD3,		VK_NUMPAD3, 	0 },
	{ "Numpad 0",		"KEY_0PAD",			DIK_NUMPAD0,		VK_NUMPAD0, 	0 },
	{ "Numpad .",		"KEY_DELPAD",		DIK_DECIMAL,		VK_DECIMAL, 	0 },
	{ "F11",			"KEY_F11",			DIK_F11,			VK_F11, 		0 },
	{ "F12",			"KEY_F12",			DIK_F12,			VK_F12, 		0 },
	{ "F13",			"KEY_F13",			DIK_F13,			VK_F13, 		0 },
	{ "F14",			"KEY_F14",			DIK_F14,			VK_F14, 		0 },
	{ "F15",			"KEY_F15",			DIK_F15,			VK_F15, 		0 },
	{ "Numpad Enter",	"KEY_ENTERPAD",		DIK_NUMPADENTER,	VK_RETURN, 		0 },
	{ "Right Ctrl",		"KEY_RCONTROL",		DIK_RCONTROL,		VK_RCONTROL, 	0 },
	{ "Numpad /",		"KEY_SLASHPAD",		DIK_DIVIDE,			VK_DIVIDE, 		0 },
	{ "PrtScrn/SysRq",	"KEY_PRTSCR",		DIK_SYSRQ, 			0, 				0 },
	{ "Right Alt",		"KEY_RALT",			DIK_RMENU,			VK_RMENU, 		0 },
	{ "Home",			"KEY_HOME",			DIK_HOME,			VK_HOME, 		0 },
	{ "Up",				"KEY_UP",			DIK_UP,				VK_UP, 			0 },
	{ "PgUp",			"KEY_PGUP",			DIK_PRIOR,			VK_PRIOR, 		0 },
	{ "Left",			"KEY_LEFT",			DIK_LEFT,			VK_LEFT, 		0 },
	{ "Right",			"KEY_RIGHT",		DIK_RIGHT,			VK_RIGHT, 		0 },
	{ "End",			"KEY_END",			DIK_END,			VK_END, 		0 },
	{ "Down",			"KEY_DOWN",			DIK_DOWN,			VK_DOWN, 		0 },
	{ "PgDn",			"KEY_PGDN",			DIK_NEXT,			VK_NEXT, 		0 },
	{ "Insert",			"KEY_INSERT",		DIK_INSERT,			VK_INSERT, 		0 },
	{ "Delete",			"KEY_DEL",			DIK_DELETE,			VK_DELETE, 		0 },
	{ "Left Windows",	"KEY_LWIN",			DIK_LWIN,			VK_LWIN, 		0 },
	{ "Right Windows",	"KEY_RWIN",			DIK_RWIN,			VK_RWIN, 		0 },
	{ "AppMenu",		"KEY_MENU",			DIK_APPS,			VK_APPS, 		0 },
	{ "Pause/Break",	"KEY_PAUSE",		DIK_PAUSE,			VK_PAUSE,		0 },
	{ "Cancel",			"KEY_CANCEL",		0,					VK_CANCEL,		0 },

	// New keys introduced in Windows 2000. These have no MAME codes to
	// preserve compatibility with old config files that may refer to them
	// as e.g. FORWARD instead of e.g. KEY_WEBFORWARD. They need table
	// entries anyway because otherwise they aren't recognized when
	// GetAsyncKeyState polling is used (as happens currently when MAME is
	// paused). Some codes are missing because the mapping to vkey codes
	// isn't clear, and MapVirtualKey is no help.

	{ "Mute",			"KEY_MUTE",			DIK_MUTE,			VK_VOLUME_MUTE,			0 },
	{ "Volume Down",	"KEY_VOLUMEDOWN",	DIK_VOLUMEDOWN,		VK_VOLUME_DOWN,			0 },
	{ "Volume Up",		"KEY_VOLUMEUP",		DIK_VOLUMEUP,		VK_VOLUME_UP,			0 },
	{ "Web Home",		"KEY_WEBHOME",		DIK_WEBHOME,		VK_BROWSER_HOME,		0 },
	{ "Web Search",		"KEY_WEBSEARCH",	DIK_WEBSEARCH,		VK_BROWSER_SEARCH,		0 },
	{ "Web Favorites",	"KEY_WEBFAVORITES",	DIK_WEBFAVORITES,	VK_BROWSER_FAVORITES,	0 },
	{ "Web Refresh",	"KEY_WEBREFRESH",	DIK_WEBREFRESH,		VK_BROWSER_REFRESH,		0 },
	{ "Web Stop",		"KEY_WEBSTOP",		DIK_WEBSTOP,		VK_BROWSER_STOP,		0 },
	{ "Web Forward",	"KEY_WEBFORWARD",	DIK_WEBFORWARD,		VK_BROWSER_FORWARD,		0 },
	{ "Web Back",		"KEY_WEBBACK",		DIK_WEBBACK,		VK_BROWSER_BACK,		0 },
	{ "Mail",			"KEY_MAIL",			DIK_MAIL,			VK_LAUNCH_MAIL,			0 },
	{ "Media Select",	"KEY_MEDIASELECT",	DIK_MEDIASELECT,	VK_LAUNCH_MEDIA_SELECT,	0 },
};

int VK2DIK(int vk)
{
	for (int i = 0; i < ARRAY_LENGTH(key_codes); i++)
		if (key_codes[i].VKCode == vk)
			return key_codes[i].DIKCode;

	return 0;
}

PCHAR VK2Name(int vk)
{
	for (int i = 0; i < ARRAY_LENGTH(key_codes); i++)
		if (key_codes[i].VKCode == vk)
			return key_codes[i].Name;

	return NULL;
}

PCHAR VK2NameCode(int vk)
{
	for (int i = 0; i < ARRAY_LENGTH(key_codes); i++)
		if (key_codes[i].VKCode == vk)
			return key_codes[i].NameCode;

	return NULL;
}

int DIK2VK(int dik)
{
	for (int i = 0; i < ARRAY_LENGTH(key_codes); i++)
		if (key_codes[i].DIKCode == dik)
			return key_codes[i].VKCode;

	return 0;
}

int NameCode2VK(PCHAR name)
{
	for (int i = 0; i < ARRAY_LENGTH(key_codes); i++)
		if (stricmp(key_codes[i].NameCode, name) == 0)
			return key_codes[i].VKCode;

	return 0;
}

int NameCode2DIK(PCHAR name)
{
	for (int i = 0; i < ARRAY_LENGTH(key_codes); i++)
		if (stricmp(key_codes[i].NameCode, name) == 0)
			return key_codes[i].DIKCode;

	return 0;
}
