#include <FrgMarine_Scene3D_TItem.hxx>
#include <FrgVisual_Scene3D.hxx>
#include <FrgVisual_Scene.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_GeomParts_TItem.hxx>
#include <FrgMarine_GeomPModels_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgMarine_MainWindow.hxx>

#include <FrgVisual_BoxActor.hxx>
#include <FrgVisual_LineActor.hxx>
#include <FrgVisual_MeshActor.hxx>
#include <FrgVisual_GridActor.hxx>

ForgMarineLib::FrgMarine_Scene3D_TItem::FrgMarine_Scene3D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene3D_TItem(itemTitle, parentItem, parentTree)
{
	theSelectTItems_ = new ForgBaseLib::FrgBase_PrptsVrntSelectTItems
	("Select Parts", dynamic_cast<FrgMarine_Tree*>(GetParentTree())->GetGeometryTItem()->GetParametricModelsTItem());

	thePropertiesPanel_->AddRow(theSelectTItems_);

	/*auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
	{
		myMainWindow->ShowTabWidget(theScene_, parentItem->text(0) + " " + this->text(0));
		connect(parentItem, SIGNAL(TItemNameChanged(const QString&)), this, SLOT(TItemNameToTabTitleChangedSlot(const QString&)));
	}*/
}

void ForgMarineLib::FrgMarine_Scene3D_TItem::FormTItem()
{
	FrgVisual_Scene3D_TItem::FormTItem();
	theScene_->SetLogoText("Tonb");
}/*

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
}*/

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_Scene3D_TItem)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene3D_TItem>(*this);
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_Scene3D_TItem)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene3D_TItem>(*this);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Scene3D_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Scene3D_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Scene3D_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Scene3D_TItem);
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_Scene3D_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_Scene3D_TItem)

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene3D)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BoxActor)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_LineActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_LineActor<3>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshActor<3>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_GridActor)