#pragma once
#ifndef _SLListBase_Header
#define _SLListBase_Header

#include <label.hxx>

namespace AutLib
{

	class SLListBase
	{

	public:

		//- Link structure
		struct link
		{
			//- Pointer to next entry in list
			link* next_;

			//- Null construct
			link();

			//- Construct given pointer to another link
			link(link* p);
		};


	private:

		// Private data

		//- last_ points to last element
		//  last_->next_ points to first element, i.e. circular storage
		link* last_;

		//- Number of elements in in list
		label nElmts_;

		// Private Member Functions

		//- Disallow default bitwise copy construct
		SLListBase(const SLListBase&);

		//- Disallow default bitwise assignment
		void operator=(const SLListBase&);


	public:

		// Forward declaration of STL iterators

		class iterator;
		friend class iterator;

		class const_iterator;
		friend class const_iterator;


		// Constructors

		//- Null construct
		SLListBase();

		//- Construct given initial entry
		SLListBase(link*);


		//- Destructor
		~SLListBase();


		// Member Functions

		// Access

		//- Return number of elements in list
		label size() const;

		//- Return true if the list is empty
		bool empty() const;

		//- Return first entry
		link* first();

		//- Return const access to first entry
		const link* first() const;

		//- Return last entry
		link* last();

		//- Return const access to last entry
		const link* last() const;


		// Edit

		//- Add at head of list
		void insert(link*);

		//- Add at tail of list
		void append(link*);

		//- Remove and return head
		link* removeHead();

		// Remove and return element
		link* remove(link*);

		// Remove and return element specified by iterator
		link* remove(iterator&);

		//- Clear the list
		void clear();

		//- Transfer the contents of the argument into this List
		//  and annul the argument list.
		void transfer(SLListBase&);

		// STL iterator

		//- An STL-conforming iterator
		class iterator
		{
			friend class SLListBase;
			friend class const_iterator;

			// Private data

			//- Reference to the list this is an iterator for
			SLListBase& curList_;

			//- Current element
			link* curElmt_;

			//- Copy of the link
			link curLink_;

			// Private Member Functions

			//- Construct for a given SLListBase with NULL element and link.
			//  Only used to create endIter
			iterator(SLListBase&);

		public:

			//- Construct for a given SLListBase and link
			iterator(SLListBase&, link*);

			// Member operators

			void operator=(const iterator&);

			bool operator==(const iterator&) const;
			bool operator!=(const iterator&) const;

			link& operator*();

			iterator& operator++();
			iterator operator++(int);
		};

		iterator begin();
		const iterator& end();


		// STL const_iterator

		//- An STL-conforming const_iterator
		class const_iterator
		{
			// Private data

			//- Reference to the list this is an iterator for
			const SLListBase& curList_;

			//- Current element
			const link* curElmt_;

		public:

			//- Construct for a given SLListBase and link
			const_iterator(const SLListBase&, const link*);

			//- Construct from a non-const iterator
			const_iterator(const iterator&);


			// Member operators

			void operator=(const const_iterator&);

			bool operator==(const const_iterator&) const;
			bool operator!=(const const_iterator&) const;

			const link& operator*();

			const_iterator& operator++();
			const_iterator operator++(int);
		};

		const_iterator cbegin() const;
		const const_iterator& cend() const;

		const_iterator begin() const;
		const const_iterator& end() const;


	private:

		//- Iterator returned by end()
		static iterator endIter_;

		//- const_iterator returned by end()
		static const_iterator endConstIter_;
	};
}

#include <SLListBaseI.hxx>

#endif // !_SLListBase_Header
