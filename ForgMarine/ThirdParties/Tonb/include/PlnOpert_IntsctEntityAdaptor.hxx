#pragma once
#ifndef _PlnOpert_IntsctEntityAdaptor_Header
#define _PlnOpert_IntsctEntityAdaptor_Header

#include <Global_AccessMethod.hxx>

#include <memory>
#include <list>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctEntity;

	class PlnOpert_IntsctEntityAdaptor
	{

		/*Private Data*/

		std::list<std::weak_ptr<PlnOpert_IntsctEntity>> thePairs_;

	protected:

		PlnOpert_IntsctEntityAdaptor()
		{}

	public:

		auto NbPaires() const
		{
			return (Standard_Integer)thePairs_.size();
		}

		auto& Paires()
		{
			return thePairs_;
		}

		const auto& Paires() const
		{
			return thePairs_;
		}

		void PushToPairs(const std::weak_ptr<PlnOpert_IntsctEntity>& thePair)
		{
			thePairs_.push_back(thePair);
		}

		//- Macros
		
	};
}

#endif // !_PlnOpert_IntsctEntityAdaptor_Header
