#include <Tree.hxx>
#include <MainWindow.hxx>

#include <FrgCAD_Scene_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgVisual_Scene3D_TItem.hxx>
#include <FrgVisual_Scene.hxx>
#include <FrgBase_Pnt.hxx>

#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_ToolsParameterScalar_TItem.hxx>
#include <FrgBase_PrptsVrntTextEdit.hxx>
#include <FrgBase_PropertiesPanel.hxx>

Tree::Tree(MainWindow* parentMainWindow /* = nullptr */)
	: ForgBaseLib::FrgBase_Tree(parentMainWindow)
{

}

void Tree::FormTree()
{
	//auto cad2d1 = new ForgCADLib::FrgCAD_Scene_TItem("CAD2D TItem 1", nullptr, this);
	//cad2d1->FormTItem();

	//auto cad2d2 = new ForgCADLib::FrgCAD_Scene_TItem("CAD2D TItem 2", nullptr, this);
	//cad2d2->FormTItem();

	//auto cad2d3 = new ForgCADLib::FrgCAD_Scene_TItem("CAD2D TItem 3", nullptr, this);
	//cad2d3->FormTItem();

	//auto p = new ForgVisualLib::FrgVisual_Plot2D_TItem("Plot 1", nullptr, this);
	//p->FormTItem();
	//p->GetPlot2D()->AddCosX("Cos (x)");

	//auto tree = dynamic_cast<ForgBaseLib::FrgBase_Tree*>(GetParentMainWindow()->AddTree(nullptr, ""));
	//GetParentMainWindow()->GetTabWidgetForTrees()->tabBar()->show();
	//auto p2 = new ForgVisualLib::FrgVisual_Plot2D_TItem("Plot 1", nullptr, tree);
	//p2->FormTItem();
	//p2->GetPlot2D()->AddSinX("Sin (x)");

	//auto s = new ForgVisualLib::FrgVisual_Scene3D_TItem("Scene 3D", nullptr, this);
	//s->FormTItem();

	//ForgBaseLib::FrgBase_Pnt<3> P1(-1.0, 0.0, -1.0);
	//ForgBaseLib::FrgBase_Pnt<3> P2(1.0, 0.0, 1.0);
	//ForgBaseLib::FrgBase_Pnt<3> P3(1.0, 0.0, -1.0);
	//s->GetScene()->AddPlane(P3, P1, P2);
	////s->GetScene()->AddPlaneUsingCenterNormal(P1, P2);
	//s->GetScene()->DrawGrid(0.0, 0.0, 5.0, 5.0, 10, 10);

	auto parameters = new ForgBaseLib::FrgBase_ToolsParameters_TItem("Parameters", nullptr, this);
	parameters->FormTItem();

	auto parameterTItem = new ForgBaseLib::FrgBase_ToolsParameterScalar_TItem("Scalar", parameters, this);
	parameterTItem->SetSymbolTableT(parameters->GetSymbolTableT());
	parameterTItem->SetParentToolsParametersTItem(parameters);
	parameterTItem->FormTItem();

	auto parameterTItem2 = new ForgBaseLib::FrgBase_ToolsParameterScalar_TItem("Scalar 2", parameters, this);
	parameterTItem2->SetSymbolTableT(parameters->GetSymbolTableT());
	parameterTItem2->SetParentToolsParametersTItem(parameters);
	parameterTItem2->FormTItem();

	auto tVar = new ForgBaseLib::FrgBase_PrptsVrntTextEdit("Description");
	const auto& pp = parameterTItem2->GetPropertiesPanel();
	pp->AddRow(tVar);

	int ind = pp->GetRowFromVariant(tVar);
	parameterTItem2->GetPropertiesPanel()->setRowHeight(ind, pp->rowHeight(ind) / 2);
}