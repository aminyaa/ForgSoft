#include <MainWindow.hxx>
#include <Tree.hxx>

#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_ScalarField.hxx>

MainWindow::MainWindow(QWidget* parent /* = nullptr */)
	: ForgBaseLib::FrgBase_MainWindow(parent)
{
	InitMainWindow();

	try
	{
		auto table = new ForgBaseLib::FrgBase_SymbolTable;
		table->SetName("Table1");
		table->SetPresentationName("Table1");

		auto x = table->AddVariable("X");
		x->SetExpression("1.0");

		auto y = table->AddVariable("Y");
		y->SetExpression(x->GetFullName() + " * 2.0");

		auto z = table->AddVariable("Z");
		z->SetExpression(x->GetFullName() + " + " + y->GetFullName());

		auto t = table->AddVariable("T");
		t->SetExpression(z->GetFullName() + " + " + y->GetFullName() + " + " + y->GetFullName() + " + " + x->GetFullName() + " + " + std::to_string(2.0));

		auto table2 = new ForgBaseLib::FrgBase_SymbolTable;
		table2->SetName("Table2");
		table2->SetPresentationName("Table2");
		table2->AddExternalSymbolTable(table);
		table->AddExternalSymbolTable(table2);

		auto f = table2->AddVariable("F");
		f->SetExpression(t->GetFullName() + " + 10.5");

		auto h = table->AddVariable("H");
		h->SetExpression(f->GetFullName() + " - 2.23");

		h->CalcValue();
		PrintInfoToConsole(QString::number(h->GetValue()));
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