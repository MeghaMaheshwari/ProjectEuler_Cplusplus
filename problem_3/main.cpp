#include<iostream>

using namespace std;

class GetLargestPrime
{
  private:
	  long long size;
  public :
	  GetLargestPrime(long long value);
	  long long GetLargestPrimeFactor();
};

GetLargestPrime::GetLargestPrime(long long val)
{
	size = val;
}

long long GetLargestPrime::GetLargestPrimeFactor()
{
	const long long Number = size;
    long long NewNo = Number;
    long long largestFact = 0;
 
    int counter = 2;
	//start by dividing by 2 and continue until we reach a point where the 
	//number to be divided becomes smaller than the divisor.
    while (counter <= NewNo) {
       if (NewNo % counter == 0) {
           NewNo = NewNo / counter;
           largestFact = counter;
       } else {
        counter++;
       }
    }
    if (NewNo > largestFact) { // the remainder is a prime number
       largestFact = NewNo;
    }
	return largestFact;
}


int main()
{
	GetLargestPrime Prime(600851475143);
	long long LargestPrimeFactor = Prime.GetLargestPrimeFactor();
	cout << LargestPrimeFactor;
	return 0;
}