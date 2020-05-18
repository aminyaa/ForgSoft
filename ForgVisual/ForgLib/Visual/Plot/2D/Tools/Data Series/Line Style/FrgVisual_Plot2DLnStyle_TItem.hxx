#pragma once
#ifndef _FrgVisual_Plot2DLnStyle_TItem_Header
#define _FrgVisual_Plot2DLnStyle_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>
#include <FrgBase_PrptsVrntColor.hxx>
#include <FrgBase_PrptsVrntInt.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

#include <FrgVisual_Serialization_Global.hxx>

class vtkPlot;

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2DLnStyle_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntCombo* Style READ GetStyle WRITE SetStyle)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntColor* Color READ GetColor WRITE SetColor)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* Width READ GetWidth WRITE SetWidth)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Opacity READ GetOpacity WRITE SetOpacity)

public:

	FrgVisual_Plot2DLnStyle_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	ForgBaseLib::FrgBase_PrptsVrntCombo* GetStyle() const { return theStyle_; }
	void SetStyle(ForgBaseLib::FrgBase_PrptsVrntCombo* style) { theStyle_ = style; }

	ForgBaseLib::FrgBase_PrptsVrntColor* GetColor() const { return theColor_; }
	void SetColor(ForgBaseLib::FrgBase_PrptsVrntColor* color) { theColor_ = color; }

	ForgBaseLib::FrgBase_PrptsVrntInt* GetWidth() const { return theWidth_; }
	void SetWidth(ForgBaseLib::FrgBase_PrptsVrntInt* width) { theWidth_ = width; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetOpacity() const { return theOpacity_; }
	void SetOpacity(ForgBaseLib::FrgBase_PrptsVrntDouble* opacity) { theOpacity_ = opacity; }

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	ForgBaseLib::FrgBase_PrptsVrntCombo* theStyle_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntColor* theColor_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntInt* theWidth_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theOpacity_ = nullptr;

	vtkPlot* GetVTKPlot() const;
	void RenderView() const;

	QString GetStyleFromVTKPlot() const;

public slots:

	void StyleChangedSlot(const QString& style);
	void ColorChangedSlot(const QColor& color);
	void WidthChangedSlot(const int& width);
	void OpacityChangedSlot(const double& opacity);
};

EndForgVisualLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)

#endif // !_FrgVisual_Plot2DLnStyle_TItem_Header
