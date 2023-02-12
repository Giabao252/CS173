// this file is for drafting and testing purposes
#include <iostream>
using namespace std;

void convert_to_int(string input_text) {
    for (int i = 0; i < input_text.length(); i++)
    {   
        input_text[i] = tolower(input_text[i]);
        if ( input_text[i] == ' '){
            continue;
        }
        char x = input_text.at(i) - 97;
        int converted = int(x);
    }
}

int main()
{   
    string text;
    getline(cin, text);
    convert_to_int(text);

    return 0;
}