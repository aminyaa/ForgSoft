#pragma once
#ifndef _FrgCAD_CmdLineEdit_Header
#define _FrgCAD_CmdLineEdit_Header

#include <FrgCAD_Global.hxx>
#include <QtWidgets/QLineEdit>

BeginForgCADLib

class FrgCAD_CmdLnCompleter;

class FORGCAD_EXPORT FrgCAD_CmdLineEdit
	: public QLineEdit
{

	Q_OBJECT

public:

	FrgCAD_CmdLineEdit(QWidget* parent = nullptr);

	Q_SIGNAL void CommandAcceptedSignal(const QString& command);
	Q_SIGNAL void ThrowErrorToConsole(const QString& error);

	void keyPressEvent(QKeyEvent*) override;
	void CancelCommand();
	void DisableCommandLine(bool condition = true);
	QString GetAcceptedCommand() const;

protected:

	FrgCAD_CmdLnCompleter* theCompleter_ = nullptr;
};

EndForgCADLib

#endif // !_FrgCAD_CmdLineEdit_Header
