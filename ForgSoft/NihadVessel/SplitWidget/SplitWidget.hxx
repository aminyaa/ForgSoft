#pragma once
#ifndef _SplitWidget_Header
#define _SplitWidget_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QWidget>

class QLineEdit;
class QDockWidget;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QLabel;

namespace AutLib
{
	template <class Entity>
	class Cad_BlockEntity;

	class TModel_Surface;
	class TModel_Paired;
}

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseCADPart_Entity;

typedef AutLib::Cad_BlockEntity<AutLib::TModel_Surface> SurfaceBlock;
typedef std::shared_ptr<SurfaceBlock> SurfaceBlockPtr;
typedef AutLib::Cad_BlockEntity<AutLib::TModel_Paired> CurveBlock;
typedef std::shared_ptr<CurveBlock> CurveBlockPtr;

template<class Entity>
class SplitTree;
class FrgBaseCADScene;

class SplitWidget_Base : public QWidget
{

	struct WidgetItemsStruct
	{
		QVBoxLayout* theMainLayout_ = FrgNullPtr;
		QHBoxLayout* theNameLayout_ = FrgNullPtr;
		QHBoxLayout* theButtonsLayout_ = FrgNullPtr;
		QLabel* theNameLabel_ = FrgNullPtr;
		QWidget* theMainWidget_ = FrgNullPtr;
	};

	Q_OBJECT

protected:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
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

template<class Entity>
class SplitWidget : protected SplitWidget_Base
{

private:

	SplitTree<Entity>* theTree_ = FrgNullPtr;

	const std::shared_ptr<AutLib::Cad_EntityManager<Entity>>& GetManager() const;

	/*FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	SplitTree* theTree_ = FrgNullPtr;
	QDockWidget* theDockWidget_ = FrgNullPtr;

	QLineEdit* theNameLineEdit_ = FrgNullPtr;
	QPushButton* theCreateButton_ = FrgNullPtr;
	QPushButton* theCloseButton_ = FrgNullPtr;

	WidgetItemsStruct* theWidgetItems_ = FrgNullPtr;*/

	virtual void CloseButtonClicked() override;

public:

	SplitWidget
	(
		FrgString name,
		FrgBaseMainWindow* parentMainWindow,
		QList<FrgBaseCADScene*> pointerToScenes,
		FrgBaseCADPart_Entity* parentPart
	);

	~SplitWidget();

	FrgGetMacro(QLineEdit*, NameLineEdit, theNameLineEdit_);
	FrgGetMacro(SplitTree*, Tree, theTree_);
	FrgGetMacro(QPushButton*, CreateButton, theCreateButton_);
	FrgGetMacro(QPushButton*, CloseButton, theCloseButton_);
};

EndFrgBaseLib

#include <SplitWidgetI.hxx>

#endif // !_SplitWidget_Header
