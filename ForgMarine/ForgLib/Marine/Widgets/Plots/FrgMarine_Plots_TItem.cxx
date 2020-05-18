#include <FrgMarine_Plots_TItem.hxx>
#include <FrgMarine_Plot2D_TItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_Tree.hxx>
#include <QtWidgets/QTreeWidgetItemIterator>

//BOOST_CLASS_EXPORT_GUID(ForgMarineLib::FrgMarine_Plots_TItem, "ForgMarineLib::FrgMarine_Plots_TItem")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgMarineLib::FrgMarine_Plots_TItem)

ForgMarineLib::FrgMarine_Plots_TItem::FrgMarine_Plots_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	ForgBaseLib::FrgBase_Menu* newMenu = new ForgBaseLib::FrgBase_Menu("New", GetParentMainWindow());
	newMenu->SetToolBarHidden(true);
	auto addPlot2DAction = newMenu->AddItem("2D", false);
	addPlot2DAction->setIcon(QIcon(ICONPlot_2D));
	GetContextMenu()->addMenu(newMenu);

	connect(addPlot2DAction, SIGNAL(triggered()), this, SLOT(AddPlot2DSlot()));

	boost::serialization::void_cast_register<ForgMarineLib::FrgMarine_Plots_TItem, ForgBaseLib::FrgBase_TreeItem>();
}

ForgMarineLib::FrgMarine_Plot2D_TItem * ForgMarineLib::FrgMarine_Plots_TItem::AddPlot2D()
{
	auto plotItem = new FrgMarine_Plot2D_TItem(CorrectName(this, "Plot"), this, GetParentTree());
	GetParentTree()->ScrollToItem(plotItem);

	return plotItem;
}

void ForgMarineLib::FrgMarine_Plots_TItem::AddPlot2DSlot()
{
	AddPlot2D();
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_Plots_TItem)
{
	std::list<ForgMarineLib::FrgMarine_Plot2D_TItem*> myItems;

	QTreeWidgetItemIterator it((QTreeWidgetItem*)this);
	while (*it)
	{
		auto castedTItem = dynamic_cast<ForgMarineLib::FrgMarine_Plot2D_TItem*>(*it);
		if (castedTItem)
			myItems.push_back(castedTItem);

		++it;
	}

	ar & myItems;
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_Plots_TItem)
{
	std::list<ForgMarineLib::FrgMarine_Plot2D_TItem*> myItems;

	ar & myItems;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Plots_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Plots_TItem)

		/*std::list<ForgBaseLib::FrgBase_TreeItem*> myTItems;
		QTreeWidgetItemIterator it((QTreeWidgetItem*)t);
		while (*it)
		{
			auto myTItem = dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(*it);

			myTItems.push_back(myTItem);

			++it;
		}

		ar & myTItems;*/
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Plots_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Plots_TItem)

		/*std::list<ForgBaseLib::FrgBase_TreeItem*> myTItems;

		ar & myTItems;*/
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_Plots_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_Plots_TItem)