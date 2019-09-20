// Struct de x e y
typedef struct vetorR2
{
    float x;
    float y;

} vetorR2;

// Objetos não animados
typedef struct spriteObject
{
    vetorR2 posicao;
    vetorR2 dimensoes;
    vetorR2 movimento;
    int textura;

} spriteObject;

// Scores animados
typedef struct spriteScore
{
    vetorR2 posicao;
    vetorR2 dimensoes;
    int pontos;
    int textura;
    double proporcaoSprite;

} spriteScore;

// Objetos animados
typedef struct Objeto_Animado
{
	vetorR2 posicao;
	vetorR2 dimensoes;
	vetorR2 movimento;
	float frequencia_animacao;
	int textura;
	double proporcaoSprite;
} spriteOb_Animado_s;