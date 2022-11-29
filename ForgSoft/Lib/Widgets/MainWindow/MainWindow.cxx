#include <MainWindow.hxx>
#include <Tree.hxx>

#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_ScalarField.hxx>
#include <FrgBase_VectorField.hxx>
#include <FrgBase_FieldTools.hxx>

MainWindow::MainWindow(QWidget* parent /* = nullptr */)
	: ForgBaseLib::FrgBase_MainWindow(parent)
{
	InitMainWindow();

	try
	{
		auto registry1 = new ForgBaseLib::FrgBase_SymbolTableRegistry;
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

		auto v1 = table1->AddVector<4>("V1");
		v1->SetExpression("[" + h->GetFullName() + ", 2.0 * " + h2->GetFullName() + ", " + f->GetFullName() + ", " + t->GetFullName() + "]");

		//ForgBaseLib::FrgBase_FieldTools::SetBracket(ForgBaseLib::FrgBase_FieldTools::Bracket::Angle);
		//ForgBaseLib::FrgBase_FieldTools::SetDecorator(ForgBaseLib::FrgBase_FieldTools::Decorator::Ampersand);

		auto partsTable = registry1->CreateTable("Parts");
		partsTable->SetParentSymbolTable(table1);

		auto p1 = partsTable->AddVariable("P1");

		auto p2 = partsTable->AddVariable("P1");
		p2->SetExpression(p1->GetFullName() + " + 2.2");

		std::cout << p2->GetExpression() << std::endl;
		auto dec = ForgBaseLib::FrgBase_FieldTools::DecorizeExpression(p2);
		std::cout << dec << std::endl;

		auto ss = dec;
		auto undec = ForgBaseLib::FrgBase_FieldTools::UnDecorizeExpression(ss, registry1);
		std::cout << undec << std::endl;
		p2->SetExpression(undec);

		PrintInfoToConsole(QString::fromStdString(registry1->Print()));
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