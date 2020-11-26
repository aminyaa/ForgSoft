#pragma once
#ifndef _FrgVisual_Plot_TItem_Header
#define _FrgVisual_Plot_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

class vtkPlot;

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

	void FormTItem() override;

	void ShowTabWidget() const;

	FrgVisual_Plot* GetPlot() const { return thePlot_; }
	void RenderView() const;

	bool RemovePlot(vtkPlot* plot);

	void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow) override;

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	FrgVisual_Plot* thePlot_ = NullPtr;

	virtual void Init();

public slots:

	void TItemDoubleClickedSlot() override;

private slots:

	void TItemNameToTabTitleChangedSlot(const QString& title);
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot_TItem)

#endif // !_FrgVisual_Plot_TItem_Header
