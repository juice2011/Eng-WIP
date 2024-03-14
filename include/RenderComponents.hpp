#pragma once
#include "../include/eng.hpp"
#include <iostream>
#include <string>
namespace eng::rendering
{
	struct Mesh 
	{
		Vec3* vertices;
		int* triangles;
	};

	class Shader
	{
	public:
		std::string vert_data;
		std::string frag_data;
	};

	class Material {
	public:
		Shader shader;
	};
}