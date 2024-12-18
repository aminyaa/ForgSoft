#include <FrgBase_StylesMenuItemStyle.hxx>

ForgBaseLib::FrgBase_StylesMenuItemStyle::FrgBase_StylesMenuItemStyle()
	: FrgBase_MainStyle()
	, theIconSize_(40)
{

}

ForgBaseLib::FrgBase_StylesMenuItemStyle::FrgBase_StylesMenuItemStyle(QStyle* style)
	: FrgBase_MainStyle(style)
	, theIconSize_(40)
{

}

int ForgBaseLib::FrgBase_StylesMenuItemStyle::pixelMetric
(
	PixelMetric metric,
	const QStyleOption* option,
	const QWidget* widget
) const
{
	if (metric == QStyle::PM_SmallIconSize)
		return theIconSize_;
	else
		return QProxyStyle::pixelMetric(metric, option, widget);
}