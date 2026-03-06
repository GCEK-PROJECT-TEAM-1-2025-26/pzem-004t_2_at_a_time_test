#include <PZEM004Tv30.h>

#include <SoftwareSerial.h>

// PZEM #1 Pins: RX=D5(14), TX=D6(12)
SoftwareSerial pzemSWSerial1(14, 12);
PZEM004Tv30 pzem1(pzemSWSerial1);

// PZEM #2 Pins: RX=D1(5), TX=D2(4)
SoftwareSerial pzemSWSerial2(5, 4);
PZEM004Tv30 pzem2(pzemSWSerial2);

void setup() {
  // ESP8266 is much faster than Arduino, 115200 is standard
  Serial.begin(115200);
  delay(1000); 
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  Serial.println("PZEM Dual Sensor Read Starting...");
}

void readAndPrint(PZEM004Tv30 &pzem, const char* label) {
    Serial.print("--- Reading ");
    Serial.print(label);
    Serial.println(" ---");

    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();

    if (isnan(voltage)) {
        Serial.println("Error: Could not read sensor. Check wiring/power.");
    } else {
        Serial.printf("V: %.1fV | A: %.3fA | W: %.1fW | E: %.3fkWh | F: %.1fHz | PF: %.2f\n", 
                      voltage, current, power, energy, frequency, pf);
    }

    
    
}

void loop() {
    readAndPrint(pzem1, "Sensor 1");
    readAndPrint(pzem2, "Sensor 2");
    
    

    Serial.println("----------------------------------------------");
    delay(3000); // 3-second interval between readings
}