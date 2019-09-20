// Inicializa comandos essenciais
void setup()
{
    // Cor do fundo
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Habilita a utilização de texturas
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);

    // Desativando a opção de repetir uma tecla quando ela é continua apertada
    glutSetKeyRepeat(0);

    // Startando barras e bola centralizados
    resetBar();
    resetBall();

	// Startando Máquinas de Estado
	spd = 10;
	pause = 0;
	reset = 0;
	sair = 0;
	lugarJogadores = 0;
	segundos_sleep = 0;
	timer_switch = 0;
	tipoJogo = 3;
    fase = 1;    
    void faseAtual(); // Setando ponto_0_wallpaper inicial

    // Dimensões e Posições dos objetos iniciais
    set1.pontos = 0;
    set1.posicao.x = 3*posIdealx*largura;
    set1.posicao.y = altura-posIdealy*altura;
    set1.dimensoes.x = tamIdealx*largura;
    set1.dimensoes.y = tamIdealy*altura;
    set1.textura = loadTexture("../imagens/gray.png");
    set1.proporcaoSprite = 0.1;

    dezena1.pontos = 0;
    dezena1.posicao.x = 5*posIdealx*largura;
    dezena1.posicao.y = altura-posIdealy*altura;
    dezena1.dimensoes.x = tamIdealx*largura;
    dezena1.dimensoes.y = tamIdealy*altura;
    dezena1.textura = loadTexture("../imagens/blue.png");
    dezena1.proporcaoSprite = 0.1;

    pontos1.pontos = 0;
    pontos1.posicao.x = 7*posIdealx*largura;
    pontos1.posicao.y = altura-posIdealy*altura;
    pontos1.dimensoes.x = tamIdealx*largura;
    pontos1.dimensoes.y = tamIdealy*altura;
    pontos1.textura = loadTexture("../imagens/blue.png");
    pontos1.proporcaoSprite = 0.1;

    deuce1.pontos = 0;
    deuce1.posicao.x = 9*posIdealx*largura;
    deuce1.posicao.y = altura-posIdealy*altura*2;
    deuce1.dimensoes.x = tamIdealx*largura*(3/4.0);
    deuce1.dimensoes.y = tamIdealy*altura;
    deuce1.textura = loadTexture("../imagens/+1_blue.png");
    deuce1.proporcaoSprite = 0.5; 

    set2.pontos = 0;
    set2.posicao.x = largura-7*posIdealx*largura;
    set2.posicao.y = altura-posIdealy*altura;
    set2.dimensoes.x = tamIdealx*largura;
    set2.dimensoes.y = tamIdealy*altura;
    set2.textura = loadTexture("../imagens/gray.png");
    set2.proporcaoSprite = 0.1;

    dezena2.pontos=0;
    dezena2.posicao.x=largura-5*posIdealx*largura;
    dezena2.posicao.y=altura-posIdealy*altura;
    dezena2.dimensoes.x=tamIdealx*largura;
    dezena2.dimensoes.y=tamIdealy*altura;
    dezena2.textura=loadTexture("../imagens/red.png");
    dezena2.proporcaoSprite=0.1;

    pontos2.pontos = 0;
    pontos2.posicao.x = largura-3*posIdealx*largura;
    pontos2.posicao.y = altura-posIdealy*altura;
    pontos2.dimensoes.x = tamIdealx*largura;
    pontos2.dimensoes.y = tamIdealy*altura;
    pontos2.textura = loadTexture("../imagens/red.png");
    pontos2.proporcaoSprite = 0.1;

    deuce2.pontos = 0;
    deuce2.posicao.x = largura-posIdealx*largura;
    deuce2.posicao.y = altura-posIdealy*altura*2;
    deuce2.dimensoes.x = tamIdealx*largura;
    deuce2.dimensoes.y = tamIdealy*altura;
    deuce2.textura = loadTexture("../imagens/+1_red.png");
    deuce2.proporcaoSprite = 0.5; 

	estrela.dimensoes.x = (1/15.0)*largura;
	estrela.dimensoes.y = (1/10.0)*altura;
	estrela.textura = loadTexture("../imagens/star.png");
	estrela.proporcaoSprite = 1/23.0;
	estrela.frequencia_animacao = 0;
	estrela.movimento.x=0;
	estrela.movimento.y=0;

	vencedor.dimensoes.x = (4/9.0)*largura;
	vencedor.dimensoes.y = (2/3.0)*altura;
	vencedor.posicao.x = largura/2;
	vencedor.posicao.y = altura/2;
	vencedor.movimento.x = 0;
	vencedor.movimento.y = 0;

	deuce.dimensoes.x = 3*tamIdealx*largura;
	deuce.dimensoes.y = (2.0/6.0)*tamIdealy*altura;
	deuce.posicao.x = largura/2;
	deuce.posicao.y = altura - ((2.0/1.1)*tamIdealy*altura)/2;
	deuce.movimento.x = 0;
	deuce.movimento.y = 0;
	deuce.textura = loadTexture("../imagens/Deuce.png");

	match.dimensoes.x = 3*tamIdealx*largura;
	match.dimensoes.y = (2.0/6.0)*tamIdealy*altura;
    match.posicao.x = 12*posIdealx*largura;
    match.posicao.y = altura - (2.0/1.1)*tamIdealy*altura/2;
    match.movimento.x = 0;
    match.movimento.y = 0;

	kamek_voador.posicao.x = 0;
	kamek_voador.posicao.y = (1/8.0)*altura;
	kamek_voador.dimensoes.x = (1/4.0)*altura;
	kamek_voador.dimensoes.y = (1/4.0)*altura;
	kamek_voador.movimento.x = spd*1.2;
	kamek_voador.movimento.y = 0;

	mario_voador.posicao.x = largura;
	mario_voador.posicao.y = (3/8.0)*altura;
	mario_voador.dimensoes.x = (1/3.0)*altura;
	mario_voador.dimensoes.y = (1/4.0)*altura;
	mario_voador.movimento.x = spd*1.2;
	mario_voador.movimento.y = 0;
	mario_voador.frequencia_animacao = 0;
	mario_voador.proporcaoSprite = 1/4.0;

	switch_player.posicao.x = largura/2;
	switch_player.posicao.y = altura/2 + altura/6;
	switch_player.dimensoes.x = largura/2;
	switch_player.dimensoes.y = altura/6;
	switch_player.movimento.x = 0;
	switch_player.movimento.y = 0;
	switch_player.textura = loadTexture("../imagens/Switch.png");

    setP.dimensoes.x = 3*tamIdealx*largura;
    setP.dimensoes.y = (2.0/6.0)*tamIdealy*altura;
    setP.posicao.x = 12*posIdealx*largura;
    setP.posicao.y = altura - ((2.0/1.1)*tamIdealy*altura)/2;
    setP.movimento.x = 0;
    setP.movimento.y = 0;
	
    bar1.dimensoes.x = largura/60;
    bar1.dimensoes.y = altura/4;
    bar1.textura = loadTexture("../imagens/blue_brick.png");

    bar2.dimensoes.x = largura/60 ;
    bar2.dimensoes.y = altura/4 ;
    bar2.textura = loadTexture("../imagens/red_brick.png");

    ball.dimensoes.x = largura/30;
    ball.dimensoes.y = altura/20;
    ball.movimento.x = spd;
    ball.movimento.y = spd;
	ball.frequencia_animacao = 0;
	ball.proporcaoSprite = 1/8.0;
    ball.textura = loadTexture("../imagens/shell_animado_purple.png");

    wallPaper.dimensoes.x = largura*4;
    wallPaper.dimensoes.y = altura;
    wallPaper.posicao.x = (largura*4)/2;
    wallPaper.posicao.y = altura/2;
    wallPaper.movimento.x = spd;
    wallPaper.movimento.y = 0;
    wallPaper.textura = loadTexture("../imagens/4_fases.png");

    confirmation_sair.dimensoes.x = largura/4;
    confirmation_sair.dimensoes.y = altura/14;
    confirmation_sair.posicao.x = largura/2;
    confirmation_sair.posicao.y = altura/2 + altura/10;
    confirmation_sair.textura = loadTexture("../imagens/confirmacao_sair.png");

    confirmation_reset.dimensoes.x = largura/4;
    confirmation_reset.dimensoes.y = altura/14;
    confirmation_reset.posicao.x = largura/2;
    confirmation_reset.posicao.y = altura/2 + altura/10;
    confirmation_reset.textura = loadTexture("../imagens/confirmacao_reset.png");

    yes.dimensoes.x = largura/12;
    yes.dimensoes.y = altura/16;
    yes.posicao.x = largura/2 - largura/20;
    yes.posicao.y = altura/2;
    yes.textura = loadTexture("../imagens/sim.png");

    no.dimensoes.x = largura/12;
    no.dimensoes.y = altura/16;
    no.posicao.x = largura/2 + largura/20;
    no.posicao.y = altura/2;
    no.textura = loadTexture("../imagens/nao.png");

    pausado.dimensoes.x = largura/6;
    pausado.dimensoes.y = altura/14;
    pausado.posicao.x = largura/2;
    pausado.posicao.y = altura/2 + altura/10;
    pausado.textura = loadTexture("../imagens/pause.png");

    jogar.dimensoes.x = largura/6;
    jogar.dimensoes.y = altura/14;
    jogar.posicao.x = largura/2;
    jogar.posicao.y = altura/2 + altura/8;
    jogar.textura = loadTexture("../imagens/Jogar.png");

    opcoes.dimensoes.x = largura/6;
    opcoes.dimensoes.y = altura/14;
    opcoes.posicao.x = largura/2;
    opcoes.posicao.y = altura/2;
    opcoes.textura = loadTexture("../imagens/Opcoes.png");

    creditos.dimensoes.x = largura/6;
    creditos.dimensoes.y = altura/14;
    creditos.posicao.x = largura/2;
    creditos.posicao.y = altura/2 - altura/8;
    creditos.textura = loadTexture("../imagens/Creditos.png");

    saida.dimensoes.x = largura/10;
    saida.dimensoes.y = altura/14;
    saida.posicao.x = largura/2;
    saida.posicao.y = altura/2 - altura/4;
    saida.textura = loadTexture("../imagens/Sair.png");

    titulo.dimensoes.x = largura/2;
    titulo.dimensoes.y = altura/8;
    titulo.posicao.x = largura/2;
    titulo.posicao.y = altura/2 + altura/3;
    titulo.textura = loadTexture("../imagens/mario_pong.png");

    mario.dimensoes.x = largura/4;
    mario.dimensoes.y = altura/4;
    mario.posicao.x = largura/6;
    mario.posicao.y = altura/2 + altura/8;
    mario.textura = loadTexture("../imagens/mario_flying.png");

    kamek.dimensoes.x = largura/3;
    kamek.dimensoes.y = altura/5;
    kamek.posicao.x = largura/2 + largura/3;
    kamek.posicao.y = altura/2 - altura/10;
    kamek.textura = loadTexture("../imagens/kamek_flying.png");

    iagor.dimensoes.x = largura/3;
    iagor.dimensoes.y = altura/16;
    iagor.posicao.x = largura/2;
    iagor.posicao.y = altura/2 + altura/8;
    iagor.textura = loadTexture("../imagens/Iagor.png");

    iagor_foto.dimensoes.x = largura/7;
    iagor_foto.dimensoes.y = altura/7;
    iagor_foto.posicao.x = largura - largura/4;
    iagor_foto.posicao.y = altura/2 + altura/8;
    iagor_foto.textura = loadTexture("../imagens/Iagor_foto.png");

    eduardo.dimensoes.x = largura/3;
    eduardo.dimensoes.y = altura/16;
    eduardo.posicao.x = largura/2;
    eduardo.posicao.y = altura/2 - altura/8;
    eduardo.textura = loadTexture("../imagens/Eduardo.png");

    eduardo_foto.dimensoes.x = largura/7;
    eduardo_foto.dimensoes.y = altura/7;
    eduardo_foto.posicao.x = largura/2 - largura/4;
    eduardo_foto.posicao.y = altura/2 - altura/8;
    eduardo_foto.textura = loadTexture("../imagens/Eduardo_foto.png");

    menu.dimensoes.x = largura/10;
    menu.dimensoes.y = altura/16;
    menu.posicao.x = largura/2;
    menu.posicao.y = altura/2 - altura/3;
    menu.textura = loadTexture("../imagens/Menu.png");

    sets.dimensoes.x = largura/10;
    sets.dimensoes.y = altura/16;
    sets.posicao.x = largura/2;
    sets.posicao.y = altura/2 + altura/6;
    sets.textura = loadTexture("../imagens/Sets.png");

    set_1.dimensoes.x = largura/14;
    set_1.dimensoes.y = altura/14;
    set_1.posicao.x = largura/3;
    set_1.posicao.y = altura/2 + altura/18;
    set_1.textura = loadTexture("../imagens/1set.png");

    set_3.dimensoes.x = largura/14;
    set_3.dimensoes.y = altura/14;
    set_3.posicao.x = largura/2;
    set_3.posicao.y = altura/2 + altura/18;
    set_3.textura = loadTexture("../imagens/3set_preto.png");

    set_5.dimensoes.x = largura/14;
    set_5.dimensoes.y = altura/14;
    set_5.posicao.x = largura/2 + largura/6;
    set_5.posicao.y = altura/2 + altura/18;
    set_5.textura = loadTexture("../imagens/5set.png");

    set_7.dimensoes.x = largura/14;
    set_7.dimensoes.y = altura/14;
    set_7.posicao.x = largura/2 - largura/12;
    set_7.posicao.y = altura/2 - altura/14;
    set_7.textura = loadTexture("../imagens/7set.png");

    set_9.dimensoes.x = largura/14;
    set_9.dimensoes.y = altura/14;
    set_9.posicao.x = largura/2 + largura/12;
    set_9.posicao.y = altura/2 - altura/14;
    set_9.textura = loadTexture("../imagens/9set.png");

    seta_direita.dimensoes.x = largura/14;
    seta_direita.dimensoes.y = altura/14;
    seta_direita.posicao.x = largura/2 + largura/16;
    seta_direita.posicao.y = altura/2 - altura/5;
    seta_direita.textura = loadTexture("../imagens/Seta_direita.png");

    seta_esquerda.dimensoes.x = largura/14;
    seta_esquerda.dimensoes.y = altura/14;
    seta_esquerda.posicao.x = largura/2 - largura/16;
    seta_esquerda.posicao.y = altura/2 - altura/5;
    seta_esquerda.textura = loadTexture("../imagens/Seta_esquerda.png");
}