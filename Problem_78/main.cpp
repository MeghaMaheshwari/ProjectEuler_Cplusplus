#include<iostream>

using namespace std;

int main()
{
	int smallestval = 0;
    const int target = 100000;
	int ways[target+1] = {0};
    ways[0] = 1;
	for (int i = 1; i < target; i++)
    {
		for (int j = i; j <= target; j++)
		{
			//since we are interested in only the last six digits we take a mod and
			// store the value so that we do not face the consequences of overflow
			ways[j] = (ways[j] + ways[j - i]) % 1000000;
		}
		if (ways[i] == 0)
		{
			smallestval = i;
			break;
		}
     }
	return 0;
}