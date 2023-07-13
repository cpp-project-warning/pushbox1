#include "ViewModel.h"

extern int level;

ViewModel::ViewModel():m_move(std::make_shared<MoveCommand>),
m_sink(std::make_shared<ViewModelSink>(this))
{

}

ViewModel::~ViewModel()
{

}

void ViewModel::set_model(const std::shared_ptr<Model>& model)
{
	m_model = model;
}

void ViewModel::set_direction(direction dir)
{
	m_model->get_player().set_direction(dir);
}

void ViewModel::set_change(int operation)
{
	m_model->change_current_game(operation);
}

	// Player ViewModel::set_player();
	// std::set<Box> ViewModel::set_all_box();
	// void ViewModel::set_wall(int w[][MAXN]);
	// std::set<position> sViewModel::et_destination();

void ViewModel::get_ViewMap(int viewMap[][MAXN])
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			viewMap[i][j] = 0;
		}
	}
	int wall[MAXN][MAXN];
	get_wall(wall);
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			if (wall[i][j] == 1)
			{
				viewMap[i][j] = 1;
			}
		}
	}
	Player p = get_player();
	position p_position = p.get_position();
	viewMap[p_position.x][p_position.y] = 4;
	std::set<Box> box = get_all_box();
	for (auto i = box.begin(); i != box.end(); i++)
	{
		position box_positon=(*i).get_position();
		viewMap[box_positon.x][box_positon.y] = 3;
	}
	std::set<position> des= get_destination();
	for (auto i = des.begin(); i != des.end(); i++)
	{
		viewMap[(*i).x][(*i).y] = 2;
	}
}

int ViewModel::get_Level()
{
	return level;
}

int ViewModel::get_Step()
{
	return m_model->get_count_step();
}

bool ViewModel::get_Ifsuccess()
{
	return m_model->judge_if_win();
}

direction ViewModel::get_Orientation()
{
	return m_model->get_player().get_direction();
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
	return m_model->move_operation(dir);
}

void ViewModel::skip_operation(int operation)
{
	m_model->change_current_game(operation);
}

std::shared_ptr<ICommandBase> ViewModel::get_MoveCommand() noexcept
{
	return std::static_pointer_cast<ICommandBase>(m_move);
}

std::shared_ptr<ICommandBase> ViewModel::get_SkipCommand() noexcept
{
	return std::static_pointer_cast<ICommandBase>(m_skip);
}

std::shared_ptr<IPropertyNotification> ViewModel::get_PropertySink() noexcept
{
	return std::static_pointer_cast<IPropertyNotification>(m_sink);
}