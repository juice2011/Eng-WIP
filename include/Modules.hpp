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
<<<<<<< HEAD
=======
		GLuint vbo, // Vertex Buffer Object
			ebo, // Element Buffer Object
			vao, // Vertex Something
			vs, // Vertex Shader
			fs; // Fragment Shader
		int meshSize, // Mesh Size (in bytes)
			meshLength, // Vertex Count
			triCount; // Triangle Count * 3
>>>>>>> development
	public:
		Mesh mesh;
		Mesh material;

		GLuint shaderProgram;

		GLuint sp;

		void Render();

<<<<<<< HEAD
		void Create(ObjectRendererData data, int vertCount, int triCount, float vertices[], int triangles[]);
	private:
		GLuint vbo, // Vertex Buffer Object
			ebo, // Element Buffer Object
			vao, // Vertex Something
			vs, // Vertex Shader
			fs; // Fragment Shader
		int meshSize, // Mesh Size (in bytes)
			meshLength, // Vertex Count
			triCount; // Triangle Count * 3
	
=======
		void Create(ObjectRendererData data, int vertCount, int triCount);
>>>>>>> development
	};


	class Light
	{

	};

}