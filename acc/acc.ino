#include <Keyboard.h>
#define DEBUG
// see https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
const int PINS[18] = {
   0,  1,  2,  3,  // LEFT (1-4)
   4,  5,  6,  7,  // RIGHT (TIPS)
   8,  9, 10, 16,  // RIGHT (MIDS)
  A0, A1, A2, A3, A4, A5
  };
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
  179, 176, 178, 212,  32, 177,   0,   0, // TAB RETURN BKSPC DEL   SPACE ESC
  216, 218, 217, 215, 210, 213, 211, 214, // LEFT UP DOWN RIGHT   HOME END PGUP PGDN
  194, 195, 196, 197, 198, 199, 200, 201, // F1 F2 F3 F4  F5 F6 F7 F8
  202, 203, 204, 205,   0,   0,   0,   0  // F9 F10 F11 F12
  };
const int MOD_KEYS[4] = {128, 129, 130, 131}; // CTRL SHIFT ALT SUPER

int r_key = 0;
int typed = 0;  
bool pressed = false;

void setup() {
  for (int i = 0; i < 18; i++){
    pinMode(PINS[i], INPUT_PULLUP);
  }
}

void loop() {
  if (pressed){
    if (!digitalRead(PINS[r_key + 4])){
      delay(10); // prevents ghosting
      return;
    }
    else {
      r_key = 0;
      typed = 0;
      pressed = false;
    }
  }
  
  for (int i = 0; i < 8; i++){
    if (!digitalRead(PINS[4+i])){
      r_key = i;
      
      #ifdef DEBUG
      Serial.print(" Typed [");
      Serial.print(r_key);
      Serial.print("]\n");
      #endif
      
      pressed = true;
      break;
    }
  }

  if (!pressed){
    
    #ifdef DEBUG
    Serial.write(" Nothing pressed\n");
    #endif
    
    delay(100);
  }
  else{
    
    #ifdef DEBUG
    Serial.write(" Key down\n");
    Serial.write(" \tChecking group...\n");
    #endif
    
    int group = 0;
    for (int i = 0; i < 4; i++){
      if (!digitalRead(PINS[i])){
        group += pow(2, i);
      }
    }
    
    #ifdef DEBUG
    Serial.write(" \tGroup: ");
    Serial.print(group);
    Serial.write("\n");
    #endif
    
    for (int i = 12; i < 18; i++){
      if (!digitalRead(PINS[i])){
        Keyboard.press(MOD_KEYS[i - 12]);
      }
      else{
        Keyboard.release(MOD_KEYS[i - 12]);
      }
    }
    typed = (group * 8) + r_key;

    #ifdef DEBUG
    Serial.print("\n\tID ");
    Serial.print(typed);
    Serial.print("\n\tKEY ");
    Serial.print(char(KEYS[typed]));
    #endif
    
    Keyboard.press(KEYS[typed]);
    delay(50);
    Keyboard.release(KEYS[typed]);

    #ifdef DEBUG
    Serial.write("\n");
    #endif
  }
}









