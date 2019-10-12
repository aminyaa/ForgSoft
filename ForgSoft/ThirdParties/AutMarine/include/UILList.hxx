#pragma once
#ifndef _UILList_Header
#define _UILList_Header

#include <label.hxx>

namespace AutLib
{

	template<class LListBase, class T>
	class UILList
		: public LListBase
	{

	public:

		// Forward declaration of STL iterators

		class iterator;
		friend class iterator;

		class const_iterator;
		friend class const_iterator;


		// Constructors

		//- Null construct
		UILList()
		{}

		//- Construct given initial T
		UILList(T* a)
			: LListBase(a)
		{}

		//- Construct as copy
		UILList(const UILList<LListBase, T>&);


		// Member Functions

		// Access

		//- Return the first entry
		T* first()
		{
			return static_cast<T*>(LListBase::first());
		}

		//- Return the first entry
		const T* first() const
		{
			return static_cast<const T*>(LListBase::first());
		}

		//- Return the last entry
		T* last()
		{
			return static_cast<T*>(LListBase::last());
		}

		//- Return the last entry
		const T* last() const
		{
			return static_cast<const T*>(LListBase::last());
		}


		// Edit

		//- Remove and return head
		T* removeHead()
		{
			return static_cast<T*>(LListBase::removeHead());
		}

		//- Remove and return element
		T* remove(T* p)
		{
			return static_cast<T*>(LListBase::remove(p));
		}

		//- Remove and return specified by iterator
		T* remove(iterator& it)
		{
			return static_cast<T*>(LListBase::remove(it));
		}


		// Member operators

		void operator=(const UILList<LListBase, T>&);


		// STL type definitions

		//- Type of values the DLList contains.
		typedef T value_type;

		//- Type that can be used for storing into DLList::value_type
		//  objects.
		typedef T& reference;

		//- Type that can be used for storing into constant
		//  DLList::value_type objects.
		typedef const T& const_reference;

		//- The type that can represent the size of a DLList.
		typedef label size_type;


		// STL iterator

		typedef typename LListBase::iterator LListBase_iterator;

		//- An STL-conforming iterator
		class iterator
			: public LListBase_iterator
		{

		public:

			//- Construct from base iterator
			iterator(LListBase_iterator baseIter)
				:
				LListBase_iterator(baseIter)
			{}


			// Member operators

			T& operator*()
			{
				return static_cast<T&>(LListBase_iterator::operator*());
			}

			T& operator()()
			{
				return operator*();
			}

			iterator& operator++()
			{
				LListBase_iterator::operator++();
				return *this;
			}
		};


		// STL const_iterator

		typedef typename LListBase::const_iterator LListBase_const_iterator;

		//- An STL-conforming const_iterator
		class const_iterator
			:
			public LListBase_const_iterator
		{

		public:

			//- Construct from base const_iterator
			const_iterator(LListBase_const_iterator baseIter)
				:
				LListBase_const_iterator(baseIter)
			{}

			//- Construct from base iterator
			const_iterator(LListBase_iterator baseIter)
				:
				LListBase_const_iterator(baseIter)
			{}

			// Member operators

			const T& operator*()
			{
				return static_cast<const T&> (LListBase_const_iterator::operator*());
			}

			const T& operator()()
			{
				return operator*();
			}

			const_iterator& operator++()
			{
				LListBase_const_iterator::operator++();
				return *this;
			}
		};


		// STL member operators

		//- Equality operation on ULists of the same type.
		//  Returns true when the ULists are element-wise equal
		//  (using UList::value_type::operator==).  Takes linear time.
		bool operator==(const UILList<LListBase, T>&) const;

		//- The opposite of the equality operation. Takes linear time.
		bool operator!=(const UILList<LListBase, T>&) const;


		// Ostream operator

		template<typename LListBase, typename T>
		friend Ostream& operator<<(Ostream&, const UILList<LListBase, T>&);
	};
}

#include <UILListI.hxx>

#endif // !_UILList_Header
