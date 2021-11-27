#include <iostream>
#include "conio.h"
#include "locale.h"
 
using namespace std;
 
int main()
{
    int n, m, x, y, a[80][80];
    setlocale(LC_ALL, "rus");
    cout << "Введите количество вершин: ";
    cin >> n;
    cout << "Введите количество рёбер: ";
    cin>> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
        cout << endl;
    cout << "Введите рёбра: " << endl;
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    cout << endl;
    cout << "Матрица смежности: " << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}