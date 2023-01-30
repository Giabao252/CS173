/*

@Authors: Bao Luu
@Description: This program takes 4 inputs that represents the length the on-off lighting cycles of Lionel Messi's two security
              flood lights, and the time after midnight when the UPS package arrives, all in minutes and integer type. At the time
              (after midnight) that the UPS package arrives, the program will outputs BOTH if both lights are on, ONE if only one
              is on and NONE otherwise.

@Date: 2023/01/28
@Updated: 2023/01/28

*/

// importing libraries
#include <iostream>
using namespace std;

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

  // time starts from 0 at midnight
  int timestamp1 = 0;
  int timestamp2 = 0;

  // we use the lights' activity cycle to track the time the package arrives
  int cycle1 = t1_on + t2_off;
  int cycle2 = t2_on + t2_off;

  while (timestamp1 < 1440 && timestamp2 < 1440)
  {
    timestamp1 += cycle1;
    timestamp2 += cycle2;

    if (timestamp1 == 1440 && timestamp2 == 1440) {
      timestamp1 = timestamp1 - 1440;
      timestamp2 = timestamp2 - 1440;
    }
  }

  //keep track of how many times the lighting cycles are repeated during the 1440 mins period
  int n1 = timestamp1 / cycle1;
  int n2 = timestamp2 / cycle2;


  return 0;
}