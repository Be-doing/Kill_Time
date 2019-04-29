
#include"game.h"


int main() 
{
	if (StartGame())
	{
		if (LevelGame())
		{
			init_arr(mine_map, show_map);
			PrintMap(show_map);
		}
	}
	system("pause");
	return 0;
}