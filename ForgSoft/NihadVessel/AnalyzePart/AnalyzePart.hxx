#pragma once
#ifndef _AnalyzePart_Header
#define _AnalyzePart_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QWidget>

class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QPushButton;

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseCADPart_Entity;

class AnalyzePart : public QWidget
{

	struct ContainerItems_Struct
	{
		QLabel* theNbCommonSingularitiesLabel_ = FrgNullPtr;
		QPushButton* theNbCommonSingularitiesValue_ = FrgNullPtr;

		QLabel* theNbDefectsLabel_ = FrgNullPtr;
		QPushButton* theNbDefectsValue_ = FrgNullPtr;

		QLabel* theNbDeepSingularitiesLabel_ = FrgNullPtr;
		QPushButton* theNbDeepSingularitiesValue_ = FrgNullPtr;

		QLabel* theNbRegularsLabel_ = FrgNullPtr;
		QPushButton* theNbRegularsValue_ = FrgNullPtr;
	};

	struct ButtonItems_Struct
	{
		QPushButton* theRepairButton_ = FrgNullPtr;
		QPushButton* theCloseButton_ = FrgNullPtr;
	};

private:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgBaseCADPart_Entity* theParentPart_ = FrgNullPtr;

	QLabel* theTitle_ = FrgNullPtr;
	QGridLayout* theContainerLayout_ = FrgNullPtr;
	QHBoxLayout* theButtonLayout_ = FrgNullPtr;
	ContainerItems_Struct* theContainerItems_ = FrgNullPtr;
	QPushButton* theAnalyzeButton_ = FrgNullPtr;
	ButtonItems_Struct* theButtonItems_ = FrgNullPtr;

	QVBoxLayout* theMainLayout_ = FrgNullPtr;

private:

	void SetNbCommonSingularities(int number);
	void SetNbDefects(int number);
	void SetNbDeepSingularities(int number);
	void SetNbRegulars(int number);

public:

	AnalyzePart
	(
		FrgString name,
		FrgBaseMainWindow* parentMainWindow,
		FrgBaseCADPart_Entity* parentPart
	);

};

EndFrgBaseLib

#endif // !_AnalyzePart_Header
