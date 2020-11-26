//#pragma once
//#ifndef _FrgVisual_3DMeshActor_Header
//#define _FrgVisual_3DMeshActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_MeshActor.hxx>
//
//#include <FrgVisual_Serialization_Global.hxx>
//
//namespace ForgBaseLib
//{
//	class FrgBase_Pnt3d;
//}
//
//BeginForgVisualLib
//
//class FORGVISUAL_EXPORT FrgVisual_3DMeshActor
//	: public FrgVisual_MeshActor
//{
//
//	typedef FrgVisual_MeshActor SuperClass;
//
//public:
//
//	FrgVisual_3DMeshActor();
//
//	static FrgVisual_3DMeshActor* New();
//	vtkTypeMacro(FrgVisual_3DMeshActor, FrgVisual_MeshActor);
//
//	~FrgVisual_3DMeshActor();
//
//	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> pts, std::vector<std::shared_ptr<std::tuple<int, int, int>>> connectivity);
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> thePoints_;
//	std::vector<std::shared_ptr<std::tuple<int, int, int>>> theConnectivity_;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DMeshActor)
//
//#endif // !_FrgVisual_3DMeshActor_Header
