///////////////
// SUPERLOOP //
///////////////

unsigned long startTime = 0;                // TIEMPO DE INICIO DEL LOOP
unsigned long elapsedTime = 0;              // TIEMPO DE LOOP
const int superloop = 10;  		    // Tiempo de superloop



//////////
// PINS //
//////////

const int boton_0= 1;	              // BOTON DE ENTRADA
const int boton_1= 2;	              // BOTON DE ENTRADA

const int led_0	= 3;	              // LED DE ENCENDIDO
const int medicion_0 = 4              // Lectura analogica



///////////
// SETUP //
///////////

void setup(){
	
  analogReadResolution(12);         // CAMBIAMOS RESOLUCION DE LECTURA ANALOGICA

  /////////////////////////
  // CLOCK MODIFICATIONS //          MODIFICACION DE CICLOS DE RELOJ (OPCION PARA AHORRAR BATERIA(TENER EN CUENTA QUE ESTO MODIFICA LA TASA DE BAUDIOS PARA LA LECTURA DE PUERTO SERIAL))
  /////////////////////////
  
  noInterrupts();                   // deshabilitamos las interrupciones
  CLKPR = 1<<CLKPCE;                // empezamos la secuencia de escritura
  CLKPR = 1;                        // seleccionamos el divisor desado, en nuestro caso el 1
  interrupts();                     // habilitamos las interrupciones
  
  ////////////
  // SERIAL //
  ////////////
	
  Serial.begin(9600);                 // INICIAMOS SERIAL USB-PC
  Serial1.begin(115200);               // INICIAMOS SERIAL MASTER_SLAVE	

/////////////////////
// PIN DECLARATION //
/////////////////////

pinMode(boton_0,	INPUT);		// PIN DE BOTON_0
pinMode(boton_1,	INPUT);		// PIN DE BOTON_1
pinMode(led_0,		OUTPUT);	// PIN DE LED_0 
pinMode(medicion_0,	INPUT);		// PIN DE LECTURA 
	
}
void loop(){
  startTime = millis();               // INICIO DE SUPERLOOP
	
  hardwarewIn();                      // ENTRADA DE SEÑALES
  linkIn();                           // CAPA DE ENLACE PARA DATOS DE ENTRADA
  App();                              // CAPA DE APLICACION
  linkOut();                          // CAPA DE ENLACE PARA DATOS DE SALIDA
  hardwareOut();                      // RESPUESTA DEL SISTEMA
	
  if (elapsedTime < superloop) {     	// SI SOBRA TIEMPO
		delay(superloop - elapsedTime);  	// ESPERA PARA COMPLETAR SUPERLOOP
	}
}
