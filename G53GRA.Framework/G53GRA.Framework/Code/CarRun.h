#pragma once
#include "ObjLoader.h"
#include "Animation.h"

class CarRun :
	public ObjLoader,
	public Animation
{
public:
	CarRun(string filename);
	~CarRun();

	void Display();
	void Update(const double& deltaTime);

private:
	void Draw();

	// member variable indicating program runtime
	double _runtime;
	float speed, acceleration, speedMax;	// variable used to control the speed

};

