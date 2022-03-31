const int ENA = 2; //  pwn (pulse width modulation) manipula a velocidade/tensao do motor A
const int in_3B = 3; // Controla o motor B
const int in_4B = 4; // Controla o motor B
const int in_1A = 5; // Controla o motor A
const int in_2A = 6; // Cont  rola o motor A
const int ENB = 7;//  pwn (pulse width modulation) manipula a velocidade/tensao do motor B
// A variavel pwn é reponsavel pela velocidade de rotação, isto é conseguido atraves do controlo do input voltage no motor. O metodo de controlo da voltagem mais usado é de PWN, que permite ajustar o valor médio da voltagem que vai para o device
// atraves de desligamento e o ligamento da voltagem, a voltagem média depende do tempo em que o sinal é transimitido e do tempo em que o sinal não o é, num periodo de tempo.
//For providing logic to L298 IC to choose the direction of the DC motor 
// Para modificar o sentido da rotação do motor basta inverter o sentido que a corrente percorre o motor, para isso temos as variaveis In_1 e In_2, atraves da variação da sua tivação conseguimos mudar o sentido de rotação
const int ENC = 8; //  pwn (pulse width modulation) manipula a velocidade/tensao do motor C
const int in_3C = 9; // Controla o motor C
const int in_4C = 10; // Controla o motor C
const int in_1D = 11; // Controla o motor D
const int in_2D = 12; // Controla o motor D
const int END = 13;//
void setup()
{
pinMode(ENA,OUTPUT);  // Estamos a estabeler as entradas e saidas  
pinMode(in_3B,OUTPUT);  
pinMode(in_4B,OUTPUT);
pinMode(in_1A,OUTPUT);
pinMode(in_2A,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(ENC,OUTPUT);  // Estamos a estabeler as entradas e saidas  
pinMode(in_3C,OUTPUT);  
pinMode(in_4C,OUTPUT);
pinMode(in_1D,OUTPUT);
pinMode(in_2D,OUTPUT);
pinMode(END,OUTPUT);
}

void loop()
{
//Para uma rotação no sentido do relogio é preciso meter o in_1 = HIGH e o in_2 = LOW
//Para uma rotação no sentido oposto ao dos relogios é preciso meter o in_1 = LOW e o in_2 = HIGH
//int vel = analogRead(A0); // Estamos a defenir uma variavel inteira (vel)  que vai corresponde ao valor que é lido na variavel analogica A0 

// Tudo parado:
digitalWrite(in_3B,HIGH); 
digitalWrite(in_4B,HIGH);
digitalWrite(in_1A,HIGH); 
digitalWrite(in_2A,HIGH);
digitalWrite(in_3C,HIGH); 
digitalWrite(in_4C,HIGH);
digitalWrite(in_1D,HIGH); 
digitalWrite(in_2D,HIGH);
analogWrite(ENC, 255);
analogWrite(END, 255);
analogWrite(ENB, 255);// Estamos a variar a tensão média que é transmitida para o motor. Atraves da variação do potenciometro
analogWrite(ENA, 255);
delay(1000); // 1 Segundo de espera

/*setting pwm of the motor to 255
we can change the speed of rotaion
by chaning pwm input but we are only
using arduino so we are using higest
value to driver the motor  */  

// Para a roda 1 no sentido anti-horario: (Roda frente)
digitalWrite(in_1A,HIGH);  
digitalWrite(in_2A,LOW);
delay(1000);




// Roda 1 frente esquerda (parte nao partida)
//Para a roda 1 no sentido horario: (Roda para tras)
digitalWrite(in_1A,LOW); 
digitalWrite(in_2A,HIGH);
delay(1000);

// Parar a roda 1
digitalWrite(in_1A,HIGH); 
digitalWrite(in_2A,HIGH);
delay(1000);

// Para a roda 2 rodar no sentido horario; (Roda para frente)
digitalWrite(in_3B,LOW);
digitalWrite(in_4B,HIGH);
delay(1000);



// roda frente direita (
 // Para a roda 2: (RODA PARA TRAS)
digitalWrite(in_3B,HIGH);
digitalWrite(in_4B,LOW);
delay(1000);


// Para a roda 2 rodar no sentido anti-horario;
digitalWrite(in_3B,HIGH);
digitalWrite(in_4B,HIGH);
delay(1000);
// As 4 rodas a rodar no sentido horario: (Roda para frente)
digitalWrite(in_1A,HIGH);  
digitalWrite(in_2A,LOW);
digitalWrite(in_3B,LOW);
digitalWrite(in_4B,HIGH);
digitalWrite(in_1D,LOW); 
digitalWrite(in_2D,HIGH);
digitalWrite(in_3C,HIGH); 
digitalWrite(in_4C,LOW);
delay(1000);

// As 4 rodas no sentido anti-horario: Roda para tras
digitalWrite(in_1A,LOW); 
digitalWrite(in_2A,HIGH);
digitalWrite(in_3B,HIGH);
digitalWrite(in_4B,LOW);
digitalWrite(in_1D,HIGH);  
digitalWrite(in_2D,LOW);
digitalWrite(in_3C,LOW);
digitalWrite(in_4C,HIGH);
delay(1000);

// As 4 parar:
digitalWrite(in_3B,HIGH); 
digitalWrite(in_4B,HIGH);
digitalWrite(in_1A,HIGH); 
digitalWrite(in_2A,HIGH);
digitalWrite(in_3C,HIGH); 
digitalWrite(in_4C,HIGH);
digitalWrite(in_1D,HIGH); 
digitalWrite(in_2D,HIGH);
delay(1000);

// Roda de tras direita
//Para a roda 3 no sentido horario: (roda para frente)
digitalWrite(in_1D,LOW); 
digitalWrite(in_2D,HIGH);
delay(1000);
// Para a roda 3 no sentido anti-horario: (roda para tras)
digitalWrite(in_1D,HIGH);  
digitalWrite(in_2D,LOW);
delay(1000);
// Parar a roda 3
digitalWrite(in_1D,HIGH); 
digitalWrite(in_2D,HIGH);
delay(1000);
// Para a roda 4: (RODA PARA FRENTE)
digitalWrite(in_3C,HIGH); 
digitalWrite(in_4C,LOW);
delay(1000);

// Para a roda 4 rodar no sentido horario;
digitalWrite(in_3C,LOW);
digitalWrite(in_4C,HIGH);
delay(1000);

// Para a roda 4 rodar no sentido anti-horario;
digitalWrite(in_3C,HIGH);
digitalWrite(in_4C,HIGH);
delay(1000);
}
