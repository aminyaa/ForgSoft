#include <MainWindow.hxx>
#include <Tree.hxx>

MainWindow::MainWindow(QWidget* parent /* = nullptr */)
	: ForgBaseLib::FrgBase_MainWindow(parent)
{
	InitMainWindow();
}

void MainWindow::InitTree()
{
	theTree_ = new Tree(this);
	theTree_->FormTree();
}