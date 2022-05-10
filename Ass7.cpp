// #include <iostream>
// #include <stdio.h>
// int main ()
// {
//     std::cout<<"Hi";
//     return 0;
// }


// Your First C++ Program

// #include <iostream>

// int main() {
//     std::cout << "Hello World!";
//     return 0;
// }


//  #include<iostream>

//  using namespace std;
//  int main(){
//      int a,b,c;
//      cout<<"Enter the Numbers";
//      cin>>a>>b;
//      c=a+b;
//      cout<<"this is out put :"<<a<<"+"<<b<<"="<<c;
// return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {

//   int first_number, second_number, sum;
    
//   cout << "Enter two integers: ";
//   cin >> first_number >> second_number;

//   // sum of two numbers in stored in variable sumOfTwoNumbers
//   sum = first_number + second_number;

//   // prints sum 
//   cout << first_number << " + " <<  second_number << " = " << sum;     

//   return 0;
// }

//travalling sales man problem;
// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][j];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

// Driver Code
int main()  
{
	
  int i = 0,j = 0 ;

  cout << "Enter no of rows of the matrix";
  cin >> i;
  cout << "Enter no of columns of the matrix";
  cin >> j;

  float l[i][j];

  int p = 0, q = 0;

  while (p < i) {
    while (q < j) {
      cout << "Enter the" << p + 1 << "*" << q + 1 << "entry";
      cin >> l[p][q];

      q = q + 1;
    }
    p = p + 1;
    q = 0;
  }
  cout << l;

	
	cout << travllingSalesmanProblem(graph, j) << endl;
	return 0;
}


// #include <iostream>

// using namespace std;

// int main(){

// }