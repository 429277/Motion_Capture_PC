#pragma once
#include <sl/Camera.hpp>

using std::vector;

class CoordinateDataStorage {

public:
	int SafeCoordinate(vector<sl::float3> coordinate);
	vector<vector<sl::float3>> GiveCollectedData();
	void test();
	void PrintCoordinateData();

private:
	vector<vector <sl::float3 >> coordinates;
};