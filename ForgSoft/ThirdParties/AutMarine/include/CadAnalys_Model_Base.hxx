#pragma once
#ifndef _CadAnalys_Model_Base_Header
#define _CadAnalys_Model_Base_Header

#include <Global_Done.hxx>
#include <Global_Named.hxx>
#include <Global_Indexed.hxx>

#include <map>
#include <memory>
#include <vector>

namespace AutLib
{

	template<class PatchType>
	class CadAnalys_Model_Base
	{

		typedef std::map<Standard_Integer, std::shared_ptr<PatchType>>
			indexedEntityMap;

		/*Private Data*/

		indexedEntityMap theRegulars_;
		indexedEntityMap theDefects_;

		indexedEntityMap theDeepSingulars_;
		indexedEntityMap theCommonSingulars_;

	protected:

		CadAnalys_Model_Base()
		{}

		indexedEntityMap& ChangeRegulars()
		{
			return theRegulars_;
		}

		indexedEntityMap& ChangeDefects()
		{
			return theDefects_;
		}

		indexedEntityMap& ChangeDeepSingulars()
		{
			return theDeepSingulars_;
		}

		indexedEntityMap& ChangeCommonSingulars()
		{
			return theCommonSingulars_;
		}

	public:

		Standard_Integer NbRegulars() const
		{
			return (Standard_Integer)theRegulars_.size();
		}

		Standard_Integer NbDefects() const
		{
			return (Standard_Integer)theDefects_.size();
		}

		Standard_Integer NbDeepSingularities() const
		{
			return (Standard_Integer)theDeepSingulars_.size();
		}

		Standard_Integer NbCommonSingularities() const
		{
			return (Standard_Integer)theCommonSingulars_.size();
		}

		const indexedEntityMap& Regulars() const
		{
			return theRegulars_;
		}

		indexedEntityMap& Regulars()
		{
			return theRegulars_;
		}

		const indexedEntityMap& Defects() const
		{
			return theDefects_;
		}

		indexedEntityMap& Defects()
		{
			return theDefects_;
		}

		const indexedEntityMap& DeepSingulars() const
		{
			return theDeepSingulars_;
		}

		indexedEntityMap& DeepSingulars()
		{
			return theDeepSingulars_;
		}

		const indexedEntityMap& CommonSingulars() const
		{
			return theCommonSingulars_;
		}

		indexedEntityMap& CommonSingulars()
		{
			return theCommonSingulars_;
		}
	};
}

#endif // !_CadAnalys_Model_Base_Header
