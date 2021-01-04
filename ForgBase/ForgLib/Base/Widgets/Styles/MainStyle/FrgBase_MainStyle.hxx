#pragma once
#ifndef _FrgBase_MainStyle_Header
#define _FrgBase_MainStyle_Header

#include <FrgBase_Global.hxx>

#include <QApplication>
#include <QFile>
#include <QFont>
#include <QProxyStyle>
#include <QStyleFactory>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_MainStyle
	: public QProxyStyle
{
	Q_OBJECT

public:
	FrgBase_MainStyle(bool darkMode = true);
	explicit FrgBase_MainStyle(QStyle* style);

	QStyle* baseStyle() const;

	void polish(QPalette& palette) override;
	void polish(QApplication* app) override;

	int pixelMetric(PixelMetric metric, const QStyleOption* option = nullptr, const QWidget* widget = nullptr) const override;

	bool IsThemeDark() const { return theIsDarkMode_; }
	void SetThemeDark(bool darkMode);

private:
	
	QStyle* styleBase(QStyle* style = Q_NULLPTR) const;

	QApplication* theQApplication_ = nullptr;
	int* theDefaultFontSize_ = nullptr;
	bool theIsDarkMode_;
};

EndForgBaseLib

#endif // !_FrgBase_MainStyle_Header
