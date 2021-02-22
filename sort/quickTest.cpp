#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> &vec)
{
    for (auto it = vec.begin() ; it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};

    vector<int> vec1(vec.begin(), vec.begin() + 2);

    print_vec(vec1);
}