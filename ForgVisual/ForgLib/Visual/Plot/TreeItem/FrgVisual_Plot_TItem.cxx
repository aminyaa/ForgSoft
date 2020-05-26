#include <FrgVisual_Plot_TItem.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgVisual_Plot.hxx>
#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_Plot_TItem::FrgVisual_Plot_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->AddRenameOptionInContextMenu();
	this->AddDeleteOptionInContextMenu();

	connect(this, SIGNAL(TItemNameChanged(const QString&)), this, SLOT(TItemNameToTabTitleChangedSlot(const QString&)));

	boost::serialization::void_cast_register<ForgVisualLib::FrgVisual_Plot_TItem, ForgBaseLib::FrgBase_TreeItem>();
}

ForgVisualLib::FrgVisual_Plot_TItem::~FrgVisual_Plot_TItem()
{
	FreePointer(thePlot_);
}

void ForgVisualLib::FrgVisual_Plot_TItem::Init()
{
	if (!GetParentMainWindow())
		return;

	GetParentMainWindow()->ShowTabWidget(thePlot_, this->text(0) + " - Plot");
}

void ForgVisualLib::FrgVisual_Plot_TItem::TItemNameToTabTitleChangedSlot(const QString& title)
{
	GetParentMainWindow()->SetTabText(thePlot_, title + " - Plot");
}

void ForgVisualLib::FrgVisual_Plot_TItem::ShowTabWidget()
{
	if(!GetParentMainWindow())
		return;

	GetParentMainWindow()->ShowTabWidget(thePlot_, this->text(0) + " - Plot");
}

void ForgVisualLib::FrgVisual_Plot_TItem::TItemDoubleClickedSlot()
{
	ShowTabWidget();
}

void ForgVisualLib::FrgVisual_Plot_TItem::RenderView() const
{
	if (thePlot_)
		if (thePlot_)
			thePlot_->RenderView();
}

bool ForgVisualLib::FrgVisual_Plot_TItem::RemovePlot(vtkPlot * plot)
{
	if (thePlot_)
	{
		return thePlot_->RemovePlot(plot);
	}
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot_TItem)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot_TItem)