//////RGB value structure.
//typedef struct {
//    byte r;
//    byte g;
//    byte b;
//} RGB_t;
//
// RGB_t  rgb[160] = {
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
//        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
//        };
//
float   cR = 1, cG = 0, cB = 0;
//        
void mode2(boolean newmode)
{
  //Music VU mode with Low Pass filtering
  //Does Trailing effects Per Orginal Suit design
  if (newmode)
  {
    //potval = analogRead(POT); //Read pot at start
    turn_all_off();
    Serial.println(F("Sound Activated Cycling based on peaks"));

  }

static bool potlock = false;
static long lastpotvalue = 0;

if (triggersavepot)
{
  triggersavepot = false;

  
  Serial.print(F("Lockng pot:"));
  Serial.println(potlock);
  if (potlock)
  {
    turn_on_color(255,0,0);
    delay(1000);
  }
  else    
  {
    turn_on_color(0,255,0);
    lastpotvalue = (long)getpot();
    delay(1000);
  }
  turn_all_off();
  
}
//long audio = analogRead(MIC_A); //get the voltage from MIC or BASS MIC
//long bass = analogRead(MIC_LP);
//word bias = analogRead(POT); //offset adjustment (sometimes sensitivty adjustment)


////static int highest_level;
//
//
//  static unsigned long previousMillis;
//  if(millis() - previousMillis >= 500) //time expired
//  {
////    Serial.print(F("A0,A1:"));
////    Serial.print((float)val*.0049 );
////    Serial.print(F("V,"));
////    Serial.print((float)base*.0049 );
////    Serial.println(F("V."));
////    previousMillis = millis();
//    potval = analogRead(POT); //pot being red over serial port
//
////    if (highest_level > 0)
////      highest_level--;
//  }
////
//bias = 300; //for Adafruits mic 
////
//audio = audio - bias; //use the pot to remove the offset
//bass = bass - bias; //use the pot to remove the offset





//const int Elements = sizeof(rgb);
static int col = 0;
//static byte red = 0;
//static byte green = 0;
//static byte blue = 0;


        for(int k=0; k<10; k++) {
//                        for(int i = back.numPixels() - 1; i >= 1; i--)
//                        {
//                                rgb[i].r = rgb[i - 1].r;
//                                rgb[i].g = rgb[i - 1].g;
//                                rgb[i].b = rgb[i - 1].b;
//                                                                    
//                        }
                        for(uint16_t i=back.numPixels(); i > 0 ; i--)
                                      back.setPixelColor(i, back.getPixelColor(i-1));
                                      
//                        for(uint16_t i=left_arm.numPixels(); i > 0 ; i--)
//                                      left_arm.setPixelColor(i, left_arm.getPixelColor(i-1));                                  
//                        for(uint16_t i=right_arm.numPixels(); i > 0 ; i--)
//                                      right_arm.setPixelColor(i, right_arm.getPixelColor(i-1));
                        for(uint16_t i=0; i < 10 ; i++)
                                      left_arm.setPixelColor(i, left_arm.getPixelColor(i+1));                                  
                        for(uint16_t i=0; i < 10 ; i++)
                                      right_arm.setPixelColor(i, right_arm.getPixelColor(i+1));

                        for(uint16_t i=25; i > 11 ; i--)
                                      left_arm.setPixelColor(i, left_arm.getPixelColor(i-1));                                  
                        for(uint16_t i=25; i > 11 ; i--)
                                      right_arm.setPixelColor(i, right_arm.getPixelColor(i-1));
                                      
                                      

                        for(uint16_t i=left_arm.numPixels(); i > 31 ; i--)
                                      left_arm.setPixelColor(i, left_arm.getPixelColor(i-1));                                  
                        for(uint16_t i=right_arm.numPixels(); i > 31 ; i--)
                                      right_arm.setPixelColor(i, right_arm.getPixelColor(i-1));
                                      
                                      
                        for(uint16_t i=left_leg.numPixels(); i > 0 ; i--)
                                      left_leg.setPixelColor(i, left_leg.getPixelColor(i-1));
                        for(uint16_t i=right_leg.numPixels(); i > 0 ; i--)
                                      right_leg.setPixelColor(i, right_leg.getPixelColor(i-1));
//                        for(uint16_t i=26; i > 0 ; i--)
//                                      left_leg.setPixelColor(i, left_leg.getPixelColor(i-1));
//                        for(uint16_t i=26; i > 0 ; i--)
//                                      right_leg.setPixelColor(i, right_leg.getPixelColor(i-1));                                      
      
                       
                        long micLevel = getpot();//analogRead(MIC_A) - 255 - analogRead(POT); //adafruit offset
                        
//                        int log4Level = log(micLevel) / log(4) * 12.5;
                        int squareLevel = micLevel * micLevel * micLevel / ((long)4 * 1024 * 1024); 
//                        float sCurveLevel = (int)(sCurve(micLevel, 4) * 255);
                       
//                        float fMicLevel = micLevel / 4.0f / 200.0f;
//                        float quadraticLevel = pow(fMicLevel, 2);
                       
                        //Serial.println(squareLevel);
                       
//                        const float one = 1.f;
                       
//                        red = green = blue = 0;
                        back.setPixelColor(0, back.Color(0,0,0)); //reset 0 to all
                        
                       //Serial.println(squareLevel);
                       //micLevel
                        setRgb(squareLevel / 4.0f);
                        
//                        setRgb(squareLevel / 2.0f); 
//                        float mic2 = (float)micLevel/1024.0;
//                        Serial.println(mic2);
//                        setRgb(mic2); 


                        //the lighting of the LED's works on a 0 to 1 scale
// 0 is off and 1 is full bright and anything in between dims the light
// in the code "(squareLevel / 0.2f))" the number 0.2 restricts the range between on and off
// increasing that number, incrases the range but also makes the lights less responsive
                        
                        //if(log4Level > squareLevel && log4Level > sCurveLevel)
                                //rgb[0].r = log4Level;
                        //else if(squareLevel > log4Level && squareLevel > sCurveLevel)
                               // rgb[0].g = quadraticLevel * 255;
                        //else if(sCurveLevel > log4Level && sCurveLevel > squareLevel)
                                //rgb[0].b = sCurveLevel;
                                
                               
                        //WS2811RGB(rgb, Elements);  //copy the elements to the neopixil
//                        maptoneopixel();
                        head.show();
                        back.show();  //push the color out to all 
                        left_arm.show(); //Slow down to the arduino
                        right_arm.show();
                        left_leg.show();
                        right_leg.show();  //probably all we can do
                        
                        //_delay_ms(5);
                        fadeRgb();
                }
               
                //_delay_ms(500);
               
                col = ++col % 6; // col = col modulus 6, Plus 1
                //Serial.println(col);
                cycleRgb(col); // makes them blinky
                
                    
   
}

void setRgb(float val)
{
  //Drakes; Drops the first pixel on each set
        if (val > 1.0f) val = 1.0f;
//        rgb[0].r = (int)(val * cR * 255);
//        rgb[0].g = (int)(val * cG * 255);
//        rgb[0].b = (int)(val * cB * 255);
//        back.setPixelColor(0, back.Color((int)(val * cR * 255), (int)(val * cG * 255), (int)(val * cB * 255)));
//brightness control (0.1-0.9)
        back.setPixelColor(0, (int)(val * cR * 255), (int)(val * cG * 255), (int)(val * cB * 255));
        
        left_arm.setPixelColor(10, (int)(val * cR * 255), (int)(val * cG * 255), (int)(val * cB * 255));
        right_arm.setPixelColor(10, (int)(val * cR * 255), (int)(val * cG * 255), (int)(val * cB * 255));
        
        left_arm.setPixelColor(11, left_arm.getPixelColor(0));
        right_arm.setPixelColor(11, right_arm.getPixelColor(0));
        
 ////////////////////////////////////
        left_arm.setPixelColor(31, left_arm.getPixelColor(25));
        right_arm.setPixelColor(31, right_arm.getPixelColor(25));
        
        //continuation to another stirng 
        left_leg.setPixelColor(0, left_arm.getPixelColor(11));
        right_leg.setPixelColor(0, right_arm.getPixelColor(11));
        
        left_leg.setPixelColor(31, left_leg.getPixelColor(26));     //skipping more leds
        right_leg.setPixelColor(31, right_leg.getPixelColor(26));   //skipping more leds
        left_leg.setPixelColor(32, left_leg.getPixelColor(31));     //skipping more leds
        right_leg.setPixelColor(32, right_leg.getPixelColor(31));   //skipping more leds
        left_leg.setPixelColor(33, left_leg.getPixelColor(32));     //skipping more leds
        right_leg.setPixelColor(33, right_leg.getPixelColor(32));   //skipping more leds        
        
//        left_arm.setPixelColor(12, 0, 0, 0);
//        right_arm.setPixelColor(12, 0, 0, 0);
//  //Set constant on's
//   back.setPixelColor(60, 255, 255, 0);
//   back.setPixelColor(61, 255, 255, 0);
//   back.setPixelColor(62, 255, 255, 0);
//   back.setPixelColor(63, 255, 255, 0);
//   back.setPixelColor(64, 255, 255, 0);
//  
//   left_leg.setPixelColor(27, 255, 255, 0);
//   right_leg.setPixelColor(27, 255, 255, 0);
//    left_leg.setPixelColor(28, 255, 255, 0);
//   right_leg.setPixelColor(28, 255, 255, 0);
//    left_leg.setPixelColor(29, 255, 255, 0);
//   right_leg.setPixelColor(29, 255, 255, 0);
//    left_leg.setPixelColor(30, 255, 255, 0);
//   right_leg.setPixelColor(30, 255, 255, 0);
//  
//   left_arm.setPixelColor(26, 255, 255, 0);
//   right_arm.setPixelColor(26, 255, 255, 0);
//   left_arm.setPixelColor(27, 255, 255, 0);
//   right_arm.setPixelColor(27, 255, 255, 0);
//   left_arm.setPixelColor(28, 255, 255, 0);
//   right_arm.setPixelColor(28, 255, 255, 0);
//   left_arm.setPixelColor(29, 255, 255, 0);
//   right_arm.setPixelColor(29, 255, 255, 0);  
//   left_arm.setPixelColor(30, 255, 255, 0);
//   right_arm.setPixelColor(30, 255, 255, 0);   
 
// 
        
}        



//float sCurve(int micInput, float power)
//{
//        float normalised = micInput / 1024.0f;
//       
//        return normalised / (pow(1 + pow(normalised, power), 1.0f / power) );
//}



const int phaseLength = 50; //5; // thinking that it dose the color lenght or the linth of the power coming in 
const int period = phaseLength * 5;
int iteration = 0;  

void fadeRgb() {
    
        // Determine which phase we are in
        int phase = iteration / phaseLength;
        int step = iteration % phaseLength;
         
         
//        Serial.print(F("Phase:"));Serial.println(phase);
//        Serial.print(F("Step:"));Serial.println(step);
        switch(phase)
        {
                case 0: // Red on, green increasing, blue off
                cR = 1;
                cG = step / ((float)phaseLength);
                cB = 0;
                break;
               
                case 1: // Red decreasing, green on, blue off
                cR = (phaseLength - step) / ((float)phaseLength);
                cG = 1;
                cB = 0;
                break;
               
                case 2: // Red off, green on, blue increasing
                cR = 0;
                cG = 1;
                cB = step / ((float)phaseLength);
                break;
               
                case 3: // Red off, green decreasing, blue on
                cR = 0;
                cG = (phaseLength - step) / ((float)phaseLength);
                cB = 1;
                break;
               
                case 4: // Red increasing, green off, blue on
                cR = step / ((float)phaseLength);
                cG = 0;
                cB = 1;
                break;
               
                case 5: // Red on, green off, blue decreasing
                cR = 1;
                cG = 0;
                cB = (phaseLength - step) / ((float)phaseLength);
                break;
        }
       
        iteration = ++iteration % period;
}
 
 
 
void cycleRgb(int col) {
        switch(col)
        {
                case 0:
                cR = 1;
                cG = 0;
                cB = 0;
                break;
               
                case 1:
                cR = 0.5;
                cG = 0.5;
                cB = 0;
                break;
               
                case 2:
                cR = 0;
                cG = 1;
                cB = 0;
                break;
               
                case 3:
                cR = 0;
                cG = 0.5;
                cB = 0.5;
                break;
               
                case 4:
                cR = 0;
                cG = 0;
                cB = 1;
                break;
               
                case 5:
                cR = 0.5;
                cG = 0;
                cB = 0.5;
                break;
        }
}

//void maptoneopixel()
//{
//  //Drake: Takes are of mapping the "Elements" (which is 240 elements right now)
//  static unsigned long previousMillis;
//  if(millis() - previousMillis >= 100) //time expired
//  {
//     for (int i = 0; i < sizeof(rgb); i++)
//     {
//       Serial.print(F("["));
//       Serial.print(rgb[i].r, DEC);
//       Serial.print(F(","));
//       Serial.print(rgb[i].g, DEC);
//       Serial.print(F(","));
//       Serial.print(rgb[i].b, DEC);
//       Serial.print(F("],"));
//       
//     } 
//    
//    Serial.println();
//    
//    
//    
//    
//    previousMillis = millis();
//
//
//  } 
//  ////////////////////////////////////////////////////////////////////////
//  
//  
//}
