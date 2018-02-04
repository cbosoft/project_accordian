/**
 * Project Accordian: Key Map
 * 
 * QWERTY-ish Mapping
 * A keymap where each 8-key subgroup reflects a portion of a QWERTY keyboard
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

#include "acc_ascii.h"

const int PINS[18] = {
  0,  1,  2,  3,  // LEFT  (Index to Pinky)
  4,  6,  8, 10,  // RIGHT (Tips, Index to Pinky)
  5,  7,  9, 16,  // RIGHT (Mids, Index to Pinky)
  A0, A1,         // MODS  (Left, Super + Shift)
  A2, A3          // MODS  (Right, Alt + Ctrl)
};
  
const int KEYS[128] = {
  // Navigation (+ F keys)
  ACC_RETURN, ACC_UP_ARROW, ACC_ESC, ACC_TAB, // RET   UP    ESC    TAB
  ACC_LEFT_ARROW, ACC_DOWN_ARROW, ACC_RIGHT_ARROW, ACC_TAB, // LEFT  DOWN  RIGHT  TAB
  
  ACC_INSERT, ACC_HOME, ACC_PGUP, ACC_NULL, // INS HOME PGUP --
  ACC_DEL, ACC_END, ACC_PGDN, ACC_NULL, // DEL END PGDN --
  
  ACC_F1, ACC_F2, ACC_F3, ACC_F4, // F1 to F4
  ACC_F5, ACC_F6, ACC_F7, ACC_F8, // F5 to F8
  
  ACC_F9, ACC_F10, ACC_F11, ACC_F12, // F9 to F12
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 

  // Main qwerty
  ACC_Q, ACC_W, ACC_E, ACC_R, // Q W E R
  ACC_A, ACC_S, ACC_D, ACC_F, // A S D F
   
  ACC_T, ACC_Y, ACC_U, ACC_I, // T Y U I
  ACC_G, ACC_H, ACC_J, ACC_K, // G H J K 
  
  ACC_O, ACC_P,  ACC_OPEN_BRACKET_SQUARE,  ACC_CLOSE_BRACKET_SQUARE, // O P [ ]
  ACC_L,  ACC_SEMI_COLON, ACC_APOSTROPHE,  ACC_HASH, // L ; ' #
  
  ACC_Z, ACC_X, ACC_C, ACC_V, // Z X C V
  ACC_B, ACC_N, ACC_M, ACC_COMMA, // B N M ,
  
  // Numbers, math, programming
  ACC_0, ACC_1, ACC_3, ACC_4, // 0 1 2 3
  ACC_PLUS, ACC_FORWARDSLASH, ACC_ASTERISK, ACC_MINUS, // + / * -
   
  ACC_4, ACC_5, ACC_6, ACC_7, // 4 5 6 7
  ACC_8, ACC_9, ACC_PERIOD, ACC_EQUALS, // 8 9 . =
   
  ACC_TAB, ACC_RETURN, ACC_BACKSPACE, ACC_SPACE, // TAB RET BKSPC SPC
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 
    
  ACC_TICK, ACC_BACKSLASH, ACC_OPEN_BRACKET, ACC_CLOSE_BRACKET, // ` \ ( )
  ACC_OPEN_BRACKET_SQUARE, ACC_CLOSE_BRACKET_SQUARE, ACC_OPEN_BRACKET_CURLY, ACC_CLOSE_BRACKET_CURLY, // [ ] { } 
  
  // Null block
  ACC_BACKSPACE, ACC_DEL, ACC_NULL, ACC_NULL, // 
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 
    
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 
    
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 
    
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL, // 
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL // 
};
  
const int MOD_KEYS[4] = {
  ACC_SUPER, 
  ACC_SHIFT, 
  ACC_ALT, 
  ACC_CTRL
}; 
