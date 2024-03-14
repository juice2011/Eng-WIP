#include "../include/eng.hpp"

using namespace eng;

void Object::AddModule(Module* mod)
{
	return modules.push_back(mod);
}