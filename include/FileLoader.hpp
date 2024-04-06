#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
namespace eng::files {
	std::string OpenTextFile(std::string directory);
	std::string OpenShaderFile(std::string directory);
}