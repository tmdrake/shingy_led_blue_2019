void mode3(boolean newmode)
{
       // Serial.println(F("Rainbow Effect"));
       //TODO: Make it do it all outputs
  if (newmode)
  {
    turn_all_off();
    Serial.println(F("RainBow Colow modes"));
  }


    
  rainbowCycle(10);  
}


void rainbowCycle(uint8_t wait) {
  static uint16_t i = 0, j;
  static unsigned long previousMillis;




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
      for(i=0; i< head.numPixels(); i++) 
        head.setPixelColor(i, Wheel(((i * 256 / head.numPixels()) + j) & 255));  
      
      head.show();  
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
