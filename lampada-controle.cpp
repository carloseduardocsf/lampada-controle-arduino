#include <IRremote.h>

int RECV_PIN = 11;
float armazenavalor;
int pinoLam1 = 5;
int pinoLam2 = 7;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(pinoLam1, OUTPUT);
  pinMode(pinoLam2, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if(irrecv.decode(&results))
  {
  	Serial.print("Valor lido : ");
    Serial.println(results.value, HEX);
    armazenavalor = (results.value);
    if(armazenavalor == 0xFD08F7)    // BOTAO 1 - LIGA LAMPADA 1
    {   
    	digitalWrite(pinoLam1, HIGH);
    }
    if(armazenavalor == 0xFD8877)    // BOTAO 2 - DESLIGA LAMP 1
    {   
    	digitalWrite(pinoLam1, LOW);
    }
    if(armazenavalor == 0xFD48B7)    // BOTAO 3 - LIGA LAMP 2
    {   
    	digitalWrite(pinoLam2, HIGH);
    }
    if(armazenavalor == 0xFD28D7)    // BOTAO 4 - DESLIGA LAMP 2
    {   
    	digitalWrite(pinoLam2, LOW);
    }
    if(armazenavalor == 0xFD00FF)    /*BOTAO LIGAR/DESLIGAR - DESLIGA TODAS AS LAMPS*/ 
    {   
      	digitalWrite(pinoLam1, LOW);
    	digitalWrite(pinoLam2, LOW);
    }
  irrecv.resume(); // LE O PROX VALOR
  }
}
