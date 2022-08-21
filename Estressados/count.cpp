#include <iostream>
#include <vector>
using namespace std;

int count(vector<int> x, int value)
{
    int index = -1;
    for(auto a : x)
        if(a == value){
            index++;
            if(index == 0)
                index++;
        }
    return index;
}

int average(vector<int> x)
{
    int index = 0;
    for(int i = 0; i < (int)x.size(); i++){
        if(x[i] < 0)
            x[i] *= -1;

        index += x[i];
    }

    if((int)x.size() == 0)
        return - 1;
    return index / (int)x.size();
}

string half_compares(vector<int> x)
{
    if((int)x.size() == 0) return "-1";

    int h1 = 0, h2 = 0;
    for(int i = 0, j = (int)x.size() / 2; i < (int)x.size() / 2; i++, j++){
        if(x[i] < 0)
             x[i] *= -1;
        if(x[j] < 0)
            x[j] *= -1;

        h1 += x[i];
        h2 += x[j];
    }

    if(h1 == h2)
        return "draw";
    if(h2 > h1)
        return "second";
    return "first";
}

string more_men_or_women(vector<int> x)
{
    if((int)x.size() == 0) return "-1";

    int men = 0, women = 0;
    for(auto a : x)
        if(a > 0)
            men++;
        else   
            women++;

    if(men == women)
        return "draw";
    if(men > women)
        return "men";
    return "women";
}

string sex_battle(vector<int> x)
{
    int menStress = 0, men = 0;
    int womenStress = 0, women = 0;
    
    for(auto a : x)
        if(a > 0){
            men++;
            menStress += a;
        }
        else {
            women++;
            womenStress += -a;
        }
    int menAvg = menStress / men;
    int womenAvg = womenStress / women;

    if(menAvg == womenAvg)
        return "draw";
    if(womenAvg > menAvg)
        return "women";
    return "men";
}

int main()
{
    cout << count({2, 2, 2, 2, 2}, 2) << " - count function\n";
    cout << average({7, 7, 7}) << " - average fnc\n";
    cout << half_compares({2, 2, 2, 3}) << " - half compare fnc\n";
    cout << more_men_or_women({-1, -45, -3, 5, 3, 2, 5}) << " - more men or women fnc\n";
    cout << sex_battle({-1, -2, -3, -4, 1, 2 ,3 ,4});
    
}