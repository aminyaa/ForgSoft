#include <CADScene.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseGlobalsThread.hxx>
#include <NihadVesselPartTreeItem.hxx>
#include <array>

#include <vtkRenderer.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>
#include <vtkTransform.h>


#include <Cad3d_TModel.hxx>
#include <FastDiscrete_Params.hxx>
#include <FastDiscrete.hxx>
#include <Poly_Triangulation.hxx>
#include <Cad_Tools.hxx>

std::shared_ptr<AutLib::FastDiscrete_Params> FrgFastParameters_2 = std::make_shared<AutLib::FastDiscrete_Params>();

ForgBaseLib::CADScene::CADScene(FrgBaseTree * parentTree)
	: FrgBaseCADScene(parentTree)
{

}

void ForgBaseLib::CADScene::AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor)
{
	GetRenderer()->AddActor(actor);
}

void ForgBaseLib::CADScene::CreateActor(NihadVesselPartTreeItem* part)
{
	if (GetActors().size() != 0)
	{
		for (int iActor = 0; iActor < GetActors().size(); iActor++)
		{
			GetRenderer()->RemoveActor(GetActors().at(iActor));
		}
		GetActors().clear();
	}

	//FrgFastParameters->Angle = 0.2;
	//FrgFastParameters->Deflection = 0.01;
	FrgFastParameters_2->InParallel = true;

	if (part->GetModel())
	{
		const auto& model = part->GetModel();

		std::vector<std::shared_ptr<AutLib::TModel_Surface>> TModelSurfaces;
		std::vector<std::shared_ptr<AutLib::TModel_Paired>> TModelCurves;
		model->RetrieveFacesTo(TModelSurfaces);
		model->RetrieveSegmentsTo(TModelCurves);

		if (!part->GetIsTriangulated())
		{
			FrgExecuteFunctionInProcess(GetParentTree()->GetParentMainWindow(), AutLib::FastDiscrete::Triangulation(model->Shape(), *(FrgFastParameters_2)););
			part->GetIsTriangulated() = FrgTrue;
		}

		std::vector<Handle(Poly_Triangulation)> Triangulation = AutLib::Cad_Tools::RetrieveTriangulation(model->Shape());

		for (int iSurface = 0; iSurface < TModelSurfaces.size(); iSurface++)
		{
			vtkNew<vtkPolyData> Hull;
			vtkNew<vtkPoints> points;
			vtkNew<vtkCellArray> polys;

			if (Triangulation.at(iSurface).IsNull()) continue;

			int nbNodes = Triangulation.at(iSurface)->Nodes().Size();
			int nbElements = Triangulation.at(iSurface)->Triangles().Size();

			for (auto i = 0ul; i < nbNodes; ++i)
			{
				points->InsertPoint(i, Triangulation.at(iSurface)->Nodes().Value(i + 1).X(), Triangulation.at(iSurface)->Nodes().Value(i + 1).Y(), Triangulation.at(iSurface)->Nodes().Value(i + 1).Z());
			}

			for (int i = 0; i < nbElements; i++)
			{
				int I1, I2, I3;
				Triangulation.at(iSurface)->Triangles().Value(i + 1).Get(I1, I2, I3);
				std::array<std::array<vtkIdType, 3>, 1> order = { { {I1 - 1,I2 - 1,I3 - 1 } } };
				polys->InsertNextCell(vtkIdType(3), order[0].data());
			}
			Hull->SetPoints(points);
			Hull->SetPolys(polys);

			// Now we'll look at it.
			vtkNew<vtkPolyDataMapper> HullMapper;
			HullMapper->SetInputData(Hull);

			vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

			// Create a transform to rescale model
			double center[3];
			Hull->GetCenter(center);
			double bounds[6];
			Hull->GetBounds(bounds);
			double maxBound =
				std::max(std::max(bounds[1] - bounds[0], bounds[3] - bounds[2]),
					bounds[5] - bounds[4]);

			auto userTransform = vtkSmartPointer<vtkTransform>::New();

			auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
			transform->SetTransform(userTransform);
			transform->SetInputData(Hull);

			auto triangles = vtkSmartPointer<vtkTriangleFilter>::New();
			triangles->SetInputConnection(transform->GetOutputPort());

			auto norms = vtkSmartPointer<vtkTriangleMeshPointNormals>::New();
			norms->SetInputConnection(triangles->GetOutputPort());

			HullMapper->SetInputConnection(norms->GetOutputPort());
			HullMapper->ScalarVisibilityOff();

			GetActors().push_back(actor);
			GetActors().at(GetActors().size() - 1)->SetMapper(HullMapper);

			AddActorToTheRenderer(actor);

			for (int i = 0; i < part->GetSurfaces().size(); i++)
			{
				if (part->GetSurfaces().at(i) == TModelSurfaces.at(iSurface))
				{
					GetActorToPartFeature().insert(actor, part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(i));
					GetPartFeatureToActor().insert(part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(i), actor);
					auto& scenes = part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(i)->GetPointerToScenes();

					if (scenes.isEmpty())
						scenes.push_back(this);
					else
					{
						for (int iScene = 0; iScene < scenes.size(); iScene++)
						{
							if (scenes.at(iScene) == this)
								continue;
							scenes.push_back(this);
						}
					}
				}
			}
		}

		for (int iCurve = 0; iCurve < TModelCurves.size(); iCurve++)
		{

			vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

			for (int i = 0; i < part->GetCurves().size(); i++)
			{
				if (part->GetCurves().at(i) == TModelCurves.at(iCurve))
				{
					GetActorToPartFeature().insert(actor, part->GetFeatures()->GetCurvesEntity()->GetFeatureEntity(i));
					GetPartFeatureToActor().insert(part->GetFeatures()->GetCurvesEntity()->GetFeatureEntity(i), actor);
					auto scenes = part->GetFeatures()->GetCurvesEntity()->GetFeatureEntity(i)->GetPointerToScenes();

					if (scenes.isEmpty())
						scenes.push_back(this);
					else
					{
						for (int iScene = 0; iScene < scenes.size(); iScene++)
						{
							if (scenes.at(iScene) == this)
								continue;
							scenes.push_back(this);
						}
					}
				}
			}
		}
	}

	DrawGrid(10, 5);
}

void ForgBaseLib::CADScene::ClearScene()
{
	if (GetActors().size() != 0)
	{
		for (int iActor = 0; iActor < GetActors().size(); iActor++)
		{
			GetRenderer()->RemoveActor(GetActors().at(iActor));
		}
		GetActors().clear();
	}
}