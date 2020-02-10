#pragma once

#include <array>

#include <vtkRenderer.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkIdTypeArray.h>
#include <vtkActor.h>
#include <vtkTextActor.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>
#include <vtkProperty.h>

template<typename Triangulation>
inline void ForgVisualLib::FrgVisual_Scene3D::AddTriangulations(std::vector<Triangulation> triangulations, bool resetCamera)
{
	//QList<vtkSmartPointer<vtkActor>> actors;

	for (int iTriangulation = 0; iTriangulation < triangulations.size(); iTriangulation++)
	{
		auto myTriangulation = triangulations.at(iTriangulation);

		vtkNew<vtkPolyData> Hull;
		vtkNew<vtkPoints> points;
		vtkNew<vtkCellArray> polys;

		int nbNodes = myTriangulation->NbNodes();
		int nbElements = myTriangulation->NbTriangles();

		auto Triangulation_Pts = myTriangulation->Nodes();
		for (auto i = 0ul; i < nbNodes; ++i)
		{
			points->InsertPoint(i, Triangulation_Pts.Value(i + 1).X(), Triangulation_Pts.Value(i + 1).Y(), Triangulation_Pts.Value(i + 1).Z());
		}

		auto Triangulation_Element_Connectivity = myTriangulation->Triangles();
		for (int i = 0; i < nbElements; i++)
		{
			int I1, I2, I3;
			I1 = Triangulation_Element_Connectivity.Value(i + 1).Value(1);
			I2 = Triangulation_Element_Connectivity.Value(i + 1).Value(2);
			I3 = Triangulation_Element_Connectivity.Value(i + 1).Value(3);
			std::array<std::array<vtkIdType, 3>, 1> order = { { {I1 - 1,I2 - 1,I3 - 1 } } };
			polys->InsertNextCell(vtkIdType(3), order[0].data());
		}
		Hull->SetPoints(points);
		Hull->SetPolys(polys);

		// Now we'll look at it.
		vtkNew<vtkPolyDataMapper> HullMapper;
		HullMapper->SetInputData(Hull);

		vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

		//actor->SetMapper(HullMapper);

		// Create a transform to rescale model
		double center[3];
		Hull->GetCenter(center);
		double bounds[6];
		Hull->GetBounds(bounds);
		double maxBound =
			std::max(std::max(bounds[1] - bounds[0], bounds[3] - bounds[2]),
				bounds[5] - bounds[4]);

		auto userTransform = vtkSmartPointer<vtkTransform>::New();
		/*userTransform->Translate(-center[0], -center[1], -center[2]);
		userTransform->Scale(1.0 / maxBound, 1.0 / maxBound, 1.0 / maxBound);*/
		auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
		transform->SetTransform(userTransform);
		transform->SetInputData(Hull);

		auto triangles = vtkSmartPointer<vtkTriangleFilter>::New();
		triangles->SetInputConnection(transform->GetOutputPort());

		auto norms = vtkSmartPointer<vtkTriangleMeshPointNormals>::New();
		norms->SetInputConnection(triangles->GetOutputPort());

		HullMapper->SetInputConnection(norms->GetOutputPort());
		HullMapper->ScalarVisibilityOff();

		//actor->GetProperty()->SetRepresentationToWireframe();

		//actor->GetProperty()->EdgeVisibilityOn();
		//actor->GetProperty()->SetLineWidth(2.0);

		actor->SetMapper(HullMapper);
		//actors.push_back(actor);

		theRenderer_->AddActor(actor);

		/*for (auto scene : GetViewPorts()->GetScenes())
		{
			for (int iActor = 0; iActor < scene->GetActors().size(); iActor++)
			{
				scene->GetActors().at(iActor)->GetProperty()->SetOpacity(0.5);
			}
		}*/

	}

	/*for (auto scene : GetViewPorts()->GetScenes())
	{
		for (int i = 0; i < thePreviewActors_.size(); i++)
		{
			scene->GetRenderer()->RemoveActor(thePreviewActors_.at(i));
		}
	}

	thePreviewActors_ = actors;

	for (auto scene : GetViewPorts()->GetScenes())
	{
		for (int i = 0; i < thePreviewActors_.size(); i++)
		{
			scene->AddActorToTheRenderer(thePreviewActors_.at(i));
		}
	}*/

	RenderScene(resetCamera);
}