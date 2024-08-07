#pragma once
#ifndef _FrgVisual_SceneRegistry_Header
#define _FrgVisual_SceneRegistry_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_Object.hxx>
#include <FrgVisual_Serialization_Global.hxx>
#include <FrgVisual_BaseActor_Entity.hxx>

BeginForgVisualLib

class FrgVisual_Scene_Entity;

class FORGVISUAL_EXPORT FrgVisual_SceneRegistry
	: public ForgBaseLib::FrgBase_Object
{

public:

	static const size_t nbEntities = (size_t)FrgVisual_BaseActor_Entity::ActorType::Other;
	typedef std::map<unsigned int, FrgVisual_BaseActor_Entity*> mapOfActors;

	FrgVisual_SceneRegistry(FrgVisual_Scene_Entity* parentScene = nullptr);

	~FrgVisual_SceneRegistry();

	unsigned int theIndexOfLastActor_ = 1;

	int AddActor(FrgVisual_BaseActor_Entity* actor);
	int FindActor(FrgVisual_BaseActor_Entity* actor) const;
	FrgVisual_BaseActor_Entity* FindActor(int index) const;
	void RemoveActor(int index);
	void RemoveActor(FrgVisual_BaseActor_Entity* actor);

	mapOfActors GetActorsByType(FrgVisual_BaseActor_Entity::ActorType actorType) const;

	mapOfActors GetAllActors() const { return theActors_; }

private:

	DECLARE_SAVE_LOAD_HEADER( )
    

protected:

	FrgVisual_Scene_Entity* theParentScene_ = nullptr;

	mapOfActors theActors_;
	mapOfActors theTypeMap_[nbEntities];
	std::vector<int> theReservedIndexes_;

private:

	void heapify(std::vector<int>& arr, int n, int i);
	void heapSort(std::vector<int>& arr, int n);
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneRegistry);

#endif // !_FrgVisual_SceneRegistry_Header
