
void storeDataInAttributeList(int32 attributeNumber, real32 *data, int32 size, DynamicArray<GLuint> vbos)
{
    GLuint vboID;
    glGenBuffers(1, &vboID);
    PushBack(&vbos, vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID); 
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


GLuint CreateVAO(DynamicArray<GLuint> vaos)
{

    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    PushBack(&vaos, vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}



void UnbindVAO()
{
    glBindVertexArray(0);
}

void CleanUp(DynamicArray<GLuint> vaos, DynamicArray<GLuint> vbos)
{
    for (int i = 0; i < vaos.count; i++)
    {
        glDeleteVertexArrays(1, &vaos[i]);
    }
    for (int i = 0; i < vbos.count; i++)
    {
        glDeleteBuffers(1, &vbos[i]);
    }
}



void LoadToVAO(Model* model, real32* positions, int32 size, DynamicArray<GLuint> vaos, DynamicArray<GLuint> vbos)
{
    // ** bind VAO
    GLuint vaoID = CreateVAO(vaos);
    model->vaoID = vaoID;
    model->vertexCount = size;
    // 
    storeDataInAttributeList(0, positions, size, vbos);
    // ** unbind VAO
    UnbindVAO();
}
