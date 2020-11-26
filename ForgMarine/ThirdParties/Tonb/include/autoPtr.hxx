#pragma once
#ifndef _autoPtr_Header
#define _autoPtr_Header

#include <cstddef>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class autoPtr Declaration
\*---------------------------------------------------------------------------*/

	template<class T>
	class autoPtr
	{
		// Public data

			//- Pointer to object
		mutable T* ptr_;


	public:

		// Constructors

			//- Store object pointer
		explicit autoPtr(T* = 0);

		//- Construct as copy by transfering pointer to this autoPtr and
		//  setting the arguments pointer to NULL
		autoPtr(const autoPtr<T>&);


		// Destructor

			//- Delete object if pointer is not NULL
		~autoPtr();


		// Member Functions

			// Check

				//- Return true if the autoPtr is empty (ie, no pointer set).
		bool empty() const;

		//- Return true if the autoPtr valid (ie, the pointer is set).
		bool valid() const;


		// Edit

			//- Return object pointer for reuse
		T* ptr();

		//- Set pointer to that given.
		//  If object pointer already set issue a FatalError.
		void set(T*);

		//- If object pointer already set, delete object and set to
		//  given pointer
		void reset(T* = 0);

		//- If object pointer points to valid object:
		//  delete object and set pointer to NULL
		void clear();


		// Member operators

			//- Return reference to the object data
		T& operator()();

		//- Return const reference to the object data
		const T& operator()() const;

		// T& operator*();
		// const T& operator*() const;

		operator const T&() const;

		//- Return object pointer
		T* operator->();

		//- Return const object pointer
		const T* operator->() const;

		//- Take over object pointer from parameter
		void operator=(const autoPtr<T>&);
	};

}

#include <autoPtrI.hxx>

#endif // !_autoPtr_Header
