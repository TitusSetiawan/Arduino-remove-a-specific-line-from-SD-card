/*
   Baca file per baris
   Titus 19/02/2022
*/

#include <SPI.h>
#include <SD.h>

String removeText = "3344";
String readText[12];
bool stateOverwrite = false, stateDone = true;
int indexCharX = 0, indexCharY = 0, flagDeleted;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  delay(3000);
  Serial.println("Start");
  findText();
  createFile();
}

void loop() {


}
