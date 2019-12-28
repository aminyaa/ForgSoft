#include <NihadMainWindow.hxx>
#include <FrgBaseTree.hxx>
#include <NihadTree.hxx>
#include <NihadTree.hxx>
#include <NihadVesselPartTreeItem.hxx>
#include <FrgBaseGlobalsThread.hxx>
#include <CADPartItem.hxx>
#include <CAD_PartItem.hxx>
#include <SplitPart_Feature.hxx>

#include <IO_IGES.hxx>
#include <IO_STEP.hxx>
#include <FastDiscrete_Params.hxx>
#include <TModel_Tools.hxx>
#include <Cad3d_TModel.hxx>
#include <Cad_EntityManager.hxx>
#include <Cad_BlockEntity.hxx>
#include <TModel_Surface.hxx>
#include <TModel_Paired.hxx>

#include <QtWidgets/QFileDialog>
#include <QtCore/QMutex>

ForgBaseLib::NihadMainWindow::NihadMainWindow(QWidget* parent)
	: FrgBaseMainWindow(parent)
{
	this->setMinimumSize(QSize(1366, 768));
}

void ForgBaseLib::NihadMainWindow::CreateTree()
{
	GetTree() = FrgNew NihadTree(this);
}

void ForgBaseLib::NihadMainWindow::FileImportActionSlot()
{
	QList<QString> QfileTypes;
	QfileTypes.push_back("All Supported Files (*.igs; *.iges; *.stp; *.step)");
	QfileTypes.push_back("IGES (*.igs)");
	QfileTypes.push_back("STEP (*.stp; *.step)");

	QString fileTypes;
	for (int i = 0; i < QfileTypes.size() - 1; i++)
	{
		fileTypes += QfileTypes.at(i);
		fileTypes += ";;";
	}
	fileTypes += QfileTypes.at(QfileTypes.size() - 1);

	QString* ext = new QString("All Supported Files");
	QString fileName = QFileDialog::getOpenFileName(this,
		QMainWindow::tr("Export Part"), "",
		fileTypes, ext);

	if (fileName.isEmpty())
		return;
	else
	{
		if (fileName.contains(".igs") || fileName.contains(".iges"))
		{
			std::shared_ptr<AutLib::FastDiscrete_Params> fastParameters = std::make_shared<AutLib::FastDiscrete_Params>();
			fastParameters->InParallel = true;
			fastParameters->Angle = 2.5;
			fastParameters->Deflection = 0.1;

			AutLib::IO_IGES reader(fastParameters);
			reader.Verbose() = 2;

			FrgExecuteFunctionInProcess(this, reader.ReadFile(fileName.toStdString());, FrgNullPtr, std::cout << "";);
			
			auto solid = AutLib::Cad3d_TModel::MakeSolid(reader.Shape(), 1.0e-6);
			QString bareFileName = QFileInfo(fileName).fileName();
			bareFileName.remove(".igs");
			bareFileName.remove(".iges");

			dynamic_cast<NihadTree*>(GetTree())->GetPartTreeItems().push_back
			(
				FrgNew CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>
				(
					CorrectName<FrgBaseTreeItem>(GetTree()->GetTreeItem("Parts"), bareFileName), GetTree()->GetTreeItem("Parts"), solid
				)
			);

			std::vector<std::shared_ptr<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>>> blocksForSurfaces;
			std::vector<std::shared_ptr<AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>> blocksForCurves;
			solid->Faces()->RetrieveTo(blocksForSurfaces);
			solid->Segments()->RetrieveTo(blocksForCurves);

			CAD_PartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>* ex_part =
				new CAD_PartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>
				("ex_part", GetTree()->GetTreeItem("Parts"), solid);

			/*FrgBaseCAD_Part<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>* ex_part =
				new FrgBaseCAD_Part<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>
				("ex_part", GetTree()->GetTreeItem("Parts"), blocksForSurfaces, blocksForCurves);*/

			SplitPart_Feature<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>>* spl = FrgNew SplitPart_Feature<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>>
				(this, ex_part->GetSurfacesFeatures()->GetFeature(0), solid->Faces());

			/*((NihadTree*)GetTree())->GetPartTreeItems().push_back
			(
				FrgNew NihadVesselPartTreeItem
				(
					CorrectName<FrgBaseTreeItem>(GetTree()->GetTreeItem("Parts"), bareFileName), GetTree()->GetTreeItem("Parts"), solid
					)
			);*/
		}
		else if (fileName.contains(".stp") || fileName.contains(".step"))
		{
			std::shared_ptr<AutLib::FastDiscrete_Params> fastParameters = std::make_shared<AutLib::FastDiscrete_Params>();
			fastParameters->InParallel = true;
			fastParameters->Angle = 2.5;
			fastParameters->Deflection = 0.1;

			AutLib::IO_STEP reader(fastParameters);
			reader.Verbose() = 2;
			
			FrgExecuteFunctionInProcess(this, reader.ReadFile(fileName.toStdString().c_str());, FrgNullPtr, std::cout << "";, FrgNullPtr);

			auto solid = AutLib::Cad3d_TModel::MakeSolid(reader.Shape(), 1.0e-6);
			QString bareFileName = QFileInfo(fileName).fileName();
			bareFileName.remove(".stp");
			bareFileName.remove(".step");

			dynamic_cast<NihadTree*>(GetTree())->GetPartTreeItems().push_back
			(
				FrgNew CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>
				(
					CorrectName<FrgBaseTreeItem>(GetTree()->GetTreeItem("Parts"), bareFileName), GetTree()->GetTreeItem("Parts"), solid
					)
			);
		}
	}

	ParseInfoToConsole("\"" + fileName + "\" imported successfully.\"");
}