#include <Windows.h>
#include <iostream>
using namespace std;
const int N = 4; //розмір черги
struct Queue
{
	int data[N]; //масив даних
	int last; //покажчик на початок
};
void Creation(Queue* Q) //створення черги
{
	Q->last = 0;
}
bool Full(Queue* Q) //перевірка черги на порожнечу
{
	if (Q->last == 0) return true;
	else return false;
}
void Add(Queue* Q) //додавання елемента
{
	if (Q->last == N)
	{
		cout << "\nЧерга заповнена\n\n"; return;
	}
	int value;
	cout << "\nЗначення > "; cin >> value;
	Q->data[Q->last++] = value;
	cout << endl << "Елемент доданий до черги\n\n";
}
void Delete(Queue* Q) //видалення елемента
{
	for (int i = 0; i < Q->last && i < N; i++) //зміщення елементів
		Q->data[i] = Q->data[i + 1]; Q->last--;
}
int Top(Queue* Q) //виведення початкового елемента
{
	return Q->data[0];
}
int Size(Queue* Q) //розмір черги
{
	return Q->last;
}
void main() //головна функція
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Queue Q;
	Creation(&Q);
	char number;
	do
	{
		cout << "1. Додати елемент" << endl;
		cout << "2. Видалити елемент" << endl;
		cout << "3. Вивести верхній елемент" << endl;
		cout << "4. Дізнатись розмір черги" << endl;
		cout << "0. Вийти\n\n";
		cout << "Номер команди > "; cin >> number;
		switch (number)
		{
		case '1': Add(&Q);
			break;
			//-----------------------------------------------
		case '2':
			if (Full(&Q)) cout << endl << "Черга порожня\n\n";
			else
			{
				Delete(&Q);
				cout << endl << "Елемент видалено із черги\n\n";
			} break;
			//-----------------------------------------------
		case '3':
			if (Full(&Q)) cout << endl << "Черга порожня\n\n";
			else cout << "\nПочатковий елемент: " << Top(&Q) << "\n\n";
			break;
			//-----------------------------------------------
		case '4':
			if (Full(&Q)) cout << endl << "Черга порожня\n\n";
			else cout << "\nРозмір черги: " << Size(&Q) << "\n\n";
			break;
			//-----------------------------------------------
		case '0': break;
		default: cout << endl << "Команда не визначена\n\n";
			break;
		}
	} while (number != '0');
	system("pause");
}