void PrepareRenderer()
{
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Render(Model* model)
{
    glBindVertexArray(model->vaoID);
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model->vertexCount, GL_UNSIGNED_INT, 0); 
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}