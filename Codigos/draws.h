// Desenho do jogo
void desenhaMinhaCena()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Atualizar a faseAtual
    faseAtual(); 

    // Movimentar as fases e sumir com as setas nos limites esquerda e direita
    if (ponto_0_wallpaper > (fase - 0.01) && ponto_0_wallpaper < (fase + 0.01));

    else if(ponto_0_wallpaper>fase)
    {
        move_wallpaper_direita();
    }

    else if(ponto_0_wallpaper<fase)
    {
        move_wallpaper_esquerda();
    }

    drawObject(wallPaper);

    // Menu
    if(tela == 0)
    {
        // Desenhar os objetos e imagens
        drawObject(jogar);
        drawObject(opcoes);
        drawObject(creditos);
        drawObject(saida);
        drawObject(titulo);
        drawObject(mario);
        drawObject(kamek);
    }

    // Tela do Jogo
    else if(tela == 1)
    {
        //Desenhar os objetos e imagens
        drawPlacar(set1);
        drawPlacar(set2);
        drawPlacar(pontos1);
        drawPlacar(pontos2);
        drawObject(bar1);
        drawObject(bar2);

        // Desenhar o reizinho em quem estiver ganhando
    	if(vencedorMomento() != 0)
    	{
    		estrela.frequencia_animacao+=0.5;
    		posAtualEstrela();
    		drawObjectA(estrela);
    	}

    	// Desenhar o placar das dezenas e dos deuces
        if(dezena1.pontos == 1)
        {
            drawPlacar(dezena1);
        }

        if(dezena2.pontos == 1)
        {
            drawPlacar(dezena2);
        }

        if(deuce1.pontos == 1)
        {
            drawPlacar(deuce1);
        }

        if(deuce2.pontos == 1)
        {
            drawPlacar(deuce2);
        }
    	
    	// Desenhando bola
    	drawObjectA(ball);
    	ball.frequencia_animacao += 0.4;

    	// Desenhando eventos de vencedor
        if(set1.pontos == tipoJogo)
        {
    	   	winner(Player1);
        	resetAll();
    	   	drawObject(vencedor);
    	   	glutSwapBuffers();
    	   	sleep(2);
    	   	tela = 0;
        }

        else if(set2.pontos == tipoJogo)
        {
    	   	winner(Player2);
        	resetAll();
    	   	drawObject(vencedor);
    	   	glutSwapBuffers();
    	   	sleep(2);
    	   	tela = 0;
        }

		// Desenhando Switch (Troca de lados)
		if(switch_rodando() > 0)
		{
			Switch();
		}


		// Determinar matchpoints e setpoints
        if(pontos1.pontos != pontos2.pontos)
        {
        	if(pontos1.pontos == 10)
        	{
        		if(set1.pontos + 1 == tipoJogo)
				{
        			matchPoint(Player1);
        			drawObject(match);
        		}

     			else
                {
        			setPoint(Player1);
        			drawObject(setP);
        		}
        	}

            else if(pontos2.pontos == 10)
            {		
        		if(set2.pontos + 1 == tipoJogo)
                {
        			matchPoint(Player2);
        			drawObject(match);
        		}

                else
                {
        			setPoint(Player2);
        			drawObject(setP);
        		}
        	}
        }
    	
    	// Determinar deuce combinados com matchpoint e setpoints
        if(deuce1.pontos == deuce2.pontos && pontos1.pontos == pontos2.pontos && pontos1.pontos == 10)
        {
			drawObject(deuce);
        }

        else if(deuce1.pontos == 1)
        {
        	if(set1.pontos + 1 == tipoJogo)
            {
        		matchPoint(Player1);
        		drawObject(match);
        	}

            else
            {
        		setPoint(Player1);
        		drawObject(setP);
        	}
        }

    	else if(deuce2.pontos == 1)
        {
        	if(set2.pontos + 1 == tipoJogo)
            {
        		matchPoint(Player2);
        		drawObject(match);
        	}

            else
            {
        		setPoint(Player2);
        		drawObject(setP);
        	}
        }

        // Reset e Exit
        if(reset == 1 || sair == 1)
        {
            if(pause % 2 == 0)
            {
                pause++;
            }

            if(reset == 1 && sair == 0)
            {
                drawObject(confirmation_reset);
            }

            if(sair == 1)
            {
                drawObject(confirmation_sair);
            }

            drawObject(yes);
            drawObject(no);
        }

        if(pause % 2 != 0 && reset != 1 && sair != 1)
        {
            // Pausar
            drawObject(pausado);
        }
    }

    // Tela de Opcoes
    else if(tela == 2)
    {
    	drawObject(titulo);
        drawObject(mario);
        drawObject(kamek);
    	drawObject(menu);
    	drawObject(sets);
    	drawObject(set_1);
    	drawObject(set_3);
    	drawObject(set_5);
    	drawObject(set_7);
    	drawObject(set_9);

    	if(ponto_0_wallpaper > (4 - 0.01) && ponto_0_wallpaper < (4 + 0.01));

    	else
    	{
    		drawObject(seta_direita);
    	}

    	if(ponto_0_wallpaper > (1 - 0.01) && ponto_0_wallpaper < (1 + 0.01));

    	else
    	{
    		drawObject(seta_esquerda);
    	}
    }

    // Tela de Creditos
    else if(tela == 3)
    {
    	drawObject(titulo);
        drawObject(mario);
        drawObject(kamek);
    	drawObject(iagor);
        drawObject(iagor_foto);
        drawObject(eduardo);
        drawObject(eduardo_foto);
        drawObject(menu);
    }

    glutSwapBuffers();
}


// Desenha os placares
void drawPlacar(spriteScore objeto)
{

    // Inicio da textura
    float ponto_0 = objeto.proporcaoSprite*(objeto.pontos%10);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, objeto.textura);

    glPushMatrix();
    glTranslatef(objeto.posicao.x, objeto.posicao.y, 0);

    glBegin(GL_TRIANGLE_FAN);
    {
        glTexCoord2f(ponto_0, 0);
        glVertex3f(-objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(objeto.proporcaoSprite+ponto_0, 0);
        glVertex3f( objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(objeto.proporcaoSprite+ponto_0, 1);
        glVertex3f( objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
        glTexCoord2f(ponto_0, 1);
        glVertex3f(-objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
    }

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

//Desenha os objetos e imagens
void drawObject(spriteObject objeto)
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, objeto.textura);

    glPushMatrix();
    glTranslatef(objeto.posicao.x, objeto.posicao.y, 0);

    glBegin(GL_TRIANGLE_FAN);
    {
        glTexCoord2f(0, 0);
        glVertex3f(-objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(1, 0);
        glVertex3f( objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(1, 1);
        glVertex3f( objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
        glTexCoord2f(0, 1);
        glVertex3f(-objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
    }

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

//Desenha objetos animados
void drawObjectA(spriteOb_Animado_s objeto)
{

    // Inicio da textura
    int aux = (int)objeto.frequencia_animacao % (int)(1/objeto.proporcaoSprite);
    float ponto_0 = objeto.proporcaoSprite*aux;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, objeto.textura);

    glPushMatrix();
    glTranslatef(objeto.posicao.x, objeto.posicao.y, 0);

    glBegin(GL_TRIANGLE_FAN);
    {
        glTexCoord2f(ponto_0, 0);
        glVertex3f(-objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(objeto.proporcaoSprite+ponto_0, 0);
        glVertex3f( objeto.dimensoes.x/2, -objeto.dimensoes.y/2,  0);
        glTexCoord2f(objeto.proporcaoSprite+ponto_0, 1);
        glVertex3f( objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
        glTexCoord2f(ponto_0, 1);
        glVertex3f(-objeto.dimensoes.x/2,  objeto.dimensoes.y/2,  0);
    }

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}