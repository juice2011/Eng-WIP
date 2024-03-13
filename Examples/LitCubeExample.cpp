#include "../include/eng.hpp"

using namespace eng::modules;

eng::AppData appdata = {
	(char*)"Test App", // title
	eng::fullscreen, // width
	eng::fullscreen // height
};

eng::Transform transform = {
	eng::Vec3(0, 0, 0), // position
	eng::Vec3(0, 0, 0), // rotation
	eng::Vec3(1, 1, 1) // scale
};

eng::Transform lighttransform = {
	eng::Vec3(0, 0, 0), // position
	eng::Vec3(0, 0, 0), // rotation
	eng::Vec3(1, 1, 1) // scale
};

eng::CameraData cameradata = {
		1,
		eng::perspective,
		eng::Vec2(0.03f, 1000),
		eng::Vec3(0, 0, -10),
		eng::Vec3(0, 0, 0),
		eng::Color(0,0,0,0)
};

eng::ObjectRendererData renderdata = {
	eng::meshes::cube,
	eng::materials::lit
};

int main()
{
	eng::Engine engine = eng::CreateEngine(appdata);
	
	eng::Camera camera = engine.CreateCamera(cameradata);
	
	eng::Object obj = engine.CreateObject("test object", transform);
	
	ObjectRenderer renderobject = obj.AddModule<ObjectRenderer>();
	
	renderobject.Create(renderdata);
	
	eng::Object lightobject = engine.CreateObject("light", lighttransform);
	
	Light light = lightobject.AddModule<Light>();
	
	light.Create(1);
	
	while (engine.Running())
	{
		camera.StartDrawing();
		
		camera.Render(renderobject);
		
		camera.Present();
	}
	
	engine.Terminate();
	
	return 0;
}