#include "../include/eng.hpp"

using namespace eng;

std::size_t Object::AddModule(Module* mod)
{
	modules.push_back(mod);
}