#include <iostream>
#include "BodyTracking.hpp"
#include "Shader.hpp"
#include "PositionalTracking.hpp"
#include "INIParser.hpp"
#include "DataStructures.hpp"

using namespace std;

int main(int argc, char** argv){
	//PositionalTracking(argc, argv);
	//ConfigParameters config = GetConfigurationParameters("./config.ini");
	BodyTracking(argc, argv);
}