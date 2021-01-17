#pragma once
#ifndef _FrgCAD_CmdLnCompleter_Header
#define _FrgCAD_CmdLnCompleter_Header

#include <FrgCAD_Global.hxx>
#include <QtWidgets/QCompleter>

BeginForgCADLib

class FORGCAD_EXPORT FrgCAD_CmdLnCompleter
	: public QCompleter
{

	Q_OBJECT

public:

	FrgCAD_CmdLnCompleter
	(
		const QStringList& completions,
		QObject* parent = nullptr
	);

	QString ContainCommand(const QString& command);
	QString GetMessageFromCommand(const QString& command) const;

	QString GetAcceptedCommand() const { return theLastSelectedCommand_; }

protected:

	QString theLastSelectedCommand_;
};

EndForgCADLib

#endif // !_FrgCAD_CmdLnCompleter_Header
