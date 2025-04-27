#include "MyD3DApp.h"
#include <stdexcept>

#ifndef ThrowIfFailed
#define ThrowIfFailed(x)                              \
do {                                                  \
    HRESULT hr__ = (x);                               \
    if (FAILED(hr__)) {                               \
        throw std::runtime_error("HRESULT FAILED");   \
    }                                                 \
} while (0)
#endif

// Constructor
MyD3DApp::MyD3DApp(HINSTANCE hInstance)
	: mhAppInst(hInstance) {
}

// Destructor
MyD3DApp::~MyD3DApp() {

}

/// <summary>
/// Initialize the application.
/// </summary>
/// <returns></returns>
bool MyD3DApp::Initialize() {
	if (!InitWindow()) return false;
	if (!InitDirect3D()) return false;
	return true;
}

/// <summary>
///	Run the application.
/// </summary>
/// <returns></returns>
int MyD3DApp::Run() {
	MSG msg = { 0 };

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// @todo: add Update and Draw  
		}
	}
	return static_cast<int>(msg.wParam);
}

bool MyD3DApp::InitWindow() {
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = DefWindowProc;
	wc.hInstance = mhAppInst;
	wc.lpszClassName = mMainWndCaption.c_str();

	if (!RegisterClass(&wc)) {
		MessageBox(nullptr, L"RegisterClass Failed", L"Error", MB_OK);
		return false;
	}

	RECT rc = { 0, 0, mClientWidth, mClientHeight };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	// Create the window
	mhMainWnd = CreateWindow(
		mMainWndCaption.c_str(),
		mMainWndCaption.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		nullptr,
		nullptr,
		mhAppInst,
		this
	);

	if (!mhMainWnd) {
		MessageBox(nullptr, L"CreateWindow Failed", L"Error", MB_OK);
		return false;
	}

	ShowWindow(mhMainWnd, SW_SHOW);

	return true;
}

bool MyD3DApp::InitDirect3D() {
#if defined(DEBUG) || defined(_DEBUG)
	Microsoft::WRL::ComPtr<ID3D12Debug> debugController;
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
		debugController->EnableDebugLayer();
	}
#endif

	ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&mdxgiFactory)));
	ThrowIfFailed(D3D12CreateDevice(
		nullptr,
		D3D_FEATURE_LEVEL_11_0,
		IID_PPV_ARGS(&md3dDevice)
	));

	return true;
}