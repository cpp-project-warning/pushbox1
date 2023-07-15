////////////////////////////////////////////////////////////////////////////////

#include "../../COMMON/etlbase.h"

#include "MainWindowPropertySink.h"

#include "../MainWindow.h"

////////////////////////////////////////////////////////////////////////////////

MainWindowPropertySink::MainWindowPropertySink(MainWindow* pW) throw() : m_pW(pW){

}

void MainWindowPropertySink::OnPropertyChanged(const std::string& str)
{
//	m_pW->draw();
#ifndef NDEBUG
	qDebug() << "windows_property_sink::on property changed " << str << "\n"<<"level:"<<level<<"step: \n";
#endif // !NDEBUG
	if( str == "doSuccess" ) {
		m_pW->popsuccess();
	}
	else {
		m_pW->update();
	}

}

////////////////////////////////////////////////////////////////////////////////