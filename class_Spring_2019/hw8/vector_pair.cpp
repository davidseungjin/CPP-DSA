// C++ program to demonstrate vector of pairs
// David: maybe it's not possible but you can study tuple with vector later if you want to implement using tuple.


#include<iostream>
#include<vector>

using namespace std;

int main()
{
    //declaring vector of pairs
    vector<pair <int,int> > vect;
    vector< pair <int, int> > vect2;
    
    // initialising 1st and 2nd element of
    // pairs with array values
    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int arr2[] = {1,2,3,4,5};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // Entering values in vector of pairs
    for (int i=0; i<n; i++){
        vect.push_back( make_pair(arr[i],arr1[i]) );
        vect2.push_back( make_pair(vect[i], arr2[i]));
    }
    
    // Printing the vector
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
        << vect[i].second << endl;
    }
    
    return 0;
}
