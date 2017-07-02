#include"Scene.hpp"
#include"MeshRenderer.hpp"
#include"../BehaviourScripts/SceneCamera.hpp"
#include"../BehaviourScripts/RotateWithTime.hpp"
#include"GameObject.hpp"
#include"Mesh.hpp"

Scene::Scene(){
}

Scene *Scene::CreateDefaultTestScene(){
    Scene *scene = new Scene();
    //currentScene = new Scene();
    scene->mainCamera = new GameObject();
    scene->mainCamera->AddComponent<Camera>();
    scene->mainCamera->transform.position = Vector3(0, 0, -5.0f);
    scene->mainCamera->AddComponent<SceneCamera>();

    // Creating a default cube.
    GameObject *cb = new GameObject();
    cb->transform.rotation = Quaternion::Euler(0.0f, 0.0f, 0.0f);
    cb->AddComponent<MeshRenderer>();
    cb->AddComponent<RotateWithTime>();
    MeshRenderer *meshRen = cb->GetComponent<MeshRenderer>();
    Mesh *mesh = new Mesh();
    //mesh->vertices = (Vector3 *)malloc(sizeof(Vector3) * 36 * 2);
    mesh->vertices = verts;
    mesh->normals = vertsNormals;

    mesh->triangles = (unsigned int*)cubeElements;
    meshRen->mesh = mesh;
    meshRen->UpdateMeshProperties();

    scene->RegisterObject(cb);
    return scene;
};

int Scene::GetAvailableID(){
    bool found = false;
    int i=0;
    while(!found){
        GameObjectNode * temp = activeObjects.head;
        bool alreadyInList=false;
        while(!alreadyInList && temp != NULL){
            if(temp->data->GetID() != i){
                temp = temp->next;
            } else {
                alreadyInList = true;
                i++;
            }
        }
        if(!alreadyInList){
            return i;
        }
    }return -1;

}
void Scene::RegisterObject(GameObject * object){
    GameObjectNode * node = GameObjectList::NewEmptyNode();
    object->SetID(GetAvailableID());
    node->data = object;
    activeObjects.AddAtTail(node);
}

void Scene::UnregisterObject(int id){
    activeObjects.RemoveById(id);
}

GameObject * Scene::GetObjectByID(int id){
    GameObjectNode * temp = activeObjects.GetById(id);
    return temp != NULL ? temp->data : NULL;
}

void Scene::MainUpdate(){
    int i=0;
    GameObjectNode * temp = activeObjects.head;
    while(i < activeObjects.Count){
        temp->data->UpdateBehaviours();


        i++;
        temp = temp->next;
    }
}

