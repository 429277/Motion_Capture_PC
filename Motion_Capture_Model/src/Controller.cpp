#include "BodyTracking.hpp"
#include "PositionalTracking.hpp"
#include "Controller.hpp"
#include <sl/Camera.hpp>
#include "DataStructures.hpp"

char* str[] = { "" };
char** nothing = str;

typedef void (*CoordinateDataCallback)(Coordinate);
static CoordinateDataCallback callbackCoordinate = nullptr;

typedef void (*PositionCallback)(PoseSimple);
static PositionCallback callbackPosition = nullptr;

#define Controller extern "C" _declspec(dllexport)

#pragma region Coordinates callback
Controller void RegisterCoordinateCallback(CoordinateDataCallback cb) {
	callbackCoordinate = cb;
}

void NotifyNewCoordinateData(Coordinate newValue) {
	if (callbackCoordinate) {
		callbackCoordinate(newValue);
	}
}
#pragma endregion

#pragma region Loading callback 
Controller void RegisterPositionCallback(PositionCallback cb) {
	callbackPosition = cb;
}

void NotifyPosition(PoseSimple pose) {
	if (callbackPosition) {
		callbackPosition(pose);
	}
}
#pragma endregion


Controller int TestDll() {
	return 777;
}

Controller void StartBodyTracking() {
	BodyTracking(0, nothing);
}

Controller void StopBodyTracking() {
	BodyTracking(0, nothing);
}

Controller void StartPositionalTracking(char* areaFile) {
	PositionalTracking(0, nothing, "", 0);

}Controller void SetCameraPosition(Coordinate position) {
	
}
