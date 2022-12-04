#pragma once
#ifndef _FrgBase_ToolsWidgets_Header
#define _FrgBase_ToolsWidgets_Header

#include <FrgBase_Global.hxx>

class QWidget;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_ToolsWidgets
{

public:

	static void SetGeometry
	(
		QWidget* widget,
		const int PercentageOfScreenW,
		const int PercentageOfScreenH
	);
};

EndForgBaseLib

#endif // !_FrgBase_ToolsWidgets_Header
