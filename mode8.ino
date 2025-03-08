void mode8(boolean newmode)
{
  //my attempt at light to sound, turns on all LEDS
    //Serial.println(F("Flash Light to sound!"));
  if (newmode)
  {
    turn_all_off();
    Serial.println(F("Sound Activated Light."));
  }

long val = getpot(); //get the voltage from analog



//word bias =  potval; //offset adjustment (sometimes sensitivty adjustment)
//word bias =  1024-analogRead(POT); //offset adjustment (sometimes sensitivty adjustment)


//bias = 300; //ADDED FOR ADAFRUIT MIC

//val = val - bias;

if (val > 255)
 val = 255;

if (val < 0)
 val = 0;

turn_on_color(val,val,val);


   
}
