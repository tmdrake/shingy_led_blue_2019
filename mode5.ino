
#define led_high_value 50
void mode5(boolean newmode)
{
  
  if (newmode)
  {
   turn_all_off();
   Serial.println(F("Red Blue Police Lights"));
  }

  static int led_position = 0;
  static byte _direction = false;
  static unsigned long previousMillis;
  static int phase = 0;

  if(millis() - previousMillis >= 10) //time expired
  {
    
    
    
    if (led_position >= 60)
    {
      _direction = true;
      led_position--;
    }
    else if (led_position < 0)
    {
      _direction = false;
      led_position++;
    }
      
    //Serial.println(led_position);
    show_red_blue_light(led_position, phase);
      //update LED

    if (_direction)
      led_position--;
    else
       led_position++;  
    
    phase++;
    if (phase > led_high_value)
      phase = 0;
    
    previousMillis = millis();
  }




  
}


void show_red_blue_light(byte led_position, int phase)
{
  //first scale the positon based on the number of LEDS
  int led_pos;  
  
  
  
  
  
  
  
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
  
//  //Set any LEDS that need to be ON
// back.setPixelColor(60, 255, 255, 0);
// back.setPixelColor(61, 255, 255, 0);
// back.setPixelColor(62, 255, 255, 0);
// back.setPixelColor(63, 255, 255, 0);
// back.setPixelColor(64, 255, 255, 0);
//
// left_leg.setPixelColor(27, 255, 255, 0);
// right_leg.setPixelColor(27, 255, 255, 0); 
// 
// left_leg.setPixelColor(28, 255, 255, 0);
// right_leg.setPixelColor(28, 255, 255, 0); 
// left_leg.setPixelColor(29, 255, 255, 0);
// right_leg.setPixelColor(29, 255, 255, 0);  
// left_leg.setPixelColor(30, 255, 255, 0);
// right_leg.setPixelColor(30, 255, 255, 0);
//
// left_arm.setPixelColor(26, 255, 255, 0);
// right_arm.setPixelColor(26, 255, 255, 0);
// left_arm.setPixelColor(27, 255, 255, 0);
// right_arm.setPixelColor(27, 255, 255, 0);
// left_arm.setPixelColor(28, 255, 255, 0);
// right_arm.setPixelColor(28, 255, 255, 0);
// left_arm.setPixelColor(29, 255, 255, 0);
// right_arm.setPixelColor(29, 255, 255, 0);  
// left_arm.setPixelColor(30, 255, 255, 0);
// right_arm.setPixelColor(30, 255, 255, 0);  
  
  
  
  
  
  
  //Position the large flashing lights    
  led_pos = map(led_position, 0, 60, 0, back.numPixels());   
  back.setPixelColor(led_pos, 255, 0, 0); //position
  back.setPixelColor(back.numPixels() - 2 - led_pos, 0, 0, 255); //positi
  
  led_pos = map(led_position, 0, 60, 0, left_arm.numPixels()); 
  left_arm.setPixelColor(led_pos, 255, 0, 0);   
  left_arm.setPixelColor(left_arm.numPixels() - 1 - led_pos, 0, 0, 255);

  led_pos = map(led_position, 0, 60, 0, right_arm.numPixels()); 
  right_arm.setPixelColor(led_pos,255, 0, 0);   
  right_arm.setPixelColor(right_arm.numPixels() - 1 - led_pos, 0, 0, 255);

  led_pos = map(led_position, 0, 60, 0, left_leg.numPixels()); 
  left_leg.setPixelColor(led_pos, 255, 0, 0);   
  left_leg.setPixelColor(left_leg.numPixels() - 1 - led_pos, 0, 0, 255);
  
  led_pos = map(led_position, 0, 60, 0, right_leg.numPixels()); 
  right_leg.setPixelColor(led_pos, 255, 0, 0);   
  right_leg.setPixelColor(right_leg.numPixels() - 1 - led_pos, 0, 0, 255); 
   

  rotate(phase);
  

  

  back.show();
  left_arm.show();
  right_arm.show();
  left_leg.show();
  right_leg.show();  
  
  
  
  
  
}


void rotate(int phase)
{
  int led_blue;
  int led_red;
        left_arm.setPixelColor(11, 0, 0, 0);
        left_arm.setPixelColor(12, 0, 0, 0);
        left_arm.setPixelColor(13, 0, 0, 0);
        left_arm.setPixelColor(14, 0, 0, 0);
        left_arm.setPixelColor(15, 0, 0, 0);
        left_arm.setPixelColor(16, 0, 0, 0);
  
  led_blue = 11 + map(phase, 0, led_high_value, 0, 6);
  led_red = 14 + map(phase, 0, led_high_value, 0, 6);
  if (led_red > 16)
    led_red = led_red - 6;
  
//  Serial.println(led_red);
  left_arm.setPixelColor(led_blue, 0, 0, 255);
  left_arm.setPixelColor(led_red, 255, 0, 0);


        right_arm.setPixelColor(11, left_arm.getPixelColor(13));
        right_arm.setPixelColor(12, left_arm.getPixelColor(12));
        right_arm.setPixelColor(13, left_arm.getPixelColor(11));
        right_arm.setPixelColor(14, left_arm.getPixelColor(16));
        right_arm.setPixelColor(15, left_arm.getPixelColor(15));
        right_arm.setPixelColor(16, left_arm.getPixelColor(14));  
    
//  right_arm.setPixelColor(led_blue, 0, 0, 255);
//  right_arm.setPixelColor(led_red, 255, 0, 0);     
        left_arm.setPixelColor(18, 0, 0, 0);
        left_arm.setPixelColor(19, 0, 0, 0);
        left_arm.setPixelColor(20, 0, 0, 0);
        left_arm.setPixelColor(21, 0, 0, 0);
        left_arm.setPixelColor(22, 0, 0, 0);
        left_arm.setPixelColor(23, 0, 0, 0); 
        left_arm.setPixelColor(24, 0, 0, 0); 
        left_arm.setPixelColor(25, 0, 0, 0);

  led_blue = 18 + map(phase, 0, led_high_value, 0, 8);
  led_red = 22 + map(phase, 0, led_high_value, 0, 8);
  if (led_red > 25)
    led_red = led_red - 8;
  
  left_arm.setPixelColor(led_blue, 0, 0, 255);
  left_arm.setPixelColor(led_red, 255, 0, 0);  
    

        right_arm.setPixelColor(18, left_arm.getPixelColor(19));
        right_arm.setPixelColor(19, left_arm.getPixelColor(18));
        right_arm.setPixelColor(20, left_arm.getPixelColor(25));
        right_arm.setPixelColor(21, left_arm.getPixelColor(24));
        right_arm.setPixelColor(22, left_arm.getPixelColor(23));
        right_arm.setPixelColor(23, left_arm.getPixelColor(22)); 
        right_arm.setPixelColor(24, left_arm.getPixelColor(21));    
        right_arm.setPixelColor(25, left_arm.getPixelColor(20)); 


  led_blue =  map(phase, 0, led_high_value, 0, 14);
  led_red = 7 + map(phase, 0, led_high_value, 0, 14);
  if (led_red > 13)
    led_red = led_red - 14;
  
  for (int i = 0; i <= 13; i++)
  {
    left_leg.setPixelColor(i, 0, 0, 0);
    right_leg.setPixelColor(i, 0, 0, 0);
  }
  
  
    
  left_leg.setPixelColor(led_red, 0, 0, 255);
  left_leg.setPixelColor(led_blue, 255, 0, 0);  

  right_leg.setPixelColor(led_red, 0, 0, 255);
  right_leg.setPixelColor(led_blue, 255, 0, 0);
 
 
 led_blue = 14 +  map(phase, 0, led_high_value, 0, 11);
  led_red = 19 + map(phase, 0, led_high_value, 0, 11); 
  if (led_red > 24)
    led_red = led_red - 11;
  
 
  for (int i = 14; i <= 24; i++)
  {
    left_leg.setPixelColor(i, 0, 0, 0);
    right_leg.setPixelColor(i, 0, 0, 0);
  } 
  
  left_leg.setPixelColor(led_red, 0, 0, 255);
  left_leg.setPixelColor(led_blue, 255, 0, 0);  

  right_leg.setPixelColor(led_red, 0, 0, 255);
  right_leg.setPixelColor(led_blue, 255, 0, 0);
        
//  switch ()
//  {
//      case 0:
//        left_arm.setPixelColor(11, 255, 0, 0);
//        left_arm.setPixelColor(12, 0, 0, 0);
//        left_arm.setPixelColor(13, 0, 0, 0);
//        left_arm.setPixelColor(14, 0, 0, 255);
//        left_arm.setPixelColor(15, 0, 0, 0);
//        left_arm.setPixelColor(16, 0, 0, 0);        
//      break;
//      case 0:
//        left_arm.setPixelColor(11, 0, 0, 0);
//        left_arm.setPixelColor(12, 255, 0, 0);
//        left_arm.setPixelColor(13, 0, 0, 0);
//        left_arm.setPixelColor(14, 0, 0, 0);
//        left_arm.setPixelColor(15, 0, 0, 255);
//        left_arm.setPixelColor(16, 0, 0, 0);        
//      break;
//      case 0:
//        left_leg.setPixelColor(11, 0, 0, 0);
//        left_leg.setPixelColor(12, 0, 0, 0);
//        left_leg.setPixelColor(13, 255, 0, 0);
//        left_leg.setPixelColor(14, 0, 0, 0);
//        left_leg.setPixelColor(15, 0, 0, 255);
//      break;
//      case 0:
//        left_leg.setPixelColor(11, 255, 0, 0);
//        left_leg.setPixelColor(12, 0, 0, 0);
//        left_leg.setPixelColor(13, 0, 0, 0);
//        left_leg.setPixelColor(14, 0, 0, 0);
//        left_leg.setPixelColor(15, 0, 0, 255);
//      break;
//      case 0:
//        left_leg.setPixelColor(11, 255, 0, 0);
//        left_leg.setPixelColor(12, 0, 0, 0);
//        left_leg.setPixelColor(13, 0, 0, 0);
//        left_leg.setPixelColor(14, 0, 0, 0);
//        left_leg.setPixelColor(15, 0, 0, 255);
//      break;      
//  }
  
  
  
  
}
