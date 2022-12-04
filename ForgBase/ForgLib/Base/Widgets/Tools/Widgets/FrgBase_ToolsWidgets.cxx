#include "FrgBase_ToolsWidgets.hxx"

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

void ForgBaseLib::FrgBase_ToolsWidgets::SetGeometry
(
	QWidget* widget,
	const int PercentageOfScreenW,
	const int PercentageOfScreenH
)
{
	if (!widget)
		return;

	if (PercentageOfScreenW < 0 || PercentageOfScreenW > 100)
		return;

	if (PercentageOfScreenH < 0 || PercentageOfScreenH > 100)
		return;

	const QRect rect = QApplication::desktop()->screenGeometry();
	const int screen_width = rect.width();
	const int screen_height = rect.height();

	//Represent Percentage in decimals
	const float PercentageOfScreenFloatW = static_cast<float>(PercentageOfScreenW) / 100.0;
	const float PercentageOfScreenFloatH = static_cast<float>(PercentageOfScreenH) / 100.0;

	//Calculate w and h
	int w = (PercentageOfScreenFloatW * screen_width);
	int h = (PercentageOfScreenFloatH * screen_height);

	//Check for max and min size hints
	const int minW = widget->minimumWidth();
	const int minH = widget->minimumHeight();

	const int maxW = widget->maximumWidth();
	const int maxH = widget->maximumHeight();

	if (w < minW || h < minH)
	{
		w = minW;
		h = minH;
	}
	else if (w > maxW || h > maxH)
	{
		w = maxW;
		h = maxH;
	}

	//Now Calculate x and y
	int x = screen_width / 2;
	x = x - w / 2;

	int y = screen_height / 2;
	y = y - h / 2;

	widget->setGeometry(x, y, w, h);
}