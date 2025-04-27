#pragma once

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <string>

// Link necessary libraries
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

class MyD3DApp {
public:
	// Constructors
	MyD3DApp(HINSTANCE hInstance);
	// Destructor
	~MyD3DApp();

	bool Initialize();
	int Run();

private:
	bool InitWindow();
	bool InitDirect3D();

private:
	HINSTANCE mhAppInst = nullptr;
	HWND mhMainWnd = nullptr;
	int mClientWidth = 800;
	int mClientHeight = 600;
	std::wstring mMainWndCaption = L"D3D App";

	Microsoft::WRL::ComPtr<ID3D12Device> md3dDevice;
	Microsoft::WRL::ComPtr<IDXGIFactory6> mdxgiFactory;

};