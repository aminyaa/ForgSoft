#pragma once
#ifndef _SplitPart_Feature_Header
#define _SplitPart_Feature_Header

#include <FrgBaseGlobals.hxx>
#include <SplitPartFeature_Traits.hxx>

BeginFrgBaseLib

template<class T>
class SplitPartFeature_Widget;

template<class T>
class FrgBaseCADPart_Feature;

template<class BlockEntity>
class SplitPart_Feature
{

private:

	SplitPartFeature_Widget<BlockEntity>* theSplitWidget_ = FrgNullPtr;

public:

	SplitPart_Feature
	(
		FrgBaseMainWindow* parentMainWindow,
		FrgBaseCADPart_Feature<BlockEntity>* partFeature,
		std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager
	);

};

EndFrgBaseLib

#include <SplitPart_FeatureI.hxx>

#endif // !_SplitPart_Feature_Header
