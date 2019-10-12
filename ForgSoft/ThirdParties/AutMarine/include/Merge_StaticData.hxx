#pragma once
#ifndef _Merge_StaticData_Header
#define _Merge_StaticData_Header

#include <Merge_Pnt.hxx>

#include <memory>
#include <Stl_Vector.hxx>

namespace AutLib
{

	// Forward Declarations

	class Merge_StaticDataInfo
	{

		/*Private Data*/

		Standard_Boolean IsDone_;
		Standard_Boolean HandleDegeneracy_;

	protected:

		void SetDone()
		{
			IsDone_ = Standard_True;
		}

		Standard_Boolean HandleDegeneracy() const
		{
			return HandleDegeneracy_;
		}

	public:

		Merge_StaticDataInfo()
			: IsDone_(Standard_False)
			, HandleDegeneracy_(Standard_False)
		{}

		void SetRemoveDegeneracy()
		{
			HandleDegeneracy_ = Standard_True;
		}

		Standard_Boolean IsDone() const
		{
			return IsDone_;
		}

	};

	template<class ItemType, Merge_PntAlg Alg = Merge_PntAlg_Mean>
	class Merge_StaticData
		: public Merge_StaticDataInfo
	{

		typedef typename ItemType::ptType Point;
		typedef typename ItemType::connectType Connectivity;
		typedef std::shared_ptr<ItemType> item_ptr;
		typedef Stl_Vector<item_ptr> itemList;

		typedef Merge_Pnt<Point, Stl_Vector, Alg> merging;

		/*Private Data*/

		merging theAlg_;

		item_ptr theItem_;

		void UpdateIndices
		(
			Connectivity& Matrix,
			Stl_Vector<Standard_Integer> Indices
		) const
		{
			for (int i = 0; i < Connectivity::nbCmpts; i++)
			{
				Matrix.Value(i) = Indices[Matrix.Value(i) - 1];
			}
		}

	public:

		Merge_StaticData()
		{}

		void Import(const itemList& theList)
		{
			theItem_ = std::make_shared<ItemType>();

			auto& item = *theItem_;

			auto nbPts = (Standard_Integer)0;
			auto nbConnect = (Standard_Integer)0;
			for (const auto& x : theList)
			{
				if (!x)
				{
					FatalErrorIn("void Import(const itemList& theList)")
						<< "Null pointer has been encountered!"
						<< abort(FatalError);
				}
				const auto& Points = x->Points();
				const auto& Matrix = x->Connectivity();
				nbPts += (Standard_Integer)Points.size();
				nbConnect += (Standard_Integer)Matrix.size();
			}

			auto& pointList = item.Points();
			pointList.reserve(nbPts);
			for (const auto& x : theList)
			{
				const auto& Points = x->Points();
				for (const auto& pt : Points)
					pointList.push_back(pt);
			}

			auto& Matrix = item.Connectivity();
			Matrix.reserve(nbConnect);
			nbPts = 0;
			for (const auto& x : theList)
			{
				const auto& ConnectMatrix = x->Connectivity();
				for (const auto& I : ConnectMatrix)
				{
					Connectivity nI;
					for (int i = 0; i < Connectivity::nbCmpts; i++)
					{
						nI.Value(i) = I.Value(i) + nbPts;
					}
					Matrix.push_back(nI);
				}
				nbPts += x->NbPoints();
			}
		}

		void Import(const ItemType& theItem)
		{
			theItem_ = std::make_shared<ItemType>();

			auto& item = *theItem_;

			item.Points() = theItem.Points();
			item.Connectivity() = theItem.Connectivity();
		}

		void Perform()
		{
			if (!theItem_)
			{
				FatalErrorIn("void Perform()")
					<< "Null pointer has been encountered!"
					<< abort(FatalError);
			}
			auto& item = *theItem_;

			// Merging the points
			theAlg_.SetCoords(item.Points());
			theAlg_.Perform();

			// Import Merged Points to the item
			item.Points() = theAlg_.CompactPoints();
			
			auto Indices = theAlg_.CompactIndices();

			auto& ConnectMat = item.Connectivity();

			if (HandleDegeneracy())
			{
				Stl_Vector<Connectivity> Q;
				for (auto& x : ConnectMat)
				{
					UpdateIndices(x, Indices);
					if (!x.IsDegenerated()) Q.push_back(x);
				}

				//ConnectMat.resize(Q.size());
				ConnectMat = Q;
			}
			else
			{
				for (auto& x : ConnectMat)
				{
					UpdateIndices(x, Indices);
				}
			}

			SetDone();
		}

		Merge_Info& InfoAlg()
		{
			return theAlg_;
		}

		const item_ptr& Merged() const
		{
			if (NOT IsDone())
			{
				FatalErrorIn("const item_ptr& Merged() const")
					<< "The algorithm is not performed!"
					<< abort(FatalError);
			}
			return theItem_;
		}
	};
}

#endif // !_Merge_StaticData_Header
