#include "graph.h"
extern ofstream debug;

void deb_display_grid(vector<vector<Space>>v)
{
	debug<<"Grid---|||||||||||||||||||||||||||\n";
	debug<<"-----------------------------------\n";
	debug<<endl;

	for (int a=0; a<9; a++)
	{
		debug<<endl;
		for (int b=0; b<9; b++)
		{
			debug<<v[a][b].value();
			debug<<"  ";
		}
	}
}


