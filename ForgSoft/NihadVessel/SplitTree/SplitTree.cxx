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

#include <QtGui/QIcon>

ForgBaseLib::SplitTree::SplitTree
(
	FrgBaseMainWindow* parent,
	SurfaceBlockPtr surfaceBlock,
	CurveBlockPtr curveBlock,
	QList<FrgBaseCADScene*> pointerToScenes
)
	: FrgBaseTree(parent)
	, theSurfaceBlock_(surfaceBlock)
	, theCurveBlock_(curveBlock)
	, theParentMainWindow_(parent)
	, thePointerToScenes_(pointerToScenes)
{
	connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemInSplitTreeClickedSlot(QTreeWidgetItem*, int)));

	FormTree();
}

void ForgBaseLib::SplitTree::FormTree()
{
	std::vector<std::shared_ptr<AutLib::TModel_Surface>> surfaces;
	std::vector<std::shared_ptr<AutLib::TModel_Paired>> curves;

	if (theSurfaceBlock_)
		theSurfaceBlock_->RetrieveEntitiesTo(surfaces);

	if(theCurveBlock_)
		theCurveBlock_->RetrieveEntitiesTo(curves);

	for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
	{
		auto item = FrgNew FrgBaseCADPartFeatureEntity<AutLib::TModel_Surface>(QString::number(surfaces[iSurface]->Index()), this);
		item->GetEntity() = surfaces[iSurface];
		item->GetPointerToScenes() = thePointerToScenes_;

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		{
			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
			if(!scene) continue;

			scene->CreateActor(surfaces[iSurface], item);
		}

		//auto item = FrgNew FrgBaseTreeItem(QString::number(surfaces[iSurface]->Index()), FrgNullPtr, this, theParentMainWindow_);
		item->setIcon(0, QIcon(FrgICONTreeItemPartSurface));
		GetItems().push_back(item);
	}
}

void ForgBaseLib::SplitTree::itemInSplitTreeClickedSlot(QTreeWidgetItem* item, int column)
{
	FrgBaseTree::itemClickedSlot(item, column);

	auto tree = dynamic_cast<NihadTree*>(theParentMainWindow_->GetTree());

	if (!tree)
		return;

	tree->itemInSplitTreeClickedSlot(this, item, column);
}