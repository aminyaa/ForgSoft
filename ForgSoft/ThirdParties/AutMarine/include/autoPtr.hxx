#pragma once
#ifndef _autoPtr_Header
#define _autoPtr_Header

namespace AutLib
{

	template<class T>
	class autoPtr
	{

		//- Pointer to object
		mutable T* ptr_;

	public:

		explicit autoPtr(T* tPtr = 0)
			: ptr_(tPtr)
		{}

		//- Construct as copy by transfering pointer to this autoPtr and
		//  setting the arguments pointer to NULL
		autoPtr(const autoPtr<T>& ap)
			: ptr_(ap.ptr_)
		{
			ap.ptr_ = 0;
		}

		~autoPtr()
		{
			clear();
		}

		bool empty() const
		{
			return !ptr_;
		}

		//- Return true if the autoPtr valid (ie, the pointer is set).
		bool valid() const
		{
			return ptr_;
		}

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

		//- Return reference to the object data
		T& operator()();

		//- Return const reference to the object data
		const T& operator()() const;

		// inline T& operator*();
		// inline const T& operator*() const;

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
