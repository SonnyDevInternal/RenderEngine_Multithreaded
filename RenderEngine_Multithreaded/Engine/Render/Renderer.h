#pragma once

#include <array>
#include <future>
#include <atomic>
#include "d3d10.h"

#include "../MathTypes.h"
#include "RenderTypes.h"

#define DebugRenderer;

template <int Width, int Height>
class Plane
{
	const size_t DimensionSize = Width * Height;
private:
	std::array<Colour, DimensionSize> data;

public:
	Plane();

	void Clear();

	bool SetPixel(int x, int y, Colour clr);

	void DrawLine(int x, int y, int w, int y, Colour clr);
	void DrawLine(int x, int y, int w, int y, int width, Colour clr);

	template <int size>
	void DrawMesh(std::array<Face, size>)
	{

	}
};

class Renderer {
	enum RendererErrors : unsigned char
	{
		None = 0,
		DeviceCreationFailed = 1
	};
private:
	ID3D10Device* d3dDevice = nullptr;
	IDXGISwapChain* pSwapChain = nullptr;
	ID3D10RenderTargetView* pRenderTargetView = nullptr;

	bool hasRendererFailed = false;
	RendererErrors rendererError = None;

	Plane<1920, 1080> Screen;

	void CreateDevice(HWND windowHandle);
	void CleanupDevice();
public:
	void RenderScene();
};