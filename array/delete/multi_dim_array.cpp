#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> &vec)
{
    vector<int>::iterator it = vec.begin();
    for ( ; it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> array;
    vector<int> array1 = {1, 2, 3};
    vector<int> array2 = {4, 5, 6, 7};
    array.push_back(array1);
    array.push_back(array2);

    print_vec(array[0]);

    cout << array[1][1] << endl;
}