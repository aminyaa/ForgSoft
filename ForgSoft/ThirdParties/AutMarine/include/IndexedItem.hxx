#pragma once
#ifndef _IndexedItem_Header
#define _IndexedItem_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{
	template<class T>
	class IndexedItem
	{

		/*Private Data*/

		Standard_Integer theIndex_;

		T theItem_;

	public:

		typedef typename T::ptType ptType;

		IndexedItem()
		{}

		IndexedItem(const Standard_Integer theIndex, const T& theItem)
			: theIndex_(theIndex)
			, theItem_(theItem)
		{}

		Standard_Integer Index() const
		{
			return theIndex_;
		}

		const T& Item() const
		{
			return theItem_;
		}

		void SetIndex(const Standard_Integer theIndex)
		{
			theIndex_ = theIndex;
		}

		void SetItem(const T& theItem)
		{
			theItem_ = theItem;
		}
	};
}

#endif // !_IndexedItem_Header
