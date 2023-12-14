// Matriz de LEDs 5x5 - Atividade 02 de Microcontroladores UPE/Poli
// Arthur L. Castro
// Dezembro de 2023

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

// ---------- Declaracao de variaveis para figuras ----------
unsigned long previousTime=0;
unsigned int frame_idx=0;

byte quadrado_5x5[5][5] = {
  {1,1,1,1,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,1,1,1,1},
};

byte quadrado_3x3[5][5] = {
  {0,0,0,0,0},
  {0,1,1,1,0},
  {0,1,0,1,0},
  {0,1,1,1,0},
  {0,0,0,0,0},
};

byte ponto_central[5][5] = {
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,1,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
};

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

void atualiza_matriz_L1() {
  // Configurando catodos dos LEDs (colunas)
  digitalWrite(matrix_pins[1][0], matriz_buffer[0][0]);   // Configurando valor 00 do buffer no pino 7 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][1], matriz_buffer[0][1]);   // Configurando valor 01 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][2], matriz_buffer[0][2]);   // Configurando valor 02 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][3], matriz_buffer[0][3]);
  digitalWrite(matrix_pins[1][4], matriz_buffer[0][4]);
  
  // Habilita linha (em nivel logico baixo)
  digitalWrite(matrix_pins[0][0], LOW);

  // Aguarda tempo maximo por linha para 24 Hz
  delay(TEMPO_POR_LINHA_MS);

  // Desabilita linha (em nivel logico alto)
  digitalWrite(matrix_pins[0][0], HIGH);
}

void atualiza_matriz_L2() {
  // Configurando catodos dos LEDs (colunas)
  digitalWrite(matrix_pins[1][0], matriz_buffer[1][0]);   // Configurando valor 10 do buffer no pino 7 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][1], matriz_buffer[1][1]);   // Configurando valor 11 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][2], matriz_buffer[1][2]);   // Configurando valor 12 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][3], matriz_buffer[1][3]);
  digitalWrite(matrix_pins[1][4], matriz_buffer[1][4]);
  
  // Habilita linha (em nivel logico baixo)
  digitalWrite(matrix_pins[0][1], LOW);

  // Aguarda tempo maximo por linha para 24 Hz
  delay(TEMPO_POR_LINHA_MS);

  // Desabilita linha (em nivel logico alto)
  digitalWrite(matrix_pins[0][1], HIGH);
}

void atualiza_matriz_L3() {
  // Configurando catodos dos LEDs (colunas)
  digitalWrite(matrix_pins[1][0], matriz_buffer[2][0]);   // Configurando valor 10 do buffer no pino 7 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][1], matriz_buffer[2][1]);   // Configurando valor 11 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][2], matriz_buffer[2][2]);   // Configurando valor 12 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][3], matriz_buffer[2][3]);
  digitalWrite(matrix_pins[1][4], matriz_buffer[2][4]);
  
  // Habilita linha (em nivel logico baixo)
  digitalWrite(matrix_pins[0][2], LOW);

  // Aguarda tempo maximo por linha para 24 Hz
  delay(TEMPO_POR_LINHA_MS);

  // Desabilita linha (em nivel logico alto)
  digitalWrite(matrix_pins[0][2], HIGH);
}

void atualiza_matriz_L4() {
  // Configurando catodos dos LEDs (colunas)
  digitalWrite(matrix_pins[1][0], matriz_buffer[3][0]);   // Configurando valor 10 do buffer no pino 7 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][1], matriz_buffer[3][1]);   // Configurando valor 11 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][2], matriz_buffer[3][2]);   // Configurando valor 12 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][3], matriz_buffer[3][3]);
  digitalWrite(matrix_pins[1][4], matriz_buffer[3][4]);
  
  // Habilita linha (em nivel logico baixo)
  digitalWrite(matrix_pins[0][3], LOW);

  // Aguarda tempo maximo por linha para 24 Hz
  delay(TEMPO_POR_LINHA_MS);

  // Desabilita linha (em nivel logico alto)
  digitalWrite(matrix_pins[0][3], HIGH);
}

void atualiza_matriz_L5() {
  // Configurando catodos dos LEDs (colunas)
  digitalWrite(matrix_pins[1][0], matriz_buffer[4][0]);   // Configurando valor 10 do buffer no pino 7 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][1], matriz_buffer[4][1]);   // Configurando valor 11 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][2], matriz_buffer[4][2]);   // Configurando valor 12 do buffer no pino 8 (invertido pois é o anodo)
  digitalWrite(matrix_pins[1][3], matriz_buffer[4][3]);
  digitalWrite(matrix_pins[1][4], matriz_buffer[4][4]);
  
  // Habilita linha (em nivel logico baixo)
  digitalWrite(matrix_pins[0][4], LOW);

  // Aguarda tempo maximo por linha para 24 Hz
  delay(TEMPO_POR_LINHA_MS);

  // Desabilita linha (em nivel logico alto)
  digitalWrite(matrix_pins[0][4], HIGH);
}

void atualiza_matriz(){
  atualiza_matriz_L1();
  atualiza_matriz_L2();
  atualiza_matriz_L3();
  atualiza_matriz_L4();
  atualiza_matriz_L5();
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

// ---------- Configuracoes de inicializacao ----------
void setup() {
  config_matriz();    // Definindo todos os pinos da matriz como saidas
  resetar_matriz();   // Apagando todos os LEDs da matriz

  Serial.begin(9600);
}

// ---------- Loop infinito ----------
void loop() {
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

  atualiza_matriz();
}
