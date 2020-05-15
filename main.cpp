#include "ingreso_admin.h"
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

ingreso_admin condicion;
int main()
{
    map<string,vector<int>>Data;
    bool conf = false;
    int dec,menu_principal;
    while (conf == false){
    ingreso_admin admin;
    conf=admin.verificacion();
    if (conf==false)
        cout<<"usted no es el asministrador, intente de nuevo"<<endl;
    }

    Data = condicion.cargar_data();

    while (true){
    ingreso_admin principal;
    menu_principal = principal.prin_menu();
    ingreso_admin ingreso;
    conf = false;
    while(menu_principal == 1){
        conf = ingreso.login();
        while (conf == false){
            cout<<"Usurio o contraseña erroneo, intente de nuevo."<<endl;
            conf = ingreso.login();
        }
        ingreso_admin menu2;
        dec = menu2.all_menu();
        if (dec == 1){
            dec = menu2.see_combos();
            ingreso_admin comprar;
            comprar.ejecutar_compra(dec, Data);
        }
        else if(dec == 2){
            ingreso_admin ac_admin;
            conf = false;
            while (conf == false){
            ingreso_admin ac_admin;
            conf=ac_admin.verificacion();

            if (conf==false)
                cout<<"usted no es el asministrador, intente de nuevo"<<endl;
            }
            while (true){
            dec = ac_admin.menu_admin();
            if (dec == 1){
                ingreso_admin desicion_admin;
                desicion_admin.comprar_ingred();
            }
            if (dec == 2){
                ingreso_admin ver_venta;
                ver_venta.registro_venta();
            }
            if (dec == 3){
                ingreso_admin ver_compra;
                ver_compra.registro_compra();
            }
            if( dec == 4)
                break;
            else
                cout<<"la opcion ("<<dec<<") no existe, intente de nuevo."<<endl;

        }
            if(dec == 4)
                break;
     }
    }
    if(menu_principal == 2){
        ingreso.registrar();
        }

    if (menu_principal == 3){
       break;
    }
    }

}

