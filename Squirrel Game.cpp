#include <iostream>
#include <chrono>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

class movement
{
public:
    double xcord(double theta)
    {
        double radians = theta * M_PI / 180.0;
        return cos(radians);
    }

    double ycord(double theta)
    {
        double radians = theta * M_PI / 180.0;
        return cos(radians);
    }
};

class chaser : public movement
{
public:
    double theta(double chy, double tay, double distance)
    {
        return asin(((tay - chy) / distance));
    }
};

class target : public movement
{
public:
    double theta()
    {
        srand(time(nullptr));
        return rand() % 360;
    }
};

int main()
{
    using std::chrono::high_resolution_clock;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bool flag = 1;
    chaser* chase = new chaser;
    target* targ = new target;
    double chx, chy, tax, tay, distance, chtheta, disx, disy, tatheta;
    int count;

    while (flag)
    {
        chx = 0, chy = 0, tax = 10, tay = 10, distance = 2, chtheta, disx = 0, disy = 0, tatheta, count = 0;
        distance = sqrt((pow((tax - chx), 2) + pow((tay - chy), 2)));

        while (distance > 1)
        {
            tatheta = targ->theta();
            chtheta = chase->theta(chy, tay, distance);
            chx += chase->xcord(chtheta);
            chy += chase->ycord(chtheta);
            tax += targ->xcord(tatheta);
            tay += targ->ycord(tatheta);
            disx += chase->xcord(chtheta);
            disy += chase->ycord(chtheta);
            ++count;
            distance = sqrt((pow((tax - chx), 2) + pow((tay - chy), 2)));
        }

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::milliseconds>(t2 - t1) / 100;
        cout << "It took " << count << " moves to catch the target.\nChaser coordinates: (" << chx << ", " << chy << ")\nTarget coordinates: (" << tax << ", " << tay << ")\nDistance: " << distance << "m\nChaser travelled " << disx << "m on the x - axis\nChaser travelled " << disy << "m on the y - axis\nChaser offset is " << (chx - 0) << "m x - axis and " << (chy - 0) << "m y - axis\nTarget offset is " << (tax - 10) << "m x - axis and " << (tay - 10) << "m y - axis\nTime to execute: " << time.count() << "ms\n\nEnter 0 to close or 1 to go again." << endl;
        cin >> flag;
    }

    delete chase;
    delete targ;
}