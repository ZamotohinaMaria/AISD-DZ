#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>
class List
{
public:
	struct e
	{
		T val;
		e* next;
		e(const T& v, e* next) : val(v), next(next)
		{}
		
	};
	e* head;
public:
	List() { head = NULL; }
	~List() { clear(); }

	void clear()
	{
		while (head)
		{
			e* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	List& operator += (const T& v)
	{
		head = new e(v, head);
		return *this;
	}

	//добавление в конец - дз
	/*List& operator += (const T& v)
	{
		if (head == NULL)
			head = new e(v, NULL);
		else
		{
			e* p = head;
			while (p->next)
			{
				p = p->next;
			}
			p->next = new e(v, NULL);
		}
		return *this;
	}*/

	// iterative
	void print()
	{
		e* tmp = head;
		while (tmp)
		{
			cout << tmp->val << endl;
			tmp = tmp->next;
		}
	}

	void print(e* p)
	{
		if (!p) {}
		if (p)
		{
			cout << p->val << endl;
			print(p->next);
		}
	}
	//обратнo-рекурсивный вывод - дз
	void reverse_print(e* p)
	{
		if (!p) {}
		if (p)
		{
			print(p->next);
			cout << p->val << endl;
		}
	}
	// рекурсивная сумма - дз
	int get_count(e* p, int c = 0)
	{
		if (!p) { return c; }
		if (p)
		{
			c += 1;
			get_count(p->next, c);
		}
		return c;
	}
	//рекурсивная очистка - дз
	void recursive_clear(e* p)
	{
		if (!p) {}
		if (p)
		{
			e* tmp = p->next;
			delete p;
			head = NULL;
			recursive_clear(tmp);
		}
	}
};



int main()
{
	List <int> q;
	q += 5;
	q += 6;
	q.print();
	cout << "------------------------------------" << endl;
	cout << q.get_count(q.head) << endl;
	q += 1;
	cout << "------------------------------------" << endl;
	q.print(q.head);
	cout << q.get_count(q.head) << endl;
	q.recursive_clear(q.head);
}