#pragma once
#ifndef _SplitTree_Header
#define _SplitTree_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTree.hxx>

namespace AutLib
{
	template <class Entity>
	class Cad_BlockEntity;

	class TModel_Surface;
	class TModel_Paired;
}

BeginFrgBaseLib

class FrgBaseCADPart_Entity;
class FrgBaseMainWindow;
class FrgBaseCADScene;
class SplitWidget;
class FrgBaseCADPart_Entity;

typedef AutLib::Cad_BlockEntity<AutLib::TModel_Surface> SurfaceBlock;
typedef std::shared_ptr<SurfaceBlock> SurfaceBlockPtr;
typedef AutLib::Cad_BlockEntity<AutLib::TModel_Paired> CurveBlock;
typedef std::shared_ptr<CurveBlock> CurveBlockPtr;

class SplitTree : public FrgBaseTree
{

	Q_OBJECT

private:

	SurfaceBlockPtr theSurfaceBlock_ = FrgNullPtr;
	CurveBlockPtr theCurveBlock_ = FrgNullPtr;

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	SplitWidget* theParentSplitWidget_ = FrgNullPtr;
	FrgBaseCADPart_Entity* theParentPart_ = FrgNullPtr;

	QList<FrgBaseCADScene*> thePointerToScenes_;

public:

	SplitTree
	(
		FrgBaseMainWindow* parent,
		SurfaceBlockPtr surfaceBlock,
		CurveBlockPtr curveBlock,
		QList<FrgBaseCADScene*> pointerToScenes,
		SplitWidget* parentSplitWidget,
		FrgBaseCADPart_Entity* parentPart
	);

	virtual void FormTree() override;

	FrgGetMacro(FrgBaseCADPart_Entity*, ParentPart, theParentPart_);
	FrgGetMacro(SurfaceBlockPtr, SurfaceBlock, theSurfaceBlock_);
	FrgGetMacro(CurveBlockPtr, CurveBlock, theCurveBlock_);
	FrgGetMacro(QList<FrgBaseCADScene*>, PointerToScenes, thePointerToScenes_);

private slots:

	void itemInSplitTreeClickedSlot(QTreeWidgetItem*, int);

private slots:

	void CreateButtonClickedSlot();

};

EndFrgBaseLib

#endif // !_SplitTree_Header
