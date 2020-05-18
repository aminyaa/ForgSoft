#include <FrgBase_SerialSpec_QColor.hxx>

DECLARE_SAVE_IMP_SPEC(QColor)
{
	int red = m.red();
	int green = m.green();
	int blue = m.blue();
	int alpha = m.alpha();

	ar & red;
	ar & green;
	ar & blue;
	ar & alpha;
}

DECLARE_LOAD_IMP_SPEC(QColor)
{
	int red, green, blue, alpha;

	ar & red;
	ar & green;
	ar & blue;
	ar & alpha;

	m.setRed(red);
	m.setGreen(green);
	m.setBlue(blue);
	m.setAlpha(alpha);
}

BOOST_CLASS_EXPORT_CXX_SPEC(QColor)