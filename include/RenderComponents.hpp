#pragma once
#include "../include/eng.hpp"
#include <string>
#include <vector>

namespace eng
{
	class Mesh
	{
	public:
		float* vertices;
		int* triangles;
	};
	class Shader
	{
	public:
		char* vert_data;
		char* frag_data;
<<<<<<< HEAD
		void SetValue(float v, std::string name, int o);
		void SetValue(int v, std::string name, int o);
		void SetValue(double v, std::string name, int o);
=======
		void SetValue(float v, std::string name, int sp);
>>>>>>> development
	};

	class Material {
	public:
		Shader shader;
	};

}