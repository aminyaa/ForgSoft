#pragma once
#ifndef _FrgMarine_Tree_Header
#define _FrgMarine_Tree_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_Tree.hxx>

#include <FrgMarine_Serialization_Global.hxx>

BeginForgMarineLib

class FrgMarine_MainWindow;
class FrgMarine_Geometry_TItem;
class FrgMarine_Analyses_TItem;
class FrgMarine_Plots_TItem;

class FORGMARINE_EXPORT FrgMarine_Tree
	: public ForgBaseLib::FrgBase_Tree
{
	Q_OBJECT

public:

	FrgMarine_Tree
	(
		FrgMarine_MainWindow* parentMainWindow = nullptr
	);

	~FrgMarine_Tree();

	FrgMarine_Geometry_TItem* GetGeometryTItem() const { return theGeometry_; }
	FrgMarine_Analyses_TItem* GetAnalysisTItem() const { return theAnalysis_; }
	FrgMarine_Plots_TItem* GetPlotsTItem() const { return thePlots_; }

	void FormTree() override;

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	mutable FrgMarine_Geometry_TItem* theGeometry_ = NullPtr;
	mutable FrgMarine_Analyses_TItem* theAnalysis_ = NullPtr;
	mutable FrgMarine_Plots_TItem* thePlots_ = NullPtr;

};

EndForgMarineLib

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_Tree)

#endif // !_FrgMarine_Tree_Header
