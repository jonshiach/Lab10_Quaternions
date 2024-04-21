#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"

Camera::Camera(const glm::vec3 position)
{
    this->position = position;
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    return view;
}

glm::mat4 Camera::getProjectionMatrix()
{
    return projection;
}

void Camera::calculateMatrices(GLFWwindow *window, const float deltaTime)
{
    // Keyboard inputs
    if (glfwGetKey(window, GLFW_KEY_W))
        position += front * deltaTime * speed;
    
    if (glfwGetKey(window, GLFW_KEY_S))
        position -= front * deltaTime * speed;
    
    if (glfwGetKey(window, GLFW_KEY_A))
        position -= right * deltaTime * speed;
    
    if (glfwGetKey(window, GLFW_KEY_D))
        position += right * deltaTime * speed;
    
    // Get mouse cursor position
    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);
    glfwSetCursorPos(window, 1024/2, 768/2);
    
    // Update yaw and pitch angles
    yaw += mouseSpeed * deltaTime * float(xPos - 1024/2);
    pitch += mouseSpeed * deltaTime * float(yPos - 768/2);

    // Update camera vectors
    front = glm::normalize(glm::vec3(sin(yaw) * cos(pitch), -sin(pitch), -cos(yaw) * cos(pitch)));
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
    target = position + front;
    
    // Calculate view matrix
    view = glm::lookAt(position, target, up);
    
    // Calculate projection matrix
    projection = glm::perspective(fov, aspect, near, far);
}
