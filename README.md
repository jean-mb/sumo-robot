> If you're not a Portuguese reader, you can skip to the bottom of the page and you'll find an English version of this document! Hope it helps!

# Robô de Sumô

![robot](https://user-images.githubusercontent.com/79486623/188323944-59569501-31c2-4434-bc8d-61aac61281ff.jpeg)

> Robô em Arduino programado para lutar em uma arena redonda branca, com os limites pintados de preto. 
- Robô lutando: https://www.linkedin.com/posts/jeanmoschen_robotica-ugcPost-6947741716468617216-Df8P?utm_source=share&utm_medium=member_desktop
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
- Ou seja, use a imaginação para construir seu próprio chassi e robô! Considere a impressão 3D para um resultado incrivel! 😎

### Use a ponte H apenas para controlar a direção das rodas
 - Pois o Arduino, mesmo ligado em baterias potentes, não irá fornecer muita energia para os motores ligados na ponte H. 
 - É possível ligar paralelamente: 
 > Baterias -> Arduino
 
 > Baterias -> VCC da Ponte H 

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Sumo Robot
> Arduino Robot programmed to fight sumo in a white painted arena limited with black lines
- The fight: https://www.linkedin.com/posts/jeanmoschen_robotica-ugcPost-6947741716468617216-Df8P?utm_source=share&utm_medium=member_desktop
## Components
 - 1x Arduino Uno
 - Jumpers
 - 1x Ultra-sonic sensor HC_SR04
 - 4x Infra-red sensors TCRT5000
 - 1x Motor Drive - Dual H Bridge L298N
 - 2x DC Motor and its wheels 
## Powering
 - 2x Battery 3000MAH 20A/3.7V or similar
## Behavior
> Following the rules, 3 seconds after its operator releases the START button, the robot will start to take action, looping:
- Go foward, until it encounters its oponent or the arena limits (painted in white on the ground);
- If it finds the oponent, it'll focus on it and try to push it off the arena limits;
- When pushing the oponent, if the robot perceives the arena limits, it'll retreat;
- If the robot perceives the arena limits, it'll retreats, turn around, and continue to search for the oponent.
## Tips
### This repository instructs only the programming and eletronic circuits, and it is independent of its carcass and structure 
- That said, it means you are free to use your imagination and build your own robot as you like! 3D printing would me awesome! 😎  

### Use the Motor Drive only to controll the direction of the wheels. 
 - Even on batteries, the Arduino will not provide enough power to the controller and the DC motors, since these will spin as much as the energy provided.
 - It's possible to do parallel wiring as:
 > Batteries -> Arduino
 
 > Bateries -> Motor Drive's VCC 

## Contributors
> | ![Jean Moschen](https://github.com/jean-mb.png?size=64) | ![Vinicius Aquino](https://github.com/viniaqf.png?size=64) |
> | --- | --- | 
> | [Jean Moschen](https://github.com/jean-mb) | [Vinicius Aquino](https://github.com/viniaqf) |
