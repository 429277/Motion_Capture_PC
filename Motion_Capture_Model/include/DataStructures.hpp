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

struct RotationSimple{
	float x;
	float y;
	float z;

	RotationSimple(float xRot, float yRot, float zRot)
	{
		x = xRot;
		y = yRot;
		z = zRot;
	}
	RotationSimple(sl::float3 rots) {
		x = rots.x;
		y = rots.y;
		z = rots.z;
	}
};

struct PoseSimple
{
	struct Coordinate coordinate;
	struct RotationSimple rotation;

	PoseSimple(Coordinate const& coord, RotationSimple const& rot) 
		: coordinate(coord)
		, rotation(rot)
	{}

};

struct CameraPoseData {
	 float transformX;
	 float transformY;
	 float transformZ;

	 float rotationX;
	 float rotationY;
	 float rotationZ;

	 char* status;

	 CameraPoseData(sl::float3 points, sl::float3 rots, char *stat ) {
		 transformX = points.x;
		 transformY = points.y;
		 transformZ = points.z;

		 rotationX = rots.x;
		 rotationY = rots.y;
		 rotationZ = rots.z;

		 status = stat;
	 }
	 CameraPoseData(char *stat) {
		 status = stat;
		 transformX = 0;
		 transformY = 0;
		 transformZ = 0;

		 rotationX = 0;
		 rotationY = 0;
		 rotationZ = 0;
	 }
};

struct ConfigParameters {
	Coordinate initialPosition;
	RotationSimple initialRotation;
	float measurementsPerMinute; 

	ConfigParameters(Coordinate const& position, RotationSimple const& rotation, float mpm) 
		: initialPosition(position)
		, initialRotation(rotation)
		,measurementsPerMinute(mpm)
	{}
};