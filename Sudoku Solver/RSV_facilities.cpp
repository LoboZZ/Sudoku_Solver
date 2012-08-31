/*

RSV_facilities.cpp    v0.8

*/

#include "RSV_facilities.h"



//sys_error();
//--------------------------------------------------------------------------------


string string_maker(string msg)
{
string	final_msg="\nERROR"+msg;
return final_msg;
}

void sys_error(int value) //value
{
	string s_value;
	stringstream(value)>>s_value;
	string msg="\nValue: "+s_value+'\n';
	msg=string_maker(msg);
	throw runtime_error(msg);
}

void sys_error(string msg1) //message
{
	string msg=msg1+'\n';
	msg=string_maker(msg);
	throw runtime_error(msg);
}

void sys_error(string msg1, string msg2) //message + position
{
	string msg="\nMessage: "+msg1+'\n'+"Position: "+msg2+'\n';
	msg=string_maker(msg);
	throw runtime_error(msg);
}

void sys_error(int value, string msg1) //value + message/position
{
	string s_value;
	stringstream(value)>>s_value;
	string msg="\nValue: "+s_value+"\nPosition or message: "+msg1+'\n';
	msg=string_maker(msg);
	throw runtime_error(msg);
}

void sys_error(int value, string msg1, string msg2) //value + message + position
{
	string s_value;
	stringstream(value)>>s_value;
	string msg="\nValue: "+s_value+"\nMessage: "+msg1+"\nPosition: "+msg2+'\n';
	msg=string_maker(msg);
	throw runtime_error(msg);
}


//loose-cin handling
//----------------------------------------------------------------------------------


void cin_throw1()
{
	cin.clear();
	cin.ignore();
}

void cin_throw()
{
	char str [256];
	cin.get(&str[0], numeric_limits<streamsize>::max());
	cin.clear();
	cin.ignore();
}


//cases
//---------------------------------------------------------------------------------

//Cases cases; //declaration of object cases of class Cases

/*
string Cases_rsv::all_up(string word)
{
	string f_word;
	char letter=' ';
	
	for (int check=0; (unsigned)check<=word.size()-1; check++)
	{
		letter=word[check];
		letter=toupper(letter);
		f_word+=letter;
	}

	return f_word;
}

string Cases_rsv::all_low(string word)
{
	string f_word;
	char letter=' ';

	for (int check=0; (unsigned)check<=word.size()-1; check++)
	{
		letter=word[check];
		letter=tolower(letter);
		f_word+=letter;
	}

    return f_word;
}

string Cases_rsv::first_up(string word)
{
	string f_word;
	char letter=' ';

	letter=word[0];
	letter=toupper(letter);
	f_word+=letter;

	for (int check=1; (unsigned)check<=word.size()-1; check++)
	{
		letter=word[check];
		letter=tolower(letter);
		f_word+=letter;
	}

    return f_word;
}
*/

//keep_window_open()
//---------------------------------------------------------------------------------

void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}
