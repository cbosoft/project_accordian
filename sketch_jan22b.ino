#include "Keyboard.h"

// see https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
const int PINS[18] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, A0, A1, A2, A3, A4, A5};
const int KEYS[] = {
   97,  98,  99, 100, 101, 102, 103, 104, // ALPHA1 // ABCD EFGH
  105, 106, 107, 108, 109, 110, 111, 112, // ALPHA2 // IJKL MNOP
  113, 114, 115, 116, 117, 118, 119, 120, // ALPHA3 // QRST UVWX
  121, 122,   0,   0,   0,   0,   0,   0, // ALPHA4 // YZ
   48,  49,  50,  51,  52,  53,  54,  55, // MATHS1 // 0123 4567
   56,  57,  43,  45,  42,  47,  94,  61, // MATHS2 // 89+- */^=
   40,  41,  37,  36,  60,  62,  33, 126, // SYMBS1 // ()%$ <>!~
   44,  46,  63,  34,  58,  59,  39,  35, // SYMBS2 //,.?" :;'#
   64,  38,  91,  93, 123, 125, 124,  92, // SYMBS3 // @&[] {}|\
    0,   0,   0,   0,   0,   0,   0,   0, // NULL
    0,   0,   0,   0,   0,   0,   0,   0, // NULL
    0,   0,   0,   0,   0,   0,   0,   0, // TAB RETURN BKSPC DEL   ESC
  216, 218, 217, 215, 210, 213, 211, 214, // LEFT UP DOWN RIGHT   HOME END PGUP PGDN
  194, 195, 196, 197, 198, 199, 200, 201, // F1 F2 F3 F4  F5 F6 F7 F8
  202, 203, 204, 205,   0,   0,   0,   0  // F9 F10 F11 F12
  };
const int MOD_KEYS[5] = {128, 129, 130, 131, 132}; // CTRL SHIFT ALT SUPER

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 18; i++){
    pinMode(PINS[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //bool typed = false;
  int typed = 0;
  
  for (int j = 4; j < 12; j++){
    if (digitalRead(PINS[j])){
      typed += j - 3;
      
      for (int i = 0; i < 8; i++){
        if (digitalRead(PINS[i])){
          typed += pow(2, i);
        }
      }

      for (int i = 12; i < 18; i++){
        if (digitalRead(PINS[i])){
          typed += (i - 11) * 1000;
        }
      }
      
      break;
    }
  }

  if (typed){

    int modif = typed / 1000;

    if (modif){
      Keyboard.press(MOD_KEYS[modif - 1]);
    }

    Keyboard.press(KEYS[typed - 1]);
    delay(50);
    Keyboard.releaseAll();
  }
}












