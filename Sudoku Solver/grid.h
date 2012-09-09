
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
public:

	struct Coo_and_val
	{
		Coo_and_val(int a, Coordinate b)
			:coo(b), val(a){}
		Coo_and_val()
			:coo(-1,-1), val(-1){}
		
		friend istream& operator>>(istream& is, Coo_and_val& cov);
		Coo_and_val& operator=(Coo_and_val& right)
		{
			coo=right.coo;
			val=right.val;
			return *this;
		}

		Coordinate coo;
		int val;
	};
	
	class Error{}; //for exceptions
	
	Grid();

//Access functions___________________________________
  //non-modifying functions	
	const vector<vector<Space>>& grid() const;


  //modifying functions
	bool set_original();
	bool solve();
	


private:
//Data_______________________________________________
    vector<vector<Space>>gd;  //9x9 two dimensional vector
    bool original;
	bool solved;
	bool unsolvable; 

//functions___________________________________________	
//non-modifying


//modifying
	

	//HELPER______________________________________________
	static const int DONE=-5;
	static const int FAIL=-7;
public:
    Coo_and_val get_entry();
	Coo_and_val get_entry(bool);

};

#endif GRID





