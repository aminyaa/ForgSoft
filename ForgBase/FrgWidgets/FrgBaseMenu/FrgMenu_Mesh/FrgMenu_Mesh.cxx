#include <FrgMenu_Mesh.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseMainWindow.hxx>
#include <QtWidgets/QMenuBar>

ForgBaseLib::FrgMenu_Mesh::FrgMenu_Mesh(FrgBaseMainWindow * parentMainWindow)
	: FrgBaseMenu("&Mesh", parentMainWindow)
{
	AddItem(FrgICON_Menu_Mesh_GenerateSurfaceMesh, "Generate &Surface Mesh", "");
	AddItem(FrgICON_Menu_Mesh_GenerateVolumeMesh, "Generate &Volume Mesh", "");
	AddItem(FrgICON_Menu_Mesh_ClearGeneratedMesh, "&Clear Generated Mesh", "");
	AddItem(FrgICON_Menu_Mesh_InitializeMeshing, "&Initialize Meshing", "");

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(GetToolBar());

}