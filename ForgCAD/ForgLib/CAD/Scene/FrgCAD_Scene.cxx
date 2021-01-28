#include <FrgCAD_Scene.hxx>
#include <FrgCAD_Scene_InteractorStyle.hxx>
#include <FrgCAD_CmdLineEdit.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QToolBar>
#include <QToolButton>
#include <QHBoxLayout>
#include <QShortcut>
#include <QKeyEvent>
#include <QStatusBar>

ForgCADLib::FrgCAD_Scene::FrgCAD_Scene(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
	: ForgVisualLib::FrgVisual_Scene2D(parentMainWindow)
{
	theCmdLineEdit_ = new FrgCAD_CmdLineEdit;
	this->statusBar()->addPermanentWidget(theCmdLineEdit_, 1);

	connect(theCmdLineEdit_, &FrgCAD_CmdLineEdit::ThrowErrorToConsole, theParentMainWindow_, &ForgBaseLib::FrgBase_MainWindow::PrintErrorToConsole);
	connect(theCmdLineEdit_, &FrgCAD_CmdLineEdit::CommandAcceptedSignal, [this](const QString& command)
		{
			theParentMainWindow_->PrintInfoToConsole(command);
			theCastedInterStyle_->AddCommand(theCmdLineEdit_->GetAcceptedCommand());
		}
	);
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

void ForgCADLib::FrgCAD_Scene::FormToolBar()
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
		cancelOperations->setIcon(QIcon(":/ForgCAD/Resources/Icons/Scene/Cursor.png"));
		cancelOperations->setShortcut(QKeySequence(Qt::Key_Escape));
		cancelOperations->setToolTip("Cancel (Esc)");
		connect(cancelOperations, &QToolButton::clicked, [this]() {theCastedInterStyle_->CancelCommand(true); theCmdLineEdit_->CancelCommand(); });

		auto* addPoint = new QToolButton();
		addPoint->setIcon(QIcon(":/ForgCAD/Resources/Icons/Scene/Point.png"));
		addPoint->setToolTip("Point");
		connect(addPoint, &QToolButton::clicked, [this]() {theCastedInterStyle_->AddPoint(); });
		row1->AddWidget(cancelOperations);
		row1->AddWidget(addPoint);
		/* End of Row 1 */

		/* Beginning of Row 2*/
		QToolButtonContainer* row2 = new QToolButtonContainer;
		auto* addPolyline = new QToolButton();
		addPolyline->setIcon(QIcon(":/ForgCAD/Resources/Icons/Scene/Polyline.png"));
		addPolyline->setToolTip("Polyline");
		connect(addPolyline, &QToolButton::clicked, [this]() {theCastedInterStyle_->AddPolyLine(); });
		row2->AddWidget(addPolyline);

		auto* addBSPLine = new QToolButton();
		addBSPLine->setIcon(QIcon(":/ForgCAD/Resources/Icons/Scene/BSPLine.png"));
		addBSPLine->setToolTip("BSPLine");
		connect(addBSPLine, &QToolButton::clicked, [this]() {theCastedInterStyle_->AddBSPLine(); });
		row2->AddWidget(addBSPLine);
		/* End of Row 2 */

		/* Beginning of Row 3*/
		QToolButtonContainer* row3 = new QToolButtonContainer;
		auto* addRectangle = new QToolButton();
		addRectangle->setIcon(QIcon(":/ForgCAD/Resources/Icons/Scene/Rectangle.png"));
		addRectangle->setToolTip("Rectangle");
		connect(addRectangle, &QToolButton::clicked, [this]() {theCastedInterStyle_->AddRectangle(); });
		row3->AddWidget(addRectangle);

		auto* addCircle = new QToolButton();
		addCircle->setIcon(QIcon(":/ForgCAD/Resources/Icons/Scene/Circle.png"));
		addCircle->setToolTip("Circle");
		connect(addCircle, &QToolButton::clicked, [this]() {theCastedInterStyle_->AddCircle(); });
		row3->AddWidget(addCircle);
		/* End of Row 3 */

		/* Beginning of Row 4*/
		QToolButtonContainer* row4 = new QToolButtonContainer;
		auto* addBSPLineThrougPoints = new QToolButton();
		addBSPLineThrougPoints->setIcon(QIcon(":/ForgCAD/Resources/Icons/Scene/Polyline.png"));
		addBSPLineThrougPoints->setToolTip("BSPLine Through Points");
		connect(addBSPLineThrougPoints, &QToolButton::clicked, [this]() {theCastedInterStyle_->AddBSPLineThroughPoints(); });
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

void ForgCADLib::FrgCAD_Scene::InitInteractorStyle()
{
	theInteractorStyle_ = FrgCAD_Scene_InteractorStyle::New();

	theCastedInterStyle_ = FrgCAD_Scene_InteractorStyle::SafeDownCast((FrgCAD_Scene_InteractorStyle::SuperClass*)(theInteractorStyle_));
	theCastedInterStyle_->SetParentScene(this);
	theCastedInterStyle_->SetCurrentRenderer(theRenderer_);
	theCastedInterStyle_->SetMouseWheelMotionFactor(0.5);
	theRenderWindowInteractor_->SetInteractorStyle(theCastedInterStyle_);
}

void ForgCADLib::FrgCAD_Scene::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Z)
	{
		if (event->modifiers() == Qt::KeyboardModifier::ControlModifier)
		{
			theCastedInterStyle_->UndoCommand();
			event->accept();
		}
	}
	if (event->key() == Qt::Key_Delete)
	{
		theCastedInterStyle_->DeleteSelectedActors();
		event->accept();
	}
	if (event->modifiers() == Qt::KeyboardModifier::ShiftModifier)
	{
		theCastedInterStyle_->OnMouseMove();
	}
	if (!theCastedInterStyle_->IsInOperation())
	{
		theCmdLineEdit_->setFocus();
		theCmdLineEdit_->keyPressEvent(event);
		this->setFocus();
	}

	event->ignore();
}

DECLARE_SAVE_IMP(ForgCADLib::FrgCAD_Scene)
{

}

DECLARE_LOAD_IMP(ForgCADLib::FrgCAD_Scene)
{

}

BOOST_CLASS_EXPORT_CXX(ForgCADLib::FrgCAD_Scene)