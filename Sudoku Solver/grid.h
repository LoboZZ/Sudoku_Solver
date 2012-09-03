
#include "std.h"
#include "RSV_facilities.h"

//class Coordinate

#ifndef COORDINATE
#define COORDINATE

class Coordinate
{
public:
	Coordinate(int a, int b)
		:x(a), y(b){}
	Coordinate()
		:x(-1), y(-1){}
	
	int x;
	int y;
};

#endif COORDINATE


//class Space --- every one of the 81 spaces

#ifndef SPACE
#define SPACE

class Space
{
public:
	class Invalid{};

	Space(bool, int); //if true asks for value and sets it to original, if false calls other constructor
	Space();

  //Access functions___________________________________
  //non-modifying functions	
	int value() const;
	bool original() const;
	bool found_val() const;


  //modifying functions
	int set_value();
	bool set_orig();
	int set_poss_val();


private:
//Data_______________________________________________
	int v;
	bool o_v;
	bool f_v;
	vector<int>poss_v;

	Coordinate coo;
	
//functions	
	bool allow_modif();
	Coordinate get_coo();
};

#endif SPACE


//class Grid --- full grid
//will store Spaces in a two dimensional vector array (vector of vectors)
//contains all function to read and modify Spaces in the grid
