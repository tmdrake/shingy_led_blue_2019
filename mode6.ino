void mode6(boolean newmode)
{

  if (newmode)
  {
    turn_all_off();
    Serial.println(F("Adjustable Speed Police Lights"));
  }

  brightness_rainbowCycle(10); 
}



void brightness_rainbowCycle(uint8_t wait) 
{
  static uint16_t i = 0, j;
  static unsigned long previousMillis;
  
long val = getpot(); //get the voltage from analog
//long bias =  potval; //offset adjustment (sometimes sensitivty adjustment)
//bias = 300; //ADDED FOR ADAFRUIT MIC
//val = val - potval;
//val = val - analogRead(POT);

back.setBrightness(val);
left_arm.setBrightness(val);
right_arm.setBrightness(val);
left_leg.setBrightness(val);
right_leg.setBrightness(val);


  
  
  if(millis() - previousMillis >= wait) //time expired, using non blocking delay
  {
    
    if (j<256*5)
    {
      //code needs to be patched for all LEDs
      for(i=0; i< back.numPixels(); i++) 
        back.setPixelColor(i, Wheel(((i * 256 / back.numPixels()) + j) & 255));
      for(i=0; i< left_arm.numPixels(); i++) 
        left_arm.setPixelColor(i, Wheel(((i * 256 / left_arm.numPixels()) + j) & 255));
      for(i=0; i< right_arm.numPixels(); i++) 
        right_arm.setPixelColor(i, Wheel(((i * 256 / right_arm.numPixels()) + j) & 255));
      for(i=0; i< left_leg.numPixels(); i++) 
        left_leg.setPixelColor(i, Wheel(((i * 256 / left_leg.numPixels()) + j) & 255));
      for(i=0; i< right_leg.numPixels(); i++) 
        right_leg.setPixelColor(i, Wheel(((i * 256 / right_leg.numPixels()) + j) & 255));  
      
        
      back.show();
      left_arm.show();
      right_arm.show();
      left_leg.show();
      right_leg.show();  
    
    }
    else
      j = 0;
    
    j++;  
    
    previousMillis = millis(); //reset delay
  }  
  
}
