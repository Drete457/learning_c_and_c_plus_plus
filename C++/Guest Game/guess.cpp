#include <iostream>
#include <cstdlib>
#include <ctime>

//this make the program to know that we sill use functions from the std, we only need to write cout <<, and not std::cout <<
using namespace std;

int main()
{
    cout << "******************************************" << endl;
    cout << "*      Welcome to our guessing game!     *" << endl;
    cout << "******************************************" << endl;

    srand(time(NULL));
    const int SECRET_NUMBER = rand() % 100;
    double points = 1000.0;
    cout << SECRET_NUMBER << endl;
    cout << "What is the level of difficulty? " << endl;
    cout << "(E) Easy (M) Medium (D) Difficult  " << endl;

    char level;
    cin >> level;

    int numberOfTries = 0;
    switch (level)
    {
    case 'F':
        numberOfTries = 15;
        break;
    case 'M':
        numberOfTries = 10;
        break;
    default:
        numberOfTries = 5;
        break;
    }

    do
    {
        cout << "What number you choose? ";
        int guestNumber;
        cin >> guestNumber;

        bool guest = guestNumber == SECRET_NUMBER;
        bool larger = guestNumber > SECRET_NUMBER;

        double pointsLose = abs(guestNumber - SECRET_NUMBER) / 2.0;
        points -= pointsLose;

        if (guest)
        {
            cout << "Congratulations you guest the secret number!!" << endl;
            cout << "You still had " << numberOfTries << " tries" << endl;
            break;
        }
        else if (larger)
        {
            cout << "The number you choose is greater than the secret number" << endl;
        }
        else
        {
            cout << "The number you choose is less than the secret number" << endl;
        }

        numberOfTries--;
        cout << "You still have " << numberOfTries << " tries" << endl;

    } while (numberOfTries > 0);

    // need to write precision before the cout that will print the result, we always print the number in scientific number. exp: 9.9ex02
    cout.precision(2);
    // using the fixed will make the cout print the number in .00 format exp: 999.00
    cout << fixed;
    cout << "Total of points: " << points << endl;
    cout << "Thanks for playing!" << endl;
}
