#pragma once
//#include <FrgBaseCADPart_Features.hxx>
#include <FrgBaseCAD_Part.hxx>

template<class FeatureType>
inline ForgBaseLib::FrgBaseCADPart_Feature<FeatureType>::FrgBaseCADPart_Feature
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem,
	FrgBaseCAD_Part_Base* parentPart
)
	: FrgBaseCADPart_Feature_Base(title, parentItem, parentPart)
{

}

template<class FeatureType>
inline ForgBaseLib::FrgBaseCADPart_Feature<FeatureType>::FrgBaseCADPart_Feature
(
	const FrgString & title,
	FrgBaseTree * parentTree,
	FrgBaseCAD_Part_Base * parentPart
)
	: FrgBaseCADPart_Feature_Base(title, parentTree, parentPart)
{
}

template<class FeatureType>
inline ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::FrgBaseCADPart_Features
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem,
	FrgBaseCAD_Part_Base* parentPart
)
	: FrgBaseCADPart_Features_Base(title, parentItem, parentPart)
{

}

template<class FeatureType>
inline ForgBaseLib::FrgBaseCADPart_Feature<FeatureType>* ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::AddFeature
(
	std::shared_ptr<FeatureType> featureEntity
)
{
	FrgBaseCADPart_Feature<FeatureType>* feature = FrgNew FrgBaseCADPart_Feature<FeatureType>(featureEntity->Name().c_str(), this, theParentPart_);
	theFeatures_.push_back(feature);
	feature->GetFeatureEntity() = featureEntity;

	return feature;
}

template<class FeatureType>
inline void ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::RemoveFeature
(
	FrgBaseCADPart_Feature<FeatureType>* featureEntity
)
{
	this->removeChild(featureEntity);
	theFeatures_.takeAt(theFeatures_.indexOf(featureEntity));
	this->GetParentTree()->GetItems().takeAt(this->GetParentTree()->GetItems().indexOf(featureEntity));
}

template<class FeatureType>
inline std::shared_ptr<FeatureType> ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::GetEntity(int iEntity) const
{
	return theFeatures_[iEntity]->GetFeatureEntity();
}

template<class FeatureType>
inline std::shared_ptr<FeatureType>& ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::GetEntity(int iEntity)
{
	return theFeatures_[iEntity]->GetFeatureEntity();
}

template<class FeatureType>
inline std::shared_ptr<FeatureType> ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::GetEntity(FrgString nameOfEntity) const
{
	for (int iFeature; iFeature < theFeatures_.size(); iFeature++)
	{
		if (theFeatures_[iFeature]->GetFeatureEntity()->Name() == nameOfEntity.toStdString().c_str())
			return theFeatures_[iFeature]->GetFeatureEntity();
	}

	return FrgNullPtr;
}

template<class FeatureType>
inline std::shared_ptr<FeatureType>& ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::GetEntity(FrgString nameOfEntity)
{
	for (int iFeature; iFeature < theFeatures_.size(); iFeature++)
	{
		if (theFeatures_[iFeature]->GetFeatureEntity()->Name() == nameOfEntity.toStdString().c_str())
			return theFeatures_[iFeature]->GetFeatureEntity();
	}

	return FrgNullPtr;
}

template<class FeatureType>
inline ForgBaseLib::FrgBaseCADPart_Feature<FeatureType>* ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::GetFeature(FrgString nameOfEntity) const
{
	for (int iFeature = 0; iFeature < theFeatures_.size(); iFeature++)
	{
		if (theFeatures_[iFeature]->GetFeatureEntity()->Name() == nameOfEntity.toStdString().c_str())
			return theFeatures_[iFeature];
	}

	return FrgNullPtr;
}

template<class FeatureType>
inline ForgBaseLib::FrgBaseCADPart_Feature<FeatureType>*& ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::GetFeature(FrgString nameOfEntity)
{
	for (int iFeature = 0; iFeature < theFeatures_.size(); iFeature++)
	{
		if (theFeatures_[iFeature]->GetFeatureEntity()->Name() == nameOfEntity.toStdString().c_str())
			return theFeatures_[iFeature];
	}

	return FrgNullPtr;
}

template<class FeatureType>
inline void ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::SelectAllFeatures()
{
	QList<FrgBaseTreeItem*> items;
	for (int iItem = 0; iItem < theFeatures_.size(); iItem++)
		items.push_back(theFeatures_[iItem]);

	GetParentTree()->ScrollToItems(items);
}