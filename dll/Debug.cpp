#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Debug.h"

void DbgPrint(LPTSTR fmt, ...)
{
	va_list marker;
	TCHAR szBuf[512];

	va_start(marker, fmt);
	vsprintf(szBuf, fmt, marker);
	va_end(marker);

	OutputDebugString(szBuf);
}
