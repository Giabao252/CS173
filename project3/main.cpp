/*

@Authors: Daniel Luu and Caroline Cavalier
@Description:

@Key:
@Quote's author:
@Date: 2023/02/07
@Updated: 2023/02/07

*/

// including libraries
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void decryption(int input_key)
{
    // Reading several lines of inputs as the ciphertext has newlines
    string text, temp;
    while (getline(cin, temp))
    {
        text = text + temp;
    }
    
    int key_applied_nums = 0;

    for (int i = 0; i < text.length(); i++)
    {
        // converting all the characters in the input string to lowercases for later conversion
        text[i] = tolower(text[i]);

        // if the text includes spaces/tabs/newlines, skip
        if (text[i] == ' ')
        {
            continue;
        }

        // converting characters to integers of range 0 to 25
        char x = text.at(i) - 97;
        int converted = int(x);

        //cout << converted << endl;

        int key_applied_nums = (converted - input_key) + 26;

        int cleaned_nums = key_applied_nums % 26;

        //cout << cleaned_nums << endl;
        int ascii = cleaned_nums + 97;

        string decrypted_text;
        decrypted_text = decrypted_text + char(ascii);

        cout << decrypted_text << endl;
    }
    
}

int main(int argc, char *argv[])
{
    // reading the key value
    int key;

    if (argc > 1)
    {
        key = atoi(argv[1]);
    }
    else
    {
        key = 3;
    }

    // calling the function
    decryption(key);

    return 0;
}