#pragma once

#include "DisplayableObject.h"
#include <string>
#include <vector>
using namespace std;

/*
	ObjLoader inherits the DisplayableObject
	Import the object from Object format file
	which includes
		v	(vectors)
		vn	(normal of each vector)
		f	(face consists of v and vn)
*/
class ObjLoader:
	public DisplayableObject
{
public:
	ObjLoader(string filename);
	~ObjLoader(){};

	void Load(string filename);

	vector<vector<float>> vSets;	// save vectors
	vector<vector<float>> vnSets;	// save normal vectors
	vector<vector<int>> fvSets;		// save index of vectors
	vector<vector<int>> fvnSets;	// save index of normal vectors
	
	int mtlNum[10];					// save the material
									// mtlNum[0] save the number of materials
};

