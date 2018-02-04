/**
 * Project Accordian: ASCII Table (extended)
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

// All characters here are lowercase, unless otherwise stated
// see: http://www.asciitable.com/ and https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/ for more information

const int ACC_NULL = 0;

// characters
const int ACC_A = 97;
const int ACC_B = 98;
const int ACC_C = 99;
const int ACC_D = 100;
const int ACC_E = 101;
const int ACC_F = 102;
const int ACC_G = 103;
const int ACC_H = 104;
const int ACC_I = 105;
const int ACC_J = 106;
const int ACC_K = 107;
const int ACC_L = 108;
const int ACC_M = 109;
const int ACC_N = 110;
const int ACC_O = 111;
const int ACC_P = 112;
const int ACC_Q = 113;
const int ACC_R = 114;
const int ACC_S = 115;
const int ACC_T = 116;
const int ACC_U = 117;
const int ACC_V = 118;
const int ACC_W = 119;
const int ACC_X = 120;
const int ACC_Y = 121;
const int ACC_Z = 122;

// numbers
const int ACC_0 = 48;
const int ACC_1 = 49;
const int ACC_2 = 50;
const int ACC_3 = 51;
const int ACC_4 = 52;
const int ACC_5 = 53;
const int ACC_6 = 54;
const int ACC_7 = 55;
const int ACC_8 = 56;
const int ACC_9 = 57;

// symbols (including those obtained by shift+[key])
const int ACC_TICK = 96;
const int ACC_MINUS = 45;
const int ACC_PLUS = 43;
const int ACC_OPEN_BRACKET_SQUARE = 91;
const int ACC_CLOSE_BRACKET_SQUARE = 93;
const int ACC_COLON = 58;
const int ACC_SEMI_COLON = 59;
const int ACC_APOSTROPHE = 39;
const int ACC_HASH = 35;
const int ACC_COMMA = 44;
const int ACC_PERIOD = 46;
const int ACC_BACKSLASH = 92;
const int ACC_FORWARDSLASH = 47;
const int ACC_ASTERISK = 42;
const int ACC_EXCLAMATION_MARK = 33;
const int ACC_DOUBLE_QUOTE = 34;
const int ACC_DOLLAR = 36;
const int ACC_PERCENTAGE = 37;
const int ACC_CIRCUMFLEX = 94;
const int ACC_AMPERSAND = 38;
const int ACC_UNDERSCORE = 95;
const int ACC_EQUALS = 61;
const int ACC_OPEN_BRACKET = 40;
const int ACC_CLOSE_BRACKET = 41;
const int ACC_OPEN_BRACKET_CURLY = 123;
const int ACC_CLOSE_BRACKET_CURLY = 125;
const int ACC_AT = 64;
const int ACC_TILDE = 126;
const int ACC_LESS_THAN = 60;
const int ACC_GREATER_THAN = 62;
const int ACC_QUESTION_MARK = 63;
const int ACC_PIPE = 124;

// functions
const int ACC_F1 = 194;
const int ACC_F2 = 195;
const int ACC_F3 = 196;
const int ACC_F4 = 197;
const int ACC_F5 = 198;
const int ACC_F6 = 199;
const int ACC_F7 = 200;
const int ACC_F8 = 201;
const int ACC_F9 = 202;
const int ACC_F10 = 203;
const int ACC_F11 = 204;
const int ACC_F12 = 205;

// other
const int ACC_RETURN = 176;
const int ACC_SPACE = 32;
const int ACC_BACKSPACE = 178;
const int ACC_DEL = 212;
const int ACC_INSERT = 209;
const int ACC_HOME = 210;
const int ACC_END = 213;
const int ACC_PGUP = 211;
const int ACC_PGDN = 214;
const int ACC_TAB = 179;
const int ACC_ESC = 177;
const int ACC_LEFT_ARROW = 216;
const int ACC_RIGHT_ARROW = 215;
const int ACC_UP_ARROW = 218;
const int ACC_DOWN_ARROW = 217;

// modifiers
const int ACC_CTRL = 128;
const int ACC_SHIFT = 129;
const int ACC_ALT = 130;
const int ACC_SUPER = 131;
const int ACC_RIGHT_CTRL = 132;
const int ACC_RIGHT_SHIFT = 133;
const int ACC_RIGHT_ALT = 134;
const int ACC_RIGHT_SUPER = 135;
