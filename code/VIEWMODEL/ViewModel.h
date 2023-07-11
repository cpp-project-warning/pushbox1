
#ifndef _VIEWMODEL_H_
#define _VIEWMODEL_H_

#include "../MODEL/Model.h"
#include "../COMMON/COMMON.h"

class ViewModel
{
private:
	std::shared_ptr<Model> m_model;

public:
	ViewModel();
	~ViewModel();
	void set_model(const std::shared_ptr<Model>& model);
	Player get_player();
	std::set<Box> get_all_box();
	//int** get_wall();
	void get_wall(int w[][MAXN]);
	std::set<position> get_destination();
	bool move_operation(direction dir);
	bool if_next_game();
	bool if_reset();
};

#endif
