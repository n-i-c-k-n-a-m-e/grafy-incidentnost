#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int dugi,top;

	cout << "dugi" << endl;
	cin >> dugi;
	cout << "vershini" << endl;
	cin >> top;

	int arr[top][dugi];	

	for (int i = 0; i < top; i++)
	{
		for (int j = 0; j < dugi; j++)
		{
			cin >> arr[i][j];
		}
	}

	char duga = 'a';
	cout << "\t";
	for (int i = 0; i < dugi; i++)
	{
		cout << duga++ << "\t";
	}
	cout << endl;
	for (int i = 0; i < top; i++) {
		cout << i+1 << "\t";
        for (int j = 0; j < dugi; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    // СЧИТАЕМ СТЕПЕНИ ВЕРШИН
    int ub[top][2] = { {0}, {0} };
    for (int i = 0; i < top; i++)
    {
    	ub[i][0] = i+1;
    }

    for (int i = 0; i < top; i++)
    {
    	for (int j = 0; j < dugi; j++)
    	{
    		if (arr[i][j])
    		{
    			ub[i][1]++;
    		}
    	}
    }
    //

    // ВЫВОДИМ ИХ
    cout << "\nDEGREES\n";
    for (int i = 0; i < top; i++)
    {
    	cout << ub[i][0] << ":\t" << ub[i][1] << endl; // 
    }
    //

    // SORT
    for (int i = 0; i < top; i++)
    {
    	for (int j = 0; j < top; j++)
    	{
    		if (ub[i][1] > ub[j][1])
    		{
    			int tmp = ub[j][1];
    			ub[j][1] = ub[i][1];
    			ub[i][1] = tmp;

    			tmp = ub[j][0];
    			ub[j][0] = ub[i][0];
    			ub[i][0] = tmp;
    		}
    	}
    }
    //

    // ВЫВОДИМ ИХ
    cout << endl << "SORTED:" << endl;
    for (int i = 0; i < top; i++)
    {
    	cout << ub[i][0]  << ":\t" << ub[i][1] << endl; // 
    }
    //

    int colour = 1;
    int cur_top = 0; // ТЕКУЩАЯ ВЕРШИНА
    for (int i = 0; i < top; i++)
    {
    	ub[i][1] = 0; // ЗАНУЛЯЕМ ВСЕ ЦВЕТА
    }

    for (int i = 0; i < top; i++)
    {
    	if (ub[i][1]) // ЕСЛИ ЦВЕТ ЕСТЬ, ТО ПРОПУСКАЕМ
    	{
    		continue;
    	}

		cur_top = ub[i][0]; // ТЕКУЩАЯ ВЕРШИНА
    	ub[i][1] = colour; // СТАВИМ ЦВЕТ ВЕРШИНЕ
    	cout << "CUR TOP: " << cur_top << "\tCUR COLOUR: " << colour << endl;

    	int or_operand[top] = {0}; // МАССИВ ДЛЯ ПОРАЗРЯДНОГО "ИЛИ"

    	for (int j = 0; j < dugi; j++)
    	{
    		if (arr[cur_top - 1][j])
    		{
    			cout << "arr[" << i << "," << j << "]\t" << "DUGA " << j << ":\t\t";
    			for (int k = 0; k < top; k++)
    			{
    				or_operand[k] |= arr[k][j]; // ПОРАЗРЯДНОЕ ИЛИ
    			
    				cout << or_operand[k];
    			}

    			cout << endl;
    		}
    	}

    	for (int j = 0; j < top; j++)
    	{
    		if (!or_operand[j]) 
    		{
    			for (int k = 0; k < top; k++)
    			{
    				if (ub[k][0] == j + 1)
    				{
						ub[k][1] = colour; // ПРИСВАЕВАЕМ ЦВЕТ
						break;
					}
    			}
    		}
    	}

    	colour++;
    }

    // ВЫВОДИМ ИХ
    cout << endl << "COLOURS:" << endl;
    for (int i = 0; i < top; i++)
    {
    	cout << ub[i][0]  << ":\t" << ub[i][1] << endl; // 
    }
    //

	return 0;
}