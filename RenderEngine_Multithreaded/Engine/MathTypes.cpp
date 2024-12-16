#include "MathTypes.h"

//vec 2

void NormalizeInternalVec2(Vector2* vec)
{
	float x = vec->x;
	float y = vec->y;

	float normalizer = std::sqrt((x * x) + (y * y));

	vec->x = x / normalizer;
	vec->y = y / normalizer;
}

void Vector2::Normalize()
{
	NormalizeInternalVec2(this);
}

Vector2 Vector2::Normalize_copy()
{
	Vector2 outVal = *this;

	NormalizeInternalVec2(&outVal);

	return outVal;
}

//not normalized
Vector2 Vector2::Direction(Vector2& targetTo)
{
	return { targetTo.x - x, targetTo.y - y};
}

//this is if your tryna pass an inline constructed Vector
Vector2 Vector2::Direction_copyParam(Vector2 targetTo)
{
	return Vector2(targetTo.x - x, targetTo.y - y);
}

void Vector2::operator=(Vector2* vec)
{
	std::memcpy(this, vec, sizeof(Vector2));
}

void Vector2::operator+=(Vector2* vec)
{
	this->x += vec->x;
	this->y += vec->y;
}

Vector2 Vector2::operator+(Vector2* vec)
{
	return Vector2(this->x + vec->x, this->y + vec->y);
}

//vec 3

void NormalizeInternalVec3(Vector3* vec)
{
	float x = vec->x;
	float y = vec->y;
	float z = vec->z;

	float normalizer = std::sqrt((x * x) + (y * y) + (z * z));

	vec->x = x / normalizer;
	vec->y = y / normalizer;
	vec->z = z / normalizer;
}


void Vector3::Normalize()
{
	NormalizeInternalVec3(this);
}

Vector3 Vector3::Normalize_copy()
{
	Vector3 outVal = *this;

	NormalizeInternalVec3(&outVal);

	return outVal;
}

//not normalized
Vector3 Vector3::Direction(Vector3& targetTo)
{
	return { targetTo.x - x, targetTo.y - y, targetTo.z - z };
}

//this is if your tryna pass an inline constructed Vector
Vector3 Vector3::Direction_copyParam(Vector3 targetTo)
{
	return Vector3(targetTo.x - x, targetTo.y - y, targetTo.z - z);
}

void Vector3::operator=(Vector3* vec)
{
	std::memcpy(this, vec, sizeof(Vector3));
}

void Vector3::operator+=(Vector3* vec)
{
	this->x += vec->x;
	this->y += vec->y;
	this->z += vec->z;
}

Vector3 Vector3::operator+(Vector3* vec)
{
	return Vector3(this->x + vec->x, this->y + vec->y, this->z + vec->z);
}

Colour::operator unsigned int()
{
	return *(unsigned int*)(this);
}