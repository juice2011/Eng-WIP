#pragma once
#include "../include/RenderComponents.hpp"

namespace eng::materials {
	const std::string blank_vert_shader = {
		"#version 330\n"
		"layout(location = 0) in vec3 aPos;"
		"void main() {"
		"	gl_Position = vec4(aPos, 1.0);"
		"}"
	};
	const std::string unlit_frag_shader = {
		"#version 330\n"
		"uniform in vec4 color;"
		"out vec4 FragColor"
		"void main() {"
		"	FragColor = color;"
		"}"
	};
	eng::rendering::Shader unlit_shader = {
		blank_vert_shader,
		unlit_frag_shader
	};

	eng::rendering::Material unlit = {unlit_shader};

}
