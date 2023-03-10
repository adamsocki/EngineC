
void bindIndicesBuffer(int32* indices, int32 count, DynamicArray<GLuint> vbos)
{
    GLuint vboID;
    glGenBuffers(1, &vboID);
    PushBack(&vbos, vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int32) * count, indices, GL_STATIC_DRAW);
}


void storeDataInAttributeList(int32 attributeNumber, real32 *data, int32 count, DynamicArray<GLuint> vbos)
{
    GLuint vboID;
    glGenBuffers(1, &vboID);
    PushBack(&vbos, vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * count, data, GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, (void*)0);
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


void LoadToVAO(Model* model, real32* positions, int32 sizeVert, int32* indices, int32 indicesCount, DynamicArray<GLuint> vaos, DynamicArray<GLuint> vbos)
{
    // ** bind VAO
    GLuint vaoID = CreateVAO(vaos);
    model->vaoID = vaoID;
    model->vertexCount = sizeVert;
    // bind Index VBO
    bindIndicesBuffer(indices, indicesCount, vbos);
    storeDataInAttributeList(0, positions, sizeVert, vbos);
    // ** unbind VAO
    UnbindVAO();
}
