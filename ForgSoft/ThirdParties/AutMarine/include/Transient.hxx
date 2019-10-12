#pragma once
#ifndef _Transient_Header
#define _Transient_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Transient
	{

		/* Private Data*/
		mutable Standard_Integer theCount_;

	public:

		Transient()
			: theCount_(0)
		{}

		Transient(const Transient&)
			: theCount_(0)
		{}

		Transient& operator=(const Transient&) { return *this; }

		virtual ~Transient() {}

		Standard_Integer getRefCount() const { return theCount_; }

		Standard_Boolean isShared() const { return getRefCount() > 1; }

		void incrementRefCounter() const { theCount_++; }

		void deleteThis() const { delete this; }

		Standard_Integer decrementRefCounter() const { --theCount_; return theCount_; }
	};
}

#endif // !_Transient_Header
