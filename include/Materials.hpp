#pragma once
#include "../include/RenderComponents.hpp"
namespace eng::materials {
	const char* vert_shader_2d =
		"#version 400 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec2 texCoords;\n"
		"out vec2 texC;\n"
		"uniform mat4 transform;\n"
		"uniform mat4 view;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = view * transform * vec4(aPos, 1.0);\n"
		"	texC = texCoords;"
		"}\0";

	const char* vert_shader_3d =
		"#version 400 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec2 texCoords;\n"
		"out vec2 texC;\n"
		"uniform mat4 transform;\n"
		"uniform mat4 view;\n"
		"uniform mat4 proj;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = proj * view * transform * vec4(aPos, 1.0);\n"
		"	texC = texCoords;"
		"}\0";

	const char* unlit_frag_shader =
		"#version 400 core\n"
		"out vec4 FragColor;\n"
		"uniform sampler2D tex;\n"
		"in vec2 texC;\n"
		"void main()\n"
		"{\n"
		"   FragColor = texture(tex, texC);\n"
		"}\n\0";
	eng::Shader unlit_2d_shader = {
		(char*)vert_shader_2d,
		(char*)unlit_frag_shader
	};

	eng::Shader unlit_3d_shader = {
		(char*)vert_shader_3d,
		(char*)unlit_frag_shader
	};


	eng::Material unlit_2d = {unlit_2d_shader};
	eng::Material unlit_3d = {unlit_3d_shader};

}
