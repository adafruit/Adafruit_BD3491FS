#include <Adafruit_BD3491FS.h>

Adafruit_BD3491FS bd3491fs = Adafruit_BD3491FS();

void setup() {
  Serial.begin(115200);
  // Wait until serial port is opened
  while (!Serial) { delay(1); }

  Serial.println("Adafruit BD3491FS Test");

  if (!bd3491fs.begin()) {
    Serial.println("Couldn't find BD3491FS chip");
    while (1);
  }
  Serial.println("Found BD3491FS chip");
  bd3491fs.setInputGain(BD3491FSGAIN_20DB);
  bd3491fs.setVolumeCh1(BD3491FSGAIN_0DB);
  bd3491fs.setVolumeCh2(BD3491FSGAIN_0DB);
}


void loop() {

  bd3491fs.setCurrentInput(BD3491FS_INPUT_A);
  bd3491fs.setVolumeCh1(BD3491FSGAIN_0DB);
  bd3491fs.setVolumeCh2(BD3491FSGAIN_10DB);

  delay(5000);

  bd3491fs.setCurrentInput(BD3491FS_INPUT_B);
  bd3491fs.setVolumeCh1(BD3491FSGAIN_10DB);
  bd3491fs.setVolumeCh2(BD3491FSGAIN_0DB);
  delay(5000);
}