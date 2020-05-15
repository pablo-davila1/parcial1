#ifndef INGRESO_ADMIN_H
#define INGRESO_ADMIN_H
#include <map>
#include <string>
#include <vector>
using namespace std;

class ingreso_admin
{
    int a;
    map<string, vector<int>>data;
public:
    ingreso_admin();
    bool verificacion();
    void registrar();
    int all_menu();
    int prin_menu();
    bool login();
    int see_combos();
    map<string,vector<int>> cargar_data();
    int menu_admin();
    void comprar_ingred();
    void registro_venta();
    void registro_compra();

    int getA() const;
    void setA(int value);

    map<string, vector<int> > getData() const;
    void setData(const map<string, vector<int> > &value);

    void ejecutar_compra (int a, map<string, vector<int>>data);
};







































#endif // INGRESO_ADMIN_H
