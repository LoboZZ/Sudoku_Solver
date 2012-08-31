/*

RSV_facilities.h    v0.8

*/

#include "std.h"

//sys_error();
//--------------------------------------------------------------------------------

string string_maker(string);
void sys_error(int);
void sys_error(string);
void sys_error(string, string);
void sys_error(int, string);
void sys_error(int, string, string);

//loose-cin handling
//----------------------------------------------------------------------------------

void cin_throw1();
void cin_throw();


//cases
//---------------------------------------------------------------------------------

#ifndef _CASES
#define _CASES

class Cases_rsv
{
public:
	string all_up(string);
	string all_low(string);
	string first_up(string);
};
#endif _CASES


//keep_window_open()
//---------------------------------------------------------------------------------

void keep_window_open();

