#pragma once
#ifndef _FrgVisual_SceneRegistry_Header
#define _FrgVisual_SceneRegistry_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

template <int Dim>
class FrgVisual_Scene;

class FrgVisual_BaseActor_Entity;

template <int Dim>
class FORGVISUAL_EXPORT FrgVisual_SceneRegistry
{

public:

	FrgVisual_SceneRegistry(FrgVisual_Scene<Dim>* parentScene = nullptr);

	~FrgVisual_SceneRegistry();

	int AddActor(FrgVisual_BaseActor_Entity* actor);
	int FindActor(FrgVisual_BaseActor_Entity* actor) const;
	FrgVisual_BaseActor_Entity* FindActor(int index) const;
	void RemoveActor(int index);
	void RemoveActor(FrgVisual_BaseActor_Entity* actor);

private:

	DECLARE_SAVE_LOAD_HEADER( )
    

protected:

	FrgVisual_Scene<Dim>* theParentScene_ = nullptr;

	std::map<unsigned int, FrgVisual_BaseActor_Entity*> theActors_;
	std::vector<int> theReservedIndexes_;

private:

	void heapify(std::vector<int>& arr, int n, int i);
	void heapSort(std::vector<int>& arr, int n);
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneRegistry<2>);
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneRegistry<3>);

#endif // !_FrgVisual_SceneRegistry_Header
