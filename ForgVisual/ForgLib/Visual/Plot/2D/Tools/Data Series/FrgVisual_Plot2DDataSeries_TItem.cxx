#include <FrgVisual_Plot2DDataSeries_TItem.hxx>
#include <FrgVisual_Plot2DLnStyle_TItem.hxx>
#include <FrgVisual_Plot2DSmblStyle_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgVisual_Plot.hxx>

#include <vtkPlot.h>
#include <vtkTable.h>
#include <vtkAbstractArray.h>
#include <vtkContextScene.h>

ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::FrgVisual_Plot2DDataSeries_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	vtkPlot* VTKPlot
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theVTKPlot_(VTKPlot)
{
	theLineStyle_ = new FrgVisual_Plot2DLnStyle_TItem("Line Style", this, parentTree);
	theSymbolStyle_ = new FrgVisual_Plot2DSmblStyle_TItem("Symbol Style", this, parentTree);

	this->AddRenameOptionInContextMenu();
	this->AddDeleteOptionInContextMenu();

	connect(this, SIGNAL(TItemNameChanged(const QString&)), this, SLOT(DataSeriesNameChangedSlot(const QString&)));
}

ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::~FrgVisual_Plot2DDataSeries_TItem()
{
	auto plot2dTItem = GetPlot2DTItem();
	if (plot2dTItem)
	{
		plot2dTItem->RemovePlot(theVTKPlot_);
	}
}

ForgVisualLib::FrgVisual_Plot2D_TItem * ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::GetPlot2DTItem() const
{
	if (!QTreeWidgetItem::parent())
		return nullptr;

	auto parentPlot2DTItem = dynamic_cast<FrgVisual_Plot2D_TItem*>(QTreeWidgetItem::parent()->parent());

	if (!parentPlot2DTItem)
	{
		std::cout << "parentPlot2DTItem is null in void ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::GetPlot2DTItem() const\n";
		return nullptr;
	}

	return parentPlot2DTItem;
}

void ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::RenderView() const
{
	auto parentPlot2DTItem = GetPlot2DTItem();

	if (parentPlot2DTItem)
	{
		auto plot = parentPlot2DTItem->GetPlot();
		if (plot)
			plot->RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::DataSeriesNameChangedSlot(const QString& name)
{
	if (theVTKPlot_)
	{
		theVTKPlot_->SetLabel(name.toStdString());
		theVTKPlot_->GetScene()->SetDirty(true);

		const auto& col = theVTKPlot_->GetInput()->GetColumn(1);
		
		if(col)
			col->SetName(name.toStdString().c_str());
	}
}