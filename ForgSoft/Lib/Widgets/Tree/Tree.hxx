#pragma once
#ifndef _Tree_Header
#define _Tree_Header

#include <FrgBase_Tree.hxx>

namespace ForgVisualLib
{
	class FrgVisual_Scene3D_TItem;
}

class MainWindow;

class Tree
	: public ForgBaseLib::FrgBase_Tree
{

	Q_OBJECT

public:

	Tree(MainWindow* parentMainWindow = nullptr);

	void FormTree() override;

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	std::vector<ForgVisualLib::FrgVisual_Scene3D_TItem*> theItems_;
};

BOOST_CLASS_EXPORT_KEY(Tree)

#endif // !_Tree_Header
