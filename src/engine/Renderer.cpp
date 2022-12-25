void PrepareRenderer()
{
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Render(Model* model)
{
    glBindVertexArray(model->vaoID);
    glEnableVertexAttribArray(0);
 //    glDrawArrays(GL_TRIANGLES, 0, model->vertexCount); 
   glDisableVertexAttribArray(0);
}