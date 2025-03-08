void mode11(boolean newmode)
{
  //Music VU mode
  if (newmode)
  {
    turn_all_off();
    Serial.println(F("Music VU mode"));
  }

long raw = analogRead(MIC_A); //get the voltage from MIC or BASS MIC
long bass = analogRead(MIC_LP);
word bias = analogRead(POT); //offset adjustment (sometimes sensitivty adjustment)

//pinMode(MIC_G, INPUT); //highest gain






//pinMode(MIC_G, INPUT); //highest gain


  static unsigned long previousMillis;
  if(millis() - previousMillis >= 100) //time expired
  {
    Serial.print(F("A0,A1:"));
    Serial.print((float)raw*.0049 );
    Serial.print(F("V,"));
    Serial.print((float)bass*.0049 );
    Serial.println(F("V."));
    previousMillis = millis();

  }
bias = 300;

raw = raw - bias; //use the pot to remove the offset
bass = bass - bias; //use the pot to remove the offset



if (bass < 0)
  bass = 0;

if (raw < 0)
  raw = 0;

//if (raw > 255)
//  raw = 255;




show_level_on_all(raw, 178, 3, 238); //bargraph with Red as MIC, and Blue as Low Pass Filter 
show_level_on_back(bass, 178, 3, 238);





    
   
}

void show_level_on_back(int val, byte red, byte green, byte blue)
{
   for(uint16_t i=0; i < back.numPixels(); i++) //
      back.setPixelColor(i, back.Color(0, 0, 0));
  
//  if (val > back.numPixels())
//    val = back.numPixels();
    val = map(val, 0, 200, 0, back.numPixels());
  
  for(uint16_t i=0; i < val; i++) //
      back.setPixelColor(i, back.Color(red, green, blue));
      
  back.show();
}

void show_level_on_all(int val, byte red, byte green, byte blue)
{
  //clear all led buffer
//  for(uint16_t i=0; i<back.numPixels(); i++)
//      back.setPixelColor(i, back.Color(0, 0, 0));
  for(uint16_t i=0; i<left_arm.numPixels(); i++)
      left_arm.setPixelColor(i, left_arm.Color(0, 0, 0));
  for(uint16_t i=0; i<right_arm.numPixels(); i++)
      right_arm.setPixelColor(i, right_arm.Color(0, 0, 0));
  for(uint16_t i=0; i<left_leg.numPixels(); i++)
      left_leg.setPixelColor(i, left_leg.Color(0, 0, 0));
  for(uint16_t i=0; i<right_leg.numPixels(); i++)
      right_leg.setPixelColor(i, right_leg.Color(0, 0, 0));
      
      
      

  
//  for(uint16_t i=0; i <= val; i++) //
//      back.setPixelColor(i, back.Color(red, green, blue));
  for(uint16_t i=0; i <= map(val, 0, 200, 0, left_arm.numPixels()); i++) //
      left_arm.setPixelColor(i, left_arm.Color(red, green, blue));      
  for(uint16_t i=0; i <= map(val, 0, 200, 0, right_arm.numPixels()); i++) //
      right_arm.setPixelColor(i, right_arm.Color(red, green, blue));     
  for(uint16_t i=0; i <= map(val, 0, 200, 0, left_leg.numPixels()); i++) //
      left_leg.setPixelColor(i, left_leg.Color(red, green, blue));
  for(uint16_t i=0; i <= map(val, 0, 200, 0, right_leg.numPixels()); i++) //
      right_leg.setPixelColor(i, right_leg.Color(red, green, blue));

      
//  back.show();
  left_arm.show();
  right_arm.show();
  left_leg.show();
  right_leg.show(); 
}
