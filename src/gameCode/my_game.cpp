

#include "struct.cpp"



Model modelToRender = {};

DynamicArray<GLuint> vaos;
DynamicArray<GLuint> vbos;

void MyInit()
{

    AllocateMemoryArena(&modelArena, Megabytes(1));
    vaos = MakeDynamicArray<GLuint>(&modelArena, 1000);
    vbos = MakeDynamicArray<GLuint>(&modelArena, 1000);
    
    real32 vertices[] = {
    -0.5f, 0.5f, 0,
    -0.5f, -0.5f, 0,
    0.5f, -0.5f, 0,
    0.5f, 0.5f, 0
   };


    int32 indices[] = {
        0,1,3,
        3,1,2
    };

    LoadToVAO(&modelToRender, vertices, 6, indices, 6, vaos, vbos);
}

void MyGameUpdate()
{
    // render a box

    PrepareRenderer();
    Render(&modelToRender);
 //   CleanUp(vaos, vbos);
}


void MyGameClose()
{
    CleanUp(vaos, vbos);
}