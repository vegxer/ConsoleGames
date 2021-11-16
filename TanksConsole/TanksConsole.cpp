#include <iostream>
#include <conio.h>
#include <random>
#include <ctime>
#include <windows.h>

using namespace std;

int shirina = 20, dlina = 40, ship_health = 10, shot[20][2], bots[20][8], bot_shot[30][2], score = -20, bot_shot_max = 30, bot_shot_count = -1, count_shot = -1, max_shot = 10, placeI = 2, count_bot = -1, max_bot = 20, bot_xod = 1, base_health = 20;

int tank[4][2];

char a[20][40] =
{
    {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
};

void draw()
{
    for (int i = 0; i < max_shot; ++i)
        for (int j = 0; j < max_bot; ++j)
            if ((shot[i][0] == bots[j][0] || shot[i][0] == bots[j][6]) && (shot[i][1] == bots[j][1] || shot[i][1] == bots[j][3] || shot[i][1] == bots[j][5]))
            {
                ++score;
                shot[i][0] = 0, shot[i][1] = 0;
                for (int k = 0; k <= 6; k += 2)
                {
                    bots[j][k] = 0;
                    bots[j][k + 1] = dlina - 1;
                }
            }
    for (int i = 0; i < max_bot; ++i)
    {
        a[bots[i][0]][bots[i][1]] = '@';
        a[bots[i][2]][bots[i][3]] = '@';
        a[bots[i][4]][bots[i][5]] = '@';
        a[bots[i][6]][bots[i][7]] = '@';
    }
    for (int i = 0; i < bot_shot_max; ++i)
        a[bot_shot[i][0]][bot_shot[i][1]] = '+';
    for (int i = 0; i < 4; ++i)
        a[tank[i][0]][tank[i][1]] = '$';
    for (int i = 0; i < max_shot; ++i)
        a[shot[i][0]][shot[i][1]] = '*';
    Sleep(70);
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cd;
    cd.X = 0;
    cd.Y = 0;
    SetConsoleCursorPosition(hd, cd);
    for (int i = 0; i < shirina; ++i)
    {
        for (int j = 0; j < dlina; ++j)
        {
            cout << a[i][j];
            if (i != 0 && i != shirina - 1 && j != 0 && j != dlina - 1)
                a[i][j] = ' ';
        }
        cout << '\n';
    }
    cout << "\nHealth of base: " << base_health;
    cout << "\nHealth of tank: " << ship_health;
    cout << "\nScore: " << score;
}

void set_tank()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (tank[1][1] - 1 > 0)
            {
                for (int i = 0; i < 4; ++i)
                    --tank[i][1];
            }
            break;
        case 's':
            if (tank[1][0] + 1 < shirina - 1)
            {
                for (int i = 0; i < 4; ++i)
                    ++tank[i][0];
            }
            break;
        case 'd':
            if (tank[3][1] + 1 < dlina - 1)
            {
                for (int i = 0; i < 4; ++i)
                    ++tank[i][1];
            }
            break;
        case 'w':
            if (tank[0][0] - 1 > 0)
            {
                for (int i = 0; i < 4; ++i)
                    --tank[i][0];
            }
            break;
        case 32:
            ++count_shot;
            if (count_shot > max_shot - 1)
                count_shot = 0;
            shot[count_shot][0] = tank[0][0];
            shot[count_shot][1] = tank[0][1];
            break;
        }
    }
}

void shot_move()
{
    for (int i = 0; i < max_shot; ++i)
        if (shot[i][0] != 0 && shot[i][1] != 0)
        {
            if (shot[i][0] > 2)
                --shot[i][0];
            else
                shot[i][0] = 0, shot[i][1] = 0;
        }
}

void bot_spawn()
{
    int t = rand() % 28;
    if (t == 8)
    {
        int placeJ = (rand() % 38) + 2;
        if (placeJ > 37)
            --placeJ;
        if (placeJ > 37)
            --placeJ;
        ++count_bot;
        if (count_bot > 19)
            count_bot = 0;
        bots[count_bot][0] = placeI, bots[count_bot][1] = placeJ - 1, bots[count_bot][2] = placeI, bots[count_bot][3] = placeJ,
            bots[count_bot][4] = placeI, bots[count_bot][5] = placeJ + 1, bots[count_bot][6] = placeI + 1, bots[count_bot][7] = placeJ;
    }
}

void bot_move()
{
    ++bot_xod;
    if (bot_xod > 1000000)
        bot_xod = 1;
    if (count_bot > -1 && bot_xod % 7 == 0)
    {
        for (int i = 0; i < max_bot; ++i)
            if (bots[i][6] < shirina - 2 && bots[i][0] != 0 && bots[i][1] != shirina - 1)
            {
                for (int j = 0; j <= 6; j += 2)
                    ++bots[i][j];
            }
            else
            {
                if (bots[i][6] >= shirina - 2)
                    --base_health;
                for (int j = 0; j <= 6; j += 2)
                {
                    bots[i][j] = 0;
                    bots[i][j + 1] = dlina - 1;
                }
            }
    }
}

void bot_fire()
{
    for (int i = 0; i < max_bot; ++i)
    {
        int p = rand() % 35;
        if (bots[i][0] > 0 && bots[i][0] < shirina - 4 && p == 4)
        {
            ++bot_shot_count;
            if (bot_shot_count > 29)
                bot_shot_count = 0;
            bot_shot[bot_shot_count][0] = bots[i][6] + 1;
            bot_shot[bot_shot_count][1] = bots[i][7];
        }
    }
}

void bot_fire_move()
{
    for (int i = 0; i < bot_shot_max; ++i)
    {
        if (bot_shot[i][0] < shirina - 1 && bot_shot[i][1] > 0)
        {
            if ((bot_shot[i][0] == tank[0][0] || bot_shot[i][0] == tank[1][0]) && (bot_shot[i][1] == tank[0][1] || bot_shot[i][1] == tank[1][1] || bot_shot[i][1] == tank[2][1] || bot_shot[i][1] == tank[3][1]))
            {
                --ship_health;
                bot_shot[i][0] = shirina - 1;
                bot_shot[i][1] = 0;
            }
            if (bot_shot[i][0] < shirina - 2)
            {
                if (bot_xod % 2 == 0)
                    ++bot_shot[i][0];
            }
            else
            {
                bot_shot[i][0] = shirina - 1;
                bot_shot[i][1] = 0;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    tank[0][0] = 17, tank[0][1] = 19, tank[1][0] = 18, tank[1][1] = 18, tank[2][0] = 18, tank[2][1] = 19, tank[3][0] = 18, tank[3][1] = 20;
    shot[0][0] = 0, shot[0][1] = 0;
    //system("color F0"); белый фон, чёрный текст
    while (base_health > 0 && ship_health > 0)
    {
        draw();
        set_tank();
        shot_move();
        bot_spawn();
        bot_move();
        bot_fire();
        bot_fire_move();
    }
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
    cout << "Your score: " << score << '\n';
    system("pause");
    return 0;
}