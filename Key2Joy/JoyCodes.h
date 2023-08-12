#define JOY_LEFT			0
#define JOY_RIGHT			1
#define JOY_UP				2
#define JOY_DOWN			3
#define JOY_ZAXIS_NEG		4
#define JOY_ZAXIS_POS		5
#define JOY_XROTATE_NEG		6
#define JOY_XROTATE_POS		7
#define JOY_YROTATE_NEG		8
#define JOY_YROTATE_POS		9
#define JOY_ZROTATE_NEG		10
#define JOY_ZROTATE_POS		11
#define JOY_SLIDER_NEG		12
#define JOY_SLIDER_POS		13
#define JOY_DIAL_NEG		14
#define JOY_DIAL_POS		15
#define JOY_POV0_LEFT		16
#define JOY_POV0_RIGHT		17
#define JOY_POV0_UP			18
#define JOY_POV0_DOWN		19
#define JOY_POV1_LEFT		20
#define JOY_POV1_RIGHT		21
#define JOY_POV1_UP			22
#define JOY_POV1_DOWN		23
#define JOY_POV2_LEFT		24
#define JOY_POV2_RIGHT		25
#define JOY_POV2_UP			26
#define JOY_POV2_DOWN		27
#define JOY_POV3_LEFT		28
#define JOY_POV3_RIGHT		29
#define JOY_POV3_UP			30
#define JOY_POV3_DOWN		31
#define JOY_BUTTON1			32
#define JOY_BUTTON2			33
#define JOY_BUTTON3			34
#define JOY_BUTTON4			35
#define JOY_BUTTON5			36
#define JOY_BUTTON6			37
#define JOY_BUTTON7			38
#define JOY_BUTTON8			39
#define JOY_BUTTON9			40
#define JOY_BUTTON10		41
#define JOY_BUTTON11		42
#define JOY_BUTTON12		43
#define JOY_BUTTON13		44
#define JOY_BUTTON14		45
#define JOY_BUTTON15		46
#define JOY_BUTTON16		47
#define JOY_BUTTON17		48
#define JOY_BUTTON18		49
#define JOY_BUTTON19		50
#define JOY_BUTTON20		51
#define JOY_BUTTON21		52
#define JOY_BUTTON22		53
#define JOY_BUTTON23		54
#define JOY_BUTTON24		55
#define JOY_BUTTON25		56
#define JOY_BUTTON26		57
#define JOY_BUTTON27		58
#define JOY_BUTTON28		59
#define JOY_BUTTON29		60
#define JOY_BUTTON30		61
#define JOY_BUTTON31		62
#define JOY_BUTTON32		63
#define JOY_INPUT_COUNT		64

#define JOY_COUNT			2

#define JOY_BUTTON_COUNT	32

#define POV_UP				0
#define POV_RIGHT			1
#define POV_DOWN			2
#define POV_LEFT			3
#define POV_NIL				4

extern const PCHAR joy_codes[JOY_INPUT_COUNT];
extern const PCHAR multi_joy_codes[JOY_INPUT_COUNT];

int Name2Joy(PCHAR name);