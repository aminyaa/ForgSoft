//#pragma once
//#ifndef _PlnOpert_SplitWire_Header
//#define _PlnOpert_SplitWire_Header
//
//#include <Global_Done.hxx>
//
//#include <memory>
//
//namespace tnbLib
//{
//
//	// Forward Declarations
//	class Pln_Curve;
//	class Pln_Wire;
//	class PlnOpert_SplitWire_Info;
//
//	class PlnOpert_SplitWire
//		: public Global_Done
//	{
//
//		typedef PlnOpert_SplitWire_Info info;
//
//		/*Private Data*/
//
//		std::shared_ptr<Pln_Curve> theCutter_;
//		std::shared_ptr<Pln_Wire> theWire_;
//
//		std::shared_ptr<info> theInfo_;
//
//	public:
//
//		PlnOpert_SplitWire
//		(
//			const std::shared_ptr<info>& theInfo
//		)
//			: theInfo_(theInfo)
//		{}
//
//		const auto& Info() const
//		{
//			return theInfo_;
//		}
//
//		const auto& Cutter() const
//		{
//			return theCutter_;
//		}
//
//		const auto& Wire() const
//		{
//			return theWire_;
//		}
//
//		void Perform();
//
//		void LoadCutter(const std::shared_ptr<Pln_Edge>& theEdge)
//		{
//			theCutter_ = theEdge;
//		}
//
//		void LoadWire(const std::shared_ptr<Pln_Wire>& theWire)
//		{
//			theWire_ = theWire;
//		}
//
//
//	};
//}
//
//#endif // !_PlnOpert_SplitWire_Header
