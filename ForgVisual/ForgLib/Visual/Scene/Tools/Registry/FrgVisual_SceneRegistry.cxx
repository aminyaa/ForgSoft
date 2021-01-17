#include <FrgVisual_SceneRegistry.hxx>
#include <FrgVisual_Scene.hxx>
#include <FrgVisual_BaseActor_Entity.hxx>
#include <FrgVisual_PickingPointActor.hxx>

#include <boost/serialization/map.hpp>

template <int Dim>
ForgVisualLib::FrgVisual_SceneRegistry<Dim>::FrgVisual_SceneRegistry(ForgVisualLib::FrgVisual_Scene<Dim>* parentScene)
	: theParentScene_(parentScene)
{

}

template<int Dim>
ForgVisualLib::FrgVisual_SceneRegistry<Dim>::~FrgVisual_SceneRegistry()
{
	theActors_.clear();
	theReservedIndexes_.clear();
}

template<int Dim>
int ForgVisualLib::FrgVisual_SceneRegistry<Dim>::AddActor(FrgVisual_BaseActor_Entity* actor)
{
	if (!actor)
		return -1;

	if (actor->IsPickingPoint())
		return -2;

	if (actor->GetIndex() != -1)
		return actor->GetIndex();

	// the item can be added
	int index;
	if (!theReservedIndexes_.empty())
	{
		index = theReservedIndexes_[0];
		theReservedIndexes_.erase(theReservedIndexes_.begin());
	}
	else
	{
		index = theActors_.size() + 1;
	}

	theActors_[index] = actor;

	const auto& actorTypes = actor->GetActorTypes();
	for (const auto& actorType : actorTypes)
	{
		theTypeMap_[(size_t)actorType][index] = actor;
	}

	actor->SetIndex(index);

	/*for (const auto& actorType : actorTypes)
	{
		std::cout << "type " << actor->GetActorTypeAsString(actorType).toStdString() << " :\n";
		for(const auto& ind : theTypeMap_[(size_t)actorType])
			std::cout << ind.first << std::endl;
	}*/

	//std::cout << "index added = " << index << std::endl;

	std::cout << actor->GetActorTypeAsString().toStdString() << " was added with index " << index << std::endl;

	return index;
}

template<int Dim>
void ForgVisualLib::FrgVisual_SceneRegistry<Dim>::RemoveActor(int index)
{
	if (index < 1)
		return;

	auto actor = theActors_.at(index);
	if (!actor)
		return;

	auto i = theActors_.erase(index);
	if (i == 1 && index != theActors_.size() + 1)
	{
		theReservedIndexes_.push_back(index);
		heapSort(theReservedIndexes_, theReservedIndexes_.size());
	}

	auto actorTypes = actor->GetActorTypes();
	for (auto actorType : actorTypes)
	{
		theTypeMap_[(size_t)actorType].erase(index);
	}

	actor->SetIndex(-1);
}

template<int Dim>
void ForgVisualLib::FrgVisual_SceneRegistry<Dim>::RemoveActor(FrgVisual_BaseActor_Entity* actor)
{
	RemoveActor(FindActor(actor));
}

template<int Dim>
int ForgVisualLib::FrgVisual_SceneRegistry<Dim>::FindActor(FrgVisual_BaseActor_Entity* actor) const
{
	if (!theActors_.empty() && actor != nullptr)
	{
		auto actorTypes = actor->GetActorTypes();
		if (!actorTypes.empty())
		{
			for (const auto& item : theTypeMap_[(size_t)actorTypes[0]])
			{
				if (item.second == actor)
					return item.first;
			}
		}
	}

	return -1;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity* ForgVisualLib::FrgVisual_SceneRegistry<Dim>::FindActor(int index) const
{
	if (!theActors_.empty() && index > 0 && index < theActors_.size() + 1)
	{
		auto iter = theActors_.find(index);
		if (iter != theActors_.end())
			return iter->second;
	}

	return nullptr;
}

template <int Dim>
void ForgVisualLib::FrgVisual_SceneRegistry<Dim>::heapify(std::vector<int>& arr, int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		//swap(arr[i], arr[largest]);
		int tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_SceneRegistry<Dim>::heapSort(std::vector<int>& arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end
		//swap(arr[0], arr[i]);
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

template <int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneRegistry<Dim>)
{
	ar& theParentScene_;
	ar& theActors_;
	ar& theReservedIndexes_;
	ar& theTypeMap_;
}

template <int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneRegistry<Dim>)
{
	ar& theParentScene_;
	ar& theActors_;
	ar& theReservedIndexes_;
	ar& theTypeMap_;
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_SceneRegistry<2>);
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_SceneRegistry<3>);

template class FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_SceneRegistry<2>;
template class FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_SceneRegistry<3>;