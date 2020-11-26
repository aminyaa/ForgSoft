#pragma once
#ifndef _Marine_PhysicsModel_Header
#define _Marine_PhysicsModel_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class Marine_PhysicsModel
		: public std::enable_shared_from_this<Marine_PhysicsModel>
	{

		/*Private Data*/

	protected:

		Marine_PhysicsModel();

	public:

		virtual ~Marine_PhysicsModel()
		{}
	};
}

#endif // !_Marine_PhysicsModel_Header
