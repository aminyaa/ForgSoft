// QCodeEditor
#include <QExprtkCompleter>
#include <QLanguage>

// Qt
#include <QStringListModel>
#include <QFile>

QExprtkCompleter::QExprtkCompleter(QObject* parent) :
	QCompleter(parent)
{
	// Setting up GLSL types
	QStringList list;

	//Q_INIT_RESOURCE(qcodeeditor_resources);
	QFile fl(":/styles/QCodeEditor/languages/exprtk.xml");

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

void QExprtkCompleter::AddCompleter(const QString& completer)
{
	auto stringListModel = dynamic_cast<QStringListModel*>(this->model());
	if (stringListModel)
	{
		auto stringList = stringListModel->stringList();
		if (!stringList.contains(completer))
		{
			stringList.push_back(completer);
			stringListModel->setStringList(stringList);
		}
	}
}

void QExprtkCompleter::RemoveCompleter(const QString& completer)
{
	auto stringListModel = dynamic_cast<QStringListModel*>(this->model());
	if (stringListModel)
	{
		auto stringList = stringListModel->stringList();
		if (!stringList.contains(completer))
		{
			stringList.removeOne(completer);
			stringListModel->setStringList(stringList);
		}
	}
}