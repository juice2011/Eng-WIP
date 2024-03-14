#pragma once
#include "../include/eng.hpp"
using namespace eng;
using namespace eng::rendering;
namespace eng::modules 
{
	struct ObjectRendererData
	{
		Mesh mesh;
		Material material;
	};

	class ObjectRenderer : public Module
	{
	public:
		Mesh mesh;
		Material material;

		void Start() override {}
		void Update() override {}
		void Exit() override {}

		void Render() override
		{
			std::cout << "Rendering\n";
		}

		void Create(ObjectRendererData data)
		{
			this->mesh = data.mesh;
			this->material = data.material;
		}
	};


	class Light
	{

	};

}