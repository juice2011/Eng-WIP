#pragma once
#define GLEW_STATIC
#include "../include/lib/glew.h"
#include "../include/lib/glfw3.h"
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