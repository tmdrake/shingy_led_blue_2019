
#define TURN_LEFT 1
#define TURN_RIGHT 2

void mode10(boolean newmode)
{
  //random mode
  if (newmode)
  {
    turn_all_off();
    //Serial.println(F("Turn Signal, use pot to set turn"));
  }

  //unsigned int val = analogRead(POT);

  int val = potval;

  //Serial.println(val);
  
  if (val > 682)
      turn_signal(TURN_LEFT);
  else if (val < 341)
      turn_signal(TURN_RIGHT);
  else
      turn_all_off();



  //delay(100);
    
   
}


void turn_signal(byte _signal)
{
  static unsigned long previousMillis;
  static byte led_lit = 0;
  
  if(millis() - previousMillis >= 250) //time expired
  {
    if (led_lit >= 10)
      led_lit = 0;
    led_lit++;
    
    
      bargraph_led_turn(_signal,  led_lit);
    
    
    
    previousMillis = millis();
  }
  
  
  
}


void bargraph_led_turn(byte which_direction, byte led_lit)
{
  //turn_all_off();
  //clear all led buffer
  for(uint16_t i=0; i<back.numPixels(); i++)
      back.setPixelColor(i, back.Color(0, 0, 0));
  for(uint16_t i=0; i<left_arm.numPixels(); i++)
      left_arm.setPixelColor(i, left_arm.Color(0, 0, 0));
  for(uint16_t i=0; i<right_arm.numPixels(); i++)
      right_arm.setPixelColor(i, right_arm.Color(0, 0, 0));
  for(uint16_t i=0; i<left_leg.numPixels(); i++)
      left_leg.setPixelColor(i, left_leg.Color(0, 0, 0));
  for(uint16_t i=0; i<right_leg.numPixels(); i++)
      right_leg.setPixelColor(i, right_leg.Color(0, 0, 0));  


  
  
  if (which_direction == TURN_LEFT)
  {
    led_lit = map(led_lit, 0, 10, 0 , left_arm.numPixels());
    for (byte i = 0; i < led_lit; i++)
       left_arm.setPixelColor(i, left_arm.Color(200, 127, 0));
       
    left_arm.show(); 
    
  }
  else
  {
    //Serial.println(which_direction);
    led_lit = map(led_lit, 0, 10, 0 , right_arm.numPixels());
    for (byte i = 0; i < led_lit; i++)  
       right_arm.setPixelColor(i, right_arm.Color(200, 127, 0));  
       
    right_arm.show();
  }

  
  
}



