#pragma once
#define GLEW_STATIC
#include "../include/lib/glew.h"
#include "../include/lib/glfw3.h"
#include "../include/RenderComponents.hpp"
#include <iostream>
using namespace eng;
namespace eng
{
	class ObjectRendererData
	{
	public:
		Mesh mesh;
		Material material;
	};

	class ObjectRenderer 
	{
		GLuint vbo, // Vertex Buffer Object
			ebo, // Element Buffer Object
			vao, // Vertex Something
			vs, // Vertex Shader
			fs; // Fragment Shader
		int meshSize, // Mesh Size (in bytes)
			meshLength, // Vertex Count
			triCount; // Triangle Count * 3
	public:
		Mesh mesh;
		Material material;

		GLuint sp;

		void Render();

		void Create(ObjectRendererData data, int vertCount, int triCount);
	};


	class Light
	{

	};

}