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
void print(int* tree, int* &tempTree, int treeSize, int numValues, int &i);

int main()
{
  int max = 50;
  char input[50];
  bool editing = true; // determines if you still want the program to continue

  // tree
  int treeSize = 101;
  int* tree = new int[treeSize];
  int insertIndex = 0; // records where to insert a new value
  tree[0] = 0; // we will not be using the 0 index
  
  while (editing)
    {
      // instructions
      cout << "Please only use lowercase letters." << endl;
      cout << "This is a max heap program that takes in 100 integers." << endl;
      cout << "If you would like to enter your numbers manually, type 'manual.'" << endl;
      cout << "If you would like to generate numbers from a file, type 'file.'" << endl;
      cout << "if you would like to print your tree, type 'print." << endl;
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
	  insertIndex = 1;
	  
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
      else if (strcmp(input, "print") == 0)
	{
	  int* tempTree = new int[insertIndex];
	  int tempIndex = 0;
	  print(tree, tempTree, treeSize, insertIndex, tempIndex);
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

      int tempIndex = 0;
      int* tempTree = new int[treeSize];
      // print(tree, tempTree, treeSize, tempIndex);
    }
  else
    {
      cout << "we are here." << endl;
    }

  // if so, swap indices with the parent, call add again
  // else if parent > current, stop and stay at the index you are at

}

void print(int* tree, int* &tempTree, int treeSize, int numValues,  int &i)
{
  for (int j = 0; j < treeSize - 1; j++)
    {
      tempTree[j] = 0;
      if (tree[j] != 0)
	{
	  cout << tree[j] << endl;
	}
    }

  cout << "" << endl;

  cout << "inside print function." << endl;
  // create a new printable array, equal to the number of values + 1
  // starting index i = 0
  int x = 0; // this is the index of our new array
  if (i == 0)
    {
      cout << "i = 0." << endl;
      // we must insert the root into the middle of the array
      x = i + (numValues - i)/2; // right now i = 0
      tempTree[x] = tree[i + 1];
      i = x;
      cout << "number " << tempTree[x] << " inserted at " << i << endl;
      print (tree, tempTree, treeSize, numValues, i);
    }
  else
    {
      // if both children = 0; we've reached the bottom
    }
  // if both children = 0, we've reached the bottom, print
  // if the children are not equal to 0
  // start with the left child, put it at index i - (size - i)/2
  // then do the right child, put it at index i + (size - i)/2

  
}
