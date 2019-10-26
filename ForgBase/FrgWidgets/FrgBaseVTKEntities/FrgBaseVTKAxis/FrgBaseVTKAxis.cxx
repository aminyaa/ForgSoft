//#include <FrgBaseVTKAxis.hxx>
//
//// VTK Includes
//#include <vtkConfigure.h>
//#include <vtkMath.h>
//#include <vtkMapper.h>
//#include <vtkDataSet.h>
//#include <vtkRenderer.h>
//#include <vtkRenderWindow.h>
//#include <vtkObjectFactory.h>
//
//#include <vtkActor.h>
//#include <vtkProperty.h>
//#include <vtkLineSource.h>
//#include <vtkConeSource.h>
//#include <vtkPolyDataMapper.h>
//#include <vtkPolyDataMapper2D.h>
//#include <vtkVectorText.h>
//#include <vtkTextActor.h>
//#include <vtkTextMapper.h>
//#include <vtkTextProperty.h>
//
//vtkStandardNewMacro(ForgBaseLib::VTKViewer_UnScaledActor);
//
///*!Constructor*/
//ForgBaseLib::VTKViewer_UnScaledActor::VTKViewer_UnScaledActor()
//{
//	Bounds[0] = Bounds[2] = Bounds[4] = VTK_FLOAT_MAX;
//	Bounds[1] = Bounds[3] = Bounds[5] = -VTK_FLOAT_MAX;
//}
//
///*!
//  \return bounding box
//*/
//double*
//ForgBaseLib::VTKViewer_UnScaledActor
//::GetBounds()
//{
//	return Bounds;
//}
//
///*! Sets \a mySize= \a theSize variable.
// * \param  theSize - integer size
// */
//void ForgBaseLib::VTKViewer_UnScaledActor::SetSize(int theSize)
//{
//	mySize = theSize;
//}
//
///*!This causes the actor to be rendered.
// * Set new scale for actor.
// */
//void ForgBaseLib::VTKViewer_UnScaledActor::Render(vtkRenderer* theRenderer)
//{
//	if (theRenderer) {
//		double P[2][3] = { {-1.0, -1.0, 0.0},{+1.0, +1.0, 0.0} };
//		theRenderer->ViewToWorld(P[0][0], P[0][1], P[0][2]);
//		theRenderer->ViewToWorld(P[1][0], P[1][1], P[1][2]);
//		double aWorldDiag = sqrt((P[1][0] - P[0][0]) * (P[1][0] - P[0][0]) +
//			(P[1][1] - P[0][1]) * (P[1][1] - P[0][1]) +
//			(P[1][2] - P[0][2]) * (P[1][2] - P[0][2]));
//		int* aSize = theRenderer->GetRenderWindow()->GetSize();
//		double aWinDiag = sqrt(double(aSize[0] * aSize[0] + aSize[1] * aSize[1]));
//		vtkDataSet* aDataSet = GetMapper()->GetInput();
//		GetMapper()->Update();
//		double aLength = aDataSet->GetLength();
//		double aPrecision = 1.0E-3;
//		double aZeroTol = 1.0E-12;
//		double anOldScale = GetScale()[0];
//		double aScale = anOldScale;
//		double aMaxSize = (double)qMax(aSize[1], aSize[0]);
//		if (qAbs(aWinDiag) > aZeroTol&& qAbs(aLength) > aZeroTol&& qAbs(aMaxSize) > aZeroTol)
//			aScale = mySize * aWorldDiag / aWinDiag / aLength * sqrt(double(qMin(aSize[1], aSize[0])) / aMaxSize);
//		if (qAbs(aScale) > aZeroTol&& qAbs(aScale - anOldScale) / aScale > aPrecision) {
//			SetScale(aScale);
//		}
//	}
//	vtkFollower::Render(theRenderer);
//}
//
//vtkStandardNewMacro(ForgBaseLib::VTKViewer_LineActor);
//
//#ifdef IPAL21440
//vtkCxxSetObjectMacro(ForgBaseLib::VTKViewer_LineActor, LabelActor, vtkTextActor);
//#else
//vtkCxxSetObjectMacro(ForgBaseLib::VTKViewer_LineActor, LabelActor, ForgBaseLib::VTKViewer_UnScaledActor);
//#endif
//vtkCxxSetObjectMacro(ForgBaseLib::VTKViewer_LineActor, ArrowActor, vtkFollower);
//
///*!Adds Label and Arrow actors to \a theRenderer.*/
//void ForgBaseLib::VTKViewer_LineActor::Render(vtkRenderer* theRenderer)
//{
//#ifndef IPAL21440
//	if (LabelActor && LabelActor->GetVisibility()) {
//		LabelActor->Modified();
//		LabelActor->Render(theRenderer);
//	}
//#endif
//	if (ArrowActor && ArrowActor->GetVisibility()) {
//		ArrowActor->Modified();
//		ArrowActor->Render(theRenderer);
//	}
//	vtkFollower::Render(theRenderer);
//}
//
///*!
//  Constructor
//*/
//ForgBaseLib::VTKViewer_Axis::VTKViewer_Axis()
//{
//	/*! \li Initialize the Line pipe-line representation*/
//	myLineSource = vtkLineSource::New();
//	myLineSource->SetPoint1(0.0, 0.0, 0.0);
//
//	myMapper[0] = vtkPolyDataMapper::New();
//	myMapper[0]->SetInputConnection(myLineSource->GetOutputPort());
//
//	myLineActor = VTKViewer_LineActor::New();
//	myLineActor->SetMapper(myMapper[0]);
//	myLineActor->PickableOff();
//
//	/*! \li Initialize the Arrow pipe-line representation*/
//	myConeSource = vtkConeSource::New();
//	myConeSource->SetResolution(16);
//	myConeSource->SetAngle(10);
//	myConeSource->SetCenter(-0.5, 0.0, 0.0);
//
//	myMapper[1] = vtkPolyDataMapper::New();
//	myMapper[1]->SetInputConnection(myConeSource->GetOutputPort());
//
//	myArrowActor = vtkFollower::New();
//	myArrowActor->SetMapper(myMapper[1]);
//	static int aArrowActorSize = 16;
//	myArrowActor->SetScale(aArrowActorSize);
//	myArrowActor->PickableOff();
//
//	myLineActor->SetArrowActor(myArrowActor);
//
//	/*! \li Initialize the Label pipe-line representation */
//#ifdef IPAL21440
//	myTextMapper = vtkTextMapper::New();
//
//	myLabelActor = vtkTextActor::New();
//	myLabelActor->SetMapper(myTextMapper);
//	myLabelActor->SetTextScaleModeToNone();
//	myLabelActor->PickableOff();
//
//	vtkCoordinate* aCoord = vtkCoordinate::New();
//	myLabelActor->GetPositionCoordinate()->SetReferenceCoordinate(aCoord);
//	aCoord->Delete();
//#else
//	myVectorText = vtkVectorText::New();
//
//	myMapper[2] = vtkPolyDataMapper::New();
//	myMapper[2]->SetInputConnection(myVectorText->GetOutputPort());
//
////	myLabelActor = VTKViewer_UnScaledActor::New();
//	myLabelActor->SetMapper(myMapper[2]);
//	static int aLabelActorSize = 12;
//	myLabelActor->SetSize(aLabelActorSize);
//	myLabelActor->PickableOff();
//	//myLabelActor->DebugOn();
//#endif
//
//	myLineActor->SetLabelActor(myLabelActor);
//
//	/*! \li Initialise visibility param.*/
//	myVisibility = VTKViewer_Trihedron::eOn;
//}
//
///*!
//  Destructor
//*/
//ForgBaseLib::VTKViewer_Axis::~VTKViewer_Axis()
//{
//	/*! \li Destroy of the Label pipe-line representation */
//	myLabelActor->Delete();
//
//	myMapper[0]->RemoveAllInputs();
//	myMapper[0]->Delete();
//
//	/*! \li Destroy of the Arrow pipe-line representation */
//	myArrowActor->Delete();
//
//	myMapper[1]->RemoveAllInputs();
//	myMapper[1]->Delete();
//
//	myConeSource->Delete();
//
//	/*! \li Destroy of the Line pipe-line representation */
//	myLineActor->Delete();
//
//#ifdef IPAL21440
//	myTextMapper->RemoveAllInputs();
//	myTextMapper->Delete();
//#else
//	myVectorText->Delete();
//
//	myMapper[2]->RemoveAllInputs();
//	myMapper[2]->Delete();
//#endif
//
//	myLineSource->Delete();
//}
//
///*! Add to renderer
// * \param theRenderer - vtkRenderer pointer
// */
//void ForgBaseLib::VTKViewer_Axis::AddToRender(vtkRenderer* theRenderer) {
//	/*! \li Order of the calls are important*/
//	theRenderer->AddActor(myLineActor);
//	theRenderer->AddActor(myLabelActor);
//	theRenderer->AddActor(myArrowActor);
//}
//
///*! Remove actor of acis from \a theRenderer which are in myPresent.
// * \param theRenderer - vtkRenderer pointer
// */
//void ForgBaseLib::VTKViewer_Axis::RemoveFromRender(vtkRenderer* theRenderer) {
//	/*! \li Order of the calls are important*/
//	theRenderer->RemoveActor(myLineActor);
//	theRenderer->RemoveActor(myLabelActor);
//	theRenderer->RemoveActor(myArrowActor);
//}
//
///*! Sets visibility for all Axis to \a theVis*/
//void ForgBaseLib::VTKViewer_Axis::SetVisibility(VTKViewer_Trihedron::TVisibility theVis)
//{
//	switch (theVis) {
//	case VTKViewer_Trihedron::eOff:
//	case VTKViewer_Trihedron::eOn:
//		myLabelActor->SetVisibility(theVis);
//		myArrowActor->SetVisibility(theVis);
//		myLineActor->SetVisibility(theVis);
//		break;
//	case VTKViewer_Trihedron::eOnlyLineOn:
//		myLabelActor->VisibilityOff();
//		myArrowActor->VisibilityOff();
//		myLineActor->VisibilityOn();
//		break;
//	default:
//		return;
//	}
//	myVisibility = theVis;
//}
//
///*! Set camera for myLabelActor
// */
//void ForgBaseLib::VTKViewer_Axis::SetCamera(vtkCamera* theCamera) {
//#ifndef IPAL21440
//	myLabelActor->SetCamera(theCamera);
//#endif
//}
//
///*! Sets color for actors: myLineActor,myLabelActor,myArrowActor
// */
//void ForgBaseLib::VTKViewer_Axis::SetColor(double theRed, double theGreen, double theBlue)
//{
//	// Set color property for arrow and line actors
//	vtkProperty* aProperty = vtkProperty::New();
//	aProperty->SetColor(theRed, theGreen, theBlue);
//
//	myArrowActor->SetProperty(aProperty);
//	myLineActor->SetProperty(aProperty);
//#ifndef IPAL21440
//	myLabelActor->SetProperty(aProperty);
//#endif
//
//	aProperty->Delete();
//
//	// Set color property for label actor
//#ifdef IPAL21440
//	vtkTextProperty* aTextProperty = vtkTextProperty::New();
//	aTextProperty->SetColor(theRed, theGreen, theBlue);
//
//	myLabelActor->SetTextProperty(aTextProperty);
//
//	aTextProperty->Delete();
//#endif
//}
//
///*! Set size of VTKViewer_Axis
// */
//void ForgBaseLib::VTKViewer_Axis::SetSize(double theSize)
//{
//	double aPosition[3] = { myDir[0] * theSize, myDir[1] * theSize, myDir[2] * theSize };
//
//	double aCoef = 0.99;
//	double aLinePosition[3] = { aPosition[0] * aCoef, aPosition[1] * aCoef, aPosition[2] * aCoef };
//	myLineSource->SetPoint2(aLinePosition);
//
//	myArrowActor->SetPosition(0.0, 0.0, 0.0);
//	myArrowActor->AddPosition(aPosition);
//	myArrowActor->SetOrientation(myRot);
//	myArrowActor->SetScale(theSize / 10.);
//
//#ifdef IPAL21440
//	if (vtkCoordinate* aCoord = myLabelActor->GetPositionCoordinate()->GetReferenceCoordinate())
//		aCoord->SetValue(aPosition);
//#else
//	myLabelActor->SetPosition(0.0, 0.0, 0.0);
//	myLabelActor->AddPosition(aPosition);
//#endif
//}
//
///*! Check if actor belongs to the axis object
// * \param theActor - vtkActor pointer
// * \retval Return true if the actor belongs to the axis object
// */
//bool ForgBaseLib::VTKViewer_Axis::OwnActor(const vtkActor* theActor)
//{
//	return theActor == myLineActor ||
//		theActor == myArrowActor ||
//#ifdef IPAL21440
//		false;
//#else
//		theActor == myLabelActor;
//#endif
//}
//
//BeginFrgBaseLib
//
///*! \class VTKViewer_XAxis
// * \brief X Axis actor
// */
//class VTKViewer_XAxis : public VTKViewer_Axis
//{
//protected:
//	VTKViewer_XAxis();
//	VTKViewer_XAxis(const VTKViewer_XAxis&);
//public:
//	vtkTypeMacro(VTKViewer_XAxis, VTKViewer_Axis);
//	static VTKViewer_XAxis* New();
//};
//
//vtkStandardNewMacro(VTKViewer_XAxis);
//
//EndFrgBaseLib
//
///*!Initialize X Axis*/
//ForgBaseLib::VTKViewer_XAxis::VTKViewer_XAxis() {
//	myDir[0] = 1.0; myDir[1] = 0.0; myDir[2] = 0.0;
//	myRot[0] = 0.0; myRot[1] = 0.0; myRot[2] = 0.0;
//#ifdef IPAL21440
//	myTextMapper->SetInput("X");
//#else
//	myVectorText->SetText("X");
//#endif
//	SetColor(1.0, 0.0, 0.0);
//}
//
//BeginFrgBaseLib
//
///*! \class VTKViewer_YAxis
// * \brief Y Axis actor
// */
//class VTKViewer_YAxis : public VTKViewer_Axis {
//protected:
//	VTKViewer_YAxis();
//	VTKViewer_YAxis(const VTKViewer_YAxis&);
//public:
//	vtkTypeMacro(VTKViewer_YAxis, VTKViewer_Axis);
//	static VTKViewer_YAxis* New();
//};
//
//vtkStandardNewMacro(VTKViewer_YAxis);
//
//EndFrgBaseLib
//
///*!Initialize Y Axis*/
//ForgBaseLib::VTKViewer_YAxis::VTKViewer_YAxis()
//{
//	myDir[0] = 0.0; myDir[1] = 1.0; myDir[2] = 0.0;
//	myRot[0] = 0.0; myRot[1] = 0.0; myRot[2] = 90.;
//#ifdef IPAL21440
//	myTextMapper->SetInput("Y");
//#else
//	myVectorText->SetText("Y");
//#endif
//	SetColor(0.0, 1.0, 0.0);
//}
//
//BeginFrgBaseLib
//
///*! \class VTKViewer_ZAxis
// * \brief Z Axis actor
// */
//class VTKViewer_ZAxis : public VTKViewer_Axis
//{
//protected:
//	VTKViewer_ZAxis();
//	VTKViewer_ZAxis(const VTKViewer_ZAxis&);
//public:
//	vtkTypeMacro(VTKViewer_ZAxis, VTKViewer_Axis);
//	static VTKViewer_ZAxis* New();
//};
//
//vtkStandardNewMacro(VTKViewer_ZAxis);
//
//EndFrgBaseLib
//
///*!Initialize Z Axis*/
//ForgBaseLib::VTKViewer_ZAxis::VTKViewer_ZAxis()
//{
//	myDir[0] = 0.0; myDir[1] = 0.0; myDir[2] = 1.0;
//	myRot[0] = 0.0; myRot[1] = -90; myRot[2] = 0.0;
//#ifdef IPAL21440
//	myTextMapper->SetInput("Z");
//#else
//	myVectorText->SetText("Z");
//#endif
//	SetColor(0.0, 0.0, 1.0);
//}