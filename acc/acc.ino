#include <Keyboard.h>
/**
 * Project Accordian
 * 
 * See https://www.github.com/cbosoft/project_accordian
 * 
 * This work is licensed under CC-BY-NC-SA (https://creativecommons.org/licenses/by-nc-sa/3.0/).
 * 
 * This means do are free to use, alter, and pass along this work as long as it is not used for 
 * commercial purposes, you give me some credit, and subsequent products have this (or a compatible)
 * license.
*/
//#define DEBUG

const int PINS[18] = {
   0,  1,  2,  3,  // LEFT  (Index to Pinky)
   4,  6,  8, 10,  // RIGHT (Tips, Index to Pinky)
   5,  7,  9, 16,  // RIGHT (Mids, Index to Pinky)
  A0, A1,          // MODS  (Left, Super + Shift)
  A2, A3           // MODS  (Right, Alt + Ctrl)
  };
const int KEYS[] = {                      // PR MI
                                          // 00  -- all fingers released: navigation group
  216, 218, 217, 215, 210, 213, 211, 214, // 00 00 // NAVIG1 // LEFT UP DOWN RIGHT   HOME END PGUP PGDN
  179, 176, 178, 212,  32, 177,   0,   0, // 00 01 // NAVIG2 // TAB RETURN BKSPC DEL   SPACE ESC
  194, 195, 196, 197, 198, 199, 200, 201, // 00 10 // FUNCS1 // F1 F2 F3 F4  F5 F6 F7 F8
  202, 203, 204, 205,   0,   0,   0,   0, // 00 11 // FUNCS2 // F9 F10 F11 F12

                                          // 01  -- ring finger down, pinky released: alphabet group
   97,  98,  99, 100, 101, 102, 103, 104, // 01 00 // ALPHA1 // ABCD EFGH
  105, 106, 107, 108, 109, 110, 111, 112, // 01 01 // ALPHA2 // IJKL MNOP
  113, 114, 115, 116, 117, 118, 119, 120, // 01 10 // ALPHA3 // QRST UVWX
  121, 122,   0,   0,   0,   0,   0,   0, // 01 11 // ALPHA4 // YZ

                                          // 10  -- pinky finger down, ring released: math group
   48,  49,  50,  51,  52,  53,  54,  55, // 10 00 // MATHS1 // 0123 4567
   56,  57,   0,   0,   0,   0,   0,   0, // 10 01 // MATHS2 // 89
    0,   0,   0,   0,   0,   0,   0,   0, // 10 10 // --
    0,   0,   0,   0,   0,   0,   0,   0, // 10 11 // --

                                          // 11  -- both fingers down: symbols group
   43,  45,  42,  47,  94,  61,   95,   0, // 11 00 // SYMBS1 // +-*/ ^=_
   40,  41,  37,  36,  60,  62,  33, 126, // 11 01 // SYMBS2 // ()%$ <>!~
   44,  46,  63,  34,  58,  59,  39,  35, // 11 10 // SYMBS3 //,.?" :;'#
   64,  38,  91,  93, 123, 125, 124,  92  // 11 11 // SYMBS4 // @&[] {}| (backslash)
  };
const int MOD_KEYS[4] = {131, 129, 130, 128}; // SUPER SHIFT ALT CTRL

int pressed_key = 0;
int typed = 0;  
bool pressed = false;
int count = 0;
const int holddelay = 30;

void setup() {
  for (int i = 0; i < 18; i++){
    pinMode(PINS[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 12; i < 18; i++){
    if (!digitalRead(PINS[i])){
      Keyboard.press(MOD_KEYS[i - 12]);
    }
    else{
      Keyboard.release(MOD_KEYS[i - 12]);
    }
  }
  
  if (pressed){
    if (!digitalRead(PINS[pressed_key + 4])){
      delay(10); // prevents ghosting
      count += 1;
      if (count >= holddelay){
        count = holddelay;
      }
      else{
        return;
      }
    }
    else {
      pressed_key = 0;
      typed = 0;
      count = 0;
      pressed = false;
    }
  }
  
  for (int i = 0; i < 8; i++){
    if (!digitalRead(PINS[4+i])){
      pressed_key = i;
      
      #ifdef DEBUG
      Serial.print(" Typed [");
      Serial.print(pressed_key);
      Serial.print("]\n");
      #endif
      
      pressed = true;
      break;
    }
  }

  if (!pressed){
    
    #ifdef DEBUG
    //Serial.write(" Nothing pressed\n");
    #endif
    
    delay(100);
  }
  else{
    
    #ifdef DEBUG
    Serial.write(" Key down\n");
    Serial.write(" \tChecking group...");
    #endif
    
    int group = 0;
    for (int i = 0; i < 4; i++){

      #ifdef DEBUG
      Serial.write("\n\t Switch ");
      Serial.print(i);
      Serial.write(" (v: ");
      Serial.print(pow(2, i));
      #endif
      
      if (!digitalRead(PINS[i])){
        #ifdef DEBUG
        Serial.write(") closed");
        Serial.write("\n\t Group = Group + s^i");
        Serial.write("\n\t Group = ");
        Serial.print(group);
        Serial.write(" + ");
        Serial.print(pow(2,i));
        Serial.write(" = ");
        Serial.print(group);
        #endif

        group = group + int(ceil(pow(2.0, double(i))));

        #ifdef DEBUG
        Serial.write(" = ");
        Serial.print(group);
        #endif
      }
      else {
        #ifdef DEBUG
        Serial.write(") open");
        #endif
      }
    }
    
    #ifdef DEBUG
    Serial.write(" \n\tGroup: ");
    Serial.print(group);
    Serial.write("\n");
    #endif
    
    typed = (group * 8) + pressed_key;

    #ifdef DEBUG
    Serial.print("\n\tIndex ");
    Serial.print(typed);
    Serial.print("\n\tKey Ascii ");
    Serial.print(KEYS[typed]);
    #endif
    
    Keyboard.press(KEYS[typed]);
    delay(50);
    Keyboard.release(KEYS[typed]);

    #ifdef DEBUG
    Serial.write("\n");
    #endif
  }
}









