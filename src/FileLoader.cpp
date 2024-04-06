#include "../include/FileLoader.hpp"

namespace eng::files {
	std::string OpenTextFile(std::string directory)
	{
		std::string s;
		std::ifstream f;
		f.open(directory);

		if (!f.is_open())
			return std::string("FAILED");

		while (f) {
			s += f.get();
		}

		f.close();
		return s;
	}

	std::string OpenShaderFile(std::string directory)
	{
		std::string vertexCode;
		std::ifstream vShaderFile;

		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			vShaderFile.open(directory);
			std::stringstream vShaderStream;

			vShaderStream << vShaderFile.rdbuf();

			vShaderFile.close();

			vertexCode = vShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			return "FAILED";
		}

		return vertexCode;
	}
}