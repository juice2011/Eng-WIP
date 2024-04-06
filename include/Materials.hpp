#pragma once
#include "../include/RenderComponents.hpp"

const char* blak_vert_shader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"out vec4 color;\n"
"uniform float time;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"	color = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* unli_frag_shader =
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec4 color;"
"void main()\n"
"{\n"
"   FragColor = color;\n"
"}\n\0";

namespace eng::materials {
	const char* blank_vert_shader = 
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char* unlit_frag_shader = 
		    "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n\0";
	eng::Shader unlit_shader = {
		(char*)blank_vert_shader,
		(char*)unlit_frag_shader
	};

	eng::Material unlit = {unlit_shader};

}
