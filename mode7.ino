void mode7(boolean newmode)
{

  if (newmode)
  {
    turn_all_off();
    Serial.println(F("Adjustable Speed Police Lights"));
  }
//    
//    
//  static unsigned int _delay = analogRead(POT);
//  _delay = map(_delay, 0, 1023, 1, 100);
////  Serial.print("Pot reads:");
////  Serial.println(_delay);
//  static unsigned long previousMillis;
//  
//  static byte led_position = 0;
//  static boolean _direction = false;
//  
//  if(millis() - previousMillis >= _delay) //just like delay, only exec if _delay expired
//  {
//    //position swaping
//    if (led_position >= 60)
//    {
//      _direction = true;
//      led_position--;
//    }
//    else if (led_position <= 0)
//    {
//      _direction = false;
//      led_position++;
//    }
//     
//     
//     //shows leds
//     show_red_blue_light(led_position);
//     
//     
//     //if it at either end switch back and forth
//    if (_direction)
//      led_position--;
//    else
//       led_position++;
// 
//    previousMillis = millis();
//  }    
//    
//    
//   



float brightness = (float)(1024-analogRead(POT))/1023;
 
  for(uint16_t i=0; i<back.numPixels(); i++)
      back.setPixelColor(i, back.Color(0, 255 * brightness, 255 * brightness));
  for(uint16_t i=0; i<left_arm.numPixels(); i++)
      left_arm.setPixelColor(i, left_arm.Color(0, 255 * brightness, 255 * brightness));
  for(uint16_t i=0; i<right_arm.numPixels(); i++)
      right_arm.setPixelColor(i, right_arm.Color(0, 255 * brightness, 255 * brightness));
  for(uint16_t i=0; i<left_leg.numPixels(); i++)
      left_leg.setPixelColor(i, left_leg.Color(0, 255 * brightness, 255 * brightness));
  for(uint16_t i=0; i<right_leg.numPixels(); i++)
      right_leg.setPixelColor(i, right_leg.Color(0, 255 * brightness, 255 * brightness));







  back.show();
  left_arm.show();
  right_arm.show();
  left_leg.show();
  right_leg.show();     


}
