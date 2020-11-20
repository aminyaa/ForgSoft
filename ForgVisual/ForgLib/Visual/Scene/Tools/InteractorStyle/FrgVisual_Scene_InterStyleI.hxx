#pragma once

#include <vtkObjectFactory.h>
#include <vtkInteractorStyle.h>

template <int Dim, class T>
ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>* ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>::New()
{
	ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>* result = new ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>;
	result->InitializeObjectBase();
	return result;
}

template<int Dim, class T>
inline ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>::FrgVisual_Scene_InterStyle()
{

}

template<int Dim, class T>
inline void ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>::StartTranslation()
{
	if (this->State != VTKIS_NONE)
	{
		return;
	}

	this->StartState(VTKIS_Translation);
}

template<int Dim, class T>
inline void ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>::EndTranslation()
{
	if (this->State != VTKIS_Translation)
	{
		return;
	}

	this->StopState();
}