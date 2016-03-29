#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <time.h>
#include <algorithm>
#include "linkedlist.h"

using namespace std;

vector<string> words;

class ReadFile
{
   private:       
	   string InputFile;
   public:
	   ReadFile(string File)
	   {
		   InputFile = File;
	   };
	   int GetWordByWord(); 
};

int ReadFile::GetWordByWord()
{
	ifstream myFile;
	string EachChar;
	myFile.open(InputFile);
 
    if (myFile.is_open())
	{
		string token;
        /* Get all file data with ',' delimiter*/        
		while (getline(myFile, token, ','))
		{
			// Remove quotes from the string
			if (token.front() == '"' ) {
                   token.erase( 0, 1 ); // erase the first character
                   token.erase(token.size() - 1 ); // erase the last character
             }
			words.push_back(token);
		}
    }
	else
	{
		return -1;
	}
    myFile.close();
    return 0;
}

int main() 
{
	clock_t tStart = clock();
	ReadFile MyFile("d:\p022_names.txt");
	int Total = 0;
	if(MyFile.GetWordByWord() == 0)
	{
		LinkedList MyList;
		// add each word in the linkedlist
		for (vector<string>::iterator it = words.begin() ; it != words.end(); ++it)
		{
			MyList.InsertData(*it);
		}
		// added the print function for debugging
		//MyList.PrintData();
		Total = MyList.CalculateValue();
	}
	else
	{
		cout << "Error reading file";
	}
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}
