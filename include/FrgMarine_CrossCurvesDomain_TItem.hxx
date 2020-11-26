#pragma once
#ifndef _FrgMarine_CrossCurvesDomain_TItem_Header
#define _FrgMarine_CrossCurvesDomain_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <Entity3d_BoxFwd.hxx>

namespace tnbLib
{
	class Marine_Domain;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_CrossCurvesDomain_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_CrossCurvesDomain_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		tnbLib::Entity3d_Box* box
	);

	const std::shared_ptr<tnbLib::Marine_Domain>& GetDomain() const { return theDomain_; }

private:

	std::shared_ptr<tnbLib::Marine_Domain> theDomain_;
};

EndForgMarineLib

#endif // !_FrgMarine_CrossCurvesDomain_TItem_Header
