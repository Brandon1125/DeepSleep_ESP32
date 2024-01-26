const byte Entrada = 33; // Pin de entrada digital y pines de LED de rango.
//const byte Entrada = 35; // Pin de entrada digital y pines de LED de rango.
const byte LED01 = 4;
const byte LED02 = 16;
const byte LED03 = 17;
const byte LED04 = 18;
const byte LED05 = 19;
const byte LED06 = 21;
const byte LED07 = 22;
const byte LED08 = 23;
const byte LED09 = 25;

//boolean flag = false; 
boolean inputState = false; // Valor variable entre 0 y 1; es el estado actual de la frecuencia siendo leida. 
boolean lastInputState = false; // Valor variable entre 0 y 1; lleva nota de cual fue el estado anterior de la frecuencia.

int EstadoLED01 = LOW; // Seteamos todos los leds como apagados
int EstadoLED02 = LOW;
int EstadoLED03 = LOW;
int EstadoLED04 = LOW;
int EstadoLED05 = LOW;
int EstadoLED06 = LOW;
int EstadoLED07 = LOW;
int EstadoLED08 = LOW;
int EstadoLED09 = LOW;

int counter = 0; // Declaración de contadores
int counterState = 0;
//RTC_DATA_ATTR int bootCount = 0;

unsigned long Fin_Pulso; // Seteamos los medidores de tiempo 
unsigned long Inicio_Pulso; 
unsigned long Tiempo_Chido;
unsigned long Tiempo_Anterior;

void Turn(int TiempoChido){ // Función que mediante la duración del pulso positivo leído, enciende el led correspondiente al pulso que se leyó y apaga todos los demás
  switch(TiempoChido){
    case 2: EstadoLED01 = HIGH; EstadoLED02 = EstadoLED03 = EstadoLED04 = EstadoLED05 = EstadoLED06 = EstadoLED07 = EstadoLED08 = EstadoLED09 = LOW; break;
    case 3: EstadoLED02 = HIGH; EstadoLED01 = EstadoLED03 = EstadoLED04 = EstadoLED05 = EstadoLED06 = EstadoLED07 = EstadoLED08 = EstadoLED09 = LOW; break;
    case 4: EstadoLED03 = HIGH; EstadoLED01 = EstadoLED02 = EstadoLED04 = EstadoLED05 = EstadoLED06 = EstadoLED07 = EstadoLED08 = EstadoLED09 = LOW; break;
    case 5: EstadoLED04 = HIGH; EstadoLED01 = EstadoLED02 = EstadoLED03 = EstadoLED05 = EstadoLED06 = EstadoLED07 = EstadoLED08 = EstadoLED09 = LOW; break;
    case 6: EstadoLED05 = HIGH; EstadoLED01 = EstadoLED02 = EstadoLED03 = EstadoLED04 = EstadoLED06 = EstadoLED07 = EstadoLED08 = EstadoLED09 = LOW; break;
    case 7: EstadoLED06 = HIGH; EstadoLED01 = EstadoLED02 = EstadoLED03 = EstadoLED04 = EstadoLED05 = EstadoLED07 = EstadoLED08 = EstadoLED09 = LOW; break;
    case 8: EstadoLED07 = HIGH; EstadoLED01 = EstadoLED02 = EstadoLED03 = EstadoLED04 = EstadoLED05 = EstadoLED06 = EstadoLED08 = EstadoLED09 = LOW; break;
    case 10: EstadoLED08 = HIGH; EstadoLED01 = EstadoLED02 = EstadoLED03 = EstadoLED04 = EstadoLED05 = EstadoLED06 = EstadoLED07 = EstadoLED09 = LOW; break;
    case 12: EstadoLED09 = HIGH; EstadoLED01 = EstadoLED02 = EstadoLED03 = EstadoLED04 = EstadoLED05 = EstadoLED06 = EstadoLED07 = EstadoLED08 = LOW; break;
  }
  //flag = true;
}



//"""////////////////////////////////////////// INICIO DEL SETUP /////////////////////////////////////////////"""
void setup() { // Seteamos todos los pines si serán de Entrada o Salida de la ESP32
  Serial.begin(115200);
  //delay(1000);
  pinMode(Entrada, INPUT);
  pinMode(LED01, OUTPUT);
  pinMode(LED02, OUTPUT);
  pinMode(LED03, OUTPUT);
  pinMode(LED04, OUTPUT);
  pinMode(LED05, OUTPUT);
  pinMode(LED06, OUTPUT);
  pinMode(LED07, OUTPUT);
  pinMode(LED08, OUTPUT);
  pinMode(LED09, OUTPUT);

  //++bootCount;
  ////Serial.println("Boot Count: " + String(bootCount));
  Serial.println("DESPIERTO");
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 1);
}

void setInputState() { // Funcion que lleva a cabo la lectura DIGITAL del pin de entrada definido, en este caso el pin 33.
  inputState = digitalRead(Entrada); 
}    

//"""////////////////////////////////////////// INICIO DEL LOOP /////////////////////////////////////////////"""
void loop() {
  setInputState(); // Llamamos al pin Input que lee entradas digitales, en este caso pulsos mandados de otra ESP32

  if (inputState != lastInputState) { // Cada que recibimos un pulso ya sea HIGH o LOW, lo registramos y trabajamos sobre ese pulso
    lastInputState = inputState;

    if (inputState == 1){ Inicio_Pulso = millis();}
    else{ 
      Fin_Pulso = millis(); 
      Tiempo_Chido = Fin_Pulso - Inicio_Pulso; // Contamos el tiempo en el que el pulso fue positivo (HIGH)

      if (Tiempo_Chido == Tiempo_Anterior){ // Si el tiempo del pulso es el mismo durante al menos 4 pulsos consecutivos, entra al if counter >= 4
      counter += 1;
      
        if (counter >= 4){
          Turn(Tiempo_Chido);
        }
      }
    }
    
    Tiempo_Anterior = Tiempo_Chido;    

  }else{
    
    counterState +=1;
    
    if(counterState >= 1000){ // Cada que se cuentan 100000 counterState, apagamos todos los leds, en tiempo esto es aprox 1000 milisegundos
      EstadoLED01 = LOW;
      EstadoLED02 = LOW;
      EstadoLED03 = LOW;
      EstadoLED04 = LOW;
      EstadoLED05 = LOW;
      EstadoLED06 = LOW;
      EstadoLED07 = LOW;
      EstadoLED08 = LOW;
      EstadoLED09 = LOW;

      counterState = 0;
      counter = 0;
      //flag = false;
      delay(1000);
      Serial.println("DORMIDO");
      esp_deep_sleep_start();
    }
    
  }

  // ACTUALIZAMOS LOS ESTADOS DE LOS LEDS a como quedaron seteados en el if anterior.
  digitalWrite(LED01, EstadoLED01);
  digitalWrite(LED02, EstadoLED02);
  digitalWrite(LED03, EstadoLED03);
  digitalWrite(LED04, EstadoLED04);
  digitalWrite(LED05, EstadoLED05);
  digitalWrite(LED06, EstadoLED06);
  digitalWrite(LED07, EstadoLED07);
  digitalWrite(LED08, EstadoLED08);
  digitalWrite(LED09, EstadoLED09);
}