#include <FrgVisual_Plot_TItem.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgVisual_Plot.hxx>

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
}

ForgVisualLib::FrgVisual_Plot_TItem::~FrgVisual_Plot_TItem()
{
	FreePointer(thePlot_);
}

void ForgVisualLib::FrgVisual_Plot_TItem::Init()
{
	GetParentMainWindow()->ShowTabWidget(thePlot_, this->text(0) + " - Plot");
	connect(this, SIGNAL(TItemNameChanged(const QString&)), this, SLOT(TItemNameToTabTitleChangedSlot(const QString&)));
}

void ForgVisualLib::FrgVisual_Plot_TItem::TItemNameToTabTitleChangedSlot(const QString& title)
{
	GetParentMainWindow()->SetTabText(thePlot_, title + " - Plot");
}

void ForgVisualLib::FrgVisual_Plot_TItem::ShowTabWidget()
{
	GetParentMainWindow()->ShowTabWidget(thePlot_, this->text(0) + " - Plot");
}

void ForgVisualLib::FrgVisual_Plot_TItem::TItemDoubleClickedSlot()
{
	ShowTabWidget();
}