#pragma once
#include "DataStructures.hpp"

ConfigParameters GetConfigurationParameters(const char* filePath);
bool SetConfigurationParameters(const char* filePath, ConfigParameters configParameters);