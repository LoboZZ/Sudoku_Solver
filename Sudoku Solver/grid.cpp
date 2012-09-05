
#include "grid.h"


//Space class------------------------------------------------------
//Constructors_____________________________________________________

Space::Space(bool ov, int val, Coordinate a)
{
	try{
	if (!ov) throw Invalid();
	if (val<0||val>9) throw Invalid();
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

    

