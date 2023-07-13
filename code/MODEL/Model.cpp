#include "Model.h"
#include "get.h"

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

extern int level;
extern int level_num;

extern int get_box_number();
extern int** get_wall();
extern position* get_destination(int box_number);
extern position* get_box(int box_number);
extern position get_player();

Model::Model()
{
	count_step = 0;
	int box_number = get_box_number();
	int wall[MAXN][MAXN];
	get_wall(wall);
	position *destination = get_destination(box_number);
	position *box = get_box(box_number);
	position player = get_player().get_position();
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

Model::~Model()
{

}

Map& Model::get_game_map()
{
	return game_map;
}

Player& Model::get_player()
{
	return p;
}

std::set<Box>& Model::get_all_box()
{
	return all_box;
}

void Model::set_model()
{
	count_step = 0;
	int box_number = get_box_number();
	int wall[MAXN][MAXN];
	get_wall(wall);
	position *destination = get_destination(box_number);
	position *box = get_box(box_number);
	position player = get_player().get_position();
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
	p.set_direction(Down);
	all_box = all_box_init;
}

bool Model::move_operation(direction dir)
{
	int count_step_before = count_step;
	direction dir_before = get_player().get_direction();
	position player_pos_before = get_player().get_position();
	std::set<Box> box_pos_before = get_all_box();

	p.set_direction(dir);
	bool res = p.move_player(dir, all_box, game_map);
	judge_if_win();

	if( !(player_pos_before == get_player().get_position()) || !(box_pos_before == get_all_box()) )
	{
		Fire_OnPropertyChanged("ViewMap");
	}
	if(count_step != count_step_before)
	{
		Fire_OnPropertyChanged("Step");	
	}
	if(dir_before != get_player().get_direction())
	{
		Fire_OnPropertyChanged("Orientation");	
	}
	return res;
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
		Fire_OnPropertyChanged("doSuccess");
		return true;
	}
	else
	{
		return false;
	}
}

void Model::change_current_game(int operation)
{
	//-1表示上一关
	if(operation == -1)
	{
		if(level != 1)
		{
			level -= 1;
			set_model();
			Fire_OnPropertyChanged("Level");
			Fire_OnPropertyChanged("ViewMap");
		}
	}
	//0表示重新开始本关
	else if(operation == 0)
	{
		reset_model();
	}
	//1表示下一关
	else if(operation == 1)
	{
		if(level != level_num)
		{
			level += 1;
			set_model();
			Fire_OnPropertyChanged("Level");
			Fire_OnPropertyChanged("ViewMap");
		}
	}
	//2不进行任何
}

int& Model::get_count_step()
{
	return count_step;
}