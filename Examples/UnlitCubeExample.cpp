#include "../include/eng.hpp"
#include "../include/Meshes.hpp" // Provides basic mesh templates
#include "../include/Materials.hpp" // Provides shaders

eng::AppData appdata = {
	(char*)"Test App", // title
	500, // width
	500 // height
};

eng::Transform transform = {
	Vec3(0, 0, 0), // position
	Vec3(0, 0, 0), // rotation
	Vec3(1, 1, 1) // scale
};

eng::CameraData cameradata = {
		1,
		eng::perspective,
		Vec2(0.03f, 1000),
		Vec3(0, 0, -10),
		Vec3(0, 0, 0),
		Color(0,0,0,1)
};

ObjectRendererData renderdata = {
	eng::meshes::triangle,
	eng::materials::unlit
};

int main()
{
	bool yay;
	eng::Engine engine = eng::CreateEngine(appdata , &yay);
	if (!yay)
	{
		return -1;
	}

	eng::Camera camera = engine.CreateCamera(cameradata);

	eng::Object obj = engine.CreateObject((char*)"test object", transform);

	ObjectRenderer renderobject;

	renderobject.Create(renderdata, 3, 1, eng::meshes::triangle_vertices, eng::meshes::triangle_triangles);

	while (engine.Running(engine.window))
	{
		camera.BeginDraw();
		renderobject.Render();
		camera.Present(engine.window);
	}

	engine.Terminate();

	return 0;
}