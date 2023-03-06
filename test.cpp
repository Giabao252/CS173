#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  const int MAX_DNA = 100;
  const int MAX_FRAGMENTS = 100;
  char dna[MAX_DNA + 1], fragment[MAX_DNA + 1], reverseFragment[MAX_DNA + 1];
  int n;
  cin >> dna >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> fragment;
    int len = strlen(fragment);
    bool found = false;
    for (int j = 0; j < strlen(dna) - len + 1; j++)
    {
      if (strncmp(dna + j, fragment, len) == 0)
      {
        if (!found)
        {
          cout << fragment << " is found at index " << j << "." << endl;
          found = true;
        }
      }
    }
    if (!found)
    {
      int reverseIndex = 0;
      for (int j = len - 1; j >= 0; j--)
      {
        reverseFragment[reverseIndex++] = fragment[j];
      }
      reverseFragment[len] = '\0';
      for (int j = 0; j < strlen(dna) - len + 1; j++)
      {
        if (strncmp(dna + j, reverseFragment, len) == 0)
        {
          cout << fragment << " is found at index " << j + len - 1 << " and overlaps with ";
          cout << reverseFragment << " at index " << j << "." << endl;
          found = true;
          break;
        }
      }
      if (!found)
      {
        cout << fragment << " is not found." << endl;
      }
    }
  }
  return 0;
}