/*
@Authors: Caroline Cavalier and Bao Luu
@Description: This is the program that uses the Ceasar Cipher in order to decrypt encoded cipher texts that is inputted
              from the program from the users,returning the decrypted messages by passing the key to the main function,
              and also returning the key value that was used to create the cipher text which is placed in the program by the users
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

    string text, temp;     // declaring a string variable
    string decrypted_text; // declaring a string variable for the decypted message

    while (getline(cin, temp)) // each of the line inputs are stored in the temp string variable.
    {
        text = text + temp;

        char text_chars;          // declaring a character type variable
        int key_applied_nums = 0; // declaring a integer type variable to keep track of the key

        // looping through the line of input string
        for (int i = 0; i < temp.length(); i++) // loop to iterate through the text sring
        {
            temp[i] = tolower(temp[i]); // converting all the characters in the input string to lowercases for later conversion

            // if the text includes whitespaces, append it directly to the decrypted string
            if (isspace(temp[i]) == true)
            {
                decrypted_text += temp[i];
            }
            else
            {

                text_chars = temp.at(i) - 97; // converts all of the characters from there ACII values within a range from 0-25
                int converted = int(text_chars);

                // shifting the integer values using the input key
                int key_applied_nums = (converted - input_key) + 26;
                int shifted_ints = key_applied_nums % 26;

                int decrypted_ascii = shifted_ints + 97; // converts the values back to their ACII values before they are added to the final string.

                decrypted_text += char(decrypted_ascii); // concatenates the decrypted text to the decrypted text variable.
            }
        }
        // after each line has been processed in the while loop, stop and move to a new line and continue the decryption process
        decrypted_text += "\n";
    }
    cout << decrypted_text << endl;
}

int main(int argc, char *argv[])
{

    int key; // initalizing the key value

    if (argc > 1) // if the argument is greater than one
    {
        key = atoi(argv[1]); // uses the a to i function
    }
    else
    {
        key = 3; // else than the key value is just equal to 3
    }

    decryption(key); // calls the function in main

    return 0; // returns zero to terminate the program.
}