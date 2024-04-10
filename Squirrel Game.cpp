#include <iostream>

using namespace std;

class chaser
{
public:
    double xcord(double theta)
    {
        return cos(theta);
    }

    double ycord(double theta)
    {
        return sin(theta);
    }

    double theta(double chy, double tay, double distance)
    {
        return asin(((tay - chy) / distance));
    }
};

class target
{
public:
    double xcord(double theta)
    {
        return cos(theta);
    }

    double ycord(double theta)
    {
        return sin(theta);
    }
};

int main()
{
    bool flag = 1;
    chaser* chase = new chaser;
    target* targ = new target;

    while (flag)
    {
        double chx = 0, chy = 0, tax = 10, tay = 10, distance = 2, chtheta, disx = 0, disy = 0;
        int count = 0;
        srand(time(nullptr));

        while (distance > 1)
        {
            double tatheta = rand() % 89 + 1;
            distance = sqrt((pow((tax - chx), 2) + pow((tay - chy), 2)));
            chtheta = chase->theta(chy, tay, distance);
            chx += chase->xcord(chtheta);
            chy += chase->ycord(chtheta);
            tax += targ->xcord(tatheta);
            tay += targ->ycord(tatheta);
            disx += chase->xcord(chtheta);
            disy += chase->ycord(chtheta);
            ++count;
        }
        cout << "It took " << count << " moves to catch the target.\nChaser coordinates: (" << chx << ", " << chy << ")\nTarget coordinates: (" << tax << ", " << tay << ")\nDistance: " << distance << "m\nChaser travelled " << disx << "m on the x - axis\nChaser travelled " << disy << "m on the y - axis\nChaser offset is " << (chx - 0) << "m x - axis and " << (chy - 0) << "m y - axis\nTarget offset is " << (tax - 10) << "m x - axis and " << (tay - 10) << "m y - axis" << "\n\nEnter 0 to close or 1 to go again." << endl;
        cin >> flag;
    }

    delete chase;
    delete targ;
}