#pragma once

struct Color
{
	char R, G, B, A;

	Color(char R, char G, char B, char A) : R(){}
};

struct Vertice
{
	float x;
	float y;



	Vertice() : x(0.0f), y(0.0f) {};

	Vertice(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

struct Edge
{
	Vertice x;
	Vertice y;

	Edge() {};

	Edge(Vertice x, Vertice y)
	{
		this->x = x;
		this->y = y;
	}
};

struct Face
{
	Edge x;
	Edge y;
	Edge z;

	Face(Edge x, Edge y, Edge z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};