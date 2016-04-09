#include<iostream>

using namespace std;

class CalcWays
{
  private :
	 int MaxValue;
     int TargetVal;
     int TotalWays;

 public:
	 CalcWays(int MaxVal, int Target);
	 int CalculateWays();
	 void GetWays(int CurrentIndex, int ValToForm);
};

CalcWays::CalcWays(int MaxVal, int Target)
{
	MaxValue = MaxVal;
	TargetVal = Target;
	TotalWays = 0;
}

int CalcWays::CalculateWays()
{
	for (int i = 1; i <= MaxValue; i++)
    {
		if (TargetVal % i == 0)
        {
			TotalWays++;
        }
        for (int j = (TargetVal / i - 1); j >= 1; j--)
        {
			int RemainingVal = TargetVal - (j * i);
            if (RemainingVal < (i + 1))
            {
				continue;
            }
            GetWays(i + 1, RemainingVal);
		}
    }
	return TotalWays;
}

void CalcWays::GetWays(int CurrentIndex, int ValToForm)
{
	for (int j = CurrentIndex; j <= MaxValue; j++)
    {
		if (ValToForm < j)
        {
			continue;
        }
        for (int k = (ValToForm / j); k >= 1; k--)
        {
			int RemainVal = ValToForm - (k * j);
            if (RemainVal == 0)
            {
                TotalWays++;
            }
            else
			{
				if (RemainVal < (j+1))
                {
					continue;
                }
                GetWays(j + 1, RemainVal);            	
			}
                
       }
	}
}

int main()
{
	// here max value is set to be 99 since the question is asking to find combinations that has atleast two positive integers
	CalcWays Ways(99,100);
	int TotalWays = Ways.CalculateWays();
	cout << TotalWays ;
	return 0;
}