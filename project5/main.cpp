/*
@Authors: Bao Luu and Levi Liu
@Description: This program searches a DNA string for occurrences of any 
              given fragments and return the first index of the matched 
              fragments. It also reports overlap between fragments
@Date: 2023/03/04
@Updated: 2023/03/06
*/

//Importing libraries
#include <iostream> 
#include <string>
#include <cstring>
#include <array>
using namespace std;

const int s = 100; //declaring the variable holding the size of the arrays which satisfies the constraints

//Prototyping functions
int DNA_search(char fragment[], char donor_string[], int fragment_size, int donor_size);
void reverse(char fragment[]);
bool overlap(char fragment[], int matched_indexes[], int first_index);

int main() {

    //declaring variables
    int n;
    char fragments_inputPanel;
    char donor_string[s];
    char fragment[s];
    int matched_indexes[s];
    for (int i = 0; i < s; i++) {
        matched_indexes[i] = 0;
    }
    bool overlap_spotted;

    cin.get(donor_string, s + 1);
    cin.get(fragments_inputPanel);
    cin >> n;

    while(n--) {
        cin.get(fragments_inputPanel);
        cin.get(fragment, s + 1);

        int index = 0;
        while(fragment[index]) {
            cout << fragment[index];
            index++;
        }
        
        //Using the DNA_search function to forward search the fragments in the donor string
        int forward_search;
        forward_search = DNA_search(fragment, donor_string, strlen(fragment), strlen(donor_string));

        //for searching backwards, reverse the inputted fragments and then search forward to find the reversed fragments
        int backward_search;
        reverse(fragment);
        backward_search = DNA_search(fragment, donor_string, strlen(fragment), strlen(donor_string));

        cout << " " << "is";

        //Determining the left most index of a fragment in the donor string
        int leftmost_index = -1;

        if (backward_search != -1 && forward_search != -1) {
            if (forward_search <= backward_search) {
                leftmost_index = forward_search;
            } 
            else {
                leftmost_index = backward_search;
            }
        }
        else if (forward_search == -1) {
            if (backward_search == -1) {
                leftmost_index = -1;
            }
            else {
                leftmost_index = backward_search;
            }
        }
        else if (backward_search == -1) {
            if (forward_search == -1) {
                leftmost_index = -1;
            }
            else {
                leftmost_index = forward_search;
            }
        }

        if (leftmost_index == -1) {
            cout << " not found" << endl;
        }
        else {
            overlap_spotted = overlap(fragment, matched_indexes, leftmost_index);
            if (overlap_spotted == true) {
                cout << " found at index " << leftmost_index << " overlap" << endl;
            }
            else {
                cout << " found at index " << leftmost_index << endl;
            }
        }

    }
    return 0;
}

/*
FUNCTION 1: DNA_search
Description: This function searches from left to right to determine if the fragment is in the donor string
Parameters: 
    char fragment[]: the array that stores the inputted fragment string that needs to be searched 
    char donor_string[]: the array that stores the donor string that might contains the fragments we're looking for
    int fragment_size: the size of the fragment string
    int donor_string: the size of the donor string
Return values: 
first_index: The index of the first character in the fragment string
*/

int DNA_search(char fragment[], char donor_string[],int fragment_size, int donor_size) {

    int first_index = -1;

    for (int i = 0; i < donor_size; i++) {
        int length = 0;

        if (donor_string[i] == fragment[0]){
            for (int j = 0; j < fragment_size; j++) {
                if (donor_string[i+j] == fragment[j]){
                    length++;
                }
            }
            if (length == fragment_size) {
                first_index = i;
                break;
            }
        }
    }
    return first_index;
}

/*
FUNCTION 2: reverse
Description: This function reverses the inputted fragment array for backward searching purposes
Parameters: 
    char fragment[]: the array that stores the inputted fragment string that needs to be reversed
Return value: none because this is a void function
*/

void reverse(char fragment[]) {
    int start = 0;
    int end = strlen(fragment) - 1;

    while(start < end) {
        int holder = fragment[start];
        fragment[start] = fragment[end];
        fragment[end] = holder;
        start++;
        end--;
    }
}

/*
FUNCTION 3: overlap
Description: This function reports if a fragment overlaps with the location of a previously inputted fragment
Parameters: 
    char fragment[]: the array storing the fragment to be processed
    int matched_indexes[]: the array that keeps track of which character have been matched in the donor string
    int first_index: the first index of the passed fragment in the donor string

*/
bool overlap(char fragment[], int matched_indexes[], int first_index) {
    bool overlap = false;

    for ( int i = first_index; i < (first_index + (strlen(fragment) -1)); i++) {
        if (matched_indexes[i] == 1) {
            overlap = true;
        }
    }

    if (overlap);
    else {
        overlap = false;
    }

    for (int i = first_index; i < (first_index + (strlen(fragment) - 1)); i++) {
        matched_indexes[i] = 1;
    }
    
    return overlap;
}

