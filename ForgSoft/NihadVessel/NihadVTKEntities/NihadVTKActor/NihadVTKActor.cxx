#include <NihadVTKActor.hxx>

#include <vtkObjectFactory.h>
#include <vtkMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTexture.h>
#include <vtkMatrix4x4.h>

//----------------------------------------------------------------------------
// Return nullptr if no override is supplied.
//vtkAbstractObjectFactoryNewMacro(ForgBaseLib::NihadVTKActor)

//vtkCxxSetObjectMacro(ForgBaseLib::NihadVTKActor, Texture, vtkTexture);
//vtkCxxSetObjectMacro(ForgBaseLib::NihadVTKActor, Mapper, vtkMapper);
//vtkCxxSetObjectMacro(ForgBaseLib::NihadVTKActor, BackfaceProperty, vtkProperty);
//vtkCxxSetObjectMacro(ForgBaseLib::NihadVTKActor, Property, vtkProperty);

ForgBaseLib::NihadVTKActor* ForgBaseLib::NihadVTKActor::New()
{
	VTK_STANDARD_NEW_BODY(ForgBaseLib::NihadVTKActor)
}

ForgBaseLib::NihadVTKActor::NihadVTKActor()
	//: vtkActor()
{
	std::cout << "NihadVTKActor Constructor is called\n";

	//vtkMath::UninitializeBounds(this->MapperBounds);
}

//ForgBaseLib::NihadVTKActor::~NihadVTKActor()
//{
//	if (this->Property != nullptr)
//	{
//		this->Property->UnRegister(this);
//		this->Property = nullptr;
//	}
//
//	if (this->BackfaceProperty != nullptr)
//	{
//		this->BackfaceProperty->UnRegister(this);
//		this->BackfaceProperty = nullptr;
//	}
//
//	if (this->Mapper)
//	{
//		this->Mapper->UnRegister(this);
//		this->Mapper = nullptr;
//	}
//	this->SetTexture(nullptr);
//}

//double* ForgBaseLib::NihadVTKActor::GetBounds()
//{
//	int i, n;
//	double bbox[24], * fptr;
//
//	vtkDebugMacro(<< "Getting Bounds");
//
//	// get the bounds of the Mapper if we have one
//	if (!this->Mapper)
//	{
//		return this->Bounds;
//	}
//
//	const double* bounds = this->Mapper->GetBounds();
//	// Check for the special case when the mapper's bounds are unknown
//	if (!bounds)
//	{
//		return nullptr;
//	}
//
//	// Check for the special case when the actor is empty.
//	if (!vtkMath::AreBoundsInitialized(bounds))
//	{
//		memcpy(this->MapperBounds, bounds, 6 * sizeof(double));
//		vtkMath::UninitializeBounds(this->Bounds);
//		this->BoundsMTime.Modified();
//		return this->Bounds;
//	}
//
//	// Check if we have cached values for these bounds - we cache the
//	// values returned by this->Mapper->GetBounds() and we store the time
//	// of caching. If the values returned this time are different, or
//	// the modified time of this class is newer than the cached time,
//	// then we need to rebuild.
//	if ((memcmp(this->MapperBounds, bounds, 6 * sizeof(double)) != 0) ||
//		(this->GetMTime() > this->BoundsMTime))
//	{
//		vtkDebugMacro(<< "Recomputing bounds...");
//
//		memcpy(this->MapperBounds, bounds, 6 * sizeof(double));
//
//		// fill out vertices of a bounding box
//		bbox[0] = bounds[1]; bbox[1] = bounds[3]; bbox[2] = bounds[5];
//		bbox[3] = bounds[1]; bbox[4] = bounds[2]; bbox[5] = bounds[5];
//		bbox[6] = bounds[0]; bbox[7] = bounds[2]; bbox[8] = bounds[5];
//		bbox[9] = bounds[0]; bbox[10] = bounds[3]; bbox[11] = bounds[5];
//		bbox[12] = bounds[1]; bbox[13] = bounds[3]; bbox[14] = bounds[4];
//		bbox[15] = bounds[1]; bbox[16] = bounds[2]; bbox[17] = bounds[4];
//		bbox[18] = bounds[0]; bbox[19] = bounds[2]; bbox[20] = bounds[4];
//		bbox[21] = bounds[0]; bbox[22] = bounds[3]; bbox[23] = bounds[4];
//
//		// make sure matrix (transform) is up-to-date
//		this->ComputeMatrix();
//
//		// and transform into actors coordinates
//		fptr = bbox;
//		for (n = 0; n < 8; n++)
//		{
//			double homogeneousPt[4] = { fptr[0], fptr[1], fptr[2], 1.0 };
//			this->Matrix->MultiplyPoint(homogeneousPt, homogeneousPt);
//			fptr[0] = homogeneousPt[0] / homogeneousPt[3];
//			fptr[1] = homogeneousPt[1] / homogeneousPt[3];
//			fptr[2] = homogeneousPt[2] / homogeneousPt[3];
//			fptr += 3;
//		}
//
//		// now calc the new bounds
//		this->Bounds[0] = this->Bounds[2] = this->Bounds[4] = VTK_DOUBLE_MAX;
//		this->Bounds[1] = this->Bounds[3] = this->Bounds[5] = -VTK_DOUBLE_MAX;
//		for (i = 0; i < 8; i++)
//		{
//			for (n = 0; n < 3; n++)
//			{
//				if (bbox[i * 3 + n] < this->Bounds[n * 2])
//				{
//					this->Bounds[n * 2] = bbox[i * 3 + n];
//				}
//				if (bbox[i * 3 + n] > this->Bounds[n * 2 + 1])
//				{
//					this->Bounds[n * 2 + 1] = bbox[i * 3 + n];
//				}
//			}
//		}
//		this->BoundsMTime.Modified();
//	}
//
//	return this->Bounds;
//}
