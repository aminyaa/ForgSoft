#include "FrgBase_FieldFunctionsTreeWidget.hxx"

#include <FrgBase_Global_Icons.hxx>

ForgBaseLib::FrgBase_FieldFunctionsTreeWidget::FrgBase_FieldFunctionsTreeWidget
(
	QWidget* parent
)
	: QTreeWidget(parent)
{
	this->setWindowTitle("Mathematical Functions Tree");

	this->setHeaderLabels({ "Function", "Description", "Example" });

	SetupLayout();

	connect
	(
		this,
		&FrgBase_FieldFunctionsTreeWidget::itemDoubleClicked,
		this,
		&FrgBase_FieldFunctionsTreeWidget::ItemDoubleClickedSlot
	);
}

#define AddTItemToFunctionsTree(parentTItem, varName, title, description, example)		\
auto varName = new QTreeWidgetItem;														\
varName->setText(0, title);																\
varName->setText(1, description);														\
varName->setText(2, example);															\
parentTItem->addChild(varName);															\
varName->setToolTip(0, description);

void ForgBaseLib::FrgBase_FieldFunctionsTreeWidget::SetupLayout()
{
	auto generalFunctionsTItem =
		new QTreeWidgetItem;

	generalFunctionsTItem->setText
	(
		0,
		"General Functions"
	);

	generalFunctionsTItem->setIcon
	(
		0,
		QIcon(ICONTreeItemEye)
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		absGFunc,
		"abs",
		"Absolute value of x.", "abs(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		avgGFunc,
		"avg",
		"Average of all the inputs.",
		"avg(x,y,z,w,u,v) == (x + y + z + w + u + v) / 6"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		ceilGFunc,
		"ceil",
		"Smallest integer that is greater than or equal to x.",
		"ceil(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		clampGFunc,
		"clamp",
		"Clamp x in range between r0 and r1, where r0 < r1.",
		"clamp(r0,x,r1)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		equalGFunc,
		"equal",
		"Equality test between x and y using normalised epsilon.",
		"equal(x, y)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		erfGFunc,
		"erf",
		"Error function of x.",
		"erf(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		erfcGFunc,
		"erfc",
		"Complimentary error function of x.",
		"erfc(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		expGFunc,
		"exp",
		"e to the power of x.",
		"exp(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		expm1GFunc,
		"expm1",
		"e to the power of x minus 1, where x is very small.",
		"expm1(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		floorGFunc,
		"floor",
		"Largest integer that is less than or equal to x.",
		"floor(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		fracGFunc,
		"frac",
		"Fractional portion of x.",
		"frac(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		hypotGFunc,
		"hypot",
		"Hypotenuse of x and y.",
		"hypot(x,y) == sqrt(x*x + y*y)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		iclampGFunc,
		"iclamp",
		"Inverse-clamp x outside of the range r0 and r1. Where r0 < r1.If x is within the range it will snap to the closest bound.",
		"iclamp(r0,x,r1)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		inrangeGFunc,
		"inrange",
		"In-range returns 'true' when x is within the range r0 and r1. Where r0 < r1.",
		"inrange(r0,x,r1)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		logGFunc,
		"log",
		"Natural logarithm of x.",
		"log(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		log10GFunc,
		"log10",
		"Base 10 logarithm of x.",
		"log10(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		log1pGFunc,
		"log1p",
		"Natural logarithm of 1 + x, where x is very small.",
		"log1p(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		log2GFunc,
		"log2",
		"Base 2 logarithm of x.",
		"log2(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		lognGFunc,
		"logn",
		"Base N logarithm of x. where n is a positive integer.",
		"logn(x, 8)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		maxGFunc,
		"max",
		"Largest value of all the inputs.",
		"max(x,y,z,w,u,v)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		minGFunc,
		"min",
		"Smallest value of all the inputs.",
		"min(x,y,z,w,u,v)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		modGFunc,
		"mod",
		"returns the remainder of a division.",
		"mod(56, 10) == 6"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		mulGFunc,
		"mul",
		"Product of all the inputs.",
		"mul(x,y,z,w,u,v,t) == (x * y * z * w * u * v * t)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		ncdfGFunc,
		"ncdf",
		"Normal cumulative distribution function.",
		"ncdf(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		powGFunc,
		"pow",
		"x to the power of y.",
		"pow(x,y) == x ^ y"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		rootGFunc,
		"root",
		"Nth-Root of x. where n is a positive integer.",
		"root(x,3) == x^(1/3)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		roundGFunc,
		"round",
		"Round x to the nearest integer.",
		"round(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		roundnGFunc,
		"roundn",
		"Round x to n decimal places. where n > 0 and is an integer.",
		"roundn(1.2345678,4) == 1.2346"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		sgnGFunc,
		"sgn",
		"Sign of x, -1 where x < 0, +1 where x > 0, else zero.",
		"sgn(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		sqrtGFunc,
		"sqrt",
		"Square root of x, where x >= 0.",
		"sqrt(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		sumGFunc,
		"sum",
		"Sum of all the inputs.",
		"sum(x,y,z,w,u,v,t) == (x + y + z + w + u + v + t)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		swapGFunc,
		"swap",
		"Swap the values of the variables x and y and return the current value of y.",
		"swap(x,y) or x <=> y"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		truncGFunc,
		"trunc",
		"Integer portion of x.",
		"trunc(x)"
	);

	auto trigonometryFunctionsTItem = new QTreeWidgetItem;
	trigonometryFunctionsTItem->setText(0, "Trigonometry Functions");
	trigonometryFunctionsTItem->setIcon(0, QIcon(ICONTreeItemEye));
	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		acosTFunc,
		"acos",
		"Arc cosine of x expressed in radians. Interval [-1,+1]",
		"acos(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		acoshTFunc,
		"acosh",
		"Inverse hyperbolic cosine of x expressed in radians.",
		"acosh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		asinTFunc,
		"asin",
		"Arc sine of x expressed in radians. Interval [-1,+1]",
		"asin(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		asinhTFunc,
		"asinh",
		"Inverse hyperbolic sine of x expressed in radians.",
		"asinh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		atanTFunc,
		"atan",
		"Arc tangent of x expressed in radians. Interval [-1,+1]",
		"atan(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		atan2TFunc,
		"atan2",
		"Arc tangent of (x / y) expressed in radians. [-pi,+pi]",
		"atan2(x, y)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		atanhTFunc,
		"atanh",
		"Inverse hyperbolic tangent of x expressed in radians.",
		"atanh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		cosTFunc,
		"cos",
		"Cosine of x. x is in radians.",
		"cos(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		coshTFunc,
		"cosh",
		"Hyperbolic cosine of x. x is in radians.",
		"cosh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		cotTFunc,
		"cot",
		"Cotangent of x. x is in radians.",
		"cot(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		cscTFunc,
		"csc",
		"Cosecant of x. x is in radians.",
		"csc(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		secTFunc,
		"sec",
		"Secant of x. x is in radians.",
		"sec(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		sinTFunc,
		"sin",
		"Sine of x. x is in radians.",
		"sin(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		sincTFunc,
		"sinc",
		"Sine cardinal of x. x is in radians.",
		"sinc(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		sinhTFunc,
		"sinh",
		"Hyperbolic sine of x. x is in radians.",
		"sinh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		tanTFunc,
		"tan",
		"Tangent of x. x is in radians.",
		"tan(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		tanhTFunc,
		"tanh",
		"Hyperbolic tangent of x. x is in radians.",
		"tanh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		deg2radTFunc,
		"deg2rad",
		"Convert x from degrees to radians.",
		"deg2rad(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		deg2gradTFunc,
		"deg2grad",
		"Convert x from degrees to gradians.",
		"deg2grad(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		rad2degTFunc,
		"rad2deg",
		"Convert x from radians to degrees.",
		"rad2deg(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		grad2degTFunc,
		"grad2deg",
		"Convert x from gradians to degrees.",
		"grad2deg(x)"
	);

	this->addTopLevelItem(generalFunctionsTItem);
	this->addTopLevelItem(trigonometryFunctionsTItem);

	this->expandAll();
	for (int iColumn = 0; iColumn < this->columnCount(); iColumn++)
		this->resizeColumnToContents(iColumn);
	this->collapseAll();
}

void ForgBaseLib::FrgBase_FieldFunctionsTreeWidget::ItemDoubleClickedSlot
(
	QTreeWidgetItem* item,
	int column
)
{
	if (item && item->childCount() == 0)
		emit ItemDoubleClickedSignal(item->text(0));
}