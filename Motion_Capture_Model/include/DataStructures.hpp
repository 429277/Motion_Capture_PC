#pragma once
#include <sl/Camera.hpp>

struct Coordinate {
	float x;
	float y;
	float z;

	Coordinate(float xCoord, float yCoord, float zCoord) {
		x = xCoord;
		y = yCoord;
		z = zCoord;
	}
	Coordinate(sl::float3 points) {
		x = points.x;
		y = points.y;
		z = points.z;
	}
};