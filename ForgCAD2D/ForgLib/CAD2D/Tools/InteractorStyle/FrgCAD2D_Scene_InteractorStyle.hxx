#pragma once
#ifndef _FrgCAD2D_Scene_InteractorStyle_Header
#define _FrgCAD2D_Scene_InteractorStyle_Header

#include <FrgCAD2D_Global.hxx>
#include <FrgVisual_Scene_InterStyle2D.hxx>

class QHBoxLayout;
class QLabel;

namespace ForgBaseLib
{
	template <int Dim>
	class FrgBase_Pnt;
}

namespace ForgVisualLib
{
	class FrgVisual_BaseActor_Entity;

	template <int Dim>
	class FrgVisual_PointActor;
}

BeginForgCAD2DLib

class FORGCAD2D_EXPORT FrgCAD2D_Scene_InteractorStyle
	: public ForgVisualLib::FrgVisual_Scene_InterStyle2D
{

	Q_OBJECT;

	enum OperationType
	{
		Default,
		AddingPoint,
		AddingPolyLine,
		AddingBSPLine,
		AddingBSPLineThroughPoints,
		AddingRectangle,
		AddingCircle
	};

public:

	typedef ForgVisualLib::FrgVisual_Scene_InterStyle2D SuperClass;

public:
	static FrgCAD2D_Scene_InteractorStyle* New();
	vtkTypeMacro(FrgCAD2D_Scene_InteractorStyle, SuperClass);

	//@{
	/**
	 * Event bindings controlling the effects of pressing mouse buttons
	 * or moving the mouse.
	 */
	void OnMouseMove() override;
	void OnLeftButtonDown() override;
	void OnRightButtonDown() override;

	bool IsInOperation() const { return theIsInOperation_; }
	void SetInOperation(bool inOperation) { theIsInOperation_ = inOperation; }

	OperationType GetOperationType() const { return theOperationType_; }
	void SetOperationType(OperationType operationType) { theOperationType_ = operationType; }

	void AddPoint();
	void AddPolyLine();
	void AddBSPLine();
	void AddBSPLineThroughPoints();
	void AddRectangle();
	void AddCircle();

	void CompleteCommand();
	void CancelCommand(bool unselectAllActors = false);
	void UndoCommand();

	void DeleteSelectedActors();

protected:

	FrgCAD2D_Scene_InteractorStyle();
	~FrgCAD2D_Scene_InteractorStyle() override;

	void FormInterStyle() override;

	FrgCAD2D_Scene_InteractorStyle(const FrgCAD2D_Scene_InteractorStyle&) = delete;
	void operator=(const FrgCAD2D_Scene_InteractorStyle&) = delete;

	void Update(double x, double y);

protected:

	struct Label
	{
		//QHBoxLayout* theLayout_ = nullptr;
		QLabel* theTitle_ = nullptr;
		QLabel* theValue_ = nullptr;
	};

	Label* theXLabel_ = nullptr;
	Label* theYLabel_ = nullptr;

	bool theIsInOperation_;
	OperationType theOperationType_;

	ForgVisualLib::FrgVisual_BaseActor_Entity* theTempActor_ = nullptr;
	ForgVisualLib::FrgVisual_PointActor<2>* theTempPointActor_ = nullptr;

	double theLastClickedPosition_[2];
	double theCurrentPosition_[2];

	std::vector<ForgBaseLib::FrgBase_Pnt<2>> thePts_;
};

EndForgCAD2DLib

#endif // !_FrgCAD2D_Scene_InteractorStyle_Header
