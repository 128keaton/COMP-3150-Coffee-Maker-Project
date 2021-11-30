//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_PROGRESSBAR_H
#define HONORSPROJECT_PROGRESSBAR_H


#include <iostream>
#include <iomanip>
#include <string>


using std::cout,
std::flush,
std::string,
std::endl,
std::fixed,
std::setprecision;

class ProgressBar {
public:
    static void percentage(int current, int total = 100, const string &title = "", bool last = false) {
        double percentage = ((double) current) / ((double) total) * 100;

        if (percentage >= 0 && percentage <= 100) {
            string progress = "[" + string((int) percentage, '*') + string(100 - (int) percentage, ' ') + "]";

            cout << "\r\033[F" << progress << " " << (int) percentage << "% " << title << flush;
        }

        if (last) {
            cout << endl;
        }
    }

    static void temperature(double current, double max, const string &title = "", bool last = false) {
        double percentage = (current / max) * 100;
        string progress = "[" + string((int) percentage, '*') + string(100 - (int) percentage, ' ') + "]";
        cout <<
             "\r\033[F" <<
             progress <<
             " " <<
             fixed <<
             setprecision(2) <<
             current <<
             "°C" <<
             " / " <<
             fixed <<
             setprecision(0) <<
             max <<
             "°C " <<
             title <<
             flush;

        if (last) {
            cout << endl;
        }
    }
};

#endif //HONORSPROJECT_PROGRESSBAR_H
