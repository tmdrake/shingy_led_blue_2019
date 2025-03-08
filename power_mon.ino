
//Monitors power supply voltage, and flashes red if there is a problem

void checkpower()
{
  long val = analogRead(PWR_V);
  
  //now to get the val into voltage
  
  float voltage = val * 0.01728723404255319148936170212766;
  
  Serial.print(F("Battery:"));
  Serial.print(voltage);
  Serial.println(F("V"));
//  
  //Check if voltage is below 9 volts and do a cutoff mode

  //Serial.println(F("L10 0 3")); 

  
  if (voltage < 9) 
  {
    pwr_shutdown();
  }

  
  
}

void pwr_shutdown()
{
    Serial.println(F("Battery Discharged!"));
    static boolean last;
    last = !last;
    if (last)
      pinMode(PWR_EN, INPUT);
    else
     pinMode(PWR_EN, OUTPUT); 
    
    
  
  
}


