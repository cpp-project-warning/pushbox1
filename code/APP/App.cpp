#include "App.h"
App::App() {}
App::~App() {}
void App::run()
{
	//initialize
	model = std::make_shared<Model>();
	model->set_model();
	viewmodel = std::make_shared<ViewModel>();
	viewmodel->set_model(model);

//	while (1) {
		//
		int viewMap[MAXN][MAXN] = { 0 };
		int wall[MAXN][MAXN];
		viewmodel->get_wall(wall);
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				if (wall[i][j] == 1) {
					viewMap[i][j] = 1;
				}
			}
		}
		Player p = viewmodel->get_player();
		position p_position = p.get_position();
		viewMap[p_position.x][p_position.y] = 4;

		std::set<Box> box = viewmodel->get_all_box();
		for (auto i = box.begin(); i != box.end(); i++) {
			position box_positon=(*i).get_position();
			viewMap[box_positon.x][box_positon.y] = 3;
		}
		std::set<position> des= viewmodel->get_destination();
		for (auto i = des.begin(); i != des.end(); i++) {
			viewMap[(*i).x][(*i).y] = 2;
		}
		_mainwindow.setviewMap(viewMap);


		std::shared_ptr<int>round = std::make_shared<int>();
		*round = 1;
		_mainwindow.setRound(round);
		_mainwindow.LoadGame();
		direction dir=_mainwindow.getMovedir();
		viewmodel->move_operation(dir);

		/*
		if(dir!=Nomove && viewmodel->move_operation(dir)){
			_mainwindow->resetMove();
		}
		*/
//		_mainwindow.resetMove();
//		_mainwindow.resetRoundchange();

		std::cout << "running\n";
//	}
}
