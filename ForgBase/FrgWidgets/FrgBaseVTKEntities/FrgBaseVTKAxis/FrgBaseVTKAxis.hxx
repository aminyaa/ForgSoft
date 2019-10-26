//#pragma once
//#ifndef _FrgBaseVTKAxis_Header
//#define _FrgBaseVTKAxis_Header
//
//#include <FrgBaseGlobals.hxx>
//
//#include <vtkObject.h>
//#include <vtkFollower.h>
//#include <vtkVersion.h>
//
//class vtkRenderer;
//class vtkActorCollection;
//class vtkCamera;
//class vtkProperty;
//class vtkPolyDataMapper;
//class vtkLineSource;
//class vtkConeSource;
//class vtkVectorText;
//class vtkTextActor;
//class vtkTextMapper;
//
//BeginFrgBaseLib
//
///*! \class vtkFollower
// * See <a href="http://www.vtk.org/">vtk documentation</a>
// */
// /*!a subclass of actor that always faces the camera
//  *@see vtkFollower
//  */
//	class VTKViewer_UnScaledActor : public vtkFollower
//{
//	VTKViewer_UnScaledActor(const VTKViewer_UnScaledActor&);
//
//public:
//
//	vtkTypeMacro(VTKViewer_UnScaledActor, vtkFollower);
//
//	/*!Create new instance of VTKViewer_UnScaledActor.*/
//	static VTKViewer_UnScaledActor* New();
//
//	virtual double* GetBounds();
//	virtual void SetSize(int theSize);
//	virtual void Render(vtkRenderer* theRenderer);
//
//protected:
//	VTKViewer_UnScaledActor();
//	/*!Destructor. Do nothing.*/
//	~VTKViewer_UnScaledActor() {}
//
//	int mySize;
//};
//
///*!a subclass of actor that always faces the camera
// *@see vtkFollower
// */
//class VTKViewer_LineActor : public vtkFollower
//{
//	VTKViewer_LineActor(const VTKViewer_LineActor&);
//
//public:
//	/*!vtk type macros.*/
//	vtkTypeMacro(VTKViewer_LineActor, vtkFollower);
//
//	/*!Create new instance of VTKViewer_LineActor.*/
//	static VTKViewer_LineActor* New();
//
//#ifdef IPAL21440
//	/*! Sets Label actor.
//	 * \param theLabelActor - vtkTextActor
//	 */
//	void SetLabelActor(vtkTextActor* theLabelActor);
//#else
//	/*! Sets Label actor.
//	 * \param theLabelActor - VTKViewer_UnScaledActor
//	 */
//	void SetLabelActor(VTKViewer_UnScaledActor* theLabelActor);
//#endif
//
//	/*! Sets Arrow actor.
//	 * \param theLabelActor - VTKViewer_UnScaledActor
//	 */
//	void SetArrowActor(vtkFollower* theArrowActor);
//
//	virtual void Render(vtkRenderer* theRenderer);
//
//protected:
//
//	/*! Constructor which sets \a LabelActor and \a ArrowActor to NULL*/
//	VTKViewer_LineActor() {
//		LabelActor = NULL;
//		ArrowActor = NULL;
//	}
//
//	/*!Destructor which call SetLabelActor(NULL) and SetArrowActor(NULL)*/
//	~VTKViewer_LineActor() {
//		SetLabelActor(NULL);
//		SetArrowActor(NULL);
//	}
//
//	/*!Label actor pointer*/
//#ifdef IPAL21440
//	vtkTextActor* LabelActor;
//#else
//	VTKViewer_UnScaledActor* LabelActor;
//#endif
//
//	/*!Arrow actor pointer*/
//	vtkFollower* ArrowActor;
//};
//
///*!This class provide support trihedron object in vtk viewer.*/
//class VTKViewer_Trihedron : public vtkObject
//{
//protected:
//	/*!Initialize fields by default values.*/
//	VTKViewer_Trihedron();
//
//	/*!Const copy constructor.*/
//	VTKViewer_Trihedron(const VTKViewer_Trihedron&);
//
//	/*!Destructor. Remove all fileds.*/
//	virtual ~VTKViewer_Trihedron();
//
//public:
//	/*!vtk type macros.*/
//	vtkTypeMacro(VTKViewer_Trihedron, vtkObject);
//
//	/*!Create new instance of VTKViewer_Trihedron.*/
//	static VTKViewer_Trihedron* New();
//
//	/*!Sets size of trihedron.
//	 * \param theSize - double value
//	 */
//	virtual void        SetSize(double theSize);
//
//	/*! Get size of trihedron.
//	 * \retval mySize - double value
//	 */
//	virtual double  GetSize() { return mySize; }
//
//	enum TVisibility { eOff, eOn, eOnlyLineOn };
//
//	/*! Sets visibility for all Axis to \a theVis*/
//	virtual void        SetVisibility(TVisibility theVis);
//
//	/*! OFF visibility for all Axis.*/
//	virtual void        VisibilityOff() { SetVisibility(eOff); }
//
//	/*! ON visibility for all Axis.*/
//	virtual void        VisibilityOn() { SetVisibility(eOn); }
//
//	/*! Gets visibility of myAxis[0] actor.*/
//	virtual TVisibility GetVisibility();
//
//	/*! Add to render all Axis
//	 * \param theRenderer - vtkRenderer pointer
//	 */
//	virtual void        AddToRender(vtkRenderer* theRenderer);
//
//	/*! Remove all actors from \a theRenderer which are in myPresent.
//	 * \param theRenderer - vtkRenderer pointer
//	 */
//	virtual void        RemoveFromRender(vtkRenderer* theRenderer);
//
//	/*! Return count of visible actors.
//	 * \param theRenderer - vtkRenderer pointer
//	 */
//	virtual int         GetVisibleActorCount(vtkRenderer* theRenderer);
//
//	/*! Check if actor belongs to the trihedron object
//	 * \param theActor - vtkActor pointer
//	 * \retval Return true if the actor belongs to the trihedron object
//	 */
//	virtual bool        OwnActor(const vtkActor* theActor);
//
//protected:
//	/*! Actor collection*/
//	vtkActorCollection* myPresent;
//
//	/*! \li myAxis[0] - X Axis actor
//	 *  \li myAxis[1] - Y Axis actor
//	 *  \li myAxis[2] - Z Axis actor
//	 */
//	VTKViewer_Axis* myAxis[3];
//
//	/*! Common size for trihedron, for each axis.*/
//	double mySize;
//};
//
//class VTKViewer_Axis : public vtkObject
//{
//protected:
//	VTKViewer_Axis();
//	VTKViewer_Axis(const VTKViewer_Axis&);
//	virtual ~VTKViewer_Axis();
//
//public:
//	/*!vtk type macros.*/
//	vtkTypeMacro(VTKViewer_Axis, vtkObject);
//
//	/*! Add to \a theRenderer actors: myLineActor,myLabelActor,myArrowActor
//	 */
//	virtual void AddToRender(vtkRenderer* theRenderer);
//	virtual void RemoveFromRender(vtkRenderer* theRenderer);
//
//	/*! Sets visibility for actors: myLineActor,myLabelActor,myArrowActor
//	 */
//	virtual void SetVisibility(VTKViewer_Trihedron::TVisibility theVis);
//
//	/*! Return visibility of VTKViewer_Axis
//	 * \retval myVisibility
//	 */
//	virtual VTKViewer_Trihedron::TVisibility GetVisibility() { return myVisibility; }
//
//	/*! Set camera for myLabelActor
//	 */
//	virtual void SetCamera(vtkCamera* theCamera);
//
//	/*! Sets color for actors: myLineActor,myLabelActor,myArrowActor
//	 * \param theRed - red component of the color
//	 * \param theGreen - green component of the color
//	 * \param theBlue - blue component of the color
//	 */
//	virtual void SetColor(double theRed, double theGreen, double theBlue);
//
//	/*! Set size of VTKViewer_Axis
//	 */
//	virtual void SetSize(double theSize);
//
//	/*! Get label actor.
//	 * \retval Return myLabelActor.
//	 */
//	virtual vtkTextActor* GetLabel() { return myLabelActor; }
//
//	/*! Get arrow actor.
//	 * \retval Return myArrowActor
//	 */
//	virtual vtkFollower* GetArrow() { return myArrowActor; }
//
//	/*! Check if actor belongs to the axis object
//	 * \param theActor - vtkActor pointer
//	 * \retval Return true if the actor belongs to the axis object
//	 */
//	virtual bool OwnActor(const vtkActor* theActor);
//
//protected:
//	/*! Visibility flag.
//	 */
//	VTKViewer_Trihedron::TVisibility myVisibility;
//
//	/*! \var myDir[3]
//	 * Direction vector
//	 */
//	 /*! \var myRot[3]
//	  * Orientation vector
//	  */
//	double myDir[3], myRot[3];
//
//	/*! VTKViewer_LineActor actor pointer
//	 */
//	VTKViewer_LineActor* myLineActor;
//
//	/*! vtkFollower actor pointer
//	 */
//	vtkFollower* myArrowActor;
//
//	/*! VTKViewer_UnScaledActor actor pointer
//	 */
//	vtkTextActor* myLabelActor;
//
//	/*! \li myMapper[0] - for the Line pipe-line representation
//	 *  \li myMapper[1] - for the Arrow pipe-line representation
//	 *  \li myMapper[2] - for the Label pipe-line representation
//	 */
//	vtkPolyDataMapper* myMapper[3];
//
//	/*! vtkLineSource pointer (Line)
//	 */
//	vtkLineSource* myLineSource;
//
//	/*! vtkConeSource pointer (Arrow)
//	 */
//	vtkConeSource* myConeSource;
//
//	/*! vtkTextMapper pointer (Label)
//	 */
//	vtkTextMapper* myTextMapper;
//};
//
//EndFrgBaseLib
//
//#endif // !_FrgBaseVTKAxis_Header
