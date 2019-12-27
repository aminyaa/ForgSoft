#pragma once
#ifndef _FrgBaseCAD_Part_Header
#define _FrgBaseCAD_Part_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

BeginFrgBaseLib

class FrgBaseTree;

class FORGBASE_EXPORT FrgBaseCAD_Part_Base
	: public QObject
	, public FrgBaseTreeItem
{
	Q_OBJECT

public:

	FrgBaseCAD_Part_Base
	(
		const FrgString& title,
		FrgBaseTreeItem* parent
	);

	FrgBaseCAD_Part_Base
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	);

	virtual ~FrgBaseCAD_Part_Base() {}

	void DoAfterConstruct() override;
};

template<class T>
class FrgBaseCADPart_Features;

template<class SurfaceEntity, class CurveEntity>
class FrgBaseCAD_Part
	: public FrgBaseCAD_Part_Base
{

private:

	FrgBaseCADPart_Features<SurfaceEntity>* theSurfaceFeatures_;
	FrgBaseCADPart_Features<CurveEntity>* theCurveFeatures_;

public:

	FrgBaseCAD_Part
	(
		const FrgString& title,
		FrgBaseTreeItem* parent
	);

	FrgBaseCAD_Part
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	);

	FrgBaseCAD_Part
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
		std::vector<std::shared_ptr<CurveEntity>> curves
	);

	FrgBaseCAD_Part
	(
		const FrgString& title,
		FrgBaseTree* parentTree,
		std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
		std::vector<std::shared_ptr<CurveEntity>> curves
	);

	void ConstructWithEntities(std::vector<std::shared_ptr<SurfaceEntity>> surfaces, std::vector<std::shared_ptr<CurveEntity>> curves);

	FrgGetMacro(FrgBaseCADPart_Features<SurfaceEntity>*, SurfacesFeatures, theSurfaceFeatures_);
	FrgGetMacro(FrgBaseCADPart_Features<CurveEntity>*, CurvesFeatures, theCurveFeatures_);

	void DoAfterConstruct() override;
};

EndFrgBaseLib

#include <FrgBaseCAD_PartI.hxx>

#endif // !_FrgBaseCAD_Part_Header
