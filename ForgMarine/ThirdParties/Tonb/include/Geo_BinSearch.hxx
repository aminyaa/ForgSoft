#pragma once
#ifndef _Geo_BinSearch_Header
#define _Geo_BinSearch_Header

#include <Global_AccessMethod.hxx>
#include <Entity_Box.hxx>
#include <Adt_AvlTree.hxx>
#include <Traits.hxx>

#include <array>
#include <memory>
#include <vector>

namespace tnbLib
{

	template<class T>
	class Geo_BinSearch
	{

		typedef typename T::ptType Point;

		/*Private Data*/

		std::array<Standard_Integer, (size_t)Point::dim>
			theNbSections_;

		std::array<Standard_Real, (size_t)Point::dim>
			theD_;

		Entity_Box<Point> theDomain_;

		std::vector
			<
			std::shared_ptr
			<
			std::map
			<
			Standard_Integer,
			std::shared_ptr<T>
			>>> theTable_;


		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		Standard_Integer KeyX(const Standard_Real theX) const;

		Standard_Integer KeyY(const Standard_Real theX) const;

		template<class U = Standard_Integer>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			KeyZ(const Standard_Real theX) const
		{
			return (Standard_Integer)((theX - Pmin().Z()) / std::get<2>(D)) + 1;
		}

		const std::vector
			<
			std::shared_ptr
			<
			std::map
			<
			Standard_Integer,
			std::shared_ptr<T>
			>>>& Table() const
		{
			return theTable_;
		}

	public:

		Geo_BinSearch(const Entity_Box<Point>& theDomain)
			: theDomain_(theDomain)
		{}

		const Point& Pmin() const
		{
			return theDomain_.P0();
		}

		const std::array<Standard_Integer, (size_t)Point::dim>& NbSections() const
		{
			return theNbSections_;
		}

		std::array<Standard_Integer, (size_t)Point::dim>& NbSections()
		{
			return theNbSections_;
		}

		const std::array<Standard_Real, (size_t)Point::dim>& D() const
		{
			return theD_;
		}

		template<class U = std::vector<std::shared_ptr<T>>>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			Search(const Entity_Box<Point>& theBox) const
		{
			const auto& pmin = theBox.P0();
			const auto& pmax = theBox.P1();

			const auto i0 = KeyX(pmin.X());
			const auto i1 = KeyX(pmax.X());

			const auto j0 = KeyY(pmin.Y());
			const auto j1 = KeyY(pmin.Y());

			const auto nx = std::get<0>(NbSections());
			const auto ny = std::get<1>(NbSections());

			const auto& table = Table();
			const auto nt = table.size();

			Adt_AvlTree<T> tree;
			tree.SetComparableFunction(&T::IsLess);

			for (auto j = j0; j <= j1; j++)
			{
				for (auto i = i0; i <= i1; i++)
				{
					auto l = (j - 1) * nx + i;

					Debug_If_Condition_Message(NOT INSIDE(l, 0, nt), "Exceed array size");

					if (table[l])
					{
						for (const auto& x : *table[l])
						{
							tree.InsertIgnoreDup(x);
						}
					}
				}
			}

			std::vector<std::shared_ptr<T>> items;
			tree.RetrieveTo(items);

			return std::move(items);
		}


		template<class U = std::vector<std::shared_ptr<T>>>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			Search(const Entity_Box<Point>& theBox) const
		{
			const auto& pmin = theBox.P0();
			const auto& pmax = theBox.P1();

			const auto i0 = KeyX(pmin.X());
			const auto i1 = KeyX(pmax.X());

			const auto j0 = KeyY(pmin.Y());
			const auto j1 = KeyY(pmin.Y());

			const auto k0 = KeyZ(pmin.Z());
			const auto k1 = KeyZ(pmax.Z());

			const auto nx = std::get<0>(NbSections());
			const auto ny = std::get<1>(NbSections());
			const auto nz = std::get<2>(NbSections());

			const auto& table = Table();
			const auto nt = table.size();

			Adt_AvlTree<T> tree;
			tree.SetComparableFunction(&T::IsLess);

			for (auto k = k0; k <= k1; k++)
			{
				for (auto j = j0; j <= j1; j++)
				{
					for (auto i = i0; i <= i1; i++)
					{
						auto l = (k - 1) * nx * ny + (j - 1) * nx + i;

						Debug_If_Condition_Message(NOT INSIDE(l, 0, nt), "Exceed array size");

						if (table[l])
						{
							for (const auto& x : *table[l])
							{
								tree.InsertIgnoreDup(x);
							}
						}
					}
				}
			}

			std::vector<std::shared_ptr<T>> items;
			tree.RetrieveTo(items);

			return std::move(items);
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			Register(const std::vector<std::shared_ptr<T>>& theItems)
		{
			Standard_Real dxMax = 0;
			Standard_Real dyMax = 0;

			Standard_Real xMax = RealFirst();
			Standard_Real xMin = RealLast();
			Standard_Real yMax = RealFirst();
			Standard_Real yMin = RealLast();

			for (const auto& x : theItems)
			{
				const auto& b = x->BoundingBox();

				const auto& p0 = b.P0();
				const auto& p1 = b.P1();

				auto dx = p1.X() - p0.X();
				auto dy = p1.Y() - p0.Y();

				if (dx > dxMax) dxMax = dx;
				if (dy > dyMax) dyMax = dy;

				if (p1.X() > xMax) xMax = p1.X();
				if (p1.Y() > yMax) yMax = p1.Y();
				if (p0.X() < xMin) xMin = p0.X();
				if (p0.Y() < yMin) yMin = p0.Y();
			}

			const auto Dx = xMax - xMin;
			const auto Dy = yMax - yMin;

			const auto dMax = MAX(dxMax, dyMax);

			theNbSections_[0] = size_t(Dx / dMax) + 1;
			theNbSections_[1] = size_t(Dy / dMax) + 1;

			theD_[0] = Dx;
			theD_[1] = Dy;

			const auto nx = theNbSections_[0];
			const auto ny = theNbSections_[1];

			const auto N = nx * ny;

			theTable_.resize(N + 1);

			for (const auto& x : theItems)
			{
				const auto& b = x->BoundingBox();

				const auto& p0 = b.P0();
				const auto& p1 = b.P1();

				auto i0 = KeyX(p0.X());
				auto i1 = KeyX(p1.X());

				auto j0 = KeyY(p0.Y());
				auto j1 = KeyY(p1.Y());

				for (auto j = j0; j <= j1; j++)
				{
					for (auto i = i0; i <= i1; i++)
					{
						auto l = (j - 1) * nx + i;

						Debug_If_Condition_Message(NOT INSIDE(l, 0, N), "Exceed array size");

						if (NOT theTable_[l])
						{
							theTable_[l] = std::make_shared<std::map<Standard_Integer, std::shared_ptr<T>>>();
						}

						theTable_[l]->insert(std::make_pair(x->Index(), x));
					}
				}
			}
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			Register(const std::vector<std::shared_ptr<T>>& theItems)
		{
			const auto b = Entity_Box<T>::BoundingBoxOf(theItems);


		}
	};
}

#include <Geo_BinSearchI.hxx>

#endif // !_Geo_BinSearch_Header