/*
  Matriz de LEDs 5x5 - Atividade 02 de Microcontroladores UPE/Poli
  Arthur L. Castro
  Dezembro de 2023

  Decoração natalina que alterna entre diferentes modos a cada clique do botao:
    - Animação 01: Sino badalando
    - Animação 02: Estrela cintilando
    - Animação 03: Feliz Natal!

  Para maiores detalhes, consultar a documentacao disponivel em https://github.com/ArthurLCastro/Atividade_02_uC_UPE  

  Observacao:
    Este firmware faz uso da biblioteca "ALC_LED_Matrix" desenvolvida durante a implementacao do projeto
    (disponivel em https://github.com/ArthurLCastro/ALC_LED_Matrix)
*/

// ---------- Importacao de bibliotecas ----------
#include <ALC_LED_Matrix.h>
#include <ALC_LED_Matrix_Figures.h>

// ---------- Definindo macros ----------
#define PIN_BUTTON 12
#define INTERVALO_ENTRE_FIGURAS_MS 500

// ---------- Declaracao de variaveis para matriz de LEDs ----------
uint8_t matrix_pins[5][5] = {
  {2,3,4,5,6},    // linhas
  {7,8,9,10,11},  // colunas
};

// ---------- Declaracao de variaveis para animacoes ----------
const byte* animacao_sino_badalando[4] = {sino_centro[0], sino_esquerda[0], sino_centro[0], sino_direita[0]};

const byte* animacao_estrela[4] = {estrela_frame1[0], estrela_frame2[0], estrela_frame3[0], estrela_frame2[0]};

const byte* animacao_feliz_natal[13] = {
  letra_F[0], letra_E[0], letra_L[0], letra_I[0], letra_Z[0],
  vazio[0],
  letra_N[0], letra_A[0], letra_T[0], letra_A[0], letra_L[0], ponto_de_exclamacao[0],
  vazio[0]
};

unsigned long previousTime=0;
unsigned int frame_idx=0;
uint8_t qtd_frames;

// ---------- Declaracao de variaveis para controle por botao ----------
bool estado_botao;
uint8_t modo = 1;

// ---------- Instanciando objetos ----------
ALC_LED_Matrix matriz5x5(matrix_pins);

// ---------- Configuracoes de inicializacao ----------
void setup() {
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  matriz5x5.begin();    // Inicializa matriz de LEDs
  matriz5x5.clear();    // Apaga todos os LEDs da matriz
}

// ---------- Loop infinito ----------
void loop() {
  // Controle do botao:
  estado_botao = digitalRead(PIN_BUTTON);

  if (!estado_botao) {
    delay(100);

    if (modo >= 3) {
      modo = 1;
    } else {
      modo++;
    }

    frame_idx = 0;
  }

  // Controle da matriz de LEDs:
  if (millis() - previousTime >= INTERVALO_ENTRE_FIGURAS_MS){
    previousTime = millis();
    
    switch (modo) {
      case 1:
        matriz5x5.select_figure(animacao_sino_badalando[frame_idx]);   // Atualiza a matriz de buffer
        qtd_frames = sizeof(animacao_sino_badalando)/sizeof(const byte*) - 1;
        break;
      case 2:
        matriz5x5.select_figure(animacao_estrela[frame_idx]);   // Atualiza a matriz de buffer
        qtd_frames = sizeof(animacao_estrela)/sizeof(const byte*) - 1;
        break;
      case 3:
        matriz5x5.select_figure(animacao_feliz_natal[frame_idx]);   // Atualiza a matriz de buffer
        qtd_frames = sizeof(animacao_feliz_natal)/sizeof(const byte*) - 1;
        break;
    }
    
    if (frame_idx >= qtd_frames) {
      frame_idx = 0;
    } else {
      frame_idx++;
    }
  }

  matriz5x5.update();     // Percorre todas as linhas da matriz atualizando os estados dos LEDs
}

