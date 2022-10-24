#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_LEN = 10;

struct p
{
	char key[MAX_LEN];
	int val;
};

template <class T>
class A
{
private:
	p* mass;
	int size, count;
public:
	A(unsigned size): size(size), count (0), mass(NULL)
	{
		mass = new p[size];
	}
	A(const A& a)
	{
		size = a.size;
		count = a.count;
		mass = new p[size];
		for (int i = 0; i < size; i++)
		{
			mass[i] = a.mass[i];
		}
	}
	~A()
	{
		delete[] mass;
		size = 0;
		count = 0;
	}
	A& operator = (const A& a)
	{
		if (this == (&a)) return *this;
		if (size < a.count)
		{
			delete[] mass;
			mass = new p[a.size];
			size = a.size;
		}
		for (int i = 0; i < a.count; i++)
		{
			mass[i] = a.mass[i];
		}
		count = a.count;
		return *this;
	}

	A& operator += (const p& para)
	{
		if (count == size) throw "нет места";
		mass[count].val = para.val;
		strcpy(mass[count].key, para.key);
		count += 1;
		return *this;
	}

	T operator [] (const char* key) const
	{
		for (int i = 0; i < count; i++)
		{
			if (strcmp(mass[i].key, key) == 0) return mass[i].val;
		}
		throw("занчение не найдено");
	}

	p operator [] (const int id) const
	{
		if (id >= size || id < 0)
		{
			throw "index i is out of range";
		}
		for (int j = 0; j < size; j++)
		{
			if (id == j)
			{
				return mass[id];
			}
		}
	}

	A operator +(const A& a)
	{
		if (count == 0) return a;
		if (a.count == 0) return *this;
		A res(size + a.size);
		for (int i = 0; i < size; i++)
		{
			res.mass[i] = mass[i];
		}
		for (int i = size; i < size + a.size; i++)
		{
			res.mass[i] = a.mass[i];
		}
		return res;
	}
};

//template <class T>
//struct array
//{
//	* a;
//	int n;
//};

template <class T>
T* Poisk(T* a, int n)
{
	int i = 0;

	T* res1 = new T[n];
	T* res2 = NULL;

	int n1 = 0;
	int n2 = 0;
	while (i < n)
	{
		if (res1 == NULL)
		{
			T* res0 = new T[n];
			res1 = res0;
		}
		if (i == n - 1)
		{
			if (a[n - 2] > a[n - 1])
			{
				res1[n1] = a[n - 1];
				n1 += 1;
			}
		}
		if (i < n-1 && a[i] > a[i + 1]) {
			res1[n1] = a[i];
			n1 += 1;
		}
		else
		{
			res1[n1] = a[i];
			n1 += 1;
			if (n1 > n2)
			{
				if (res2 != NULL)
					delete[] res2;
				res2 = NULL;
				T* res0 = new T[n1];
				res2 = res0;
				for (int j = 0; j < n1; j++)
				{
					res2[j] = res1[j];
				}
				n2 = n1;
			}
			n1 = 0;
			delete[] res1;
			res1 = NULL;
		}
		i++;
	}

	if (n1 > n2) return res1;
	if (n1 < n2) return res2;
}

int ymain()
{
	/*p a = { "ee", 5 };
	p b = a;
	cout << b.key << endl << b.val;*/
	int aa[16] = { 3, 2, 1, 60, 50, 40, 30, 20,10, 5, 4, 3, 2, 1, 6, 3 };
	cout << aa << endl;

	int* bb = Poisk(aa, 16);
	cout << bb << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << bb[i] << endl;
	}
	return 0;
}