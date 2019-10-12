#pragma once
#ifndef _LList_Header
#define _LList_Header

#include <label.hxx>

namespace AutLib
{

	template<class LListBase, class T>
	class LList
		: public LListBase
	{

	public:

		// Forward declaration of STL iterators

		class iterator;
		friend class iterator;

		class const_iterator;
		friend class const_iterator;

		//- Link structure
		struct link
			: public LListBase::link
		{
			//- Stored object
			T obj_;

			//- Construct given object
			link(T a)
				: obj_(a)
			{}
		};


		// Constructors

		//- Null construct
		LList()
		{}

		//- Construct given initial T
		LList(T a)
			:
			LListBase(new link(a))
		{}

		//- Construct from Istream
		LList(Istream&);

		//- Construct as copy
		LList(const LList<LListBase, T>&);


		//- Destructor
		~LList();


		// Member Functions

		// Access

		//- Return the first entry added
		T& first()
		{
			return static_cast<link*>(LListBase::first())->obj_;
		}

		//- Return const access to the first entry added
		const T& first() const
		{
			return static_cast<const link*>(LListBase::first())->obj_;
		}

		//- Return the last entry added
		T& last()
		{
			return static_cast<link*>(LListBase::last())->obj_;
		}

		//- Return const access to the last entry added
		const T& last() const
		{
			return static_cast<const link*>(LListBase::last())->obj_;
		}


		// Edit

		//- Add at head of list
		void insert(const T& a)
		{
			LListBase::insert(new link(a));
		}

		//- Add at tail of list
		void append(const T& a)
		{
			LListBase::append(new link(a));
		}

		//- Remove and return head
		T removeHead()
		{
			link* elmtPtr = static_cast<link*>(LListBase::removeHead());
			T data = elmtPtr->obj_;
			delete elmtPtr;
			return data;
		}

		//- Remove and return element
		T remove(link* l)
		{
			link* elmtPtr = static_cast<link*>(LListBase::remove(l));
			T data = elmtPtr->obj_;
			delete elmtPtr;
			return data;
		}

		//- Remove and return element specified by iterator
		T remove(iterator& it)
		{
			link* elmtPtr = static_cast<link*>(LListBase::remove(it));
			T data = elmtPtr->obj_;
			delete elmtPtr;
			return data;
		}

		//- Delete contents of list
		void clear();

		//- Transfer the contents of the argument into this List
		//  and annul the argument list.
		void transfer(LList<LListBase, T>&);


		// Member operators

		void operator=(const LList<LListBase, T>&);


		// STL type definitions

		//- Type of values the LList contains.
		typedef T value_type;

		//- Type that can be used for storing into value_type
		//  objects.
		typedef T& reference;

		//- Type that can be used for storing into constant
		//  LList::value_type objects.
		typedef const T& const_reference;

		//- The type that can represent the size of a LList.
		typedef label size_type;


		// STL iterator

		typedef typename LListBase::iterator LListBase_iterator;

		//- An STL-conforming iterator
		class iterator
			:
			public LListBase_iterator
		{

		public:

			//- Construct from base iterator
			iterator(LListBase_iterator baseIter)
				: LListBase_iterator(baseIter)
			{}


			// Member operators

			T& operator*()
			{
				return
					static_cast<link&>
					(LListBase_iterator::operator*()).obj_;
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
				: LListBase_const_iterator(baseIter)
			{}


			//- Construct from base iterator
			const_iterator(LListBase_iterator baseIter)
				: LListBase_const_iterator(baseIter)
			{}


			// Member operators

			const T& operator*()
			{
				return
					static_cast<const link&>
					(LListBase_const_iterator::operator*()).obj_;
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


		// IOstream operators

		template<typename LListBase, typename T>
		friend Istream& operator>>(Istream&, LList<LListBase, T>&);

		template<typename LListBase, typename T>
		friend Ostream& operator<<(Ostream&, const LList<LListBase, T>&);
	};
}

#include <LListI.hxx>

#endif // !_LList_Header
