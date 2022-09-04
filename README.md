> If you're not a Portuguese reader, you can skip to the bottom of the page and you'll find an Englisg version of this document! Thank you!

# Robô de Sumô
> Robô em Arduino programado para lutar em uma arena redonda branca, com os limites pintados de preto. 
## Componentes
 - 1x Arduino Uno
 - Jumpers
 - 1x Sensor Ultra-Sônico HC_SR04
 - 4x Sensores de linha infra-vermelho TCRT5000
 - 1x Ponte H Dupla L298N
 - 2x Motores de redução e suas respectivas rodas
## Alimentação
 - 2x baterias 3000MAH 20A/3.7V ou similar
## Comportamento
> De acordo com as regras, 3 segundos depois de seu operador soltar o botão START, o robô irá começar a agir, em loop:
- Irá para frente, até encontrar seu oponente ou os limites da arena
- Se encontrar seu oponente, irá focar em persegui-lo e o empurrar para fora da arena 
- Se ao tentar empurrar o oponente para fora da arena, perceber que está em cima dos limites da arena, irá recuar
- Se encontrar os limites da arena, irá recuar, virar para o lado, e seguir em frente.
## Dicas
### Esse repositório instrui apenas o circuito eletrônico e programação do robô e é independente da carcaça usada para suporte.
Ou seja, use a imaginação para construir seu próprio chassi e robô! Considere a impressão 3D para um resultado incrivel! 😎

### Use a ponte H apenas para controlar a direção das rodas
Pois o Arduino, mesmo ligado em baterias potentes, não irá fornecer muita força para os motores ligados na ponte H. 
É possível ligar paralelamente: Baterias -> Arduino / Baterias -> Ponte H
