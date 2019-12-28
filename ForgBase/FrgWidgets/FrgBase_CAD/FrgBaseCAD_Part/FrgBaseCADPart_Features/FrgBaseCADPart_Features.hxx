#pragma once
#ifndef _FrgBaseCADPart_Features_Header
#define _FrgBaseCADPart_Features_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

#include <QtCore/QObject>

BeginFrgBaseLib

class FrgBaseCAD_Part_Base;
class FrgBaseTree;

class FORGBASE_EXPORT FrgBaseCADPart_Feature_Base
	: public QObject
	, public FrgBaseTreeItem
{
	Q_OBJECT

protected:

	FrgBaseCAD_Part_Base* theParentPart_ = FrgNullPtr;

public:

	FrgBaseCADPart_Feature_Base
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	FrgBaseCADPart_Feature_Base
	(
		const FrgString& title,
		FrgBaseTree* parentTree,
		FrgBaseCAD_Part_Base* parentPart
	);

	virtual ~FrgBaseCADPart_Feature_Base() {}

	FrgGetMacro(FrgBaseCAD_Part_Base*, ParentPart, theParentPart_);

	void DoAfterConstruct() override;
};

template<class T>
class FrgBaseCADPart_Features;

template<class FeatureType>
class FrgBaseCADPart_Feature
	: public FrgBaseCADPart_Feature_Base
{

private:

	std::shared_ptr<FeatureType> theFeatureEntity_;
	FrgBaseCADPart_Features<FeatureType>* theParentFeatures_ = FrgNullPtr;

public:

	FrgBaseCADPart_Feature
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	FrgBaseCADPart_Feature
	(
		const FrgString& title,
		FrgBaseTree* parentTree,
		FrgBaseCAD_Part_Base* parentPart
	);

	FrgGetMacro(std::shared_ptr<FeatureType>, FeatureEntity, theFeatureEntity_);
	FrgGetMacro(FrgBaseCADPart_Features<FeatureType>*, ParentFeatures, theParentFeatures_);
};

class FORGBASE_EXPORT FrgBaseCADPart_Features_Base
	: public QObject
	, public FrgBaseTreeItem
{
	Q_OBJECT

protected:

	FrgBaseCAD_Part_Base* theParentPart_ = FrgNullPtr;

public:

	FrgBaseCADPart_Features_Base
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	virtual ~FrgBaseCADPart_Features_Base() {}

	FrgGetMacro(FrgBaseCAD_Part_Base*, ParentPart, theParentPart_);

	void DoAfterConstruct() override;

public slots:

	void SelectAllFeaturesSlot(bool);

protected:

	virtual void SelectAllFeatures() {}
};

template<class FeatureType>
class FrgBaseCADPart_Features
	: public FrgBaseCADPart_Features_Base
{

private:

	QList<FrgBaseCADPart_Feature<FeatureType>*> theFeatures_;

public:

	FrgBaseCADPart_Features
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	FrgBaseCADPart_Feature<FeatureType>* AddFeature(std::shared_ptr<FeatureType> featureEntity);
	void RemoveFeature(FrgBaseCADPart_Feature<FeatureType>* featureEntity);

	QList<FrgBaseCADPart_Feature<FeatureType>*> GetListOfFeatures() { return theFeatures_; }
	QList<FrgBaseCADPart_Feature<FeatureType>*> GetListOfFeatures() const { return theFeatures_; }

	std::shared_ptr<FeatureType> GetEntity(int iEntity) const;
	std::shared_ptr<FeatureType>& GetEntity(int iEntity);
	std::shared_ptr<FeatureType> GetEntity(FrgString nameOfEntity) const;
	std::shared_ptr<FeatureType>& GetEntity(FrgString nameOfEntity);

	FrgBaseCADPart_Feature<FeatureType>* GetFeature(int iFeature) const { return theFeatures_[iFeature]; }
	FrgBaseCADPart_Feature<FeatureType>*& GetFeature(int iFeature) { return theFeatures_[iFeature]; }
	FrgBaseCADPart_Feature<FeatureType>* GetFeature(FrgString nameOfEntity) const;
	FrgBaseCADPart_Feature<FeatureType>*& GetFeature(FrgString nameOfEntity);

protected:

	void SelectAllFeatures() override;
};

EndFrgBaseLib

#include <FrgBaseCADPart_FeaturesI.hxx>

#endif // !_FrgBaseCADPart_Features_Header
