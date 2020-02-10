#include <FrgMarine_TItemGeomParMdlsShip_01.hxx>
#include <FrgMarine_Ship01_Params.hxx>

#include <LegModel_DispNo1.hxx>
#include <LegModel_ConstParameter.hxx>

ForgMarineLib::FrgMarine_TItemGeomParMdlsShip_01::FrgMarine_TItemGeomParMdlsShip_01
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_TItemGeomParMdls_Ship(itemTitle, parentItem, parentTree)
{
	theModel_ = std::make_shared<tnbLib::LegModel_DispNo1>();
	theModel_->Parameters().Draft() = std::make_shared<tnbLib::LegModel_ConstParameter>(1110, "Draft", 1.0);

	theParameters_ = new FrgMarine_Ship01_Params("Parameters", this, parentTree, theModel_);
}