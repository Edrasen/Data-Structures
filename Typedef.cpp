#include<iostream>
#include<vector>

using namespace std;

typedef struct persona{
    string nombre;
    int edad;
    
}persona;

void showData(persona *p){
    p->nombre = "Alain";
    p->edad =14;
}

int main(){
    persona p1;

    cout<<"Introduzca su nombre";
    cin>>p1.nombre;
    cout<<"Introduzca su edad";
    cin>>p1.edad;
    cout<<"Datos antes de la modificacion por referencia"<<endl;
    cout<<p1.nombre<<"\n";
    cout<<p1.edad<<"\n";
    showData(&p1);
    cout<<"EStos son los datos despues del paso por referencia"<<endl;
    cout<<p1.nombre<<"\n";
    cout<<p1.edad<<"\n";
}
