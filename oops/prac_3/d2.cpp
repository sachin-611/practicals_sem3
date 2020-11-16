#include <bits/stdc++.h>
using namespace std;
class rat
{
    int numerator;
    int denominator;

public:
    void getdata()
    {
        cout << "\n enter the numerator part of the rational no. :: ";
        cin >> numerator;
        cout << "\n enter the denominator part of the rational no. :: ";
        cin >> denominator;
    }
    void operator+(rat c1)
{
    rat temp;
    temp.numerator = (numerator * c1.denominator) + (c1.numerator * denominator);
    temp.denominator = denominator * c1.denominator;
    cout << "\nrational no. after addition :: ";
    cout << "\n numerator = " << temp.numerator << "\n denominator = " << temp.denominator;
}
void operator*(rat c1)
{
    rat temp;
    temp.numerator = numerator * c1.numerator;
    temp.denominator = denominator * c1.denominator;
    cout << "\n rational no. after multiplication :: ";
    cout << "\n numerator = " << temp.numerator << "\n denominator = " << temp.denominator;
}
    void operator/(rat c1)
{
    rat temp;
    temp.numerator = numerator * c1.denominator;
    temp.denominator = c1.numerator * denominator;
    cout << "\n rational no. after dividation :: ";
    cout << "\n numerator = " << temp.numerator << "\n denominator = " << temp.denominator;
}
void operator-(rat c1)
{
    rat temp;
    temp.numerator = (numerator * c1.denominator) - (c1.numerator * denominator);
    temp.denominator = denominator * c1.denominator;
    cout << "\n rational no. after subtraction :: ";
    cout << "\n numerator = " << temp.numerator << "\n denominator = " << temp.denominator;
}
};


int main()
{
    rat c1, c2;
    int n;
    do
    {
        cout << "\n\n 1.Input rational no. ";
        cout << "\n 2. Add rational no. ";
        cout << "\n 3. Subtract rational no. ";
        cout << "\n 4. Multiply rational no.";
        cout << "\n 5. Divide rational no. ";
        cout << "\n 6. Quit";
        cout << "\n\n Enter your choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << endl
                 << "\n enter the data for first rational no.:: ";
            c1.getdata();
            cout << endl
                 << "\n enter the data for second rational no. :: ";
            c2.getdata();
            break;
        case 2:
            c1 + c2;
            break;
        case 3:
            c1 - c2;
            break;
        case 4:
            c1 *c2;
            break;
        case 5:
            c1 / c2;
            break;
        case 6:
            exit(1);
            break;
        }
    } while (n != 6);
    return 0;
}