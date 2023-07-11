#include "MODEL.h"

// Model::Model(int box_number, int wall[MAXN][MAXN], position destination[], position box[], position player) :
// 	game_map(box_number, wall, destination), p(player), p_init(player)
// {
// 	for(auto a : box)
// 	{
// 		Box temp(a);
// 		all_box.insert(temp);
// 	}
// 	all_box_init = all_box;
// }
//extern int get_box_number();
//extern int** get_wall();
//extern position* get_destination(int box_number);

//extern position* get_box(int box_number);
//extern position get_player();
Model::Model()
{

}

Model::~Model()
{

}

Map Model::get_game_map()
{
	return game_map;
}

Player Model::get_player()
{
	return p;
}

std::set<Box> Model::get_all_box()
{
	return all_box;
}

void Model::set_model()
{
	int box_number = get_box_number();
	int wall[MAXN][MAXN];
	get_wall(wall);
	position *destination = get_destination(box_number);
	position *box = get_box(box_number);
	position player = ::get_player();
	game_map.set_box_number(box_number);
	game_map.set_wall(wall);
	std::set<position> des;
	for(int i = 0; i < box_number; i++)
	{
		des.insert(destination[i]);
	}
	game_map.set_destination(des);
	p.set_position(player);
	p_init.set_position(player);
	for(int i = 0; i < box_number; i++)
	{
		Box temp(box[i]);
		all_box.insert(temp);
	}
	all_box_init = all_box;
}

void Model::reset_model()
{
	p.set_position(p_init.get_position());
	all_box = all_box_init;
}

bool Model::move_operator(char c)
{
	p.move_player(c);
	return true;
}

bool Model::judge_if_win()
{
	std::set<position> boxes_position;
	for(auto a : all_box)
	{
		boxes_position.insert(a.get_position());
	}
	if(game_map.get_destination() == boxes_position)
	{
		return true;
	}
	else
	{
		return false;
	}
}
