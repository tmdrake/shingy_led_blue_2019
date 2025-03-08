//////////////////////
//This is mode one
//THis mode takes in input and direct drives the pot
void potmode(boolean newmode)
{
  if (newmode)
  {
    turn_all_off();
    Serial.println(F("Direct Pot to Bargraph Mode"));
    
    //Mode one
  }  
  //digitalWrite(POT_EN, HIGH); //enables pot

static bool vumode = false;
static int val = 0;

//Check trigger to switch between
if (triggersavepot)
{
  triggersavepot = false;
  vumode = !vumode;
  
  Serial.print(F("VUMODE:"));
  Serial.println(vumode);
  if (vumode)
  {
    turn_on_color(255,0,0);
    delay(1000);
  }
  else    
  {
    turn_on_color(0,0,255);
    delay(1000);
  }
  turn_all_off();
  
}
//////////////////////////////////////////////

///Main Routin

    //int val = 1024-potval;
    if (!vumode)
    {
  static unsigned long previousMillis;
  if(millis() - previousMillis >= 100) //time expired
    {      
      val = 1024-analogRead(POT);
      val = map(val, 0, 1000, 0, 100);
    
    previousMillis = millis();
    } //End of hard delay
  
      
    }
    else
    {
      val = analogRead(MIC_A);
      val = map(val, 300, 512, 0, 100);
      if (val < 0)
        val = 0;
    } 
    
    //Serial.println(val);
    show_level_on_back(val);
//    delay(100);




  
  
}

void show_level_on_back(int val)
{
  //Input 0-100
int i = 0;
int pixels = 0;
//
  for(uint16_t i=0; i < back.numPixels(); i++) //
     back.setPixelColor(i, back.Color(0, 0, 0));

  pixels = map(val, 0, 100, 1, back.numPixels());
  
  for(i=0; i < pixels; i++) //
  {
      back.setPixelColor(back.numPixels() - i, back.Color(178, 3, 238));      
  }




  for(i=0; i < left_leg.numPixels(); i++) //
     left_leg.setPixelColor(i, left_leg.Color(0, 0, 0));
     
  for(i=0; i < right_leg.numPixels(); i++) //
     right_leg.setPixelColor(i, right_leg.Color(0, 0, 0));  

  for(i=0; i < pixels; i++) //
  {
      left_leg.setPixelColor(left_leg.numPixels() - i, left_leg.Color(178, 3, 238));
      right_leg.setPixelColor(right_leg.numPixels() - i, right_leg.Color(178, 3, 238));      
  }


    
  for(i=0; i < left_arm.numPixels(); i++) //
     left_arm.setPixelColor(i, left_arm.Color(0, 0, 0));   
  for(i=0; i < right_arm.numPixels(); i++) //
     right_arm.setPixelColor(i, right_arm.Color(0, 0, 0));  

  pixels = map(val, 0, 100, 0, 11);
     
  for(i=0; i < pixels; i++) //
  {
      left_arm.setPixelColor(i, left_arm.Color(178, 3, 238));
      right_arm.setPixelColor(i, right_arm.Color(178, 3, 238));      
  }     

  pixels = map(val, 0, 100, 0, 30);

  for(i=0; i < pixels; i++) //
  {
      left_arm.setPixelColor(left_arm.numPixels() - i, left_arm.Color(178, 3, 238));
      right_arm.setPixelColor(right_arm.numPixels() - i, right_arm.Color(178, 3, 238));      
  }     


//  for(uint16_t i=0; i < left_arm.numPixels(); i++)
//      left_arm.setPixelColor(left_arm.numPixels() - i, left_arm.Color(178, 3, 238));
//      
//  for(uint16_t i=0; i < right_arm.numPixels(); i++)
//      right_arm.setPixelColor(right_arm.numPixels() - i, right_arm.Color(178, 3, 238));



//      
//  for(uint16_t i=0; i<left_leg.numPixels(); i++)
//      left_leg.setPixelColor(left_leg.numPixels() - i, left_leg.Color(178, 3, 238));
//      
//  for(uint16_t i=0; i<right_leg.numPixels(); i++)
//      right_leg.setPixelColor(right_leg.numPixels() - i, right_leg.Color(178, 3, 238));
      
 
  
  back.show();
  left_arm.show();
  right_arm.show();
  left_leg.show();
  right_leg.show();      
  
}
