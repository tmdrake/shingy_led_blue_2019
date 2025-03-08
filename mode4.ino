//handles mode 4 

void mode4(boolean newmode)
{
  if (newmode)
  {
    turn_all_off();
    Serial.println(F("Fading Color Mode"));
  }
  
  static byte brightness; //0-100 only
  static bool _direction;
  
  static unsigned long previousMillis;
  
  if(millis() - previousMillis >= 30) //time expired
  {


    
    if (_direction)
      brightness--;
    else
      brightness++;

    if (brightness >= 100)
      _direction = true;
    else if (brightness <=0)
      _direction = false;

    set_brightness(brightness);
    //Serial.println(brightness);
    

    previousMillis = millis();



    
  }
  
}


void set_brightness(byte brightness)
{
  float _brightness = (float)brightness/200.0;
  
  for(uint16_t i=0; i<back.numPixels(); i++)
      back.setPixelColor(i, back.Color(178 * _brightness, 3 * _brightness, 238 * _brightness));
  for(uint16_t i=0; i<left_arm.numPixels(); i++)
      left_arm.setPixelColor(i, left_arm.Color(178 * _brightness, 3 * _brightness, 238 * _brightness));
  for(uint16_t i=0; i<right_arm.numPixels(); i++)
      right_arm.setPixelColor(i, right_arm.Color(178 * _brightness, 3 * _brightness, 238 * _brightness));
  for(uint16_t i=0; i<left_leg.numPixels(); i++)
      left_leg.setPixelColor(i, left_leg.Color(178 * _brightness, 3 * _brightness, 238 * _brightness));
  for(uint16_t i=0; i<right_leg.numPixels(); i++)
      right_leg.setPixelColor(i, right_leg.Color(178 * _brightness, 3 * _brightness, 238 * _brightness));
  
  
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
  
  
  
      
   
  back.show();
  left_arm.show();
  right_arm.show();
  left_leg.show();
  right_leg.show();
      
}
