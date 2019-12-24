#pragma once
#ifndef _SplitTree_Header
#define _SplitTree_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTree.hxx>

namespace AutLib
{
	template <class Entity>
	class Cad_BlockEntity;

	class TModel_Surface;
	class TModel_Paired;
}

BeginFrgBaseLib

class FrgBaseCADPart_Entity;
class FrgBaseMainWindow;
class FrgBaseCADScene;
class FrgBaseCADPart_Entity;

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

template<class Entity>
class SplitWidget;

template<class Entity>
class FrgBaseCADPartFeatureEntity;

template<class BlockEntity>
class SplitTree : protected SplitTree_Base
{
public:

	typedef typename BlockEntity::Entity entityType;

private:

	FrgBaseCADPartFeatureEntity<Entity>* theFeatureEntity_ = FrgNullPtr;
	SplitWidget<Entity>* theParentSplitWidget_ = FrgNullPtr;

public:

	SplitTree
	(
		FrgBaseMainWindow* parent,
		FrgBaseCADPartFeatureEntity<BlockEntity> featureEntity,
		QList<FrgBaseCADScene*> pointerToScenes,
		SplitWidget<BlockEntity>* parentSplitWidget,
		FrgBaseCADPart_Entity* parentPart
	);

	FrgGetMacro(FrgBaseCADPartFeatureEntity<Entity>*, FeatureEntity, theFeatureEntity_);

	virtual void FormTree() override;

protected:

	virtual void CreateButtonClicked() override;

};

EndFrgBaseLib

#include <SplitTreeI.hxx>

#endif // !_SplitTree_Header
