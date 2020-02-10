#pragma once
#ifndef _FrgMarine_Tree_Header
#define _FrgMarine_Tree_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_Tree.hxx>

BeginForgMarineLib

class FrgMarine_MainWindow;
class FrgMarine_TItem_Geom;
class FrgMarine_TItem_Analysis;

class FORGMARINE_EXPORT FrgMarine_Tree
	: public ForgBaseLib::FrgBase_Tree
{
	Q_OBJECT

public:

	FrgMarine_Tree(FrgMarine_MainWindow* parentMainWindow);

	void FormTree() override;

private:

	FrgMarine_TItem_Geom* theGeometry_ = NullPtr;
	FrgMarine_TItem_Analysis* theAnalysis_ = NullPtr;

};

EndForgMarineLib

#endif // !_FrgMarine_Tree_Header
