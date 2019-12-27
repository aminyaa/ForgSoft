#pragma once

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::CAD_PartItem<SurfaceEntity, CurveEntity>::CAD_PartItem
(
	const FrgString & title,
	FrgBaseTreeItem * parent,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
)
	: FrgBaseCAD_Part<SurfaceEntity, CurveEntity>(title, parent)
	, theModel_(model)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::CAD_PartItem<SurfaceEntity, CurveEntity>::CAD_PartItem
(
	const FrgString & title,
	FrgBaseTree * parentTree,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
)
	: FrgBaseCAD_Part<SurfaceEntity, CurveEntity>(title, parent)
	, theModel_(model)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline void ForgBaseLib::CAD_PartItem<SurfaceEntity, CurveEntity>::DoAfterConstruct()
{
	std::vector<std::shared_ptr<SurfaceEntity>> blocksForSurfaces;
	std::vector<std::shared_ptr<CurveEntity>> blocksForCurves;
	theModel_->Faces()->RetrieveTo(blocksForSurfaces);
	theModel_->Segments()->RetrieveTo(blocksForCurves);

	FrgBaseCAD_Part::ConstructWithEntities(blocksForSurfaces, blocksForCurves);

	if (!this->GetContextMenu()->GetItems().isEmpty())
		this->GetContextMenu()->addSeparator();

	FrgString ExportPartString = "&Export";
	this->GetContextMenu()->AddItem(ExportPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(ExportPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(ExportPartSlot(bool))
	);

	FrgString AnalyzePartString = "Analyze Part";
	this->GetContextMenu()->AddItem(AnalyzePartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(AnalyzePartString)
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(AnalyzePartSlot(bool))
	);
}