#include <iostream> 
#include <string>
#include <cctype>
#include <array>
using namespace std;

//Prototyping functions
void index_search();

int main() {

    //taking the inputs
    string DNA_string, fragments;
    int n, temp;

    cin >> DNA_string;
    cin >> n;

    while (temp <= n) {
        cin >> fragments;
        temp += 1;
    }

    return 0;
}