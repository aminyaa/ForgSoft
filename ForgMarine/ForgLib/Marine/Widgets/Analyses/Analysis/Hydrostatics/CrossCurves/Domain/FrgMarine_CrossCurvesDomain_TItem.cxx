#include <FrgMarine_CrossCurvesDomain_TItem.hxx>

#include <Entity3d_Box.hxx>
#include <Marine_Domain.hxx>

ForgMarineLib::FrgMarine_CrossCurvesDomain_TItem::FrgMarine_CrossCurvesDomain_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	tnbLib::Entity3d_Box* box
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theDomain_ = std::make_shared<tnbLib::Marine_Domain>();

	theDomain_->Perform(*box);
}