// Quaternion is a tool used to rotate objects around an axis (x,y,z), in a certain
// Angle (w).
#include <array>
#include<iostream>

#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include"Vector3.hpp"
#include"Mathf.hpp"


#define PI 3.14159265f

template<std::size_t SIZE>
std::array<std::array<float, SIZE>, SIZE> multiplyMatrix(std::array<std::array<float, SIZE>, SIZE> matrix1, std::array<std::array<float, SIZE>, SIZE> matrix2){
    std::array<std::array<float, 4>, 4> newMatrix = {{{0,0,0},
                                                      {0,0,0},
                                                      {0,0,0}}};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            float sum = 0;
            for(int k=0; k<3; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            newMatrix[i][j] = sum;
        }
    }

    return newMatrix;
}

class Quaternion {
    public:
        float x,y,z,w;
        std::array<std::array<float, 4>, 4> rotMatrix;
        Quaternion(float X, float Y, float Z, float W);
        Quaternion();

        std::array<std::array<float, 4>, 4> buildMatrix(float x, float y, float z, float w);
        // Converts from euler (x,y,z) angles to a Quaternion.
        static Quaternion Euler(Vector3 angles);

        // Converts from euler (x,y,z) angles to a Quaternion.
        static Quaternion Euler(float Xa, float Ya, float Za);

        // Default zero rotation.
        static Quaternion identity();
        // Converts from a Axis and angle to Quaternion.
        static Quaternion AxisAngle(Vector3 axis, float angle);
        void PrintValues();
        Vector3 operator*(Vector3 vector);
        Quaternion operator*(Quaternion addQuat);
};

/*
class Quaternion {
    //const static float degreeToRad = M_PI/180;
    //const static float radToDegree = 180 / M_PI;

    public:
        float x, y, z, w;
        std::array<std::array<float, 4>, 4> rotMatrix;

        Quaternion(float X, float Y, float Z, float W){
            x = X, y=Y; z=Z; w=W;
            rotMatrix = buildMatrix(x,y,z,w);
        }

        std::array<std::array<float, 4>, 4> buildMatrix(float x, float y, float z, float w){
            return {{{1 - 2*y*y - 2*z*z,   2*x*y - 2*w*z,       2*x*z + 2*w*y,   0},
                     {2*x*y + 2*w*z,       1 - 2*x*x - 2*z*z,   2*y*z - 2*w*x,   0},
                     {2*x*z - 2*w*y,       2*y*z + 2*w*x,       1 - 2*x*x - 2*y*y, 0},
                     {0,                   0,                   0,               1}}};
        }

        Quaternion(){
            x = 0; y = 0; z = 0; w = 1;
            rotMatrix = buildMatrix(x,y,z,w);
        }

        // Default zero rotation.
        static Quaternion identity(){
            return Quaternion(0,0,0,1);
        }

        // Converts from euler (x,y,z) angles to a Quaternion.
        static Quaternion Euler(Vector3 angles){

            float cosX = cos((angles.x/2.0f)* PI/180);
            float sinX = sin((angles.x/2.0f)* PI/180);
            float cosY = cos((angles.y/2.0f)* PI/180);
            float sinY = sin((angles.y/2.0f)* PI/180);
            float cosZ = cos((angles.z/2.0f)* PI/180);
            float sinZ = sin((angles.z/2.0f)* PI/180);


            float X = cosX * cosY * cosZ + sinX * sinY * sinZ;
            float Y = cosX * cosY * sinZ - sinX * sinY * cosZ;
            float Z = cosX * sinY * cosZ + sinX * cosY * sinZ;
            float W = sinX * cosY * cosZ - cosX * sinY * sinZ;
            return Quaternion(X,Y,Z,W);

        }

        // Converts from euler (x,y,z) angles to a Quaternion.
        static Quaternion Euler(float Xa, float Ya, float Za){

            float cosX = cos((Xa/2.0f)* PI/180);
            float sinX = sin((Xa/2.0f)* PI/180);
            float cosY = cos((Ya/2.0f)* PI/180);
            float sinY = sin((Ya/2.0f)* PI/180);
            float cosZ = cos((Za/2.0f)* PI/180);
            float sinZ = sin((Za/2.0f)* PI/180);


            float X = cosX * cosY * cosZ + sinX * sinY * sinZ;
            float Y = cosX * cosY * sinZ - sinX * sinY * cosZ;
            float Z = cosX * sinY * cosZ + sinX * cosY * sinZ;
            float W = sinX * cosY * cosZ - cosX * sinY * sinZ;
            return Quaternion(X,Y,Z,W);

        }

        // Converts from a Axis and angle to Quaternion.
        static Quaternion AxisAngle(Vector3 axis, float angle){
            Vector3 unitAxis = axis.normalized();
            return Quaternion(unitAxis.x * sin((angle * PI/180)/2),
                              unitAxis.y * sin((angle * PI/180)/2),
                              unitAxis.z * sin((angle * PI/180)/2),
                              cos((angle * PI/180)/2));
        }

        void PrintValues(){
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    std::cout << ("%.3f", rotMatrix[i][j]);
                    std::cout << ("        |        ");
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            std::cout << ("%.2f", x); std::cout << "   ";
            std::cout << ("%.2f", y); std::cout << "   ";
            std::cout << ("%.2f", z); std::cout << "   ";
            std::cout << ("%.2f", w);
        }

        // Rotates Vector3 by the rotation matrix.
        Vector3 operator*(Vector3 vector){
            Vector3 rotatedVector = Vector3(0,0,0);
            rotatedVector.x = rotMatrix[0][0] * vector.x +
                              rotMatrix[0][1] * vector.y +
                              rotMatrix[0][2] * vector.z;
            rotatedVector.y = rotMatrix[1][0] * vector.x +
                              rotMatrix[1][1] * vector.y +
                              rotMatrix[1][2] * vector.z;
            rotatedVector.z = rotMatrix[2][0] * vector.x +
                              rotMatrix[2][1] * vector.y +
                              rotMatrix[2][2] * vector.z;
            return rotatedVector;
        }

        // Quaternions can be added by multiplying the matrix of each one
        Quaternion operator*(Quaternion addQuat){
            return Quaternion(w * addQuat.x + x * addQuat.w + y * addQuat.z - z * addQuat.y, // W
                              w * addQuat.y + y * addQuat.w + z * addQuat.x - x * addQuat.z, // X
                              w * addQuat.z + z * addQuat.w + x * addQuat.y - y * addQuat.x, // Y
                              w * addQuat.w - x * addQuat.x - y * addQuat.y - z * addQuat.z);// Z

            //rotMatrix = multiplyMatrix(rotMatrix, addQuat.rotMatrix);
        }
};
*/
#endif
