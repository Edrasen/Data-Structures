#include<iostream>
#include<vector>

using namespace std;

int SumVector(const vector<int> vector1, const vector<int> vector2, int n){
    vector<int> vector3(n);
    cout<<"La suma de los vectores es:"<<endl;
    for(int i = 0; i<n; i++){
        vector3[i] = vector1[i] + vector2[i];
        cout<<"v3"<<"["<<i<<"]"<<"="<<vector3[i]<<endl;
    }
}

int main(){
    int n;
    vector<int> vector1(n);
    vector<int> vector2(n);
    cout<<"Por favor ingrese el numero elementos que contendran los vectores. Ambos seran de la misma dimension"<<endl;
    cin>>n;
    cout<<"Ingrese los numeros del primer vector"<<endl;
    for(int i = 0; i<n; i++){
        cout<<"v1"<<"["<<i<<"]"<<"=";
        cin>>vector1[i];
    }
    cout<<"Ingrese los numeros del segundo vector"<<endl;
    for(int i = 0; i<n; i++){
        cout<<"v2"<<'['<<i<<']'<<"=";
        cin>>vector2[i];
    }

    SumVector(vector1, vector2, n);
}