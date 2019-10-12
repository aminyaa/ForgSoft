#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{
	namespace Io
	{

		template<class Type, int nbVAR>
		void WriteFiled
		(
			const std::vector<multiValued_Variable<Type, nbVAR>>& var,
			const std::vector<Pnt2d>& thePoints,
			OFstream & File
		)
		{
			if (var.size() != thePoints.size())
			{
				FatalErrorIn("void WriteFiled()")
					<< "Filed size and Points size not equal"
					<< abort(FatalError);
			}

			forThose(Index, 0, thePoints.size() - 1)
			{
				thePoints[Index].AddToPlt(File);
				File << "  ";
				var[Index].AddToPlt(File);
				File << endl;
			}
		}

		template<class Type, int nbVAR>
		void WriteFiled
		(
			const std::vector<multiValued_Variable<Type, nbVAR>>& var,
			const std::vector<Pnt3d>& thePoints,
			OFstream & File
		)
		{
			if (var.size() != thePoints.size())
			{
				FatalErrorIn("void WriteFiled()")
					<< "Filed size and Points size not equal"
					<< abort(FatalError);
			}

			forThose(Index, 0, thePoints.size() - 1)
			{
				thePoints[Index].AddToPlt(File);
				File << "  ";
				var[Index].AddToPlt(File);
				File << endl;
			}
		}

		template<class Type, int nbVAR>
		void WriteCellCenteredField
		(
			const std::vector<connectivity::triple>& Triangles,
			const std::vector<multiValued_Variable<Type, nbVAR>>& var,
			OFstream & File
		)
		{
			if (var.size() != Triangles.size())
			{
				FatalErrorIn("void WriteCellCenteredField()")
					<< "Filed size and Triangles size not equal"
					<< abort(FatalError);
			}

			for (const auto& x : var)
			{
				x.AddToPlt(File);
				File << endl;
			}

			for (const auto& x : Triangles)
			{
				File << x.Value(0) << "  " << x.Value(1) << "  " << x.Value(2) << endl;
			}
		}

		template<class Type, int nbVAR>
		void ExportField
		(
			const word& theVarNames,
			const std::vector<multiValued_Variable<Type, nbVAR>>& var,
			const std::vector<Pnt2d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream & File
		)
		{
			word Variables = "VARIABLES = X Y " + theVarNames;
			File << Variables << endl;

			WriteFeTriangleZone
			(
				(Standard_Integer)thePoints.size(),
				(Standard_Integer)Triangles.size(),
				File
			);

			WriteFiled
			(
				var,
				thePoints,
				File
			);

			for (const auto& x : Triangles)
			{
				File << x.Value(0) << "  " << x.Value(1) << "  " << x.Value(2) << endl;
			}
		}

		template<class Type, int nbVAR>
		void ExportField
		(
			const word& theVarNames,
			const std::vector<multiValued_Variable<Type, nbVAR>>& var,
			const std::vector<Pnt3d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream & File
		)
		{
			word Variables = "VARIABLES = X Y Z " + theVarNames;
			File << Variables << endl;

			WriteFeTriangleZone
			(
				(Standard_Integer)thePoints.size(),
				(Standard_Integer)Triangles.size(),
				File
			);

			WriteFiled
			(
				var,
				thePoints,
				File
			);

			for (const auto& x : Triangles)
			{
				File << x.Value(0) << "  " << x.Value(1) << "  " << x.Value(2) << endl;
			}
		}

		template<class Type, int nbVAR>
		void ExportCellCenteredField
		(
			const word & theVarNames,
			const std::vector<multiValued_Variable<Type, nbVAR>>& var,
			const std::vector<Pnt2d>& thePoints,
			const std::vector<connectivity::triple>& Triangles,
			OFstream & File
		)
		{
			word Variables = "VARIABLES = X Y " + theVarNames;
			File << Variables << endl;

			WriteCellCenteredFeTriangularZone
			(
				(Standard_Integer)thePoints.size(),
				(Standard_Integer)Triangles.size(),
				(Standard_Integer)nbVAR, File);

			WritePointsVariables(thePoints, File);

			WriteCellCenteredField(Triangles, var, File);
		}
	}
}