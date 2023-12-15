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

![Hardware](/hardware/tinkercad/hardware_tinkercad_02.png "Hardware - Matriz de LEDs 5x5 no Arduino Uno")

[Link para Projeto no Tinkercad](https://www.tinkercad.com/things/gU8OBjhMp1a-atividade-02-uc-20232-v2?sharecode=IhkAorqFj_hop4MJpGZXsWnfL1JWquQtuNhMrLfkzjY)

### **Lista de Componentes:**
<!-- Lista de componentes necessários, com as respectivas especificações. -->

| Quantidade |       Componente        |
|   :---:    |   :---                  |
|     1      | Arduino UNO R3          |
|     5      | LEDs Vermelhos 2V 20mA  |
|     5      | LEDs Verdes 2V 20mA     |
|     5      | LEDs Amarelos 2V 20mA   |
|     5      | LEDs Azuis 2V 20mA      |
|     5      | LEDs Laranjas 2V 20mA   |
|     5      | Resistores de 220Ω 1/4W |
|     1      | Kit de jumpers diversos |

## **Configurações e Características**:
A matriz de LEDs apresenta animações (conjunto de diversas imagens em sequência) com temas natalinos que podem ser selecionadas, alternando entre os diferentes modos, ao clicar no botão.

- Animação 01: Sino badalando
- Animação 02: Estrela cintilando
- Animação 03: Frase "Feliz Natal!"

## **Firmware**:
Faça upload do [firmware_decoracao_de_natal.ino](/firmware/firmware_decoracao_de_natal/firmware_decoracao_de_natal.ino) para o microcontrolador.

> *Observação:* </br>Este projeto faz uso da biblioteca **ALC_LED_Matrix** desenvolvida durante a implementacao do projeto e  encontra-se disponivel para download em https://github.com/ArthurLCastro/ALC_LED_Matrix
.

## **Fotografias**:
![](/fotos_e_videos/fotos/circuito.jpg "Circuito")

![](/fotos_e_videos/fotos/img_trilhas.jpg "Trilhas")

![](/fotos_e_videos/fotos/letra_A.jpg "Letra A")

## **Vídeos**:
<!-- Filmagem com a explicação do sistema decorativo de iluminação. -->

- [Vídeo Demonstrativo](/fotos_e_videos/videos/video_demonstrativo.mp4)

    <video width="400" controls>
    <source src="/fotos_e_videos/videos/video_demonstrativo.mp4" type="video/mp4">
    </video>

- [Vídeo - Testando matriz](/fotos_e_videos/videos/video_testando_matriz.mp4)

    <video width="400" controls>
    <source src="/fotos_e_videos/videos/video_demonstrativo.mp4" type="video/mp4">
    </video>

- [Vídeo - Animação Quadrados](/fotos_e_videos/videos/video_animacao_quadrados.mp4)

    <video width="400" controls>
    <source src="/fotos_e_videos/videos/video_demonstrativo.mp4" type="video/mp4">
    </video>

## **A fazer**:

- [X] Definir figuras que serão apresentadas
- [X] Adicionar controle por botão
- [ ] Implementar efeito "pisca"
- [ ] Implementar efeito "rolagem"
- [ ] Implementar efeito "inverter"
- [X] Substituir alguns dos LEDs por de outra cor (solicitado o uso de LEDs vermelhos, verdes, amarelos e azuis)
- [X] Atualizar firmware para uso com novas figuras e botões
- [X] Desenvolver biblioteca para uso da Matriz de LEDs
- [X] Gravar vídeos demonstrativos
- [ ] Gravar vídeo explicando o funcionamento do projeto
