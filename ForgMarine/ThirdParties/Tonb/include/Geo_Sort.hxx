#pragma once
#ifndef _Geo_Sort_Header
#define _Geo_Sort_Header

#include <Standard_TypeDef.hxx>

#include <iostream>
#include <vector>

namespace tnbLib
{

	class Geo_Sort
	{

		/*Private Data*/

		static inline Standard_Integer left_child(const Standard_Integer i) { return 2 * i + 1; }

		template<class T>
		static void PercDown
		(
			std::vector<T>& a,
			std::vector<Standard_Integer> & s,
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

		template<class T>
		static void PercDown
		(
			std::vector<T>& a,
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

		template<class T>
		static void Sort
		(
			std::vector<T>& a,
			std::vector<Standard_Integer>& s
		)
		{
			for (auto i = (Standard_Integer)a.size() / 2 - 1; i >= 0; --i)
				Geo_Sort::PercDown<T>(a, s, i, (Standard_Integer)a.size());

			for (auto j = (Standard_Integer)a.size() - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				std::swap(s[0], s[j]);

				Geo_Sort::PercDown<T>(a, s, 0, j);
			}
		}

		template<class T>
		static void Sort
		(
			std::vector<T>& a,
			std::vector<Standard_Integer>& s,
			const Standard_Integer theSize
		)
		{
			for (int i = theSize / 2 - 1; i >= 0; --i)
				Geo_Sort::PercDown<T>(a, s, i, theSize);

			for (int j = theSize - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				std::swap(s[0], s[j]);

				Geo_Sort::PercDown<T>(a, s, 0, j);
			}
		}

		template<class T>
		static void Sort(std::vector<T>& a)
		{
			for (auto i = (Standard_Integer)a.size() / 2 - 1; i >= 0; --i)
				Geo_Sort::PercDown<T>(a, i, (Standard_Integer)a.size());

			for (auto j = (Standard_Integer)a.size() - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				Geo_Sort::PercDown<T>(a, 0, j);
			}
		}

		template<class T>
		static void Sort(std::vector<T>& a, const Standard_Integer theSize)
		{
			for (int i = theSize / 2 - 1; i >= 0; --i)
				Geo_Sort::PercDown<T>(a, i, theSize);

			for (int j = theSize - 1; j > 0; --j)
			{
				std::swap(a[0], a[j]);
				Geo_Sort::PercDown<T>(a, 0, j);
			}
		}
	};
}

#endif // !_Geo_Sort_Header