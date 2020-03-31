#pragma once
#ifndef _FrgMarine_HStaticsCrossCurves_TItem_Header
#define _FrgMarine_HStaticsCrossCurves_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_AnalysisHStatics_TItem.hxx>
#include <FrgBase_PrptsVrntSelectTItems.hxx>

#include <Entity3d_BoxFwd.hxx>

class TopoDS_Shape;

namespace tnbLib
{
	class HydroStatic_CrossCurves;
}

BeginForgMarineLib

class FrgMarine_CrossCurvesModel_TItem;
class FrgMarine_CrossCurvesDomain_TItem;
class FrgMarine_CrossCurvesHeel_TItem;

class FORGMARINE_EXPORT FrgMarine_HStaticsCrossCurves_TItem
	: public FrgMarine_AnalysisHStatics_TItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntSelectTItems* ShapeVrnt READ GetShapeVrnt WRITE SetShapeVrnt)

public:

	FrgMarine_HStaticsCrossCurves_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgMarine_HStaticsCrossCurves_TItem();

	ForgBaseLib::FrgBase_PrptsVrntSelectTItems* GetShapeVrnt() const { return theShapeVrnt_; }
	void SetShapeVrnt(ForgBaseLib::FrgBase_PrptsVrntSelectTItems* shape) { theShapeVrnt_ = shape; }

private:

	std::shared_ptr<tnbLib::HydroStatic_CrossCurves> theCrossCurve_;
	TopoDS_Shape* theShape_ = nullptr;
	tnbLib::Entity3d_Box* theBox_ = nullptr;

	ForgBaseLib::FrgBase_PrptsVrntSelectTItems* theShapeVrnt_ = nullptr;

	FrgMarine_CrossCurvesModel_TItem* theModelTItem_ = nullptr;
	FrgMarine_CrossCurvesDomain_TItem* theDomainTItem_ = nullptr;
	FrgMarine_CrossCurvesHeel_TItem* theHeelTItem_ = nullptr;

private slots:

	void ShapeVrntChangedSlot(std::vector<QTreeWidgetItem*> item);
	void PerformCrossCurvesSlot();
};

EndForgMarineLib

#endif // !_FrgMarine_HStaticsCrossCurves_TItem_Header
