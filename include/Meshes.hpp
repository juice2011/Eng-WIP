#pragma once
#include "../include/RenderComponents.hpp"

namespace eng::meshes
{
    float cube_vertices[24] = {
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f
    };
    int cube_triangles[36] = {
        0, 1, 3, 3, 1, 2,
        1, 5, 2, 2, 5, 6,
        5, 4, 6, 6, 4, 7,
        4, 0, 7, 7, 0, 3,
        3, 2, 7, 7, 2, 6,
        4, 5, 0, 0, 5, 1
    };
    eng::Mesh cube = {
        cube_vertices,
        cube_triangles
    };

    float triangle_vertices[9] = {
        -0.5f, -0.5f, 1,
        0.5f, -0.5f, 1,
        0, 1, 0
    };
    int triangle_triangles[3] = {
<<<<<<< HEAD
        1, 2, 3
=======
        3,2,1
>>>>>>> development
    };

    eng::Mesh triangle = {
        triangle_vertices,
        triangle_triangles
    };

    float square_vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };
    int square_indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    eng::Mesh square = {
        square_vertices,
        square_indices
    };
}