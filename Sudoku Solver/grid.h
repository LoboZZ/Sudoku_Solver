
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

	Space(bool, int, Coordinate); //if true asks for value and sets it to original, if false calls other constructor
	Space(Coordinate);

  //Access functions___________________________________
  //non-modifying functions	
	int value() const;
	bool original() const;
	bool found_val() const;
	bool find_poss_val(int) const;


  //modifying functions
	bool set_value(int);
	
	bool set_poss_val(int);
	bool delete_poss_val(int);


private:
//Data_______________________________________________
	int v;
	bool o_v;
	bool f_v;
	vector<int>poss_v;

	Coordinate coo;
	
//functions	
	bool allow_modif();
};

#endif SPACE


//class Grid --- full grid
//will store Spaces in a two dimensional vector array (vector of vectors)
//contains all function to read and modify Spaces in the grid

#ifndef GRID
#define GRID

class Grid
{



};

#endif GRID