#pragma once
//#include <FrgBaseCAD_Part.hxx>
#include <FrgBaseCADPart_Features.hxx>

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::FrgBaseCAD_Part
(
	const FrgString& title,
	FrgBaseTreeItem* parent
)
	: FrgBaseCAD_Part_Base(title, parent)
{

}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::FrgBaseCAD_Part
(
	const FrgString& title,
	FrgBaseTree* parentTree
)
	: FrgBaseCAD_Part_Base(title, parentTree)
{

}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::FrgBaseCAD_Part
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
	std::vector<std::shared_ptr<CurveEntity>> curves
)
	: FrgBaseCAD_Part_Base(title, parent)
{
	ConstructWithEntities(surfaces, curves);
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::FrgBaseCAD_Part
(
	const FrgString& title,
	FrgBaseTree* parentTree,
	std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
	std::vector<std::shared_ptr<CurveEntity>> curves
)
	: FrgBaseCAD_Part_Base(title, parentTree)
{
	ConstructWithEntities(surfaces, curves);
}

template<class SurfaceEntity, class CurveEntity>
inline void ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::DoAfterConstruct()
{
}

template<class SurfaceEntity, class CurveEntity>
inline void ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::ConstructWithEntities
(
	std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
	std::vector<std::shared_ptr<CurveEntity>> curves
)
{
	theSurfaceFeatures_ = FrgNew FrgBaseCADPart_Features<SurfaceEntity>("Surfaces", this, this);
	theCurveFeatures_ = FrgNew FrgBaseCADPart_Features<CurveEntity>("Curves", this, this);

	for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
	{
		auto feature = theSurfaceFeatures_->AddFeature(surfaces[iSurface]);
		feature->DoAfterConstruct();
		feature->GetParentFeatures() = theSurfaceFeatures_;
		feature->setIcon(0, QIcon(FrgICONTreeItemPartSurface));
	}

	for (int iCurve = 0; iCurve < curves.size(); iCurve++)
	{
		auto feature = theCurveFeatures_->AddFeature(curves[iCurve]);
		feature->DoAfterConstruct();
		feature->GetParentFeatures() = theCurveFeatures_;
		feature->setIcon(0, QIcon(FrgICONTreeItemPartCurve));
	}
}