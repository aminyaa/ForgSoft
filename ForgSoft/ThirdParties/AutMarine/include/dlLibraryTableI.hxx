#pragma once
#include <dictionary.hxx>
#include <fileNameList.hxx>
template<class TablePtr>
bool AutLib::dlLibraryTable::open
(
	const dictionary& dict,
	const word& libsEntry,
	const TablePtr& tablePtr
)
{
	if (dict.found(libsEntry))
	{
		fileNameList libNames(dict.lookup(libsEntry));

		bool allOpened = (libNames.size() > 0);

		for (label i = 0; i < (libNames).size(); i++)
		{
			const fileName& libName = libNames[i];

			label nEntries = 0;

			if (tablePtr)
			{
				nEntries = tablePtr->size();
			}

			bool opened = dlLibraryTable::open(libName);
			allOpened = opened && allOpened;

			if (opened && (!tablePtr || tablePtr->size() <= nEntries))
			{
				WarningIn
				(
					"dlLibraryTable::open"
					"(const dictionary& dict, const word& libsEntry, "
					"const TablePtr tablePtr)"
				) << "library " << libName
					<< " did not introduce any new entries"
					<< endl << endl;
			}
		}

		return allOpened;
	}
	else
	{
		return false;
	}
}