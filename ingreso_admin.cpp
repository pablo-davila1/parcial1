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
/*
Esta función no espera ninguna variable, y se encarga de verificar que la
cedula del usuario y la contraseña sean del administrador, la contraseña y
la cedula están almacenadas en el archivo “sudo.txt” y corresponden a la
primera linea del archivo respectivamente
*/
bool ingreso_admin::verificacion()
{
    cout<<endl;
    cout<<"Para poner en marcha la aplicacion es neceario que se identifique como administrador."<<endl;
    string Cedula, Clave;
    cout<<"Ingrese su cedula de administrador: ";
    cin>>Cedula;
    cout<<"Ingrese su clave de administrador: ";
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

/*
Esta funcion se encarga de agragar un usuario al alchivo “sudo.txt”,
los agrega al final del archivo
*/

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


/*
Esta funcion se encarga de imprimir un cuadro en consola, el cual
contiene texto representando las opciones que tiene el usuario
1.ver el menú de combos
2 ingresar como administrador
3: salir
en el caso de que elija otra opccion, le reitera que
elija una que este disponible.
Retorna un objeto tipo “int” que representa la desicion
del usuario
(este cuadro es para los usuarios que ya ingresaron)
*/
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
/*
Esta funcion se encarga de imprimir un cuadro en consola, el cual
contiene texto representando las opciones que tiene el usuario
1.inisiar sesion
2 registrarse
3: salir
en el caso de que elija otra opccion, le reitera que
elija una que este disponible.
Retorna un objeto tipo “int” que representa la desicion
del usuario
(este cuadro es para los usuarios que no han ingresado)
*/

int ingreso_admin::prin_menu()
{
    int dec;
    while (true){
        cout<<"------------------------------------"<<endl<<'|'<<"Por favor ingrese una opcion (1/2)|"<<endl<<"------------------------------------"<<endl;
        cout<<"| (1): inisiar sesion              |"<<endl<<"| (2): registrarse                 |"<<endl<<"| (3): salir                       |"<<endl;
        cout<<"------------------------------------"<<endl;
        cin>>dec;
        if (dec == 1 || dec == 2 || dec == 3)
            return dec;
        else
            cout<<"Su orden ("<<dec<<") no se encuentra en las opciones, recuerde pulsar 1 o 2."<<endl;
    }
}
/*
Esta función se encarga de permitir que el usuario ingrese a la
aplicación, pidiéndole que ingrese la cedula y la contraseña,
procede a verificar su existencia y que la contraseña coincida
con la cedula en el archivo “sudo.txt”, de ser así retorna un
bool true, de lo contrario retorna false
*/
bool ingreso_admin::login()
{
    cout<<endl;
    ifstream leer ("sudo.txt", ios::in);
    string cedula,clave,Cedula,Clave;
    cout<<"Ingrese su cedula para acceder: ";
    cin>>Cedula;
    cout<<"Ingrese su celave  para acceder: ";
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

/*
Esta funcion se encarga de imprimir un cuadro en consola, el cual
contiene texto representando los combos disponibles para el usuario,
un ciclo for() se encrga de imprmirlo recorriendo los archivos
"nombres_combos.txt" y "combos.txt".
en el caso de que elija otra opccion, le reitera que
elija una que este disponible.
Retorna un objeto tipo “int” que representa la desicion
del usuario

*/
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


/*
esta función retorna un dato tipo map, el cual contiene como
contraseña un dato tipo string, que corresponde al nombre del
combo, y como clave asociada contiene un dato tipo vector<int>
cuyas posiciones impares representan el elemento del inventario,
y las pares representan la cantidad que necesitan de el elemento
del inventario

*/
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


/*
esta función se encarga de realizar una compra elegida por el
usuario, usa los archivos "ventas.txt" , "combos.txt" y
 "nombres_combos.txt" para extraer datos  y crear
una estructura que sigue los siguientes pasos
1. restar los ingredientes de la compra al inventario
2.hacer la compra
3. cargar esta compra al archivo "ventas.txt"
*/
void ingreso_admin::ejecutar_compra(int a, map<string, vector<int> > data)
{
    ofstream registro;
    registro.open("ventas.txt", ios::out | ios::app);
    int num = 1,precio;
    vector<int>precios;
    ifstream precio_combo;
    precio_combo.open("combos.txt",ios::in);
    precio_combo>>precio;
    while(!precio_combo.eof()){
        if (num == a){
            registro<<"venta de comobo "<<a<<": "<<precio<<endl;
            break;
            registro.close();
        }
        num++;
        precio_combo>>precio;
    }
    registro.close();
    precio_combo.close();


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
    ofstream unitis_aux;
    unitis_aux.open("inventario_aux.txt",ios::out);
    ifstream unitis;
    unitis.open("inventario.txt", ios::in);
    unitis>>contador;
    while(!unitis.eof()){
        unitis>>many_unit;
        unitis>>not1;
        unitis>>not2;
        if (contador == needs[c]){
            if ((many_unit-needs[c+1])<0){
                cout<<"Lo sentmos, no hay suficientes ingredientes para hacer su pedido, vuelva mas tarde."<<endl;
                return;
            }
            else if (c > needs.size()){

            }
            else{
                unitis_aux<<contador<<' '<<many_unit-needs[c+1]<<' '<<not1<<' '<<not2<<endl;

            }


        }
        else{
            unitis_aux<<contador<<' '<<many_unit<<' '<<not1<<' '<<not2<<endl;}
        unitis>>contador;
        c=c+2;
    }

    unitis.close();
    unitis_aux.close();
    cout<<"compra realizada con exito."<<endl;
    remove("inventario.txt");
    rename("inventario_aux.txt","inventario.txt");

}
/*
Esta funcion se encarga de imprimir un cuadro en consola, el cual
es especifico para el administrador.
contiene texto representando las opciones que tiene el administrador
1. comprar ingredientes para el inventrio
2. ver el registros de ventas del dia
3. ver el registro de compras para el inventario del dia
4. salir
en el caso de que elija otra opccion, le reitera que
elija una que este disponible.
Retorna un objeto tipo “int” que representa la desicion
del administrador
*/

int ingreso_admin::menu_admin()
{
    int dec;
    while(true){
        cout<<"__________________________________________________________"<<endl;
        cout<<"|     Bienvenido administrador, elija una opcion          |"<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<"| 1. comprar ingredientes para el inventrio               |"<<endl;
        cout<<"| 2. ver el registros de ventas del dia                   |"<<endl;
        cout<<"| 3. ver el registro de compras para el inventario del dia|"<<endl;
        cout<<"| 4. salir                                                |"<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<"ingrese la opcion que desa ejecutar: ";
        cin>>dec;
        if (dec == 1 || dec==2 || dec==3 || dec == 4)
            return dec;
        else
            cout<<"la opcion ("<<dec<<") no esta en las opciones, intente de nuevo."<<endl;
    }

}
/*
esta función le permite al administrador comprar ingredientes para
el inventario en caso de que ya no hallan ingredientes lo cual
impediría que mas usuarios compren o por que simplemente
desea comprar, agrega las unidades compradas al inventario
y agrega la compra el archivo “compras.txt”
*/
void ingreso_admin::comprar_ingred()
{
    int dec;
    int paquetes;
    int precio,cant,not1;
    float not2;
    vector <int> cantidad_paquete;// <- la cantidad por paquete
    vector <int> precio_paquete;// <- los precios
    string cadena;
    vector<string> ingredientes;
    ifstream paquetes_precio;
    paquetes_precio.open("paquetes_inventario.txt", ios::in);
    paquetes_precio>>paquetes;
    while(!paquetes_precio.eof()){
        paquetes_precio>>precio;
        cantidad_paquete.push_back(paquetes);// <- la cantidad por paquete
        precio_paquete.push_back(precio);// <- los precios

        paquetes_precio>>paquetes;
    }

    ifstream name_archivo;
    name_archivo.open("nombres_inventario.txt", ios::in);
    char name_product[30];
    name_archivo.getline(name_product,30,'\n');
    while(!name_archivo.eof()){
        for(int i = 0; name_product[i] != '\0'; i++){
            cadena+= name_product[i];
        }
        name_archivo.getline(name_product,30,'\n');
        ingredientes.push_back(cadena);
        cadena.clear();
    }
    name_archivo.close();
    paquetes_precio.close();
    cout<<"______________________________________________________________________________________________________________________________"<<endl;
    cout<<"|                                                     LOS INGREDIENTES SON                                                    |"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i<ingredientes.size() ; i++){
        cout<<"| "<<i+1<<". "<<ingredientes[i]<<", cada paquete trae "<<cantidad_paquete[i]<<" unidades y cuesta "<<precio_paquete[i]<<"$. "<<endl;
        cout<<"-----------------------------------------------------------------------.------------------------------------------------------"<<endl;

    }
    cout<<"|ingrese la opcion del ingrediente que desee comprar: ";
    cin>>dec;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Ingrese cuatos paquetes de ("<<ingredientes[dec-1]<<") desea comprar: ";
    cin>>cant;

    int num,unids;
    ofstream actualizar_aux;
    actualizar_aux.open("inventario_aux.txt", ios::out);
    ifstream actualizar;
    actualizar.open("inventario.txt",ios::in);
    actualizar>>num;
    while(!actualizar.eof()){
        actualizar>>unids;
        actualizar>>not1;
        actualizar>>not2;
        if (num == dec){
            actualizar_aux<<num<<' '<<unids + (cant*cantidad_paquete[dec-1])<<' '<<not1<<' '<<not2<<endl;
        }
        else{
            actualizar_aux<<num<<' '<<unids <<' '<<not1<<' '<<not2<<endl;
        }
    actualizar>>num;
    }
    remove("inventario.txt");
    rename("inventario_aux.txt","inventario.txt");
    actualizar.close();
    actualizar_aux.close();

    ofstream compras;
    compras.open("compras.txt", ios::out | ios::app);
    compras<<"se compro "<<cant<<" paquetes de "<<ingredientes[dec-1]<<" por un valor de: "<<(precio_paquete[dec-1])*cant<<endl;
    compras.close();
}
/*
esta función imprime el historial de ventas de el archivo "ventas.txt" si
el administrador lo desea
*/
void ingreso_admin::registro_venta()
{
    ifstream ver;
    int c=1;
    ver.open("ventas.txt",ios::in);
    char texto[100];
    ver.getline(texto,100,'\n');
    while(!ver.eof()){
        cout<<"| "<<c<<" : "<<texto<<endl;
        ver.getline(texto,100,'\n');
        c++;
    }

}

/*
esta función imprime el historial de compras de el archivo "compras.txt" si
el administrador lo desea
*/
void ingreso_admin::registro_compra()
{
    ifstream ver;
    int c=1;
    ver.open("compras.txt",ios::in);
    char texto[100];
    ver.getline(texto,100,'\n');
    while(!ver.eof()){
        cout<<"| "<<c<<" : "<<texto<<endl;
        ver.getline(texto,100,'\n');
        c++;
    }

}
