#include "../COMMON/push_box_base.h"
#include "../COMMON/COMMON.h"
extern int current_map_count;
int get_box_number()
{
	std::string datapath = "..//ProjectFiles//Game" + std::to_string(current_map_count) + "//box_number.txt";
	std::ifstream file;
	file.open("D:\\pushbox\\code\\ProjectFiles\\Game1\\box_number.txt");
	if(file.is_open())
	{
		int t;
		file >> t;
		return t;
	}
	else
	{
		return -1;
	}
}

/*
int** get_wall()
{
	std::string datapath = "..//ProjectFiles//Game" + std::to_string(current_map_count) + "//wall.txt";
	std::ifstream file;
	file.open(datapath);
	if(file.is_open())
	{
//		std::cout << "success";
		int wall[MAXN][MAXN] = { 0 };
//		for (int i = 0; i < MAXN; i++)
//		{
//			*(wall + i) = new int[MAXN];
//		}
		for (int i = 0; i < MAXN; i++)
		{
			for (int j = 0; j < MAXN; j++)
			{
				int t;
				file >> t;
				wall[i][j] = t;
			}
		}
		return (int **)wall;
	}
	else
	{
///		std::cout << "read_file_failed\n";
		return NULL;
	}
}
*/

void get_wall(int w[][MAXN])
{
	std::string datapath = "..//ProjectFiles//Game" + std::to_string(current_map_count) + "//wall.txt";
	std::ifstream file;
	file.open("D:\\pushbox\\code\\ProjectFiles\\Game1\\wall.txt");
	if(file.is_open())
	{
		for(int i = 0; i < MAXN; i++)
		{
			for(int j = 0; j < MAXN; j++)
			{
				int t;
				file >> t;
				w[i][j] = t;
			}
		}
	}
}

position* get_destination(int box_number)
{
	std::string datapath = "..//ProjectFiles//Game" + std::to_string(current_map_count) + "//destination.txt";
	std::ifstream file;
	file.open("D:\\pushbox\\code\\ProjectFiles\\Game1\\destination.txt");
	if(file.is_open())
	{
		position *destination = 0;
		destination = new position[MAXN];
		for (int i = 0; i < box_number; i++)
		{
			int xx;
			int yy;
			position p;
			file >> xx >> yy;
			p.x = xx;
			p.y = yy;
			destination[i] = p;
		}
		return destination;
	}
	else
	{
		return NULL;
	}
}

position* get_box(int box_number)
{
	std::string datapath = "..//ProjectFiles//Game" + std::to_string(current_map_count) + "//box.txt";
	std::ifstream file;
	file.open("D:\\pushbox\\code\\ProjectFiles\\Game1\\box.txt");
	if(file.is_open())
	{
		position *box = 0;
		box = new position[MAXN];
		for (int i = 0; i < box_number; i++)
		{
			int xx;
			int yy;
			position p;
			file >> xx >> yy;
			p.x = xx;
			p.y = yy;
			box[i] = p;
		}
		return box;
	}
	else
	{
		return NULL;
	}
}

position get_player()
{
	std::string datapath = "..//ProjectFiles//Game" + std::to_string(current_map_count) + "//player.txt";
	std::ifstream file;
	file.open("D:\\pushbox\\code\\ProjectFiles\\Game1\\player.txt");
	position p;
	p.x = -1;
	p.y = -1;
	if(file.is_open())
	{
		int xx;
		int yy;		
		file >> xx >> yy;
		p.x = xx;
		p.y = yy;
	}
	return p;
}