#include "encrypt.h"
#include "padding.h"
#include "append_length.h"
#include "hex_to_bin.h"
#include "get_constant_k.h"
#include "get_process_p.h"
#include "get_w.h"
#include "shift_left.h"
#include "binary_add.h"

#include "bin_to_hex.h"

string encrypt(string input) 
{
    string padded_input = padding(input);
    input = append_length(input, padded_input);
    int n = input.length() / 512;
    
    // string a = hex_to_bin("01234567");
    // string b = hex_to_bin("89ABCDEF");
    // string c = hex_to_bin("FEDCBA98");
    // string d = hex_to_bin("76543210");
    // string e = hex_to_bin("C3D2E1F0");

    string a = hex_to_bin("67452301");
    string b = hex_to_bin("EFCDAB89");
    string c = hex_to_bin("98BADCFE");
    string d = hex_to_bin("10325476");
    string e = hex_to_bin("C3D2E1F0");

    cout<<"abcde = "<<bin_to_hex(a)<<" "<<bin_to_hex(b)<<" "<<bin_to_hex(c)<<" "<<bin_to_hex(d)<<" "<<bin_to_hex(e)<<endl;

    string h0 = a;
    string h1 = b;  
    string h2 = c;
    string h3 = d;
    string h4 = e;

    for(int i = 0; i < n; i++) {
        string block = input.substr(i * 512, 512);
        string* w = get_w(block);
        for(int j = 0; j < 80; j++) {
            cout << "iter "<<j<<": ";
            string p = get_process_p(j, b, c, d);
            string k = get_constant_k(j);

            // string temp = binary_add(e, p, shift_left(a, 5), *(w + j), k);
            string temp = binary_add(binary_add(binary_add(binary_add(e, p), shift_left(a, 5)), *(w + j)), k);
            e = d;
            d = c;
            c = shift_left(b, 30);
            b = a;
            a = temp;

            cout<<bin_to_hex(a)<<" "<<bin_to_hex(b)<<" "<<bin_to_hex(c)<<" "<<bin_to_hex(d)<<" "<<bin_to_hex(e)<<endl;
        }
        h0 = binary_add(h0, a);
        h1 = binary_add(h1, b);
        h2 = binary_add(h2, c);
        h3 = binary_add(h3, d);
        h4 = binary_add(h4, e);
    }
    string message_digest = h0 + h1 + h2 + h3 + h4;
    return message_digest;
}