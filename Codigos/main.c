#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "structs.h"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "cabecalho.h"

// Constantes globais
#define largura 900.0
#define altura 600
#define tamIdealx 1/12.0
#define tamIdealy 1/8.0
#define posIdealx 1/24.0
#define posIdealy 1/10.0
#define Player1 1
#define Player2 2
#define FPS 17.0
#define DELAY_PONT 2
#define DELAY_SET 3
#define TEMPO_TROCA 5
#define FASE_FINAL 4

// Variavéis objetos, ASCII, constante de velocidade, pause, pontuação

spriteObject 	    bar1, bar2, wallPaper, confirmation_sair, confirmation_reset, yes, no, mouse, pausado, vencedor, 
			        match, setP, deuce, jogar, opcoes, creditos, saida, titulo, mario, kamek, kamek_voador, switch_player,
                    iagor, iagor_foto, eduardo, eduardo_foto, menu, sets, set_1, set_3, set_5, set_7, set_9, seta_direita,
                    seta_esquerda; 

spriteScore 	    set1, set2, pontos1,pontos2,dezena1,dezena2, deuce1,deuce2;

spriteOb_Animado_s 	ball, estrela, mario_voador;

int 			    keyboard[256], pause, reset, sair, lugarJogadores, tipoJogo, tela = 0, fase, ultimo_pontuador;

double 			    segundos_sleep, spd, timer_switch, ponto_0_wallpaper;

Mix_Chunk		*som1, *som2, *som3, *som4;

void main(int argc, char** argv)
{

    //Inicialização
    glutInit(&argc, argv);

    //Definindo versão do GLUT
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    //Configurações iniciais da janela GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(100, 100);

    //Inicializando a Janela
    glutCreateWindow("Mario Pong");

    //Seta valores iniciais
    setup();
    srand(time(0));

    // Callbacks
    glutDisplayFunc(desenhaMinhaCena);
    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaSegurada);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mouseClick);
    glutTimerFunc(FPS,refresh,FPS);


    //Loop
    glutMainLoop();
}

#include "draws.h"
#include "setup.h"
#include "keyboard.h"
#include "mouse.h"
#include "movimentos.h"
#include "refresh.h"
#include "pontuacao.h"
#include "resets.h"
#include "sides.h"
#include "events.h"
#include "musicas.h"
