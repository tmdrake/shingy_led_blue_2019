// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<back.numPixels(); i++) {
      back.setPixelColor(i, c);
      back.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {

    
    for(i=0; i<back.numPixels(); i++) {
      back.setPixelColor(i, Wheel((i+j) & 255));
    }
    back.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
//void rainbowCycle(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< back.numPixels(); i++) {
//      back.setPixelColor(i, Wheel(((i * 256 / back.numPixels()) + j) & 255));
//    }
//    back.show();
//    delay(wait);
//  }
//}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < back.numPixels(); i=i+3) {
        back.setPixelColor(i+q, c);    //turn every third pixel on
      }
      back.show();
     
      delay(wait);
     
      for (int i=0; i < back.numPixels(); i=i+3) {
        back.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < back.numPixels(); i=i+3) {
          back.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        back.show();
       
        delay(wait);
       
        for (int i=0; i < back.numPixels(); i=i+3) {
          back.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return back.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return back.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return back.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}


