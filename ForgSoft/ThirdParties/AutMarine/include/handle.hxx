#pragma once
#ifndef _handle_Header
#define _handle_Header

#include <Standard_Macro.hxx>
#include <Transient.hxx>

#include <type_traits>

namespace AutLib
{

	// Forward Declarations
	class Transient;

	//! Trait yielding true if class T1 is base of T2 but not the same
	template <class T1, class T2, class Dummy = void>
	struct is_base_but_not_same : std::is_base_of <T1, T2> {};

	//! Explicit specialization of is_base_of trait to workaround the
	//! requirement of type to be complete when T1 and T2 are the same.
	template <class T1, class T2>
	struct is_base_but_not_same <T1, T2, typename std::enable_if <std::is_same <T1, T2>::value>::type> : std::false_type {};

	template<class T>
	class handle
	{

		Transient* entity;

		void assign(Transient* thePtr)
		{
			if (thePtr == entity) return;
			endScope();
			entity = thePtr;
			beginScope();
		}

		//! Increment reference counter of referred object 
		void beginScope()
		{
			if (entity != 0)
				entity->incrementRefCounter();
		}

		//! Decrement reference counter and if 0, destroy referred object
		void endScope()
		{
			if (entity != 0 && entity->decrementRefCounter() == 0)
				entity->deleteThis();
			entity = 0;
		}

	public:

		//! STL-compliant typedef of contained type
		typedef T element_type;

		handle()
			: entity(0)
		{}

		handle(const T* thePtr)
			: entity(const_cast<T*>(thePtr))
		{
			beginScope();
		}

		handle(const handle& theHandle)
			: entity(theHandle.entity)
		{
			beginScope();
		}

		handle(handle&& theHandle)
			: entity(theHandle.entity)
		{
			theHandle.entity = 0;
		}

		~handle()
		{
			endScope();
		}

		void nullify()
		{
			endScope();
		}

		Standard_Boolean isNull() const { return entity == 0; }

		void reset(T* thePtr)
		{
			assign(thePtr);
		}

		handle& operator=(const handle& theHandle)
		{
			assign(theHandle.entity);
			return *this;
		}

		handle& operator=(const T* thePtr)
		{
			assign(const_cast<T*>(thePtr));
			return *this;
		}

		handle& operator=(handle&& theHandle)
		{
			std::swap(entity, theHandle.entity);
			return *this;
		}

		//! STL-like cast to pointer to referred object (note non-const).
		//! @sa std::shared_ptr::get()
		T* get() const { return static_cast<T*>(entity); }

		//! Member access operator (note non-const)
		T* operator-> () const { return static_cast<T*>(entity); }

		//! Dereferencing operator (note non-const)
		T& operator* () const { return *get(); }

		//! Check for equality
		template <class T2>
		bool operator== (const handle<T2>& theHandle) const
		{
			return get() == theHandle.get();
		}

		//! Check for equality
		template <class T2>
		bool operator== (const T2 *thePtr) const
		{
			return get() == thePtr;
		}

		//! Check for equality
		template <class T2>
		friend bool operator== (const T2 *left, const handle& right)
		{
			return left == right.get();
		}

		//! Check for inequality
		template <class T2>
		bool operator!= (const handle<T2>& theHandle) const
		{
			return get() != theHandle.get();
		}

		//! Check for inequality
		template <class T2>
		bool operator!= (const T2 *thePtr) const
		{
			return get() != thePtr;
		}

		//! Check for inequality
		template <class T2>
		friend bool operator!= (const T2 *left, const handle& right)
		{
			return left != right.get();
		}

		//! Compare operator for possible use in std::map<> etc. 
		template <class T2>
		bool operator< (const handle<T2>& theHandle) const
		{
			return get() < theHandle.get();
		}

		//! Down casting operator from handle to base type
		template <class T2>
		static typename std::enable_if<is_base_but_not_same<T2, T>::value, handle>::type downCast(const handle<T2>& theObject)
		{
			return handle(dynamic_cast<T*>(const_cast<T2*>(theObject.get())));
		}

		//! Down casting operator from pointer to base type
		template <class T2>
		static typename std::enable_if<is_base_but_not_same<T2, T>::value, handle>::type downCast(const T2* thePtr)
		{
			return handle(dynamic_cast<T*>(const_cast<T2*>(thePtr)));
		}

		//! For compatibility, define down casting operator from non-base type, as deprecated
		template <class T2>
		Standard_DEPRECATED("down-casting from object of the same or unrelated type is meaningless")
			static handle downCast(const handle<T2>& theObject, typename std::enable_if<!is_base_but_not_same<T2, T>::value, void*>::type = 0)
		{
			return handle(dynamic_cast<T*>(const_cast<T2*>(theObject.get())));
		}

		//! For compatibility, define down casting operator from non-base type, as deprecated
		template <class T2>
		Standard_DEPRECATED("down-casting from object of the same or unrelated type is meaningless")
			static handle downCast(const T2* thePtr, typename std::enable_if<!is_base_but_not_same<T2, T>::value, void*>::type = 0)
		{
			return handle(dynamic_cast<T*>(const_cast<T2*>(thePtr)));
		}

		//! Conversion to bool for use in conditional expressions
		explicit operator bool() const
		{
			return entity != nullptr;
		}

		//! Upcast to const reference to base type.
		template <class T2, typename = typename std::enable_if<is_base_but_not_same<T2, T>::value>::type>
		operator const handle<T2>& () const
		{
			return reinterpret_cast<const handle<T2>&>(*this);
		}

		//! Upcast to non-const reference to base type.
		//! NB: this cast can be dangerous, but required for legacy code; see #26377
		template <class T2, typename = typename std::enable_if<is_base_but_not_same<T2, T>::value>::type>
		operator handle<T2>& ()
		{
			return reinterpret_cast<handle<T2>&>(*this);
		}
	};
}

#define pHandle(Class) AutLib::handle<Class>



#endif // !_handle_Header
