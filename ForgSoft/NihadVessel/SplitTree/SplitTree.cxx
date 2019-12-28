#include <SplitTree.hxx>
#include <FrgBaseCADPart.hxx>
#include <Cad_BlockEntity.hxx>
#include <TModel_Surface.hxx>
#include <TModel_Paired.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseCADScene.hxx>
#include <CADScene.hxx>
#include <NihadTree.hxx>
#include <SplitWidget.hxx>
#include <FrgBaseCADPart.hxx>
#include <CADPartItem.hxx>

#include <vtkActor.h>
#include <vtkRenderWindow.h>

#include <QtGui/QIcon>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDockWidget>

ForgBaseLib::SplitTree_Base::SplitTree_Base
(
	FrgBaseMainWindow* parent,
	QList<FrgBaseCADScene*> pointerToScenes,
	FrgBaseCADPart_Entity* parentPart
)
	: FrgBaseTree(parent)
	, theParentMainWindow_(parent)
	, thePointerToScenes_(pointerToScenes)
	, theParentPart_(parentPart)
{
}

//void ForgBaseLib::SplitTree_Base::FormTree()
//{
//	std::vector<std::shared_ptr<AutLib::TModel_Surface>> surfaces;
//	std::vector<std::shared_ptr<AutLib::TModel_Paired>> curves;
//
//	if (theSurfaceBlock_)
//		theSurfaceBlock_->RetrieveEntitiesTo(surfaces);
//
//	if (theCurveBlock_)
//		theCurveBlock_->RetrieveEntitiesTo(curves);
//
//	for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
//		if (!(thePointerToScenes_[iScene]->GetActors().isEmpty()))
//			for (int i = 0; i < thePointerToScenes_[iScene]->GetActors().size(); i++)
//				thePointerToScenes_[iScene]->GetActors()[i]->SetVisibility(false);
//
//	for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
//	{
//		auto item = FrgNew FrgBaseCADPartFeatureEntity<AutLib::TModel_Surface>(QString::number(surfaces[iSurface]->Index()), this);
//		item->GetEntity() = surfaces[iSurface];
//		item->GetPointerToScenes() = thePointerToScenes_;
//
//		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
//		{
//			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
//			if (!scene) continue;
//
//			scene->CreateActor(surfaces[iSurface], item);
//			scene->GetParentTree() = this;
//		}
//
//		//auto item = FrgNew FrgBaseTreeItem(QString::number(surfaces[iSurface]->Index()), FrgNullPtr, this, theParentMainWindow_);
//		item->setIcon(0, QIcon(FrgICONTreeItemPartSurface));
//		GetItems().push_back(item);
//	}
//
//	for (int iCurve = 0; iCurve < curves.size(); iCurve++)
//	{
//		auto item = FrgNew FrgBaseCADPartFeatureEntity<AutLib::TModel_Paired>(QString::number(curves[iCurve]->Index()), this);
//		item->GetEntity() = curves[iCurve];
//		item->GetPointerToScenes() = thePointerToScenes_;
//
//		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
//		{
//			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
//			if (!scene) continue;
//
//			scene->CreateActor(curves[iCurve], item);
//			scene->GetParentTree() = this;
//		}
//
//		//auto item = FrgNew FrgBaseTreeItem(QString::number(surfaces[iSurface]->Index()), FrgNullPtr, this, theParentMainWindow_);
//		item->setIcon(0, QIcon(FrgICONTreeItemPartCurve));
//		GetItems().push_back(item);
//	}
//}

void ForgBaseLib::SplitTree_Base::itemInSplitTreeClickedSlot(QTreeWidgetItem* item, int column)
{
	FrgBaseTree::itemClickedSlot(item, column);

	auto tree = dynamic_cast<NihadTree*>(theParentMainWindow_->GetTree());

	if (!tree)
		return;

	tree->itemInSplitTreeClickedSlot(this, item, column);
}

void ForgBaseLib::SplitTree_Base::CreateButtonClickedSlot()
{
	CreateButtonClicked();
}