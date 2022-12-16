#include <MainWindow.hxx>
#include <Tree.hxx>

#include <FrgBase_SymbolTableRegistries.hxx>
#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_ScalarField.hxx>
#include <FrgBase_VectorField.hxx>
#include <FrgBase_FieldTools.hxx>
#include <FrgBase_FieldTextEdit.hxx>
#include <FrgBase_FieldTreeWidget.hxx>
#include <FrgBase_FieldDialog.hxx>

#include <fstream>

MainWindow::MainWindow(QWidget* parent /* = nullptr */)
	: ForgBaseLib::FrgBase_MainWindow(parent)
{
	InitMainWindow();

	try
	{
		auto registries =
			std::make_shared<ForgBaseLib::FrgBase_SymbolTableRegistries>();

		auto registry1 =
			registries->CreateRegistry();

		auto table1 = registry1->CreateTable("Geometry");
		auto table2 = registry1->CreateTable("Table 2");

		auto x = table1->AddVariable("X");
		x->SetExpression("1.0");

		auto y = table1->AddVariable("Y");
		y->SetExpression(x->GetFullName() + " * 2.0");

		auto z = table1->AddVariable("Z");
		z->SetExpression(x->GetFullName() + " + " + y->GetFullName());

		auto t = table1->AddVariable("T");
		t->SetExpression(z->GetFullName() + " + " + y->GetFullName() + " + " + y->GetFullName() + " + " + x->GetFullName() + " + " + std::to_string(2.0));

		table2->AddExternalSymbolTable(table1);
		table1->AddExternalSymbolTable(table2);

		auto f = table2->AddVariable("F");
		f->SetExpression(t->GetFullName() + " + 10.5");

		auto h = table1->AddVariable("H");
		h->SetExpression(f->GetFullName() + " - 2.23");

		auto h2 = table1->AddVariable("H2");
		h2->SetExpression(h->GetFullName() + " * 2.23");

		auto v1 = table1->AddVector("V1", 4);
		v1->SetExpression("[" + h->GetFullName() + ", 2.0 * " + h2->GetFullName() + ", " + f->GetFullName() + ", " + t->GetFullName() + "]");

		//ForgBaseLib::FrgBase_FieldTools::SetBracket(ForgBaseLib::FrgBase_FieldTools::Bracket::Angle);
		//ForgBaseLib::FrgBase_FieldTools::SetDecorator(ForgBaseLib::FrgBase_FieldTools::Decorator::Ampersand);

		auto partsTable = registry1->CreateTable("Parts");
		partsTable->SetParentSymbolTable(table1);

		auto p1 = partsTable->AddVariable("P1");

		auto p2 = partsTable->AddVariable("P2");
		p2->SetExpression(p1->GetFullName() + " + 2.2");

		/*std::string str =
			"[${Geometry.Value4}, 2.0 * ${Geometry.Value5}, ${Table 2.Value0}, ${Geometry.Value4}]";

		auto fff = ForgBaseLib::FrgBase_FieldTools::UnDecorizeExpression(str, registry1);
		std::cout << str << std::endl;
		std::cout << fff << std::endl;*/

		auto func = []() -> double
		{
			return -1.4563;
		};

		p1->SetCalcValueFunction(func);

		/*{
			std::ofstream myFile("Test.txt");
			boost::archive::polymorphic_text_oarchive oa(myFile);

			oa << registries;

			myFile.close();
		}

		{
			auto registriesL = std::shared_ptr<ForgBaseLib::FrgBase_SymbolTableRegistries>();

			std::ifstream myFile("Test.txt");
			boost::archive::polymorphic_text_iarchive oa(myFile);

			oa >> registriesL;

			for (auto reg : registriesL->GetRegistries())
				reg->Print(std::cout);

			myFile.close();
		}*/

		/*for (auto reg : registries->GetRegistries())
			reg->Print(std::cout);*/

		//PrintInfoToConsole(QString::fromStdString(registry1->Print()));

		/*std::cout << registry1->Print() << std::endl;

		std::cout << "\n==============================\n\n";

		auto fMy = std::make_shared<ForgBaseLib::FrgBase_SymbolTableRegistry>();
		*fMy = *registry1;

		std::cout << fMy->Print() << std::endl;*/

		/*auto w = new ForgBaseLib::FrgBase_FieldTextEdit(v1, this);
		w->SetGeometry(40, 30);
		w->show();*/

		/*auto w2 = new ForgBaseLib::FrgBase_FieldTreeWidget(registry1->GetTables());
		w2->show();*/

		auto w3 =
			new ForgBaseLib::FrgBase_FieldDialog(v1, this);

		w3->exec();

		PrintSuccessToConsole("DSfdsjfikg sdihfgids fds");
	}
 	catch (const std::exception& ex)
 	{
 		PrintErrorToConsole(QString::fromStdString(ex.what()));
 	}
}

void MainWindow::InitTree()
{
	theTree_ = new Tree(this);
	theTree_->FormTree();
}