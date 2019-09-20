// Função de carregar texturas
GLuint loadTexture(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(arquivo, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

    if (idTextura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}


// Reshape
void redimensionada(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, largura, 0.0, altura, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Atualiza a cena
void refresh(int delay)
{
    // Redesenha
    glutPostRedisplay();

    // Só movimentar se estiver fora de pause/exit/reset
    if(pause % 2 == 0 && reset != 1 && sair != 1)
    {
        //Manter a bola em movimento e movimentar as barras
    	if(bola_dormindo() <= 0)
            moveBall();

        
        moveBar();
    }

    // Registra a callback novamente
    glutTimerFunc(delay, refresh, delay);
}