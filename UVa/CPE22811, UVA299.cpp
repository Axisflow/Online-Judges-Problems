#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, L, tmp, cont;
    vector<int> lens;
    cin >> N;
    while (N--)
    {
        cin >> L;
        if(L == 0) {
            cout << "Optimal train swapping takes 0 swaps.\n";
            continue;
        }

        while (L--)
        {
            cin >> tmp;
            lens.push_back(tmp);
        }

        cont = 0;
        for (int i = 0; i < lens.size() - 1; i++)
        {
            for (int j = 0; j < lens.size() - 1; j++)
            {
                if (lens[j] > lens[j + 1])
                {
                    tmp = lens[j];
                    lens[j] = lens[j + 1];
                    lens[j + 1] = tmp;
                    cont++;
                }
            }
        }

        cout << "Optimal train swapping takes " << cont << " swaps.\n";

        lens.clear();
    }
    return 0;
}
