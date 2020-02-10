#pragma once
#ifndef _UList_Header
#define _UList_Header

#include <bool.hxx>
#include <label.hxx>
#include <uLabel.hxx>

namespace tnbLib
{

	// Forward declaration of friend classes
	template<class T> class List;
	template<class T> class SubList;

	// Forward declaration of friend functions and operators
	template<class T> class UList;
	template<class T> Ostream& operator<<(Ostream&, const UList<T>&);


	/*---------------------------------------------------------------------------*\
							   Class UList Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class UList
	{
		// Private data

			//- Vector of values of type T.
		T* __restrict v_;

		//- Number of elements in UList.
		label size_;


	protected:

		// Protected member functions

			//- Reset the list without changing the base pointer
			//  Used in Sublist slicing.  HJ, 19/Oct/2008
		void reset(T* __restrict v, label size);


	public:

		// Related types

			//- Declare friendship with the List class
		friend class List<T>;

		//- Declare friendship with the SubList class
		friend class SubList<T>;


		// Static data members

			//- Empty list
		static const UList<T> zero;


		// Static Member Functions

			//- Return a null UList
		static const UList<T>& null();


		// Public classes

			//- Less function class that can be used for sorting
		class less
		{
			const UList<T>& values_;

		public:

			less(const UList<T>& values)
				:
				values_(values)
			{}

			bool operator()(const label a, const label b)
			{
				return values_[a] < values_[b];
			}
		};


		// Constructors

			//- Null constructor.
		UList();

		//- Construct from components
		UList(T* __restrict v, label size);


		// Member Functions


			// Access

				//- Return the forward circular index, i.e. the next index
				//  which returns to the first at the end of the list
		label fcIndex(const label i) const;

		//- Return the reverse circular index, i.e. the previous index
		//  which returns to the last at the beginning of the list
		label rcIndex(const label i) const;

		//- Return the binary size in number of characters of the UList
		//  if the element is a primitive type
		//  i.e. contiguous<T>() == true
		label byteSize() const;


		//- Return a const pointer to the first data element,
		//  similar to the STL front() method and the string::data() method
		//  This can be used (with caution) when interfacing with C code.
		const T* cdata() const;

		//- Return a pointer to the first data element,
		//  similar to the STL front() method and the string::data() method
		//  This can be used (with caution) when interfacing with C code.
		T* data();

		//- Return the first element of the list.
		T& first();

		//- Return first element of the list.
		const T& first() const;

		//- Return the last element of the list.
		T& last();

		//- Return the last element of the list.
		const T& last() const;


		// Check

			//- Check start is within valid range (0 ... size-1).
		void checkStart(const label start) const;

		//- Check size is within valid range (0 ... size).
		void checkSize(const label size) const;

		//- Check index i is within valid range (0 ... size-1).
		void checkIndex(const label i) const;


		//- Write the UList as a dictionary entry.
		void writeEntry(Ostream&) const;

		//- Write the UList as a dictionary entry with keyword.
		void writeEntry(const word& keyword, Ostream&) const;

		//- Assign elements to those from UList.
		void assign(const UList<T>&);


		// Member operators

			//- Return (subscript-checked on debug) element of UList.
		T& operator[](const label);

		//- Return (subscript-checked on debug) element of constant UList.
		//  Note that the bool specialization adds lazy evaluation so reading
		//  an out-of-range element returns false without any ill-effects
		const T& operator[](const label) const;

		//- Allow cast to a const List<T>&
		operator const tnbLib::List<T>&() const;

		//- Assignment of all entries to the given value
		void operator=(const T&);


		// STL type definitions

			//- Type of values the UList contains.
		typedef T value_type;

		//- Type that can be used for storing into
		//  UList::value_type objects.
		typedef T& reference;

		//- Type that can be used for storing into
		//  constant UList::value_type objects
		typedef const T& const_reference;

		//- The type that can represent the difference between any two
		//  UList iterator objects.
		typedef label difference_type;

		//- The type that can represent the size of a UList.
		typedef label size_type;


		// STL iterator

			//- Random access iterator for traversing UList.
		typedef T* iterator;

		//- Return an iterator to begin traversing the UList.
		iterator begin();

		//- Return an iterator to end traversing the UList.
		iterator end();


		// STL const_iterator

			//- Random access iterator for traversing UList.
		typedef const T* const_iterator;

		//- Return const_iterator to begin traversing the constant UList.
		const_iterator cbegin() const;

		//- Return const_iterator to end traversing the constant UList.
		const_iterator cend() const;

		//- Return const_iterator to begin traversing the constant UList.
		const_iterator begin() const;

		//- Return const_iterator to end traversing the constant UList.
		const_iterator end() const;


		// STL reverse_iterator

			//- Reverse iterator for reverse traversal of UList.
		typedef T* reverse_iterator;

		//- Return reverse_iterator to begin reverse traversing the UList.
		reverse_iterator rbegin();

		//- Return reverse_iterator to end reverse traversing the UList.
		reverse_iterator rend();


		// STL const_reverse_iterator

			//- Reverse iterator for reverse traversal of constant UList.
		typedef const T* const_reverse_iterator;

		//- Return const_reverse_iterator to begin reverse traversing the UList.
		const_reverse_iterator crbegin() const;

		//- Return const_reverse_iterator to end reverse traversing the UList.
		const_reverse_iterator crend() const;

		//- Return const_reverse_iterator to begin reverse traversing the UList.
		const_reverse_iterator rbegin() const;

		//- Return const_reverse_iterator to end reverse traversing the UList.
		const_reverse_iterator rend() const;


		// STL member functions

			//- Return the number of elements in the UList.
		label size() const;

		//- Return size of the largest possible UList.
		label max_size() const;

		//- Return true if the UList is empty (ie, size() is zero).
		bool empty() const;

		//- Swap two ULists of the same type in constant time.
		void swap(UList<T>&);


		// STL member operators

			//- Equality operation on ULists of the same type.
			//  Returns true when the ULists are elementwise equal
			//  (using UList::value_type::operator==).  Takes linear time.
		bool operator==(const UList<T>&) const;

		//- The opposite of the equality operation. Takes linear time.
		bool operator!=(const UList<T>&) const;

		//- Compare two ULists lexicographically. Takes linear time.
		bool operator<(const UList<T>&) const;

		//- Compare two ULists lexicographically. Takes linear time.
		bool operator>(const UList<T>&) const;

		//- Return true if !(a > b). Takes linear time.
		bool operator<=(const UList<T>&) const;

		//- Return true if !(a < b). Takes linear time.
		bool operator>=(const UList<T>&) const;


		// Ostream operator

			// Write UList to Ostream.
#ifndef SWIG
		friend Ostream& operator<< <T>
			(
				Ostream&,
				const UList<T>&
				);
#endif
	};


	template<class T>
	void sort(UList<T>&);

	template<class T, class Cmp>
	void sort(UList<T>&, const Cmp&);

	template<class T>
	void stableSort(UList<T>&);

	template<class T, class Cmp>
	void stableSort(UList<T>&, const Cmp&);

	// Reverse the first n elements of the list
	template<class T>
	void reverse(UList<T>&, const label n);

	// Reverse all the elements of the list
	template<class T>
	void reverse(UList<T>&);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

//#include <UListI.hxx>

/**
 * @def forAll(list, i)
 * Loop across all elements in @a list
 * @par Usage
 * @code
 * forAll(anyList, i)
 * {
 *      statements;
 * }
 * @endcode
 * @sa forAllReverse
*/
/**
 * @def forAllReverse(list, i)
 * Reverse loop across all elements in @a list
 * @par Usage
 * @code
 * forAllReverse(anyList, i)
 * {
 *      statements;
 * }
 * @endcode
 * @sa forAll
*/
#define forAll(list, i) \
    for (tnbLib::label i=0; i<(list).size(); i++)

#define forAllReverse(list, i) \
    for (tnbLib::label i=(list).size()-1; i>=0; i--)

/**
 * @def forAllIter(Container, container, iter)
 * Iterate across all elements in the @a container object of type
 * @a Container.
 * @par Usage
 * @code
 * forAll(ContainerType, container, iter)
 * {
 *     statements;
 * }
 * @endcode
 * @sa forAllConstIter
*/
#define forAllIter(Container,container,iter)                                  \
    for                                                                       \
    (                                                                         \
        Container::iterator iter = (container).begin();                       \
        iter != (container).end();                                            \
        ++iter                                                                \
    )

/**
 * @def forAllConstIter(Container, container, iter)
 * Iterate across all elements in the @a container object of type
 * @a Container with const access.
 * @par Usage
 * @code
 * forAllConstIter(ContainerType, container, iter)
 * {
 *     statements;
 * }
 * @endcode
 * @sa forAllIter
*/
#define forAllConstIter(Container,container,iter)                             \
    for                                                                       \
    (                                                                         \
        Container::const_iterator iter = (container).begin();                 \
        iter != (container).end();                                            \
        ++iter                                                                \
    )


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <UListI.hxx>

#ifdef NoRepository
#   include "UList.cxx"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_UList_Header
