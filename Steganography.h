#pragma once
#include <string>
using namespace std;
class Steganography {
    
private:
    string file_container;
    string file_message;
    string file_new;
public:
    int extraction(string file_container);
    int concealment(string file_container, string file_message);
    };
