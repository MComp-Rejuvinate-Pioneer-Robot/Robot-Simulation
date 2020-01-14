#pragma once
#include "Robot.h"

class Renderer : public Application {
	Simulator robotSim;
};

class Application {
protected:
	int width;
	int height;
public:
	void getTitle();
	void initGraphics();
	void display();
	void deinitialise();
	void resize();
	void update();
};

class Simulator {
public:
	Robot robot;
	World world;
};

class World {
	Obstacle* obstacles = nullptr;
};

class Obstacle {
private:
	float position[6]; // X, Y, Z, Width, Height, Depth.
public:
	float getPosition;
};