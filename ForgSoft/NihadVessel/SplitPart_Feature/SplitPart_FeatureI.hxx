#pragma once
#include <SplitPartFeature_Widget.hxx>

template<class BlockEntity>
inline ForgBaseLib::SplitPart_Feature<BlockEntity>::SplitPart_Feature
(
	FrgBaseMainWindow * parentMainWindow,
	FrgBaseCADPart_Feature<BlockEntity>* partFeature,
	std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager
)
{
	theSplitWidget_ = FrgNew SplitPartFeature_Widget<BlockEntity>(parentMainWindow, partFeature);
	theSplitWidget_->SetManager(manager);
}