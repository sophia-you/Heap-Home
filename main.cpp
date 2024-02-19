#include <iostream>
#include <cstring>
using namespace std;

/*
 * Author | Sophia You
 * Date | 02/22/2024
 * Description | This program creates a max heap where the root element is the 
 * largest, and its children get progressively smaller. 
 * Sources | 
 * https://www.geeksforgeeks.org/heap-data-structure/
 */

// function prototypes
void insert(int* &tree, int treeSize, int i);
void print(int* tree, int treeSize);

int main()
{
  int max = 50;
  char input[50];
  bool editing = true; // determines if you still want the program to continue

  // tree
  int treeSize = 101;
  int* tree = new int[treeSize];
  tree[0] = 0; // we will not be using the 0 index
  
  while (editing)
    {
      // instructions
      cout << "Please only use lowercase letters." << endl;
      cout << "This is a max heap program that takes in 100 integers." << endl;
      cout << "If you would like to enter your numbers manually, type 'manual.'" << endl;
      cout << "If you would like to generate numbers from a file, type 'file.'" << endl;
      cout << "If you would like to quit the program, type 'quit.'" << endl;

      // receiving input
      cin.getline(input, max);
      if (strcmp(input, "file") == 0)
	{
	  // read in from a file
	}
      else if (strcmp(input, "manual") == 0)
	{
	  // manual read-in
	  int count = 0;
	  bool wantToQuit = false;

	  // records index where the new value is added;
	  int insertIndex = 1;
	  
	  while ((count < treeSize - 1) && !wantToQuit)
	    {
	      int newnum = 0;
	      cout << "If you want to stop adding numbers, enter '-1', otherwise, please enter number " << insertIndex  << ": " << endl;
	      cin >> newnum;
	      cin.ignore(max, '\n');
	      if (newnum == -1)
		{
		  wantToQuit = true;
		}
	      else
		{
		  tree[insertIndex] = newnum;
		  insert(tree, treeSize, insertIndex);
		  insertIndex++;
		  cout << "now we are on slot " << insertIndex << endl;
		}

	      count++;
	    }
	}
      else if (strcmp(input, "quit") == 0)
	{
	  editing = false;
	}
    }
return 0;
}

/*
 * This function adds the data value into your max heap
 * @param tree | this is the heap
 * @param data | the value being entered
 * @param i | current index we are walking through
 */
void insert(int* &tree, int treeSize,  int i)
{
  cout << "added value: " << tree[i] << endl;
  
  // check if your parent (floor(i/2), with i as the current index) < current
  int parent = tree[(int)(i/2)];
  if (parent !=0 && parent < tree[i])
    {
      // swap parent with child
      cout << "a swap is necessary" << endl;
      int temp = parent;
      tree[(int)(i/2)] = tree[i];
      tree[i] = temp;

      // move up one generation
      i /= 2;
      insert(tree, treeSize, i);
      print(tree, treeSize);
    }
  else
    {
      cout << "we are here." << endl;
    }

  // if so, swap indices with the parent, call add again
  // else if parent > current, stop and stay at the index you are at

}

void print(int* tree, int treeSize/* int i*/)
{
  for (int j = 0; j < treeSize - 1; j++)
    {
      if (tree[j] != 0)
	{
	  cout << tree[j] << endl;
	}
    }

  cout << "" << endl;

  // print rightmost child (last slot in array first
  // print the parent
  // print left child
  // find the grandparent, if there is one, print it
  // then print everything in the left child
  
}
