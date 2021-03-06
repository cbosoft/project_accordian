/**
 * Project Accordian: Key Map
 * 
 * Standard Mapping
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
  A0, A1,          // MODS  (Left, Super + Shift)
  A2, A3           // MODS  (Right, Alt + Ctrl)
};
  
const int KEYS[128] = {
  ACC_LEFT_ARROW, ACC_UP_ARROW, ACC_DOWN_ARROW, ACC_RIGHT_ARROW,
  ACC_HOME, ACC_END, ACC_PGUP, ACC_PGDN,
  
  ACC_TAB, ACC_RETURN, ACC_BACKSPACE, ACC_DEL,
  ACC_SPACE, ACC_ESC, ACC_NULL, ACC_NULL,
   
  ACC_F1, ACC_F2, ACC_F3, ACC_F4,
  ACC_F5, ACC_F6, ACC_F7, ACC_F8,

  ACC_F9, ACC_F10, ACC_F11, ACC_F12,
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL,

  ACC_A, ACC_B, ACC_C, ACC_D,
  ACC_E, ACC_F, ACC_G, ACC_H,
  
  ACC_I, ACC_J, ACC_K, ACC_L,
  ACC_M, ACC_N, ACC_O, ACC_P,
  
  ACC_Q, ACC_R, ACC_S, ACC_T,
  ACC_U, ACC_V, ACC_W, ACC_X,
  
  ACC_Y, ACC_Z, ACC_NULL, ACC_NULL,
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL,

  ACC_0, ACC_1, ACC_2, ACC_3,
  ACC_4, ACC_5, ACC_6, ACC_7,
   
  ACC_8, ACC_9, ACC_NULL, ACC_NULL,
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL,
    
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL,
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL,
    
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL,
  ACC_NULL, ACC_NULL, ACC_NULL, ACC_NULL,

  ACC_PLUS, ACC_MINUS, ACC_ASTERISK, ACC_FORWARDSLASH,
  ACC_CIRCUMFLEX, ACC_EQUALS, ACC_UNDERSCORE, ACC_NULL,
   
  ACC_OPEN_BRACKET, ACC_CLOSE_BRACKET, ACC_PERCENTAGE, ACC_DOLLAR,
  ACC_LESS_THAN, ACC_GREATER_THAN, ACC_EXCLAMATION_MARK, ACC_TILDE,
   
  ACC_COMMA, ACC_PERIOD, ACC_QUESTION_MARK, ACC_DOUBLE_QUOTE,
  ACC_COLON, ACC_SEMI_COLON, ACC_APOSTROPHE, ACC_HASH,
   
  ACC_AT, ACC_AMPERSAND, ACC_OPEN_BRACKET_SQUARE, ACC_CLOSE_BRACKET_SQUARE,
  ACC_OPEN_BRACKET_CURLY, ACC_CLOSE_BRACKET_CURLY, ACC_PIPE, ACC_BACKSLASH
};

const int MOD_KEYS[4] = {
  ACC_SUPER,
  ACC_SHIFT,
  ACC_ALT,
  ACC_CTRL
}; // SUPER SHIFT ALT CTRL
