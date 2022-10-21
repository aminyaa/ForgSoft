#pragma once
#ifndef _FrgCAD_Scene_InteractorStyle_Header
#define _FrgCAD_Scene_InteractorStyle_Header

#include <FrgCAD_Global.hxx>
#include <FrgVisual_Scene_InterStyle2D.hxx>

class QLabel;

namespace ForgBaseLib
{
	template <int Dim>
	class FrgBase_Pnt;
}

namespace ForgVisualLib
{
	template <int Dim>
	class FrgVisual_PointActor;

	class FrgVisual_BaseActor_Entity;
}

BeginForgCADLib

class FrgCAD_DlgEntity;

class FORGCAD_EXPORT FrgCAD_Scene_InteractorStyle
	: public ForgVisualLib::FrgVisual_Scene_InterStyle2D
{

	Q_OBJECT

public:

	enum class OperationType
	{
		Default,
		AddingPoint,
		AddingPolyLine,
		AddingBSPLine,
		AddingBSPLineThroughPoints,
		AddingRectangle,
		AddingCircle
	};

	typedef ForgVisualLib::FrgVisual_Scene_InterStyle2D SuperClass;

public:
	static FrgCAD_Scene_InteractorStyle* New();
	vtkTypeMacro(FrgCAD_Scene_InteractorStyle, SuperClass);

	//@{
	/**
	 * Event bindings controlling the effects of pressing mouse buttons
	 * or moving the mouse.
	 */
	void OnMouseMove() override;
	void OnLeftButtonDown() override;
	void OnRightButtonDown() override;

	bool IsInOperation() const { return theIsInOperation_; }
	void SetInOperation(bool inOperation);

	OperationType GetOperationType() const { return theOperationType_; }
	void SetOperationType(OperationType operationType) { theOperationType_ = operationType; }

	void AddCommand(const QString& command);

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

Q_SIGNALS:

	void ActorAddedToCADSignal(ForgVisualLib::FrgVisual_BaseActor_Entity*);
	void ActorIsGoingToBeDeletedFromCADSignal(ForgVisualLib::FrgVisual_BaseActor_Entity*);

protected:

	FrgCAD_Scene_InteractorStyle();
	~FrgCAD_Scene_InteractorStyle() override;

	void FormInterStyle() override;

	FrgCAD_Scene_InteractorStyle(const FrgCAD_Scene_InteractorStyle&) = delete;
	void operator=(const FrgCAD_Scene_InteractorStyle&) = delete;

	void Update(double x, double y, bool render = false);
	void CustomOnMouseMove(int x, int y);

	void AddPointDialog();

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

	FrgCAD_DlgEntity* theDlg_ = nullptr;

	double theLastClickedPosition_[2];
	double theCurrentPosition_[2];

	std::vector<ForgBaseLib::FrgBase_Pnt<2>> thePts_;
};

EndForgCADLib

#endif // !_FrgCAD_Scene_InteractorStyle_Header
