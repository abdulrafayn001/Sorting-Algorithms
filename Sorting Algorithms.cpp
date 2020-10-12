#include<iostream>
#include<list>
#include<vector>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;

void CreateFile(string FileName, int MB)
{
	unsigned long j;
	srand((unsigned)time(NULL));
	ofstream fout;
	fout.open(FileName);
	for (int j = 0; j < 1024 * MB; ++j)
	{
		fout << rand() % 1000 << " ";
	}
}
void ReadData();
void MENUE();
template<typename T>
ostream& operator<<(ostream&, vector<T>&V)
{
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}
	return cout << endl;
}
//Q1 BubbleSort Vector using Bubbling function
bool VectorBubbleUp(vector<int> &V);
void VectorBubbleSort(vector<int> &V);
//Q1 BubbleSort Vector using Nested loop
void VectorBubbleSortNL(vector<int> &V);
//Q1 BubbleSort Vector Using do while and a nested loop
void VectorBubbleSortDW(vector<int> &V);

//Q1 BubbleSort List (pointer swap)
template<typename T>
ostream& operator<<(ostream&, list<T> &li)
{
	for (auto x = li.begin(); x != li.end(); x++)
	{
		cout << *x << "=>";
	}
	return cout << "X" << endl;
}
bool ListBubbleUpPS(list<int> &li);
void ListBubbleSortPS(list<int> &li);

//Q1 BubbleSort List (data swap)
bool ListBubbleUpDS(list<int> &li);
void ListBubbleSortDS(list<int> &li);

//Q2 Vector Merge function
vector<int> VectorMerge(vector<int> &A, vector<int> &B);
//Q2 List Merge function
list<int> ListMerge(list<int> &A, list<int> &B);

//Q3 Vector Merge Sort
void VectorMergeSort(vector<int> &L);
//Q3 List Merge Sort
void ListMergeSort(list<int> &L);

//Q4 Vector Selection Sort
void VectorSelectionSort(vector<int> &V);
//Q4 List Selection Sort
void ListSelectionSort(list<int> &L);

//Q5  Vector Insertion Sort
void VectorInsertionSort(vector<int> &V);
//Q5 List Insertion Sort
void ListInsertionSort(list<int> &L);
//Q6 Bucket Sort
void BucketSort(list<int> &L);
int main()
{
	/*vector<int> Vs{ 1, 3, 5, 7, 9, 0, 8, 6, 4, 2 };
	cout << Vs.size() << endl;
	cout << Vs;
	VectorInsertionSort(Vs);
	cout << Vs;*/

	CreateFile("Data.txt", 1);
	list<int> Ls;
	Ls.push_back(11);
	Ls.push_back(78);
	Ls.push_back(12);
	Ls.push_back(23);
	Ls.push_back(90);
	Ls.push_back(11);
	Ls.push_back(3);
	Ls.push_back(21);
	Ls.push_back(91);
	Ls.push_back(2);
	cout << Ls;
	//ListSelectionSort(Ls);
	//ListBubbleSortPS(Ls);
	//ListMergeSort(Ls);
	//ListInsertionSort(Ls);
	BucketSort(Ls);
	cout << Ls;

	//vector<int>V1{ 0, 1, 3, 5, 7, 9 };
	//vector<int>V2{ 2, 4, 6, 8, 10, 12, 13, 14, 15 };
	////cout << VectorMerge(V1, V2);
	//cout << Vs;
	////VectorMergeSort(Vs);
	//cout << Vs;
	return 0;
}

//Q1 BubbleSort Vector
//Q1 BubbleSort Vector using Bubbling function
bool VectorBubbling(vector<int> &V,int &size)
{
	bool swapped = { false };
	for (int i = 0; i<V.size() - 1; i++) //+1+1+1 + 1 + 1 + ...+1 O(N)
	{
		if (V[i]>V[i + 1])
		{
			swap(V[i], V[i + 1]);
			swapped = { true };
		}
	}
	size--;
	return swapped;
}
void VectorBubbleSort(vector<int> &V)
{
	int size = V.size() - 1;
	bool swapped = { false };
	do
	{
		swapped = VectorBubbling(V, size);
	} while (swapped); //In worst case O(N)
	//Over all complexity = O(N^2)
}
//Q1 BubbleSort Vector using Nested loop
void VectorBubbleSortNL(vector<int> &V)
{
	int i, j;
	for (i = 0; i < V.size(); i++) //1+1+1+1+..+1 =O(N)
	{
		for (j = 0; j < V.size(); j++)//1+1+1+1+..+1 =O(N)
		{
			if (V[j] > V[j + 1])
			{
				swap(V[j], V[j + 1]);
			}
		}
	}
	//O(N) * O(N2) = O(N^2)
}
//Q1 BubbleSort Vector Using do while and a nested loop
void VectorBubbleSortDW(vector<int> &V)
{
	bool swapped;
	do {
		int j = 0;
		swapped = false;
		while (j<V.size() - 1) //1+1+1+1+..+1 =O(N)
		{
			if (V[j]>V[j + 1])
			{
				swap(V[j], V[j + 1]);
				swapped = true;
			}
			j++;
		}
	} while (swapped);//1+1+1+1+..+1 =O(N)
	//O(N) * O(N) = O(N^2);
}


//Q1 BubbleSort List (pointer swap)
bool ListBubbleUpPS(list<int> &li)
{
	bool swapped = { false };
	auto prev = li.begin(), next = li.begin(); next++; //1+1+1+1+..+1 =O(N)
	while (next != li.end())
	{
		if (*prev > *next)
		{
			iter_swap(prev, next);
			swapped = true;
		}
		next++;
		prev++;
	}
	return swapped;
}
void ListBubbleSortPS(list<int> &li)
{
	bool swapped = { false };
	do
	{
		swapped = ListBubbleUpPS(li);
	} while (swapped); //In worst case O(N)
	//Over all complexity = O(N^2)
}


//Q1 BubbleSort List (data swap)
bool ListBubbleUpDS(list<int> &li)
{
	bool swapped = { false };
	auto prev = li.begin(), next = li.begin(); next++;
	while (next != li.end()) //1+1+1+1+..+1 =O(N)
	{
		if (*prev > *next)
		{
			swap(*prev, *next);
			swap(prev, next);
			swapped = true;
		}
		next++;
		prev++;
	}
	return swapped;
}
void ListBubbleSortDS(list<int> &li)
{
	bool swapped = { false };
	do
	{
		swapped = ListBubbleUpPS(li);
	} while (swapped); //In worst case O(N)
	//Overall complexity = O(N^2)
}

//Q2 Vector Merge function
vector<int> VectorMerge(vector<int> &A, vector<int> &B)
{
	vector<int> C;
	int ai = 0, bi = 0;
	while (ai < A.size() && bi < B.size())
	{
		if (A[ai] < B[bi])
		{
			C.push_back(A[ai]), ai++;
		}
		else
		{
			C.push_back(B[bi]), bi++;
		}
	}
	if (ai == A.size())
	{
		for (int i = bi; i < B.size(); i++)
			C.push_back(B[i]);
	}
	else
	if (bi == B.size())
	{
		for (int i = ai; i < A.size(); i++)
			C.push_back(A[i]);
	}
	return C;
	//Complexity = O(A) + O(B)
}
//Q2 list Merge function
list<int> ListMerge(list<int> &A, list<int> &B)
{
	list<int> C;
	auto ai = A.begin(), bi = B.begin();
	while (ai != A.end() && bi != B.end())
	{
		if (*ai < *bi)
		{
			C.insert(C.end(), *ai), ai++;
		}
		else
		{
			C.insert(C.end(), *bi); bi++;
		}
	}
	if (ai == A.end())
	{
		C.insert(C.end(), bi, B.end());
	}
	else
	if (bi == B.end())
	{
		C.insert(C.end(), ai, A.end());
		ai = B.end();
	}
	return C;
	//Complexity = O(A) + O(B)
}

//Q3 Vector Merge Sort
void VectorMergeSort(vector<int> &L)
{
	if (L.size() == 1)
		return;

	vector<int> A, B;
	for (int i = 0; i < L.size() / 2; i++)
	{
		A.push_back(L[i]);
	}
	for (int i = L.size() / 2; i < L.size(); i++)
	{
		B.push_back(L[i]);
	}
	VectorMergeSort(A);
	VectorMergeSort(B);
	L = VectorMerge(A, B);
	//	(log N) = 2^(log N) (or N / 2) calls to merge() with N/2 ^ log N(or 1) ->  O(N Log N)
}
//Q3 List Merge Sort
void ListMergeSort(list<int> &L)
{
	if (L.size() == 1)
		return;

	list<int> A, B;
	auto li = L.begin();
	for (int i = 0; i < L.size() / 2; i++)
	{
		A.insert(A.end(), *li); li++;
	}
	for (int i = L.size() / 2; i < L.size(); i++)
	{
		B.insert(B.end(), *li); li++;
	}
	ListMergeSort(A);
	ListMergeSort(B);
	L = ListMerge(A, B);
	//	(log N) = 2^(log N) (or N / 2) calls to merge() with N/2 ^ log N(or 1) ->  O(N Log N)
}

//Q4 Vector Selection Sort
void VectorSelectionSort(vector<int> &V)
{
	int minIndex;  
	for (int i = 0; i < V.size() - 1; i++) //1 + 1 + 1 + 1 + .... + 1 = O(N)
	{  
		minIndex = i;
		for (int j = i + 1; j < V.size(); j++) //1 + 1 + 1 + 1 + .... + 1 = O(N)
		{
			if (V[j] < V[minIndex])
			{
				minIndex = j;
			}
		}  
		swap(V[minIndex], V[i]);
	}
	//O(N) * O(N)=O(N^2)
}
//Q4 List Selection Sort
void ListSelectionSort(list<int> &L)
{
	//int minIndex;
	auto minIndex = L.begin(), li = L.begin();
	for (int i = 0; i < L.size() - 1; i++, li++) //1 + 1 + 1 + 1 + .... + 1 = O(N)
	{
		minIndex = li;
		auto j = li;
		j++;
		for (; j!=L.end(); j++)//1 + 1 + 1 + 1 + .... + 1 = O(N)
		{
			if (*j < *minIndex)
			{
				minIndex = j;
			}
		}
		iter_swap(minIndex, li);
	}
	//O(N) * O(N)=O(N^2)
}

//Q5 Vector Insertion Sort
void VectorInsertionSort(vector<int> &V) 
{
	int tmp = { 0 }, j = { 0 };
	for (int i = 1; i < V.size(); i++) //1 + 1 + 1 + 1 + .... + 1 = O(N)
	{
		tmp = V[i];
		j = i - 1;
		while (j >= 0 && V[j] > tmp)// In worst case O(N)
		{
			V[j + 1] = V[j];
			j--;
		}
		V[j + 1] = tmp;
	}
	//Over all complexity = O(N) * O(N) = O(N^2)
}
//Q5 List Insertion Sort
void ListInsertionSort(list<int> &L)
{
	bool brk = true;
	int tmp = { 0 }, j = { 0 };
	auto bk = L.begin();
	auto li = L.begin(); li++;
	for (int i = 1; i < L.size(); li++, i++) //1 + 1 + 1 + 1 + .... + 1 = O(N)
	{
		tmp = *li;
		brk = true;
		auto js = li;
		js--;
		int j = i - 1;
		while (*js > tmp) // In worst case O(N)
		{
			if (brk == false)
			{
				int x = *js;
				*js = x;
				break;
			}
			else
			{
				int x = *js;
				*(++js) = x;
			}
			js--;
			
			if (js == L.begin() && j >= 0)
			{
				int x = *js;
				*(++js) = x;
				js--;
				brk = false;
				continue;
			}
			js--;
			j--;
			cout <<  L;
		}
		if (brk == true)
			*(++js) = tmp;
		else
			*js = tmp;
	}
	//Over all complexity = O(N) * O(N) = O(N^2)
}

//Q6 Bucket Sort
void BucketSort(list<int> &L)
{
	int NoOfBuckets = L.size(), index = 0;
	vector<list<int>> Vs(NoOfBuckets);
	auto li = L.begin();
	for (int i = 0; i < NoOfBuckets; i++, li++) //O(NoOfBuckets)
	{
		index = *li % NoOfBuckets;
		if (index < 0)
			index += NoOfBuckets;
		Vs[index].push_back(*li);
		ListInsertionSort(Vs[index]);
	}
	L.clear();
	list<int> M;
	for (int i = 0; i < NoOfBuckets; i++)
	{
		M = ListMerge(M, Vs[i]);
	}
	L = M;
}