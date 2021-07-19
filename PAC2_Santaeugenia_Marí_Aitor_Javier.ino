//LDR sensor
int LDRsensor = 0;  

//Valor dels cinc LEDS
int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;

//LDR pin
int pinLDR = 0;

//INICI del SETUP
//------------------------------------------------------
void setup()
{
  //Sortida LEDS
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  //Referencia externa per el voltatge del pin AREF
  analogReference(EXTERNAL); 

  //Obrim, iniciem port serie a 9600 bits per segon
  Serial.begin(9600);

}
//------------------------------------------------------
//FI del SETUP


//INICI del LOOP
//------------------------------------------------------
void loop()
{
  //Valor del sensor guardada en la variable LDRsensor
  LDRsensor = analogRead(pinLDR);
  
  //Inicialitzem variable temp per el pinA0 (del LDRsensor)
  int temp = analogRead(A0);
  
  //Escrivim per COM MONITOR SERIE per saber els valors del sensorLDR
  Serial.print ("Valor de entrada: ");
  Serial.println(temp); // Valor de entrada de A0.

  //Delay de 1 segon
  delay(1000); 

  //Més gran o igual a 823 i Més gran o igual a 1023 tots encessos
  //Valor d'entrada de la llum al LDR es de 0 a 1023, fent l'escriptura al MONITOR SERIE
  //decidim els valors que tindran (no es el mateix fer-ho al matí, que de nit).
  //Valors actuals = migdia
  if((LDRsensor >= 823) & (LDRsensor >= 1023))
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);

    //Escrivim valor del sensorLDR a COM MONITOR SERIE
    Serial.print ("Valor de entrada: ");
    Serial.println(temp); // Valor de entrada de A0.

    //Delay de 1 segon
    delay(1000); 
  }
  //Major o igual a 723 i major o igual a 823 tots encessos menys 1
  else if((LDRsensor >= 723) & (LDRsensor < 823))
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    
    //Escrivim valor del sensorLDR a COM MONITOR SERIE
    Serial.print ("Valor de entrada: ");
    Serial.println(temp); // Valor de entrada de A0.
  
    //Delay de 1 segon
    delay(1000); 
  }
  //Més gran o igual a 623 i Més gran a 723 tots encessos menys 2
  else if((LDRsensor >= 623) & (LDRsensor < 723))
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    
    //Escrivim valor del sensorLDR a COM MONITOR SERIE
    Serial.print ("Valor de entrada: ");
    Serial.println(temp); // Valor de entrada de A0.

    //Delay de 1 segon
    delay(1000); 
  }
  //Més gran o igual a 523 i Més gran a 623 dos encessos, tres apagats
  else if((LDRsensor >= 523) & (LDRsensor < 623))
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    
    //Escrivim valor del sensorLDR a COM MONITOR SERIE
    Serial.print ("Valor de entrada: ");
    Serial.println(temp); // Valor de entrada de A0.

    //Delay de 1 segon
    delay(1000); 
  }
  //Més gran o igual a 500 i Més gran a 523 tots apagats menys 1
  else  if((LDRsensor >= 500) & (LDRsensor < 523))
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    
    //Escrivim valor del sensorLDR a COM MONITOR SERIE
    Serial.print ("Valor de entrada: ");
    Serial.println(temp); // Valor de entrada de A0.

    //Delay de 1 segon
    delay(1000); 
  }
  //La resta (és a dir, normalment que el LDRsensor sigui menor de 500) tot apagat
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    
    //Escrivim valor del sensorLDR a COM MONITOR SERIE
    Serial.print ("Valor de entrada: ");
    Serial.println(temp); // Valor de entrada de A0.

    //Delay de 1 segon
    delay(1000); 
  }

}
//------------------------------------------------------
//FI del LOOP
