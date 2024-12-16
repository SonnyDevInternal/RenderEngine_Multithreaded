#include "Renderer.h"

template<int Width, int Height>
inline void Plane<Width, Height>::Clear()
{
	std::memset(data.data(), 0, sizeof(Colour) * DimensionSize);
}

template<int Width, int Height>
bool Plane<Width, Height>::SetPixel(int x, int y, Colour clr)
{
    if (x >= Width || y >= Height || x < 0 || y < 0)
        return false;

    buffer[y * Width + x] = clr;
    return true;
}

template<int Width, int Height>
void Plane<Width, Height>::DrawLine(int x1, int y1, int x2, int y2, Colour clr) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        this->SetPixel(x1, y1, clr);

        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

template<int Width, int Height>
void Plane<Width, Height>::DrawLine(int x, int y, int w, int h, int width, Colour clr) {
    int maxThreads = std::thread::hardware_concurrency();
    int threadBatchSize = (width + maxThreads - 1) / maxThreads;

    std::vector<std::future<void>> futures;

    for (int i = 0; i < maxThreads; ++i) {
        int start = i * threadBatchSize;
        int end = std::min(width, start + threadBatchSize);

        if (start < end) {
            futures.push_back(std::async(std::launch::async, [=, this]() {
                for (int j = start; j < end; ++j) {
                    this->DrawLine(x + j, y, w + j, h, clr);
                }
                }));
        }
    }

    for (auto& future : futures) {
        future.get();
    }
}

template<int Width, int Height>
Plane<Width, Height>::Plane()
{
	this->Clear();
}

void Renderer::CreateDevice(HWND window)
{
    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

    //set buffer dimensions and format
    swapChainDesc.BufferCount = 2;
    swapChainDesc.BufferDesc.Width = 1920;
    swapChainDesc.BufferDesc.Height = 1080;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;;

    //set refresh rate
    swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
    swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;

    //sampling settings
    swapChainDesc.SampleDesc.Quality = 0;
    swapChainDesc.SampleDesc.Count = 1;

    //output window handle
    swapChainDesc.OutputWindow = window;
    swapChainDesc.Windowed = true;

    //Create the D3D device
    //--------------------------------------------------------------

    auto hresultDevice = D3D10CreateDeviceAndSwapChain(NULL,
        D3D10_DRIVER_TYPE_HARDWARE,
        NULL,
        0,
        D3D10_SDK_VERSION,
        &swapChainDesc,
        &pSwapChain,
        &d3dDevice);

    if (FAILED(hresultDevice))
    {
        hasRendererFailed = true;
        rendererError = RendererErrors::DeviceCreationFailed;
        return;
    }
}

void Renderer::CleanupDevice()
{

}

void Renderer::RenderScene()
{

}
