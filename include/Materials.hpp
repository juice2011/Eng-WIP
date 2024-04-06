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
	const char* vert_shader_2d =
		"#version 400 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
<<<<<<< HEAD
	const char* unlit_frag_shader = 
		    "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n\0";
	eng::Shader unlit_shader = {
		(char*)blank_vert_shader,
=======
	const char* unlit_frag_shader =
		"#version 400 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1,1,1,1);\n"
		"}\n\0";
	eng::Shader unlit_2d_shader = {
		(char*)vert_shader_2d,
>>>>>>> development
		(char*)unlit_frag_shader
	};


	eng::Material unlit_2d = {unlit_2d_shader};

}
