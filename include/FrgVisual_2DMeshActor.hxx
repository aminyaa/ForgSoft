//#pragma once
//#ifndef _FrgVisual_2DMeshActor_Header
//#define _FrgVisual_2DMeshActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_MeshActor.hxx>
//
//#include <FrgVisual_Serialization_Global.hxx>
//
//namespace ForgBaseLib
//{
//	class FrgBase_Pnt2d;
//}
//
//BeginForgVisualLib
//
//class FORGVISUAL_EXPORT FrgVisual_2DMeshActor
//	: public FrgVisual_MeshActor
//{
//
//	typedef FrgVisual_MeshActor SuperClass;
//
//public:
//
//	FrgVisual_2DMeshActor();
//
//	static FrgVisual_2DMeshActor* New();
//	vtkTypeMacro(FrgVisual_2DMeshActor, FrgVisual_MeshActor);
//
//	~FrgVisual_2DMeshActor();
//
//	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> pts, std::vector<std::shared_ptr<std::tuple<int, int, int>>> connectivity);
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> thePoints_;
//	std::vector<std::shared_ptr<std::tuple<int, int, int>>> theConnectivity_;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_2DMeshActor)
//
//#endif // !_FrgVisual_2DMeshActor_Header
