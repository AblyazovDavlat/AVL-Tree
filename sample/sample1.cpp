#include <iostream>
#include "Set.h"
#include <set>
#include <vector>
#include <ctime>
#include <algorithm> 
using namespace std;

bool Search_Binary(vector<float> vect, int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < vect[midd])       // если искомое меньше значени€ в €чейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > vect[midd])  // если искомое больше значени€ в €чейке
			left = midd + 1;	   // смещаем левую границу поиска
		else                       // иначе (значени€ равны)
			return true;           // функци€ возвращает индекс €чейки

		if (left > right)          // если границы сомкнулись 
			return false;
	}
}

int main(int argc, char** argv) {
	Set setAVL;
	set <float> setRB;
	vector<float> vect;
	int size = atoi(argv[1]);

	/*time_t start, end;
	double time;
	bool flag;*/

	for (int i = size - 1; i >= 0; i--) {
		setAVL.insert(i * 3);
		setRB.insert(i * 3);
		vect.push_back(i * 3);
	}


	cout << "Size: " << setAVL.size() << endl;
	cout << boolalpha;

	cout << "Result search to AVL-tree :" << endl;
	for (int i = 1; i <= 10; i++)
	{
		/*ctime(&start);
		flag = (bool)setAVL.find((size / 100)*i);
		ctime(&end);
		time = difftime(end, start) * 1000.0;
		cout << "Searching element: " << (size / 100)*i << ' ' << "Time for find : " << time << endl;*/
		cout << "Searching element: " << (size / 100)*i << ' ' << (bool)setAVL.find((size / 100)*i) << endl;
	}


	cout << "Result search to RB-tree :" << endl;
	cout << boolalpha;
	

	for (int i = 1; i <= 10; i++)
	{
		cout <<"Searching element: "<< (size / 100)*i << ' ' << (bool)*setRB.find((size / 100)*i) << endl;
	}

	sort(vect.begin(), vect.end());
	cout << "Result binary search to vector:" << endl;
	cout << boolalpha;

	for (int i = 1; i <= 10; i++)
	{
		cout << "Searching element: " << (size / 100)*i << ' ' << (bool)Search_Binary(vect, 0, vect.size(), (size / 100)*i) << endl;
	}

	return 0;
}