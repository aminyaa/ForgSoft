#pragma once
#ifndef _Tree_Header
#define _Tree_Header

#include <FrgBase_Tree.hxx>

class MainWindow;

class Tree
	: public ForgBaseLib::FrgBase_Tree
{

	Q_OBJECT

public:

	Tree(MainWindow* parentMainWindow = nullptr);

	void FormTree() override;
};

#endif // !_Tree_Header
