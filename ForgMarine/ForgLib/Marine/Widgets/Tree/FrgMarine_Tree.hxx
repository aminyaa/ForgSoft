#pragma once
#ifndef _FrgMarine_Tree_Header
#define _FrgMarine_Tree_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_Tree.hxx>

BeginForgMarineLib

class FrgMarine_MainWindow;
class FrgMarine_Geometry_TItem;
class FrgMarine_Analyses_TItem;

class FORGMARINE_EXPORT FrgMarine_Tree
	: public ForgBaseLib::FrgBase_Tree
{
	Q_OBJECT

public:

	FrgMarine_Tree(FrgMarine_MainWindow* parentMainWindow);

	void FormTree() override;

private:

	FrgMarine_Geometry_TItem* theGeometry_ = NullPtr;
	FrgMarine_Analyses_TItem* theAnalysis_ = NullPtr;

};

EndForgMarineLib

#endif // !_FrgMarine_Tree_Header
