#include <MainWindow.hxx>
#include <Tree.hxx>

#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_ScalarField.hxx>
#include <FrgBase_VectorField.hxx>

MainWindow::MainWindow(QWidget* parent /* = nullptr */)
	: ForgBaseLib::FrgBase_MainWindow(parent)
{
	InitMainWindow();

	try
	{
		auto registry1 = new ForgBaseLib::FrgBase_SymbolTableRegistry;
		auto table1 = registry1->CreateTable("Table 1");
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

		auto v1 = table1->AddVector<3>("V1");
		v1->SetExpression("[" + h->GetFullName() + ", 2.0*" + h2->GetFullName() + ", " + f->GetFullName() + /*", " + t->GetFullName() +*/ "]");
		//v1->CalcValue();

		//PrintInfoToConsole(QString::fromStdString(table1->Print()));
		//PrintInfoToConsole(QString::fromStdString(table2->Print()));
		PrintInfoToConsole(QString::fromStdString(registry1->Print()));

		/*ForgBaseLib::FrgBase_VectorField<4> v1;
		v1.SetExpression("[1, 3, 8.2, -33.3]");
		v1.CalcValue();
		for (const auto& x : v1.GetValue())
			PrintInfoToConsole(QString::number(x));*/
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