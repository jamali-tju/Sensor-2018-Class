
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ln(x) log(x)
#define ThermistorPin A0 
        
double Vo;
double R0 = 10000;
double R5=10000;
double T,Rth,B,T0,Tc,Tf;

void setup() {
Serial.begin(9600);
}

void loop() {

 T=analogRead(ThermistorPin);
 int readingTmp = analogRead(ThermistorPin);
 
float voltage = readingTmp * 5.0;
 voltage /=1024.0;
 
 Rth=R5*1024/ADC-R5;
 B=3435;
 T0=298.15;
 
 //Next: the ln() function has defined in header
 T=1/(ln(Rth/R0)/B+1/T0); //Direct computing The temperature from this Equation 
 //T=1/(log((10000*1024/ADC-10000)/10000)/3435+1/298.15);
 
  Tc = T - 273.15; //Convert Kelvin to Celsius
  Tf = (Tc * 9.0)/ 5.0 + 32.0; // Celsius to Fahrenheit - comment out this line if you need Celsius
 
  Serial.print("V: "); 
  Serial.print(voltage); //print out the Voltage
  Serial.print("\tTemp: "); 
  
  Serial.print(Tf); //Print the Tf value to the serial port
  Serial.print("F; ");
  
  Serial.print(Tc); //Print the Tc value to the serial port
  Serial.println("C");
  
  delay(1000); /Wait one second before we do it again
}
