#include <FrgMarine_Plot2D_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgVisual_Plot2D.hxx>

#include <FrgVisual_Plot.hxx>
#include <FrgBase_Tree.hxx>

//BOOST_CLASS_EXPORT_GUID(ForgMarineLib::FrgMarine_Plot2D_TItem, "ForgMarineLib::FrgMarine_Plot2D_TItem")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgMarineLib::FrgMarine_Plot2D_TItem)

ForgMarineLib::FrgMarine_Plot2D_TItem::FrgMarine_Plot2D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Plot2D_TItem(itemTitle, parentItem, parentTree)
{
	GetContextMenu()->addSeparator();

	ForgBaseLib::FrgBase_Menu* newPredefinedFunctions = new ForgBaseLib::FrgBase_Menu("Add Predefined Functions", GetParentMainWindow());

	auto sinAction = newPredefinedFunctions->AddItem("Sin(x)", false);
	auto cosAction = newPredefinedFunctions->AddItem("Cos(x)", false);

	connect(sinAction, SIGNAL(triggered()), this, SLOT(AddPlotSinXSlot()));
	connect(cosAction, SIGNAL(triggered()), this, SLOT(AddPlotCosXSlot()));

	GetContextMenu()->addMenu(newPredefinedFunctions);
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_Plot2D_TItem)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Plot2D_TItem, ForgVisualLib::FrgVisual_Plot2D_TItem)
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Plot2D_TItem, ForgBaseLib::FrgBase_TreeItem)

	//ar.template register_type<ForgMarineLib::FrgMarine_Plot2D_TItem>();

	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_Plot2D_TItem>(*this);
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_Plot2D_TItem)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Plot2D_TItem, ForgVisualLib::FrgVisual_Plot2D_TItem)
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Plot2D_TItem, ForgBaseLib::FrgBase_TreeItem)

	//ar.template register_type<ForgMarineLib::FrgMarine_Plot2D_TItem>();

	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_Plot2D_TItem>(*this);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Plot2D_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Plot2D_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Plot2D_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Plot2D_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_Plot2D_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_Plot2D_TItem)