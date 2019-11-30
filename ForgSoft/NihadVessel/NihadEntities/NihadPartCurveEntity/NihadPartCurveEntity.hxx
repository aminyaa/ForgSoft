//#pragma once
//#ifndef _NihadPartCurveEntity_Header
//#define _NihadPartCurveEntity_Header
//
//#include <FrgBaseGlobals.hxx>
//#include <FrgBaseTreeItem.hxx>
//#include <NihadPartFeature.hxx>
//
//namespace AutLib
//{
//	class TModel_Paired;
//}
//
//BeginFrgBaseLib
//
//class NihadVesselScenePartTreeItem;
//
//class NihadPartCurveEntity : public NihadPartFeature, public FrgBaseTreeItem
//{
//
//	Q_OBJECT
//
//private:
//
//	FrgSharedPtr<AutLib::TModel_Paired> theTModelCurve_ = FrgNullPtr;
//
//	NihadVesselScenePartTreeItem* thePointerToScene_ = FrgNullPtr;
//
//public:
//
//	NihadPartCurveEntity
//	(
//		const FrgString& itemName,
//		FrgBaseTreeItem* parentItem = FrgNullPtr,
//		FrgBaseTree* parentTree = FrgNullPtr,
//		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
//	);
//
//	FrgGetMacro(FrgSharedPtr<AutLib::TModel_Paired>, TModelCurve, theTModelCurve_);
//	FrgGetMacro(NihadVesselScenePartTreeItem*, PointerToScene, thePointerToScene_);
//};
//
//class NihadPartCurvesEntity : public FrgBaseTreeItem
//{
//
//private:
//
//	QList<NihadPartCurveEntity*> theCurves_;
//
//public:
//
//	NihadPartCurvesEntity
//	(
//		const FrgString& itemName,
//		FrgBaseTreeItem* parentItem = FrgNullPtr,
//		FrgBaseTree* parentTree = FrgNullPtr,
//		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
//	);
//
//	FrgGetMacro(QList<NihadPartCurveEntity*>, CurvesEntity, theCurves_);
//};
//
//EndFrgBaseLib
//
//#endif // !_NihadPartCurveEntity_Header
