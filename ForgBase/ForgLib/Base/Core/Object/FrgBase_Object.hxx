#pragma once
#ifndef _FrgBase_Object_Header
#define _FrgBase_Object_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>
#include <QtCore/QObject>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Object
{

protected:

	int theIndex_;
	QString theName_;

public:

	FrgBase_Object();

	virtual ~FrgBase_Object();

	virtual int GetIndex() const { return theIndex_; }
	virtual void SetIndex(int index) { theIndex_ = index; }

	virtual const QString& GetName() const { return theName_; }
	virtual void SetName(const QString& name) { theName_ = name; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Object)

#endif // !_FrgBase_Object_Header
