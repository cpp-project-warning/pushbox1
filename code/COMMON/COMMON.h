#ifndef _COMMON_H_
#define _COMMON_H_

#include "push_box_base.h"

#define MAXN 20

enum direction
{
	Up,
	Down,
	Left,
	Right,
	Nomove
};

struct position
{
	int x;
	int y;
	bool operator < (const position & rhs) const
	{
		if((x < rhs.x) || (x == rhs.x && y < rhs.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator == (const position & rhs) const
	{
		if(x == rhs.x && y == rhs.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Map
{
private:
	int box_number;
	//1表示有墙，0表示没有
	int wall[MAXN][MAXN];
	std::set<position> destination;

public:
	Map();
	Map(int bn, int w[MAXN][MAXN], position des[]);
	~Map();
	std::set<position> get_destination();
	//int** get_wall();
	void get_wall(int w[][MAXN]);
	void set_box_number(int bx);
	//void set_wall(int** w);
	void set_wall(int w[][MAXN]);
	void set_destination(std::set<position> des);
	bool if_wall(int x, int y);
};

class Player
{
private:
	position player;

public:
	Player();
	Player(position p);
	position get_position() const;
	void set_position(position p);
	//传入移动方向，判断能否进行移动（对应方向有墙不行，或有箱子且箱子后面还有东西不想）
				void move_player(char c);
};

class Box
{
private:
	position box;

public:
	Box(position b);
	position get_position() const;
	void set_position(position p);
	//对应方向有墙返回1，没有返回0
	bool check_around_if_wall(char c, Map game_map) throw(int);
	//'n'不移动，其他情况朝对应方向移动
	void move_box(char c, Map game_map);
	bool operator < (const Box & rhs ) const;
	bool operator == (const Box & rhs) const;
};

#endif
