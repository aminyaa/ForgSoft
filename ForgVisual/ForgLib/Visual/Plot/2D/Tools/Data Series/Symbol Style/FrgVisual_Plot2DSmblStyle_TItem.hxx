#pragma once
#ifndef _FrgVisual_Plot2DSmblStyle_TItem_Header
#define _FrgVisual_Plot2DSmblStyle_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

#include <FrgVisual_Serialization_Global.hxx>

class vtkPlot;

BeginForgVisualLib

class FrgVisual_Plot2DDataSeries_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2DSmblStyle_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntCombo* Shape READ GetShape WRITE SetShape)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* Size READ GetSize WRITE SetSize)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* Spacing READ GetSpacing WRITE SetSpacing)

public:

	FrgVisual_Plot2DSmblStyle_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	ForgBaseLib::FrgBase_PrptsVrntCombo* GetShape() const { return theShape_; }
	void SetShape(ForgBaseLib::FrgBase_PrptsVrntCombo* shape) { theShape_ = shape; }

	ForgBaseLib::FrgBase_PrptsVrntInt* GetSize() const { return theSize_; }
	void SetSize(ForgBaseLib::FrgBase_PrptsVrntInt* size) { theSize_ = size; }

	ForgBaseLib::FrgBase_PrptsVrntInt* GetSpacing() const { return theSpacing_; }
	void SetSpacing(ForgBaseLib::FrgBase_PrptsVrntInt* spacing) { theSpacing_ = spacing; }

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	ForgBaseLib::FrgBase_PrptsVrntCombo* theShape_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntInt* theSize_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntInt* theSpacing_ = nullptr;

	FrgVisual_Plot2DDataSeries_TItem* GetDataSeries() const;
	vtkPlot* GetVTKPlot() const;
	void RenderView() const;

	QString GetShapeFromVTKPlot() const;
	float GetSymbolSizeFromVTKPlot() const;

public slots:

	void ShapeChangedSlot(const QString& shape);
	void SizeChangedSlot(const int& size);
	void SpacingChangedSlot(const int& spacing);
};

EndForgVisualLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)

#endif // !_FrgVisual_Plot2DSmblStyle_TItem_Header
