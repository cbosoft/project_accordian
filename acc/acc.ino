/**
 * Project Accordian
 *  
 * Software version 1.2
 *  
 * See https://www.github.com/cbosoft/project_accordian
 * 
 * This work is licensed under CC-BY-NC-SA (https://creativecommons.org/licenses/by-nc-sa/3.0/).
 * 
 * This means do are free to use, alter, and pass along this work as long as it is not used for 
 * commercial purposes, you give me some credit, and subsequent products have this (or a compatible)
 * license.
*/

#include <Keyboard.h>
#include "acc_keymap_std.h"
//#include "acc_keymap_qwertyish.h"
//#define DEBUG

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









