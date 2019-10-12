#pragma once
#ifndef _Adt_List_Header
#define _Adt_List_Header

#include <Adt_Ary1d.hxx>

#include <algorithm>

namespace AutLib
{

	template<class Object>
	class Adt_List
	{

		/*Private Data*/

		Standard_Integer theSize;

		struct Node
		{

			Object  data;
			Node   *prev;
			Node   *next;

			Node
			(
				const Object & d = Object{},
				Node * p = nullptr,
				Node * n = nullptr
			)
				: data{ d }
				, prev{ p }
				, next{ n } 
			{}

			Node
			(
				Object && d,
				Node * p = nullptr,
				Node * n = nullptr
			)
				: data{ std::move(d) }
				, prev{ p }
				, next{ n } 
			{}
		};

		Node *head;
		Node *tail;

		void init()
		{
			theSize = 0;
			head = new Node;
			tail = new Node;
			head->next = tail;
			tail->prev = head;
		}

	public:

		class const_iterator
		{
		public:

			// Public constructor for const_iterator.
			const_iterator() : current{ nullptr }
			{ }

			// Return the object stored at the current position.
			// For const_iterator, this is an accessor with a
			// const reference return type.
			const Object & operator* () const
			{
				return retrieve();
			}

			const_iterator & operator++ ()
			{
				current = current->next;
				return *this;
			}

			const_iterator operator++ (int)
			{
				const_iterator old = *this;
				++(*this);
				return old;
			}

			const_iterator & operator-- ()
			{
				current = current->prev;
				return *this;
			}

			const_iterator operator-- (int)
			{
				const_iterator old = *this;
				--(*this);
				return old;
			}

			bool operator== (const const_iterator & rhs) const
			{
				return current == rhs.current;
			}

			bool operator!= (const const_iterator & rhs) const
			{
				return !(*this == rhs);
			}

		protected:

			Node *current;

			// Protected helper in const_iterator that returns the object
			// stored at the current position. Can be called by all
			// three versions of operator* without any type conversions.
			Object & retrieve() const
			{
				return current->data;
			}

			// Protected constructor for const_iterator.
			// Expects a pointer that represents the current position.
			const_iterator(Node *p) : current{ p }
			{}

			friend class Adt_List<Object>;
		};

		class iterator : public const_iterator
		{
		public:

			// Public constructor for iterator.
			// Calls the base-class constructor.
			// Must be provided because the private constructor
			// is written; otherwise zero-parameter constructor
			// would be disabled.
			iterator()
			{ }

			Object & operator* ()
			{
				return const_iterator::retrieve();
			}

			// Return the object stored at the current position.
			// For iterator, there is an accessor with a
			// const reference return type and a mutator with
			// a reference return type. The accessor is shown first.
			const Object & operator* () const
			{
				return const_iterator::operator*();
			}

			iterator & operator++ ()
			{
				this->current = this->current->next;
				return *this;
			}

			iterator operator++ (int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}

			iterator & operator-- ()
			{
				this->current = this->current->prev;
				return *this;
			}

			iterator operator-- (int)
			{
				iterator old = *this;
				--(*this);
				return old;
			}

		protected:
			// Protected constructor for iterator.
			// Expects the current position.
			iterator(Node *p) : const_iterator{ p }
			{ }

			friend class Adt_List<Object>;
		};

	public:

		Adt_List()
		{
			init();
		}

		~Adt_List()
		{
			Clear();
			delete head;
			delete tail;
		}

		Adt_List(const Adt_List& rhs)
		{
			init();
			for (auto & x : rhs)
				push_back(x);
		}

		Adt_List(Adt_List && rhs)
			: theSize{ rhs.theSize }
			, head{ rhs.head }
			, tail{ rhs.tail }
		{
			rhs.theSize = 0;
			rhs.head = nullptr;
			rhs.tail = nullptr;
		}

		Adt_List & operator= (const Adt_List & rhs)
		{
			Adt_List copy = rhs;
			std::swap(*this, copy);
			return *this;
		}

		Adt_List & operator= (Adt_List && rhs)
		{
			std::swap(theSize, rhs.theSize);
			std::swap(head, rhs.head);
			std::swap(tail, rhs.tail);

			return *this;
		}

		// Return iterator representing beginning of list.
		// Mutator version is first, then accessor version.
		iterator begin()
		{
			return iterator(head->next);
		}

		const_iterator begin() const
		{
			return const_iterator(head->next);
		}

		// Return iterator representing endmarker of list.
		// Mutator version is first, then accessor version.
		iterator end()
		{
			return iterator(tail);
		}

		const_iterator end() const
		{
			return const_iterator(tail);
		}

		// Return number of elements currently in the list.
		Standard_Integer Size() const
		{
			return theSize;
		}

		// Return true if the list is empty, false otherwise.
		Standard_Boolean IsEmpty() const
		{
			return Size() == 0;
		}

		void Clear()
		{
			while (!IsEmpty())
				pop_front();
		}

		// front, back, push_front, push_back, pop_front, and pop_back
		// are the basic double-ended queue operations.
		Object & front()
		{
			return *begin();
		}

		const Object & front() const
		{
			return *begin();
		}

		Object & back()
		{
			return *--end();
		}

		const Object & back() const
		{
			return *--end();
		}

		void push_front(const Object & x)
		{
			insert(begin(), x);
		}

		void push_back(const Object & x)
		{
			insert(end(), x);
		}

		void push_front(Object && x)
		{
			insert(begin(), std::move(x));
		}

		void push_back(Object && x)
		{
			insert(end(), std::move(x));
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_front(Object& x)
		{
			x = *begin();

			erase(begin());
		}

		void pop_back(Object& x)
		{
			x = *(--end());
			erase(--end());
		}

		// Insert x before itr.
		iterator insert(iterator itr, const Object & x)
		{
			Node *p = itr.current;
			++theSize;
			return iterator(p->prev = p->prev->next = new Node{ x, p->prev, p });
		}

		// Insert x before itr.
		iterator insert(iterator itr, Object && x)
		{
			Node *p = itr.current;
			++theSize;
			return iterator(p->prev = p->prev->next = new Node{ std::move(x), p->prev, p });
		}

		// Erase item at itr.
		iterator erase(iterator itr)
		{
			Node *p = itr.current;
			iterator retVal(p->next);
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			--theSize;

			return retVal;
		}

		iterator erase(iterator from, iterator to)
		{
			for (iterator itr = from; itr != to;)
				itr = erase(itr);

			return to;
		}

		void RetrieveTo(Adt_Ary1d<Object>& theItems) const
		{
			theItems.Resize(Size());
			auto iter = begin();
			Standard_Integer k = 0;

			while (iter != end())
				theItems[k++] = *iter++;
		}

		Adt_Ary1d<Object> Retrieve() const
		{
			Adt_Ary1d<Object> List;
			RetrieveTo(List);
			MOVE(List);
		}
	};


	template<typename Object>
	class Adt_Queue
		: public Adt_List<Object>
	{

		typedef Adt_List<Object> list;

	public:

		// enqueue calls list member function insert_at_back
		void EnQueue(const Object& x)
		{
			list::push_back(x);
		}

		void EnQueue(const Adt_Ary1d<Object>& data)
		{
			for (const auto& x : data)
			{
				EnQueue(x);
			}
		}

		// dequeue calls list member function remove_from_front
		Standard_Boolean deQueue(Object& x)
		{
			if (list::IsEmpty())
				return Standard_False;
			else
			{
				list::pop_front(x);
				return Standard_True;
			}
		}

		Adt_Ary1d<Object> operator()() const
		{
			Standard_Integer K = 0;
			Adt_Ary1d<Object> ary(list::Size());
			for (const auto& x : *this)
			{
				ary[K++] = x;
			}
			MOVE(ary);
		}
	};
}

#endif // !_Adt_List_Header
