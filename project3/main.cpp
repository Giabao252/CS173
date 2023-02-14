/*

@Authors: Bao Luu and Caroline Cavalier
@Description: This is the program that uses the Ceasar Cipher in order to decrypt encoded cipher texts that is inputted 
              from the program from the users,returning the decrypted messages by passing the key to the main function,
              and also returning the key values that was used to create thecipher text which is placed in the program by the users
@Key: 7
@Quote's author: Lady Gaga (Song: Born This Way)
@Date: 2023/02/07
@Updated: 2023/02/13

*/

// including libraries
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void decryption(int input_key)
{
    // declaring global variables 
    string text, temp;
    string decrypted_text;

    //each line of inputs will be stored in the temp variable 
    while (getline(cin, temp))
    {
        text = text + temp;

        char text_chars;
        int key_applied_nums = 0;

        //looping through the line of input string 
        for (int i = 0; i < temp.length(); i++)
        {
            temp[i] = tolower(temp[i]); // converting all the characters in the input string to lowercases for later conversion

            // if the text includes whitespaces, append it directly to the decrypted string
            if (isspace(temp[i]) == true)
            {
                decrypted_text += temp[i];
            }
            else
            {
                // converting characters to integers of range 0 to 25
                text_chars = temp.at(i) - 97;
                int converted = int(text_chars);

                // shifting the integer values using the input key
                int key_applied_nums = (converted - input_key) + 26;
                int shifted_ints = key_applied_nums % 26;

                // converting the decrypted representative integers back to ASCII values for final string char conversion
                int decrypted_ascii = shifted_ints + 97;

                decrypted_text += char(decrypted_ascii);
            }
        }
        //after each line has been processed in the while loop, stop and move to a new line and continue the decryption process
        decrypted_text += "\n";
    }
    cout << decrypted_text << endl;
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