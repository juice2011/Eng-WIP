#pragma once
#define GLEW_STATIC
#include "../include/lib/glew.h"
#include "../include/lib/glfw3.h"
#include "../include/Modules.hpp"
#include <iostream>
#include <vector>

class Vec2
{
public:
	float x, y;

	Vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2 operator+(Vec2 b)
	{
		return Vec2(this->x + b.x, this->y + b.y);
	}
	Vec2 operator-(Vec2 b)
	{
		return Vec2(this->x - b.x, this->y - b.y);
	}
	Vec2 operator*(Vec2 b)
	{
		return Vec2(this->x * b.x, this->y * b.y);
	}
	Vec2 operator/(Vec2 b)
	{
		return Vec2(this->x / b.x, this->y / b.y);
	}
};
class Vec3
{
public:
	float x, y, z;

	Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3 operator+(Vec3 b)
	{
		return Vec3(this->x + b.x, this->y + b.y, this->z + b.z);
	}
	Vec3 operator-(Vec3 b)
	{
		return Vec3(this->x - b.x, this->y - b.y, this->z - b.z);
	}
	Vec3 operator*(Vec3 b)
	{
		return Vec3(this->x * b.x, this->y * b.y, this->z * b.z);
	}
	Vec3 operator/(Vec3 b)
	{
		return Vec3(this->x / b.x, this->y / b.y, this->z / b.z);
	}
};
class Vec4
{
public:
	float x, y, z, w;

	Vec4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vec4 operator+(Vec4 b)
	{
		return Vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);
	}
	Vec4 operator-(Vec4 b)
	{
		return Vec4(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);
	}
	Vec4 operator*(Vec4 b)
	{
		return Vec4(this->x * b.x, this->y * b.y, this->z * b.z, this->w * b.w);
	}
	Vec4 operator/(Vec4 b)
	{
		return Vec4(this->x / b.x, this->y / b.y, this->z / b.z, this->w / b.w);
	}
};
using Color = Vec4;

namespace eng {
	class Engine;
	const int perspective = 1;
	const int orthographic = 0;
	const int fullscreen = 52354;
	

	class Module {
	public:
		virtual void Update() = 0;
		virtual void Start() = 0;
		virtual void Render() = 0;
		virtual void Exit() = 0;
	};

	struct AppData {
		char* title;
		int width, height;
	};

	struct Transform {
		Vec3 position, rotation, scale;
	};

	struct CameraData {
		int priority, depth;
		Vec2 viewPlanes;
		Vec3 position, rotation;
		Color backgroundColor;
	};

	class Camera
	{
	public:
		int priority, depth;
		Vec2 viewPlanes = Vec2(0,0);
		Vec3 position = Vec3(0,0,0), rotation = Vec3(0,0,0);
		Color backgroundColor = Color(0,0,0,0);
		Camera(CameraData data) 
		{
			this->priority = data.priority;
			this->depth = data.depth;
			this->viewPlanes = data.viewPlanes;
			this->position = data.position;
			this->rotation = data.rotation;
			this->backgroundColor = data.backgroundColor;
		}

		void BeginDraw();
		void Present(GLFWwindow* e);
	};

	class Object {
	public:
		Transform* transform;
		char* name;

		std::vector<Module*> modules;


		void AddModule(Module* mod);
	};

	class Engine {
	public:
		char* name;
		int width, height;
		GLFWwindow* window;
		Object CreateObject(char name[], Transform transform);
		Camera CreateCamera(CameraData data);
		void Terminate();
		bool Running(GLFWwindow* window);
	};

	Engine CreateEngine(AppData data, bool* success);
}