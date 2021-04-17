#include <FastLED.h>
#define LED_PIN  7
#define NUM_LEDS 25
#define DELAY 5000

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {

  for(int i =0;i<6;i++){
//    fade();
    pickFuncion(i);
    FastLED.show();
  }

}

void pickFuncion(int i){

  switch (i) {
  case 0:
  default:
    snake();
    delay(500);
    break;
  case 1:
    spotty();
    delay(DELAY);
    break;
  case 2:
    grad();
    delay(DELAY);
    break;
  case 3:
    blueSpec();
    delay(500);
    break;
   case 4:
    randShow();
    delay(500);
   case 5:
    sweep();
    delay(500);
    break;
   case 6:
    climb();
    delay(500);
    break;
   case 7:
    climb();
    delay(500);
    break;
  }

}

void white(){
  for(int i = 0; i< NUM_LEDS;i++){
  leds[i] = CRGB(200, 200, 200);

  }
}


void spotty(){
  int h = 0;
  for(int i = 0; i< NUM_LEDS;i++){
  leds[i] = CHSV(h, 150, 255);
  h+=60;
  }
}


void grad(){
  int h = 0;
  for(int i = 0; i< NUM_LEDS;i++){
  leds[i] = CHSV(h, 180, 200);
  h+=14;
  }
}


void blueSpec(){


  for(int i = 0; i< NUM_LEDS;i++){
    for(int i = 0; i< NUM_LEDS;i++){
    int s = random(120,230);
    int v = random(120,230);
    int h = 120 + random(0,30);
    leds[i] = CHSV(h, s, v);
    }
    delay(200);
    FastLED.show();
  }
}


void snake(){
  for(int i = 0; i< NUM_LEDS;i++){
    leds[i] = CHSV(200, 200, 20);
  }
  FastLED.show();

  for(int i = 0; i< NUM_LEDS;i++){
    leds[i] = CHSV(200, 200, 255);
    FastLED.show();
    delay(200);
  }
}


void randShow(){
  bool on[NUM_LEDS];

  for(int i = 0; i< NUM_LEDS;i++){
    on[i] = false;
  }


  for(int i = 0; i< NUM_LEDS;i++){
    leds[i] = CHSV(150, 200, 20);
  }
  FastLED.show();

  for(int i = 0; i< NUM_LEDS;i++){
    int ran = random(NUM_LEDS);
    if(on[ran] == true){
      continue;
    }
    on[ran] = true;

    leds[ran] = CHSV(250, 200, 255);
    FastLED.show();
    delay(200);
  }
}

void fade(){
  int v =0;


  FastLED.show();
  for(int i = 0; i<255;i++){
    v++;
    for(int i = 0; i< NUM_LEDS;i++){
      int ran = random(NUM_LEDS);


      leds[ran] = CHSV(250, 200, v);
      FastLED.show();
      delay(1);
    }
  }
}


void climb(){
  for(int i = 0; i< NUM_LEDS;i++){
    leds[i] = CHSV(100, 200, 255);
  }
  FastLED.show();

  for(int i = 0; i< NUM_LEDS;i++){
    leds[i] = CHSV(200, 200, 255);
    FastLED.show();
        if(i%5 == 0){
          delay(200);
    }

  }
}

void sweep(){
  for(int k = 0; k < 2;k++){
  for(int i = 0; i< NUM_LEDS;i++){
    leds[i] = CHSV(150, 200, 255);
  }
  FastLED.show();

  for(int i = 0; i < NUM_LEDS;i+=5){
    for(int j = 0; j < 5;j++){
      leds[i+j] = CHSV(00, 200, 255);
    }

    FastLED.show();
    delay(100);
    for(int j = 0; j < 5;j++){
      leds[i+j] = CHSV(150, 200, 255);
    }
  }
delay(100);
  for(int i = NUM_LEDS -5; i > -5;i-=5){
    for(int j = 0; j < 5;j++){
      leds[i+j] = CHSV(00, 200, 255);
    }

    FastLED.show();
    delay(100);
    for(int j = 0; j < 5;j++){
      leds[i+j] = CHSV(150, 200, 255);
    }
  }
  }
}