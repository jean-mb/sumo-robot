// 04/09/2022
// Author: Jean Felipe Moschen Buss
// E-mail: jeanfelipe0610@gmail.com

// Instruções: 
// - Os comentários que seguem o código são apenas dicas de organização do circuito do robô
// - Esse robô busca empurrar tudo que estiver à sua frente, EXCETO quando um de seus sensores infravermelho detectar no CHÃO a cor PRETA, pois esta é considerada o limite da arena.
// - Seguindo as regras da competição, o robô só pode agir após 3 segundos em que o operador do robô SOLTA o botão START


// Sensor ultra-sônico HC_SR04 para detecção de objetos
#define trigger 9 // cinza
#define echo 8 // roxo escuro

//Motor direito
#define motorR_pos 4 // verde - 3
#define motorR_neg 5 // azul - 4

//Motor esquerdo
#define motorL_pos 3 // amarelo - 2
#define motorL_neg 2 // laranja - 1

// Sensores infra-vermelho
#define sensor_dianteiro_direita  11 // amarelo 
#define sensor_dianteiro_esquerda 10 // laranja
#define sensor_traseiro_esquerda  12 // azul
#define sensor_traseiro_direita   13 // verde

// Botão START
#define botao 6 // branco 
 
// Gatilhos dos sensores infra-vermelho
int branco = 0;
int preto = 1;

// Variaveis de controle
int ligado = false;
int trava = true;
int distancia = 0;

void frente() {
  digitalWrite(motorR_pos, HIGH);
  digitalWrite(motorL_pos, HIGH);
  digitalWrite(motorR_neg, LOW);
  digitalWrite(motorL_neg, LOW);
}

void tras() {
  digitalWrite(motorR_pos, LOW);
  digitalWrite(motorL_pos, LOW);
  digitalWrite(motorR_neg, HIGH);
  digitalWrite(motorL_neg, HIGH);
}

void esquerda() {
  digitalWrite(motorR_pos, HIGH);
  digitalWrite(motorL_pos, LOW);
  digitalWrite(motorR_neg, LOW);
  digitalWrite(motorL_neg, HIGH);
}

void direita() {
  digitalWrite(motorR_pos, LOW);
  digitalWrite(motorL_pos, HIGH);
  digitalWrite(motorR_neg, HIGH);
  digitalWrite(motorL_neg, LOW);
}
void parada() {
  digitalWrite(motorR_pos, LOW);
  digitalWrite(motorL_pos, LOW);
  digitalWrite(motorR_neg, LOW);
  digitalWrite(motorL_neg, LOW);
}

void procura() {
  frente();
  delay(300);
  esquerda();
  delay(300);
}

long leDistancia(int triggerPin, int echoPin) // le sensor ultrassonico
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(motorR_pos, OUTPUT);
  pinMode(motorL_pos, OUTPUT);
  pinMode(motorR_neg, OUTPUT);
  pinMode(motorL_neg, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(sensor_dianteiro_direita, INPUT);
  pinMode(sensor_dianteiro_esquerda, INPUT);
  pinMode(sensor_traseiro_esquerda, INPUT);
  pinMode(sensor_traseiro_direita, INPUT);
  pinMode(botao, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  int botao_ativador = digitalRead(botao); 
  if (botao_ativador == 0) { 
    trava = false;
  }
  if (botao_ativador == 1 && trava == false) {
    Serial.print("iniciando");
    delay(4000);
    frente();
    ligado = true;
    trava = true;
  }
  if (ligado == true){
    int sensor_dd = digitalRead(sensor_dianteiro_direita); // dd = dianteiro direita
    int sensor_de = digitalRead(sensor_dianteiro_esquerda); // de = dianteiro esquerda
    int sensor_te = digitalRead(sensor_traseiro_esquerda); // te = traseira esquerda
    int sensor_td = digitalRead(sensor_traseiro_direita); // td = traseira direita
    distancia =  0.01723 * leDistancia(trigger, echo);
    Serial.println(distancia);
    if (sensor_dd == branco  && sensor_de == branco && sensor_td == branco && sensor_te == branco) {
      Serial.println("Seguro");
      if (distancia > 40 &&   sensor_de == branco && sensor_dd){
        Serial.println("procurando oponente");
        frente();
      }
      else if (distancia < 40 || distancia > 1200) {
          while (sensor_dd == branco && sensor_de == branco && sensor_td == branco && sensor_te == branco) { //Prende na condição até o sensor encotrar a borda da arena
            sensor_de = digitalRead(sensor_dianteiro_direita);
            sensor_dd = digitalRead(sensor_dianteiro_esquerda);
            sensor_te = digitalRead(sensor_traseiro_esquerda);
            sensor_td = digitalRead(sensor_traseiro_direita);
            frente();
          }
      }
    } else {
      if (sensor_dd == preto) {
        Serial.println("frente direita");
        tras();
        delay(500);
        esquerda();
        delay(250);
      }
      if (sensor_de == preto) {
        Serial.println("frente esquerda");
        tras();
        delay(500);
        direita();
        delay(250);
      }
      if (sensor_td == preto) {
        Serial.println("traseira direita");
        esquerda();
        delay(250);
        frente();
        delay(500);
      }
      if (sensor_te == preto) {
        Serial.println("traseira esquerda");
        direita();
        delay(250);
        frente();
        delay(500);
      }
    }
  }
}
