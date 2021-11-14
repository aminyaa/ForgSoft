#include <FrgVisual_CylinderActor.hxx>
#include <FrgVisual_MeshActor.hxx>
#include <FrgBase_Application.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgVisual_Tools.hxx>

#include <vtkObjectFactory.h>
#include <vtkRenderer.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkCylinderSource.h>

#include <BRepPrimAPI_MakeCylinder.hxx>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_CylinderActor);

ForgVisualLib::FrgVisual_CylinderActor::FrgVisual_CylinderActor()
{

}

void ForgVisualLib::FrgVisual_CylinderActor::SetData(ForgBaseLib::FrgBase_Pnt<3> Start, ForgBaseLib::FrgBase_Pnt<3> End, double radius)
{
	SetData(Start.X(), End.X(), Start.Y(), End.Y(), Start.Z(), End.Z(), radius);
}

void ForgVisualLib::FrgVisual_CylinderActor::SetData(double Start_x, double Start_y, double Start_z, double End_x, double End_y, double End_z, double radius)
{
	theStart_.X() = Start_x;
	theStart_.Y() = Start_y;
	theStart_.Z() = Start_z;

	theEnd_.X() = End_x;
	theEnd_.Y() = End_y;
	theEnd_.Z() = End_z;

	theRadius_ = radius;

	try
	{
		gp_Pnt start(theStart_.X(), theStart_.Y(), theStart_.Z());
		gp_Pnt end(theEnd_.X(), theEnd_.Y(), theEnd_.Z());
		gp_Vec V(start, end);
		gp_Dir dir(V.Normalized());
		gp_Ax2 ax(start, dir);

		BRepPrimAPI_MakeCylinder c(ax, theRadius_, V.Magnitude());
		auto shape = c.Shape();

		bool isMeshEmpty = theMesh_.empty();
		std::vector
			<
			std::tuple
			<
			std::vector<ForgBaseLib::FrgBase_Pnt<3>>,
			std::vector<std::tuple<int, int, int>>
			>
			> meshes;

		if (IsRepresentationToSurface())
		{
			meshes = FrgVisual_Tools::GetMeshOnSurfacesFromShape(shape);
		}
		else
		{
			meshes = FrgVisual_Tools::GetMeshOnEdgesFromShape(shape);
		}

		if (!isMeshEmpty && meshes.size() != theMesh_.size())
		{
			if (theRenderer_)
			{
				for (const auto& mesh : theMesh_)
					theRenderer_->RemoveActor(mesh);

				theMesh_.clear();
				isMeshEmpty = true;
			}
		}

		int i = 0;
		for (const auto& mesh : meshes)
		{
			if (isMeshEmpty)
			{
				auto actor = new FrgVisual_MeshActor<3>;

				actor->SetDataTriangulation(std::get<0>(mesh), std::get<1>(mesh));

				theMesh_.push_back(actor);
			}
			else
				theMesh_[i]->SetDataTriangulation(std::get<0>(mesh), std::get<1>(mesh));

			i++;
		}

		for (const auto& mesh : theMesh_)
		{
			if (IsRepresentationToSurface())
			{
				mesh->GetProperty()->SetRepresentationToSurface();
				mesh->GetProperty()->EdgeVisibilityOff();
			}
			else
			{
				mesh->GetProperty()->SetRepresentationToWireframe();
				mesh->GetProperty()->EdgeVisibilityOn();
				mesh->GetProperty()->SetLineWidth(2.0f);
			}
		}
	}
	catch (const Standard_Failure& f)
	{
		/*const auto& app = FrgBase_Application::Instance();
		if (app)
		{
			app->GetParentMainWindow()->PrintErrorToConsole(QString::fromStdString(f.GetMessageString()));
		}*/

		std::exception ex(f.GetMessageString());
		throw ex;
	}

	//// actor
	//vtkNew<vtkCylinderSource> cylinderSource;
	//cylinderSource->SetCenter(0.0, 0.0, 0.0);
	//cylinderSource->SetRadius(0.05);
	//cylinderSource->SetHeight(0.5);
	//cylinderSource->SetResolution(100);

	//// mapper
	//auto cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	//cubeMapper->SetInputConnection(cylinderSource->GetOutputPort());

	//this->SetMapper(cubeMapper);
}

void ForgVisualLib::FrgVisual_CylinderActor::SetRepresentationToSurface()
{
	if (theIsRepresentationToSurface_)
		return;

	theIsRepresentationToSurface_ = true;

	SetData(theStart_, theEnd_, theRadius_);
}

void ForgVisualLib::FrgVisual_CylinderActor::SetRepresentationToWireframe()
{
	if (!theIsRepresentationToSurface_)
		return;

	theIsRepresentationToSurface_ = false;

	SetData(theStart_, theEnd_, theRadius_);
}

void ForgVisualLib::FrgVisual_CylinderActor::SetEdgeColor(double red, double green, double blue)
{
	//this->GetProperty()->SetInterpolationToFlat();
	this->GetProperty()->SetEdgeColor(red, green, blue);
	//this->GetProperty()->SetLineWidth(2.0f);
	/*this->GetProperty()->SetAmbient(0.0);
	this->GetProperty()->SetSpecular(0.0);*/
}

void ForgVisualLib::FrgVisual_CylinderActor::AddActors(vtkRenderer* renderer)
{
	if (renderer)
	{
		for (const auto& mesh : theMesh_)
		{
			mesh->SetRenderer(renderer);
			mesh->AddActors(renderer);
			renderer->AddActor(mesh);
		}
	}
}

void ForgVisualLib::FrgVisual_CylinderActor::RemoveActors(vtkRenderer* renderer)
{
	if (renderer)
	{
		for (const auto& mesh : theMesh_)
			renderer->RemoveActor(mesh);

		theMesh_.clear();
	}
}

bool ForgVisualLib::FrgVisual_CylinderActor::IsSelectable() const
{
	bool result = theIsSelectable_;
	for (const auto& m : theMesh_)
		result = result && m->IsSelectable();

	return result;
}

void ForgVisualLib::FrgVisual_CylinderActor::SetSelectable(bool selectable)
{
	FrgVisual_ConicActor<3>::SetSelectable(selectable);

	for (const auto& m : theMesh_)
		m->SetSelectable(selectable);
}

bool ForgVisualLib::FrgVisual_CylinderActor::IsSelected() const
{
	bool result = theIsSelectable_;
	for (const auto& m : theMesh_)
		result = result && m->IsSelected();

	return result;
}

void ForgVisualLib::FrgVisual_CylinderActor::SetColor(double red, double green, double blue)
{
	FrgVisual_ConicActor<3>::SetColor(red, green, blue);

	for (const auto& m : theMesh_)
		m->SetColor(red, green, blue);
}

void ForgVisualLib::FrgVisual_CylinderActor::SetColor(double a[3])
{
	FrgVisual_ConicActor<3>::SetColor(a);

	for (const auto& m : theMesh_)
		m->SetColor(a);
}

void ForgVisualLib::FrgVisual_CylinderActor::SetColor(const QColor& color)
{
	FrgVisual_ConicActor<3>::SetColor(color);

	for (const auto& m : theMesh_)
		m->SetColor(color);
}

void ForgVisualLib::FrgVisual_CylinderActor::SetSelectingColor(const QColor& color)
{
	FrgVisual_ConicActor<3>::SetSelectingColor(color);

	for (const auto& m : theMesh_)
		m->SetSelectingColor(color);
}

QColor ForgVisualLib::FrgVisual_CylinderActor::GetSelectingColor() const
{
	return FrgVisual_ConicActor<3>::GetSelectingColor();
}

double* ForgVisualLib::FrgVisual_CylinderActor::GetColor()
{
	return FrgVisual_ConicActor<3>::GetColor();
}

void ForgVisualLib::FrgVisual_CylinderActor::GetColor(double rgb[3])
{
	FrgVisual_ConicActor<3>::GetColor(rgb);
}

void ForgVisualLib::FrgVisual_CylinderActor::GetColor(double& r, double& g, double& b)
{
	FrgVisual_ConicActor<3>::GetColor(r, g, b);
}

bool ForgVisualLib::FrgVisual_CylinderActor::SelectActor(const QColor& color)
{
	auto res = FrgVisual_ConicActor<3>::SelectActor(color);

	for (const auto& m : theMesh_)
		res = res && m->SelectActor(color);

	return res;
}

bool ForgVisualLib::FrgVisual_CylinderActor::SelectActor()
{
	auto res = FrgVisual_ConicActor<3>::SelectActor();

	for (const auto& m : theMesh_)
		res = res && m->SelectActor();

	return res;
}

bool ForgVisualLib::FrgVisual_CylinderActor::UnSelectActor()
{
	auto res = FrgVisual_ConicActor<3>::UnSelectActor();

	for (const auto& m : theMesh_)
		res = res && m->UnSelectActor();

	return res;
}

bool ForgVisualLib::FrgVisual_CylinderActor::HideActor()
{
	auto res = FrgVisual_ConicActor<3>::HideActor();

	for (const auto& m : theMesh_)
		res = res && m->HideActor();

	return res;
}

bool ForgVisualLib::FrgVisual_CylinderActor::UnHideActor()
{
	auto res = FrgVisual_ConicActor<3>::UnHideActor();

	for (const auto& m : theMesh_)
		res = res && m->UnHideActor();

	return res;
}

void ForgVisualLib::FrgVisual_CylinderActor::SetVisibility(vtkTypeBool _arg)
{
	FrgVisual_ConicActor<3>::SetVisibility(_arg);

	for (const auto& m : theMesh_)
		m->SetVisibility(_arg);
}

void ForgVisualLib::FrgVisual_CylinderActor::VisibilityOn()
{
	FrgVisual_ConicActor<3>::VisibilityOn();

	for (const auto& m : theMesh_)
		m->VisibilityOn();
}

void ForgVisualLib::FrgVisual_CylinderActor::VisibilityOff()
{
	FrgVisual_ConicActor<3>::VisibilityOff();

	for (const auto& m : theMesh_)
		m->VisibilityOff();
}

double ForgVisualLib::FrgVisual_CylinderActor::GetOpacity()
{
	return FrgVisual_ConicActor<3>::GetOpacity();
}

void ForgVisualLib::FrgVisual_CylinderActor::SetOpacity(double opacity)
{
	FrgVisual_ConicActor<3>::SetOpacity(opacity);

	for (const auto& mesh : theMesh_)
		mesh->SetOpacity(opacity);
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_CylinderActor::GetActorType() const
{
	return FrgVisual_BaseActor_Entity::ActorType::Cylinder;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_CylinderActor::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Cylinder);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Conic);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Solid);

	return types;
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_CylinderActor::GetActorDimension() const
{
	return FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_CylinderActor)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_ConicActor<3>>(*this);

	ar& theStart_;
	ar& theEnd_;
	ar& theRadius_;
	ar& theIsRepresentationToSurface_;
	ar& theMesh_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_CylinderActor)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_ConicActor<3>>(*this);

	ar& theStart_;
	ar& theEnd_;
	ar& theRadius_;
	ar& theIsRepresentationToSurface_;
	ar& theMesh_;

	SetData(theStart_, theEnd_, theRadius_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CylinderActor)