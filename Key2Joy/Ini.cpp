#include "stdafx.h"
#include <stdio.h>
#include "Globals.h"
#include "KeyCodes.h"
#include "JoyCodes.h"

#define ARRAY_LENGTH(x)		(sizeof(x) / sizeof(x[0]))

BOOL IniOptionGetBool(PCHAR fileName, PCHAR buffer, PCHAR section, PCHAR key, BOOL defaultValue)
{
	if(GetPrivateProfileString(section, key, "", buffer, MAX_PATH, fileName) != 0)
		return (_stricmp(buffer, "true") == 0);

	return defaultValue;
}

BOOL IniOptionGet(PCHAR fileName, PCHAR buffer, PCHAR section, PCHAR key, PCHAR value)
{
	if(GetPrivateProfileString(section, key, "", buffer, MAX_PATH, fileName) != 0)
		if(value == NULL || _stricmp(buffer, value) == 0)
			return TRUE;

	return FALSE;
}

BOOL IniOptionSet(PCHAR fileName, PCHAR section, PCHAR key, PCHAR value)
{
	if(WritePrivateProfileString(section, key, value, fileName) != 0)
		return TRUE;

	return FALSE;
}

VOID ReadKeyToJoy(PCHAR szPath, PCHAR buf)
{
	g_LaunchOnStartup = IniOptionGetBool(szPath, buf, "General", "LaunchOnStartup", false);
	g_KeyToJoyEnabled = IniOptionGetBool(szPath, buf, "KeyToJoy", "Enabled", false);
	g_KeyToJoyBlockKeys = IniOptionGetBool(szPath, buf, "KeyToJoy", "BlockKeys", false);
	g_KeyToJoyAutoCenter = IniOptionGetBool(szPath, buf, "KeyToJoy", "AutoCenter", true);
	
	memset(g_KeyToJoyCode, 0, sizeof(g_KeyToJoyCode));

	for(int j = 0; j < JOY_COUNT; j++)
	{
		CHAR joyName[256];

		for (int i = 0; i < ARRAY_LENGTH(multi_joy_codes); i++)
		{
			sprintf_s(joyName, multi_joy_codes[i], j + 1);

			if(IniOptionGet(szPath, buf, "KeyToJoy", joyName, NULL))
				g_KeyToJoyCode[j][i] = NameCode2VK(buf);
		}
	}
}

VOID WriteKeyToJoy(PCHAR szPath)
{
	IniOptionSet(szPath, "General", "LaunchOnStartup", g_LaunchOnStartup ? "True" : "False");
	IniOptionSet(szPath, "KeyToJoy", "Enabled", g_KeyToJoyEnabled ? "True" : "False");
	IniOptionSet(szPath, "KeyToJoy", "BlockKeys", g_KeyToJoyBlockKeys ? "True" : "False");
	IniOptionSet(szPath, "KeyToJoy", "AutoCenter", g_KeyToJoyAutoCenter ? "True" : "False");

	for(int j = 0; j < JOY_COUNT; j++)
	{
		CHAR joyName[256];

		for (int i = 0; i < ARRAY_LENGTH(multi_joy_codes); i++)
		{
			sprintf_s(joyName, multi_joy_codes[i], j + 1);

			IniOptionSet(szPath, "KeyToJoy", joyName, VK2NameCode(g_KeyToJoyCode[j][i]));
		}
	}
}
