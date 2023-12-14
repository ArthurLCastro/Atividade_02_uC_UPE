// Matriz de LEDs 5x5 - Atividade 02 de Microcontroladores UPE/Poli
// Arthur L. Castro
// Dezembro de 2023

#include "figuras.h"

// Macros para DEBUG
// #define DEBUG_MATRIZ_BUFFER

#define TEMPO_POR_LINHA_MS 1    // Tempo maximo para atualizar cada uma das 5 linhas (para 24Hz) seria 8ms
/*
  Para uma taxa de atualização de 24Hz:

  tempo_min_por_frame_em_seg = 1 / 24
  tempo_min_por_frame_em_seg = 40ms

  tempo_max_por_linha = 40ms / 5 linhas
  tempo_max_por_linha = 8ms
*/

#define INTERVALO_ENTRE_FIGURAS_MS 250


// ---------- Declaracao de variaveis para matriz de LEDs ----------
unsigned int matrix_pins[5][5] = {
  {2,3,4,5,6},    // linhas
  {7,8,9,10,11},  // colunas
};

byte matriz_buffer[5][5] = {
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
};

// ---------- Declaracao de variaveis para animacoes ----------
unsigned long previousTime=0;
unsigned int frame_idx=0;

// ---------- Funcoes para matriz de LEDs ----------
void config_matriz() {
  // Definindo pinos da matriz como saidas
  for (int i=0; i<=4; i++) {
    pinMode(matrix_pins[0][i], OUTPUT);
  }
  for (int i=0; i<=4; i++) {
    pinMode(matrix_pins[1][i], OUTPUT);
  }
}

void resetar_matriz() {
  // Catodos dos LEDs para HIGH
  for (int i=0; i<=4; i++) {
    digitalWrite(matrix_pins[0][i], HIGH);
  }
  // Anodos dos LEDs para LOW
  for (int i=0; i<=4; i++) {
    digitalWrite(matrix_pins[1][i], LOW);
  }
}

void atualiza_matriz() {
  /*
    Funcionamento:
      Configura os niveis logicos nos anodos de todos os LEDs de uma linha simultaneamente, habilita apenas
      esta linha (catodos comum), espera um tempo, desabilita a linha e faz o mesmo para a proxima linha
  */

  for (int i=0; i<=4; i++) {
    // Controle das colunas
    for (int j=0; j<=4; j++) {
      digitalWrite(matrix_pins[1][j], matriz_buffer[i][j]);   // Configurando valores do buffer nos anodos dos LEDs (colunas)
    }

    // Controle das linhas
    digitalWrite(matrix_pins[0][i], LOW);    // Habilita linha (em nivel logico baixo)
    delay(TEMPO_POR_LINHA_MS);               // Gasta tempo
    digitalWrite(matrix_pins[0][i], HIGH);   // Desabilita linha (em nivel logico alto)
  }
}

// ---------- Funcoes para controle das figuras ----------
void seleciona_figura(byte figura[5][5]) {
  // matriz_buffer = figura;

  for (int i=0; i<=4; i++) {
    for (int j=0; j<=4; j++) {
      matriz_buffer[i][j] = figura[i][j];

      #ifdef DEBUG_MATRIZ_BUFFER
        Serial.print("matriz_buffer[");
        Serial.print(i);
        Serial.print("][");
        Serial.print(j);
        Serial.print("]: ");
        Serial.println(matriz_buffer[i][j]);
      #endif
    }
  }
}

// ---------- Animacoes ----------
void animacao_quadrados() {
  switch (frame_idx) {
    case 0:
      seleciona_figura(ponto_central);   // Atualiza 'matriz_buffer'
      break;
    case 1:
      seleciona_figura(quadrado_3x3);   // Atualiza 'matriz_buffer'
      break;
    case 2:
      seleciona_figura(quadrado_5x5);   // Atualiza 'matriz_buffer'
      break;
    case 3:
      seleciona_figura(quadrado_3x3);   // Atualiza 'matriz_buffer'
      break;
  }

  if (millis() - previousTime >= INTERVALO_ENTRE_FIGURAS_MS){
    previousTime = millis();
    
    if (frame_idx >= 3) {
      frame_idx = 0;
    } else {
      frame_idx++;
    }
  }
}

void animacao_sino_piscando() {
  switch (frame_idx) {
    case 0:
      seleciona_figura(sino);   // Atualiza 'matriz_buffer'
      break;
    case 1:
      seleciona_figura(vazio);
      break;
  }

  if (millis() - previousTime >= INTERVALO_ENTRE_FIGURAS_MS){
    previousTime = millis();
    
    if (frame_idx >= 1) {
      frame_idx = 0;
    } else {
      frame_idx++;
    }
  }
}

void animacao_feliz_natal() {
  switch (frame_idx) {
    case 0:
      seleciona_figura(letra_F);   // Atualiza 'matriz_buffer'
      break;
    case 1:
      seleciona_figura(letra_E);   // Atualiza 'matriz_buffer'
      break;
    case 2:
      seleciona_figura(letra_L);   // Atualiza 'matriz_buffer'
      break;
    case 3:
      seleciona_figura(letra_I);   // Atualiza 'matriz_buffer'
      break;
    case 4:
      seleciona_figura(letra_Z);   // Atualiza 'matriz_buffer'
      break;
    case 5:
      seleciona_figura(vazio);   // Atualiza 'matriz_buffer'
      break;
    case 6:
      seleciona_figura(letra_N);   // Atualiza 'matriz_buffer'
      break;
    case 7:
      seleciona_figura(letra_A);   // Atualiza 'matriz_buffer'
      break;
    case 8:
      seleciona_figura(letra_T);   // Atualiza 'matriz_buffer'
      break;
    case 9:
      seleciona_figura(letra_A);   // Atualiza 'matriz_buffer'
      break;
    case 10:
      seleciona_figura(letra_L);   // Atualiza 'matriz_buffer'
      break;
    case 11:
      seleciona_figura(ponto_de_exclamacao);   // Atualiza 'matriz_buffer'
      break;
    case 12:
      seleciona_figura(vazio);   // Atualiza 'matriz_buffer'
      break;
  }

  if (millis() - previousTime >= INTERVALO_ENTRE_FIGURAS_MS + 500){
    previousTime = millis();
    
    if (frame_idx >= 12) {
      frame_idx = 0;
    } else {
      frame_idx++;
    }
  }
}

// ---------- Configuracoes de inicializacao ----------
void setup() {
  config_matriz();    // Definindo todos os pinos da matriz como saidas
  resetar_matriz();   // Apagando todos os LEDs da matriz

  Serial.begin(9600);
}

// ---------- Loop infinito ----------
void loop() {
  // animacao_quadrados();
  // animacao_sino_piscando();
  animacao_feliz_natal();

  atualiza_matriz();
}
