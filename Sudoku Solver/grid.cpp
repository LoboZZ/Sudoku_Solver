
#include "grid.h"
extern ofstream debug;
#include "graph.h"

//Space class------------------------------------------------------
//Constructors_____________________________________________________

Space::Space(bool ov, int val, Coordinate a)
{
	try{
	if (!ov) throw Invalid();
	if (val<1||val>9) throw Invalid();
	if (a.x>8||a.x<0||a.y>8||a.y<0) throw Invalid();
	
	v=val;
	o_v=true;
	f_v=true;
	coo=a;
	}catch(Space::Invalid) {sys_error("Space::Space(bool, int, Coordinate)","Invalid Space-filling info");}
}
	
Space::Space(Coordinate a)
{
	try{
	v=-1;
	o_v=false;
	f_v=false;
	
	if (a.x>8||a.x<0||a.y>8||a.y<0) throw Invalid();
	coo=a;
	}catch(Space::Invalid) {sys_error("Space::Space(Coordinate)","Invalid Space-filling info");}
}


//non-modifying functions_______________________________________________

	int Space::value() const
	{
		return v;
	}
	
	bool Space::original() const
	{
		return o_v;
	}

	bool Space::found_val() const
	{
		return f_v;
	}

	bool Space::find_poss_val(int num) const
	{
		if (poss_v.size()==0) return false;
		
		for (int a=0; a<poss_v.size(); a++)
		{
			if (poss_v[a]==num) return true;
		}

		return false;
	}

//modifying functions______________________________________________________

	bool Space::set_value(int num) 
	{
		try{
			if (!allow_modif()) throw Invalid();
			v=num;
			bool f_v=true;
		}catch(Space::Invalid) {sys_error("int Space::set_value(int)", "modification not allowed");}

		return true;
	}

	bool Space::set_poss_val(int num)
	{
		if (o_v||f_v) return false;

		if (poss_v.size()==0) 
			{
				poss_v.push_back(num);
				return true;
		    }
		
		for (int a=0; a<poss_v.size(); a++)
		{
			if (poss_v[a]==num) return true;
		}

		poss_v.push_back(num);
		return true;
	}

	bool Space::delete_poss_val(int num)
	{
		if (o_v||f_v) return true;

		else if (poss_v.size()==0) return true;

		for (int a=0; a<poss_v.size(); a++)
		{
			if (poss_v[a]==num)
			{
				poss_v.erase(poss_v.begin()+a);
				return true;
			}
		}
	return true;
	}

	bool Space::allow_modif()
	{
		if (o_v||f_v) return false;
	    return true;
	}

			
//Grid------------------------------------------------------------------------------------
//Constructor_____________________________________________________________

	Grid::Grid()
	{
		try{
			
	for (int a=0; a<9; a++)
		{
			vector<Space>v;
			for (int b=0; b<9; b++)
			{
				v.push_back(Space(Coordinate(a,b)));
			}
			gd.push_back(v);
	    }

    original=false;
	solved=false;
	unsolvable=false;
		
          } catch (Grid::Error) {debug<<"\nerror in default construction of grid";}
	}



//Access functions______________________________________________________
	//non-modifying function
	const vector<vector<Space>>& Grid::grid() const
	{
		return gd;
	}


	//modifying
	bool Grid::set_original()
	{
		
        bool first_time=true;
		while (true)
		{
			vector<Space>or_sps;
			
			Coo_and_val cv;
			cv=get_entry(first_time);
			first_time=false;
			
			string s;
			if (cv.val==FAIL) 
				{
					cin.getline(s.c_str(), numberic_limits<streamsize>::max());  //<<<<<<<<<debug!!!!
					continue;
			    }
			else if (cv.val==DONE) 
				{
					fill_grid(or_sps);
					original=true;
					return true;
			    }
			else if (cv.val==-1) continue;
			else 
			{
				Space temp(true, cv.val, cv.coo);
				or_sps.push_back(temp);
			}
	    }

	  sys_error("bool Grid::set_original()", "exited loop - should not happen!");
	}

	
//private___________________________________________________________________
	//non-modifying


	//modifying
	void Grid::fill_grid(vector<Space>v)
	{
		for (int a=0; a<9; a++)
		{
			for (int b=0; b<9; b++)
			{  /////////////////////<<<<<<<<------ finish
			}
		}
	}


//HELPER___________________________________________________________________
	
	Grid::Coo_and_val Grid::get_entry(const bool a)
	{
		
		if (a==true) 
		{
			cout<<"\n\nTo fill in the original values in the puzzle enter the coordinate followed by \nthe value. For instance: \n> (1,4) 8\n"
				<<"\nAfter you have entered all the original values type 'done' to solve the puzzle.\n\n";
		}
		
		Coo_and_val b=get_entry();
		debug<<"\nb.val== "<<b.val;
		
		return b;
	}

	
	Grid::Coo_and_val Grid::get_entry()
	{
		debug<<"\nGrid::Coo_and_val Grid::get_entry()";
		Coo_and_val re_val;
		cout<<"> ";

	    if (cin>>re_val) return re_val;
		else if (cin.fail()) 
			{
				debug<<"\nentered else if"; //<---
				string s;
				cin>>s;
				if (s=="done"||s=="DONE"||s=="Done") return Coo_and_val(DONE, Coordinate());
				else return Coo_and_val(FAIL, Coordinate());
		    }
		
		else {
			    debug<<"\ntook else";
			    return Coo_and_val(FAIL, Coordinate());
		     }
	}


    istream& operator>>(istream& is, Grid::Coo_and_val& cov)
	{debug<<"\n\n Coo_and_val operator>> overload";
	 class Error{};

	try{
	
		char brk1;
		int coo1;
		char comm;
		int coo2;
		char brk2;
		int val;

		if (!(is>>brk1)) {debug<<"\nCoo_and_val input of first character error"; throw Error();}
	
		if (brk1!='(') {is.unget(); debug<<"\nFirst charachter is not of coo val syntax"; throw Error();}
		else if (brk1=='(')
		{
			if (!(is>>coo1>>comm>>coo2>>brk2>>val)) {debug<<"\nCoo_and_val input failure"; throw Error();}
			if (comm!=','||brk2!=')') {debug<<"\nCoo_and_val input -> syntax error"; throw Error();}
			if (coo1<0||coo1>8||coo2<0||coo2>8) {debug<<"\nCoo_and_val input -> out of range coordinate"; throw Error();}
			if (val<1||val>9) {debug<<"\nCoo_and_val input -> val not 1-9 range"; throw Error();}
		}
		else {debug<<"\nCoo_and_val input unknown error"; throw Error();}

		cov.coo=Coordinate(coo1, coo2);
		cov.val=val;

		debug<<"\ncov.coo== "<<cov.coo.x<<"  "<<cov.coo.y;
		debug<<"\ncov.val== "<<cov.val;
		
		return is;

	} catch (Error) {is.clear(ios_base::failbit); debug<<"\nUNKNONW ERROR - Coo_and_val input - end of fundtion"; return is;}
	}
