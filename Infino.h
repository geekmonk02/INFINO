#pragma once
#include <bits/stdc++.h>
#define ll long long int
#define cch const char
#define ci const int
using namespace std;


// creating the class for Infino


class Infino
{
protected:
    string digits;

public:
    // Constructors:
    Infino(cch *); 
    Infino(string &);  //string as int
    Infino(unsigned ll n = 0);   //Initializes the object from an unsigned long long integer by extracting its digits.
    Infino(Infino &);  //copy constructor

    // Functions:
    friend bool Null(const Infino &);
    friend void half(Infino &a);
    int operator[](ci) const;
    friend int Len(const Infino &);
    

    //op overload


    // Direct assignment
    Infino &operator=(const Infino &);  

    // Post/Pre - Incrementation

    Infino &operator--();
    Infino operator--(int temp);

    Infino &operator++();
    Infino operator++(int temp);
   
    // add , add =, minum , minus=........
    friend Infino &operator+=(Infino &, const Infino &);
    friend Infino &operator-=(Infino &, const Infino &);
    friend Infino operator-(const Infino &, const Infino &);
    friend Infino operator+(const Infino &, const Infino &);

    // comparison

    friend bool operator!=(const Infino &, const Infino &); // not equal
    friend bool operator==(const Infino &, const Infino &); //equal
    

    friend bool operator>(const Infino &, const Infino &);//greater than
    friend bool operator>=(const Infino &, const Infino &); // grtr thn eq
    friend bool operator<(const Infino &, const Infino &); //less thn
    friend bool operator<=(const Infino &, const Infino &); //less thn =


     // Power Function
    friend Infino &operator^=(Infino &, const Infino &);
    friend Infino operator^(Infino &, const Infino &);


    // Multiplication and Division
    friend Infino &operator*=(Infino &, const Infino &);
    friend Infino operator*(const Infino &, const Infino &);
    friend Infino &operator/=(Infino &, const Infino &);
    friend Infino operator/(const Infino &, const Infino &);


      // Square Root Function
    friend Infino sqrt(Infino &a);


    // Modulo
    friend Infino operator%(const Infino &, const Infino &); //remainder
    friend Infino &operator%=(Infino &, const Infino &);

   

  

    // Read and Write
    friend ostream &operator<<(ostream &, const Infino &);  //cin>>
    friend istream &operator>>(istream &, Infino &);   //cout<<

    // Others
    friend Infino NthCatalan(int n);
    friend Infino NthFibonacci(int n);
    friend Infino Factorial(int n);
};



//functionsssss............
//This constructor initializes an Infino object from a char array
Infino::Infino(cch *s) {
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            cout<<"error"<<endl;
       else{
            int x=s[i]-'0';
            digits.push_back(x);
       }
    }
}
//This constructor initializes an Infino object from a string
Infino::Infino(string &s) {
    digits = "";
    
    for (int i = s.size() - 1; i >= 0; i--) {   //pushed in reverse order for simplicity in calculation
        if (!isdigit(s[i]))  
            cout<<"error"<<endl;
       else{
            int x=s[i]-'0';
            digits.push_back(x);
       }
    }
}
//number to infino
Infino::Infino(unsigned ll number) {
    do {
        digits.push_back(number % 10);
        number /= 10;
    } while (number);
}

//copy constructor 
Infino::Infino(Infino &a) {
    digits = a.digits;
}



//find the length of the number eg. 4556854 has 7 lengths
int Len(const Infino &a) {
    return a.digits.size();
}



//check whether the number is prresent or not
bool Null(const Infino &a) {
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    else
        return false;
}


// Return the digit at the specified index.

int Infino::operator[](const int index) const {
    if (digits.size() <= index || index < 0)
        cout<<"ERROR"<<endl;
    return digits[index];
}

//checking two infinos are not equal or not
bool operator!=(const Infino &a, const Infino &b) {
    if(a==b) return 0;
    return 1;
}

//checking less than
bool operator<(const Infino &a, const Infino &b) {
    int n = Len(a), m = Len(b);
    if (n != m)
        return n < m;
    while (n--)
        if (a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}


//checking equality

bool operator==(const Infino &a, const Infino &b) {
     if(a.digits == b.digits) return true;
     return false;
}

//checking greater than
bool operator>(const Infino &a, const Infino &b) {
    return b < a;
}

//greaterthan equal
bool operator>=(const Infino &a, const Infino &b) {
     if(a<b) return false;
    return true;
}
  //less than equal
bool operator<=(const Infino &a, const Infino &b) {
    if(a>b) return false;
    return true;
}

//assignment

Infino &Infino::operator=(const Infino &a) {
    digits = a.digits;
    return *this;
}

//post decrement
Infino &Infino::operator--() {
    if (digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n; i++)
        digits[i] = 9;
    digits[i]--;
    if (n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}

Infino Infino::operator--(int temp) {
    Infino tmp;
    tmp = *this;
    --(*this);
    return tmp;
}

//post increment
Infino &Infino::operator++() {
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9; i++)
        digits[i] = 0;
    if (i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}

Infino Infino::operator++(int temp) {
    Infino tmp;
    tmp = *this;
    ++(*this);
    return tmp;
}








//+=

Infino &operator+=(Infino &a, const Infino &b) {
    int t = 0, s, i;
    int n = Len(a), m = Len(b);
    if (m > n)
        a.digits.append(m - n, 0);
    n = Len(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if (t)
        a.digits.push_back(t);
    return a;
}
//add

Infino operator+(const Infino &a, const Infino &b) {
    Infino temp;
    temp = a;
    temp += b;
    return temp;
}
//-=
Infino &operator-=(Infino &a, const Infino &b) {
    if (a < b)
        cout<<"UNDERFLOW"<<endl;
    int n = Len(a), m = Len(b);
    int i, t = 0, s;
    for (i = 0; i < n; i++) {
        if (i < m)
            s = a.digits[i] - b.digits[i] + t;
        else
            s = a.digits[i] + t;
        if (s < 0) {
            s += 10;
            t = -1;
        } else {
            t = 0;
        }
        a.digits[i] = s;
    }
    while (n > 1 && a.digits[n - 1] == 0) {
        a.digits.pop_back();
        n--;
    }
    return a;
}
//subs
Infino operator-(const Infino &a, const Infino &b) {
    Infino temp;
    temp = a;
    temp -= b;
    return temp;
}

//*=
Infino &operator*=(Infino &a, const Infino &b) {
    if (Null(a) || Null(b)) {  //if one of the number is 0 then return zero
        a = Infino();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i + j] += (a.digits[i]) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++) {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i];
    }
    for (int i = n - 1; i >= 1 && !v[i]; i--)
        a.digits.pop_back();
    return a;
}


//multiplicattion

Infino operator*(const Infino &a, const Infino &b) {
    Infino temp;
    temp = a;
    temp *= b;
    return temp;
}


//  /=
Infino &operator/=(Infino &a, const Infino &b) {
    if (Null(b))  //when denominator is 0
        throw("Arithmetic Error: Division By 0");


    if (a < b) {
        a = Infino();
        return a;
    }
    if (a == b) {
        a = Infino(1);
        return a;
    }
    int i, ind = 0, cc;
    int n = Len(a), m = Len(b);
    vector<int> tempvec(n, 0);
    Infino t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        tempvec[ind++] = cc;
    }
    a.digits.resize(tempvec.size());
    for (i = 0; i < ind; i++)
        a.digits[i] = tempvec[ind - i - 1];
    a.digits.resize(ind);
    return a;
}




//division

Infino operator/(const Infino &a, const Infino &b) {
    Infino temp;
    temp = a;
    temp /= b;
    return temp;
}




//modulus
Infino &operator%=(Infino &a, const Infino &b) {
    if (Null(b)) //deno cant be zero
        throw("Arithmetic Error: Division By 0");
    if (a < b)
        return a;
    if (a == b) {
        a = Infino();  //a%a=0
        return a;
    }
    int i, ind = 0, tempind;
    int n = Len(a), m = Len(b);
    vector<int> tempvec(n, 0);
    Infino t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (tempind = 9; tempind * b > t; tempind--);
        t -= tempind * b;
        tempvec[ind++] = tempind;
    }
    a = t;
    return a;
}


//%

Infino operator%(const Infino &a, const Infino &b) {
    Infino temp;
    temp = a;
    temp %= b;
    return temp;
}

//half

void half(Infino &a) {
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while (a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}
//power expo

Infino &operator^=(Infino &a, const Infino &b) {
    Infino Exponent, Base(a);
    Exponent = b;
    a = 1;
    while (!Null(Exponent)) {
        if (Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        half(Exponent);
    }
    return a;
}

Infino operator^(Infino &a, Infino &b) {
    Infino temp(a);
    temp ^= b;
    return temp;
}


//square root
Infino sqrt(Infino &a) {
    Infino left(1), right(a), v(1), mid, prod;
    half(right);
    while (left <= right) {
        mid += left;
        mid += right;
        half(mid);
        prod = (mid * mid);
        if (prod <= a) {
            v = mid;
            ++mid;
            left = mid;
        } else {
            --mid;
            right = mid;
        }
        mid = Infino();
    }
    return v;
}

//i/p,o/p

istream &operator>>(istream &in, Infino &a) {
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const Infino &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--)
        cout << (short)a.digits[i];
    return cout;
}
