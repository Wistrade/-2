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
            cout << "Завершение работы.";
            return 0;
        }
        case 1:
        {
            int n;
            cout << "Введите длину массива: ";
            cin >> n;

            A.update(n);

            cout << endl << "Введите элементы через пробел или Enter: ";

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

            cout << "Среднее значение элементов массива: " << xResult << endl << "Среднеквадратическое отклонение элементов массива: " << skoResult << endl;
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
            cout << "Введите новую длину массива: ";
            cin >> newN;

            A.copy(newN, A);
            cout << A << endl;
            break;
        }
        case 6:
        {
            int i;
            cout << "Выберите номер элемента, которые требуется изменить: ";
            cin >> i;
            number X;
            cout << "Выберите новое значение для элемента: ";
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
    cout << endl << "1 - создание массив с N элементами и его заполнение" << endl;
    cout << "2 - расчет среднее значение элементов и СКО элементов" << endl;
    cout << "3 - сортировка по возрастанию" << endl;
    cout << "4 - сортировка по убыванию" << endl;
    cout << "5 - изменение размера массива" << endl;
    cout << "6 - изменение элемента массива" << endl;
    cout << "7 - вывод массива" << endl;
    cout << "0 - exit" << endl << "> ";
    cin >> ch;
    cout << endl;
    return ch;
}