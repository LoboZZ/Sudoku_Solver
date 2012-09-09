
#include "main.h"
ofstream debug;

int main()
{
	try{
	
	debug.open("log.txt"); //for debugging
	if (!debug) sys_error("main", "ofstream debug did not open file");

	Grid a;
	deb_display_grid(a.grid());
	
	
	Grid::Coo_and_val cb;
	cb=a.get_entry(true);

	cout<<endl<<endl;
	cout<<'('<<cb.coo.x<<","<<cb.coo.y<<") "<<cb.val;
	
	cin.get();
	keep_window_open();
	
	}catch (exception& e) {cerr<<e.what(); debug<<e.what(); keep_window_open();} catch(...) {cerr<<"Unknown ERROR"; debug<<"Unknown ERROR"; keep_window_open();}
}
