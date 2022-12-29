
#define ESC_KEY                        53

#define NoEventMask			0L
#define KEY_PRESS			(1L<<0)
#define KeyReleaseMask			(1L<<1)
#define ButtonPressMask			(1L<<2)
#define ButtonReleaseMask		(1L<<3)
#define LeaveWindowMask			(1L<<5)
#define PointerMotionMask		(1L<<6)
#define PointerMotionHintMask	(1L<<7)
#define Button1MotionMask		(1L<<8)

/*  They start from 2 because 0 and 1
are reserved in the protocol for errors and replies. */

#define ON_KEYDOWN 2
#define ON_KEYUP 	3
#define ON_MOUSEDOWN 4
#define ON_MOUSEUP  5
#define ON_MOUSEMOVE 6
#define ON_EXPOSE  12
#define DESTROY_NOTIFY		17
