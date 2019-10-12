#pragma once
#ifndef _List_Header
#define _List_Header

#include <UList.hxx>
#include <Xfer.hxx>
#include <autoPtr.hxx>

namespace AutLib
{

	class Istream;
	class Ostream;

	// Forward declaration of friend functions and operators

	template<class T> class List;
	template<class T> class SubList;

	template<class T, unsigned Size> class FixedList;
	template<class T> class PtrList;
	template<class T> class SLList;
	template<class T, unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
	class DynamicList;
	template<class T> class SortableList;
	template<class T> class IndirectList;
	template<class T> class UIndirectList;
	template<class T> class BiIndirectList;

	typedef UList<label> unallocLabelList;

	template<class T>
	class List
		: public UList<T>
	{

	protected:

		//- Override size to be inconsistent with allocated storage.
		//  Use with care.
		void size(const label);

	public:

		// Static data members

		//- Empty list
		static const List<T> zero;


		// Static Member Functions

		//- Return a null list
		static const List<T>& null();

		// Constructors

		//- Null constructor.
		List();

		//- Construct with given size.
		explicit List(const label);

		//- Construct with given size and value for all elements.
		List(const label, const T&);

		//- Copy constructor.
		List(const List<T>&);

		//- Construct by transferring the parameter contents
		List(const Xfer< List<T> >&);

		//- Construct as copy or re-use as specified.
		List(List<T>&, bool reUse);

		//- Construct as subset.
		List(const UList<T>&, const unallocLabelList& mapAddressing);

		//- Construct given start and end iterators.
		template<class InputIterator>
		List(InputIterator first, InputIterator last);

		//- Construct as copy of FixedList<T, Size>
		template<unsigned Size>
		List(const FixedList<T, Size>&);

		//- Construct as copy of PtrList<T>
		List(const PtrList<T>&);

		//- Construct as copy of SLList<T>
		List(const SLList<T>&);

		//- Construct as copy of IndirectList<T>
		List(const IndirectList<T>&);

		//- Construct as copy of UIndirectList<T>
		List(const UIndirectList<T>&);

		//- Construct as copy of BiIndirectList<T>
		List(const BiIndirectList<T>&);

		//- Construct from Istream.
		List(Istream&);

		//- Clone
		autoPtr<List<T> > clone() const;


		// Destructor

		~List();


		// Related types

		//- Declare type of subList
		typedef SubList<T> subList;


		// Member Functions

		//- Return the number of elements in the UList.
		label size() const;


		// Edit

		//- Reset size of List.
		void resize(const label);

		//- Reset size of List and value for new elements.
		void resize(const label, const T&);

		//- Reset size of List.
		void setSize(const label);

		//- Reset size of List and value for new elements.
		void setSize(const label, const T&);

		//- Clear the list, i.e. set size to zero.
		void clear();

		//- Append a List at the end of this list
		void append(const UList<T>&);

		//- Append a UIndirectList at the end of this list
		void append(const UIndirectList<T>&);

		//- Transfer the contents of the argument List into this list
		//  and annull the argument list.
		void transfer(List<T>&);

		//- Transfer the contents of the argument List into this list
		//  and annull the argument list.
		template<unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
		void transfer(DynamicList<T, SizeInc, SizeMult, SizeDiv>&);

		//- Transfer the contents of the argument List into this list
		//  and annull the argument list.
		void transfer(SortableList<T>&);

		//- Transfer contents to the Xfer container
		Xfer< List<T> > xfer();

		//- Return subscript-checked element of UList.
		T& newElmt(const label);

		// Member operators

		//- Assignment from UList operator. Takes linear time.
		void operator=(const UList<T>&);

		//- Assignment operator. Takes linear time.
		void operator=(const List<T>&);

		//- Assignment from SLList operator. Takes linear time.
		void operator=(const SLList<T>&);

		//- Assignment from IndirectList operator. Takes linear time.
		void operator=(const IndirectList<T>&);

		//- Assignment from UIndirectList operator. Takes linear time.
		void operator=(const UIndirectList<T>&);

		//- Assignment from BiIndirectList operator. Takes linear time.
		void operator=(const BiIndirectList<T>&);

		//- Assignment of all entries to the given value
		void operator=(const T&);

		//- Read List from Istream, discarding contents of existing List.
		template<typename T>
		friend Istream& operator>>(Istream&, List<T>&);
	};

	//- Read a bracket-delimited list, or handle a single value as list of size 1.
	//  For example,
	//  @code
	//      wList = readList<word>(IStringStream("(patch1 patch2 patch3)")());
	//      wList = readList<word>(IStringStream("patch0")());
	//  @endcode
	//  Mostly useful for handling command-line arguments.
	template<class T>
	List<T> readList(Istream&);
}

#include <ListI.hxx>

#endif // !_List_Header
