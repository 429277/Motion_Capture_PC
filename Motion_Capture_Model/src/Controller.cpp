#include "BodyTracking.hpp"
#include "Controller.hpp"
#include <sl/Camera.hpp>
#include "DataStructures.hpp"

typedef void (*CoordinateDataCallback)(Coordinate);
static CoordinateDataCallback callbackCoordinate = nullptr;

typedef void (*LoadingCallback)(bool);
static LoadingCallback callbackLoading = nullptr;

#define Controller extern "C" _declspec(dllexport)

char* string[] = { "" };
char** nothing = string;

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
Controller void RegisterLoadingCallback(LoadingCallback cb) {
	callbackLoading = cb;
}

void NotifyLoadingToggle(bool loading) {
	if (callbackLoading) {
		callbackLoading(loading);
	}
}
#pragma endregion


Controller int TestDll() {
	return 777;
}

Controller void StartBodyTracking() {
	BodyTracking(0, nothing);
}

Controller void GetCurrentBodyTrackingCoordinates() {
	BodyTracking(0, nothing);
}

Controller void StopBodyTracking() {
	BodyTracking(0, nothing);
}
