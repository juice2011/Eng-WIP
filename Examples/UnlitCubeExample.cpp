using namspace eng::modules;

eng::AppData appdata = {
	"Test App", // title
	eng::FULLSCREEN, // width
	eng::FULLSCREEN // height
};

eng::Transform transform = {
	Vec3(0, 0, 0), // position
	Vec3(0, 0, 0), // rotation
	Vec3(1, 1, 1) // scale
};

eng::CameraData cameradata = {
		1,
		eng::perspective,
		0.03f, 
		1000,
		Vec3(0, 0, -10),
		Vec3(0, 0, 0),
		Color(0,0,0,0)
};

eng::ObjectRendererData renderdata = {
	eng::meshes::cube,
	eng::materials::unlit
};

int main()
{
	eng::Engine engine = eng::CreateEngine(appdata);
	
	eng::Camera camera = engine.CreateCamera(cameradata);
	
	eng::Object obj = engine.CreateObject("test object",  	 transform);
	
	ObjectRenderer renderobject = 					 	obj.AddModule<ObjectRenderer>();
	
	renderobject.Create(renderdata);
	while (engine.Running())
	{
		camera.StartDrawing();
		
		camera.Render(renderobject);
		
		camera.Present();
	}
	
	engine.Terminate();
	
	return 0;
}