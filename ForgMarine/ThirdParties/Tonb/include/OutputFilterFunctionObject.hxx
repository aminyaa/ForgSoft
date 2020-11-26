/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.0
	\\  /    A nd           | Web:         http://www.foam-extend.org
	 \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
	This file is part of foam-extend.

	foam-extend is free software: you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	foam-extend is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
	tnbLib::OutputFilterFunctionObject

Description
	A functionObject wrapper around OutputFilter to allow them to be
	created via the functions list within controlDict.

Note
	Since the timeIndex is used directly from tnbLib::Time, it is unaffected
	by user-time conversions. For example, tnbLib::engineTime might cause @a
	writeInterval to be degrees crank angle, but the functionObject
	execution @a interval would still be in timestep.

SourceFiles
	OutputFilterFunctionObject.C

\*---------------------------------------------------------------------------*/
#pragma once
#ifndef _OutputFilterFunctionObject_Header
#define _OutputFilterFunctionObject_Header


#endif // !_OutputFilterFunctionObject_Header
