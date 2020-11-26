#ifndef _PlnOpert_Cutter_Intersection_Header
#define _PlnOpert_Cutter_Intersection_Header

#include <Global_Done.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Pln_CmpEdge;
	class Pln_Wire;
	class Pln_Edge;
	class PlnOpert_IntsctPair;

	class PlnOpert_Cutter_Intersection
		: public Global_Done
	{

		typedef std::shared_ptr<Pln_Wire> outerWire;

		typedef std::vector<std::shared_ptr<Pln_Wire>> wireList;
		typedef std::shared_ptr<wireList> innerWires;

		/*Private Data*/

		std::shared_ptr<Pln_CmpEdge> theCutter_;

		outerWire theOuter_;
		innerWires theInners_;

		std::vector<std::shared_ptr<PlnOpert_IntsctPair>> theEntities_;


		auto& ChangeEntities()
		{
			return theEntities_;
		}

	public:

		PlnOpert_Cutter_Intersection()
		{}

		PlnOpert_Cutter_Intersection
		(
			const std::shared_ptr<Pln_CmpEdge>& theCutter,
			const outerWire& theOuter,
			const innerWires& theInners = nullptr
		)
			: theCutter_(theCutter)
			, theOuter_(theOuter)
			, theInners_(theInners)
		{}

		const auto& OuterWire() const
		{
			return theOuter_;
		}

		const auto& InnerWires() const
		{
			return theInners_;
		}

		const auto& Cutter() const
		{
			return theCutter_;
		}

		const auto& Entities() const
		{
			return theEntities_;
		}

		void Perform(const Standard_Real theTol);

		void LoadCutter(const std::shared_ptr<Pln_CmpEdge>& theCutter)
		{
			theCutter_ = theCutter;
		}

		void LoadOuter(const outerWire& theOuter)
		{
			theOuter_ = theOuter;
		}

		void LoadInners(const innerWires& theInners)
		{
			theInners_ = theInners;
		}
	};
}

#endif // !_PlnOpert_Cutter_Intersection_Header
