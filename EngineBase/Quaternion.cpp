#include"Quaternion.hpp"

Quaternion::Quaternion(float X, float Y, float Z, float W){
    x = X, y=Y; z=Z; w=W;
    rotMatrix = buildMatrix(x,y,z,w);
};

std::array<std::array<float, 4>, 4> Quaternion::buildMatrix(float X, float Y, float Z, float W){
    //Vector3 vec = Vector3(X,Y,Z) * sin;

    return {{{1 - 2*Y*Y - 2*Z*Z,   2*X*Y - 2*W*Z,       2*X*Z + 2*W*Y,   0},
             {2*X*Y + 2*W*Z,       1 - 2*X*X - 2*Z*Z,   2*Y*Z - 2*W*X,   0},
             {2*X*Z - 2*W*Y,       2*Y*Z + 2*W*X,       1 - 2*X*X - 2*Y*Y, 0},
             {0,                   0,                   0,               1}}};
};

Quaternion::Quaternion(){
    x = 0; y = 0; z = 0; w = 1;
    rotMatrix = buildMatrix(x,y,z,w);
};

glm::quat Quaternion::ToGLMQuat(){
    return glm::quat(w, x, y, z);
};

glm::mat4 Quaternion::ToGLMMat4(){
    return glm::mat4_cast(this->ToGLMQuat());
};

// Default zero rotation.
Quaternion Quaternion::identity(){
    return Quaternion(0,0,0,1);
};

// Converts from euler (x,y,z) angles to a Quaternion.
Quaternion Quaternion::Euler(Vector3 angles){
    /*
    float cosX = cos((angles.x/2.0f)* PI/180);
    float sinX = sin((angles.x/2.0f)* PI/180);
    float cosY = cos((angles.y/2.0f)* PI/180);
    float sinY = sin((angles.y/2.0f)* PI/180);
    float cosZ = cos((angles.z/2.0f)* PI/180);
    float sinZ = sin((angles.z/2.0f)* PI/180);
    //*/

    float c1 = cos((angles.y / 2) * PI/180);
    float c2 = cos((angles.x / 2) * PI/180);
    float c3 = cos((angles.z / 2) * PI/180);
    float s1 = sin((angles.y / 2) * PI/180);
    float s2 = sin((angles.x / 2) * PI/180);
    float s3 = sin((angles.z / 2) * PI/180);

    /*
    float X = cosX * cosY * cosZ + sinX * sinY * sinZ;
    float Y = cosX * cosY * sinZ - sinX * sinY * cosZ;
    float Z = cosX * sinY * cosZ + sinX * cosY * sinZ;
    float W = sinX * cosY * cosZ - cosX * sinY * sinZ;
    */

    float W = c1 * c2 * c3 - s1 * s2 * s3;
    float X = s1 * s2 * c3 + c1 * c2 * s3;
    float Y = s1 * c2 * c3 + c1 * s2 * s3;
    float Z = c1 * s2 * c3 - s1 * c2 * s3;

    return Quaternion(X,Y,Z,W);

};

// Converts from euler (x,y,z) angles to a Quaternion.
Quaternion Quaternion::Euler(float Xa, float Ya, float Za){
    float c1 = cos((Ya / 2) * PI/180);
    float c2 = cos((Za / 2) * PI/180);
    float c3 = cos((Xa / 2) * PI/180);
    float s1 = sin((Ya / 2) * PI/180);
    float s2 = sin((Za / 2) * PI/180);
    float s3 = sin((Xa / 2) * PI/180);


    float W = c1 * c2 * c3 - s1 * s2 * s3;
    float X = s1 * s2 * c3 + c1 * c2 * s3;
    float Y = s1 * c2 * c3 + c1 * s2 * s3;
    float Z = c1 * s2 * c3 - s1 * c2 * s3;

    return Quaternion(X,Y,Z,W);
};

// Converts from a Axis and angle to Quaternion.
Quaternion Quaternion::AxisAngle(Vector3 axis, float angle){
    Vector3 unitAxis = axis.normalized();
    return Quaternion(unitAxis.x * sin((angle * PI/180)/2),
                      unitAxis.y * sin((angle * PI/180)/2),
                      unitAxis.z * sin((angle * PI/180)/2),
                      cos((angle * PI/180)/2));
};

void Quaternion::PrintValues(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%.3f", rotMatrix[i][j]);
            printf("        |        ");
        }
        printf("\n");
    }
    printf("\n");
    printf("%.2f", x); printf("   ");
    printf("%.2f", y); printf("   ");
    printf("%.2f", z); printf("   ");
    printf("%.2f", w);
};

// Rotates Vector3 by the rotation matrix.
Vector3 Quaternion::operator*(Vector3 vector){
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
};

// Quaternions can be added by multiplying the matrix of each one
Quaternion Quaternion::operator*(Quaternion addQuat){
    return Quaternion(w * addQuat.x + x * addQuat.w + y * addQuat.z - z * addQuat.y, // W
                      w * addQuat.y + y * addQuat.w + z * addQuat.x - x * addQuat.z, // X
                      w * addQuat.z + z * addQuat.w + x * addQuat.y - y * addQuat.x, // Y
                      w * addQuat.w - x * addQuat.x - y * addQuat.y - z * addQuat.z);// Z

    //rotMatrix = multiplyMatrix(rotMatrix, addQuat.rotMatrix);
};
