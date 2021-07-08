#include <iostream>
#include <vector>
#include <ctime>

#define ESC "\033"

#define SIZE_X 60
#define SIZE_Y 20
using namespace std;

void printArea(vector<vector<bool>> &area)
{
    printf(ESC "c");
    cout << "╔" ;
    for(int i = 0; i < SIZE_X; i++)
    {
        cout << "═";
    }
    cout << "╗" ;

    cout << endl;

    for (int y = SIZE_Y - 1; y > 0; y--)
    {
        cout << "║";
        for(int x = 0; x < SIZE_X; x++)
        {
            if(area[x][y])
            {
                cout << "█";
            }
            else
            {
                cout << "░";
            }

        }
        cout << "║";
        cout << endl;
    }
    cout << "╚" ;
    for(int i = 0; i < SIZE_X; i++)
    {
        cout << "═";
    }
    cout << "╝";
    cout << endl;
}

bool testLeft(vector<vector<bool>> &area, int x, int y)
{
    if(x == 0)
    {
        return false;
    }

    return area[x - 1][y];

}

bool testRight(vector<vector<bool>> &area, int x, int y)
{
    if(x == SIZE_X - 1)
    {
        return false;
    }

    return area[x + 1][y];
}

bool testUp(vector<vector<bool>> &area, int x, int y)
{
    if(y == SIZE_Y - 1)
    {
        return false;
    }

    return area[x][y + 1];
}

bool testDown(vector<vector<bool>> &area, int x, int y)
{
    if(y == 0)
    {
        return false;
    }

    return area[x][y - 1];

}

bool testLeftDown(vector<vector<bool>> &area, int x, int y)
{
    if(x == 0 or y == 0)
    {
        return false;
    }

    return area[x - 1][y - 1];

}

bool testLeftUp(vector<vector<bool>> &area, int x, int y)
{
    if(x == 0 or y == SIZE_Y - 1)
    {
        return false;
    }

    return area[x - 1][y + 1];

}

bool testRightDown(vector<vector<bool>> &area, int x, int y)
{
    if(x == SIZE_X - 1 or y == 0)
    {
        return false;
    }

    return area[x + 1][y - 1];
}

bool testRightUp(vector<vector<bool>> &area, int x, int y)
{
    if(x == SIZE_X - 1 or y == SIZE_Y - 1)
    {
        return false;
    }

    return area[x + 1][y + 1];
}


int cellsNear(vector<vector<bool>> &area, int x, int y)
{
    int sum = 0;
    if(testLeft(area,x,y))
    {
        sum++;
    }
    if(testUp(area,x,y))
    {
        sum++;
    }
    if(testDown(area,x,y))
    {
        sum++;
    }
    if(testRight(area,x,y))
    {
        sum++;
    }
    if(testRightUp(area,x,y))
    {
        sum++;
    }
    if(testRightDown(area,x,y))
    {
        sum++;
    }
    if(testLeftUp(area,x,y))
    {
        sum++;
    }
    if(testLeftDown(area,x,y))
    {
        sum++;
    }
    return sum;
}


void handler(vector<vector<bool>> &area)
{
    vector<vector<bool>> buff = area;
    for (int y = SIZE_Y - 1; y > 0; y--)
    {
        for(int x = 0; x < SIZE_X; x++)
        {
            int sum = cellsNear(area,x,y);
            if(area[x][y])
            {
                if(sum == 2 or sum == 3)
                {

                }
                else
                {
                    buff[x][y] = false;
                }
            }
            else
            {
                if(sum == 3)
                {
                    buff[x][y] = true;
                }
                else
                {

                }
            }

        }
    }
    area = buff;
}

void randGen(vector<vector<bool>> &area)
{
    srand(time(NULL));
    for (int y = SIZE_Y - 1; y > 0; y--)
    {
        for(int x = 0; x < SIZE_X; x++)
        {
            area[x][y] = rand() % 2 == 0;
        }
    }
}

int main()
{

    vector<vector<bool>> area(SIZE_X,vector<bool>(SIZE_Y,false));// 0 - пустая клетка, 1 - живая клетка
    randGen(area);
    while(1)
    {
      clock_t endwait = clock () + 0.1 * CLOCKS_PER_SEC ;
      handler(area);
      printArea(area);

      while (clock() < endwait) {}

    }
    return 0;
}
