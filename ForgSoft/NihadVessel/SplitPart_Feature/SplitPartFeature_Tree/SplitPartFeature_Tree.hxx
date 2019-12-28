#pragma once
#ifndef _SplitPartFeature_Tree_Header
#define _SplitPartFeature_Tree_Header

#include <FrgBaseGlobals.hxx>

#include <FrgBaseTree.hxx>

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseCADPart_Feature_Base;

class SplitPartFeature_Tree_Base
	: public FrgBaseTree
{
	Q_OBJECT

protected:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgBaseCADPart_Feature_Base* thePartFeatureBase_ = FrgNullPtr;

public:

	SplitPartFeature_Tree_Base
	(
		FrgBaseMainWindow* parentMainWindow,
		FrgBaseCADPart_Feature_Base* partFeature
	);

	FrgGetMacro(FrgBaseMainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBaseCADPart_Feature_Base*, PartFeatureBase, thePartFeatureBase_);

	virtual void CreateButtonClicked() {}

public slots:

	void CreateButtonClickedSlot();
};

template<class T>
class SplitPartFeature_Widget;

template<class T>
class FrgBaseCADPart_Feature;

template<class BlockEntity>
class SplitPartFeature_Tree
	: public SplitPartFeature_Tree_Base
{

private:

	FrgBaseCADPart_Feature<BlockEntity>* thePartFeature_ = FrgNullPtr;
	SplitPartFeature_Widget<BlockEntity>* theParentSplitWidget_ = FrgNullPtr;

public:

	SplitPartFeature_Tree
	(
		FrgBaseMainWindow* parentMainWindow,
		FrgBaseCADPart_Feature<BlockEntity>* partFeature
	);

	FrgGetMacro(FrgBaseCADPart_Feature<BlockEntity>*, PartFeature, thePartFeature_);
	FrgGetMacro(SplitPartFeature_Widget<BlockEntity>*, ParentSplitWidget, theParentSplitWidget_);

	void FormTree() override;

	void CreateButtonClicked() override;
};

EndFrgBaseLib

#include <SplitPartFeature_TreeI.hxx>

#endif // !_SplitPartFeature_Tree_Header
