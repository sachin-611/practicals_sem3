#include <bits/stdc++.h>
using namespace std;
int nopoly = 1;
struct polynomail_represent
{
    int coeff;
    int expon;
};
class Polynomial
{
    int arr_cap;
    polynomail_represent *expo_coeff;

public:
    Polynomial()
    {
        expo_coeff = new polynomail_represent[100];
    }
    friend istream &operator>>(istream &input, Polynomial &polyn)
    {
        int n;
        cout << "\n"
             << "Number of variables in Polynomial " << nopoly << " are ";
        cin >> n;
        cout << "Enter the Coefficient And Degree in Polynomial " << nopoly << " (in Descending Order)" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "\n";
            cout << "Enter coefficient (" << i + 1 << ") : ";
            cin >> polyn.expo_coeff[i].coeff;
            cout << "Enter degree (" << i + 1 << ") : ";
            cin >> polyn.expo_coeff[i].expon;
        }
        nopoly += 1;
        polyn.arr_cap = n;
        return input;
    }
    friend ostream &operator<<(ostream &output, Polynomial &polyn)
    {
        cout << "The expression is : ";
        for (int i = 0; i < polyn.arr_cap; i++)
        {
            (i != 0) ? cout << " + " << polyn.expo_coeff[i].coeff << "(x^" << polyn.expo_coeff[i].expon << ")" : cout << polyn.expo_coeff[i].coeff << "(x^" << polyn.expo_coeff[i].expon << ")";
        }
        cout << endl;
        return output;
    }
    Polynomial operator+(Polynomial &polyn)
    {
        Polynomial temp_polyn;
        int i, j, k;
        i = 0;
        j = 0;
        k = 0;
        while (i < arr_cap && j < polyn.arr_cap)
        {
            if (expo_coeff[i].expon == polyn.expo_coeff[j].expon)
            {
                temp_polyn.expo_coeff[k].coeff = expo_coeff[i].coeff + polyn.expo_coeff[j].coeff;
                temp_polyn.expo_coeff[k].expon = expo_coeff[i].expon;
                i++;
                j++;
                k++;
            }
            else if (expo_coeff[i].expon > polyn.expo_coeff[j].expon)
            {
                temp_polyn.expo_coeff[k].coeff = expo_coeff[i].coeff;
                temp_polyn.expo_coeff[k].expon = expo_coeff[i].expon;
                i++;
                k++;
            }
            else
            {
                temp_polyn.expo_coeff[k].coeff = polyn.expo_coeff[j].coeff;
                temp_polyn.expo_coeff[k].expon = polyn.expo_coeff[j].expon;
                j++;
                k++;
            }
        }
        while (i < arr_cap)
        {
            temp_polyn.expo_coeff[k].coeff = expo_coeff[i].coeff;
            temp_polyn.expo_coeff[k].expon = expo_coeff[i].expon;
            i++;
            k++;
        }
        while (j < polyn.arr_cap)
        {
            temp_polyn.expo_coeff[k].coeff = polyn.expo_coeff[j].coeff;
            temp_polyn.expo_coeff[k].expon = polyn.expo_coeff[j].expon;
            j++;
            k++;
        }
        temp_polyn.arr_cap = k;
        return temp_polyn;
    }
    Polynomial operator*(Polynomial &polyn)
    {
        Polynomial temp_polyn;
        int max_expo = expo_coeff[0].expon + (polyn.expo_coeff[0].expon);
        int prod[max_expo + 1];
        for (int i = 0; i <= max_expo; i++)
        {
            prod[i] = 0;
        }
        for (int i = 0; i < arr_cap; i++)
        {
            for (int j = 0; j < polyn.arr_cap; j++)
            {
                prod[expo_coeff[i].expon + (polyn.expo_coeff[j].expon)] += (expo_coeff[i].coeff) * (polyn.expo_coeff[j].coeff);
            }
        }
        for (int i = 0; i <= max_expo; i++)
        {
            temp_polyn.expo_coeff[max_expo - i].expon = i;
            temp_polyn.expo_coeff[max_expo - i].coeff = prod[i];
        }
        temp_polyn.arr_cap = max_expo + 1;
        return temp_polyn;
    }
    Polynomial operator*(int mult)
    {
        Polynomial temp_polyn;
        for (int i = 0; i < arr_cap; i++)
        {
            temp_polyn.expo_coeff[i].expon = expo_coeff[i].expon;
            temp_polyn.expo_coeff[i].coeff = mult * expo_coeff[i].coeff;
        }
        return temp_polyn;
    }
    Polynomial operator+(int add)
    {
        Polynomial temp_polyn;
        for (int i = 0; i < arr_cap - 1; i++)
        {
            temp_polyn.expo_coeff[i].expon = expo_coeff[i].expon;
            temp_polyn.expo_coeff[i].coeff = expo_coeff[i].coeff;
        }
        temp_polyn.expo_coeff[arr_cap - 1].expon += expo_coeff[arr_cap - 1].expon;
        temp_polyn.expo_coeff[arr_cap - 1].coeff = add + expo_coeff[arr_cap - 1].coeff;
        return temp_polyn;
    }
    void operator/(int x)
    {
        int outpu_val = 0;
        for (int i = 0; i < arr_cap; i++)
        {
            outpu_val += expo_coeff[i].coeff * pow(x, expo_coeff[i].expon);
        }
        cout << "When we put " << x << " in the Polynomial 1, the value we get is " << outpu_val << endl;
    }
};
void roots_of_quadratic()
{
    float a, b, c, root1, root2, discri, real, imaginary;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
    discri = b * b - 4 * a * c;
    if (discri > 0)
    {
        root1 = (-b + sqrt(discri)) / (2 * a);
        root2 = (-b - sqrt(discri)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "root1 = " << root1 << endl;
        cout << "root2 = " << root2 << endl;
    }
    else if (discri == 0)
    {
        cout << "Roots are real and same." << endl;
        root1 = (-b + sqrt(discri)) / (2 * a);
        cout << "root1 = root2 =" << root1 << endl;
    }
    else
    {
        real = -b / (2 * a);
        imaginary = sqrt(-discri) / (2 * a);
        cout << "Roots are complex and different." << endl;
        cout << "root1 = " << real << "+" << imaginary << "i" << endl;
        cout << "root2 = " << real << "-" << imaginary << "i" << endl;
    }
}
int main()
{
    Polynomial p1, p2;
    int x;
    cin >> p1;
    cin >> p2;
    cout << p1;
    cout << p2;
    Polynomial p3 = p1 + p2;
    cout << "After adding the two polynomials : " << endl;
    cout << p3;
    cout << "\n";
    p3 = p1 * p2;
    cout << "After multiplying the two polynomials : " << endl;
    cout << p3;
    cout << "\n";
    cout << "Enter the value of x you want to find ";
    cin >> x;
    p1 / x;
    return 0;
}