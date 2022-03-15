#include <iostream>
using namespace std;
#include "Poly.h"
#include <fstream>
#include <string> 

int main()
{
    int size = 0;
    char name[20];
    cout << "\n--------< Enter the name of file like: input_poly.txt: ";
    cin >> name;
    ifstream cheack(name, ios::in);
    if (!cheack.is_open())
    {
        cout << "\nCant open file !!\n";
        cout << "\nRenter name of file: ";
        cheack.close();
        cin >> name;
    }
    ifstream file(name, ios::in);
    if (!file.is_open()) { cout << "\nwrong input !!\n"; exit(1); }
    int dum;
    while (file) { file >> dum; size++; }
    size /= 2;

    file.clear();
    file.seekg(0, ios::beg);

    int* arr_c = new int[size];
    int* arr_p = new int[size];
    for (int i = 0; i < size; i++)
    {
        file >> arr_c[i];
    }
    for (int i = 0; i < size; i++)
    {
        file >> arr_p[i];
    }
    file.close();
    Poly o(arr_c,arr_p,size);
    char menu = 'a';
    cout << "\n--------------------------------------------------< welcom >----------------------------------\n";
    while (menu!='7')
    {
        cout << "\n<1> To print poly Enter 1";
        cout << "\n<2> To insert a node to the linked list Enter 2";
        cout << "\n<3> To delete noded based on the power Enter 3";
        cout << "\n<4> To evaluation the polynomial Enter 4";
        cout << "\n<5> To get the degree of the function Enter 5";
        cout << "\n<6> To add new Poly and do sum operation on it Enter 6";
        cout << "\n<6> To exit Enter 7";
        cout << "\n---------------------------------------------";
        cout << "\nEnter your option: ";
        cin >> menu;
        int c = 0;
        int p = 0;
        if (menu == '1')
        {
            cout <<"\n"<<o ;
        }
        else if (menu == '2')
        {
            cout << "\nEnter the coefficient number: ";
            cin >> c;
            if (c == 0)
            {
                cout << "\nwrong input !!\n";
                cout << "\nRenter the coefficient number: ";
                cin >> c;
            }
            cout << "\nEnter the powre number: ";
            cin >> p;
            if (p <0)
            {
                cout << "\nwrong input: negative number !!\n";
                cout << "\nRenter the power number: ";
                cin >> c;
            }
            if (c != 0 && p >= 0)
            {
                o.insert_Node(c, p);
                cout << "\nadd sucsesful $ \n";
            }
            else
            {
                cout << "\nit is not add\n";
            }
        }
        else if (menu == '3')
        {
            cout << "\nEnter power number: ";
            cin >> p;
            int i = 0;
            for(i=0;i<size;i++)
            {
                if (arr_p[i] == p)
                {
                    o.delete_Node(p);
                    cout << "\ndelete sucsesful $\n";
                    break;
                }
            }
            if (i== (size+1))
            {
                cout << "\nit does not delete !! this power is not in function\n";
            }
        }
        else if (menu == '4')
        {
            double x;
            cout << "\nEnter the value: ";
            cin >> x;
            cout << "\nThe result of evaluation is: " << o.Eval_poly(x) << endl;
        }
        else if (menu == '5')
        {
            cout << "\nThe degree is: ";
            int d = degree(o);
            
            if (d>-1)
            {
                cout << d<<"\n";
            }
            else
            {
                cout << "\nEmpty Poly\n";
            }
        }
        else if (menu == '6')
        { 
            Poly new_p;
            Poly pl;
            int m = 0;
            while (m!=8)
            {
                cout << "\n             :(*****************************************):";
                cout << "\n               * <1> To print Exist poly Enter 1";
                cout << "\n               * <2> To print the newest poly Enter 2";
                cout << "\n               * <3> To add new nodes (poly) Enter 3";
                cout << "\n               * <4> To merge the new poly Enter 4";
                cout << "\n               * <5> To add the newest and exist Poly into a new Poly Enter 5";
                cout << "\n               * <6> To print the poly you add it togather Enter 6";
                cout << "\n               * <7> To delete the new poly Enter 7";
                cout << "\n               * <8> To Exit Enter 8";
                cout << "\n-------------------------------------------------------------\n";
                cout << "Enter your option: ";
                cin >> m;
                int count = 0;
                if (m >= 1 && m <= 8)
                {
                    if (m == 1)
                    {
                        cout << endl << o;
                    }
                    if (m == 2)
                    {
                        cout << endl << pl;
                    }
                    if (m == 3)
                    {
                        cin >> pl;
                    }
                    if (m == 4)
                    {
                        o.merge(pl);
                        cout << "\nDone succesful $$\n";
                    }
                    if (m == 5)
                    {
                        new_p = o + pl;
                        cout << "\nDone succesful $$\n";
                    }
                    if (m == 6)
                    {
                        cout << new_p;
                    }
                    if (m == 7)
                    {
                        pl.del();
                        cout << "\nDone succesful $$\n";
                    }
                }
                else {
                    cout << "\nwrong input !!";
                }
            }
        }
    }
    cout << "\n------------------------------------------<> good bay <>--------------------------------------------\n\n";
    o.del();
    system("pause");
    
}