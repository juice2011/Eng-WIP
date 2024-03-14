#pragma once
#include "../include/RenderComponents.hpp"

namespace eng::meshes
{
    eng::Vec3 cube_vertices[8] = { 
        eng::Vec3(-0.5f, -0.5f, -0.5f),
        eng::Vec3(0.5f, -0.5f, -0.5f),
        eng::Vec3(0.5f, 0.5f, -0.5f),
        eng::Vec3(-0.5f, 0.5f, -0.5f),
        eng::Vec3(-0.5f, -0.5f, 0.5f),
        eng::Vec3(0.5f, -0.5f, 0.5f),
        eng::Vec3(0.5f, 0.5f, 0.5f),
        eng::Vec3(-0.5f, 0.5f, 0.5f) 
    };
    int cube_triangles[36] = {
        0, 1, 3, 3, 1, 2,
        1, 5, 2, 2, 5, 6,
        5, 4, 6, 6, 4, 7,
        4, 0, 7, 7, 0, 3,
        3, 2, 7, 7, 2, 6,
        4, 5, 0, 0, 5, 1
    };
    eng::rendering::Mesh cube = {
        cube_vertices,
        cube_triangles
    };
}