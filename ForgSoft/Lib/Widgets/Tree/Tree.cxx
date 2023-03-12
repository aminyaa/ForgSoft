#include <Tree.hxx>
#include <MainWindow.hxx>

#include <FrgCAD_Scene_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgVisual_Scene3D_TItem.hxx>
#include <FrgVisual_Scene.hxx>
#include <FrgBase_Pnt.hxx>
#include <FrgBase_Menu.hxx>

#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_ToolsParameterScalar_TItem.hxx>
#include <FrgBase_ToolsParameterVector_TItem.hxx>
#include <FrgBase_PrptsVrntTextEdit.hxx>
#include <FrgBase_PrptsVrntBool.hxx>
#include <FrgBase_PropertiesPanel.hxx>

#include <QPushButton>

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

	auto s1 = new ForgVisualLib::FrgVisual_Scene3D_TItem("Scene 1 3D", nullptr, this);
	s1->FormTItem();
	s1->SetLockType(ForgBaseLib::FrgBase_TreeItem::LockType::RenameAndDeleteAndPPanel);
	s1->AddRenameOptionInContextMenu();
	s1->AddRenameOptionInContextMenu();

	auto s2 = new ForgVisualLib::FrgVisual_Scene3D_TItem("Scene 2 3D", nullptr, this);
	s2->FormTItem();
	s2->AddRenameOptionInContextMenu();
	s2->AddRenameOptionInContextMenu();

	auto s3 = new ForgVisualLib::FrgVisual_Scene3D_TItem("Scene 3 3D", nullptr, this);
	s3->FormTItem();
	s3->SetLockType(ForgBaseLib::FrgBase_TreeItem::LockType::Rename);
	s3->AddRenameOptionInContextMenu();
	s3->AddRenameOptionInContextMenu();

	theItems_.push_back(s1);
	theItems_.push_back(s2);
	theItems_.push_back(s3);

	auto actions =
		s1->GetContextMenu()->actions();

	std::cout << "actions.size() = "
		<< actions.size() << std::endl;

	for (auto action : actions)
		std::cout << "============> " << action->text().toStdString() << std::endl;

	std::cout << "================================\n";

	actions = s2->GetContextMenu()->actions();
	for (auto action : actions)
		std::cout << "============> " << action->text().toStdString() << std::endl;

	std::cout << "================================\n";

	auto m = s3->GetContextMenu()->AddMenu("Salam");
	m->AddItem("SSALAAM");

	actions = s3->GetContextMenu()->actions();
	for (auto action : actions)
		std::cout << "============> " << action->text().toStdString() << std::endl;

	auto i = new ForgBaseLib::FrgBase_PrptsVrntBool("Boolean", true);
	auto i2 = new ForgBaseLib::FrgBase_PrptsVrntTextEdit("TextEdit", "This is a test");

	s1->GetPropertiesPanel()->AddRow(i);
	s1->GetPropertiesPanel()->AddRow(i2);

	s1->GetScene()->AddBox(0.0, 0.0, 0.0, 1.0, 1.0, 1.0);

	auto myButton = new QPushButton("Click", GetParentMainWindow());

	connect(myButton, &QPushButton::clicked, [this, s1, s2, s3]()
		{
			QString str1 = QString("s1 isVisible = ") + (GetParentMainWindow()->IsTabWidgetVisible(s1->GetScene()) == true ? "true" : "false");
			QString str2 = QString("s2 isVisible = ") + (GetParentMainWindow()->IsTabWidgetVisible(s2->GetScene()) == true ? "true" : "false");
			QString str3 = QString("s3 isVisible = ") + (GetParentMainWindow()->IsTabWidgetVisible(s3->GetScene()) == true ? "true" : "false");

			GetParentMainWindow()->PrintInfoToConsole(str1);
			GetParentMainWindow()->PrintInfoToConsole(str2);
			GetParentMainWindow()->PrintInfoToConsole(str3);
		});

	auto l = new QVBoxLayout;
	l->addWidget(myButton);
	l->addStretch();

	QWidget* ww = new QWidget;
	ww->setLayout(l);

	GetParentMainWindow()->ShowTabWidget(ww, "Button");

	//myButton.show();

	//ForgBaseLib::FrgBase_Pnt<3> P1(-1.0, 0.0, -1.0);
	//ForgBaseLib::FrgBase_Pnt<3> P2(1.0, 0.0, 1.0);
	//ForgBaseLib::FrgBase_Pnt<3> P3(1.0, 0.0, -1.0);
	//s->GetScene()->AddPlane(P3, P1, P2);
	////s->GetScene()->AddPlaneUsingCenterNormal(P1, P2);
	//s->GetScene()->DrawGrid(0.0, 0.0, 5.0, 5.0, 10, 10);

	/*auto parameters = new ForgBaseLib::FrgBase_ToolsParameters_TItem("Parameters", nullptr, this);
	parameters->FormTItem();

	auto parameterTItem = new ForgBaseLib::FrgBase_ToolsParameterScalar_TItem("Scalar", parameters, this);
	parameterTItem->SetSymbolTableT(parameters->GetSymbolTableT());
	parameterTItem->SetParentToolsParametersTItem(parameters);
	parameterTItem->FormTItem();

	auto parameterTItem2 = new ForgBaseLib::FrgBase_ToolsParameterScalar_TItem("Scalar 2", parameters, this);
	parameterTItem2->SetSymbolTableT(parameters->GetSymbolTableT());
	parameterTItem2->SetParentToolsParametersTItem(parameters);
	parameterTItem2->FormTItem();

	auto v = new ForgBaseLib::FrgBase_ToolsParameterVector_TItem("Vector 1", parameters, this);
	v->SetSymbolTableT(parameters->GetSymbolTableT());
	v->SetParentToolsParametersTItem(parameters);
	v->FormTItem();

	auto tVar = new ForgBaseLib::FrgBase_PrptsVrntTextEdit("Description");
	const auto& pp = parameterTItem2->GetPropertiesPanel();
	pp->AddRow(tVar);

	int ind = pp->GetRowFromVariant(tVar);
	parameterTItem2->GetPropertiesPanel()->setRowHeight(ind, pp->rowHeight(ind) / 2);*/
}

DECLARE_SAVE_IMP(Tree)
{
	boost::serialization::base_object<ForgBaseLib::FrgBase_Tree>(*this);
	ar & theItems_;
}

DECLARE_LOAD_IMP(Tree)
{
	boost::serialization::base_object<ForgBaseLib::FrgBase_Tree>(*this);
	ar & theItems_;
}

BOOST_CLASS_EXPORT_CXX(Tree)