#include "CVector2D.h"

/*
*/
CVector2D::CVector2D() :
	X(0.0f),
	Y(0.0f)
{
}

/*
*/
CVector2D::CVector2D(float _x, float _y)
	: X(_x), Y(_y)
{
}

/*
*/
CVector2D::CVector2D(const CVector2D& other)
{
	X = other.X;
	Y = other.Y;
}

/*
*/
CVector2D::~CVector2D()
{
}

/*
*/
CVector2D& CVector2D::operator=(const CVector2D& other)
{
	X = other.X;
	Y = other.Y;

	return *this;
}

/*
*/
CVector2D& CVector2D::operator+=(const CVector2D& other)
{
	X += other.X;
	Y += other.Y;

	return *this;
}

/*
*/
CVector2D& CVector2D::operator-=(const CVector2D& other)
{
	X -= other.X;
	Y -= other.Y;

	return *this;
}

/*
*/
//CVector2D CVector2D::cross(const CVector2D& other)
//{
//	CVector2D res;
//	res.setValues(
//		this->Y * other.Z - this->Z * other.Y,
//		this->Z * other.X - this->X * other.Z,
//		this->X * other.Y - this->Y * other.X
//	);
//	return res;
//}

/*
*/
float CVector2D::dot(const CVector2D& other)
{
	return ((this->X * other.X) + (this->Y * other.Y));
}

/*
*/
CVector2D CVector2D::operator+(const CVector2D& other)
{
	CVector2D res;
	res.setValues(
		this->X + other.X,
		this->Y + other.Y
	);
	return res;
}

/*
*/
CVector2D CVector2D::operator-(const CVector2D& other)
{
	CVector2D res;
	res.setValues(
		this->X - other.X,
		this->Y - other.Y
	);
	return res;
}

/*
*/
CVector2D CVector2D::operator*(float delta)
{
	CVector2D res;
	res.setValues(
		this->X * delta,
		this->Y * delta
	);
	return res;
}

/*
*/
CVector2D& CVector2D::operator*=(float delta)
{
	X *= delta;
	Y *= delta;

	return *this;
}

/*
*/
void CVector2D::normalize()
{
	float mag = magnitude();
	X /= mag;
	Y /= mag;
}

// https://en.wikipedia.org/wiki/Fast_inverse_square_root
// https://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi
/*
*/
float CVector2D::quickReverseSqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;                       // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);             // what the fuck? 
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

/*
*/
float CVector2D::quickReverseSqrt2(float number)
{
	union {
		float f;
		long i;
	} conv;

	float x2;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	conv.f = number;
	conv.i = 0x5f3759df - (conv.i >> 1);	// what the fuck? 
	conv.f = conv.f * (threehalfs - (x2 * conv.f * conv.f));
	return conv.f;
}

/*
*/
float CVector2D::magnitude()
{
	float len = (X * X) + (Y * Y);
	float invSqRoot = quickReverseSqrt2(len);
	float sqRoot = 1 / invSqRoot;

	return sqRoot;
	//return sqrt(len);
}

/*
*/
void CVector2D::setValues(float _x, float _y)
{
	X = _x;
	Y = _y;
}

/*
*/
void CVector2D::setValues(float* values)
{
	X = *(values + 0);
	Y = *(values + 1);
}

ostream& operator<<(ostream& os, const CVector2D& v)
{
	os << "X: " << v.X << "\tY: " << v.Y;
	return os;
	// TODO: insert return statement here
}
