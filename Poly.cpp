#include "Poly.h"
#include <iostream>
using namespace std;

Poly::Poly()
{
	head = NULL;
	tali = NULL;
}

Poly::Poly(int Coeff_arr[], int Pow_arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		insert_Node(Coeff_arr[i],Pow_arr[i]);
	}
}

void Poly::delete_Node(int w)
{

	Node* del = NULL;
	Node* h = head;
	Node* pre=head;
	if (head->pow == w)
	{
		del = head;
		head = head->next;
		delete del;
		return;
	}
	Node *s= head;
	if (tali->pow == w)
	{
		while (s != NULL)
		{
			if (s->next->pow == w)
			{
				Node* dd = tali;
				tali = s;
				delete dd;
				tali->next = NULL;
				return;
			}
			s = s->next;
		}
	}
	while (h!= NULL)
	{
		if (h->pow == w)
		{
			del = h;
			pre->next = h->next;
			delete del;
			return;
		}
		else
		{
			pre = h;
			h=h->next;
		}
	}
}

Node *Poly::get_head()
{
	return head;
}

Node *Poly::get_tali()
{
	return tali;
}

double Poly::Eval_poly(double x)
{
	Node* h = head;
	double result = 0.0;
	while (h!=NULL)
	{
		if (head == h && head->pow==0)
		{
			result += head->conf;
		}
		else
		{
			result += ((pow(x, h->pow)) * h->conf);
		}
		h = h->next;
	}
	return result;
}

void Poly::insert_Node(int c, int p)
{
	if ((p == 0 && c == 0))
	{
		return;
	}
	Node* n;
	n = new Node;
	n->conf = c;
	n->pow = p;
	Node* loop = head;
	Node* poin = head;
	Node* dele = NULL;
	if (head == NULL)
	{
		head = tali = n;
		n->next = NULL;
		return;
	}
	else
	{

		if (p == 0 && head->pow==0 && n->pow==0)
		{
			head->conf = head->conf + c;
			return;
		}
		if (head->pow == p)
		{
			head->conf += c;
			return;
		}
		if (tali->pow == p)
		{
			tali->conf += c;
			return;
		}
		while (loop != NULL)
		{
			if (loop->pow == p)
			{
				loop->conf += c;
				return;
			}
			else
				loop = loop->next;
		}
		if (p < head->pow)//first
		{
			n->next = head;
			head = n;
			return;
		}
		if (p>tali->pow)
		{
			tali->next = n;
			tali = n;
			tali->next = NULL;
			return;
		}
		loop = head;
		while (loop != NULL)//genaral cass
		{
			if (p < loop->pow)
			{
				n->next = loop;
				poin->next = n;
				return;
			}
			else
			{
				poin = loop;
				loop = loop->next;
			}
		}
	}
}

int degree(Poly p)
{
	if (p.get_tali() != NULL)
	{
		return p.tali->pow;
	}
	else
	{
		return -1;
	}
}

Poly &operator +(Poly& p1, Poly& p2)
{	
	Poly add;
	Node* loop1 = p1.get_head();
	Node* loop2 = p2.get_head();
	while (loop1 != NULL)
	{
		add.insert_Node(loop1->conf,loop1->pow);
		loop1 = loop1->next;
	}
	while (loop2 != NULL)
	{
		add.insert_Node(loop2->conf, loop2->pow);
		loop2 = loop2->next;
	}
	return add;
}

void Poly::merge(Poly& parametr)
{
	Node* p = parametr.head;
	Node* h = head;

	Poly l;

	while (h!=NULL)
	{
		l.insert_Node(h->conf,h->pow);
		h = h->next;
	}
	while (p!=NULL)
	{
		l.insert_Node(p->conf, p->pow);
		p = p->next;
	}
	head = l.get_head();
	parametr.del();
	
}

void Poly::del()
{
	while (head != NULL)
	{
		Node* del = head;
		head = head->next;
		delete del;
	}
	head = NULL;
}

Poly::~Poly()
{
	//del();
}

istream& operator >>(istream& in, Poly& op)
{
	cout << "\nEnter the count of node: ";
	int count = 0;
	cin >> count;
	int c = 0;
	int p = 0;
	while (count--)
	{
		cout << "\nEnter cof: ";
		in>> c;
		cout << "\nEnter power number: ";
		in >> p;
		if (p >= 0 && c != 0)
		{
			op.insert_Node(c, p);
		}
		else
		{
			cout << "\nwrong input !\n";
			cout << "renter (::)\n";
			count++;
		}
	}
	return in;
}

ostream& operator <<(ostream& out, Poly& o)
{
	
	ofstream file("output_poly.txt", ios::out);
	if (!file.is_open())
	{
		cout << "\ncant open file to output the poly !!";
	}
	if (o.head == NULL)
	{
		out << "Empty";
		file << "Empty";

	}
	Node* p = o.get_head();
	while (p != NULL)
	{
		if (p==o.get_head())
		{
			out << "F(x):";
			file << "F(x):";
			if (p->pow == 0 && p->conf!=0)
			{
				out << p->conf;
				file << p->conf;
			}
			else if (p->conf==1) 
			{
				out <<"x^" << p->pow;
				file << "x^" << p->pow;
			}
			else if(p->pow==1 && p->conf!=0)
			{
				out << p->conf << "x";
				file << p->conf << "x";
			}
			else if (p->conf !=0 && p->pow!=0)
			{
				out << p->conf << "x^" << p->pow;
				file << p->conf << "x^" << p->pow;
			}
		}
		else
		{
			if (p->conf==1 && p->pow==1)
			{
				out << "+x";
				file << "+x";
			}
			else if (p->conf == 1 && p->pow != 0)
			{
				
				out << "+x^"<<p->pow;
				file << "+x^" << p->pow;
			}
			else if (p->pow == 1)
			{
				out << "+" << p->conf << "x";
				file<< "+" << p->conf << "x";
			}
			else if (p->pow == 0)
			{
				if (o.get_head()->conf != 0)
				{
					out << "+";
					file << "+";
				}
				out << p->conf;
				file << p->conf;
			}
			else if (p->conf > 0)
			{
				if (o.get_head()->conf != 0)
				{
					out << "+";
					file << "+";
				}
				out << p->conf << "x^" << p->pow;
				file << p->conf << "x^" << p->pow;
			}
			else if (p->conf != 0)
			{
				out << p->conf << "x^" << p->pow;
				file << p->conf << "x^" << p->pow;
			}
		}
		p = p->next;
	}
	file.close();
	cout << "\n";
	return out;
}
