#pragma once
#ifndef _Geom_Sort_Header
#define _Geom_Sort_Header

#include <Standard_TypeDef.hxx>
#include <Stl_Vector.hxx>

#include <iostream>

namespace AutLib
{

	class Geom_Sort
	{

		/*Private Data*/

		static Standard_Integer left_child(const Standard_Integer i) { return 2 * i + 1; }

		template<class T, template<class> class Vector>
		static void PercDown
		(
			Vector<T>& a,
			Vector<Standard_Integer> & s,
			Standard_Integer i,
			const Standard_Integer n
		)
		{
			Standard_Integer child;
			Standard_Integer s_tmp;
			T tmp;

			for (tmp = a[i], s_tmp = s[i]; left_child(i) < n; i = child)
			{
				child = left_child(i);
				if (child != n - 1 && a[child] < a[child + 1])
					++child;
				if (tmp < a[child])
				{
					a[i] = a[child];
					s[i] = s[child];
				}
				else
					break;
			}
			a[i] = tmp;
			s[i] = s_tmp;
		}

		template<class T, template<class> class Vector>
		static void PercDown
		(
			Vector<T>& a,
			Standard_Integer i,
			const Standard_Integer n
		)
		{
			Standard_Integer child;
			T tmp;

			for (tmp = a[i]; left_child(i) < n; i = child)
			{
				child = left_child(i);
				if (child != n - 1 && a[child] < a[child + 1])
					++child;
				if (tmp < a[child])
					a[i] = a[child];
				else
					break;
			}
			a[i] = tmp;
		}

	public:

		template<class T, template<class> class Vector>
		static void Sort
		(
			Vector<T>& a,
			Vector<Standard_Integer>& s
		)
		{
			for (Standard_Integer i = (Standard_Integer)a.size() / 2 - 1; i >= 0; --i)
				Geom_Sort::PercDown<T, Vector>(a, s, (Standard_Integer)i, (Standard_Integer)a.size());

			for (Standard_Integer j = (Standard_Integer)a.size() - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				std::swap(s[0], s[j]);

				Geom_Sort::PercDown<T, Vector>(a, s, 0, (Standard_Integer)j);
			}
		}

		template<class T, template<class> class Vector>
		static void Sort
		(
			Vector<T>& a,
			Vector<Standard_Integer>& s,
			const Standard_Integer theSize
		)
		{
			for (int i = theSize / 2 - 1; i >= 0; --i)
				Geom_Sort::PercDown<T, Vector>(a, s, i, theSize);

			for (int j = theSize - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				std::swap(s[0], s[j]);

				Geom_Sort::PercDown<T, Vector>(a, s, 0, j);
			}
		}

		template<class T, template<class> class Vector>
		static void Sort(Vector<T>& a)
		{
			for (Standard_Integer i = (Standard_Integer)a.size() / 2 - 1; i >= 0; --i)
				Geom_Sort::PercDown<T, Vector>(a, (Standard_Integer)i, (Standard_Integer)a.size());

			for (Standard_Integer j = (Standard_Integer)a.size() - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				Geom_Sort::PercDown<T, Vector>(a, 0, (Standard_Integer)j);
			}
		}

		template<class T, template<class> class Vector>
		static void Sort(Vector<T>& a, const Standard_Integer theSize)
		{
			for (int i = theSize / 2 - 1; i >= 0; --i)
				Geom_Sort::PercDown<T, Vector>(a, i, theSize);

			for (int j = theSize - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				Geom_Sort::PercDown<T, Vector>(a, 0, j);
			}
		}
	};
}

#endif // !_Geom_Sort_Header
