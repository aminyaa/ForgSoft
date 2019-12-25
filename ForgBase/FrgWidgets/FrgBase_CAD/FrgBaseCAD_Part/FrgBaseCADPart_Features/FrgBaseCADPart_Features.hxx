#pragma once
#ifndef _FrgBaseCADPart_Features_Header
#define _FrgBaseCADPart_Features_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

#include <QtCore/QObject>

BeginFrgBaseLib

class FrgBaseCAD_Part_Base;

class FrgBaseCADPart_Feature_Base
	: public QObject
	, public FrgBaseTreeItem
{
	Q_OBJECT

private:

	FrgBaseCAD_Part_Base* theParentPart_ = FrgNullPtr;

public:

	FrgBaseCADPart_Feature_Base
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	FrgGetMacro(FrgBaseCAD_Part_Base*, ParentPart, theParentPart_);
};

template<class FeatureType>
class FrgBaseCADPart_Feature
	: public FrgBaseCADPart_Feature_Base
{

private:

	std::shared_ptr<FeatureType> theFeatureEntity_;

public:

	FrgBaseCADPart_Feature
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	FrgGetMacro(std::shared_ptr<FeatureType>, FeatureEntity, theFeatureEntity_);
};

class FrgBaseCADPart_Features_Base
	: public QObject
	, public FrgBaseTreeItem
{
	Q_OBJECT

private:

	FrgBaseCAD_Part_Base* theParentPart_ = FrgNullPtr;

public:

	FrgBaseCADPart_Features_Base
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	FrgGetMacro(FrgBaseCAD_Part_Base*, ParentPart, theParentPart_);
};

template<class FeatureType>
class FrgBaseCADPart_Features
	: public FrgBaseCADPart_Features_Base
{

private:

	QList<FrgBaseCADPart_Feature*> theFeatures_;

public:

	FrgBaseCADPart_Features
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem,
		FrgBaseCAD_Part_Base* parentPart
	);

	void AddFeature(std::shared_ptr<FeatureType> featureEntity);

	QList<FrgBaseCADPart_Feature*> GetListOfFeatures() { return theFeatures_; }
	QList<FrgBaseCADPart_Feature*> GetListOfFeatures() const { return theFeatures_; }
};

EndFrgBaseLib

#include <FrgBaseCADPart_FeaturesI.hxx>

#endif // !_FrgBaseCADPart_Features_Header
