#include "MyScene.h"
#include "Road.h"
#include "TrafficLight.h"
#include "Building.h"
#include "Tree.h"
#include "CarStop.h"
#include "CarRun.h"
#include "Billboard.h"

#include "Light.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
	// Change the window to (1200, 800)
	Reshape(1200, 800);
}

void MyScene::Initialise()
{
	GetCamera()->Reset();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Ajust the height
	int height = -1800;

	// Add road
	Road* r = new Road(height);
	AddObjectToScene(r);

	// Add triffic light
	TrafficLight* tl1 = new TrafficLight();
	tl1->orientation(0.0f, -90.0f, 0.0f);
	tl1->position(-10.0f, height, -160.0f);
	AddObjectToScene(tl1);

	TrafficLight* tl2 = new TrafficLight();
	tl2->orientation(0.0f, 90.0f, 0.0f);
	tl2->position(610.0f, height, 160.0f);
	AddObjectToScene(tl2);

	// Add buildings
	Building* b = new Building("./Objects/building.obj", "./Textures/logo.bmp");
	b->size(30.0f);
	b->orientation(0.0f, 90.0f, 0.0f);
	b->position(-400.0f, height, 550.0f);
	AddObjectToScene(b);

	// Add trees
	Tree* t1 = new Tree("./Objects/tree2.obj");
	t1->size(25.0f);
	t1->orientation(0.0f, -90.0f, 0.0f);
	t1->position(-180.0f, height, 720.0f);
	AddObjectToScene(t1);

	Tree* t2 = new Tree("./Objects/tree2.obj");
	t2->size(25.0f);
	t2->orientation(0.0f, 90.0f, 0.0f);
	t2->position(-180.0f, height, 380.0f);
	AddObjectToScene(t2);
	
	Tree* t3 = new Tree("./Objects/tree1.obj");
	t3->size(50.0f);
	t3->position(-800.0f, height, 720.0f);
	AddObjectToScene(t3);

	Tree* t4 = new Tree("./Objects/tree1.obj");
	t4->size(50.0f);
	t4->orientation(0.0f, 30.0f, 0.0f);
	t4->position(-1100.0f, height, 380.0f);
	AddObjectToScene(t4);

	Tree* t5 = new Tree("./Objects/tree1.obj");
	t5->size(50.0f);
	t5->position(950.0f, height, 650.0f);
	AddObjectToScene(t5);

	// Add billborad
	Billboard* bb = new Billboard("./Objects/billboard.obj", "./Textures/post.bmp");
	bb->size(25.0f);
	bb->orientation(0.0f, 180.0f, 0.0f);
	bb->position(900.0f, height, 350.0f);
	AddObjectToScene(bb);

	// Add cars
	CarStop* cs = new CarStop("./Objects/car1.obj");
	cs->size(15.0f);
	cs->position(225.0f, height, 630.0f);
	AddObjectToScene(cs);
	
	CarRun* cr = new CarRun("./Objects/car2.obj");
	cr->size(12.0f);
	cr->position(-1200.0f, height, -75.0f);
	AddObjectToScene(cr);

	// Add light (Sun and Moon)
	Light* l = new Light(GetCamera(), "./Textures/moon.bmp", "./Textures/sun.bmp");
	l->position(-900.0f, 0.0f, 0.0f);
	AddObjectToScene(l);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 10000.0);
}
