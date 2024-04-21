#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>
#include <cmath>

#include "maths.hpp"

// Convert an angle from degrees to radians
float Maths::radians(const float angle)
{
    return angle * 3.1415927f / 180.0f;
}

// Calculate the norm of a vector
float Maths::norm(const glm::vec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Normalise a vector
glm::vec3 Maths::normalize(const glm::vec3 v)
{
    return v / Maths::norm(v);
}

// Calculate the translation matrix
glm::mat4 Maths::translate(const glm::mat4 mat, const glm::vec3 t)
{
    glm::mat4 T = glm::mat4(1.0f);
    T[3][0] = t.x; T[3][1] = t.y; T[3][2] = t.z;
    
    return T * mat;
}

// Calculate the scaling matrix
glm::mat4 Maths::scale(const glm::mat4 mat, const glm::vec3 s)
{
    glm::mat4 S = glm::mat4(1.0f);
    S[0][0] = s.x; S[1][1] = s.y; S[2][2] = s.z;
    
    return S * mat;
}

// Calculate the rotation matrix
glm::mat4 Maths::rotate(const glm::mat4 mat, const float angle, const glm::vec3 vector)
{
    glm::vec3 v = Maths::normalize(vector);
    float cs = cos(angle);
    float sn = sin(angle);
    
    glm::mat4 R = glm::mat4(1.0f);
    R[0][0] = v.x * v.x * (1 - cs) + cs;
    R[0][1] = v.x * v.y * (1 - cs) + v.z * sn;
    R[0][2] = v.x * v.z * (1 - cs) - v.y * sn;
    R[1][0] = v.y * v.x * (1 - cs) - v.z * sn;
    R[1][1] = v.y * v.y * (1 - cs) + cs;
    R[1][2] = v.y * v.z * (1 - cs) + v.x * sn;
    R[2][0] = v.z * v.x * (1 - cs) + v.y * sn;
    R[2][1] = v.z * v.y * (1 - cs) - v.x * sn;
    R[2][2] = v.z * v.z * (1 - cs) + cs;
    return R * mat;
}
