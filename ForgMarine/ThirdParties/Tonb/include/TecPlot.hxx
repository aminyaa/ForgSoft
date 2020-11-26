#pragma once
#ifndef _TecPlot_Header
#define _TecPlot_Header

#include <Standard_TypeDef.hxx>
#include <Entity_Connectivity.hxx>
#include <OFstream.hxx>

#include <vector>
#include <array>

namespace tnbLib
{

	class Pnt3d;
	class Pnt2d;

	namespace Io
	{

		void WriteVariables
		(
			const word& theVariables,
			OFstream& theFile
		);

		void WritePointsVariables
		(
			const std::vector<Pnt2d>& thePoints,
			OFstream& File
		);

		void WriteFeTriangleZone
		(
			const Standard_Integer NbNodes,
			const Standard_Integer NbTriangles,
			OFstream& theFile
		);

		void WriteFeTetrahedralZone
		(
			const Standard_Integer NbNodes,
			const Standard_Integer NbTets,
			OFstream& theFile
		);

		void WriteCellCenteredFeTriangularZone
		(
			const Standard_Integer NbNodes,
			const Standard_Integer NbTris,
			const Standard_Integer NbVar,
			OFstream& theFile
		);

		void WriteCellCenteredFeTriangular3DZone
		(
			const Standard_Integer NbNodes,
			const Standard_Integer NbTris,
			const Standard_Integer NbVar,
			OFstream& theFile
		);

		void WriteCellCenteredFeTetrahedralZone
		(
			const Standard_Integer NbNodes,
			const Standard_Integer NbTets,
			const Standard_Integer NbVar,
			OFstream& theFile
		);

		void WriteFeBrickZone
		(
			const Standard_Integer NbNodes,
			const Standard_Integer NbBricks,
			OFstream& theFile
		);

		void WriteIorderedZone
		(
			const Standard_Integer NbNodes,
			OFstream& theFile
		);

		template<class Type, size_t nbVAR>
		void WriteFiled
		(
			const std::vector<std::array<Type, nbVAR>>& var,
			const std::vector<Pnt2d>& thePoints,
			OFstream& File
		);

		template<class Type, size_t nbVAR>
		void WriteFiled
		(
			const std::vector<std::array<Type, nbVAR>>& var,
			const std::vector<Pnt3d>& thePoints,
			OFstream& File
		);

		template<class Type, size_t nbVAR>
		void WriteCellCenteredField
		(
			const std::vector<connectivity::triple>& Triangles,
			const std::vector<std::array<Type, nbVAR>>& var,
			OFstream& File
		);

		void ExportMesh
		(
			const std::vector<Pnt2d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream& File
		);

		void ExportMesh
		(
			const std::vector<Pnt2d>& thePoints,
			const std::vector<connectivity::dual>& Triangles,
			OFstream& File
		);

		void ExportMesh
		(
			const std::vector<Pnt3d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream& File
		);

		void ExportMesh
		(
			const std::vector<Pnt3d>& thePoints,
			const std::vector<connectivity::dual>& Triangles,
			OFstream& File
		);

		void ExportCurve
		(
			const std::vector<Pnt3d>& Points,
			OFstream& File
		);

		void ExportCurve
		(
			const std::vector<Pnt2d>& Points,
			OFstream& File
		);

		void ExportPoints
		(
			const std::vector<Pnt3d>& Points,
			OFstream& File
		);

		void ExportPoints
		(
			const std::vector<Pnt2d>& Points,
			OFstream& File
		);

		template<class Type, size_t nbVAR>
		void ExportField
		(
			const word& theVarNames,
			const std::vector<std::array<Type, nbVAR>>& var,
			const std::vector<Pnt2d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream& File
		);

		template<class Type, size_t nbVAR>
		void ExportField
		(
			const word& theVarNames,
			const std::vector<std::array<Type, nbVAR>>& var,
			const std::vector<Pnt3d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream& File
		);

		template<class Type, size_t nbVAR>
		void ExportCellCenteredField
		(
			const word& theVarNames,
			const std::vector<std::array<Type, nbVAR>>& var,
			const std::vector<Pnt2d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream& File
		);
	}
}

#include <TecPlotI.hxx>

#endif // !_TecPlot_Header
