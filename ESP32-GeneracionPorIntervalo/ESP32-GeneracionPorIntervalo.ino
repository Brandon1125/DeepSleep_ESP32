//  Pines de salida para las señales
const byte Senal01 = 4;   
const byte Senal02 = 16;   
const byte Senal03 = 17;  
const byte Senal04 = 18;
const byte Senal05 = 19;
const byte Senal06 = 21;
const byte Senal07 = 22;
const byte Senal08 = 23;
const byte Senal09 = 25;

//  Estado de la señal de salida, el cual pasara de HIGH a LOW cada cierto tiempo, siendo este especifico para cada salida
int Estado01 = LOW;
int Estado02 = LOW;
int Estado03 = LOW;
int Estado04 = LOW;
int Estado05 = LOW;
int Estado06 = LOW;
int Estado07 = LOW;
int Estado08 = LOW;
int Estado09 = LOW;

//unsigned solo almacena números positivos, y long puede almacenar valores desde 0 hasta (2^32 - 1), lo cual es útil para contar grandes cantidades, como milisegundos.
//  Factor de tiempo que ayuda a medir el intervalo especifico para cada señal
unsigned long TiempoPrevio01 = 0L; // El valor 0 significa que la variable comienza sin ningún tiempo acumulado y L indica que este 0 debe de tratarse como long
unsigned long TiempoPrevio02 = 0L;
unsigned long TiempoPrevio03 = 0L;
unsigned long TiempoPrevio04 = 0L;
unsigned long TiempoPrevio05 = 0L;
unsigned long TiempoPrevio06 = 0L;
unsigned long TiempoPrevio07 = 0L;
unsigned long TiempoPrevio08 = 0L;
unsigned long TiempoPrevio09 = 0L;

//  Intervalo de tiempo entre cada cambio de pulso de cada señal, factor que diferencia una señal de otra
//  Los valores de "frecuencia" se deben recalcular en base al tiempo de conteo determinado en el codigo de lectura, en este caso de 100 ms
float intervalo01 = 2;  //  Cambio de estado cada 2 ms, para un conteo de 100 ms debe dar 50 Hz
float intervalo02 = 3;  //  Cambio de estado cada 3 ms, para un conteo de 100 ms debe dar entre 33 y 34 Hz
float intervalo03 = 4;  //  Cambio de estado cada 4 ms, para un conteo de 100 ms debe dar 25 Hz
float intervalo04 = 5;  //  Cambio de estado cada 5 ms, para un conteo de 100 ms debe dar 20 Hz
float intervalo05 = 6;  //  Cambio de estado cada 6 ms, para un conteo de 100 ms debe dar entre 16 y 17 Hz
float intervalo06 = 7;  //  Cambio de estado cada 7 ms, para un conteo de 100 ms debe dar entre 14 y 15 Hz
float intervalo07 = 8;  //  Cambio de estado cada 8 ms, para un conteo de 100 ms debe dar entre 12 y 13 Hz
float intervalo08 = 10; //  Cambio de estado cada 9 ms, para un conteo de 100 ms debe dar 10 Hz
float intervalo09 = 12; //  Cambio de estado cada 10 ms, para un conteo de 100 ms debe dar emtre 8 y 9 Hz

//  float freq01 = 10;  //  Frecuencia 01 en Hz de la onda positiva
//  float intervaloAntiguo = (1 / (freq01 * 2)) * (1 * (pow(10, 3))); //  <-------Antiguo calculo utilizado para determinar el periodo en base a la frecuencia pedida en el valor "freq01"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Senal01, OUTPUT);
  pinMode(Senal02, OUTPUT);
  pinMode(Senal03, OUTPUT);
  pinMode(Senal04, OUTPUT);
  pinMode(Senal05, OUTPUT);
  pinMode(Senal06, OUTPUT);
  pinMode(Senal07, OUTPUT);
  pinMode(Senal08, OUTPUT);
  pinMode(Senal09, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //  Conteo inicial de tiempo para determinar si el intervalo de cada señal ya se cumplio, VERIFICAR SI BASTA CON TENER SOLO UNA VARIABLE PARA TODOS LOS CASOS---------------------------------------------------------------------
  // IMPORTANTE: milis() SE REINICIA DE VUELTA A CERO DESPUES DE APROX 50 DIAS, DEBIDO A QUE EL CONTADOR DE MILISEGUNDOS LLEGA A SU LÍMITE Y SE DESBORDA Y VUELVE A EMPEZAR DE 0.
  unsigned long TiempoActual = millis(); // Retorna el tiempo en milisegundos que han transcurrido desde que el programa comenzó a ejecutarse

  
  //Ejemplo1 (3mm - 2mm >= 2) False, //Ejemplo2 (4mm - 2mm >= 2) True MANDA UN PULSO.
  if (TiempoActual - TiempoPrevio01 >= intervalo01) { // MANDA UN PULSO CADA 2mm 
    TiempoPrevio01 = TiempoActual;

    if (Estado01 == LOW) {
      Estado01 = HIGH;
    } else {
      Estado01 = LOW;
    }
    digitalWrite(Senal01, Estado01);
  }

  if (TiempoActual - TiempoPrevio02 >= intervalo02) {
    TiempoPrevio02 = TiempoActual;

    if (Estado02 == LOW) {
      Estado02 = HIGH;
    } else {
      Estado02 = LOW;
    }
    digitalWrite(Senal02, Estado02);
  }

  if (TiempoActual - TiempoPrevio03 >= intervalo03) {
    TiempoPrevio03 = TiempoActual;

    if (Estado03 == LOW) {
      Estado03 = HIGH;
    } else {
      Estado03 = LOW;
    }
    digitalWrite(Senal03, Estado03);
  }
  
  if (TiempoActual - TiempoPrevio04 >= intervalo04) {
    TiempoPrevio04 = TiempoActual;
    if (Estado04 == LOW) {
      Estado04 = HIGH;
    } else {
      Estado04 = LOW;
    }
    digitalWrite(Senal04, Estado04);
  }

  if (TiempoActual - TiempoPrevio05 >= intervalo05) {
    TiempoPrevio05 = TiempoActual;
    if (Estado05 == LOW) {
      Estado05 = HIGH;
    } else {
      Estado05 = LOW;
    }
    digitalWrite(Senal05, Estado05);
  }

  if (TiempoActual - TiempoPrevio06 >= intervalo06) {
    TiempoPrevio06 = TiempoActual;
    if (Estado06 == LOW) {
      Estado06 = HIGH;
    } else {
      Estado06 = LOW;
    }
    digitalWrite(Senal06, Estado06);
  }

  if (TiempoActual - TiempoPrevio07 >= intervalo07) {
    TiempoPrevio07 = TiempoActual;
    if (Estado07 == LOW) {
      Estado07 = HIGH;
    } else {
      Estado07 = LOW;
    }
    digitalWrite(Senal07, Estado07);
  }

  if (TiempoActual - TiempoPrevio08 >= intervalo08) {
    TiempoPrevio08 = TiempoActual;
    if (Estado08 == LOW) {
      Estado08 = HIGH;
    } else {
      Estado08 = LOW;
    }
    digitalWrite(Senal08, Estado08);
  }
  
  if (TiempoActual - TiempoPrevio09 >= intervalo09) {
    TiempoPrevio09 = TiempoActual;
    if (Estado09 == LOW) {
      Estado09 = HIGH;
    } else {
      Estado09 = LOW;
    }
    digitalWrite(Senal09, Estado09);
  }
  
}
