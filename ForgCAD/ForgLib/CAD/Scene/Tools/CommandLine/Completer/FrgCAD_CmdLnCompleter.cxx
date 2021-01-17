#include <FrgCAD_CmdLnCompleter.hxx>

ForgCADLib::FrgCAD_CmdLnCompleter::FrgCAD_CmdLnCompleter
(
	const QStringList& completions,
	QObject* parent /* = nullptr */
)
	: QCompleter(completions, parent)
{
	this->setCompletionMode(QCompleter::PopupCompletion);
	this->setCaseSensitivity(Qt::CaseInsensitive);
}

QString ForgCADLib::FrgCAD_CmdLnCompleter::ContainCommand(const QString& command)
{
	if (command.isEmpty() && !theLastSelectedCommand_.isEmpty())
		return GetMessageFromCommand(theLastSelectedCommand_);

	if (!command.isEmpty())
	{
		for (int i = 0; QCompleter::setCurrentRow(i); i++)
		{
			if (command.contains(currentCompletion(), Qt::CaseInsensitive))
			{
				theLastSelectedCommand_ = command;
				return GetMessageFromCommand(command);
			}
		}
	}

	return "";
}

QString ForgCADLib::FrgCAD_CmdLnCompleter::GetMessageFromCommand(const QString& command) const
{
	if (command == "Point")
		return "Point: Enter Location of Point.";
	else if (command == "PolyLine")
		return "PolyLine: Enter Location of Points in Sequence.";
	else if (command == "SPLine")
		return "SPLine: Enter Location of Control Points in Sequence.";
	else if (command == "SPLineThroughPoints")
		return "SPLineThroughPoints: Enter Location of Points on Curve in Sequence.";
	else if (command == "Circle")
		return "Circle: Enter Location of Center and Then Second Point On Curve.";
	else if (command == "Rectangle")
		return "Rectangle: Enter First Corner and Then Second Corner of Rectangle.";

	return "";
}