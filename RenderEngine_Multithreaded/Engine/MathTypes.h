#pragma once

#include <stdio.h>
#include <string>
#include <cmath>

struct Vector2
{
public:
	float x, y;

public:
	Vector2() : x(0.0f), y(0.0f) {};
	Vector2(float x, float y) : x(x), y(y) {};

	void Normalize();
	Vector2 Normalize_copy();
	Vector2 Direction(Vector2 targetTo);

	void operator=(Vector2 vec);
	void operator+=(Vector2 vec);
	Vector2 operator+(Vector2 vec);
};


struct Vector3
{
public:
	float x, y, z;

public:
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {};

	void Normalize();
	Vector3 Normalize_copy();
	Vector3 Direction(Vector3& targetTo);
	Vector3 Direction_copyParam(Vector3 targetTo);


	void operator=(Vector3* vec);
	void operator+=(Vector3* vec);
	Vector3 operator+(Vector3* vec);
};

struct Vector4
{
public:
	float x, y, z, w;

public:
	Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {};
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
};

struct Colour
{
	typedef unsigned char UChar;
public:
	UChar r, g, b, a;

public:
	Colour() : r(0), g(0), b(0), a(0) {};
	Colour(UChar r, UChar g, UChar b, UChar a) : r(r), g(g), b(b), a(a) {};

	operator unsigned int();
};