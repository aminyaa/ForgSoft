#pragma once
#ifndef _Adt_SlList_Header
#define _Adt_SlList_Header

#include <Standard_TypeDef.hxx>
#include <algorithm>

namespace AutLib
{

	class Adt_SlListBase
	{

		/*Private Data*/

		Standard_Integer theNbItems_;

	protected:

		Adt_SlListBase()
			: theNbItems_(0)
		{}

		Standard_Integer NbItems() const
		{
			return theNbItems_;
		}

		Standard_Integer& NbItems()
		{
			return theNbItems_;
		}
	};

	template<class T>
	class Adt_SlList
		: public Adt_SlListBase
	{

		/*Private Data*/

		struct Node
		{

			T data_;
			Node *Next_;

			Node
			(
				const T& d = T{},
				Node* next = nullptr
			)
				: data_(d)
				, Next_(next)
			{}

			Node
			(
				T&& d,
				Node* next = nullptr
			)
				: data_(std::move(d))
				, Next_(next)
			{}
		};

		Node* theFirst_;
		Node* theLast_;

		void Increment()
		{
			NbItems()++;
		}

		void Decrement()
		{
			NbItems()--;
		}

	public:

		class const_iterator
		{
			/*Private Data*/

			friend class Adt_SlList<T>;

		protected:

			Node* current_;

			T& retrieve() const
			{
				return current_->data_;
			}

			const_iterator(Node* p) : current_{p}
			{}

		public:

			const_iterator()
				: current_{nullptr}
			{}

			const T& operator*() const
			{
				return retrieve();
			}

			const_iterator& operator++()
			{
				current_ = current_->Next_;
				return *this;
			}

			const_iterator& operator++(int)
			{
				const_iterator old = *this;
				++(*this);
				return old;
			}

			bool operator==(const const_iterator& rhs) const
			{
				return current_ == rhs.current_;
			}

			bool operator!=(const const_iterator& rhs) const
			{
				return !(*this == rhs);
			}
		};

		class iterator
			: public const_iterator
		{

			/*Private Data*/

			friend class Adt_SlList<T>;

		protected:

			iterator(Node* p)
				: const_iterator{p}
			{}

		public:

			iterator()
			{}

			T& operator*()
			{
				return const_iterator::retrieve();
			}

			const T& operator*() const
			{
				return const_iterator::operator*();
			}

			iterator& operator++()
			{
				this->current_ = this->current_->Next_;
				return *this;
			}

			iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}
		};

		Adt_SlList()
		{}



		Standard_Integer Size()
		{
			return NbItems();
		}
	};
}

#endif // !_Adt_SlList_Header
