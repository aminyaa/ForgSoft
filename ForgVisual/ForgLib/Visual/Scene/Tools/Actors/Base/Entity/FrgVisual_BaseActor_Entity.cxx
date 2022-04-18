#include <FrgVisual_BaseActor_Entity.hxx>
#include <FrgBase_SerialSpec_QColor.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>

#include <vtkTransform.h>

//vtkStandardNewMacro(ForgVisualLib::FrgVisual_BaseActor_Entity);

ForgVisualLib::FrgVisual_BaseActor_Entity::FrgVisual_BaseActor_Entity()
{
	theIsSelectable_ = true;
	theIsSelected_ = false;
	theIsIndependent_ = true;

	GetProperty()->SetAmbient(0.1);
	GetProperty()->SetDiffuse(0.95);
	GetProperty()->SetSpecular(1.0);
	GetProperty()->SetSpecularPower(128.0);

	theSelectingColor_.setRed(255);
	theSelectingColor_.setGreen(0);
	theSelectingColor_.setBlue(255);

	theProperty_ = GetProperty();
}

ForgVisualLib::FrgVisual_BaseActor_Entity::~FrgVisual_BaseActor_Entity()
{

}

void ForgVisualLib::FrgVisual_BaseActor_Entity::SetSelectable(bool condition)
{
	theIsSelectable_ = condition;

	this->SetPickable(condition);
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::SetColor(double red, double green, double blue)
{
	GetProperty()->SetColor(red, green, blue);
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::SetColor(double a[3])
{
	GetProperty()->SetColor(a);
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::SetColor(const QColor& color)
{
	SetColor(color.redF(), color.greenF(), color.blueF());
}

double* ForgVisualLib::FrgVisual_BaseActor_Entity::GetColor()
{
	return GetProperty()->GetColor();
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::GetColor(double rgb[3])
{
	GetProperty()->GetColor(rgb);
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::GetColor(double& r, double& g, double& b)
{
	GetProperty()->GetColor(r, g, b);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::SelectActor(const QColor& color)
{
	if (!theIsSelectable_)
		return false;

	if (theCopyProperty_)
	{
		theCopyProperty_->Delete();
		theCopyProperty_ = nullptr;
	}
	theCopyProperty_ = vtkProperty::New();
	theCopyProperty_->DeepCopy(GetProperty());

	GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());

	theIsSelected_ = true;

	emit SelectionHasChangedSignal();

	return true;
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::SelectActor()
{
	return SelectActor(theSelectingColor_);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::UnSelectActor()
{
	if (!theIsSelectable_)
		return false;

	if (theCopyProperty_)
	{
		GetProperty()->DeepCopy(theCopyProperty_);

		//SetProperty(theCopyProperty_);
		theProperty_ = GetProperty();

		theCopyProperty_->Delete();
		theCopyProperty_ = nullptr;
	}

	theIsSelected_ = false;

	emit SelectionHasChangedSignal();

	return true;
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::HideActor()
{
	if (!theIsSelectable_)
		return false;

	VisibilityOff();

	return true;
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::UnHideActor()
{
	if (!theIsSelectable_)
		return false;

	VisibilityOn();

	return true;
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::SetVisibility(vtkTypeBool _arg)
{
	vtkOpenGLActor::SetVisibility(_arg);
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::VisibilityOn()
{
	vtkOpenGLActor::VisibilityOn();
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::VisibilityOff()
{
	vtkOpenGLActor::VisibilityOff();
}

double ForgVisualLib::FrgVisual_BaseActor_Entity::GetOpacity()
{
	return GetProperty()->GetOpacity();
}

void ForgVisualLib::FrgVisual_BaseActor_Entity::SetOpacity(double opacity)
{
	GetProperty()->SetOpacity(opacity);
}

#define IsThatType(Type) \
auto types = GetActorTypes(); \
for (const auto& type : types) \
{ \
	if (type == FrgVisual_BaseActor_Entity::ActorType::Type) \
		return true; \
} \
return false;

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsPoint() const
{
	IsThatType(Point);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsCtrlPoint() const
{
	IsThatType(CtrlPoint);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsPickingPoint() const
{
	IsThatType(PickingPoint);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsLine() const
{
	IsThatType(Line);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsPolyLine() const
{
	IsThatType(PolyLine);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsBSPLine() const
{
	IsThatType(BSPLine);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsCurve() const
{
	IsThatType(Curve);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsSolid() const
{
	IsThatType(Solid);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsConic() const
{
	IsThatType(Conic);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsCircle() const
{
	IsThatType(Circle);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsRectangle() const
{
	IsThatType(Rectangle);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsBox() const
{
	IsThatType(Box);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsCylinder() const
{
	IsThatType(Cylinder);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsMesh() const
{
	IsThatType(Mesh);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsPolyhedral() const
{
	IsThatType(Polyhedral);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsGrid() const
{
	IsThatType(Grid);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsText() const
{
	IsThatType(Text);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsSurface() const
{
	IsThatType(Surface);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsPlane() const
{
	IsThatType(Plane);
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsTwoDimension() const
{
	if (GetActorDimension() == ActorDimension::TwoDim)
		return true;

	return false;
}

bool ForgVisualLib::FrgVisual_BaseActor_Entity::IsThreeDimension() const
{
	if (GetActorDimension() == ActorDimension::ThreeDim)
		return true;

	return false;
}

std::vector<QString> ForgVisualLib::FrgVisual_BaseActor_Entity::GetActorTypesAsString() const
{
	std::vector<QString> names;
	auto types = GetActorTypes();
	for (const auto& type : types)
		names.push_back(GetActorTypeAsString(type));

	return names;
}

QString ForgVisualLib::FrgVisual_BaseActor_Entity::GetActorTypeAsString(ActorType actorType) const
{
	if (actorType == ActorType::Point)
		return "Point";
	else if (actorType == ActorType::CtrlPoint)
		return "CtrlPoint";
	else if (actorType == ActorType::PickingPoint)
		return "PickingPoint";
	else if (actorType == ActorType::Line)
		return "Line";
	else if (actorType == ActorType::PolyLine)
		return "PolyLine";
	else if (actorType == ActorType::BSPLine)
		return "BSPLine";
	else if (actorType == ActorType::Curve)
		return "Curve";
	else if (actorType == ActorType::Solid)
		return "Solid";
	else if (actorType == ActorType::Circle)
		return "Circle";
	else if (actorType == ActorType::Conic)
		return "Conic";
	else if (actorType == ActorType::Rectangle)
		return "Rectangle";
	else if (actorType == ActorType::Box)
		return "Box";
	else if (actorType == ActorType::Mesh)
		return "Mesh";
	else if (actorType == ActorType::Grid)
		return "Grid";
	else if (actorType == ActorType::Text)
		return "Text";
	else if (actorType == ActorType::Surface)
		return "Surface";
	else if (actorType == ActorType::Plane)
		return "Plane";
	else if (actorType == ActorType::Other)
		return "Other";

	return "";
}

QString ForgVisualLib::FrgVisual_BaseActor_Entity::GetActorTypeAsString() const
{
	return GetActorTypeAsString(GetActorType());
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_BaseActor_Entity)
{
	ar& theIsSelectable_;

	auto myProperty = static_cast<vtkProperty*>(theProperty_);

	double redColor, greenColor, blueColor;
	myProperty->GetColor(redColor, greenColor, blueColor);

	double redAmbient, greenAmbient, blueAmbient;
	myProperty->GetAmbientColor(redAmbient, greenAmbient, blueAmbient);

	double redDiffuse, greenDiffuse, blueDiffuse;
	myProperty->GetDiffuseColor(redDiffuse, greenDiffuse, blueDiffuse);

	double redSpecular, greenSpecular, blueSpecular;
	myProperty->GetSpecularColor(redSpecular, greenSpecular, blueSpecular);

	double redEdgeColor, greenEdgeColor, blueEdgeColor;
	myProperty->GetEdgeColor(redEdgeColor, greenEdgeColor, blueEdgeColor);

	double redVertexColor, greenVertexColor, blueVertexColor;
	myProperty->GetVertexColor(redVertexColor, greenVertexColor, blueVertexColor);

	double Ambient = myProperty->GetAmbient();

	double Diffuse = myProperty->GetDiffuse();

	double Specular = myProperty->GetSpecular();

	double SpecularPower = myProperty->GetSpecularPower();

	double Opacity = myProperty->GetOpacity();

	int Interpolation = myProperty->GetInterpolation();

	int Representation = myProperty->GetRepresentation();

	bool EdgeVisibility = myProperty->GetEdgeVisibility();

	bool VertexVisibility = myProperty->GetVertexVisibility();

	bool BackfaceCulling = myProperty->GetBackfaceCulling();

	bool FrontfaceCulling = myProperty->GetFrontfaceCulling();

	float PointSize = myProperty->GetPointSize();

	float LineWidth = myProperty->GetLineWidth();

	int LineStipplePattern = myProperty->GetLineStipplePattern();

	int LineStippleRepeatFactor = myProperty->GetLineStippleRepeatFactor();

	bool Lighting = myProperty->GetLighting();

	bool RenderPointsAsSpheres = myProperty->GetRenderPointsAsSpheres();

	bool RenderLinesAsTubes = myProperty->GetRenderLinesAsTubes();

	bool Shading = myProperty->GetShading();

	ar& redColor;
	ar& greenColor;
	ar& blueColor;

	ar& redAmbient;
	ar& greenAmbient;
	ar& blueAmbient;

	ar& redDiffuse;
	ar& greenDiffuse;
	ar& blueDiffuse;

	ar& redSpecular;
	ar& greenSpecular;
	ar& blueSpecular;

	ar& redEdgeColor;
	ar& greenEdgeColor;
	ar& blueEdgeColor;

	ar& redVertexColor;
	ar& greenVertexColor;
	ar& blueVertexColor;

	ar& Ambient;
	ar& Diffuse;
	ar& Specular;
	ar& SpecularPower;
	ar& Opacity;
	ar& Interpolation;
	ar& Representation;
	ar& EdgeVisibility;
	ar& VertexVisibility;
	ar& BackfaceCulling;
	ar& FrontfaceCulling;
	ar& PointSize;
	ar& LineWidth;
	ar& LineStipplePattern;
	ar& LineStippleRepeatFactor;
	ar& Lighting;
	ar& RenderPointsAsSpheres;
	ar& RenderLinesAsTubes;
	ar& Shading;

	ar& theIsIndependent_;
	ar& theSelectingColor_;

	/*myProperty->RemoveAllTextures();
	auto iter = myProperty->Textures.begin();
	for (; iter != myProperty->Textures.end(); ++iter)
	{
		myProperty->Textures[iter->first] = iter->second;
	}*/
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_BaseActor_Entity)
{
	ar& theIsSelectable_;

	this->SetSelectable(theIsSelectable_);

	double redColor, greenColor, blueColor;
	double redAmbient, greenAmbient, blueAmbient;
	double redDiffuse, greenDiffuse, blueDiffuse;
	double redSpecular, greenSpecular, blueSpecular;
	double redEdgeColor, greenEdgeColor, blueEdgeColor;
	double redVertexColor, greenVertexColor, blueVertexColor;

	double Ambient, Diffuse, Specular, SpecularPower, Opacity;

	int Interpolation, Representation, LineStipplePattern, LineStippleRepeatFactor;

	bool EdgeVisibility, VertexVisibility, BackfaceCulling, FrontfaceCulling, Lighting, RenderPointsAsSpheres, RenderLinesAsTubes, Shading;

	float PointSize, LineWidth;

	ar& redColor;
	ar& greenColor;
	ar& blueColor;

	ar& redAmbient;
	ar& greenAmbient;
	ar& blueAmbient;

	ar& redDiffuse;
	ar& greenDiffuse;
	ar& blueDiffuse;

	ar& redSpecular;
	ar& greenSpecular;
	ar& blueSpecular;

	ar& redEdgeColor;
	ar& greenEdgeColor;
	ar& blueEdgeColor;

	ar& redVertexColor;
	ar& greenVertexColor;
	ar& blueVertexColor;

	ar& Ambient;
	ar& Diffuse;
	ar& Specular;
	ar& SpecularPower;
	ar& Opacity;
	ar& Interpolation;
	ar& Representation;
	ar& EdgeVisibility;
	ar& VertexVisibility;
	ar& BackfaceCulling;
	ar& FrontfaceCulling;
	ar& PointSize;
	ar& LineWidth;
	ar& LineStipplePattern;
	ar& LineStippleRepeatFactor;
	ar& Lighting;
	ar& RenderPointsAsSpheres;
	ar& RenderLinesAsTubes;
	ar& Shading;

	ar& theIsIndependent_;
	ar& theSelectingColor_;

	vtkProperty* myProperty = this->GetProperty();

	myProperty->SetColor(redColor, greenColor, blueColor);
	myProperty->SetAmbientColor(redAmbient, greenAmbient, blueAmbient);
	myProperty->SetDiffuseColor(redDiffuse, greenDiffuse, blueDiffuse);
	myProperty->SetSpecularColor(redSpecular, greenSpecular, blueSpecular);
	myProperty->SetEdgeColor(redEdgeColor, greenEdgeColor, blueEdgeColor);
	myProperty->SetVertexColor(redVertexColor, greenVertexColor, blueVertexColor);

	myProperty->SetAmbient(Ambient);
	myProperty->SetDiffuse(Diffuse);
	myProperty->SetSpecular(Specular);
	myProperty->SetSpecularPower(SpecularPower);
	myProperty->SetOpacity(Opacity);
	myProperty->SetInterpolation(Interpolation);
	myProperty->SetRepresentation(Representation);
	myProperty->SetEdgeVisibility(EdgeVisibility);
	myProperty->SetVertexVisibility(VertexVisibility);
	myProperty->SetBackfaceCulling(BackfaceCulling);
	myProperty->SetFrontfaceCulling(FrontfaceCulling);
	myProperty->SetPointSize(PointSize);
	myProperty->SetLineWidth(LineWidth);
	myProperty->SetLineStipplePattern(LineStipplePattern);
	myProperty->SetLineStippleRepeatFactor(LineStippleRepeatFactor);
	myProperty->SetLighting(Lighting);
	myProperty->SetRenderPointsAsSpheres(RenderPointsAsSpheres);
	myProperty->SetRenderLinesAsTubes(RenderLinesAsTubes);
	myProperty->SetShading(Shading);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BaseActor_Entity)