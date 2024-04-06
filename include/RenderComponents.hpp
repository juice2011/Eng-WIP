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

		void SetValue(float v, std::string name, int sp);
	};

	class Material {
	public:
		Shader shader;
	};

}