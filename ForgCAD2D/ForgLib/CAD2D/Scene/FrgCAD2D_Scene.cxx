#include <FrgCAD2D_Scene.hxx>
#include <FrgCAD2D_Scene_InteractorStyle.hxx>

#include <QToolBar>
#include <QToolButton>
#include <QHBoxLayout>
#include <QShortcut>
#include <QKeyEvent>

ForgCAD2DLib::FrgCAD2D_Scene::FrgCAD2D_Scene(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
	: ForgVisualLib::FrgVisual_Scene2D(parentMainWindow)
{

}

class QToolButtonContainer
	: public QWidget
{
public:

	QToolButtonContainer(QWidget* parent = nullptr) :QWidget(parent)
	{
		theLayout_ = new QHBoxLayout;
		this->setLayout(theLayout_);
		theLayout_->setContentsMargins(0, 0, 0, 0);
		theLayout_->setSpacing(1);
		this->setContentsMargins(0, 0, 0, 0);
	}

	void AddWidget(QWidget* widget)
	{
		theLayout_->addWidget(widget);
		if (widget)
		{
			widget->setContentsMargins(0, 0, 0, 0);
		}
	}

protected:

	QHBoxLayout* theLayout_ = nullptr;
};

void ForgCAD2DLib::FrgCAD2D_Scene::FormToolBar()
{
	ForgVisualLib::FrgVisual_Scene2D::FormToolBar();

	if (!theLeftToolBar_)
	{
		theLeftToolBar_ = new QToolBar("CAD 2D");
		theLeftToolBar_->setAllowedAreas(Qt::ToolBarArea::LeftToolBarArea);
		theLeftToolBar_->setFloatable(false);
		theLeftToolBar_->setMovable(false);
		theLeftToolBar_->setContextMenuPolicy(Qt::PreventContextMenu);

		/* Beginning of Row 1*/
		QToolButtonContainer* row1 = new QToolButtonContainer;
		auto* cancelOperations = new QToolButton();
		cancelOperations->setIcon(QIcon(":/ForgCAD2D/Resources/Icons/Scene/Cursor.png"));
		cancelOperations->setShortcut(QKeySequence(Qt::Key_Escape));
		cancelOperations->setToolTip("Cancel (Esc)");
		connect(cancelOperations, &QToolButton::clicked, [this]() {FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->CancelCommand(true); });

		auto* addPoint = new QToolButton();
		addPoint->setIcon(QIcon(":/ForgCAD2D/Resources/Icons/Scene/Circle.png"));
		addPoint->setShortcut(QKeySequence(Qt::Key_P));
		addPoint->setToolTip("Point (P)");
		connect(addPoint, &QToolButton::clicked, [this]() {FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->AddPoint(); });
		row1->AddWidget(cancelOperations);
		row1->AddWidget(addPoint);
		/* End of Row 1 */

		/* Beginning of Row 2*/
		QToolButtonContainer* row2 = new QToolButtonContainer;
		auto* addPolyline = new QToolButton();
		addPolyline->setIcon(QIcon(":/ForgCAD2D/Resources/Icons/Scene/Polyline.png"));
		addPolyline->setShortcut(QKeySequence(Qt::Key_L));
		addPolyline->setToolTip("Polyline (L)");
		connect(addPolyline, &QToolButton::clicked, [this]() {FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->AddPolyLine(); });
		row2->AddWidget(addPolyline);

		auto* addBSPLine = new QToolButton();
		addBSPLine->setIcon(QIcon(":/ForgCAD2D/Resources/Icons/Scene/Polyline.png"));
		addBSPLine->setShortcut(QKeySequence(Qt::Key_B));
		addBSPLine->setToolTip("BSPLine (B)");
		connect(addBSPLine, &QToolButton::clicked, [this]() {FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->AddBSPLine(); });
		row2->AddWidget(addBSPLine);
		/* End of Row 2 */

		/* Beginning of Row 3*/
		QToolButtonContainer* row3 = new QToolButtonContainer;
		auto* addRectangle = new QToolButton();
		addRectangle->setIcon(QIcon(":/ForgCAD2D/Resources/Icons/Scene/Polyline.png"));
		addRectangle->setShortcut(QKeySequence(Qt::Key_R));
		addRectangle->setToolTip("Rectangle (R)");
		connect(addRectangle, &QToolButton::clicked, [this]() {FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->AddRectangle(); });
		row3->AddWidget(addRectangle);

		auto* addCircle = new QToolButton();
		addCircle->setIcon(QIcon(":/ForgCAD2D/Resources/Icons/Scene/Polyline.png"));
		addCircle->setShortcut(QKeySequence(Qt::Key_C));
		addCircle->setToolTip("Circle (C)");
		connect(addCircle, &QToolButton::clicked, [this]() {FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->AddCircle(); });
		row3->AddWidget(addCircle);
		/* End of Row 3 */

		/* Beginning of Row 4*/
		QToolButtonContainer* row4 = new QToolButtonContainer;
		auto* addBSPLineThrougPoints = new QToolButton();
		addBSPLineThrougPoints->setIcon(QIcon(":/ForgCAD2D/Resources/Icons/Scene/Polyline.png"));
		addBSPLineThrougPoints->setShortcut(QKeySequence(Qt::Key_S));
		addBSPLineThrougPoints->setToolTip("BSPLine Through Points (S)");
		connect(addBSPLineThrougPoints, &QToolButton::clicked, [this]() {FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->AddBSPLineThroughPoints(); });
		row4->AddWidget(addBSPLineThrougPoints);

		/* End of Row 3 */

		theLeftToolBar_->addWidget(row1);
		theLeftToolBar_->addWidget(row2);
		theLeftToolBar_->addWidget(row3);
		theLeftToolBar_->addWidget(row4);

		this->addToolBar(Qt::LeftToolBarArea, theLeftToolBar_);

		theLeftToolBar_->setContentsMargins(0, 0, 0, 0);
	}
}

void ForgCAD2DLib::FrgCAD2D_Scene::InitInteractorStyle()
{
	theInteractorStyle_ = FrgCAD2D_Scene_InteractorStyle::New();

	auto castedInteractorStyle = FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_));
	castedInteractorStyle->SetParentScene(this);
	castedInteractorStyle->SetCurrentRenderer(theRenderer_);
	castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
	theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
}

void ForgCAD2DLib::FrgCAD2D_Scene::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Z)
	{
		if (event->modifiers() == Qt::KeyboardModifier::ControlModifier)
		{
			FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->UndoCommand();
			event->accept();
		}
	}
	if (event->key() == Qt::Key_Delete)
	{
		FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->DeleteSelectedActors();
		event->accept();
	}
	if (event->modifiers() == Qt::KeyboardModifier::ShiftModifier)
	{
		FrgCAD2D_Scene_InteractorStyle::SafeDownCast((FrgCAD2D_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_))->OnMouseMove();
	}

	event->ignore();
}

DECLARE_SAVE_IMP(ForgCAD2DLib::FrgCAD2D_Scene)
{

}

DECLARE_LOAD_IMP(ForgCAD2DLib::FrgCAD2D_Scene)
{

}

BOOST_CLASS_EXPORT_CXX(ForgCAD2DLib::FrgCAD2D_Scene)