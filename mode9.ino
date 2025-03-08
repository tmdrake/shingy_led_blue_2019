void mode9(boolean newmode)
{
  //random mode
  
  if (newmode)
  {
    turn_all_off();
    randomSeed(analogRead(MIC_A));
    Serial.println(F("Random Mode."));
    
  }

  unsigned int _delay = analogRead(POT);
  static unsigned long previousMillis;
  
  if(millis() - previousMillis >= _delay) //time expired
  {
    turn_on_color(random(255),random(255),random(255)); 
    previousMillis = millis();
  }



    
   
}
