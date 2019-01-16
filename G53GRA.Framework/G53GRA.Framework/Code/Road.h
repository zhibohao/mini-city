#pragma once
#include "DisplayableObject.h"

class Road :
	public DisplayableObject
{
public:
	Road(float _height);
	~Road(){};

	void Display();
private:
	void Draw();
	void DrawRectangle(float l, float w, float height);		// Draw the Rectangle
	void DrawCuboid(float l, float w, float h);				// Draw Cubiod

	GLfloat bWidth, bLength;		//	size of black part
	GLfloat wWidth, wLength;		//	size of white part
	GLfloat height;					//	height of sidewalk
	GLfloat zebraWidth, zebraLength;	// size of zebra crossing
	GLfloat sidewalkWidth, sidewalkHeight;	// size of sidewalk
};

