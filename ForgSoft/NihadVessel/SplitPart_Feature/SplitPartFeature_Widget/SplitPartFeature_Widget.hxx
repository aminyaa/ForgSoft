#pragma once
#ifndef _SplitPartFeature_Widget_Header
#define _SplitPartFeature_Widget_Header

#include <FrgBaseGlobals.hxx>
#include <QtWidgets/QWidget>
#include <SplitPartFeature_Traits.hxx>

class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class QDockWidget;

BeginFrgBaseLib

class FrgBaseMainWindow;

class SplitPartFeature_Widget_Base
	: public QWidget
{
	Q_OBJECT

protected:

	struct WidgetItemsStruct
	{
		QVBoxLayout* theMainLayout_ = FrgNullPtr;
		QHBoxLayout* theNameLayout_ = FrgNullPtr;
		QHBoxLayout* theButtonsLayout_ = FrgNullPtr;
		QLabel* theNameLabel_ = FrgNullPtr;
		QWidget* theMainWidget_ = FrgNullPtr;
	};

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	QDockWidget* theDockWidget_ = FrgNullPtr;
	QLineEdit* theNameLineEdit_ = FrgNullPtr;
	QPushButton* theCreateButton_ = FrgNullPtr;
	QPushButton* theCloseButton_ = FrgNullPtr;
	WidgetItemsStruct* theWidgetItems_ = FrgNullPtr;

public:

	SplitPartFeature_Widget_Base
	(
		FrgBaseMainWindow* parentMainWindow
	);

	FrgGetMacro(QLineEdit*, NameLineEdit, theNameLineEdit_);

	virtual void CloseButtonClicked() {}

public slots:

	void CloseButtonClickedSlot();
};

template<class T>
class SplitPartFeature_Tree;

template<class T>
class FrgBaseCADPart_Feature;

template<class BlockEntity>
class SplitPartFeature_Widget
	: public SplitPartFeature_Widget_Base
{

private:

	SplitPartFeature_Tree<BlockEntity>* theTree_ = FrgNullPtr;
	std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> thePartManager_;

public:

	SplitPartFeature_Widget
	(
		FrgBaseMainWindow* parentMainWindow,
		FrgBaseCADPart_Feature<BlockEntity>* partFeature
	);

	void SetManager(std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager);

	FrgGetMacro(std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager>, PartManager, thePartManager_);

	void CloseButtonClicked() override;
};

EndFrgBaseLib

#include <SplitPartFeature_WidgetI.hxx>

#endif // !_SplitPartFeature_Widget_Header
