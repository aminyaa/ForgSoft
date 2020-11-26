#pragma once
#ifndef _FrgBase_StylesDarkStyle_Header
#define _FrgBase_StylesDarkStyle_Header

#include <FrgBase_Global.hxx>

#include <QApplication>
#include <QFile>
#include <QFont>
#include <QProxyStyle>
#include <QStyleFactory>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_StylesDarkStyle
	: public QProxyStyle
{
	Q_OBJECT

public:
	FrgBase_StylesDarkStyle();
	explicit FrgBase_StylesDarkStyle(QStyle* style);

	QStyle* baseStyle() const;

	void polish(QPalette& palette) override;
	void polish(QApplication* app) override;

	int pixelMetric(PixelMetric metric, const QStyleOption* option = nullptr, const QWidget* widget = nullptr) const override;

private:
	QStyle* styleBase(QStyle* style = Q_NULLPTR) const;
};

EndForgBaseLib

#endif // !_FrgBase_StylesDarkStyle_Header
