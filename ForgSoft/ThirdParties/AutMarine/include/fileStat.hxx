#pragma once
#ifndef _fileStat_Header
#define _fileStat_Header

#include <label.hxx>

#include <sys/stat.h>

namespace AutLib
{

	class fileName;

	class fileStat
	{

		// Private data

		struct stat status_;

		bool isValid_;

	public:

		// Constructors

		//- Empty constructor
		fileStat();

		//- Construct from components
		fileStat(const fileName& fName, const unsigned int maxTime = 0);

		//- Construct from Istream
		fileStat(Istream&);


		// Member Functions

		// Access

		//- Raw status
		const struct stat& status() const
		{
			return status_;
		}

		//- Did constructor fail
		bool isValid() const
		{
			return isValid_;
		}


		// Check

		//- compare two fileStats for same device
		bool sameDevice(const fileStat& stat2) const;

		//- compare two fileStats for same Inode
		bool sameINode(const fileStat& stat2) const;

		//- compare state against inode
		bool sameINode(const label iNode) const;


		// IOstream Operators

		friend Istream& operator>>(Istream&, fileStat&);
		friend Ostream& operator<<(Ostream&, const fileStat&);
	};
}

#endif // !_fileStat_Header
