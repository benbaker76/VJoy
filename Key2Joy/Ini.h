BOOL IniOptionGetBool(PCHAR fileName, PCHAR buffer, PCHAR section, PCHAR key, BOOL defaultValue);
BOOL IniOptionSet(PCHAR fileName, PCHAR buffer, PCHAR section, PCHAR key, PCHAR value);
VOID ReadKeyToJoy(PCHAR szPath, PCHAR buf);
VOID WriteKeyToJoy(PCHAR szPath);
