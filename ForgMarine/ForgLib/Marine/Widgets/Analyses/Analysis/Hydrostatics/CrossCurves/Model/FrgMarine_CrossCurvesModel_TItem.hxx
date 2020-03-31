#pragma once
#ifndef _FrgMarine_CrossCurvesModel_TItem_Header
#define _FrgMarine_CrossCurvesModel_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <Entity3d_BoxFwd.hxx>

class TopoDS_Shape;

namespace tnbLib
{
	class CrossSection_xShapeStation;
}

BeginForgMarineLib

class FrgMarine_CrossCurvesModelAxis_TItem;
class FrgMarine_CrossCurvesModelDistributor_TItem;

class FORGMARINE_EXPORT FrgMarine_CrossCurvesModel_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_CrossCurvesModel_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		TopoDS_Shape* shape,
		tnbLib::Entity3d_Box* box
	);

	~FrgMarine_CrossCurvesModel_TItem();

	const std::shared_ptr<tnbLib::CrossSection_xShapeStation>& GetModel() const { return theModel_; }

private:

	std::shared_ptr<tnbLib::CrossSection_xShapeStation> theModel_;

	FrgMarine_CrossCurvesModelAxis_TItem* theAxisTItem_ = nullptr;
	FrgMarine_CrossCurvesModelDistributor_TItem* theDistributorTItem_ = nullptr;
};

EndForgMarineLib

#endif // !_FrgMarine_CrossCurvesModel_TItem_Header
