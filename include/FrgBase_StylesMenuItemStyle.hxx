#pragma once
#ifndef _FrgBase_StylesMenuItemStyle_Header
#define _FrgBase_StylesMenuItemStyle_Header

#include <FrgBase_StylesDarkStyle.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_StylesMenuItemStyle
	: public QProxyStyle
{
	Q_OBJECT

public:

	FrgBase_StylesMenuItemStyle();
	explicit FrgBase_StylesMenuItemStyle(QStyle* style);

	int pixelMetric
	(
		PixelMetric metric,
		const QStyleOption* option = nullptr,
		const QWidget* widget = nullptr
	) const override;

	const int GetIconSize() const { return theIconSize_; }
	void SetIconSize(int iconSize) { theIconSize_ = iconSize; }
	
private:

	int theIconSize_;
};

EndForgBaseLib

#endif // !_FrgBase_StylesMenuItemStyle_Header