#include "MyApp.h"

MyApp::MyApp(HINSTANCE hInstance)
	: D3DApp(hInstance) {}

bool MyApp::Initialize() {
	if (!D3DApp::Initialize()) return false;

	return true;
}

void MyApp::Update(const GameTimer& gt) {
	// do nothing at this moment 
}

void MyApp::Draw(const GameTimer& gt) {
	// do nothing at this moment
}