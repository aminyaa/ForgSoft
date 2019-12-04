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

	QList<FrgBaseCADScene*> thePointerToScenes_;

public:

	SplitTree
	(
		FrgBaseMainWindow* parent,
		SurfaceBlockPtr surfaceBlock,
		CurveBlockPtr curveBlock,
		QList<FrgBaseCADScene*> pointerToScenes
	);

	virtual void FormTree() override;

private slots:

	void itemInSplitTreeClickedSlot(QTreeWidgetItem*, int);

};

EndFrgBaseLib

#endif // !_SplitTree_Header
