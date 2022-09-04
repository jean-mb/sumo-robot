# Robô de Sumô | Sumo Robot 
> Robô em Arduino programado para lutar em uma arena redonda branca, com os limites pintados de preto. 
> Arduino Robot programmed to fight sumo in a white painted arena limited with black lines
## Componentes
 - 1x Arduino Uno
 - Jumpers
 - 1x Sensor Ultra-Sônico HC_SR04
 - 4x Sensores de linha infra-vermelho TCRT5000
 - 1x Ponte H Dupla L298N
 - 2x Motores de redução
## Alimentação
 - 2x baterias 3000MAH 20A/3.7V ou similar
## Comportamendo
> De acordo com as regras, 3 segundos depois de seu operador soltar o botão START, o robô irá começar a agir, em loop:
1. Irá para frente, até encontrar seu oponente ou os limites da arena
1.1 Se encontrar seu oponente, irá focar em persegui-lo e o empurrar para fora da arena
1.1.1 Se ao tentar empurrar o oponente para fora da arena, perceber que está em cima dos limites da arena, irá recuar
1.2 Se encontrar os limites da arena, irá recuar, virar para o lado, e seguir em frente.
