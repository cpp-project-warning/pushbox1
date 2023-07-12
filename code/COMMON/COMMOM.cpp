#include "COMMON.h"

int current_map_count = 1;

int roundNum = 5;  // 块大小

Map::Map()
{

}

Map::Map(int bn, int w[MAXN][MAXN], position des[])
{
	box_number = bn;
	for(int i = 0; i < MAXN; i++)
	{
		for(int j = 0; j < MAXN; j++)
		{
			if(w[i][j] == 1)
			{
				wall[i][j] = 1;
			}
			else
			{
				wall[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < box_number; i++)
	{
		destination.insert(des[i]);
	}
}

Map::~Map()
{

}

std::set<position>& Map::get_destination()
{
	return destination;
}

// int** Map::get_wall()
// {
// 	int **w = 0;
// 	w = new int *[MAXN];
// 	for (int i = 0; i < MAXN; i++)
// 	{
// 		*(w + i) = new int[MAXN];
// 	}
// 	for (int i = 0; i < MAXN; i++)
// 	{
// 		for (int j = 0; j < MAXN; j++)
// 		{
// 			w[i][j] = wall[i][j];
// 		}
// 	}
// 	return w;
// }

void Map::get_wall(int w[][MAXN])
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			w[i][j] = wall[i][j];
		}
	}	
}

void Map::set_box_number(int bx)
{
	box_number = bx;
}

// void Map::set_wall(int** w)
// {
// 	for(int i = 0; i < MAXN; i++)
// 	{
// 		for(int j = 0; j < MAXN; j++)

// 		{
// 			wall[i][j] = ((int*)w)[i*MAXN+j];
// 		}
// 	}
// }

void Map::set_wall(int w[][MAXN])
{
	for(int i = 0; i < MAXN; i++)
	{
		for(int j = 0; j < MAXN; j++)

		{
			wall[i][j] = w[i][j];
		}
	}
}

void Map::set_destination(std::set<position> des)
{
	destination = des;
}

bool Map::if_wall(int x, int y)
{
	if(wall[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Player::Player()
{
	dir = Down;
}

Player::Player(position p)
{
	player.x = p.x;
	player.y = p.y;
	dir = Down;
}

position& Player::get_position()
{
	return player;
}

void Player::set_position(position p)
{
	player = p;
}

bool Player::move_player(direction dir, std::set<Box>& all_box)
{
	bool if_move = false;
	if(dir == Up)
	{

	}
	else if(dir == Left)
	{

	}
	else if(dir == Down)
	{

	}
	else if(dir == Right)
	{

	}
	return if_move;
}

void Player::set_direction(direction dir)
{
	this->dir = dir;
}

direction& Player::get_direction()
{
	return dir;
}

Box::Box(position b)
{
	box.x = b.x;
	box.y = b.y;
}

position& Box::get_position()
{
	return box;
}

void Box::set_position(position p)
{
	box = p;
}

bool Box::check_around_if_wall(char c, Map game_map)
{
	bool ans;
	if(c == 'a')
	{
		ans = game_map.if_wall(box.x-1, box.y);
	}
	else if(c == 'w')
	{
		ans = game_map.if_wall(box.x, box.y+1);
	}
	else if(c == 's')
	{
		ans = game_map.if_wall(box.x, box.y-1);
	}
	else if(c == 'd')
	{
		ans = game_map.if_wall(box.x+1, box.y);
	}
	return ans;
}

void Box::move_box(char c)
{
	if(c == 'w')
	{
		box.y += 1;
	}
	else if(c == 'a')
	{
		box.x -= 1;
	}
	else if(c == 's')
	{
		box.y -= 1;
	}
	else if(c == 'd')
	{
		box.x += 1;
	}
}

bool Box::operator < (const Box & rhs ) const
{
	if((box.x < rhs.box.x) || (box.x == rhs.box.x && box.y < rhs.box.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Box::operator == (const Box & rhs) const
{
	if(box.x == rhs.box.x && box.y == rhs.box.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}