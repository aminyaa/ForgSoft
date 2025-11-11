#include <FrgVisual_Tools.hxx>
#include <FrgVisual_BaseActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <Bnd_Box.hxx>
#include <BRepBndLib.hxx>
#include <Poly_Triangulation.hxx>
#include <vtkPolyData.h>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRep_Tool.hxx>
#include <Poly_Triangulation.hxx>
#include <vtkTriangle.h>

IMeshTools_Parameters ComputeMeshParameters(const TopoDS_Shape& shape)
{
    IMeshTools_Parameters params;

    // Compute bounding box diagonal
    Bnd_Box bbox;
    BRepBndLib::Add(shape, bbox);
    Standard_Real xmin, ymin, zmin, xmax, ymax, zmax;
    bbox.Get(xmin, ymin, zmin, xmax, ymax, zmax);
    Standard_Real diag = gp_Pnt(xmin, ymin, zmin).Distance(gp_Pnt(xmax, ymax, zmax));
    const double dia = std::sqrt(bbox.SquareExtent());
    const double tol = 0.001 * dia;
    auto isXThin = bbox.IsXThin(tol);
    auto isYThin = bbox.IsYThin(tol);
    auto isZThin = bbox.IsZThin(tol);

    const double dx = isXThin ? dia : std::abs(xmax - xmin);
    const double dy = isYThin ? dia : std::abs(ymax - ymin);
    const double dz = isZThin ? dia : std::abs(zmax - zmin);

    const auto d = std::min(std::min(dx, dy), dz);


    //if (diag < 1e-6)
    //    diag = 1.0; // Avoid division by zero for degenerate shapes

    // Compute key adaptive parameters
    //params.Deflection = std::max(diag * 0.001, 1e-4);          // 0.1% of model size
    params.Deflection = std::max(d * 0.001, 1e-4);          // 0.1% of model size
    params.DeflectionInterior = params.Deflection * 0.5;       // finer inside
    params.Angle = 0.25;                            // 30 degrees
    params.AngleInterior = params.Angle * 0.7;
    params.MinSize = std::max(d * 0.0001, 1e-5);            // avoid too small triangles

    // Derived logical parameters
    params.Relative = Standard_True;           // deflection relative to bbox size
    params.InParallel = Standard_True;         // parallel meshing if available
    params.CleanModel = Standard_True;         // remove degenerate edges
    params.AdjustMinSize = Standard_True;      // auto adjust per surface
    params.ControlSurfaceDeflection = Standard_False; // disable OCC deflection control
    params.ForceFaceDeflection = Standard_False;      // let OCC handle per-face mesh
    params.AllowQualityDecrease = Standard_False;     // keep mesh quality strict

    return params;
}

vtkSmartPointer<vtkPolyData> ForgVisualLib::FrgVisual_Tools::ShapeToVTK(const TopoDS_Shape& shape)
{
    // Step 1: Mesh the shape (triangulate)
    BRepMesh_IncrementalMesh mesher(shape, ComputeMeshParameters(shape));
    mesher.Perform();

    // Step 2: Prepare VTK containers
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkCellArray> triangles = vtkSmartPointer<vtkCellArray>::New();

    // Step 3: Iterate over faces and extract triangles
    TopExp_Explorer faceExplorer;
    for (faceExplorer.Init(shape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next())
    {
        TopoDS_Face face = TopoDS::Face(faceExplorer.Current());

        TopLoc_Location loc;
        Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(face, loc);
        if (triangulation.IsNull())
            continue;

        const Poly_Array1OfTriangle& tris = triangulation->Triangles();

        // Map OCC points to VTK point indices
        std::vector<vtkIdType> nodeIds(triangulation->NbNodes() + 1);
        for (int i = triangulation->NbNodes(); i >= 1; --i)
        {
            gp_Pnt p = triangulation->Node(i).Transformed(loc.Transformation());
            vtkIdType id = points->InsertNextPoint(p.X(), p.Y(), p.Z());
            nodeIds[i] = id;
        }

        // Add each triangle to VTK
        for (Standard_Integer i = tris.Lower(); i <= tris.Upper(); ++i)
        {
            Standard_Integer n1, n2, n3;
            tris(i).Get(n1, n2, n3);

            vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
            triangle->GetPointIds()->SetId(0, nodeIds[n1]);
            triangle->GetPointIds()->SetId(1, nodeIds[n2]);
            triangle->GetPointIds()->SetId(2, nodeIds[n3]);
            triangles->InsertNextCell(triangle);
        }
    }

    // Step 4: Create vtkPolyData
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->SetPoints(points);
    polyData->SetPolys(triangles);

    return polyData;
}

//std::vector
//<
//	std::tuple
//	<
//	std::vector<ForgBaseLib::FrgBase_Pnt<3>>,
//	std::vector<std::tuple<int, int, int>>
//	>
//>
//ForgVisualLib::FrgVisual_Tools::GetMeshOnSurfacesFromShape(const TopoDS_Shape& shape)
//{
//	double minSize = 100.0;
//	for (TopExp_Explorer iter(shape, TopAbs_FACE); iter.More(); iter.Next())
//	{
//		TopoDS_Face face = TopoDS::Face(iter.Current());
//		auto params = CalcDiscreteParamsUsingShape(face);
//		if (params.MinSize < minSize)
//			minSize = params.MinSize;
//	}
//
//	auto finalParams = CalcDiscreteParamsUsingShape(shape);
//	finalParams.MinSize = minSize;
//
//	Bnd_Box BoundingBox;
//	BRepBndLib::AddOptimal(shape, BoundingBox);
//	BRepMesh_FastDiscret Mesh(BoundingBox, finalParams);
//	Mesh.Perform(shape);
//
//	//tnbLib::Cad_FastDiscrete::Triangulation(shape, *params);
//	//std::cout << "Triangulated...\n";
//
//	std::vector<Handle(Poly_Triangulation)> polys;
//	for
//		(
//			TopExp_Explorer Explorer(shape, TopAbs_FACE);
//			Explorer.More();
//			Explorer.Next()
//			)
//	{
//		const auto& face = TopoDS::Face(Explorer.Current());
//		TopLoc_Location Loc;
//		auto tri = BRep_Tool::Triangulation(face, Loc);
//		if (tri)
//			polys.push_back(tri);
//	}
//
//	if (polys.size() == 0)
//	{
//		return std::vector<std::tuple<std::vector<ForgBaseLib::FrgBase_Pnt<3>>, std::vector<std::tuple<int, int, int>>>>();
//	}
//
//	std::vector<std::tuple<std::vector<ForgBaseLib::FrgBase_Pnt<3>>, std::vector<std::tuple<int, int, int>>>> result;
//
//	for (const auto& poly : polys)
//	{
//		std::vector <ForgBaseLib::FrgBase_Pnt<3>> pts;
//		const auto& nodes = poly->Nodes();
//		for (const auto& node : nodes)
//			pts.emplace_back(node.X(), node.Y(), node.Z());
//
//		std::vector<std::tuple<int, int, int>> indices;
//		const auto& tris = poly->Triangles();
//		for (const auto& tri : tris)
//		{
//			int i0, i1, i2;
//			tri.Get(i0, i1, i2);
//
//			indices.emplace_back(i0, i1, i2);
//		}
//
//		result.emplace_back(pts, indices);
//	}
//
//	return result;
//}
//
//BRepMesh_FastDiscret::Parameters ForgVisualLib::FrgVisual_Tools::CalcDiscreteParamsUsingShape(const TopoDS_Shape& shape)
//{
//	Bnd_Box b;
//	BRepBndLib::AddOptimal(shape, b, false, false);
//	double xmin, ymin, zmin, xmax, ymax, zmax;
//	b.Get(xmin, ymin, zmin, xmax, ymax, zmax);
//	const double dia = std::sqrt(b.SquareExtent());
//
//	const double tol = 0.001 * dia;
//	auto isXThin = b.IsXThin(tol);
//	auto isYThin = b.IsYThin(tol);
//	auto isZThin = b.IsZThin(tol);
//
//	const double dx = isXThin ? dia : std::abs(xmax - xmin);
//	const double dy = isYThin ? dia : std::abs(ymax - ymin);
//	const double dz = isZThin ? dia : std::abs(zmax - zmin);
//
//	const auto d = std::min(std::min(dx, dy), dz);
//
//	double myAngle = 1.0;
//	double myMinSize = 0.02 * d;
//	//double myDeflection = myMinSize * std::tan(tnbLib::Geo_Tools::DegToRadian(myAngle));
//	double myDeflection = 0.001;
//	const auto inParallel = true;
//	const auto ralative = true;
//	const auto adaptiveMin = true;
//	const auto internalVerticesMode = true;
//	const auto controlSurfaceDeflection = false;
//
//	BRepMesh_FastDiscret::Parameters Params;
//	Params.Angle = myAngle * std::acos(-1.0) / 180.0;
//	Params.Deflection = myDeflection;
//	Params.MinSize = myMinSize;
//	Params.InParallel = inParallel;
//	Params.Relative = ralative;
//	Params.AdaptiveMin = adaptiveMin;
//	Params.InternalVerticesMode = internalVerticesMode;
//	Params.ControlSurfaceDeflection = controlSurfaceDeflection;
//
//	return Params;
//}
//
//std::vector<TopoDS_Edge> ForgVisualLib::FrgVisual_Tools::RetrieveEdgesOfShape(const TopoDS_Shape& shape)
//{
//	std::vector<TopoDS_Edge> edges;
//	std::vector<TopoDS_Edge> finalEdges;
//	for (TopExp_Explorer iter(shape, TopAbs_EDGE); iter.More(); iter.Next())
//	{
//		auto edge = TopoDS::Edge(iter.Current());
//		if (edge.IsNull())
//			continue;
//
//		edges.push_back(edge);
//	}
//
//	for (int i = 0; i < edges.size(); i++)
//	{
//		bool canInsert = true;
//		for (int k = 0; k < finalEdges.size(); k++)
//		{
//			if (edges[i].IsSame(finalEdges[k]))
//			{
//				canInsert = false;
//				break;
//			}
//		}
//
//		if (canInsert)
//			finalEdges.push_back(edges[i]);
//	}
//
//	return finalEdges;
//}
//
//std::tuple
//<
//	std::vector<ForgBaseLib::FrgBase_Pnt<3>>,
//	std::vector<std::tuple<int, int, int>>
//>
//ForgVisualLib::FrgVisual_Tools::ConvertPolyLineToMesh(std::vector<ForgBaseLib::FrgBase_Pnt<3>> poly)
//{
//	std::vector<ForgBaseLib::FrgBase_Pnt<3>> pts;
//	std::vector<std::tuple<int, int, int>> indices;
//	for (int i = 0; i < poly.size() - 1; i++)
//	{
//		pts.push_back(poly[i]);
//		pts.push_back(poly[i + 1]);
//		pts.push_back(poly[i]);
//
//		indices.emplace_back(i + 1, i + 2, i + 1);
//	}
//	std::tuple<std::vector<ForgBaseLib::FrgBase_Pnt<3>>, std::vector<std::tuple<int, int, int>>> result(pts, indices);
//
//	return result;
//}
//
//std::vector
//<
//	std::tuple
//	<
//	std::vector<ForgBaseLib::FrgBase_Pnt<3>>,
//	std::vector<std::tuple<int, int, int>>
//	>
//>
//ForgVisualLib::FrgVisual_Tools::GetMeshOnEdgesFromShape(const TopoDS_Shape& shape)
//{
//	std::vector<std::tuple<std::vector<ForgBaseLib::FrgBase_Pnt<3>>, std::vector<std::tuple<int, int, int>>>> result;
//
//	auto edges = RetrieveEdgesOfShape(shape);
//
//	std::vector<Handle(Geom_Curve)> myCurves;
//	for (const auto& edge : edges)
//	{
//		Standard_Real firstParameter, lastParameter;
//		auto myCurve = BRep_Tool::Curve(edge, firstParameter, lastParameter);
//		if (myCurve.IsNull())
//			continue;
//
//		myCurves.push_back(myCurve);
//
//		const int nbDiv = 50;
//		const double du = (lastParameter - firstParameter) / (double)(nbDiv);
//		std::vector<ForgBaseLib::FrgBase_Pnt<3>> pts;
//		for (int i = 0; i <= nbDiv; i++)
//		{
//			const double u = i * du + firstParameter;
//			auto pt = myCurve->Value(u);
//			pts.emplace_back(pt.X(), pt.Y(), pt.Z());
//		}
//
//		result.push_back(ConvertPolyLineToMesh(pts));
//	}
//
//	//for (const auto& myCurve : myCurves)
//	//{
//	//	const int nbDiv = 50;
//	//	const double du = (lastParameter - firstParameter) / (double)(nbDiv);
//	//	for (int i = 0; i <= nbDiv; i++)
//	//	{
//	//		const double u = i * du + firstParameter;
//	//		myPolygon->Points().push_back(myCurve->Value(u));
//	//	}
//
//	//	//auto pts = FrgVisual_BaseActor<3>::DiscreteCurve(myCurve);
//	//	//result.push_back(ConvertPolyLineToMesh(pts));
//	//}
//
//	return result;
//}