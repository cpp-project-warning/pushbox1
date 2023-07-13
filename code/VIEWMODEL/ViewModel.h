
#ifndef _VIEWMODEL_H_
#define _VIEWMODEL_H_

#include "../MODEL/Model.h"
#include "../COMMON/COMMON.h"
#include "commands/MoveCommand.h"
#include "commands/SkipCommand.h"
#include "sinks/ViewModelSink.h"

class ViewModel:public Proxy_PropertyNotification<ViewModel>,
	public Proxy_CommandNotification<ViewModel>
{
private:
	std::shared_ptr<Model> m_model;
	std::shared_ptr<MoveCommand> m_move;
	std::shared_ptr<SkipCommand> m_skip;
	std::shared_ptr<ViewModelSink> m_sink;

public:
	ViewModel();
	~ViewModel();

	void set_model(const std::shared_ptr<Model>& model);

	void set_direction(direction dir);
	void set_change(int operation);

	//properties
	void get_ViewMap(int viewMap[][MAXN]);
	Player get_player();
	std::set<Box> get_all_box();
	void get_wall(int w[][MAXN]);
	std::set<position> get_destination();

	int get_Level();
	int get_Step();
	bool get_Ifsuccess();
	direction get_Orientation();

	bool move_operation(direction dir);
	void skip_operation(int operation);

	//commands
	std::shared_ptr<ICommandBase> get_MoveCommand() noexcept;
	std::shared_ptr<ICommandBase> get_SkipCommand() noexcept;

	//notifications
	std::shared_ptr<IPropertyNotification> get_PropertySink() noexcept;
};

#endif
