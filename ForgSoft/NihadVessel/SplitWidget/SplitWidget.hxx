#pragma once
#ifndef _SplitWidget_Header
#define _SplitWidget_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QWidget>

class QLineEdit;
class QDockWidget;
class QPushButton;

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

class SplitTree;
class FrgBaseCADScene;

class SplitWidget : public QWidget 
{

	Q_OBJECT

private:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	SplitTree* theTree_ = FrgNullPtr;
	QDockWidget* theDockWidget_ = FrgNullPtr;

	QLineEdit* theNameLineEdit_ = FrgNullPtr;
	QPushButton* theCreateButton_ = FrgNullPtr;
	QPushButton* theCloseButton_ = FrgNullPtr;

	void CloseButtonClickedForSurfaces();
	void CloseButtonClickedForCurves();

public slots:

	void CloseButtonClickedSlot();

public:

	SplitWidget
	(
		FrgString name,
		FrgBaseMainWindow* parentMainWindow,
		SurfaceBlockPtr surfaceBlock,
		CurveBlockPtr curveBlock,
		QList<FrgBaseCADScene*> pointerToScenes,
		FrgBaseCADPart_Entity* parentPart
	);

	FrgGetMacro(QLineEdit*, NameLineEdit, theNameLineEdit_);
	FrgGetMacro(SplitTree*, Tree, theTree_);
	FrgGetMacro(QPushButton*, CreateButton, theCreateButton_);
	FrgGetMacro(QPushButton*, CloseButton, theCloseButton_);
};

EndFrgBaseLib

#endif // !_SplitWidget_Header
