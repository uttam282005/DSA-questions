#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num) {
  int greatestDigit = -1;
  int copy = num;
  int pos;
  int ans = 0;
  int lastDigit;
  int cnt = 0;
  while (num) {
    lastDigit = num % 10;
    num = num / 10;
    if (lastDigit > greatestDigit) {
      greatestDigit = lastDigit;
      pos = cnt;
    }
    cnt++;
  }
  int firstDigit = copy / ((int)pow(10, cnt - 1));
  ans = greatestDigit * (int)pow(10, cnt - 1) + firstDigit * (int)pow(10, pos);
  ans += (copy % ((int)pow(10, cnt - 1)));
  ans -= (greatestDigit * (int)(pow(10, pos)));
  return ans;
}
int main() {
  maximumSwap(427345);
  return 0;
}

/*
Author: Uttam Raj
Date: 2024-10-17
Problem: Problem Name/URL
*/
