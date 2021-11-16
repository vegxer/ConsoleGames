#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

using namespace std;

const int width = 20, height = 20;
bool game = true, yes = false;
string mover;
int i = 5, j = 10, fruitI = rand() % (height - 2) + 1, fruitJ = rand() % (width - 2) + 1, score = 0, snake[102], n = 4, c = -2;
char root[height][width] =
{
    {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'}
};


void write()
{
    for (int p = 0; p < n; p += 2)
    {
        if (p == 0)
            root[snake[p]][snake[p + 1]] = 'o';
        else
            root[snake[p]][snake[p + 1]] = '#';
    }
    Sleep(90);
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cd;
    cd.X = 0;
    cd.Y = 0;
    SetConsoleCursorPosition(hd, cd);
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
            if (k == fruitI && l == fruitJ)
                cout << '*';
            else
                cout << root[k][l];
        cout << "\n";
    }
    cout << "score: " << score << "\n";
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            mover = "LEFT";
            break;
        case 'd':
            mover = "RIGHT";
            break;
        case 'w':
            mover = "UP";
            break;
        case 's':
            mover = "DOWN";
            break;
        case 'e':
            game = false;
            break;
        }
    }
}

void fruit()
{
    if (snake[0] == fruitI && snake[1] == fruitJ)
    {
        do
        {
            fruitI = rand() % (height - 2) + 1;
            fruitJ = rand() % (width - 2) + 1;
        } while (root[fruitI][fruitJ] == '#');
        score += 1;
        n += 2;
        if (snake[n - 4] > snake[n - 6])
            snake[n - 2] = snake[n - 4] + 1;
        else
            if (snake[n - 4] < snake[n - 6])
                snake[n - 2] = snake[n - 4] - 1;
            else
                if (snake[n - 3] > snake[n - 5])
                    snake[n - 1] = snake[n - 3] + 1;
                else
                    if (snake[n - 3] < snake[n - 5])
                        snake[n - 1] = snake[n - 3] - 1;
    }
}

void move()
{
    if (mover == "UP")
    {
        for (int i = n - 1; i >= 2; i--)
            snake[i] = snake[i - 2];
        snake[0] -= 1;
    }
    else
        if (mover == "DOWN")
        {
            for (int i = n - 1; i >= 2; i--)
                snake[i] = snake[i - 2];
            snake[0] += 1;
        }
        else
            if (mover == "LEFT")
            {
                for (int i = n - 1; i >= 2; i--)
                    snake[i] = snake[i - 2];
                snake[1] -= 1;
            }
            else
                if (mover == "RIGHT")
                {
                    for (int i = n - 1; i >= 2; i--)
                        snake[i] = snake[i - 2];
                    snake[1] += 1;
                }
    if (root[snake[0]][snake[1]] == '#')
    {
        system("cls");
        cout << " ####   ####  #   # #####\n";
        cout << "##     ##  ## ## ## #\n";
        cout << "## ### ###### # # # ####\n";
        cout << "##  ## ##  ## #   # ##\n";
        cout << " ####  ##  ## #   # #####\n\n";
        cout << " ####  ##  ## #####  #####\n";
        cout << "##  ## ##  ## ##     ##  ##\n";
        cout << "##  ## ##  ## ####   #####\n";
        cout << "##  ##  ####  ##     ##  ##\n";
        cout << " ####    ##   #####  ##  ##\n\n";
        cout << "your score: " << score << endl;
        game = false;
    }
    for (int c = 0; c < n; c++)
        if (root[snake[c]][snake[c + 1]] == '_' || root[snake[c]][snake[c + 1]] == '|' || root[snake[c]][snake[c + 1]] == 'Z')
        {
            if (snake[c] < 1)
                snake[c] = height - 2;
            if (snake[c] > height - 2)
                snake[c] = 1;
            if (snake[c + 1] < 1)
                snake[c + 1] = width - 2;
            if (snake[c + 1] > width - 2)
                snake[c + 1] = 1;
        }
    for (int k = 0; k < height; k++)
        for (int l = 0; l < width; l++)
            if (root[k][l] == '#')
                root[k][l] = ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    snake[0] = 5, snake[1] = 10, snake[2] = 6, snake[3] = 10;
    while (game == true)
    {
        write();
        input();
        fruit();
        move();
    }
    system("pause");
    return 0;
}
