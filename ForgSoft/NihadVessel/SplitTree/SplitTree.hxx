#pragma once
#ifndef _SplitTree_Header
#define _SplitTree_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTree.hxx>
#include <SplitTree_Traits.hxx>

BeginFrgBaseLib

class FrgBaseCADPart_Entity;
class FrgBaseMainWindow;
class FrgBaseCADScene;

class SplitTree_Base : public FrgBaseTree
{

	Q_OBJECT

protected:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgBaseCADPart_Entity* theParentPart_ = FrgNullPtr;
	QList<FrgBaseCADScene*> thePointerToScenes_;

public:

	SplitTree_Base
	(
		FrgBaseMainWindow* parent,
		QList<FrgBaseCADScene*> pointerToScenes,
		FrgBaseCADPart_Entity* parentPart
	);

	FrgGetMacro(QList<FrgBaseCADScene*>, PointerToScenes, thePointerToScenes_);
	FrgGetMacro(FrgBaseCADPart_Entity*, ParentPart, theParentPart_);

	virtual void FormTree() override {}

private slots:

	void itemInSplitTreeClickedSlot(QTreeWidgetItem*, int);
	void CreateButtonClickedSlot();

protected:

	virtual void CreateButtonClicked() {}
};

template<class T>
class SplitWidget;

template<class T>
class FrgBaseCADPartFeatureEntity;

template<class BlockEntity>
class SplitTree : public SplitTree_Base
{
public:

	//typedef typename BlockEntity::Entity entityType;

private:

	FrgBaseCADPartFeatureEntity<BlockEntity>* theFeatureEntity_ = FrgNullPtr;
	std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> theEntityManager_;
	SplitWidget<BlockEntity>* theParentSplitWidget_ = FrgNullPtr;

public:

	SplitTree
	(
		FrgBaseMainWindow* parent,
		FrgBaseCADPartFeatureEntity<BlockEntity>* featureEntity,
		std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager,
		QList<FrgBaseCADScene*> pointerToScenes,
		SplitWidget<BlockEntity>* parentSplitWidget,
		FrgBaseCADPart_Entity* parentPart
	);

	FrgGetMacro(FrgBaseCADPartFeatureEntity<BlockEntity>*, FeatureEntity, theFeatureEntity_);
	FrgGetMacro(std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager>, EntityManager, theEntityManager_);

	void FormTree() override;

protected:

	virtual void CreateButtonClicked() override;

};

EndFrgBaseLib

#include <SplitTreeI.hxx>

#endif // !_SplitTree_Header
