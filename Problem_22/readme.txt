This folder contains solution to problem 22 from Project Euler

Question :

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file? 

  Solution : The solution reads the file and than sorts the words using a linkedlist. Though C++ has its own sort library, I did not use it here because I wanted to compare the performancece of the code when I explicitly sort using linked list ( I used Linkedlist since inserting an entry is easy and fast ) as compared to the C++ sort library
  and also to learn more of coding which can be done only without relying on the inbuilt libraries.
  
  Also I am using vector to store the words read from the file which can be easily eliminated by storing the words directly in the linkedlist as we are reading it. I used it here since I plan to extend this further to find an even better way of doing it.