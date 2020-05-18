#pragma once
#ifndef _FrgMarine_HStaticsCrossCurves_TItem_Header
#define _FrgMarine_HStaticsCrossCurves_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_AnalysisHStatics_TItem.hxx>
//#include <FrgBase_PrptsVrntSelectTItems.hxx>
//#include <FrgBase_PrptsVrntCombo.hxx>
#include <QtCore/QMetaType>
#include <FrgBase_PrptsVrntSelectTItem.hxx>

#include <Entity3d_BoxFwd.hxx>

namespace ForgMarineLib
{
	class FrgMarine_GeomPModel_TItem;
}

Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntSelectTItem<ForgMarineLib::FrgMarine_GeomPModel_TItem>*)

class TopoDS_Shape;

namespace tnbLib
{
	class HydroStatic_CrossCurves;
	class Marine_CmpSection;
}

BeginForgMarineLib

class FrgMarine_CrossCurvesModel_TItem;
class FrgMarine_CrossCurvesDomain_TItem;
class FrgMarine_CrossCurvesHeel_TItem;
class FrgMarine_HStaticsCrossCurvesPView_TItem;
class FrgMarine_Scene3D_TItem;

class FORGMARINE_EXPORT FrgMarine_HStaticsCrossCurves_TItem
	: public FrgMarine_AnalysisHStatics_TItem
{
	Q_OBJECT

	//Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntSelectTItems* ShapeVrnt READ GetShapeVrnt WRITE SetShapeVrnt)
	//Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntCombo* ShapeVrnt READ GetShapeVrnt WRITE SetShapeVrnt)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntSelectTItem<ForgMarineLib::FrgMarine_GeomPModel_TItem>* ShapeVrnt READ GetShapeVrnt WRITE SetShapeVrnt)

public:

	FrgMarine_HStaticsCrossCurves_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgMarine_HStaticsCrossCurves_TItem();

	/*ForgBaseLib::FrgBase_PrptsVrntSelectTItems* GetShapeVrnt() const { return theShapeVrnt_; }
	void SetShapeVrnt(ForgBaseLib::FrgBase_PrptsVrntSelectTItems* shape) { theShapeVrnt_ = shape; }*/

	/*ForgBaseLib::FrgBase_PrptsVrntCombo* GetShapeVrnt() const { return theShapeVrnt_; }
	void SetShapeVrnt(ForgBaseLib::FrgBase_PrptsVrntCombo* shape) { theShapeVrnt_ = shape; }*/

	ForgBaseLib::FrgBase_PrptsVrntSelectTItem<ForgMarineLib::FrgMarine_GeomPModel_TItem>* GetShapeVrnt() const { return theShapeVrnt_; }
	void SetShapeVrnt(ForgBaseLib::FrgBase_PrptsVrntSelectTItem<ForgMarineLib::FrgMarine_GeomPModel_TItem>* shape) { theShapeVrnt_ = shape; }

private:

	std::shared_ptr<tnbLib::HydroStatic_CrossCurves> theCrossCurve_;
	TopoDS_Shape* theShape_ = nullptr;
	tnbLib::Entity3d_Box* theBox_ = nullptr;

	ForgBaseLib::FrgBase_PrptsVrntSelectTItem<ForgMarineLib::FrgMarine_GeomPModel_TItem>* theShapeVrnt_ = nullptr;

	FrgMarine_CrossCurvesModel_TItem* theModelTItem_ = nullptr;
	FrgMarine_CrossCurvesDomain_TItem* theDomainTItem_ = nullptr;
	FrgMarine_CrossCurvesHeel_TItem* theHeelTItem_ = nullptr;
	FrgMarine_HStaticsCrossCurvesPView_TItem* thePreviewTItem_ = nullptr;

	//std::map<QString, QTreeWidgetItem*> theMapFromNameToTItem_;

	void DrawSections
	(
		std::vector<std::shared_ptr<tnbLib::Marine_CmpSection>> sections,
		double red,
		double green,
		double blue
	);

	void DrawBox(tnbLib::Entity3d_Box* box, double red, double green, double blue);

	void ClearSections();

private slots:

	void ShapeVrntChangedSlot(FrgBase_TreeItem* tItem);
	void PerformCrossCurvesSlot();
};

EndForgMarineLib

#endif // !_FrgMarine_HStaticsCrossCurves_TItem_Header
