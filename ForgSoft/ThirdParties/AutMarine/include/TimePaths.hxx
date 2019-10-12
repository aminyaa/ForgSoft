#pragma once
#ifndef _TimePaths_Header
#define _TimePaths_Header

#include <fileName.hxx>

namespace AutLib
{

	class TimePaths
	{
		// Private data

		bool processorCase_;
		fileName rootPath_;
		fileName case_;
		word system_;
		word constant_;


	public:

		// Constructors

		//- Construct given database name, rootPath and casePath
		TimePaths
		(
			const fileName& rootPath,
			const fileName& caseName,
			const word& systemName,
			const word& constantName
		);


		// Member functions

		//- Return true if this is a processor case
		bool processorCase() const
		{
			return processorCase_;
		}

		//- Return root path
		const fileName& rootPath() const
		{
			return rootPath_;
		}

		//- Return case name
		const fileName& caseName() const
		{
			return case_;
		}

		//- Return system name
		const word& system() const
		{
			return system_;
		}

		//- Return system name for the case
		//  which for parallel runs returns ../system()
		fileName caseSystem() const;

		//- Return constant name
		const word& constant() const
		{
			return constant_;
		}

		//- Return constant name for the case
		//  which for parallel runs returns ../constant()
		fileName caseConstant() const;

		//- Return path
		fileName path() const
		{
			return rootPath() / caseName();
		}

		//- Return system path
		fileName systemPath() const
		{
			return path() / system();
		}

		//- Return constant path
		fileName constantPath() const
		{
			return path() / constant();
		}
	};
}

#endif // !_TimePaths_Header
