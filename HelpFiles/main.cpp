/*#include <GL/glew.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include <stdio.h>
GLfloat cube[] = {
     0.0f,  0.5f, // Vertex 1 (X, Y)
     0.5f, -0.5f, // Vertex 2 (X, Y)
    -0.5f, -0.5f  // Vertex 3 (X, Y)
};
/*
GLfloat cube[] = {
    -0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f,  0.5f
};
//*/
/*
static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_P){
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }
}

const GLchar *vertexSource = 
//"glsl("
"#version 130\n"
"in vec3 position;\n"
"mat4 trans;\n"
"void main(){\n"
"    gl_Position = trans * vec4(position, 1.0);\n"
"}\n";
//")";

const GLchar *fragmentSource =
"#version 130\n"
"out vec4 outColor;\n"
"void main(){\n"
"    outColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
"}\n";

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;


    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, KeyCallback);
    glewInit();


    // Setting a VAO to link VBO properties to GLSL attributes.
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Creating a VBO to store the cube.
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);


    // Baking Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, 0);
    glCompileShader(vertexShader);
    // Checking if shader compiled Successfully.
    GLint status;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        printf("Fucking Vertex Crashed...\n");
        char buffer[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(EXIT_FAILURE);
    }


    // Baking Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, 0);
    glCompileShader(fragmentShader);
    // Checking if shader compiled Successfully.
    status = GL_TRUE;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        printf("Fucking Fragment Crashed...\n");
        exit(EXIT_FAILURE);
    }



    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glBindFragDataLocation(shaderProgram, 0, "outColor");

    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);


    

    //#####################
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);





    GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
    glm::mat4 trans;
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        trans = glm::rotate(trans, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));

        //glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
        glDrawArrays(GL_TRIANGLES, 0, 3);

        
        /*
        glVertexPointer(3, GL_FLOAT, 0, cube);
        glColorPointer(4, GL_FLOAT, 0, colors);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        //*/
        


/*
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
//*/
