#include <Tree.hxx>
#include <MainWindow.hxx>

#include <FrgCAD_Scene_TItem.hxx>

Tree::Tree(MainWindow* parentMainWindow /* = nullptr */)
	: ForgBaseLib::FrgBase_Tree(parentMainWindow)
{

}

void Tree::FormTree()
{
	auto cad2d = new ForgCADLib::FrgCAD_Scene_TItem("CAD2D TItem", nullptr, this);
	cad2d->FormTItem();
}