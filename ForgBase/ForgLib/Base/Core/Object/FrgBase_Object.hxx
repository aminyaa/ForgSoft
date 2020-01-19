#pragma once
#ifndef _FrgBase_Object_Header
#define _FrgBase_Object_Header

#include <FrgBase_Global.hxx>
#include <QtCore/QObject>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Object
	//: public QObject
{

	//Q_OBJECT

private:

	//FrgBool theIsObjectModified_ = FrgFalse;

public:

	FrgBase_Object();

	virtual ~FrgBase_Object();

//public slots:

	//void UpdateObject_Slot();

//signals:



public:

	//virtual void UpdateObject() {}
	//inline FrgBool IsObjectModified() { return theIsObjectModified_; }
	//inline void SetObjectModified(FrgBool condition) { theIsObjectModified_ = condition; }
};

EndForgBaseLib

#endif // !_FrgBase_Object_Header
