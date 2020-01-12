
#include <iostream>
#include <string>
using namespace std;

int factorial (int n) {
    if (n==0) {
        return 1;
    }
    else 
        return n * factorial (n-1);
}

// mirror task
string reverse (string s) {
    if (s.length() == 1) {
        return s;
    } else 
    return s.substr(s.length()-1,1) + reverse (s.substr(0,s.length()-1));
}

char[] reverseArray (char[] words) {
    if (words.size()==0 || words.size()==1) {
        return words;
    } else {
        return words[words.size()-1] + Array.copyOfArrange(words, 0, words.size()-1);
    }
}

int main()
{ 
  cout << factorial (5);
  cout << reverse ("word");
   cout << reverseArray("word");
  
}