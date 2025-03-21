#include <string.h>
#include <iostream>
#include <ini.h>
#include "DataStructures.hpp"

using namespace std;

ConfigParameters GetConfigurationParameters(const char* filePath) {
    mINI::INIFile file(filePath);
    mINI::INIStructure ini;
    file.read(ini);
    std::string& xPositionString = ini["Position"]["x"];
    std::string& yPositionString = ini["Position"]["y"];
    std::string& zPositionString = ini["Position"]["z"];

    std::string& xRotationString = ini["Rotation"]["x"];
    std::string& yRotationString = ini["Rotation"]["y"];
    std::string& zRotationString = ini["Rotation"]["z"];

    std::string& resolutionString = ini["Advanced"]["measurementsPerMinute"];

    Coordinate initialPosition = *new Coordinate(stof(xPositionString), stof(yPositionString), stof(zPositionString));
    RotationSimple initialRotation = *new RotationSimple(stof(xRotationString), stof(yRotationString), stof(zRotationString));
    int resolution = stof(resolutionString);

    ConfigParameters params = *new ConfigParameters(initialPosition, initialRotation, resolution);
    return params;
}

//ConfigParameters configParameters
bool SetConfigurationParameters(const char* filePath, ConfigParameters configParameters){
    mINI::INIFile file(filePath);
    mINI::INIStructure ini;
    file.read(ini);
    ini["Position"]["x"] = std::to_string(configParameters.initialPosition.x);
    ini["Position"]["y"] = std::to_string(configParameters.initialPosition.y);
    ini["Position"]["z"] = std::to_string(configParameters.initialPosition.z);

    ini["Rotation"]["x"] = std::to_string(configParameters.initialRotation.x);
    ini["Rotation"]["y"] = std::to_string(configParameters.initialRotation.y);
    ini["Rotation"]["z"] = std::to_string(configParameters.initialRotation.z);

    ini["Advanced"]["measurementsPerMinute"] = std::to_string(configParameters.measurementsPerMinute);;

    file.write(ini);
    return true;
}