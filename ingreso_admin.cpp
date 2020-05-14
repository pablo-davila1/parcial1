#include "ingreso_admin.h"
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include<map>
using namespace std;


int ingreso_admin::getA() const
{
    return a;
}

void ingreso_admin::setA(int value)
{
    a = value;
}

map<string, vector<int> > ingreso_admin::getData() const
{
    return data;
}

void ingreso_admin::setData(const map<string, vector<int> > &value)
{
    data = value;
}

ingreso_admin::ingreso_admin()
{

}

bool ingreso_admin::verificacion()
{
    string Cedula, Clave;
    cout<<"Ingrese su cedula: ";
    cin>>Cedula;
    cout<<"Ingrese su clave: ";
    cin>>Clave;
    ifstream leer ("sudo.txt", ios::in);
    string cedula,clave;
    leer>>cedula;
    leer>>clave;
    if (cedula == Cedula && Clave == clave){
        return true;
        leer.close();}
    else{
        return false;
        leer.close();
    }
}

void ingreso_admin::registrar()
{
    ofstream es;
    string cedula,clave;
    es.open("sudo.txt", ios::out | ios::app);
    cout<<"Ingrese su cedula: ";
    cin>>cedula;
    cout<<"Ingrese su clave: ";
    cin>>clave;
    es<<cedula<<' '<<clave<<endl;
    es.close();
    cout<<"Registrado con exito."<<endl<<endl;



}



int ingreso_admin::all_menu()
{
    int dec;
    while (true){
        cout<<"-----------------------------------------------------"<<endl<<'|'<<" Bienvenido, por favor ingrese una opcion (1,2 0 3)|"<<endl<<"-----------------------------------------------------"<<endl;
        cout<<"| (1): ver el menu de combos                        |"<<endl<<"| (2): ingresar como administrador                  |"<<endl<<"| (3): salir                                        |"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cin>>dec;
        if (dec == 1 || dec == 2 || dec==3)
            return dec;
        else
            cout<<"Su orden ("<<dec<<") no se encuentra en las opciones, recuerde pulsar 1 o 2."<<endl;
    }

}

int ingreso_admin::prin_menu()
{
    int dec;
    while (true){
        cout<<"------------------------------------"<<endl<<'|'<<"Por favor ingrese una opcion (1/2)|"<<endl<<"------------------------------------"<<endl;
        cout<<"| (1): inisiar sesion              |"<<endl<<"| (2): registrarse                 |"<<endl;
        cout<<"------------------------------------"<<endl;
        cin>>dec;
        if (dec == 1 || dec == 2)
            return dec;
        else
            cout<<"Su orden ("<<dec<<") no se encuentra en las opciones, recuerde pulsar 1 o 2."<<endl;
    }
}

bool ingreso_admin::login()
{
    ifstream leer ("sudo.txt", ios::in);
    string cedula,clave,Cedula,Clave;
    cout<<"Ingrese su cedula: ";
    cin>>Cedula;
    cout<<"Ingrese su celave: ";
    cin>>Clave;

    leer>>cedula;
    while(!leer.eof()){
        leer>>clave;
        if (Cedula==cedula && Clave == clave)
            return true;


    leer>>cedula;
    }
    return false;
    leer.close();

}


int ingreso_admin::see_combos()
{
    vector <string> combos;
    string combo;
    int desicion;
    char cadena[40];
    vector <int> precios;
    int precio;
    ifstream precios_doc;
    ifstream combos_doc;
    precios_doc.open("combos.txt", ios::in);
    combos_doc.open("nombres_combos.txt", ios::in);

    precios_doc>>precio;
    while(!precios_doc.eof()){
        precios.push_back(precio);
        precios_doc>>precio;
    }
    combos_doc.getline(cadena,40,'\n');
    while(!combos_doc.eof()){
        combos.push_back(cadena);
        combos_doc.getline(cadena,40,'\n');
    }
    while (true){
        cout<<"___________________________________________________________________________________"<<endl;
        cout<<"| Combo            ->            Contenido del combo           ->           Precio |"<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        for (int i = 0; i<precios.size() ; i++){
            cout<<"| "<<i+1<<".| -> |"<<combos[i]<<" | -> "<<precios[i]<<endl;
        }
        cout<<"------------------------------------------------------------------------------------"<<endl;
        cout<<"| Ingrese el numero corresponiente a la compra que desea efectuar: ";
        cin>>desicion;
        if (desicion < 1 || desicion > precios.size())
            cout<<"La opcion ("<<desicion<<") no esta en las opciones posibles, intente de nuevo."<<endl;
        else{
            combos_doc.close();
            precios_doc.close();
            return desicion;}
    }
}



map<string, vector<int> > ingreso_admin::cargar_data()
{
    int dec;
    map<string, vector<int>>data;
    string cadena;
    vector<string> cadenas;
    string combo_name;
    vector<string> cadena_combo;
    vector<int> cantidad;
    ifstream name_archivo;
    ifstream name_combos;
    name_combos.open("nombres_combos.txt", ios::in);
    char name_combo[40];
    name_combos.getline(name_combo,40,'\n');
    while(!name_combos.eof()){
        for(int i = 0; name_combo[i] != '\0'; i++){
            combo_name+= name_combo[i];
        }
        name_combos.getline(name_combo,40,'\n');
        cadena_combo.push_back(combo_name);
        combo_name.clear();
    }

    name_archivo.open("nombres_inventario.txt", ios::in);
    char name_product[30];
    name_archivo.getline(name_product,30,'\n');
    while(!name_archivo.eof()){
        for(int i = 0; name_product[i] != '\0'; i++){
            cadena+= name_product[i];
        }
        name_archivo.getline(name_product,30,'\n');
        cadenas.push_back(cadena);
        cadena.clear();
    }
    name_archivo.close();
    cout<<"____________________________________________________________________________________________"<<endl;
    cout<<"| Es nesesario saber que y cuantos ingredientes del invetario nesesita cada combo antes de  |\n|iniciar con la ejecucion (luego usted podra modificar tanto el inventario como los combos).|"<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    for(int i = 0; i<(cadena_combo.size()); i++){
        cout<<"los elementos disponibles en el inventario son: "<<endl;
        for(int j = 0; j<cadenas.size(); j++){
            cout<<"| "<<j+1<<". "<<cadenas[j]<<endl;
        }
    while(true){
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|ingrese que elemento de el inventario nesecita el combo ("<<cadena_combo[i]<<") o 0 para no agregar mas:"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    cin>>dec;
    while (dec < 0 || dec > cadenas.size()){
        cout<<"El elemento ("<<dec<<") no existe, ingrese otro: ";
        cin>>dec;
    }
    if (dec == 0){
        cadena = cadena_combo[i];
        data[cadena] = cantidad;
        cantidad.clear();
        break;}
    cantidad.push_back(dec);
    cout<<"Ingrese la cantidad que necesita de este elemento: ";
    cin>>dec;
    cantidad.push_back(dec);}

    }
    name_combos.close();
    name_archivo.close();
    return data;

}



void ingreso_admin::ejecutar_compra(int a, map<string, vector<int> > data)
{
    ifstream name_combos;
    string combo_name;
    int many_unit,contador,c=0,not1;
    float not2;
    vector<int>needs;
    vector<string>cadena_combo;
    name_combos.open("nombres_combos.txt", ios::in);
    char name_combo[40];
    name_combos.getline(name_combo,40,'\n');
    while(!name_combos.eof()){
        for(int i = 0; name_combo[i] != '\0'; i++){
            combo_name+= name_combo[i];
        }
        name_combos.getline(name_combo,40,'\n');
        cadena_combo.push_back(combo_name);
        combo_name.clear();
    }
    name_combos.close();
    needs = data[cadena_combo[a-1]];
    int unidades;
    ifstream unitis;
    unitis.open("inventario.txt", ios::in);
    unitis>>contador;
    while(!unitis.eof()){
        unitis>>many_unit;
        if (contador == needs[c]){
            if ((many_unit-needs[c+1])<0){
                cout<<"Lo sentmos, no hay suficientes ingredientes para hacer su pedido, vuelva mas tarde."<<endl;
                return;
            }
            if (c > needs.size())
                return;
        cout<<"si hay"<<endl;

        }
        unitis>>not1;
        unitis>>not2;
        c=c+2;
    }



}
