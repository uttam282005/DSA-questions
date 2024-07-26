#include <iostream>
using namespace std;

int func()   {
	cout << "this is mohit tiwari";

	return 0;
}
int main() {

int sum = 0,val;
  for (val=1;val<=10;val++){
  	sum+=val;
  }

  cout<< sum<<endl;


  func();
  return 0;
}