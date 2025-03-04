#include <iostream>
#include "CoordinateDataStorage.hpp"

using namespace std;
using std::vector;

int CoordinateDataStorage::SafeCoordinate(vector<sl::float3> coordinate) {
	coordinates.push_back(coordinate);
	return 0;
}

vector<vector<sl::float3>> CoordinateDataStorage::GiveCollectedData() {
	return coordinates;
} 

void CoordinateDataStorage::test() {
	std::cout << "works";
}

void CoordinateDataStorage::PrintCoordinateData() {
    cout << "The data we collected:" << endl;
    for (size_t i = 0; i < coordinates.size(); i++)
    {
        cout << "Measurement " << i << endl;
        for (size_t j = 0; j < coordinates[i].size(); j++)
        {
            cout << "<" << coordinates[i][j] << "> ";
        }
        cout << endl;
    }
}

