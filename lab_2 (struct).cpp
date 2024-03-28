#include <iostream>
#include <fstream>
#include "Source.h"
#include "Person.h"
using namespace std;

int main()
{
    Person* List, ** Plist;
    ofstream output("output.txt");
    int n;
    cout << "введите количество участников\n";
    cin >> n;
    cout << endl;
    //выделение памяти
    Plist = new Person * [n];
    List = new Person[n];
    //заполнение данных
    for (int i = 0; i < n; List[i] = Person(rand() % 26, rand() % 6, 60 + rand() % 241, rand() % 21), i++);
    for (int i = 0; i < n; Plist[i] = &List[i], i++);
    //сортировка
    IndirectSortClass<Person>::Sort_Shell(Plist, n);
    //вывод в файл и консоль
    for (int i = 0; i < n; i++) output << Plist[i]->GetPoints() << "\t" << Plist[i]->GetSolved() << "\t" << Plist[i]->GetTime() << "\t" << Plist[i]->GetTries() << "\t" << Plist[i]->GetId() << endl;
    for (int i = 0; i < n; i++) cout << List[i].GetPoints() << "\t" << List[i].GetSolved() << "\t" << List[i].GetTime() << "\t" << List[i].GetTries() << "\t" << List[i].GetId() << endl;
}
 