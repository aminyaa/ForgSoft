#pragma once
#include <FrgBaseMenu.hxx>
#include <FrgBaseTree.hxx>

#include <Cad3d_TModel.hxx>

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::CADPartItem<SurfaceEntity, CurveEntity>::CADPartItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
) : FrgBaseCADPart(title, parent)
, theModel_(model)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::CADPartItem<SurfaceEntity, CurveEntity>::CADPartItem
(
	const FrgString& title,
	FrgBaseTree* parentTree,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
) : FrgBaseCADPart(title, parentTree)
, theModel_(model)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline void ForgBaseLib::CADPartItem<SurfaceEntity, CurveEntity>::DoAfterConstruct()
{
	//std::vector<std::shared_ptr<SurfaceEntity>> surfaceVector;
	//std::vector<std::shared_ptr<CurveEntity>> curveVector;

	std::vector<std::shared_ptr<AutLib::Cad_BlockEntity<AutLib::TModel_Entity>>> blocksForSurfaces;
	std::vector<std::shared_ptr<AutLib::Cad_BlockEntity<AutLib::TModel_Entity>>> blocksForCurves;
	theModel_->Faces()->RetrieveTo(blocksForSurfaces);
	theModel_->Segments()->RetrieveTo(blocksForCurves);

	//surfaceVector.push_back(blocksForSurfaces);
	//curveVector.push_back(blocksForCurves);
	/*for (int iSurface = 0; iSurface < blocksForSurfaces.size(); iSurface++)
		GetSurfaces().push_back(std::dynamic_pointer_cast<SurfaceEntity>(blocksForSurfaces[iSurface]));
	for (int iCurve = 0; iCurve < blocksForCurves.size(); iCurve++)
		GetCurves().push_back(std::dynamic_pointer_cast<CurveEntity>(blocksForCurves[iCurve]));*/

	//GetSurfaces() = blocksForSurfaces;
	//GetCurves() = blocksForCurves;

	FrgString ExportPartString = "&Export";
	this->GetContextMenu()->AddItem(ExportPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(ExportPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(ExportPartSlot(bool))
	);

	FrgString SplitByPatchPartString = "&Split By Patch";
	this->GetContextMenu()->AddItem(SplitByPatchPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(SplitByPatchPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(SplitByPatchPartSlot(bool))
	);

	FrgBaseCADPart::DoAfterConstruct();
}