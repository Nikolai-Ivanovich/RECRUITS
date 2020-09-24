/*
2. НОВОБРАНЦЫ. 
+Новобранцы выстроены в шеренгу. 
+По команде НАЛЕ–ВО! одни из них поворачиваются налево, а другие – направо. 
+Это есть начальное положение шеренги. 
Далее каждый новобранец действует следующим образом: увидев перед собой лицо соседа, он ровно через секунду поворачивается кругом.
В конце концов повороты прекратятся. Тогда сержант подает звуковой сигнал.
*/

#include <iostream>
#include <windows.h>
using namespace std;
#define RECRUITS 15

char generateRandomValue();
void toLeft(char line[RECRUITS]);
void reverse(char line[RECRUITS]);
bool isAllStop(char line[RECRUITS]);
void showLine(char line[RECRUITS]);
void sergeantYelling();

int main()
{
    char line[RECRUITS];

    toLeft(line);

    while (true)
    {
        reverse(line);
        if (isAllStop(line) == true)
        {
            showLine(line);
            sergeantYelling();
            break;
        }
        showLine(line);
        Sleep(1000);
        
    }
    
    return 0;
}

void sergeantYelling()
{
    Beep((DWORD)659.26, 200);
    Beep((DWORD)659.26, 200);
    Sleep(200);
    Beep((DWORD)659.26, 200);
    Sleep(100);
    Beep((DWORD)523.26, 200);
    Beep((DWORD)659.26, 200);
    Sleep(200);
    Beep((DWORD)783.98, 200);
    Sleep(400);
    Beep((DWORD)391.99, 200);
}

void showLine(char line[RECRUITS])
{
    for (int i = 0; i < RECRUITS; i++)
    {
        cout << line[i] << " ";
    }
    cout << endl;
}

bool isAllStop(char line[RECRUITS])
{
    for (int i = 0; i < RECRUITS; i++)
    {
        if (line[i] == '>' and line[i + 1] == '<')
        {
            return false;
        }
    }
    return true;
}

void reverse(char line[RECRUITS])
{
    // all number [-∞;-2]
    int iterationSkipFlag = -10;

    for (int i = 0; i < RECRUITS; i++)
    {
        if (line[i] == '>' and line[i + 1] == '<')
        {
            if (iterationSkipFlag == i - 1)
            {
                continue;
            }
            else
            {
                line[i] = '<';
                line[i + 1] = '>';
                iterationSkipFlag = i;
            }
        }
        else
        {
            if (iterationSkipFlag == i - 1)
            {
                continue;
            }
            else
            {
                line[i] = line[i];
                line[i + 1] = line[i + 1];
            }
        }
    }
}

void toLeft(char line[RECRUITS])
{
    for (int i = 0; i < RECRUITS; i++)
    {
        line[i] = generateRandomValue();
    }
}

char generateRandomValue()
{
    int value = 1 + rand() % 2;
    if (value == 1)
        return '<';
    else
        return '>';
}