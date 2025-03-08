//
//void musicmode(boolean newmode, boolean policemode)
//{
//  //this mode handles the orginal Shingi LED protocol
//  if (newmode)
//  {
//    turn_all_off();
//    Serial.println(F("Sound Activated Chase Paturn"));
//  }
//
//  
//long val = analogRead(MIC_A); //get the voltage from analog
//long base = analogRead(MIC_LP);
//word bias = analogRead(POT); //offset adjustment (sometimes sensitivty adjustment)
//
//
////pinMode(MIC_G, INPUT); //highest gain
//
//  static unsigned long previousMillis;
//  if(millis() - previousMillis >= 100) //time expired
//  {
//    Serial.print(F("A0,A1,POT:"));
//    Serial.print((float)val*.0049 );
//    Serial.print(F("V,"));
//    Serial.print((float)base*.0049 );
//    Serial.print(F("V,"));
//    Serial.print((float)bias/1023*100 );
//    Serial.println(F("%."));
//    previousMillis = millis();
//
//  }
//
//bias = 255; //for adafruit mic
//
//val = val - bias; //use the pot to remove the offset
//
//
//if (val < 0)
//  val = 0;
//
//
//
//
////static byte clipcounter = 0;
////
////if (val > 255)
////{
////    val = 255;
////    //we clipped!
////    clipcounter++;
////}
////
////if (clipcounter > 10)
////  Serial.println(F("CLIPING DETECTED!"));
////else if (clipcounter > 20);
////  clipcounter = 20;
////
////
////
////
//////clipping backoff every 1 second
////  static unsigned long previousMillis;
////  if(millis() - previousMillis >= 100) //time expired
////  {
////    if (clipcounter >  0)
////      clipcounter--;
////    previousMillis = millis();
////  }
//
//
//
//
//soundmode(val, policemode); //red blue flashing mode, policemode is only red/blue combo
////soundmode_1(val, false);
//
//
//
//
//}
//
//
//void soundmode(int val, boolean pd )
//{
//// long micLevel = val;
//// int log4Level = log(micLevel) / log(4) * 12.5;
//// int squareLevel = micLevel * micLevel * micLevel / ((long)4 * 1024 * 1024);
//// float sCurveLevel = (int)(sCurve(micLevel, 4) * 255);
//// float fMicLevel = micLevel / 4.0f / 200.0f;
//// float quadraticLevel = pow(fMicLevel, 2);
//
////  float bias = (float) analogRead(POT) /1023.0;
//  
//  //Serial.println(bias);
//
// // int vu = map(val, 0, 1023, 0, 255);
//
//
//// int red = log4Level * bias;
//// int green = quadraticLevel * 255;
//// int blue =  sCurveLevel * bias;
//
//
// int red = 0;//val - bias;
// int green = 0;//val - bias;
// int blue = 0;
//
//if (pd) //lets see if we are in Police color mode
//{
//  static byte color_switch = 0;
//  switch (color_switch)
//  {
//    case 1:
//    case 2:
//      blue =  val;
//    break;
//
//    case 3:
//    case 4:
//      red =   val;
//    break;
//  }
//
//  color_switch++;
//  
//  if (color_switch > 4)
//     color_switch = 0;
//}
//else
//{
//  blue = val;   //this will be changed to Color select
//}
// 
// 
//  
//
//  
//
// ///Serial.println(blue);
// 
//  //Below is code written have the LEDS start     
//  back.setPixelColor(0, back.Color(red, green, blue));
//  
//  //start from the opposite end
//  //int chess = left_arm.numPixels()-39;
////  left_arm.setPixelColor(left_arm.numPixels()-1, back.Color(red, green, blue));
////  right_arm.setPixelColor(right_arm.numPixels()-1, back.Color(red, green, blue));
//  left_arm.setPixelColor(9, left_arm.Color(red, green, blue));
//  right_arm.setPixelColor(9, right_arm.Color(red, green, blue));
//  
//  
//  left_leg.setPixelColor(0, left_leg.Color(red, green, blue));
//  right_leg.setPixelColor(0, right_leg.Color(red, green, blue));
//
//
//for(uint16_t i=back.numPixels(); i > 0 ; i--)
//      back.setPixelColor(i, back.getPixelColor(i-1));
//
//for(uint16_t i=0; i < (left_arm.numPixels() - 1) ; i++)
//      left_arm.setPixelColor(i, left_arm.getPixelColor(i+1));
//
//for(uint16_t i=0; i < (right_arm.numPixels() - 1) ; i++)
//      right_arm.setPixelColor(i, right_arm.getPixelColor(i+1));
//      
//for(uint16_t i=left_leg.numPixels(); i > 0 ; i--)
//      left_leg.setPixelColor(i, left_leg.getPixelColor(i-1));
//
//for(uint16_t i=right_leg.numPixels(); i > 0 ; i--)
//      right_leg.setPixelColor(i, right_leg.getPixelColor(i-1));
//
// 
//     back.show();
//     left_arm.show();
//     right_arm.show();
//     left_leg.show();
//     right_leg.show();
//    
//}
//

