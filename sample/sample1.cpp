#include <fstream>
#include <iostream>
#include "Set.h"
#include <set>
#include <vector>
#include <ctime>
#include <algorithm> 
#include <chrono>
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
	ofstream fout;
	int sumTime = 0;
	int flag;

	for (int i = size - 1; i >= 0; i--) {
		setAVL.insert(i * 3);
		setRB.insert(i * 3);
		vect.push_back(i * 3);
	}

	fout.open("PerformanceStat.txt",ios_base::app);

	fout << "Size: " << setAVL.size() << endl;
	fout << "Result search to AVL-tree :" << endl;
	
	for (int i = 1; i <= 10; i++)
	{
		auto begin = chrono::high_resolution_clock::now();
		
		setAVL.find((size / 100)*i);

		auto end = chrono::high_resolution_clock::now();
		fout << "Find " << i << " time = "<< chrono::duration_cast<chrono::microseconds>(end - begin).count() << "mc" << endl;
		sumTime += chrono::duration_cast<chrono::microseconds>(end - begin).count();
	}
	fout << "Avetage time = " << sumTime / 10 << endl << endl;

	sumTime = 0;

	fout << "Size: " << setAVL.size() << endl;
	fout << "Result search to RB-tree :" << endl;

	for (int i = 1; i <= 10; i++)
	{
		auto begin = chrono::high_resolution_clock::now();

		setRB.find((size / 100)*i);

		auto end = chrono::high_resolution_clock::now();
		fout << "Find " << i << " time = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "mc" << endl;
		sumTime += chrono::duration_cast<chrono::microseconds>(end - begin).count();
	}
	fout << "Avetage time = " << sumTime / 10 << endl << endl;

	sumTime = 0;

	sort(vect.begin(), vect.end());
	fout << "Size: " << setAVL.size() << endl;
	fout << "Result search to sort array :" << endl;

	for (int i = 1; i <= 10; i++)
	{
		auto begin = chrono::high_resolution_clock::now();

		Search_Binary(vect, 0, vect.size(), (size / 100)*i);

		auto end = chrono::high_resolution_clock::now();
		fout << "Find " << i << " time = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "mc" << endl;
		sumTime += chrono::duration_cast<chrono::microseconds>(end - begin).count();
	}
	fout << "Avetage time = " << sumTime / 10 << endl << endl;

	fout.close();
	return 0;
}