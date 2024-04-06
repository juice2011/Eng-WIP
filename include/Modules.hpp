#pragma once

#include "../include/RenderComponents.hpp"
#include "../include/Camera.hpp"
#include <iostream>
using namespace eng;

namespace eng
{

	struct Transform {
		Vec3 position, rotation, scale;
	};

	class ObjectRendererData
	{
	public:
		Mesh mesh;
		Material material;
	};

	class ObjectRenderer
	{
	public:
		Mesh mesh;
		Material material;

		GLuint shaderProgram;

		Transform* transform;

		void Render(int triCount);
		void Create(ObjectRendererData data, int vertCount, int triCount, int texCoordCount, Transform* transform);
		void CreateTexture(const char* path);
		void BindTexture();
		void Perspective(GLFWwindow* window, Camera* camera);
		void Translate(Camera* camera);
	private:
		GLuint vbo, // Vertex Buffer Object
			ebo, // Element Buffer Object
			vao, // Vertex Something
			vs, // Vertex Shader
			fs,
			tex; // Fragment Shader
		int meshSize, // Mesh Size (in bytes)
			meshLength, // Vertex Count
			triCount; // Triangle Count * 3
	
	};


	class Light
	{

	};

}