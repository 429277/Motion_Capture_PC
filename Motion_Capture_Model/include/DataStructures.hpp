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

struct RotationPass{
	float x;
	float y;
	float z;

	RotationPass(float xRot, float yRot, float zRot)
	{
		x = xRot;
		y = yRot;
		z = zRot;
	}
	RotationPass(sl::float3 rots) {
		x = rots.x;
		y = rots.y;
		z = rots.z;
	}
};

struct PoseSimple {
	 float transformX;
	 float transformY;
	 float transformZ;

	 float rotationX;
	 float rotationY;
	 float rotationZ;

	 char* status;

	 PoseSimple(sl::float3 points, sl::float3 rots, char *stat ) {
		 transformX = points.x;
		 transformY = points.y;
		 transformZ = points.z;

		 rotationX = rots.x;
		 rotationY = rots.y;
		 rotationZ = rots.z;

		 status = stat;
	 }
	 PoseSimple(char *stat) {
		 status = stat;
		 transformX = 0;
		 transformY = 0;
		 transformZ = 0;

		 rotationX = 0;
		 rotationY = 0;
		 rotationZ = 0;
	 }
};

struct PosePass
{
	struct Coordinate *coordinate;
	struct RotationPass *rotation;

	PosePass(Coordinate *coord, RotationPass *rot)
	{
		coordinate = coord;
		rotation = rot;
	}

};

struct ConfigParameters {
	Coordinate *initialPosition;
	RotationPass *initialRotation;
	int measurementsPerMinute; 

	ConfigParameters(sl::float3 position, sl::float3 rotation, int mpm) {
		initialPosition = new Coordinate(position);
		initialRotation = new RotationPass(rotation);
		measurementsPerMinute = mpm;
	}
	ConfigParameters(Coordinate* position, RotationPass* rotation, int mpm) {
		initialPosition = position;
		initialRotation = rotation;
		measurementsPerMinute = mpm;
	}
};