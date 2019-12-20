#pragma once
#ifndef _AnalyzePart_Header
#define _AnalyzePart_Header

#include <FrgBaseGlobals.hxx>
#include <CadAnalys_tModel.hxx>
#include <vtkSmartPointer.h>

#include <QtWidgets/QWidget>

class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QPushButton;
class QDockWidget;

class vtkActor;

namespace AutLib
{
	class TModel_Surface;
	class Pnt3d;

	template<class T>
	class GeoSizeFun_Uniform;
}

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseCADPart_Entity;
class FrgBaseCADScene;

class AnalyzePart : public QWidget
{
	Q_OBJECT

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
		QPushButton* theAnalyzeButton_ = FrgNullPtr;
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
	ButtonItems_Struct* theButtonItems_ = FrgNullPtr;

	QVBoxLayout* theMainLayout_ = FrgNullPtr;
	QDockWidget* theDockWidget_ = FrgNullPtr;

	QList<FrgBaseCADScene*> thePointerToScenes_;
	QList<QMap<std::shared_ptr<AutLib::TModel_Surface>, vtkSmartPointer<vtkActor>>> theListOfMapTModelSurfaceToActor_;

	std::shared_ptr<AutLib::CadAnalys_tModel> theAnalyzeObject_;
	std::shared_ptr<AutLib::GeoSizeFun_Uniform<AutLib::Pnt3d>> theAnalyzeSizeFunction_;
	std::vector<std::shared_ptr<AutLib::TModel_Surface>> theSurfaces_;

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
		FrgBaseCADPart_Entity* parentPart,
		QList<FrgBaseCADScene*> pointerToScenes
	);

public slots:

	void AnalyzeClickedSlot(bool);
	void CloseButtonClickedSlot(bool);

};

EndFrgBaseLib

#endif // !_AnalyzePart_Header
