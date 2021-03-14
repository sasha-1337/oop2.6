#include "Long.h"
Long::Pair::Pair()
{
	first = 0;
	second = 0;
}
Long::Pair::Pair(int f = 0, int s = 0)
{
	first = f;
	second = s;
}
Long::Pair::Pair(const Pair& r)
{
	first = r.first;
	second = r.second;
}
Long::Pair::~Pair() { }

void Long::Read()
{
	Pair pair1(1, 1), pair2(1, 1);
	cout << " pair (a,b) - ?"; cin >> pair1;
	cout << " ( a , b )";
	cout << pair1;

	cout << " pair (c,d) - ?"; cin >> pair2;
	cout << " ( c , d )";
	cout << pair2;

	Pair a = pair1 + pair2;
	cout << "(a, b) + (c, d) = (a + c), (b + d)";
	cout << a;

	Display(pair1, pair2);

    Pair z(1, 1);
    cout << endl << endl;
    cout << " a  " << z << endl;
    cout << " a++  " << z++;
    cout << " a--  " << z--;
    cout << " ++a  " << ++z;
    cout << " --a  " << --z;
}

void Long::Pair::Init(int F, int S)
{
    SetFirst(F);
    SetSecond(S);
}

Long::Pair operator + (const Long::Pair& a, const Long::Pair& b)
{
    return Long::Pair(a.first + b.first, a.second + b.second);
}

Long::Pair& Long::Pair::operator = (const Long::Pair& r)
{
    first = r.first;
    second = r.second;
    return *this;
}

ostream& operator << (ostream& out, const Long::Pair& r)
{
    out << string(r);
    return out;
}

istream& operator >> (istream& in, Long::Pair& r)
{
    cout << " "; in >> r.first;
    cout << " "; in >> r.second;
    r.Init(r.first, r.second);
    return in;
}

void Long::Display(Pair pair1, Pair pair2)
{
    Long l;
    cout << "(a, b) * (c, d) = (a * c), (b * d)" << endl;
    cout << " ( " << l.Multiply_1(pair1, pair2) << " , " << l.Multiply_2(pair1, pair2) << " )" << endl << endl;

    cout << "(a, b) - (c, d) = (a - c), (b - d)" << endl;
    cout << " ( " << l.Diff_1(pair1, pair2) << " , " << l.Diff_2(pair1.GetSecond(), pair2.GetSecond()) << " )" << endl;
}

int Long::Multiply_1(Pair a, Pair b) { return a.GetFirst() * b.GetFirst(); }

int Long::Multiply_2(Pair a, Pair b) { return a.GetSecond() * b.GetSecond(); }

int Long::Diff_1(Pair a, Pair b) { return a.GetFirst() - b.GetFirst(); }

int Long::Diff_2(int a, int b) { return a - b; }

Long::Pair::operator string () const
{
    stringstream sstr;
    sstr << endl << " ( " << first << " , " << second << " )" << endl << endl;
    return sstr.str();
}

Long::Pair& Long::Pair::operator ++()
{
    first++;
    return *this;
}
Long::Pair& Long::Pair::operator --()
{
    first--;
    return *this;
}
Long::Pair Long::Pair::operator ++(int)
{
    Pair t(*this);
    second++;
    return t;
}
Long::Pair Long::Pair::operator --(int)
{
    Pair t(*this);
    second--;
    return t;
}