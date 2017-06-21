#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#include<cstdio>

// Abstraction to work with vectors in space
class Vector3 {
    public:
        float x;
        float y;
        float z;

        Vector3(float X, float Y, float Z);
        Vector3();
        void PrintCoords();

        // Overriding primitive operators to work with vector3
        // Sum of Vectors
        Vector3 operator+(Vector3 otherVector3);
        void operator+=(Vector3 otherVector3);
        Vector3 operator+();
        // Sub of Vectors
        Vector3 operator-(Vector3 otherVector3);
        void operator-=(Vector3 otherVector3);
        Vector3 operator-();
        // Product of vectors
        Vector3 operator*(Vector3 otherVector3);
        void operator*=(Vector3 otherVector3);
        // division of vectors (otherVector3 can't have any component = 0)
        Vector3 operator/(Vector3 otherVector3);
        void operator/=(Vector3 otherVector3);

        Vector3 operator*(float scalar);
        void operator*=(float scalar);

        bool operator==(Vector3 otherVector3);

        bool operator!=(Vector3 otherVector3);

        float Lenght();

        Vector3 normalized();

        static Vector3 up();
        static Vector3 down();
        static Vector3 left();
        static Vector3 right();
        static Vector3 forward();
        static Vector3 back();
        static Vector3 one();
        static Vector3 zero();

        static float Distance(Vector3 vector1, Vector3 vector2);

        static Vector3 Cross(Vector3 vector1, Vector3 vector2);
        static float Dot(Vector3 vector1, Vector3 vector2);
};
#endif
/*
// Abstraction to work with vectors in space
class Vector3 {
    public: float x;
    public: float y;
    public: float z;

    Vector3(float X=0, float Y=0, float Z=0){
    x=X; y=Y; z=Z;
    }

    public:
        // Overriding primitive operators to work with vector3
        // Sum of Vectors
        Vector3 operator+(Vector3 otherVector3){
            return Vector3(x + otherVector3.x, y + otherVector3.y, z + otherVector3.z);
        }
        // Sub of Vectors
        Vector3 operator-(Vector3 otherVector3){
            return Vector3(x - otherVector3.x, y - otherVector3.y, z - otherVector3.z);
        }
        // Product of vectors
        Vector3 operator*(Vector3 otherVector3){
            return Vector3(x * otherVector3.x, y * otherVector3.y, z * otherVector3.z);
        }
        // division of vectors (otherVector3 can't have any component = 0)
        Vector3 operator/(Vector3 otherVector3){
            return Vector3(x / otherVector3.x, y / otherVector3.y, z / otherVector3.z);
        }

        Vector3 operator*(float scalar){
            return Vector3(x * scalar, y*scalar, z*scalar);
        }

        bool operator==(Vector3 otherVector3){
            return (otherVector3.x == x && otherVector3.y == y && otherVector3.z == z);
        }

        bool operator!=(Vector3 otherVector3){
            return (otherVector3.x != x || otherVector3.y != y || otherVector3.z != z);
        }

        float Lenght(){
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }

        Vector3 normalized(){
            float lenght = Lenght();
            return Vector3(x/lenght, y/lenght, z/lenght);
        }

        static Vector3 up(){
            return Vector3(0, 1, 0);
        }
        static Vector3 down(){
            return Vector3(0, -1, 0);
        }
        static Vector3 left(){
            return Vector3(-1, 0, 0);
        }
        static Vector3 right(){
            return Vector3(1, 0, 0);
        }
        static Vector3 forward(){
            return Vector3(0, 0, 1);
        }
        static Vector3 back(){
            return Vector3(0, 1, -1);
        }
        static Vector3 one(){
            return Vector3(1, 1, 1);
        }
        static Vector3 zero(){
            return Vector3(0, 0, 0);
        }

        static float Distance(Vector3 vector1, Vector3 vector2){
            return Vector3(vector2 - vector1).Lenght();
        }

        static Vector3 Cross(Vector3 vector1, Vector3 vector2){
            return Vector3(vector1.y*vector2.z - vector1.z*vector2.y,
                           vector1.z*vector2.x - vector1.x*vector2.z,
                           vector1.x*vector2.y - vector1.y*vector2.x);
        }
        static float Dot(Vector3 vector1, Vector3 vector2){
            return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z;
        }
};
*/
