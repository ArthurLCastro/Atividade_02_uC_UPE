# Atividade 02 - Matriz de LEDs 5x5
## Microcontroladores - UPE/Poli 2023.2 Profª Andrea Maria

## **Descrição da atividade**:

A atividade 02 consiste na construção de um sistema programável de um painel de iluminação natalina decorativa. O controle deve ser feito pelo microcontrolador ATmega328P, por meio de um código escrito utilizando a linguagem de programação C++. O painel consiste em uma matriz de LEDs 5x5 visando exibir imagens com as diferentes combinações dos LEDs (acesos e apagados).

- Fazer no mínimo 4 imagens diferentes
- Usar LEDs com cores diferentes
- Usar botões para alterar a configuração das imagens (Ex.: ao apertar o botão na primeira vez as imagens vão trocando automaticamente; ao apertar o botão na segunda vez uma única imagem fica piscando, etc)
- Uso do Arduino UNO R3

> *Observação:* </br> Será analisada a organização da montagem, escolha das imagens que serão formadas no painel (matriz de LED). Bem como o código de cores dos jumpers utilizados para representação da alimentação.


## **Hardware**:

O hardware consiste em uma matriz de LEDs 5x5, onde as linhas da matriz tem os catodos dos LEDs conectados entre si e, de forma análoga, as colunas referem-se à união dos anodos dos LEDs.

Resistores foram dimensionados para limitação de corrente nos LEDs.

![Hardware](/hardware/tinkercad/hardware_tinkercad.png "Hardware - Matriz de LEDs 5x5 no Arduino Uno")

[Link para Projeto no Tinkercad](https://www.tinkercad.com/things/gU8OBjhMp1a-atividade-02-uc-20232)

### **Lista de Componentes:**
<!-- Lista de componentes necessários, com as respectivas especificações. -->

| Quantidade |       Componente       |
|   :---:    |   :---                 |
|     1      | Arduino UNO R3         |
|     25     | LEDs Vermelhos 2V 20mA |
|     5      | Resistores de 220Ω     |
|     10     | Jumpers                |

## **Configurações e Características**:
<!-- Informar as diferentes configurações e características do painel de iluminação Natalina decorativa. -->

## **Firmware**:

## **Fotografias**:

## **Vídeo demonstrativo**:
<!-- Filmagem com a explicação do sistema decorativo de iluminação. -->

## **A fazer**:

- [ ] Definir figuras que serão apresentadas
- [ ] Adicionar controle por botão
- [ ] Substituir alguns dos LEDs por de outra cor (solicitado o uso de LEDs vermelhos, verdes, amarelos e azuis)
- [ ] Atualizar firmware para uso com novas figuras e botões
- [ ] Desenvolver biblioteca para uso da Matriz de LEDs
- [ ] Gravar vídeo demonstrativo
