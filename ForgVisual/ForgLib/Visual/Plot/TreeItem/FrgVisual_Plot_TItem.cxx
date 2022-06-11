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

	SetParentTitleTItem(GetParentTItem());

	connect(this, &FrgVisual_Plot_TItem::TItemNameChanged, this, &FrgVisual_Plot_TItem::TItemNameToTabTitleChangedSlot);

	boost::serialization::void_cast_register<ForgVisualLib::FrgVisual_Plot_TItem, ForgBaseLib::FrgBase_TreeItem>();
}

ForgVisualLib::FrgVisual_Plot_TItem::~FrgVisual_Plot_TItem()
{
	if (GetParentMainWindow())
		GetParentMainWindow()->RemoveTabWidget(thePlot_);

	thePlot_->deleteLater();
	//FreePointer(thePlot_);
}

void ForgVisualLib::FrgVisual_Plot_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

void ForgVisualLib::FrgVisual_Plot_TItem::Init()
{
	if (!GetParentMainWindow())
		return;

	ShowTabWidget();

	//GetParentMainWindow()->ShowTabWidget(thePlot_, this->text(0) + " - Plot");
}

void ForgVisualLib::FrgVisual_Plot_TItem::TItemNameToTabTitleChangedSlot(const QString& title)
{
	//ShowTabWidget();

	GetParentMainWindow()->SetTabText(thePlot_, GetTabText());

	//GetParentMainWindow()->SetTabText(thePlot_, title + " - Plot");
}

void ForgVisualLib::FrgVisual_Plot_TItem::ShowTabWidget()
{
	if (GetParentMainWindow())
		GetParentMainWindow()->ShowTabWidget(thePlot_, GetTabText());

	//GetParentMainWindow()->ShowTabWidget(thePlot_, this->text(0) + " - Plot");
}

QString ForgVisualLib::FrgVisual_Plot_TItem::GetTabText() const
{
	QString prefix = "";
	if (theParentTitleTItem_)
		prefix = theParentTitleTItem_->text(0);

	if (prefix.isEmpty())
		return this->text(0);
	else
		return (prefix + " - " + this->text(0));
}

void ForgVisualLib::FrgVisual_Plot_TItem::SetParentTitleTItem(ForgBaseLib::FrgBase_TreeItem* pt)
{
	if (theParentTitleTItem_)
	{
		disconnect
		(
			theParentTitleTItem_,
			&ForgBaseLib::FrgBase_TreeItem::TItemNameChanged,
			this,
			&ForgVisualLib::FrgVisual_Plot_TItem::TItemNameToTabTitleChangedSlot
		);
	}

	theParentTitleTItem_ = pt;

	if (theParentTitleTItem_)
	{
		connect
		(
			theParentTitleTItem_,
			&ForgBaseLib::FrgBase_TreeItem::TItemNameChanged,
			this,
			&ForgVisualLib::FrgVisual_Plot_TItem::TItemNameToTabTitleChangedSlot
		);
	}
}

void ForgVisualLib::FrgVisual_Plot_TItem::TItemDoubleClickedSlot()
{
	ShowTabWidget();

	//GetParentMainWindow()->SetTabText(thePlot_, GetTabText());
}

void ForgVisualLib::FrgVisual_Plot_TItem::RenderView() const
{
	if (thePlot_)
		thePlot_->RenderView();
}

bool ForgVisualLib::FrgVisual_Plot_TItem::RemovePlot(vtkPlot * plot)
{
	if (thePlot_)
		return thePlot_->RemovePlot(plot);

	return true;
}

void ForgVisualLib::FrgVisual_Plot_TItem::SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow * parentMainWindow)
{
	ForgBaseLib::FrgBase_TreeItem::SetParentMainWindow(parentMainWindow);

	if (thePlot_)
		thePlot_->SetParentMainWindow(parentMainWindow);
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

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot_TItem)