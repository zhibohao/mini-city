#pragma once
#include "ObjLoader.h"
#include "Animation.h"

class Billboard :
	public ObjLoader, public Animation
{
public:
	Billboard(string filename, string textureName);
	~Billboard(){};

	void Display();
	void Update(const double& deltaTime);
private:
	void Draw();
	void DrawTexture();

	int texID;			// record texture
	double _runtime;	// record runtime
	float spread;		// record the spread of frame
};
