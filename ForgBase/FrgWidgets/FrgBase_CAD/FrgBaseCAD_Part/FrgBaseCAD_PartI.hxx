#pragma once
#include <FrgBaseCAD_Part.hxx>

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
	: FrgBaseCAD_Part(title, parent)
	, theSurfaceFeatures_(surfaces)
	, theCurveFeatures_(curves)
{
	theSurfaceFeatures_ = FrgNew FrgBaseCADPart_Features<SurfaceEntity>;
	theCurveFeatures_ = FrgNew FrgBaseCADPart_Features<CurveEntity>;

	for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
		theSurfaceFeatures_->AddFeature(surfaces[iSurface]);

	for (int iCurve = 0; iCurve < curves.size(); iCurve++)
		theCurveFeatures_->AddFeature(curves[iCurve]);
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::FrgBaseCAD_Part
(
	const FrgString& title,
	FrgBaseTree* parentTree,
	std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
	std::vector<std::shared_ptr<CurveEntity>> curves
)
	: FrgBaseCAD_Part(title, parentTree)
	, theSurfaceFeatures_(surfaces)
	, theCurveFeatures_(curves)
{
	theSurfaceFeatures_ = FrgNew FrgBaseCADPart_Features<SurfaceEntity>;
	theCurveFeatures_ = FrgNew FrgBaseCADPart_Features<CurveEntity>;

	for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
		theSurfaceFeatures_->AddFeature(surfaces[iSurface]);

	for (int iCurve = 0; iCurve < curves.size(); iCurve++)
		theCurveFeatures_->AddFeature(curves[iCurve]);
}

template<class SurfaceEntity, class CurveEntity>
inline void ForgBaseLib::FrgBaseCAD_Part<SurfaceEntity, CurveEntity>::DoAfterConstruct()
{
}