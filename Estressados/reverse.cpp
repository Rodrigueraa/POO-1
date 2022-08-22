#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> x)
{
    vector<int> y;
    for(int i = (int)x.size() - 1, j = 0; i >= 0; i--, j++)
        y.push_back(x[i]);

    return y;
}   

void reverse_inplace(vector<int> &x)
{
    vector<int> y;
    for(int i = (int)x.size() - 1; i >= 0; i--)
        y.push_back(x[i]);

    x = y;
}

int main()
{
    vector<int> x {1, 2, 3 ,4 ,5 };
    x = reverse(x);

    for(auto a : x)
        cout << a << " ";
}