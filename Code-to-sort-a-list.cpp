// C++ program to demonstrate default behaviour of sort() in STL.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	/*Here we take two parameters, the beginning of the array and the length n upto which we want the array to be sorted*/
	sort(arr, arr + n);

	cout << "\nArray after sorting using default sort is : \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}


/* Output:
Array after sorting using default sort is : 
0 1 2 3 4 5 6 7 8 9
*/


// C++ program to demonstrate descending order sort using greater<>().

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n, greater<int>());

	cout << "Array after sorting : \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}

/*Output:

Array after sorting : 
9 8 7 6 5 4 3 2 1 0 
*/



// A simple sorting program that sort a list of n integer numbers, entered by the user (ascending)

#include <iostream>
using namespace std;

#define maxsize 100

int main(void)
{
  int temp, i, j, n, list[maxsize];
  
  cout<<"\n--You are prompted to enter your list size.--";
  cout<<"\n--Then, for your list size, you are prompted to enter--";
  
  cout<<"\n--the element (integers) of your list.--";
  cout<<"\n--Finally your list will be sorted ascending!!!--\n";
  
  // enter the list's size
  
  cout<<"\nEnter your list size: ";
  
  // read the list's size
  cin>>n;
  
  // prompting the data from user store in the list
  for(i=0; i<n; i++)
  {
    cout<<"Enter list's element #"<<i<<"-->";
    cin>>list[i];
  }

 

// do the sorting...
  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
      if(list[i] > list[j])
      {
        // These three lines swap the elements list[i] and list[j].
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
  cout<<"\nSorted list, ascending: ";
  
  for(i=0; i<n; i++)
    cout<<" "<<list[i];
  cout<<endl;
  return 0;
}

 

/* Output example:

 

--You are prompted to enter your list size.--
--Then, for your list size, you are prompted to enter--

--the element (integers) of your list.--
--Finally your list will be sorted ascending!!!--

Enter your list size: 5
Enter list's element #0-->23
Enter list's element #1-->20
Enter list's element #2-->45
Enter list's element #3-->67
Enter list's element #4-->10
Sorted list, ascending: 10 20 23 45 67

Press any key to continue . . . */
