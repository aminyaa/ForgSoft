#pragma once
#ifndef _Xfer_Header
#define _Xfer_Header

namespace AutLib
{

	// Forward declaration of classes
	template<class T> class tmp;

	template<class T>
	class Xfer
	{
		// Private data

		//- Pointer to underlying datatype
		mutable T* ptr_;

	public:

		// Static data members

		//- Empty Xfer
		static const Xfer<T> zero;


		// Constructors

		//- Store object pointer and manage its deletion
		//  Can also be used later to transfer by assignment
		inline explicit Xfer(T* = 0);

		//- Construct by copying or by transferring the parameter contents
		inline explicit Xfer(T&, bool allowTransfer = false);

		//- Construct by copying the parameter contents
		inline explicit Xfer(const T&);

		//- Construct by transferring the contents
		inline Xfer(const Xfer<T>&);

		// Destructor

		inline ~Xfer();

		// Member Functions

		//- Return a null object reference
		inline static const Xfer<T>& null();

		// Member Operators

		//- Transfer the contents into the object
		inline void operator=(T&);

		//- Transfer the contents into the object
		inline void operator=(const Xfer<T>&);

		//- Reference to the underlying datatype
		inline T& operator()() const;

		//- Pointer to the underlying datatype
		inline T* operator->() const;

	};

	/**
	* Construct by copying the contents of the @a arg
	*
	* @sa xferCopyTo, xferMove, xferMoveTo, xferTmp and AutLib::Xfer
	*/
	template<class T>
	inline Xfer<T> xferCopy(const T&);

	/**
	* Construct by transferring the contents of the @a arg
	*
	* @sa xferCopy, xferCopyTo, xferMoveTo, xferTmp and AutLib::Xfer
	*/
	template<class T>
	inline Xfer<T> xferMove(T&);


	/**
	* Construct by transferring the contents of the @a arg
	*
	* @sa xferCopy, xferCopyTo, xferMove, xferMoveTo and AutLib::Xfer
	*/
	template<class T>
	inline Xfer<T> xferTmp(tmp<T>&);


	/**
	* Construct by copying the contents of the @a arg
	* between dissimilar types
	*
	* @sa xferCopy, xferMove, xferMoveTo, xferTmp and AutLib::Xfer
	*/
	template<class To, class From>
	inline Xfer<To> xferCopyTo(const From&);


	/**
	* Construct by transferring the contents of the @a arg
	* between dissimilar types
	*
	* @par Example Use
	* @code
	*     dynamicLabelList dynLst;
	*     ...
	*     labelList plainLst( xferMoveTo<labelList>(dynLst) );
	* @endcode
	*
	* @sa xferCopy, xferCopyTo, xferMove, xferTmp and AutLib::Xfer
	*/
	template<class To, class From>
	inline Xfer<To> xferMoveTo(From&);
}

#include <XferI.hxx>

#endif // !_Xfer_Header
