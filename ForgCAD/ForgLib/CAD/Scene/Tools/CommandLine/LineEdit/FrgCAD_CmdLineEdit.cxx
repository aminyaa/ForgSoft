#include <FrgCAD_CmdLineEdit.hxx>
#include <FrgCAD_CmdLnCompleter.hxx>

#include <QtCore/QFile>
#include <QtWidgets/QCompleter>
#include <QtWidgets/QAbstractItemView>
#include <QtGui/QKeyEvent>

ForgCADLib::FrgCAD_CmdLineEdit::FrgCAD_CmdLineEdit(QWidget* parent /* = nullptr */)
	: QLineEdit(parent)
{
	QStringList words;
	QFile file(":/ForgCAD/Resources/Commands/Commands");
	if (file.open(QFile::ReadOnly))
	{
		while (!file.atEnd())
		{
			QByteArray line = file.readLine();
			if (!line.isEmpty())
				words << QString::fromUtf8(line.trimmed());
		}
	}

	theCompleter_ = new FrgCAD_CmdLnCompleter(words, this);
	this->setCompleter(theCompleter_);
	this->setPlaceholderText("Command");
}

void ForgCADLib::FrgCAD_CmdLineEdit::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Escape)
	{
		CancelCommand();
		return;
	}

	if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
	{
		auto isCommand = theCompleter_->ContainCommand(text());
		if (!isCommand.isEmpty())
			emit CommandAcceptedSignal(isCommand);
		else
		{
			if (text().isEmpty())
				return;

			emit ThrowErrorToConsole("Unknown Command! \"" + text() + "\" was not found.");
		}

		CancelCommand();
		return;
	}
	QLineEdit::keyPressEvent(event);

	auto pos = text().size();
	if (pos == 1)
		this->setText(text().toUpper());

	if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete)
	{

	}
	else
	{
		if (theCompleter_->popup()->isVisible())
		{
			if (this->selectedText().isEmpty())
			{
				theCompleter_->setCurrentRow(0);
				this->setText(theCompleter_->currentCompletion());
				this->cursorBackward(true, this->text().size() - pos);
			}
		}
	}
}

void ForgCADLib::FrgCAD_CmdLineEdit::CancelCommand()
{
	this->setText("");
	this->editingFinished();
	this->clearFocus();
}

void ForgCADLib::FrgCAD_CmdLineEdit::DisableCommandLine(bool condition)
{
	this->setEnabled(!condition);
}

QString ForgCADLib::FrgCAD_CmdLineEdit::GetAcceptedCommand() const
{
	return theCompleter_->GetAcceptedCommand();
}