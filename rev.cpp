#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
  s += " ";
  string word = "";
  stack<string> words;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ' && !(word == "" || word == " ")) {
      words.push(word);
      word = "";
    } else if (s[i] != ' ')
      word += s[i];
  }
  word = "";
  while (words.size() != 1) {
    word += (words.top() + ' ');
    words.pop();
  }
  word += words.top();
  return word;
}

int main() {
  cout << reverseWords("  hello   world ");
  return 0;
}

/*
Author: Uttam Raj
Date: 2024-10-12
Problem: Problem Name/URL
*/
