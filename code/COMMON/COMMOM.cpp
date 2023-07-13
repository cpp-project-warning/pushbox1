#include "COMMON.h"

int level = 1;

int level_num = 5; //总关卡数

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

//分三种情况，空地，墙，箱子
bool Player::move_player(direction dir, std::set<Box>& all_box, Map m)
{
	position player_before = player;
	position expect_pos;
	if(dir == Up)
	{
		expect_pos.x = player.x;
		expect_pos.y = player.y + 1;
	}
	else if(dir == Left)
	{
		expect_pos.x = player.x - 1;
		expect_pos.y = player.y; 
	}
	else if(dir == Down)
	{
		expect_pos.x = player.x;
		expect_pos.y = player.y - 1;
	}
	else if(dir == Right)
	{
		expect_pos.x = player.x + 1;
		expect_pos.y = player.y; 
	}
	bool if_box = false;
	if(!m.if_wall(expect_pos.x, expect_pos.y)) //目标移动位置没有墙
	{
		for(auto a : all_box)
		{
			if(a.get_position() == expect_pos) //目标移动位置有箱子
			{
				if_box = true;
			}
		}
		if(if_box) //目标位置是箱子
		{
			position expect_pos_1;
			if(dir == Up)
			{
				expect_pos_1.x = expect_pos.x;
				expect_pos_1.y = expect_pos.y + 1;
			}
			else if(dir == Left)
			{
				expect_pos_1.x = expect_pos.x - 1;
				expect_pos_1.y = expect_pos.y;
			}
			else if(dir == Down)
			{
				expect_pos_1.x = expect_pos.x;
				expect_pos_1.y = expect_pos.y - 1;
			}
			else if(dir == Right)
			{
				expect_pos_1.x = expect_pos.x + 1;
				expect_pos_1.y = expect_pos.y;
			}
			bool if_box_1 = false;
			if(!m.if_wall(expect_pos_1.x, expect_pos_1.y)) //箱子前面不是墙
			{
				for(auto a : all_box)
				{
					if(a.get_position() == expect_pos_1) //箱子前面是箱子
					{
						if_box_1 = true;
					}
				}
				if(!if_box_1) //箱子前面不是箱子
				{
					for(auto a& : all_box) //找到需要推动的箱子
					{
						if(a.get_position() == expect_pos)
						{
							a.move_box(dir);
							player = expect_pos;
						}
					}
				}
			}
		}
		else //目标移动位置是空地
		{
			player = expect_pos;
		}
	}
	if(player_before == player)
	{
		return false;
	}
	else
	{
		return true;
	}
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

position& Box::get_position() const
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

void Box::move_box(direction dir)
{
	if(dir == Up)
	{
		box.y += 1;
	}
	else if(dir == Left)
	{
		box.x -= 1;
	}
	else if(dir == Down)
	{
		box.y -= 1;
	}
	else if(dir == Right)
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