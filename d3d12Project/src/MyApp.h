#pragma once

#include "d3dApp.h"

class MyApp : public D3DApp {
public:
	MyApp(HINSTANCE hInstance);
	virtual bool Initialize() override;

	// These are the pure virtual functions defined in D3DApp
	// We must override these (remember to implement them in cpp)
	virtual void Update(const GameTimer& gt) override;
	virtual void Draw(const GameTimer& gt) override;
};