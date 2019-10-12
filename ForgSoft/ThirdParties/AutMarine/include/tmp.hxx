#pragma once
#ifndef _tmp_Header
#define _tmp_Header

namespace AutLib
{

	template<class T>
	class tmp
	{
		// Private data

		//- Flag for whether object is a temporary or a constant object
		bool isTmp_;

		//- Pointer to temporary object
		mutable T* ptr_;

		//- Const reference to constant object
		const T& ref_;


	public:

		// Constructors

		//- Store object pointer
		explicit tmp(T* = 0);

		//- Store object const reference
		tmp(const T&);

		//- Construct copy and increment reference count
		tmp(const tmp<T>&);

		//- Construct copy transferring content of temporary if required
		tmp(const tmp<T>&, bool allowTransfer);


		//- Destructor, delete object when reference count == 0
		~tmp();


		// Member Functions

		// Access

		//- Return true if this is really a temporary object
		bool isTmp() const;

		//- Return true if this temporary object empty,
		//  ie, a temporary without allocation
		bool empty() const;

		//- Is this temporary object valid,
		//  ie, it is a reference or a temporary that has been allocated
		bool valid() const;

		// Edit

		//- Return tmp pointer for reuse
		T* ptr() const;

		//- If object pointer points to valid object:
		//  delete object and set pointer to NULL
		void clear() const;


		// Member operators

		//- Dereference operator
		T& operator()();

		//- Const dereference operator
		const T& operator()() const;

		//- Const cast to the underlying type reference
		operator const T&() const;

		//- Return object pointer
		T* operator->();

		//- Return const object pointer
		const T* operator->() const;

		//- Assignment operator
		void operator=(const tmp<T>&);
	};
}

#include <tmpI.hxx>

#endif // !_tmp_Header
