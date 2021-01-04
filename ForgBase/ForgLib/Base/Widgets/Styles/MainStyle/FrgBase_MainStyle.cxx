#include <FrgBase_MainStyle.hxx>

#include <QtWidgets/QStyleOption>

ForgBaseLib::FrgBase_MainStyle::FrgBase_MainStyle(bool darkMode)
	: FrgBase_MainStyle(styleBase())
{
	theIsDarkMode_ = darkMode;
}

ForgBaseLib::FrgBase_MainStyle::FrgBase_MainStyle(QStyle* style)
	: QProxyStyle(style)
{

}

QStyle* ForgBaseLib::FrgBase_MainStyle::styleBase(QStyle* style) const
{
	static QStyle* base =
		!style ? QStyleFactory::create(QStringLiteral("Fusion")) : style;
	return base;
}

QStyle* ForgBaseLib::FrgBase_MainStyle::baseStyle() const
{
	return styleBase();
}

void ForgBaseLib::FrgBase_MainStyle::polish(QPalette& palette)
{
	if (!theIsDarkMode_)
	{
		QProxyStyle::polish(palette);
	}
	else
	{// modify palette to dark
		palette.setColor(QPalette::Window, QColor(53, 53, 53));
		palette.setColor(QPalette::WindowText, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::WindowText,
			QColor(127, 127, 127));
		palette.setColor(QPalette::Base, QColor(42, 42, 42));
		palette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
		palette.setColor(QPalette::ToolTipBase, Qt::white);
		palette.setColor(QPalette::ToolTipText, QColor(53, 53, 53));
		palette.setColor(QPalette::Text, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
		palette.setColor(QPalette::Dark, QColor(35, 35, 35));
		palette.setColor(QPalette::Shadow, QColor(20, 20, 20));
		palette.setColor(QPalette::Button, QColor(53, 53, 53));
		palette.setColor(QPalette::ButtonText, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::ButtonText,
			QColor(127, 127, 127));
		palette.setColor(QPalette::BrightText, Qt::red);
		palette.setColor(QPalette::Link, QColor(42, 130, 218));
		palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
		palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
		palette.setColor(QPalette::HighlightedText, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(127, 127, 127));
	}
}

void ForgBaseLib::FrgBase_MainStyle::polish(QApplication* app)
{
	if (!app) return;

	if (!theQApplication_)
		theQApplication_ = app;

	// increase font size for better reading,
	// setPointSize was reduced from +2 because when applied this way in Qt5, the
	// font is larger than intended for some reason

	if (!theDefaultFontSize_)
	{
		QFont defaultFont = QApplication::font();
		theDefaultFontSize_ = new int(defaultFont.pointSize() + 1);
		defaultFont.setPointSize(*theDefaultFontSize_);
		app->setFont(defaultFont);
	}

	if (theIsDarkMode_)
	{// loadstylesheet
		QFile qfDarkstyle(QStringLiteral(":/styles/DarkStyle/DarkStyle.qss"));
		if (qfDarkstyle.open(QIODevice::ReadOnly | QIODevice::Text)) {
			// set stylesheet
			QString qsStylesheet = QString::fromLatin1(qfDarkstyle.readAll());
			app->setStyleSheet(qsStylesheet);
			qfDarkstyle.close();
		}
	}
	else
	{
		QFile qfStyle(QStringLiteral(":/styles/Default/Default.qss"));
		if (qfStyle.open(QIODevice::ReadOnly | QIODevice::Text)) {
			// set stylesheet
			QString qsStylesheet = QString::fromLatin1(qfStyle.readAll());
			app->setStyleSheet(qsStylesheet);
			qfStyle.close();
		}
	}
}

int ForgBaseLib::FrgBase_MainStyle::pixelMetric
(
	PixelMetric metric,
	const QStyleOption* option,
	const QWidget* widget
) const
{
	return QProxyStyle::pixelMetric(metric, option, widget);
}

void ForgBaseLib::FrgBase_MainStyle::SetThemeDark(bool darkMode)
{
	if (theIsDarkMode_ == darkMode)
		return;
	
	theIsDarkMode_ = darkMode;

	theQApplication_->setStyle(this);
}