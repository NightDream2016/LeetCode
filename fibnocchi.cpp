#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{
    uint64_t fibnocchi[101];
    fibnocchi[0] = 0;
    fibnocchi[1] = 1;
    cout.precision(30);
    for (int i = 2; i < 101; i++)
    {
        fibnocchi[i] = fibnocchi[i - 1] + fibnocchi[i - 2];
        cout << fibnocchi[i] << endl;
    }
    return 0;
}