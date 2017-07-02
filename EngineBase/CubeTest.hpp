#ifndef CUBETEST_HPP
#define CUBETEST_HPP
/*
GLfloat cube[] {
    // Back
    -0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
    // Left
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    // Front
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    // Right
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    // Up
    -0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
    // Down
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
};
//*/
Vector3 verts[] = {
    // Back
    Vector3(-0.5f, -0.5f, -0.5f),
    Vector3(-0.5f,  0.5f, -0.5f),
    Vector3( 0.5f,  0.5f, -0.5f),
    Vector3(-0.5f, -0.5f, -0.5f),
    Vector3( 0.5f,  0.5f, -0.5f),
    Vector3( 0.5f, -0.5f, -0.5f),
    // Left
    Vector3(-0.5f, -0.5f,  0.5f),
    Vector3(-0.5f,  0.5f,  0.5f),
    Vector3(-0.5f,  0.5f, -0.5f),
    Vector3(-0.5f, -0.5f,  0.5f),
    Vector3(-0.5f,  0.5f, -0.5f),
    Vector3(-0.5f, -0.5f, -0.5f),
    // Front
    Vector3( 0.5f, -0.5f,  0.5f),
    Vector3( 0.5f,  0.5f,  0.5f),
    Vector3(-0.5f,  0.5f,  0.5f),
    Vector3( 0.5f, -0.5f,  0.5f),
    Vector3(-0.5f,  0.5f,  0.5f),
    Vector3(-0.5f, -0.5f,  0.5f),
    // Right
    Vector3( 0.5f, -0.5f, -0.5f),
    Vector3( 0.5f,  0.5f, -0.5f),
    Vector3( 0.5f,  0.5f,  0.5f),
    Vector3( 0.5f, -0.5f, -0.5f),
    Vector3( 0.5f,  0.5f,  0.5f),
    Vector3( 0.5f, -0.5f,  0.5f),
    // Up
    Vector3(-0.5f,  0.5f, -0.5f),
    Vector3(-0.5f,  0.5f,  0.5f),
    Vector3( 0.5f,  0.5f,  0.5f),
    Vector3(-0.5f,  0.5f, -0.5f),
    Vector3( 0.5f,  0.5f,  0.5f),
    Vector3( 0.5f,  0.5f, -0.5f),
    // Down
    Vector3(-0.5f, -0.5f,  0.5f),
    Vector3(-0.5f, -0.5f, -0.5f),
    Vector3( 0.5f, -0.5f, -0.5f),
    Vector3(-0.5f, -0.5f,  0.5f),
    Vector3( 0.5f, -0.5f, -0.5f),
    Vector3( 0.5f, -0.5f,  0.5f)
};

Vector3 vertsNormals[] = {
    // Back
    Vector3( 0.0f,  0.0f, -1.0f),
    Vector3( 0.0f,  0.0f, -1.0f),
    Vector3( 0.0f,  0.0f, -1.0f),
    Vector3( 0.0f,  0.0f, -1.0f),
    Vector3( 0.0f,  0.0f, -1.0f),
    Vector3( 0.0f,  0.0f, -1.0f),
    // Left
    Vector3(-1.0f,  0.0f,  0.0f),
    Vector3(-1.0f,  0.0f,  0.0f),
    Vector3(-1.0f,  0.0f,  0.0f),
    Vector3(-1.0f,  0.0f,  0.0f),
    Vector3(-1.0f,  0.0f,  0.0f),
    Vector3(-1.0f,  0.0f,  0.0f),
    // Front
    Vector3( 0.0f,  0.0f,  1.0f),
    Vector3( 0.0f,  0.0f,  1.0f),
    Vector3( 0.0f,  0.0f,  1.0f),
    Vector3( 0.0f,  0.0f,  1.0f),
    Vector3( 0.0f,  0.0f,  1.0f),
    Vector3( 0.0f,  0.0f,  1.0f),
    // Right
    Vector3( 1.0f,  0.0f,  0.0f),
    Vector3( 1.0f,  0.0f,  0.0f),
    Vector3( 1.0f,  0.0f,  0.0f),
    Vector3( 1.0f,  0.0f,  0.0f),
    Vector3( 1.0f,  0.0f,  0.0f),
    Vector3( 1.0f,  0.0f,  0.0f),
    // Up
    Vector3( 0.0f,  1.0f,  0.0f),
    Vector3( 0.0f,  1.0f,  0.0f),
    Vector3( 0.0f,  1.0f,  0.0f),
    Vector3( 0.0f,  1.0f,  0.0f),
    Vector3( 0.0f,  1.0f,  0.0f),
    Vector3( 0.0f,  1.0f,  0.0f),
    // Down
    Vector3( 0.0f, -1.0f,  0.0f),
    Vector3( 0.0f, -1.0f,  0.0f),
    Vector3( 0.0f, -1.0f,  0.0f),
    Vector3( 0.0f, -1.0f,  0.0f),
    Vector3( 0.0f, -1.0f,  0.0f),
    Vector3( 0.0f, -1.0f,  0.0f)
};

GLuint cubeElements[] {
     0,  1, 2, 3, 4, 5,
     6,  7, 8, 9,10,11,
     12,13,14,15,16,17,
     18,19,20,21,22,23,
     24,25,26,27,28,29,
     30,31,32,33,34,35

     /*
     0, 1, 2, 0, 2, 3, // Back
     4, 5, 1, 4, 1, 0, // Left = MeshRenderer();
     7, 6, 5, 7, 5, 4, // Front
     3, 2, 6, 3, 6, 7, // Right
     4, 0, 3, 4, 3, 7, // Bottom
     1, 5, 6, 1, 6, 2  // Top
     //*/
};


#endif
