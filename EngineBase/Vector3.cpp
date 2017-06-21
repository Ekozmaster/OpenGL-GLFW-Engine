#include"Vector3.hpp"

Vector3::Vector3(float X, float Y, float Z) {
    x = X;
    y = Y;
    z = Z;
};

Vector3::Vector3(){
}

void Vector3::PrintCoords(){
    printf("X: %f  Y: %f  Z: %f\n", x, y, z);
}
// Overriding primitive operators to work with vector3
// Sum of Vectors
Vector3 Vector3::operator+(Vector3 otherVector3){
    return Vector3(x + otherVector3.x, y + otherVector3.y, z + otherVector3.z);
}
void Vector3::operator+=(Vector3 otherVector3){
    x = x + otherVector3.x;
    y = y + otherVector3.y;
    z = z + otherVector3.z;
}
Vector3 Vector3::operator+(){
    return *this;
}
// Sub of Vectors
Vector3 Vector3::operator-(Vector3 otherVector3){
    return Vector3(x - otherVector3.x, y - otherVector3.y, z - otherVector3.z);
}
void Vector3::operator-=(Vector3 otherVector3){
    x = x - otherVector3.x;
    y = y - otherVector3.y;
    z = z - otherVector3.z;
}
Vector3 Vector3::operator-(){
    return Vector3(-x, -y, -z);
}
// Product of vectors
Vector3 Vector3::operator*(Vector3 otherVector3){
    return Vector3(x * otherVector3.x, y * otherVector3.y, z * otherVector3.z);
}
void Vector3::operator*=(Vector3 otherVector3){
    x = x * otherVector3.x;
    y = y * otherVector3.y;
    z = z * otherVector3.z;
}
// division of vectors (otherVector3 can't have any component = 0)
Vector3 Vector3::operator/(Vector3 otherVector3){
    return Vector3(x / otherVector3.x, y / otherVector3.y, z / otherVector3.z);
}
void Vector3::operator/=(Vector3 otherVector3){
    x = x * otherVector3.x;
    y = y * otherVector3.y;
    z = z * otherVector3.z;
}

Vector3 Vector3::operator*(float scalar){
    return Vector3(x * scalar, y*scalar, z*scalar);
}
void Vector3::operator*=(float scalar){
    x = x * scalar;
    y = y * scalar;
    z = z * scalar;
}

bool Vector3::operator==(Vector3 otherVector3){
    return (otherVector3.x == x && otherVector3.y == y && otherVector3.z == z);
}

bool Vector3::operator!=(Vector3 otherVector3){
    return (otherVector3.x != x || otherVector3.y != y || otherVector3.z != z);
}

float Vector3::Lenght(){
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalized(){
    float lenght = Lenght();
    return Vector3(x/lenght, y/lenght, z/lenght);
}

Vector3 Vector3::up(){
    return Vector3(0, 1, 0);
}
Vector3 Vector3::down(){
    return Vector3(0, -1, 0);
}
Vector3 Vector3::left(){
    return Vector3(-1, 0, 0);
}
Vector3 Vector3::right(){
    return Vector3(1, 0, 0);
}
Vector3 Vector3::forward(){
    return Vector3(0, 0, 1);
}
Vector3 Vector3::back(){
    return Vector3(0, 0, -1);
}
Vector3 Vector3::one(){
    return Vector3(1, 1, 1);
}
Vector3 Vector3::zero(){
    return Vector3(0, 0, 0);
}

float Vector3::Distance(Vector3 vector1, Vector3 vector2){
    return Vector3(vector2 - vector1).Lenght();
}

Vector3 Vector3::Cross(Vector3 vector1, Vector3 vector2){
    return Vector3(vector1.y*vector2.z - vector1.z*vector2.y,
                   vector1.z*vector2.x - vector1.x*vector2.z,
                   vector1.x*vector2.y - vector1.y*vector2.x);
}
float Vector3::Dot(Vector3 vector1, Vector3 vector2){
    return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z;
}

