#include <FrgMarine_Scene3D_TItem.hxx>
#include <FrgVisual_Scene.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_GeomParts_TItem.hxx>
#include <FrgMarine_GeomPModels_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgMarine_MainWindow.hxx>

ForgMarineLib::FrgMarine_Scene3D_TItem::FrgMarine_Scene3D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene3D_TItem(itemTitle, parentItem, parentTree)
{
	theScene_->SetLogoText("Tonb");

	theSelectTItems_ = new ForgBaseLib::FrgBase_PrptsVrntSelectTItems
	("Select Parts", dynamic_cast<FrgMarine_Tree*>(GetParentTree())->GetGeometryTItem()->GetParametricModelsTItem());

	thePropertiesPanel_->AddRow(theSelectTItems_);

	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
	{
		myMainWindow->ShowTabWidget(theScene_, parentItem->text(0) + " " + this->text(0));
		connect(parentItem, SIGNAL(TItemNameChanged(const QString&)), this, SLOT(TItemNameToTabTitleChangedSlot(const QString&)));
	}
}

void ForgMarineLib::FrgMarine_Scene3D_TItem::TItemNameToTabTitleChangedSlot(const QString & title)
{
	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
		myMainWindow->SetTabText(theScene_, title + " " + this->text(0));
}

void ForgMarineLib::FrgMarine_Scene3D_TItem::ShowTabWidget()
{
	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
		myMainWindow->ShowTabWidget(theScene_, dynamic_cast<QTreeWidgetItem*>(this)->parent()->text(0) + " " + this->text(0));
}

void ForgMarineLib::FrgMarine_Scene3D_TItem::TItemDoubleClickedSlot()
{
	ShowTabWidget();
}