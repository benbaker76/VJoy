#ifndef __DEBUG_H__
#define __DEBUG_H__

void DbgPrint(LPTSTR fmt, ...);

#define DBG	0

#if DBG
#define DebugPrint(_x_)     { DbgPrint _x_; }
#else
#define DebugPrint(_x_)
#endif

#endif
