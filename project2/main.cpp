/*

@Authors: Bao Luu
@Description: This program takes 4 inputs that represents the length the on-off lighting cycles of Lionel Messi's two security
              flood lights, and the time after midnight when the UPS package arrives, all in minutes and integer type. At the time
              (after midnight) that the UPS package arrives, the program will outputs BOTH if both lights are on, ONE if only one
              is on and NONE otherwise.

@Date: 2023/01/28
@Updated: 2023/02/01

*/

// importing libraries
#include <iostream>
using namespace std;

//declaring the main() function that contains all our code and logic
int main()
{

  // declaring variables that stores the input values
  int t1_on;
  int t1_off;

  int t2_on;
  int t2_off;

  int t_ups;

  // prompt users to input the expected values
  cin >> t1_on >> t1_off;
  cin >> t2_on >> t2_off;
  cin >> t_ups;

  //determine each light's lighting cycles  
  int cycle1 = t1_on + t1_off;
  int cycle2 = t2_on + t2_off;

  /*
  Now, for each light, we have to check how many cycles it takes to reach the t_ups level , and where the
  package's arrival is in the last cycle of that time period by getting the remainder between t_ups and 
  each cycle, storing them in two ups_in_cycle<number> variables 
  */

  int ups_in_cycle1 = t_ups % cycle1;
  int ups_in_cycle2 = t_ups % cycle2;

  /*
  if, from midnight to the time the package arrives, the package's arrival is <ups_in_cycle> minutes
  in the final cycle, we will compare it to the time the lights are on during that cycle. If it's smaller,
  then its when the light is on. If it's equal or larger, then its when the light is off.  
  */
  if (ups_in_cycle1 < t1_on && ups_in_cycle2 < t2_on) {
    cout << "BOTH" << endl;
  }
  else if (ups_in_cycle1 < t1_on || ups_in_cycle2 < t2_on ) {
    cout << "ONE" << endl;
  }
  else {
    cout << "NONE" << endl;
  }

  return 0;
}