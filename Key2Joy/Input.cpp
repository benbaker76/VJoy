#include "stdafx.h"
#include <stdio.h>
#include "Input.h"
#include "Globals.h"
#include "JoyCodes.h"

void ProcessKeyToJoy(PKEYEVENTARGS e)
{
	for(int j = 0; j < JOY_COUNT; j++)
	{
		USHORT POV = g_KeyToJoyState[j].POV;
		UCHAR POV3 = (POV & 0xF), POV2 = ((POV >> 4) & 0xF), POV1 = ((POV >> 8) & 0xF), POV0 = ((POV >> 12) & 0xF);

		if(g_KeyToJoyAutoCenter)
		{
			POV0 = POV_NIL;
			POV1 = POV_NIL;
			POV2 = POV_NIL;
			POV3 = POV_NIL;
			g_KeyToJoyState[j].XAxis = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].YAxis = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].ZAxis = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].XRotation = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].YRotation = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].ZRotation = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].Slider = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].Dial = VJOY_AXIS_NIL;
		}

		if(e->Keys[g_KeyToJoyCode[j][JOY_LEFT]])			g_KeyToJoyState[j].XAxis =  VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_RIGHT]])			g_KeyToJoyState[j].XAxis = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_UP]])				g_KeyToJoyState[j].YAxis = VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_DOWN]])			g_KeyToJoyState[j].YAxis = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_ZAXIS_NEG]])		g_KeyToJoyState[j].ZAxis = VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_ZAXIS_POS]])		g_KeyToJoyState[j].ZAxis = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_XROTATE_NEG]])		g_KeyToJoyState[j].XRotation = VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_XROTATE_POS]])		g_KeyToJoyState[j].XRotation = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_YROTATE_NEG]])		g_KeyToJoyState[j].YRotation = VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_YROTATE_POS]])		g_KeyToJoyState[j].YRotation = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_ZROTATE_NEG]])		g_KeyToJoyState[j].ZRotation = VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_ZROTATE_POS]])		g_KeyToJoyState[j].ZRotation = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_SLIDER_NEG]])		g_KeyToJoyState[j].Slider = VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_SLIDER_POS]])		g_KeyToJoyState[j].Slider = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_DIAL_NEG]])		g_KeyToJoyState[j].Dial = VJOY_AXIS_MIN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_DIAL_POS]])		g_KeyToJoyState[j].Dial = VJOY_AXIS_MAX;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV0_LEFT]])		POV0 = POV_LEFT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV0_RIGHT]])		POV0 = POV_RIGHT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV0_UP]])			POV0 = POV_UP;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV0_DOWN]])		POV0 = POV_DOWN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV1_LEFT]])		POV1 = POV_LEFT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV1_RIGHT]])		POV1 = POV_RIGHT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV1_UP]])			POV1 = POV_UP;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV1_DOWN]])		POV1 = POV_DOWN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV2_LEFT]])		POV2 = POV_LEFT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV2_RIGHT]])		POV2 = POV_RIGHT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV2_UP]])			POV2 = POV_UP;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV2_DOWN]])		POV2 = POV_DOWN;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV3_LEFT]])		POV3 = POV_LEFT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV3_RIGHT]])		POV3 = POV_RIGHT;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV3_UP]])			POV3 = POV_UP;
		if(e->Keys[g_KeyToJoyCode[j][JOY_POV3_DOWN]])		POV3 = POV_DOWN;

		g_KeyToJoyState[j].POV = POV3 | (POV2 << 4) | (POV1 << 8) | (POV0 << 12);

		for(int i = 0; i < JOY_BUTTON_COUNT; i++)
		{
			if(e->Keys[g_KeyToJoyCode[j][JOY_BUTTON1 + i]])
				g_KeyToJoyState[j].Buttons |= (1 << i);
			else
				g_KeyToJoyState[j].Buttons &= ~(1 << i);
		}

		g_VJoy.UpdateJoyState(j, &g_KeyToJoyState[j]);
	}

	if(g_KeyToJoyBlockKeys)
	{
		for(int j = 0; j < JOY_COUNT; j++)
		{
			for(int i = 0; i < JOY_INPUT_COUNT; i++)
				if(g_KeyToJoyCode[j][i] == e->Key)
					e->Handled = TRUE;
		}
	}
}

void ProcessKeyToJoy()
{
	bool keys[256];

	for(int i=0; i<256; i++)
		if(GetAsyncKeyState(i) & 0x8000)
			keys[i] = TRUE;
		else
			keys[i] = FALSE;

	for(int j = 0; j < JOY_COUNT; j++)
	{
		USHORT POV = g_KeyToJoyState[j].POV;
		UCHAR POV3 = (POV & 0xF), POV2 = ((POV >> 4) & 0xF), POV1 = ((POV >> 8) & 0xF), POV0 = ((POV >> 12) & 0xF);

		if(g_KeyToJoyAutoCenter)
		{
			POV0 = POV_NIL;
			POV1 = POV_NIL;
			POV2 = POV_NIL;
			POV3 = POV_NIL;
			g_KeyToJoyState[j].XAxis = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].YAxis = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].ZAxis = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].XRotation = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].YRotation = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].ZRotation = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].Slider = VJOY_AXIS_NIL;
			g_KeyToJoyState[j].Dial = VJOY_AXIS_NIL;
		}

		if(keys[g_KeyToJoyCode[j][JOY_LEFT]])			g_KeyToJoyState[j].XAxis =  VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_RIGHT]])			g_KeyToJoyState[j].XAxis = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_UP]])				g_KeyToJoyState[j].YAxis = VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_DOWN]])			g_KeyToJoyState[j].YAxis = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_ZAXIS_NEG]])		g_KeyToJoyState[j].ZAxis = VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_ZAXIS_POS]])		g_KeyToJoyState[j].ZAxis = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_XROTATE_NEG]])	g_KeyToJoyState[j].XRotation = VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_XROTATE_POS]])	g_KeyToJoyState[j].XRotation = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_YROTATE_NEG]])	g_KeyToJoyState[j].YRotation = VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_YROTATE_POS]])	g_KeyToJoyState[j].YRotation = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_ZROTATE_NEG]])	g_KeyToJoyState[j].ZRotation = VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_ZROTATE_POS]])	g_KeyToJoyState[j].ZRotation = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_SLIDER_NEG]])		g_KeyToJoyState[j].Slider = VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_SLIDER_POS]])		g_KeyToJoyState[j].Slider = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_DIAL_NEG]])		g_KeyToJoyState[j].Dial = VJOY_AXIS_MIN;
		if(keys[g_KeyToJoyCode[j][JOY_DIAL_POS]])		g_KeyToJoyState[j].Dial = VJOY_AXIS_MAX;
		if(keys[g_KeyToJoyCode[j][JOY_POV0_LEFT]])		POV0 = POV_LEFT;
		if(keys[g_KeyToJoyCode[j][JOY_POV0_RIGHT]])		POV0 = POV_RIGHT;
		if(keys[g_KeyToJoyCode[j][JOY_POV0_UP]])		POV0 = POV_UP;
		if(keys[g_KeyToJoyCode[j][JOY_POV0_DOWN]])		POV0 = POV_DOWN;
		if(keys[g_KeyToJoyCode[j][JOY_POV1_LEFT]])		POV1 = POV_LEFT;
		if(keys[g_KeyToJoyCode[j][JOY_POV1_RIGHT]])		POV1 = POV_RIGHT;
		if(keys[g_KeyToJoyCode[j][JOY_POV1_UP]])		POV1 = POV_UP;
		if(keys[g_KeyToJoyCode[j][JOY_POV1_DOWN]])		POV1 = POV_DOWN;
		if(keys[g_KeyToJoyCode[j][JOY_POV2_LEFT]])		POV2 = POV_LEFT;
		if(keys[g_KeyToJoyCode[j][JOY_POV2_RIGHT]])		POV2 = POV_RIGHT;
		if(keys[g_KeyToJoyCode[j][JOY_POV2_UP]])		POV2 = POV_UP;
		if(keys[g_KeyToJoyCode[j][JOY_POV2_DOWN]])		POV2 = POV_DOWN;
		if(keys[g_KeyToJoyCode[j][JOY_POV3_LEFT]])		POV3 = POV_LEFT;
		if(keys[g_KeyToJoyCode[j][JOY_POV3_RIGHT]])		POV3 = POV_RIGHT;
		if(keys[g_KeyToJoyCode[j][JOY_POV3_UP]])		POV3 = POV_UP;
		if(keys[g_KeyToJoyCode[j][JOY_POV3_DOWN]])		POV3 = POV_DOWN;


		g_KeyToJoyState[j].POV = POV3 | (POV2 << 4) | (POV1 << 8) | (POV0 << 12);

		for(int i = 0; i < JOY_BUTTON_COUNT; i++)
		{
			if(keys[g_KeyToJoyCode[j][JOY_BUTTON1 + i]])
				g_KeyToJoyState[j].Buttons |= (1 << i);
			else
				g_KeyToJoyState[j].Buttons &= ~(1 << i);
		}

		g_VJoy.UpdateJoyState(j, &g_KeyToJoyState[j]);
	}
}

void StartVJoy()
{
	if(g_KeyToJoyEnabled)
	{
		if(!g_VJoy.Initialize())
			g_KeyToJoyEnabled = FALSE;
	}
}

void KillVJoy()
{
	g_VJoy.Shutdown();
}
