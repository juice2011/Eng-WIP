#pragma once
#include "../include/Vectors.hpp"
#include "../include/lib/glm/glm.hpp"
#include "../include/lib/glm/gtc/matrix_transform.hpp"
#include "../include/lib/glm/gtc/type_ptr.hpp"

namespace eng
{
	struct CameraData {
		int priority, depth;
		float fov;
		Vec2 viewPlanes;
		Vec3 position, rotation;
		Color backgroundColor;
	};

	class Camera
	{
	public:
		int priority, depth;
		float fov;
		Vec2 viewPlanes;
		Vec3 position, rotation;
		Color backgroundColor = Color(0, 0, 0, 0);

		glm::mat4 viewMatrix;

		void BeginDraw();
		void Update();
		void Present();
	};
}