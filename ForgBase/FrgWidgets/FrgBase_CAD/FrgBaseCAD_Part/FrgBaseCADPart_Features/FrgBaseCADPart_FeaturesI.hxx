#pragma once
#include <FrgBaseCADPart_Features.hxx>
#include <FrgBaseCAD_Part.hxx>

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
inline void ForgBaseLib::FrgBaseCADPart_Features<FeatureType>::AddFeature
(
	std::shared_ptr<FeatureType> featureEntity
)
{
	FrgBaseCADPart_Feature* feature = FrgNew FrgBaseCADPart_Feature<FeatureType>(featureEntity->Name(), this);
	theFeatures_.push_back(feature);
}