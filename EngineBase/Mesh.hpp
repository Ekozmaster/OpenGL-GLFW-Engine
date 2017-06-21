#ifndef MESH_HPP
#define MESH_HPP

class Mesh : Behaviour {
    public:
        Mesh();
        void Setup();

        Vector3 vertices[];
        int triangles[];

};

#endif
