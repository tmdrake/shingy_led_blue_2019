#define low_pot_val   100
#define hight_pot_val 500//600

int getpot()
{
  //returns pot value and Bass or All sound modes.
  int potval = analogRead(POT); //Reverse the direction
//  static int lastpot;
//  if (lastpot != potval)
//  {
//    Serial.print(F("Pot Value:"));
//    Serial.println(potval);
//    lastpot = potval;
//  }
static int return_pot;



    //Serial.println(potval);
   
  if (potval >= 512)
  {
    //all sound mode
    return_pot = map(potval-512, 0, 512, low_pot_val, hight_pot_val); //Reverse the direction
    return_pot = analogRead(MIC_A) - return_pot; //potval may need scaling
    //this part should really be a selection by Mode/flash switch.
    if (return_pot  < 0)
        return_pot = 0;
        
//    Serial.print(F("Normal:"));
//    Serial.println(return_pot);

    
    return return_pot;    
    
  }
  else
  {
    return_pot = map(potval, 0, 512, low_pot_val, hight_pot_val); //Reverse the direction
    return_pot = analogRead(MIC_LP) - return_pot; //potval may need scaling, using low pass filtering
    //this part should really be a selection by Mode/flash switch.

    if (return_pot  < 0)
        return_pot = 0;
        
//    Serial.print(F("BASS:"));
//    Serial.println(return_pot);  
    
    return return_pot;  
  }
  
  
}
