// QCodeEditor
#include <QPythonCompleter>
#include <QLanguage>

// Qt
#include <QStringListModel>
#include <QFile>

QPythonCompleter::QPythonCompleter(QObject* parent) :
	QCompleter(parent)
{
	// Setting up Python types
	QStringList list;

	//Q_INIT_RESOURCE(qcodeeditor_resources);
	QFile fl(":/styles/QCodeEditor/languages/python.xml");

	if (!fl.open(QIODevice::ReadOnly))
	{
		return;
	}

	QLanguage language(&fl);

	if (!language.isLoaded())
	{
		return;
	}

	auto keys = language.keys();
	for (auto&& key : keys)
	{
		auto names = language.names(key);
		list.append(names);
	}

	setModel(new QStringListModel(list, this));
	setCompletionColumn(0);
	setModelSorting(QCompleter::CaseInsensitivelySortedModel);
	setCaseSensitivity(Qt::CaseSensitive);
	setWrapAround(true);
}
