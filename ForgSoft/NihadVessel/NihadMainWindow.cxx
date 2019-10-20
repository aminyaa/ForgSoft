#include <NihadMainWindow.hxx>
#include <FrgBaseTree.hxx>
#include <NihadTree.hxx>
#include <NihadTree.hxx>
#include <NihadVesselPartTreeItem.hxx>

#include <IO_IGES.hxx>
#include <FastDiscrete_Params.hxx>
#include <TModel_Tools.hxx>
#include <Cad3d_TModel.hxx>
#include <Cad_EntityManager.hxx>
#include <Cad_BlockEntity.hxx>

#include <QtWidgets/QFileDialog>

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
	QfileTypes.push_back("IGES (*.igs)");
	QfileTypes.push_back("STEP (*.stp; *.step)");

	QString fileTypes;
	for (int i = 0; i < QfileTypes.size() - 1; i++)
	{
		fileTypes += QfileTypes.at(i);
		fileTypes += ";;";
	}
	fileTypes += QfileTypes.at(QfileTypes.size() - 1);

	QString* ext = new QString("IGES");
	QString fileName = QFileDialog::getOpenFileName(this,
		QMainWindow::tr("Export Part"), "",
		fileTypes, ext);

	if (fileName.isEmpty())
		return;
	else
	{
		if (*ext == "IGES (*.igs)")
		{
			AutLib::IO_IGES reader(AutLib::gl_fast_discrete_parameters);
			reader.Verbose() = 1;
			reader.ReadFile(fileName.toStdString());

			auto surfaces = AutLib::TModel_Tools::GetSurfaces(reader.Shape());
			auto solid = AutLib::Cad3d_TModel::MakeSolid(surfaces, 1.0e-6);

			((NihadTree*)GetTree())->GetPartTreeItems().push_back(FrgMakeSharedPtr(NihadVesselPartTreeItem)(fileName, GetTree()->GetTreeItem("Parts"), GetTree(), this));

			((NihadTree*)GetTree())->GetPartTreeItems().at(((NihadTree*)GetTree())->GetPartTreeItems().size() - 1)->GetTModel() = solid;
		}
		else if (*ext == "STEP (*.stp; *.step)")
		{}
	}

	ParseInfoToConsole("\"" + fileName + "\" imported successfully.\"");
}