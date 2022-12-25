

#include "struct.cpp"



Model modelToRender = {};

void MyInit()
{

    AllocateMemoryArena(&modelArena, Megabytes(1));

	DynamicArray<GLuint> vaos = MakeDynamicArray<GLuint>(&modelArena, 1000);
    DynamicArray<GLuint> vbos = MakeDynamicArray<GLuint>(&modelArena, 1000);
    
    real32 vertices[] = {
     -0.5f, 0.5f, 0,
    -0.5f, -0.5f, 0,
     0.5f, -0.5f, 0,
     0.5f, -0.5f, 0,
    0.5f, 0.5f, 0,
    -0.5f, 0.5f, 0
  };

    LoadToVAO(&modelToRender, vertices, 18, vaos, vbos);
    CleanUp(vaos, vbos);
}

void MyGameUpdate()
{
    // render a box

    PrepareRenderer();
   // Render(&modelToRender);
}