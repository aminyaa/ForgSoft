#pragma once
#ifndef _FrgVisual_SceneI_Header
#define _FrgVisual_SceneI_Header

#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkActorCollection.h>
#include <vtkCollection.h>

template<int Dim>
template<typename T>
inline void ForgVisualLib::FrgVisual_Scene<Dim>::ClearAllDataType()
{
	vtkRenderWindowInteractor* rwi = theRenderWindowInteractor_;
	vtkActorCollection* ac;
	vtkActor* anActor;
	T* aPart;
	if (theRenderer_ != nullptr)
	{
		ac = theRenderer_->GetActors();
		vtkCollectionSimpleIterator ait;
		for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
		{
			aPart = static_cast<T*>(anActor);
			if (aPart)
				RemoveActor(aPart);
		}
	}
	else
	{
		std::cout << "no current renderer on the interactor style.\n";
	}
	rwi->Render();
}

#endif // !_FrgVisual_SceneI_Header
