#pragma once
#ifndef _SelectObjectsPropertyWidget_Header
#define _SelectObjectsPropertyWidget_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QWidget>

class QLabel;
class QTreeWidgetItem;

BeginFrgBaseLib

class SelectObjectsPropertyWidget : public QWidget
{

	Q_OBJECT

public:

	SelectObjectsPropertyWidget(QWidget* parent = FrgNullPtr, QTreeWidgetItem* treeItemSelection = FrgNullPtr);

	void SetObjectsLabel(QList<QTreeWidgetItem*> value);

signals:

	void LabelChanged(const QList<QTreeWidgetItem*>& filePath);

private slots:

	void buttonClicked();

private:

	QLabel* theLabel_ = FrgNullPtr;

	QTreeWidgetItem* theTreeItemSelection_;
};

EndFrgBaseLib

#endif // !_SelectObjectsPropertyWidget_Header
