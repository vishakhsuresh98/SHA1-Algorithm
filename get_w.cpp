#include "get_w.h"
#include "binary_xor.h"
#include "shift_left.h"

// 512 bit msg block as input
string* get_w(string input)
{
    static string w[80] = {};
    for(int i = 0; i < 16; i++) {
        w[i] = input.substr(i * 32, 32);
        // cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }
    for(int i = 16; i < 80; i++) {
        w[i] = shift_left(binary_xor(binary_xor(w[i-16], w[i-14]), binary_xor(w[i-8], w[i-3])) ,1);
        // cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }
    return w;
}