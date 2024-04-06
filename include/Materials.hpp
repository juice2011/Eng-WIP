#pragma once
#include "../include/RenderComponents.hpp"

namespace eng::materials {
	const char* vert_shader_2d =
		"#version 400 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char* unlit_frag_shader =
		"#version 400 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1,1,1,1);\n"
		"}\n\0";
	eng::Shader unlit_2d_shader = {
		(char*)vert_shader_2d,
		(char*)unlit_frag_shader
	};


	eng::Material unlit_2d = {unlit_2d_shader};

}
