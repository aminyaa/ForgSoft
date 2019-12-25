#pragma once
#ifndef _SplitWidget_Header
#define _SplitWidget_Header

#include <FrgBaseGlobals.hxx>
#include <SplitTree_Traits.hxx>

#include <QtWidgets/QWidget>

class QLineEdit;
class QDockWidget;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QLabel;

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseCADPart_Entity;
class FrgBaseCADScene;

class SplitWidget_Base : public QWidget
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
	QList<FrgBaseCADScene*> thePointerToScenes_;
	QDockWidget* theDockWidget_ = FrgNullPtr;

	QLineEdit* theNameLineEdit_ = FrgNullPtr;
	QPushButton* theCreateButton_ = FrgNullPtr;
	QPushButton* theCloseButton_ = FrgNullPtr;

	WidgetItemsStruct* theWidgetItems_ = FrgNullPtr;

public:

	SplitWidget_Base
	(
		FrgString name,
		FrgBaseMainWindow* parentMainWindow,
		QList<FrgBaseCADScene*> pointerToScenes,
		FrgBaseCADPart_Entity* parentPart
	);

public slots:

	void CloseButtonClickedSlot();

protected:

	virtual void CloseButtonClicked() {}
};

template<class T>
class FrgBaseCADPartFeatureEntity;

template<class T>
class SplitTree;

template<class BlockEntity>
class SplitWidget : public SplitWidget_Base
{

private:

	SplitTree<BlockEntity>* theTree_ = FrgNullPtr;

	//const std::shared_ptr<AutLib::Cad_EntityManager<Entity>>& GetManager() const;

	/*FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	SplitTree* theTree_ = FrgNullPtr;
	QDockWidget* theDockWidget_ = FrgNullPtr;

	QLineEdit* theNameLineEdit_ = FrgNullPtr;
	QPushButton* theCreateButton_ = FrgNullPtr;
	QPushButton* theCloseButton_ = FrgNullPtr;

	WidgetItemsStruct* theWidgetItems_ = FrgNullPtr;*/

	void CloseButtonClicked() override;

public:

	SplitWidget
	(
		FrgString name,
		FrgBaseMainWindow* parentMainWindow,
		FrgBaseCADPartFeatureEntity<BlockEntity>* featureEntity,
		std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager,
		QList<FrgBaseCADScene*> pointerToScenes,
		FrgBaseCADPart_Entity* parentPart
	);

	~SplitWidget() {}

	FrgGetMacro(QLineEdit*, NameLineEdit, theNameLineEdit_);
	FrgGetMacro(SplitTree<BlockEntity>*, Tree, theTree_);
	FrgGetMacro(QPushButton*, CreateButton, theCreateButton_);
	FrgGetMacro(QPushButton*, CloseButton, theCloseButton_);
};

EndFrgBaseLib

#include <SplitWidgetI.hxx>

#endif // !_SplitWidget_Header
