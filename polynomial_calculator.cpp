#include<iostream>
#include<algorithm>
using namespace std;
class Polynomial
{
    int exponent;
    int *term;
    public:
    Polynomial(int e): exponent(e) //constructor func.
    {
        term = new int [exponent+1];
        for(int i=0; i<=exponent; i++)
        {
            term[i]=0;
        }
    }
    ~Polynomial() //destructor func.
    {
        delete [] term;
    }
    Polynomial operator+(const Polynomial &p1) //+ operator overloading
    {
            int maxdeg=max(this->exponent,p1.exponent);
            Polynomial result(maxdeg);
            for(int i=0; i<=maxdeg; i++)
            {
                if(i<=this->exponent && i<=p1.exponent)
                result.term[i]=this->term[i]+p1.term[i];
                else if(i<=this->exponent)
                result.term[i]=this->term[i];
                else
                result.term[i]=p1.term[i];

            }
            return result;
    }
    friend ostream& operator<<(ostream& os, Polynomial &p1) //operator overloading
    {
        bool printed=true;
        for (int i=p1.exponent; i>=0; i--)
        {
            if(p1.term[i]==0)
            continue;
            if(!printed)
            os<<"+";
            if(i==0)
            os<<p1.term[i];
            else if(i==1)
            os<<p1.term[i]<<"x";
            else
            os<<p1.term[i]<<"x"<<i;
            printed=0;
        }  
        if(printed)
          os<<0;
        return os;
    }
friend istream& operator>>(istream& is, Polynomial &p1) //operator overloading
    {
        for(int i=0;i<=p1.exponent; i++)
        {
            cout<<"Coefficient of x"<<i<<": ";
            is>>p1.term[i];
        }
        
        return is;
    }
};

int main()
{
    int m1,m2;
    cout<<"Enter the degree of the polynomial 1: ";
    cin>>m1;
    Polynomial p1(m1);
    cin>>p1;  
    cout<<"Enter the degree of the polynomial 2: ";
    cin>>m2;
    Polynomial p2(m2);
    cin>>p2; 
    Polynomial sum = p1+ p2;
    cout<<"The sum of "<<p1<<"+"<<p2<<"="<<sum;
    return 0;
} //Will develop in progress..
