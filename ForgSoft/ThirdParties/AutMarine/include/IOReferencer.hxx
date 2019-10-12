#pragma once
#ifndef _IOReferencer_Header
#define _IOReferencer_Header

#include <regIOobject.hxx>

namespace AutLib
{

	template<class Type>
	class IOReferencer
		: public regIOobject
	{
		// Private data

		//- Pointer to object
		Type* typePtr_;


	public:

		// Constructors

		//- Construct from IOobject - pointer set to null
		IOReferencer
		(
			const IOobject& io
		);

		//- Construct from IOobject - pointer initialized
		IOReferencer
		(
			const IOobject& io,
			Type* ptr
		);


		// Destructor

		virtual ~IOReferencer();


		// Member functions

		//- A "do nothing" writeData function, required by regIOobject
		virtual bool writeData(Ostream&) const;

		//- Return const reference to object
		const Type& operator()() const;

		//- Return access to object
		Type& operator()();

		//- Set the pointer
		void set(Type* ptr);
	};
}

#include <IOReferencerI.hxx>

#endif // !_IOReferencer_Header
