#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;

int main()
{
    int plates[5][6];

    // левый бок
    plates[3][0] = 50;
    plates[2][0] = 40;
    plates[1][0] = 30;
    plates[0][0] = 20;

    // верх
    plates[0][1] = 30;
    plates[0][2] = 40;
    plates[0][3] = 50;
    plates[0][4] = 40;

    // правый бок
    plates[0][5] = 30;    
    plates[1][5] = 40;
    plates[2][5] = 40;
    plates[3][5] = 40;

    // пол
    plates[4][0] = 10;
    plates[4][1] = 10;
    plates[4][2] = 10;
    plates[4][3] = 10;
    plates[4][4] = 10;
    plates[4][5] = 10;

    for (int y = 1; y <= 3; y++)
    {
        for (int x = 1; x <= 4; x++)
        {
            plates[y][x]=0;
        }
    }

    float delt = 0.1;
    float k = 0.5;

    while (true) {

        system("cls");

        // Вывод
        for (int y = 0; y <= 3; y++)
        {
            for (int x = 0; x <= 5; x++)
            {
                cout << plates[y][x] << "\t";
            }
            cout << endl;
        }

        for (int y = 1; y <= 3; y++)
        {
            for (int x = 1; x <= 4; x++)
            {
                plates[y][x] =
                    plates[y][x] +
                    (
                        (
                            k * (plates[y][x - 1] - plates[y][x])
                            + k * (plates[y][x + 1] - plates[y][x])
                            + k * (plates[y - 1][x] - plates[y][x])
                            + k * (plates[y + 1][x] - plates[y][x])
                         ) * delt
                    );
            }
        }

        this_thread::sleep_for(chrono::milliseconds((long long)(delt * 1000)));
    }

    return 0;
}
