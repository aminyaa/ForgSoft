#pragma once
#ifndef _FrgVisual_Plot_TItem_Header
#define _FrgVisual_Plot_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgVisualLib

class FrgVisual_Plot;

class FORGVISUAL_EXPORT FrgVisual_Plot_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgVisual_Plot_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgVisual_Plot_TItem();

	void ShowTabWidget();

	FrgVisual_Plot* GetPlot() const { return thePlot_; }
	void RenderView() const;

protected:

	FrgVisual_Plot* thePlot_ = NullPtr;

	virtual void Init();

public slots:

	void TItemDoubleClickedSlot() override;

private slots:

	void TItemNameToTabTitleChangedSlot(const QString& title);
};

EndForgVisualLib

#endif // !_FrgVisual_Plot_TItem_Header
