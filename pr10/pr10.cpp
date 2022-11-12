
#include <iostream>
#include "graph.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Практическая работа №6 \"Основные алгоритмы работы с графами.\". Резников Григорий." << endl << endl;
    cout << " (1):построение графа по вводу с  клавиатуры \n" <<
        " (2): добавление ребра в граф\n" <<
        " (3): вывод графа\n" <<
        " (4): поиск и вывод циклов Гамельтона\n" <<
        " (5): нахождение кратчайшего пути от одной вершины к другой методом “Дейкстры”. \n" <<
        endl;
    graph* aaaaa = nullptr;list<int> pa;
    int num = 0 , a, b, c;
    aaaaa = new graph(8);

    aaaaa->add_edge(1, 2, 23);
    aaaaa->add_edge(2, 1, 23);
    aaaaa->add_edge(1, 3, 12);
    aaaaa->add_edge(3, 1, 12);
    aaaaa->add_edge(2, 3, 25);
    aaaaa->add_edge(2, 5, 22);
    aaaaa->add_edge(2, 8, 35);
    aaaaa->add_edge(3, 2, 25);
    aaaaa->add_edge(3, 4, 18);
    aaaaa->add_edge(4, 3, 18);
    aaaaa->add_edge(4, 6, 20);
    aaaaa->add_edge(5, 6, 23);
    aaaaa->add_edge(5, 7, 14);
    aaaaa->add_edge(5, 2, 22);
    aaaaa->add_edge(6, 4, 20);
    aaaaa->add_edge(6, 5, 23);
    aaaaa->add_edge(6, 7, 24);
    aaaaa->add_edge(7, 6, 24);
    aaaaa->add_edge(7, 8, 16);
    aaaaa->add_edge(7, 5, 14);
    aaaaa->add_edge(8, 7, 16);
    aaaaa->add_edge(8, 2, 35);
    for(;;)
    {
        cout << "Enter num of operatoin" << endl;
        cin >> num;
	    switch (num)
	    {
	    case 1:
            aaaaa = new graph(0);
            aaaaa->construct();
            break;
	    case 2:
            cout << "Enter source, destionation and weight";
            cin >> a >> b >> c;
            aaaaa->add_edge(a, b, c);
            break;
	    case 3:
            aaaaa->print();
            break;
	    case 4:
            cout << "Enter starting point";
            cin >> a;
            aaaaa->get_gamilton_path(pa, a - 1, a - 1);
            pa.clear();
            break;
	    case 5:
            pa.clear();
            cout << "Enter stanting and final poins" << endl;
            pa = aaaaa->dijkstra(a, b);
            cout << "Path lenght: " << pa.front()<<endl;
            pa.pop_front();
            for (auto value : pa)
            {
                cout << " " << value;
            }
            cout << endl;
	    default:
                
            break;
	    }
    }
    //graph g(6);
    //g.add_edge(0, 5, 4);
    //g.add_edge(0, 1, 7);
    //g.add_edge(0, 3, 2);

    //g.add_edge(1, 0, 7);
    //g.add_edge(1, 3, 2);
    //g.add_edge(1, 2, 1);

    //g.add_edge(2, 1, 1);
    //g.add_edge(2, 3, 2);
    //g.add_edge(2, 4, 3);

    //g.add_edge(3, 0, 2);
    //g.add_edge(3, 1, 2);
    //g.add_edge(3, 2, 2);
    //g.add_edge(3, 4, 6);
    //g.add_edge(3, 5, 1);

    //g.add_edge(4, 2, 3);
    //g.add_edge(4, 3, 6);
    //g.add_edge(4, 5, 8);

    //g.add_edge(5, 0, 4);
    //g.add_edge(5, 3, 1);
    //g.add_edge(5, 4, 4);

    //list<int> pa;
    //pa = g.dijkstra(0, 4);
    //cout << pa.front()<<endl;
    //pa.pop_front();
    //for (auto value : pa)
    //{
    //    cout << value << " ";
    //}
}

