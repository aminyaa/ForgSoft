#pragma once
#ifndef _Geom_ItemSort_Header
#define _Geom_ItemSort_Header

#include <Standard_TypeDef.hxx>

#include <vector>

namespace AutLib
{

	template<class T>
	class Geom_ItemSort
	{

		/*Private Data*/

		Standard_Boolean(*IsLess_)(const T&, const T&);

		static Standard_Integer left_child(const Standard_Integer i) { return 2 * i + 1; }

		void PercDown(std::vector<T>& a, Standard_Integer i, const Standard_Integer n) const
		{
			Standard_Integer child;
			T tmp;

			for (tmp = a[i]; left_child(i) < n; i = child)
			{
				child = left_child(i);
				if (child != n - 1 &&(IsLess_(a[child], a[child + 1])))
					++child;
				if (IsLess_(tmp, a[child]))
					a[i] = a[child];
				else
					break;
			}
			a[i] = tmp;
		}

	public:

		Geom_ItemSort(Standard_Boolean(*IsLess)(const T&, const T&))
			: IsLess_(IsLess)
		{}

		void Perform(std::vector<T>& a) const
		{
			for (int i = (int)a.size() / 2 - 1; i >= 0; --i)
				PercDown(a, i, (int)a.size());

			for (int j = (int)a.size() - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				PercDown(a, 0, j);
			}
		}
	};
}

#endif // !_Geom_ItemSort_Header
