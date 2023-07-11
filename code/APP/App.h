#ifndef _APP_H_
#define _APP_H_

#include "../MODEL/Model.h"
#include "../VIEWMODEL/ViewModel.h"
#include "../WINDOWS/Mainwindow.h"

class App
{
private:
	MainWindow _mainwindow;
//	Model model;
//	ViewModel viewmodel;
	std::shared_ptr<Model> model;
	std::shared_ptr<ViewModel> viewmodel;
public:
	App();
	~App();
	void run();
};









#endif
