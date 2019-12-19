#include <AnalyzePart.hxx>
#include <FrgBaseMainWindow.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDockWidget>

#include <FrgBaseCADPart.hxx>
#include <FrgBaseCADScene.hxx>
#include <CADPartItem.hxx>
#include <CADScene.hxx>

#include <CadAnalys_Model_System.hxx>
#include <GeoSizeFun_Uniform.hxx>
#include <CadRepair_Patch.hxx>
#include <vtkActor.h>
#include <vtkProperty.h>

ForgBaseLib::AnalyzePart::AnalyzePart
(
	FrgString name,
	FrgBaseMainWindow* parentMainWindow,
	FrgBaseCADPart_Entity* parentPart,
	QList<FrgBaseCADScene*> pointerToScenes
)
	: QWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
	, theParentPart_(parentPart)
	, thePointerToScenes_(pointerToScenes)
{
	theMainLayout_ = FrgNew QVBoxLayout;
	theTitle_ = FrgNew QLabel("Analyze " + name);
	theContainerLayout_ = FrgNew QGridLayout;
	theButtonLayout_ = FrgNew QHBoxLayout;
	theContainerItems_ = FrgNew ContainerItems_Struct;
	theButtonItems_ = FrgNew ButtonItems_Struct;

	theContainerItems_->theNbCommonSingularitiesLabel_ = FrgNew QLabel("Number of Common Singularities");
	theContainerItems_->theNbDefectsLabel_ = FrgNew QLabel("Number of Defects");
	theContainerItems_->theNbDeepSingularitiesLabel_ = FrgNew QLabel("Number of Deep Singularities");
	theContainerItems_->theNbRegularsLabel_ = FrgNew QLabel("Number of Regulars");

	theContainerItems_->theNbCommonSingularitiesValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbCommonSingularitiesValue_->setMinimumWidth(75);
	theContainerItems_->theNbDefectsValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbDefectsValue_->setMinimumWidth(75);
	theContainerItems_->theNbDeepSingularitiesValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbDeepSingularitiesValue_->setMinimumWidth(75);
	theContainerItems_->theNbRegularsValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbRegularsValue_->setMinimumWidth(75);

	theButtonItems_->theRepairButton_ = FrgNew QPushButton("Repair");
	theButtonItems_->theCloseButton_ = FrgNew QPushButton("Close");
	theButtonItems_->theAnalyzeButton_ = FrgNew QPushButton("Analyze");

	QHBoxLayout* hLayout = FrgNew QHBoxLayout;

	theContainerLayout_->addWidget(theContainerItems_->theNbCommonSingularitiesLabel_, 0, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbCommonSingularitiesValue_, 0, 1);
	theContainerLayout_->addWidget(theContainerItems_->theNbDefectsLabel_, 1, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbDefectsValue_, 1, 1);
	theContainerLayout_->addWidget(theContainerItems_->theNbDeepSingularitiesLabel_, 2, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbDeepSingularitiesValue_, 2, 1);
	theContainerLayout_->addWidget(theContainerItems_->theNbRegularsLabel_, 3, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbRegularsValue_, 3, 1);
	theContainerLayout_->addWidget(theButtonItems_->theAnalyzeButton_, 4, 0);
	hLayout->addLayout(theContainerLayout_);
	hLayout->addStretch(1);

	theButtonLayout_->addWidget(theButtonItems_->theRepairButton_);
	theButtonLayout_->addWidget(theButtonItems_->theCloseButton_);
	theButtonLayout_->addStretch(1);

	theMainLayout_->addWidget(theTitle_);
	theMainLayout_->addLayout(hLayout);
	theMainLayout_->addStretch(1);
	theMainLayout_->addLayout(theButtonLayout_);

	this->setLayout(theMainLayout_);

	theDockWidget_ = new QDockWidget("Analyze " + name, theParentMainWindow_);
	theDockWidget_->setTitleBarWidget(new QWidget);
	theParentMainWindow_->tabifyDockWidget(theParentMainWindow_->GetTreeWidget()->theDockWidget_, theDockWidget_);
	theParentMainWindow_->tabifiedDockWidgetActivated(theDockWidget_);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(false);
	theDockWidget_->setWidget(this);

	theDockWidget_->show();
	theDockWidget_->raise();

	connect(theButtonItems_->theAnalyzeButton_, SIGNAL(clicked(bool)), this, SLOT(AnalyzeClickedSlot(bool)));
	connect(theButtonItems_->theCloseButton_, SIGNAL(clicked(bool)), this, SLOT(CloseButtonClickedSlot(bool)));

	SetNbCommonSingularities(0);
	SetNbDefects(0);
	SetNbDeepSingularities(0);
	SetNbRegulars(0);

	/* ============================================================================================================================================ */
	auto castedPart = dynamic_cast<CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>*>(theParentPart_);

	if (!castedPart)
	{
		std::cout << "castedPart is null in AnalyzePart::AnalyzeClickedSlot(bool)\n";
		return;
	}

	for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		if (!(thePointerToScenes_[iScene]->GetActors().isEmpty()))
			for (int i = 0; i < thePointerToScenes_[iScene]->GetActors().size(); i++)
				thePointerToScenes_[iScene]->GetActors()[i]->SetVisibility(false);

	//auto blocks = castedPart->GetSurfaces();
	std::vector<std::shared_ptr<AutLib::TModel_Surface>> surfaces;
	castedPart->GetModel()->RetrieveFacesTo(surfaces);

	/*for (int iBlock = 0; iBlock < blocks.size(); iBlock++)
	{
		std::vector<std::shared_ptr<AutLib::TModel_Surface>> surfacesTmp;
		blocks[iBlock]->RetrieveEntitiesTo(surfacesTmp);
		for (int i = 0; i < surfacesTmp.size(); i++)
			surfaces.push_back(surfacesTmp[i]);
	}*/

	for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
	{

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		{
			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
			if (!scene) continue;

			scene->CreateActor(surfaces[iSurface], FrgNullPtr);

			theListOfMapTModelSurfaceToActor_.push_back
			(
				QMap<std::shared_ptr<AutLib::TModel_Surface>, vtkSmartPointer<vtkActor>>()
			);

			theListOfMapTModelSurfaceToActor_.last().insert(surfaces[iSurface], scene->GetActors().last());
		}
	}
}

void ForgBaseLib::AnalyzePart::SetNbCommonSingularities(int number)
{
	// Yellow
	theContainerItems_->theNbCommonSingularitiesValue_->setText(QString::number(number));

	/*theContainerItems_->theNbCommonSingularitiesValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(60, 186, 162, 255), stop : 1 rgba(98, 211, 162, 255))"
	);*/

	theContainerItems_->theNbCommonSingularitiesValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(247, 220, 111, 255), stop : 1 rgba(241, 196, 15, 255))"
	);
}

void ForgBaseLib::AnalyzePart::SetNbDefects(int number)
{
	// Red
	theContainerItems_->theNbDefectsValue_->setText(QString::number(number));

	theContainerItems_->theNbDefectsValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(236, 112, 99, 255), stop : 1 rgba(231, 76, 60, 255))"
	);
}

void ForgBaseLib::AnalyzePart::SetNbDeepSingularities(int number)
{
	// Purple
	theContainerItems_->theNbDeepSingularitiesValue_->setText(QString::number(number));

	theContainerItems_->theNbDeepSingularitiesValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(165, 105, 189, 255), stop : 1 rgba(142, 68, 173, 255))"
	);
}

void ForgBaseLib::AnalyzePart::SetNbRegulars(int number)
{
	// Blue
	theContainerItems_->theNbRegularsValue_->setText(QString::number(number));

	theContainerItems_->theNbRegularsValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(52, 152, 219, 255), stop : 1 rgba(46, 134, 193, 255))"
	);
}

void ForgBaseLib::AnalyzePart::AnalyzeClickedSlot(bool)
{
	auto castedPart = dynamic_cast<CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>*>(theParentPart_);

	if (!castedPart)
	{
		std::cout << "castedPart is null in AnalyzePart::AnalyzeClickedSlot(bool)\n";
		return;
	}

	//if (!theAnalyzeObject_)
	//{
		auto tModel = castedPart->GetModel();
		auto sizeFun = std::make_shared<AutLib::GeoSizeFun_Uniform<AutLib::Pnt3d>>(0.1, tModel->BoundingBox());
		std::vector<std::shared_ptr<AutLib::TModel_Surface>> surfaces;
		tModel->RetrieveFacesTo(surfaces);

		AutLib::cadAnalysSys::init_model_analysis_info();
		AutLib::cadAnalysSys::gl_model_analysis_info->SetVerbisity(1);
		theAnalyzeObject_ = std::make_shared<AutLib::CadAnalys_tModel>(surfaces, sizeFun, AutLib::cadAnalysSys::gl_model_analysis_info);
	//}

	theAnalyzeObject_->Perform();

	SetNbCommonSingularities(theAnalyzeObject_->NbCommonSingularities());
	SetNbDefects(theAnalyzeObject_->NbDefects());
	SetNbDeepSingularities(theAnalyzeObject_->NbDeepSingularities());
	SetNbRegulars(theAnalyzeObject_->NbRegulars());

	auto commonSingulars = theAnalyzeObject_->CommonSingulars();
	auto defects = theAnalyzeObject_->Defects();
	auto deepSingulars = theAnalyzeObject_->DeepSingulars();
	auto regulars = theAnalyzeObject_->Regulars();

	std::map<Standard_Integer, std::shared_ptr<AutLib::CadRepair_Patch<AutLib::TModel_Surface>>>::iterator it;
	for (it = commonSingulars.begin(); it != commonSingulars.end(); it++)
	{
		//x.second(x.first())->Surface();
	}

	for (const auto& x : commonSingulars)
	{
		for (int i = 0; i < theListOfMapTModelSurfaceToActor_.size(); i++)
		{
			if (theListOfMapTModelSurfaceToActor_[i].contains(x.second->Surface()))
				theListOfMapTModelSurfaceToActor_[i].value(x.second->Surface())->GetProperty()->SetColor(0.9451, 0.768627, 0.058824); // Yellow
		}

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
			thePointerToScenes_[iScene]->Render(FrgFalse);
	}

	for (const auto& x : defects)
	{
		for (int i = 0; i < theListOfMapTModelSurfaceToActor_.size(); i++)
		{
			if (theListOfMapTModelSurfaceToActor_[i].contains(x.second->Surface()))
				theListOfMapTModelSurfaceToActor_[i].value(x.second->Surface())->GetProperty()->SetColor(0.90588, 0.29804, 0.235294); // Red
		}

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
			thePointerToScenes_[iScene]->Render(FrgFalse);
	}

	for (const auto& x : deepSingulars)
	{
		for (int i = 0; i < theListOfMapTModelSurfaceToActor_.size(); i++)
		{
			if (theListOfMapTModelSurfaceToActor_[i].contains(x.second->Surface()))
				theListOfMapTModelSurfaceToActor_[i].value(x.second->Surface())->GetProperty()->SetColor(0.556863, 0.266667, 0.6784314); // Purple
		}

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
			thePointerToScenes_[iScene]->Render(FrgFalse);
	}

	for (const auto& x : regulars)
	{
		for (int i = 0; i < theListOfMapTModelSurfaceToActor_.size(); i++)
		{
			if (theListOfMapTModelSurfaceToActor_[i].contains(x.second->Surface()))
				theListOfMapTModelSurfaceToActor_[i].value(x.second->Surface())->GetProperty()->SetColor(0.180392, 0.52549, 0.756863); // Blue
		}

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
			thePointerToScenes_[iScene]->Render(FrgFalse);
	}
}

void ForgBaseLib::AnalyzePart::CloseButtonClickedSlot(bool)
{
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(true);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->show();
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->raise();
	theParentMainWindow_->removeDockWidget(theDockWidget_);

	for (int i = 0; i < theListOfMapTModelSurfaceToActor_.size(); i++)
	{
		int iScene = 0;
		for (auto it = theListOfMapTModelSurfaceToActor_[i].begin(); it != theListOfMapTModelSurfaceToActor_[i].end(); it++)
		{
			thePointerToScenes_[iScene]->RemoveActor(it.value());
			thePointerToScenes_[iScene]->GetActors().removeOne(it.value());
			iScene++;
		}
	}

	for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
	{
		auto actors = thePointerToScenes_[iScene]->GetActors();

		for (int iActor = 0; iActor < actors.size(); iActor++)
		{
			actors[iActor]->VisibilityOn();
		}

		thePointerToScenes_[iScene]->Render(FrgFalse);
	}
}