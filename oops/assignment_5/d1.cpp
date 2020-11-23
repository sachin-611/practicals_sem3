#include <iostream>
using namespace std;

template <class T>
T Min(T num1, T num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

template <class T>
T Max(T num1, T num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}

int main()
{
	int n1, n2;
	double d1, d2;
	string s1, s2;
    char c1,c2;

	cout << "Enter two integer values:\n";
	cin  >> n1 >> n2;

	cout << "Lesser: " <<  Min(n1, n2) << endl;
	cout << "Greater: " << Max(n1, n2) << endl;

	cout << "Enter two float values:\n";
	cin  >> d1 >> d2;

	cout << "Lesser: " << Min(d1, d2) << endl;
	cout << "Greater: " << Max(d1, d2) << endl;

    cout << "Enter two char values:\n";
	cin >> c1 >> c2; 
	cout << "Lesser: " << Min(c1, c2) << endl;
	cout << "Greater: " << Max(c1, c2) << endl;

	cout << "Enter two strings values:\n";
	cin >> s1 >> s2; 
	cout << "Lesser: " << Min(s1, s2) << endl;
	cout << "Greater: " << Max(s1, s2) << endl;

	return 0;
}