#include<iostream>

#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct rational{
    int numerator;
    int denominator;
}rational;

void reduce(rational *inrat, rational outrat);
int equal(rational *rat1, rational *rat2);

int main(){
    rational ra1, ra2;
    cout<<"Rational equality verification"<<endl;
    cout<<"Por favor introduzca el numerador y denominador del primer numero"<<endl;
    cout<<"Numerador 1"<<endl;
    cin>>ra1.numerator;
    cout<<"Denominador 1"<<endl;
    cin>>ra1.denominator;
    cout<<ra1.numerator<<'/'<<ra1.denominator<<endl;
    cout<<"Por favor introduzca el numerador y denominador del segundo numero"<<endl;
    cout<<"Numerador 2"<<endl;
    cin>>ra2.numerator;
    cout<<"Denominador 2"<<endl;
    cin>>ra2.denominator;
    cout<<ra2.numerator<<'/'<<ra2.denominator<<endl;
    equal(&ra1, &ra2);
}

void reduce(rational *inrat, rational *outrat){
    
    int a, b, rem;

    if(inrat->numerator > inrat->denominator){
        a = inrat->numerator;
        b = inrat->denominator;
    }
    else{
        a = inrat->denominator;
        b = inrat->numerator;
    }
    while(b != 0){
        rem = a % b;
        a = b;
        b = rem;
    }
    outrat->numerator = inrat->numerator/a;
    outrat->denominator = inrat->denominator/a;
}

int equal(rational *rat1, rational *rat2){
    
    rational r1, r2;

    reduce(rat1, &r1);
    reduce(rat2, &r2);

    if(r1.numerator == r2.numerator && r1.denominator == r2.denominator){
        cout<<"Son equivalentes"<<endl;
        return(TRUE);
    }
    cout<<"Son diferentes"<<endl;
    return(FALSE);
}