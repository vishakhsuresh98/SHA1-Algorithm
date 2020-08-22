#include "alphabet_to_hex.h"

/**
 * Convert a number in English to hexadecimal system
 *
 * @param alpha the input string, in English
 * @returns the equivalent string, in the hexadecimal number system
 */
string alphabet_to_hex(string alpha)
{
    string hex = ""; 
    for (int i = 0; i < alpha.length(); i++) { 
       hex += to_string((int)(alpha[i])); 
    } 
    return hex;
}