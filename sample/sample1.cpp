#include <fstream>
#include <iostream>
#include "Set.h"
#include <set>
#include <vector>
#include <ctime>
#include <algorithm> 
#include <omp.h>
#include <Windows.h>
using namespace std;

int main(int argc, char** argv) {
	Set setAVL;
	set <float> setRB;
	vector<float> vect;
	int size = atoi(argv[1]);
	ofstream fout;
	int flag;
	double insertAVLbegin = omp_get_wtime();
	for (int i = size - 1; i >= 0; i--) {
		setAVL.insert(i * 3);
	}
	double insertAVLend = omp_get_wtime();
	cout << insertAVLend - insertAVLbegin << endl;

	double insertRBbegin = omp_get_wtime();
	for (int i = size - 1; i >= 0; i--) {
		setRB.insert(i * 3);
	}
	double insertRBend = omp_get_wtime();
	cout << insertRBend - insertRBbegin << endl;

	double insertVecbegin = omp_get_wtime();
	for (int i = size - 1; i >= 0; i--) {
		vect.push_back(i * 3);
	}
	double insertVecEnd = omp_get_wtime();
	cout << insertVecEnd - insertVecbegin << endl;


	fout.open("PerformanceStat.txt",ios_base::app);

	fout << "Size: " << setAVL.size() << endl;
	fout << "Result search to AVL-tree :" << endl;
	cout << boolalpha;
	double begin = omp_get_wtime();
	int result;
	for (int i = 0; i <= (size); i++)
	{
		result = setAVL.find((size / 100)*i);
	}
	double end = omp_get_wtime();
	fout << "Avetage time = " << end - begin << endl << endl;

	
	
	
	
	
	fout << "Size: " << setAVL.size() << endl;
	fout << "Result search to RB-tree :" << endl;

	cout << boolalpha;
	double beginRB = omp_get_wtime();
	for (int i = 0; i <= (size); i++)
	{
		result = *setRB.find((float)(size / 100)*i);
	}
	double endRB = omp_get_wtime();
	fout << "Avetage time = " << endRB - beginRB << endl << endl;

	
	
	
	
	
	sort(vect.begin(), vect.end());
	fout << "Size: " << setAVL.size() << endl;
	fout << "Result search to sort array :" << endl;

	cout << boolalpha;
	double beginBin = omp_get_wtime();
	bool resultvec;
	for (int i = 0; i <= (size); i++)
	{
		resultvec = binary_search(vect.begin(), vect.end(), (size / 100)*i);
	}
	double endBin = omp_get_wtime();
	fout << "Avetage time = " << endBin - beginBin << endl << endl;

	fout.close();
	return 0;
}