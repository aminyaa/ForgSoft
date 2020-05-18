#pragma once
#ifndef _FrgBase_PrptsVrntWdgColor_Label_Header
#define _FrgBase_PrptsVrntWdgColor_Label_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QLabel>

BeginForgBaseLib

class FrgBase_PrptsWdgColor;

class FORGBASE_EXPORT FrgBase_PrptsVrntWdgColor_Label
	: public QLabel
{

	Q_OBJECT

public:

	FrgBase_PrptsVrntWdgColor_Label
	(
		const QString& title,
		FrgBase_PrptsWdgColor* parent = nullptr
	);

protected:

	void mousePressEvent(QMouseEvent *ev) override;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntWdgColor_Label_Header
