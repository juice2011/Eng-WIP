#include "../include/eng.hpp"
namespace eng {
	void Shader::SetValue(float v, std::string name, int o)
	{
		glUniform1f(glGetUniformLocation(o, name.data()), v);
	}

	void Shader::SetValue(int v, std::string name, int o)
	{
		glUniform1i(glGetUniformLocation(o, name.data()), v);
	}

	void Shader::SetValue(double v, std::string name, int o)
	{
		glUniform1d(glGetUniformLocation(o, name.data()), v);
	}
}