#pragma once
#ifndef _Merge_Pnt_Header
#define _Merge_Pnt_Header

#include <Global_Macros.hxx>
#include <Standard_TypeDef.hxx>
#include <Merge_PntAlg.hxx>
#include <Traits.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>
#include <algorithm>

namespace AutLib
{

	class Merge_Info
	{

		/*Private Data*/

		Standard_Real theResolution_;
		Standard_Real theRadius_;

	protected:

		Merge_Info();

		Merge_Info
		(
			const Standard_Real theRes,
			const Standard_Real theRadius
		)
			: theResolution_(theRes)
			, theRadius_(theRadius)
		{}

	public:

		// Static data members

		static const Standard_Real DEFAULT_RESOLUTION;
		static const Standard_Real DEFAULT_RADIUS;

		Standard_Real Resolution() const
		{
			return theRadius_;
		}

		Standard_Real Radius() const
		{
			return theRadius_;
		}

		void SetResolution
		(
			const Standard_Real theRes
		)
		{
			theResolution_ = theRes;
		}

		void SetRadius
		(
			const Standard_Real theRadius
		)
		{
			theRadius_ = theRadius;
		}
	};

	template<class Point>
	class Merge_Params
	{

		/*Private Data*/

		Point thePmin_;
		Point thePmax_;

		Standard_Real theDelta_;

		Standard_Integer theMaxIndex_;

	protected:

		Merge_Params()
			: theDelta_(0)
			, theMaxIndex_(0)
		{}

		void SetPmin
		(
			const Point& theCoord
		)
		{
			thePmin_ = theCoord;
		}

		void SetPmax
		(
			const Point& theCoord
		)
		{
			thePmax_ = theCoord;
		}

		void SetDelta
		(
			const Standard_Real Value
		)
		{
			theDelta_ = Value;
		}

		void SetMaxIndex
		(
			const Standard_Integer Value
		)
		{
			theMaxIndex_ = Value;
		}

	public:

		const Point& Pmin() const
		{
			return thePmin_;
		}

		Point& Pmin()
		{
			return thePmin_;
		}

		const Point& Pmax() const
		{
			return thePmax_;
		}

		Point& Pmax()
		{
			return thePmax_;
		}

		Standard_Real Delta() const
		{
			return theDelta_;
		}

		Standard_Integer MaxIndex() const
		{
			return theMaxIndex_;
		}

	};

	template<int Dim> struct Merge_StaticMemory
	{
	protected: static std::vector<Standard_Integer> keys;
	};

	template<> std::vector<Standard_Integer> Merge_StaticMemory<2>::keys(9);
	template<> std::vector<Standard_Integer> Merge_StaticMemory<3>::keys(27);

	template
		<
		class Point,
		template<class> class NodeVector,
		Merge_PntAlg Alg = Merge_PntAlg_Mean
		>
		class Merge_Pnt
		: public Merge_Info
		, public Merge_Params<Point>
		, public Merge_StaticMemory<Point::dim>
	{

	public:

		//typedef typename remove_pointer<Point>::type Point;

		typedef Merge_Params<Point> Params;
		typedef Merge_StaticMemory<Point::dim> memory;
		typedef Merge_Info Base;

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		struct node
		{
			//- coordinate of the node
			Point Coord;

			//- index of the node
			Standard_Integer Index;
		};

		typedef std::shared_ptr<std::vector<std::shared_ptr<node>>>
			nodeListPtr;

		template<class Point>
		using Merge_NodeTable = std::vector<nodeListPtr>;

		typedef Merge_NodeTable<std::shared_ptr<node>> nodeTable;
		typedef std::vector<std::shared_ptr<node>> nodeList;
		typedef std::vector<Standard_Integer> indexList;

	private:

		/*Private Data*/

		const NodeVector<Point>* theCoords_;

		nodeList theNodes_;

		Standard_Boolean IsDone_;

		/*Private functions and operators*/

		Standard_Integer Round
		(
			const Standard_Real x
		) const
		{
			return (Standard_Integer)floor(x + 0.5);
		}

		Standard_Integer Key
		(
			const Point& theCoord
		) const
		{
			Standard_Integer key = 0;
			for (Standard_Integer i = 1; i <= Point::nbCmpts; i++)
				key += Round
				(
					MAX(theCoord.Coord(i) - Params::Pmin().Coord(i),
					(Standard_Real)0.) / Params::Delta()
				);
			return key;
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			Keys
			(
				const Standard_Real d,
				const Point& theCoord
			) const
		{
			Standard_Real Xo = theCoord.X();
			Standard_Real Yo = theCoord.Y();

			memory::keys[0] = Key(Point(Xo - d, Yo - d));
			memory::keys[1] = Key(Point(Xo, Yo - d));
			memory::keys[2] = Key(Point(Xo + d, Yo - d));
			memory::keys[3] = Key(Point(Xo - d, Yo));
			memory::keys[4] = Key(theCoord);
			memory::keys[5] = Key(Point(Xo + d, Yo));
			memory::keys[6] = Key(Point(Xo - d, Yo + d));
			memory::keys[7] = Key(Point(Xo, Yo + d));
			memory::keys[8] = Key(Point(Xo + d, Yo + d));
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			Keys
			(
				const Standard_Real d,
				const Point& theCoord
			) const
		{
			Standard_Real Xo = theCoord.X();
			Standard_Real Yo = theCoord.Y();
			Standard_Real Zo = theCoord.Z();

			memory::keys[0] = Key(Point(Xo - d, Yo - d, Zo - d));
			memory::keys[1] = Key(Point(Xo, Yo - d, Zo - d));
			memory::keys[2] = Key(Point(Xo + d, Yo - d, Zo - d));
			memory::keys[3] = Key(Point(Xo - d, Yo, Zo - d));
			memory::keys[4] = Key(Point(Xo, Yo, Zo - d));
			memory::keys[5] = Key(Point(Xo + d, Yo, Zo - d));
			memory::keys[6] = Key(Point(Xo - d, Yo + d, Zo - d));
			memory::keys[7] = Key(Point(Xo, Yo + d, Zo - d));
			memory::keys[8] = Key(Point(Xo + d, Yo + d, Zo - d));

			memory::keys[9] = Key(Point(Xo - d, Yo - d, Zo));
			memory::keys[10] = Key(Point(Xo, Yo - d, Zo));
			memory::keys[11] = Key(Point(Xo + d, Yo - d, Zo));
			memory::keys[12] = Key(Point(Xo - d, Yo, Zo));
			memory::keys[13] = Key(theCoord);
			memory::keys[14] = Key(Point(Xo + d, Yo, Zo));
			memory::keys[15] = Key(Point(Xo - d, Yo + d, Zo));
			memory::keys[16] = Key(Point(Xo, Yo + d, Zo));
			memory::keys[17] = Key(Point(Xo + d, Yo + d, Zo));

			memory::keys[18] = Key(Point(Xo - d, Yo - d, Zo + d));
			memory::keys[19] = Key(Point(Xo, Yo - d, Zo + d));
			memory::keys[20] = Key(Point(Xo + d, Yo - d, Zo + d));
			memory::keys[21] = Key(Point(Xo - d, Yo, Zo + d));
			memory::keys[22] = Key(Point(Xo, Yo, Zo + d));
			memory::keys[23] = Key(Point(Xo + d, Yo, Zo + d));
			memory::keys[24] = Key(Point(Xo - d, Yo + d, Zo + d));
			memory::keys[25] = Key(Point(Xo, Yo + d, Zo + d));
			memory::keys[26] = Key(Point(Xo + d, Yo + d, Zo + d));
		}

		nodeList Search
		(
			const Point& theCoord,
			const nodeTable& theTable
		) const
		{
			Standard_Real d = 0.499*Params::Delta();

			Keys(d, theCoord);

			std::sort(memory::keys.begin(), memory::keys.end());

			Standard_Integer perKey = -IntegerLast();
			nodeList nodes;
			for (const auto& key : memory::keys)
			{
				if (key <= perKey) continue;
				const nodeListPtr& listPtr =
					theTable[key];

				if (listPtr)
				{
					for (const auto& item : *listPtr)
					{
						nodes.push_back(item);
					}
				}
				perKey = key;
			}
			return std::move(nodes);
		}

		static nodeList GetNodes
		(
			const NodeVector<Point>& Coords
		)
		{
			nodeList nodeList(Coords.size());
			Standard_Integer K = 0;
			for (auto& x : nodeList)
			{
				x = std::make_shared<node>();
				x->Index = K + 1;
				x->Coord = Coords[K];
				K++;
			}
			return std::move(nodeList);
		}

		void FindMinMax
		(
			const std::vector<Point>& theCoord
		)
		{
			Params::Pmin() = Params::Pmax() = *theCoord.begin();

			auto& pMin = Params::Pmin();
			auto& pMax = Params::Pmax();

			for (const auto& x : theCoord)
			{
				for (int i = 1; i <= Point::nbCmpts; i++)
				{
					if (x.Coord(i) < pMin.Coord(i))
						pMin.SetCoord(i, x.Coord(i));

					if (x.Coord(i) > pMax.Coord(i))
						pMax.SetCoord(i, x.Coord(i));
				}
			}
		}

		void CalcResolution()
		{
			FindMinMax(*theCoords_);

			Standard_Real D = (Standard_Real)0.;
			for (Standard_Integer coord = 1; coord <= Point::nbCmpts; coord++)
			{
				Standard_Real d =
					Params::Pmax().Coord(coord) - Params::Pmin().Coord(coord);
				if (d > D) D = d;
			}

			if (D <= (Standard_Real)0.)
			{
				FatalErrorIn(FunctionSIG)
					<< "Singularity domain size"
					<< abort(FatalError);
			}

			Params::SetDelta(2.0*Resolution()*D);

			if (Params::Delta() < Radius()) Params::SetDelta(Radius() + EPS6 * D);

			Params::SetPmin(Params::Pmin() - 2.0*Params::Delta());
			Params::SetMaxIndex(Key(Params::Pmax() + 2.0*Params::Delta()));

			if (Params::MaxIndex() <= 0)
			{
				FatalErrorIn(FunctionSIG)
					<< "Singularity domain size"
					<< abort(FatalError);
			}
		}

		template<int Alg> void UpdateNode(node& inode, node& item) const;

		template<>
		void UpdateNode<Merge_PntAlg_Mean>
			(
				node& inode,
				node& item
				) const
		{
			inode.Index = item.Index;
			inode.Coord = item.Coord = MEAN(inode.Coord, item.Coord);
		}

		template<>
		void UpdateNode<Merge_PntAlg_Substitude>
			(
				node& inode,
				node& item
				) const
		{
			inode.Index = item.Index;
		}

		void Merge()
		{
			nodeTable table(Params::MaxIndex() + 1);
			Standard_Integer
				key,
				Flag;

			for (const auto& inode : theNodes_)
			{
				const auto& Pt = inode->Coord;

				nodeList Found = Search(Pt, table);

				Flag = 0;
				for (const auto& item : Found)
				{
					if (Pt.Distance(item->Coord) <= Base::Radius())
					{
						Flag = 1;
						UpdateNode<Alg>(*inode, *item);
						break;
					}
				}

				if (!Flag)
				{
					key = Key(Pt);

					if (!table[key])
					{
						table[key] = std::make_shared<nodeList>();					
					}
					table[key]->push_back(inode);
				}

			}
		}

		Standard_Boolean& Change_IsDone()
		{
			return IsDone_;
		}

	public:

		Merge_Pnt()
			: theCoords_(nullptr)
			, IsDone_(Standard_False)
		{}

		Merge_Pnt
		(
			const Standard_Real theRes,
			const Standard_Real theRadius
		)
			: Merge_Info(theRes, theRadius)
			, theCoords_(nullptr)
			, IsDone_(Standard_False)
		{}

		Merge_Pnt
		(
			const NodeVector<Point>& theCoords
		)
			: theCoords_(&theCoords)
			, IsDone_(Standard_False)
		{}

		Merge_Pnt
		(
			const NodeVector<Point>& theCoords,
			const Standard_Real theRes,
			const Standard_Real theRadius
		)
			: Merge_Info(theRes, theRadius)
			, theCoords_(&theCoords)
			, IsDone_(Standard_False)
		{}

		Standard_Boolean IsDone() const
		{
			return IsDone_;
		}

		void SetCoords
		(
			const NodeVector<Point>& theCoords
		)
		{
			theCoords_ = &theCoords;
		}

		std::vector<Point> CompactPoints() const
		{
			if (NOT IsDone())
			{
				FatalErrorIn(FunctionSIG)
					<< "Merging Points is not performed!"
					<< abort(FatalError);
			}

			if (IsNULL(theCoords_))
			{
				FatalErrorIn(FunctionSIG)
					<< "no points have been imported"
					<< abort(FatalError);
			}

			std::vector<Point> mergedList;
			int K = 0;
			for (const auto& pt : theNodes_)
			{
				if (pt->Index IS_EQUAL K + 1)
					mergedList.push_back(pt->Coord);
				K++;
			}
			return std::move(mergedList);
		}

		indexList CompactIndices() const
		{
			if (NOT IsDone())
			{
				FatalErrorIn(FunctionSIG)
					<< "Merging Points is not performed!"
					<< abort(FatalError);
			}

			if (IsNULL(theCoords_))
			{
				FatalErrorIn(FunctionSIG)
					<< "no points have been imported"
					<< abort(FatalError);
			}

			indexList compactVector(theNodes_.size());
			Standard_Integer K = 0;
			for (const auto& x : theNodes_)
			{
				if (x->Index IS_EQUAL K + 1) compactVector[K] = -1;
				else compactVector[K] = x->Index;
				K++;
			}

			K = 0;
			for (auto& x : compactVector)
				if (x < 0) x = ++K;

			forThose(Index, 0, compactVector.size() - 1)
			{
				if (theNodes_[Index]->Index NOT_EQUAL Index + 1)
				{
					compactVector[Index] = compactVector[compactVector[Index] - 1];
				}
			}
			return std::move(compactVector);
		}

		const nodeList& Nodes() const
		{
			return theNodes_;
		}

		void Perform()
		{
			if (IsNULL(theCoords_))
			{
				FatalErrorIn(FunctionSIG)
					<< " No Point Lists detected"
					<< abort(FatalError);
			}

			if (NOT theCoords_->size())
			{
				FatalErrorIn(FunctionSIG)
					<< " Point Lists is empty"
					<< abort(FatalError);
			}

			theNodes_.resize(theCoords_->size());

			if (theCoords_->size() IS_EQUAL 1)
			{
				theNodes_[0] = std::make_shared<node>();
				theNodes_[0]->Index = 1;
				theNodes_[0]->Coord = (*theCoords_)[0];
				return;
			}

			CalcResolution();

			theNodes_ = GetNodes(*theCoords_);

			Merge();

			Change_IsDone() = Standard_True;
		}


		void Reset()
		{
			theNodes_.clear();
		}
	};
}

#endif // !_Merge_Pnt_Header
