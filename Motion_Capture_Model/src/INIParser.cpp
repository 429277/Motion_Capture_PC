#include <cstdio>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <ini.h>
#include "DataStructures.hpp"

using namespace std;

void ParseIniFromFile(const char* filePath) {
    FILE* file = NULL;
    fopen_s(&file, filePath, "rb");
    if (file)
    {
        //get file size
        size_t fileSize = 0;
        fseek(file, 0, SEEK_END);
        fileSize = ftell(file);
        rewind(file);

        char* fileContent = (char*) malloc(fileSize + 1);
        if (fileContent)
        {
            if (fread(fileContent, fileSize, 1, file) == 1)
            {
                // Read sucess
                fileContent[fileSize] = '\0';
                //ini_parseIni(fileContent);
            }
            free(fileContent);
        }

        fclose(file);
    }
}

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
    RotationPass initialRotation = *new RotationPass(stof(xRotationString), stof(yRotationString), stof(zRotationString));
    int resolution = stof(resolutionString);

    ConfigParameters params = *new ConfigParameters(&initialPosition, &initialRotation, resolution);
    return params;
}