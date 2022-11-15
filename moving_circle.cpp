#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

bool check_circle_pixel(int x_pos,int y_pos, int radius, int x, int y ) {
    if (pow(x_pos - x,2) + pow(y_pos - y,2) <= pow( radius,2)) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    const int resolution[] = {60,30};
    const int radius = 8;
    const char empty = ' ';
    const char full = '#';
    int circle_position[] = {30,15};
    //cout << circle_position[0]<< ' '<< circle_position[1] << endl;
    while (true) {
        //system("cls");
        char symb = (char)_getch();
        if (symb == 'w') {
            circle_position[1] -= 1;
        }
        else if (symb == 'a') {
            circle_position[0] -= 1;
        }
        else if (symb == 's') {
            circle_position[1] += 1;
        }
        else if (symb == 'd') {
            circle_position[0] += 1;
        }

        if (circle_position[0] > 60) {
            circle_position[0] = 0;
        }
        else if (circle_position[0] < 0) {
            circle_position[0] = 60;
        }

        if (circle_position[1] > 30) {
            circle_position[1] = 0;
        }
        else if (circle_position[1] < 0) {
            circle_position[1] = 30;
        }

        string to_draw = "" ;
        for (int y = 0; y < resolution[1]; y++) {
            for (int x = 0; x < resolution[0]; x++) {
                if (check_circle_pixel(circle_position[0], circle_position[1], radius, x, y)) {
                    to_draw += full;
                }
                else {
                    to_draw += empty;
                }

            }
            to_draw += '\n';
        }
        cout << to_draw;
    }
}
