#pragma once

class Robot {
private:
	// Guessed values based on incoming sensor data and previous motor output.
	// Should be accurate in a perfect system.
	float guessPosition[3] = { 0, 0, 0 };
	float guessRotation[3] = { 0, 0, 0 };

	// Real values used for simulator only.
	// Used to feed sensor data back to robot to calculate guess values.
	float realPosition[3] = { 0, 0, 0 };
	float realRotation[3] = { 0, 0, 0 };

	
	//navigation
	//behaviour
	RobotAttributes robotAttributes;

	Motor wheelMotors[4];
	//microphone
	//speaker
	//camera
	//sonarController
public:
	
};

class Motor {
private:
	float output = 0; //-100 to 100 for full reverse/forward.
public:
	float getCurrentOutput();
	bool setCurrentOutput(float output);
};

class RobotAttributes {
public:
	const int weight = 12 ;

	// Maximum recommended payload weights on different surface types (kg).
	const int mPayloadLevel = 12;
	const int mPayloadSoft = 10;
	const int mPayloadHard = 5;

	// Maximum traversal distances before getting stuck, probably (m).
	const float mTraverseStep = 0.1;
	const float mTraverseGap = 0.15;

	// Maximum vertical grade before the robot cannot progress uphill (%).
	const float mTraverseGrade = 0.35;

	// Maximum lateral speed (m/s).
	const float mLSpeed = 0.7;

	// Maximum rotation speed (degrees/s).
	const int mRSpeed = 140;

	const float voltage = 5;
	const float amplitude = 1.5;
};

class Behaviours {
public:
	bool rotate(float degrees) { false; };
	bool move(float distance) { false; };

	bool calculateMotorOutputs() { false; };

	//Attempt to determine position in known system.
	bool determinePositioning() { false; };

	bool pingSonar() { false; };
};

class RNavigator {
	NavNode* nodeMap = nullptr;
public:
	NavNode* getNeighbors();
	NavNode* pathToNode();
};

class NavNode {
	NavNode* neighbors = nullptr;
};

class SonarController {
private:
	Sonar sonarArray[7];
public:
	float lastReading[7];
	void pingSonar();
};

class Sonar {
public:
	float pulse();
};