#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

int main()
{
    const int MAXROWS = 2;
    const int MAXCOLS = 3;

    string str1[MAXROWS][MAXCOLS] =
    {
        {"Congra", "y", "ar"},
        {"alm", "don", "La"}
    };
    string str2[MAXROWS][MAXCOLS] =
    {
        {"tulations", "ou", "e"},
        {"ost", "e    the", "b!"}
    };
    int num1[MAXROWS][MAXCOLS] =
    {
        {1, 2, 3},
        {4, 5, 6}
    };
    int num2[MAXROWS][MAXCOLS] =
    {
        {6, 5, 4},
        {3, 2, 1}
    };
    float float1[MAXROWS][MAXCOLS] =
    {
        {1.6f, 2.5f, 3.4f},
        {4.3f, 5.2f, 6.1f}
    };
    float float2[MAXROWS][MAXCOLS] =
    {
        {6.1f, 5.2f, 4.3f},
        {3.4f, 2.5f, 1.6f}
    };

    Matrix<string, MAXROWS, MAXCOLS> stringMatrix;
    Matrix<int, MAXROWS, MAXCOLS> intMatrix;
    Matrix<float, MAXROWS, MAXCOLS> floatMatrix;

    cout << "\nDemonstrating with string matrix:" << endl;
    stringMatrix.demoTemplate(str1, str2);

    cout << "\nDemonstrating with int matrix:" << endl;
    intMatrix.demoTemplate(num1, num2);

    cout << "\nDemonstrating with float matrix:" << endl;
    floatMatrix.demoTemplate(float1, float2);

    cout << "\n" << endl;
    return 0;
}
