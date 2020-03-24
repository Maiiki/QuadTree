#pragma once
#include<iostream>
using namespace std;

#ifndef CVECTOR3_H
#define CVECTOR2D_H

// Simple class to practice C++ class creation
// It will be more helpful later when more code is added
class CVector2D
{
public:
	float X, Y;

public:
	CVector2D();
	CVector2D(float _x, float _y);
	CVector2D(const CVector2D& other);
	~CVector2D();

	CVector2D& operator=(const CVector2D& other);

	friend ostream& operator<<(ostream& os, const CVector2D& v);

	CVector2D operator+(const CVector2D& other);
	CVector2D& operator+=(const CVector2D& other);

	CVector2D operator-(const CVector2D& other);
	CVector2D& operator-=(const CVector2D& other);

	CVector2D operator*(float delta);
	CVector2D& operator*=(float delta);

	//CVector2D cross(const CVector2D& other);
	float dot(const CVector2D& other);

	void setValues(float _x, float _y);
	void setValues(float* values);
	float getX() const { return X; }
	float getY() const { return Y; }
	void getValues(float* values) const { values[0] = X; values[1] = Y; }
	void normalize();
	float magnitude();

	inline static CVector2D ZeroVector()
	{
		return CVector2D(0.0f, 0.0f);
	}

private:
	float quickReverseSqrt(float number);
	float quickReverseSqrt2(float number);
};

#endif // !CVECTOR2D_H
