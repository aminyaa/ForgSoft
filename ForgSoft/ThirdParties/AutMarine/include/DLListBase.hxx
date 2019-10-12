#pragma once
#ifndef _DLListBase_Header
#define _DLListBase_Header

#include <label.hxx>

namespace AutLib
{

	class DLListBase
	{

	public:

		//- Link structure
		struct link
		{
			//- Pointer to next entry in list
			link *prev_, *next_;

			//- Null construct
			link();

			//- Check if the link is registered with the DLListBase
			bool registered() const;

			//- Deregister the link after removal
			void deregister();
		};


	private:

		// Private data

		//- first_ points to first element and last_ points to last element.
		link *first_, *last_;

		//- Number of elements in in list
		label nElmts_;


		// Private Member Functions

		//- Disallow default bitwise copy construct
		DLListBase(const DLListBase&) = delete;

		//- Disallow default bitwise assignment
		void operator=(const DLListBase&) = delete;


	public:

		// Forward declaration of STL iterators

		class iterator;
		friend class iterator;

		class const_iterator;
		friend class const_iterator;


		// Constructors

		//- Null construct
		DLListBase();

		//- Construct given initial entry
		DLListBase(link*);


		//- Destructor
		~DLListBase();


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

		//- Swap this element with the one above unless it is at the top
		bool swapUp(link*);

		//- Swap this element with the one below unless it is at the bottom
		bool swapDown(link*);

		//- Remove and return head
		link* removeHead();

		//- Remove and return element
		link* remove(link*);

		// Remove and return element specified by iterator
		link* remove(iterator&);

		//- Replace oldLink with newLink and return element
		link* replace(link* oldLink, link* newLink);

		//- Replace oldIter with newLink and return element
		link* replace(iterator& oldIter, link* newLink);

		//- Clear the list
		void clear();

		//- Transfer the contents of the argument into this List
		//  and annul the argument list.
		void transfer(DLListBase&);

		// STL iterator

		//- An STL-conforming iterator
		class iterator
		{
			friend class DLListBase;
			friend class const_iterator;

			// Private data

			//- Reference to the list this is an iterator for
			DLListBase& curList_;

			//- Current element
			link* curElmt_;

			//- Copy of the link
			link curLink_;

			// Private Member Functions

			//- Construct for a given SLListBase with NULL element and link.
			//  Only used to create endIter
			iterator(DLListBase&);

		public:

			//- Construct for a given DLListBase and link
			iterator(DLListBase&, link*);

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
			const DLListBase& curList_;

			//- Current element
			const link* curElmt_;

		public:

			//- Construct for a given DLListBase and link
			const_iterator(const DLListBase&, const link*);

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

#include <DLListBaseI.hxx>

#endif // !_DLListBase_Header