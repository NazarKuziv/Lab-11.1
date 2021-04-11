// Lab_11_1.cpp
// < Кузів Назар >
// Лабораторна робота № 11.1
// Бінарні файли
// Варіант 6

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void CreateBIN(char* fname) 
{
    ofstream f(fname, ios::binary);
    if (f.fail())
    {
        cerr << "Помилка при відкритті файлу " << endl;
        exit(1);
    }
   
    char ch; 
    double x; 
    do
    { 
        cout << "enter number: "; cin >> x;  
        f.write((char*)&x, sizeof(x));
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
    
}

void PrintBIN(char* name)
{
    ifstream f(name, ios::binary);

    if (f.fail())
    {
        cerr << "Помилка при відкритті файлу " << endl;
        exit(1);
    }
    double x;

    while (f.read((char*)&x, sizeof(x)))
        cout << x << endl;
    cout << endl;
}
 


void ProcessBIN(char* fname, char* gname) 
{ 
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);

    double x;

    while (f.read((char*)&x, sizeof(x)))
        if (x < -1 || x >1 )
            g.write((char*)&x, sizeof(x));
}

int main()
{
    char fname[100]; 
    cout << "enter file name 1: "; cin >> fname;

    CreateBIN(fname);
    PrintBIN(fname);

    char gname[100]; 
    cout << "enter file name 2: "; cin >> gname;

    ProcessBIN(fname, gname);
    PrintBIN(gname);

    return 0;
}

