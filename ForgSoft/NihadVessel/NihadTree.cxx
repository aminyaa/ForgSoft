#include <NihadTree.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseMenu.hxx>
#include <FrgBaseMainWindow.hxx>
#include <NihadVesselSceneTreeItem.hxx>

#include <QtWidgets/QAction>

ForgBaseLib::NihadTree::NihadTree(FrgBaseMainWindow* parent)
	: FrgBaseTree(parent)
{
}

void ForgBaseLib::NihadTree::FormTree()
{
	FrgString GeometryItem = "Geometry";
	FrgString PartsItem = "Parts";
	FrgString ScenesItem = "Scenes";
	FrgString PlotsItem = "Plots";

	GetItems().push_back(FrgNew FrgBaseTreeItem(GeometryItem, FrgNullPtr, this, GetParentMainWindow()));

	GetItems().push_back(FrgNew FrgBaseTreeItem(PartsItem, FrgNullPtr, this, GetParentMainWindow()));

	GetItems().push_back(FrgNew FrgBaseTreeItem(ScenesItem, FrgNullPtr, this, GetParentMainWindow()));

	GetItems().push_back(FrgNew FrgBaseTreeItem(PlotsItem, FrgNullPtr, this, GetParentMainWindow()));

	FrgString GeometryNewMenu = "&New Geometry";
	GetTreeItem(GeometryItem)->GetContextMenu()->AddItem(GeometryNewMenu);
	connect(GetTreeItem(GeometryItem)->GetContextMenu()->GetItem(GeometryNewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(NewGeometryClickedSlot(bool)));

	FrgString ScenesNewMenu = "&New Scene";
	GetTreeItem(ScenesItem)->GetContextMenu()->AddItem(ScenesNewMenu);
	connect(GetTreeItem(ScenesItem)->GetContextMenu()->GetItem(ScenesNewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(NewSceneClickedSlot(bool)));
}

void ForgBaseLib::NihadTree::NewGeometryClickedSlot(bool)
{
	GetParentMainWindow()->ParseInfoToConsole("New Geometry was clicked");
}

void ForgBaseLib::NihadTree::NewSceneClickedSlot(bool b)
{
	std::cout << (CorrectName<FrgBaseTreeItem>(GetTreeItem("Scenes"), "Scene")).toStdString() << std::endl;
	system("pause");
	NihadVesselSceneTreeItem* NihadSceneItem = FrgNew NihadVesselSceneTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Scenes"), "Scene"), GetTreeItem("Scenes"), GetParentMainWindow()->GetTree(), GetParentMainWindow());

	GetParentMainWindow()->ParseInfoToConsole("New Scene was clicked");
}