//#include <NihadPartSurfaceEntity.hxx>
//
//#include <NihadVesselPartTreeItem.hxx>
//
//#include <Cad3d_TModel.hxx>
//
//ForgBaseLib::NihadPartSurfaceEntity::NihadPartSurfaceEntity
//(
//	const FrgString& itemName,
//	FrgBaseTreeItem* parentItem,
//	FrgBaseTree* parentTree,
//	FrgBaseMainWindow* parentMainWindow
//)
//	: FrgBaseTreeItem(itemName, parentItem, parentTree, parentMainWindow)
//{
//	this->setIcon(0, QIcon(":/Icons/TreeStyle/Surface.png"));
//}
//
//ForgBaseLib::NihadPartSurfacesEntity::NihadPartSurfacesEntity
//(
//	const FrgString& itemName,
//	FrgBaseTreeItem* parentItem,
//	FrgBaseTree* parentTree,
//	FrgBaseMainWindow* parentMainWindow
//)
//	: FrgBaseTreeItem(itemName, parentItem, parentTree, parentMainWindow)
//{
//	if ((NihadVesselPartTreeItem*)parentTree)
//	{
//		auto model = ((NihadVesselPartTreeItem*)(parentItem))->GetModel();
//
//		if (!model)
//			return;
//
//		std::vector<std::shared_ptr<AutLib::TModel_Surface>> TModelSurfaces;
//		model->RetrieveFacesTo(TModelSurfaces);
//
//		for (int i = 0; i < TModelSurfaces.size(); i++)
//		{
//			theSurfaces_.push_back(FrgNew NihadPartSurfaceEntity(CorrectName<FrgBaseTreeItem>(this, "Surface "), this, parentTree, parentMainWindow));
//			theSurfaces_.at(i)->GetTModelSurface() = TModelSurfaces.at(i);
//		}
//	}
//}