#include"WindowDrawer.hpp"
#include"SceneManager.hpp"
#include"GameObject.hpp"
#include"Mesh.hpp"
#include<GL/glut.h>
#include<fstream>
#include<string>


WindowDrawer::WindowDrawer(int *width, int *height){
    Width = width;
    Height = height;
};

WindowDrawer::WindowDrawer(){
};

void WindowDrawer::RenderFrame(GLFWwindow *window){
    glfwGetFramebufferSize(window, Width, Height);
    glViewport(0, 0, *Width, *Height);
    SetupViewMatrix();
    Camera *cam;

    if(mainCamera == NULL){
        mainCamera = new GameObject();
        mainCamera->AddComponent<Camera>();
    }
    cam = mainCamera->GetComponent<Camera>();
    CamPose(cam);


    ClearScreen();
    //glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);

    glEnableClientState(GL_VERTEX_ARRAY);

    GameObjectNode *temp = SceneManager::Instance()->GetCurrentScene()->activeObjects.head;
    while(temp != NULL){
        MeshRenderer *meshRen = temp->data->GetComponent<MeshRenderer>();
        if(meshRen != NULL){
            GLint uniModel = glGetUniformLocation(shaderProgram, "modelView");
            glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(temp->data->transform.GetTransformMatrix()));
            meshRen->Render();
        }
        temp = temp->next;
    }


    //glVertexPointer(3, GL_FLOAT, 0, 0);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glDisableClientState(GL_VERTEX_ARRAY);

    glfwSwapBuffers(window);
}

void WindowDrawer::SetupViewMatrix(){
    glm::mat4 trans;
    glm::mat4 proj;
    glm::mat4 model;

    GLint uniProj = glGetUniformLocation(shaderProgram, "projection");
    GLint uniTrans = glGetUniformLocation(shaderProgram, "transform");
    GLint uniModel = glGetUniformLocation(shaderProgram, "modelView");

    glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(projMatrix));
    glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
    glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(modelMatrix));
};

void WindowDrawer::CamPose(Camera *cam){
    float aspectRatio = (float)*Width / *Height;
    projMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 1000.0f);
    GLint uniProj = glGetUniformLocation(shaderProgram, "projection");

    Vector3 camPivot = cam->eyePose + cam->pivotPoint;
    projMatrix *= glm::lookAt(glm::vec3(cam->eyePose.x, cam->eyePose.y, cam->eyePose.z),
                              glm::vec3(camPivot.x, camPivot.y, camPivot.z),
                              glm::vec3(cam->upDirection.x, cam->upDirection.y, cam->upDirection.z));

    glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(projMatrix));
};



void WindowDrawer::InitX11OpenGL(){
    glEnable(GL_DEPTH_TEST);
    float aspectRatio = (float)*Width / *Height;
    projMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 1000.0f);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 0.0f));

    //std::ifstream vertexFIle("");
    std::ifstream vertexFile("Shaders/testVertexShader.glsl");
    std::ifstream fragFile("Shaders/testFragmentShader.glsl");

    std::string *content = new std::string((std::istreambuf_iterator<char>(vertexFile)),
                                            std::istreambuf_iterator<char>());
    vertexSource = (GLchar*)content->c_str();
    vertexFile.close();

    content = new std::string((std::istreambuf_iterator<char>(fragFile)),
                               std::istreambuf_iterator<char>());
    fragmentSource = (GLchar*)content->c_str();
    fragFile.close();

    /*
    // Setting a VAO to link VBO properties to GLSL attributes.
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Creating a VBO to store the cube.
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);
    //GLuint elementBuffer;
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeElements), cubeElements, GL_STATIC_DRAW);
    //*/

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
        char buffer[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(EXIT_FAILURE);
    }



    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glBindFragDataLocation(shaderProgram, 0, "outColor");

    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    //#####################
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    //glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glEnableVertexAttribArray(posAttrib);

}


void WindowDrawer::ClearScreen(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


