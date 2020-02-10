#include <FrgMarine_Tree.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgMarine_TItem_Geom.hxx>
#include <FrgMarine_TItem_Analysis.hxx>

ForgMarineLib::FrgMarine_Tree::FrgMarine_Tree(FrgMarine_MainWindow* parentMainWindow)
	: FrgBase_Tree(parentMainWindow)
{
	FormTree();
}

void ForgMarineLib::FrgMarine_Tree::FormTree()
{
	theGeometry_ = new FrgMarine_TItem_Geom("Geometry", nullptr, this);
	theAnalysis_ = new FrgMarine_TItem_Analysis("Analysis", nullptr, this);
}