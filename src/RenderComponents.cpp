#include "../include/Modules.hpp"

void eng::Shader::SetValue(float v, std::string name, int sp)
{
	glUniform1f(glGetUniformLocation(sp, name.data()), v);
}