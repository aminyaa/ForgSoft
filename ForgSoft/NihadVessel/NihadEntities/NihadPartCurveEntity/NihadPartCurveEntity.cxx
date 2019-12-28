//#include <NihadPartCurveEntity.hxx>
//
//#include <NihadVesselPartTreeItem.hxx>
//
//#include <Cad3d_TModel.hxx>
//
//ForgBaseLib::NihadPartCurveEntity::NihadPartCurveEntity
//(
//	const FrgString& itemName,
//	FrgBaseTreeItem* parentItem,
//	FrgBaseTree* parentTree,
//	FrgBaseMainWindow* parentMainWindow
//)
//	: FrgBaseTreeItem(itemName, parentItem, parentTree, parentMainWindow)
//{
//	this->setIcon(0, QIcon(":/Icons/TreeStyle/Curve.png"));
//}
//
//ForgBaseLib::NihadPartCurvesEntity::NihadPartCurvesEntity
//(
//	const FrgString& itemName,
//	FrgBaseTreeItem* parentItem,
//	FrgBaseTree* parentTree,
//	FrgBaseMainWindow* parentMainWindow
//)
//	: FrgBaseTreeItem (itemName, parentItem, parentTree, parentMainWindow)
//{
//	if ((NihadVesselPartTreeItem*)parentTree)
//	{
//		auto model = ((NihadVesselPartTreeItem*)(parentItem))->GetModel();
//
//		if (!model)
//			return;
//
//		std::vector<std::shared_ptr<AutLib::TModel_Paired>> TModelCurves;
//		model->RetrieveSegmentsTo(TModelCurves);
//
//		for (int i = 0; i < TModelCurves.size(); i++)
//		{
//			theCurves_.push_back(FrgNew NihadPartCurveEntity(CorrectName<FrgBaseTreeItem>(this, "Curve "), this, parentTree, parentMainWindow));
//			theCurves_.at(i)->GetTModelCurve() = TModelCurves.at(i);
//		}
//	}
//}