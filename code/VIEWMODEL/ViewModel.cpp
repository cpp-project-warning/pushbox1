#include "ViewModel.h"

ViewModel::ViewModel()
{

}

ViewModel::~ViewModel()
{

}

void ViewModel::set_model(const std::shared_ptr<Model>& model)
{
	m_model = model;
}

Player ViewModel::get_player()
{
	return m_model->get_player();
}

std::set<Box> ViewModel::get_all_box()
{
	return m_model->get_all_box();
}

// int** ViewModel::get_wall()
// {
// 	return m_model->get_game_map().get_wall();
// }

void ViewModel::get_wall(int w[][MAXN])
{
	m_model->get_game_map().get_wall(w);
}

std::set<position> ViewModel::get_destination()
{
	return m_model->get_game_map().get_destination();
}

bool ViewModel::move_operation(direction dir)
{
	return true;	
}
	
bool ViewModel::if_next_game()
{
	return true;
}

bool ViewModel::if_reset()
{
	return true;
}

