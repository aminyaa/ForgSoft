#include <NihadMainWindow.hxx>
#include <FrgBaseTree.hxx>
#include <NihadTree.hxx>
#include <NihadTree.hxx>

ForgBaseLib::NihadMainWindow::NihadMainWindow(QWidget* parent)
	: FrgBaseMainWindow(parent)
{
	this->setMinimumSize(QSize(1366, 768));
}

void ForgBaseLib::NihadMainWindow::CreateTree()
{
	GetTree() = FrgNew NihadTree(this);
}