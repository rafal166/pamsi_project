
#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include  "List.h"
#include  "Stack.h"
#include  "Queue.h"
#include  "PriorityQueue.h"
#include  "Map.h"



using namespace std;

char mainMenu[100];
List<int> myList;
list<int> STLList;
Stack<int> myStack;
stack<int> STLStack;
Queue<int> myQueue;
queue<int> STLQueue;
PriorityQueue<int> priorityQueue;
priority_queue<int, std::vector<int>, std::greater<int>> STLPriorityQueue;
Map<string, string> myMap;

void displayStartMenu() {
	cout << "##########################" << endl;
	cout << "Menu: " << endl;
	cout << "1. Uruchom myListę" << endl;
	cout << "2. Uruchom stos" << endl;
	cout << "3. Uruchom kolejkę" << endl;
	cout << "4. Uruchom kolejkę priorytetową" << endl;
	cout << "5. Uruchom tablicę haszującą" << endl;
	cout << "q. Zamknij program" << endl;
	cin >> mainMenu;
	cout << "---------------------------------------" << endl;
}

int runList() {
	int tmpl, tmpl2;
	char menu[100];

	cout << "##########################" << endl;
	cout << "Menu listy: " << endl;
	cout << "1. Dodaj na końcu " << endl;
	cout << "2. Dodaj na początku " << endl;
	cout << "3. Dodaj na określonej pozycji: " << endl;
	cout << "4. Usuń element o indeksie: " << endl;
	cout << "5. Wyświetl wszystko" << endl;
	cout << "q. Zamknij program" << endl;
	cin >> menu;
	cout << "---------------------------------------" << endl;

	switch (menu[0]) {
		case '1':
			// push back
			cout << "Podaj liczbę: ";
			cin >> tmpl;
			myList.pushBack(tmpl);
			STLList.push_back(tmpl);
			break;
		case '2':
			// push front
			cout << "Podaj liczbę: ";
			cin >> tmpl;
			myList.pushFront(tmpl);
			STLList.push_front(tmpl);
			break;
		case '3':
			// insert
			cout << "Podaj pozycję na której chcesz dodać(STL doda na końcu): ";
			cin >> tmpl;
			cout << "Podaj liczbę: ";
			cin >> tmpl2;
			myList.insert(tmpl2, tmpl);
			STLList.insert(STLList.end(), tmpl);
			break;
		case '4':
			// remove
			cout << "Podaj element który chcesz usunąć: ";
			cin >> tmpl;
			myList.remove(tmpl);
			STLList.remove(tmpl);
			break;
		case '5':
			// print all
			cout << "Moja myLista" << endl;
			myList.printAllNodes();
			cout << "Lista STL" << endl;
			for (int n : STLList)
				std::cout << "STL: " << n << '\n';
			break;
		case 'q':
			return 0;
	}
	return 1;
}

int runStack() {
	int tmpl;
	char menu[100];

	cout << "##########################" << endl;
	cout << "Menu stosu: " << endl;
	cout << "1. Dodaj do stosu " << endl;
	cout << "2. Usuń ze stosu " << endl;
	cout << "3. Wyświetl wszystko" << endl;
	cout << "q. Zamknij program" << endl;
	cin >> menu;
	cout << "---------------------------------------" << endl;

	switch (menu[0]) {
		case '1':
			// push
			cout << "Podaj liczbę: ";
			cin >> tmpl;
			myStack.push(tmpl);
			STLStack.push(tmpl);
			break;
		case '2':
			// pop
			cout << "Usunięto element: " << myStack.pop() << endl;
			cout << "Usunięto element STL: " << STLStack.top() << endl;
			STLStack.pop();
			break;
		case '3':
			// print all
			myStack.printAllNodes();
			cout << "STL Stack: " << endl;
			tmpl = STLStack.size();
			while (tmpl) {
				cout << "STL: " << STLStack.top() << endl;
				tmpl--;
			}
			break;
		case 'q':
			return 0;
	}
	return 1;
}

int runQueue() {
	int tmpl;
	char menu[100];

	cout << "##########################" << endl;
	cout << "Menu kolejki: " << endl;
	cout << "1. Dodaj do kolejki " << endl;
	cout << "2. Usuń z kolejki " << endl;
	cout << "3. Wyświetl wszystko (Żeby wyświetlić, kolejksa z STL zostanie opróżniona, moja nie!)" << endl;
	cout << "q. Zamknij program" << endl;
	cin >> menu;
	cout << "---------------------------------------" << endl;

	switch (menu[0]) {
		case '1':
			// enqueue
			cout << "Podaj liczbę: ";
			cin >> tmpl;
			myQueue.enqueue(tmpl);
			STLQueue.push(tmpl);
			break;
		case '2':
			// dequeue
			cout << "Element z kolejki: " << myQueue.dequeue() << endl;
			cout << "Element z kolejki STL: " << STLQueue.front() << endl;
			STLQueue.pop();
			break;
		case '3':
			// print all
			myQueue.printAllNodes();
			cout << "STL Queue: " << endl;
			tmpl = STLQueue.size();
			while (tmpl) {
				cout << "STL: " << STLQueue.front() << endl;
				STLQueue.pop();
				tmpl--;
			}
			break;
		case 'q':
			return 0;
	}
	return 1;
}

int runPriorityQueue() {
	int tmpl, tmpl2;
	char menu[100];

	cout << "##########################" << endl;
	cout << "Menu kolejki: " << endl;
	cout << "1. Dodaj do kolejki " << endl;
	cout << "2. Usuń z kolejki " << endl;
	cout << "3. Wyświetl wszystko" << endl;
	cout << "q. Zamknij program" << endl;
	cin >> menu;
	cout << "---------------------------------------" << endl;

	switch (menu[0]) {
		case '1':
			// enmyQueue
			cout << "Podaj liczbę: ";
			cin >> tmpl;
			cout << "Podaj priorytet (1 - najwyższy, 2 - niższy, 3 - jeszcze niższy): ";
			cin >> tmpl2;
			priorityQueue.enqueue(tmpl, tmpl2);
			STLPriorityQueue.push(tmpl);
			break;
		case '2':
			// demyQueue
			cout << "Element z kolejki: " << priorityQueue.dequeue() << endl;
			cout << "Element z kolejki STL: " << STLPriorityQueue.top() << endl;
			STLPriorityQueue.pop();
			break;
		case '3':
			// print all
			priorityQueue.printAllNodes();
			cout << "STL Queue: " << endl;
			tmpl = STLPriorityQueue.size();
			while (tmpl) {
				cout << "STL: " << STLPriorityQueue.top() << endl;
				STLPriorityQueue.pop();
				tmpl--;
			}
			break;
		case 'q':
			return 0;
	}
	return 1;
}

int runMap() {
	string tmpl, tmpl2;
	char menu[100];

	cout << "##########################" << endl;
	cout << "Menu tablicy haszującej: " << endl;
	cout << "1. Dodaj do tablicy " << endl;
	cout << "2. Pobierz z tablicy" << endl;
	cout << "3. Usuń z tablicy" << endl;
	cout << "4. Wyświetl wszystko" << endl;
	cout << "q. Zamknij program" << endl;
	cin >> menu;
	cout << "---------------------------------------" << endl;

	switch (menu[0]) {
		case '1':
			// insert
			cout << "Podaj klucz (string): ";
			cin >> tmpl;
			cout << "Podaj wartość (string): ";
			cin >> tmpl2;
			myMap.insert(tmpl, tmpl2);
			break;
		case '2':
			// get
			cout << "Podaj klucz (string): ";
			cin >> tmpl;
			cout << "Pobrany element: " << myMap(tmpl) << endl;
			break;
		case '3':
			// remove
			cout << "Podaj klucz do usunięcia (string): ";
			cin >> tmpl;
			myMap.remove(tmpl);
			break;
		case '4':
			// print
			myMap.printAll();
			break;
		case 'q':
			return 0;
	}
	return 1;
}

int main() {
	int status = 1;
	displayStartMenu();
	while (status) {
		switch (mainMenu[0]) {
			case '1':
				status = runList();
				break;
			case '2':
				status = runStack();
				break;
			case '3':
				status = runQueue();
				break;
			case '4':
				status = runPriorityQueue();
				break;
			case '5':
				status = runMap();
				break;
			case 'q':
			default:
				return 0;
		}
	}
	return 0;
}

