#include "get_constant_k.h"
#include "hex_to_bin.h"

string get_constant_k(int round)
{
    string k;
    if(round <= 19) {
        k = hex_to_bin("5A827999");
    }
    else if(round <= 39) {
        k = hex_to_bin("6ED9EBA1");
    }
    else if(round <= 59) {
        k = hex_to_bin("8F1BBCDC ");
    }
    else {
        k = hex_to_bin("CA62C1D6");
    }
    return k;
}