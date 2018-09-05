#include "keys.h"
#include "world.h"
#ifdef QWERTY
bool do_key(world * w, int key)
{
	switch (key) {
	case '@':
		break;
	case 'A':
		break;
	case 'B':
		break;
	case 'C':
		break;
	case 'D':
		Backward_Char(w->curbuf);
		break;
	case 'E':
		break;
	case 'F':
		Forward_Char(w->curbuf);
		break;
	case 'G':
		break;
	case 'H':
		break;
	case 'I':
		break;
	case 'J':
		Next_Line(w->curbuf);
		break;
	case 'K':
		Prev_Line(w->curbuf);
		break;
	case 'L':
		break;
	case 'M':
		break;
	case 'N':
		break;
	case 'O':
		break;
	case 'P':
		break;
	case 'Q':
		break;
	case 'R':
		break;
	case 'S':
		break;
	case 'T':
		Beg_Of_Line(w->curbuf);
		break;
	case 'U':
		break;
	case 'V':
		break;
	case 'W':
		break;
	case 'X':
		return false;
		break;
	case 'Y':
		break;
	case 'Z':
		break;
	}
	return true;
}
#else
bool do_key(world * w, int key)
{
	switch (key) {
	case '@':
		break;
	case 'A':
		break;
	case 'B':
		break;
	case 'C':
		break;
	case 'D':
		break;
	case 'E':
		Backward_Char(w->curbuf);
		break;
	case 'F':
		break;
	case 'G':
		break;
	case 'H':
		Next_Line(w->curbuf);
		break;
	case 'I':
		break;
	case 'J':
		break;
	case 'K':
		break;
	case 'L':
		break;
	case 'M':
		break;
	case 'N':
		break;
	case 'O':
		break;
	case 'P':
		break;
	case 'Q':
		return false;
		break;
	case 'R':
		break;
	case 'S':
		break;
	case 'T':
		Prev_Line(w->curbuf);
		break;
	case 'U':
		Forward_Char(w->curbuf);
		break;
	case 'V':
		break;
	case 'W':
		break;
	case 'X':
		break;
	case 'Y':
		Beg_Of_Line(w->curbuf);
		break;
	case 'Z':
		break;
	}
	return true;
}
#endif
