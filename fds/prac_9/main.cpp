#include <bits/stdc++.h>
using namespace std;
struct poly_store{
    int coeff;
    int exp;
};
class polynomial
{
    int degree;
    struct poly_store terms[];
public:
    polynomial(int n){
        degree=n;
        terms[n];
    }
    friend ostream& operator << (ostream &out,const polynomial &object1)
    {
        out << "\nPolynomial is ---> ";
        if (object1.degree == 0) {
            out << object1.terms[0].coeff;
            return out;
        }
        for (int i = 0; i <= object1.degree; i++) {
            if (object1.terms[i].coeff != 0) {
                if (object1.terms[i].coeff != 1)
                    out << object1.terms[i].coeff << "x^" << object1.terms[i].exp << " + ";
                else
                    out << "x^" << object1.terms[i].exp << " + ";
            }
        }
        return out;
    }
    friend istream & operator>>(istream &bin,polynomial &object1)
    {
        for(int i=0;i<=object1.degree;i++)
        {
            cout<<"\nEnter the coefficient for --> ";
            object1.terms[i].exp = i;
            cout<<"x^"<<object1.terms[i].exp<<" : ";
            bin>>object1.terms[i].coeff;
        }
        return bin;
    }
    polynomial operator +(polynomial &object1)
    {
        int maxi = this->degree>object1.degree?this->degree:object1.degree;
        polynomial result(maxi);
        for(int i = 0;i<=maxi;i++)
        {
            result.terms[i].exp = i;
            result.terms[i].coeff = this->terms[i].coeff + object1.terms[i].coeff;
        }
        cout<<"\n The addition of the two polynomials results in : ";
        return result;
    }
    polynomial operator *(polynomial &object1)
    {
        polynomial product(this->degree + object1.degree);
        for(int i =0;i<=this->degree;i++)
        {
            for(int j = 0;j<=object1.degree;j++)
            {
                product.terms[this->terms[i].exp + object1.terms[j].exp].coeff += this->terms[i].coeff * object1.terms[j].coeff;
            }
        }
        cout<<"\n Multiplication of the two polynomials results in :";
        return product;
    }
    void operator =(int value){
        long int result = 0;
        for(int i=0;i<degree+1;i++)
            result += terms[i].coeff * pow(value, terms[i].exp);
        cout<<"\n The polynomial evaluates to "<<result<<" for x = "<<value<<endl;
    }
};

void choice()
{
    cout<<"\n1 show first polynomial"<<endl;
    cout<<"2 show second polynomial"<<endl;
    cout<<"3 evaluate first polynomial"<<endl;
    cout<<"4 evaluate second polynomial"<<endl;
    cout<<"5 add polynomials"<<endl;
    cout<<"6 multiply both polynomial"<<endl;
}

int main() {
    cout<<"Enter first polynomial : ";
    cout<<"\nEnter degree of polynomial : ";
    int temp;cin>>temp;
    polynomial p1(temp);
    cin>>p1;
    cout<<"\n Enter second polynomial : ";
    cout<<"\nEnter degree of polynomial : ";
    cin>>temp;
    polynomial p2(temp);
    cin>>p2;
    while(1){
        int choice_input;
        choice();
        cin>>choice_input;
        if(choice_input==1){
            cout<<p1;
        }else if(choice_input==2){
            cout<<p2;
        }else if(choice_input==3){
            cout<<"\nEnter the value of x: ";
            cin>>temp;
            p1=temp;
        }else if(choice_input==4){
            cout<<"\nEnter the value of x: ";
            cin>>temp;
            p2=temp;
        }else if(choice_input==5){
            cout<<p1+p2;
        }else if(choice_input==6){
            cout<<p1*p2;
        }else{
            cout<<"\nInvalid choice!!"<<endl;
        }
        cout<<"\nContinue?(1(yes)/0(no))";
        cin>>temp;
        if(temp==0)
            break;
    }
    return 0;
}
