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
    vector<int> vec = {1, 2, 3, 4, 5};
    print_vec(vec);
    vec.insert(vec.begin(), 8);
    print_vec(vec);
    vec.insert(vec.end(), 8);
    print_vec(vec);

    return 0;
}