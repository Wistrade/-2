#include "application.h"
#include <iostream>
#include "number.h"
#include "array.h"


using namespace std;
Application::Application()
{

}

int Application::exec()
{
    int ch;
    Array A(5);

    setlocale(LC_ALL, "Russian");

    while (true)
    {
        ch = menu();
        switch (ch)
        {
        case 0:
        {
            cout << "���������� ������.";
            return 0;
        }
        case 1:
        {
            int n;
            cout << "������� ����� �������: ";
            cin >> n;

            A.update(n);

            cout << endl << "������� �������� ����� ������ ��� Enter: ";

            for (int i = 0; i < n; i++)
            {
                number val;
                cin >> val;
                A.set(i, val);
            }

            cout << endl << A;
            break;
        }
        case 2:
        {
            number xResult;
            number skoResult;
            xResult = A.middle();
            skoResult = A.sko();

            cout << "������� �������� ��������� �������: " << xResult << endl << "�������������������� ���������� ��������� �������: " << skoResult << endl;
            break;
        }
        case 3:
        {
            A.sortIncreas();
            cout << A << endl;
            break;
        }
        case 4:
        {
            A.sortDecreas();
            cout << A << endl;
            break;
        }
        case 5:
        {
            int newN;
            cout << "������� ����� ����� �������: ";
            cin >> newN;

            A.copy(newN, A);
            cout << A << endl;
            break;
        }
        case 6:
        {
            int i;
            cout << "�������� ����� ��������, ������� ��������� ��������: ";
            cin >> i;
            number X;
            cout << "�������� ����� �������� ��� ��������: ";
            cin >> X;
            A.changeElement(i, X);
            cout << A << endl;
            break;
        }
        case 7:
        {
            cout << A;
            break;

        }
        }
    }
}

int Application::menu()
{
    int ch;
    cout << endl << "1 - �������� ������ � N ���������� � ��� ����������" << endl;
    cout << "2 - ������ ������� �������� ��������� � ��� ���������" << endl;
    cout << "3 - ���������� �� �����������" << endl;
    cout << "4 - ���������� �� ��������" << endl;
    cout << "5 - ��������� ������� �������" << endl;
    cout << "6 - ��������� �������� �������" << endl;
    cout << "7 - ����� �������" << endl;
    cout << "0 - exit" << endl << "> ";
    cin >> ch;
    cout << endl;
    return ch;
}