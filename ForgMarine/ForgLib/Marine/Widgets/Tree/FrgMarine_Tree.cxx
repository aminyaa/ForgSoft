#include <FrgMarine_Tree.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_Analyses_TItem.hxx>
#include <FrgMarine_Plots_TItem.hxx>

ForgMarineLib::FrgMarine_Tree::FrgMarine_Tree(FrgMarine_MainWindow* parentMainWindow)
	: FrgBase_Tree(parentMainWindow)
{
	FormTree();
}

void ForgMarineLib::FrgMarine_Tree::FormTree()
{
	theGeometry_ = new FrgMarine_Geometry_TItem("Geometry", nullptr, this);
	theAnalysis_ = new FrgMarine_Analyses_TItem("Analyses", nullptr, this);
	thePlots_ = new FrgMarine_Plots_TItem("Plots", nullptr, this);
}

ForgMarineLib::FrgMarine_Tree::~FrgMarine_Tree()
{
	FreePointer(thePlots_);
	FreePointer(theAnalysis_);
	FreePointer(theGeometry_);
}