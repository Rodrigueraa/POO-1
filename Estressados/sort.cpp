#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &x)
{
    int aux;
    for(int i = 0; i < (int)x.size(); i++)
        for(int j = 0; j < (int)x.size() - i - 1; j++)
            if(x[j] > x[j+1]){
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
}

void sort_stress(vector<int> &x)
{
    int aux;
    for(int i = 0; i < (int)x.size(); i++){
        for(int j = 0; j < (int)x.size() - i - 1; j++){
            bool negative1 = false, negative2 = false;
            if(x[j] < 0){
                negative1 = true;
                x[j] *= -1;
            }
            if(x[j + 1] < 0){
                negative2 = true;
                x[j+1] *= -1;
            }
            
            if(x[j] > x[j+1]){
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;

                if(negative1)
                    x[j+1] *= -1;
                if(negative2)
                    x[j] *= -1; 
                continue;
            }
            if(negative1)
                x[j] *= -1;
            if(negative2)
                x[j+1] *= -1;
        }
    }
}

int main()
{
    vector<int> x {1, -3, -4, 6, 7, 2};
    sort_stress(x);
    for(auto a : x)
        cout << a << " ";
        cout << endl;
}