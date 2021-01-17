#pragma once
#ifndef _FrgBase_Object_Header
#define _FrgBase_Object_Header

#include <FrgBase_Global.hxx>
#include <QtCore/QObject>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Object
{

protected:

	unsigned int theIndex_;
	QString theName_;

public:

	FrgBase_Object();

	virtual ~FrgBase_Object();

	unsigned int GetIndex() const { return theIndex_; }
	void SetIndex(unsigned int index) { theIndex_ = index; }

	const QString& GetName() const { return theName_; }
	void SetName(const QString& name) { theName_ = name; }

};

EndForgBaseLib

#endif // !_FrgBase_Object_Header
