#include <iostream>

using namespace std;

class nrvo_tester {
private:
	
public:
	int first;
	int second;
	int sum;
	nrvo_tester(int a, int b)
	{
		first = a;
		second = b;
		sum = a + b;

		cout << "Created" << endl;
	}

	nrvo_tester(const nrvo_tester &original)
	{
		first = original.first;
		second = original.second;
		sum = original.sum;

		cout << "Copied" << endl;
	}

	void print()
	{
		cout << "--A: " << first << endl;
		cout << "--B: " << second << endl;
		cout << "--A+B: " << sum << endl;

	}

	~nrvo_tester()
	{
		cout << "Destroyed" << endl;
	}

	

};


nrvo_tester nrvotest(int a, int b)
{
	nrvo_tester resp(a, b);

	return resp;
}

nrvo_tester copy(nrvo_tester const& a)
{
	nrvo_tester resp = a;
	return resp;
}

int main()
{
	nrvo_tester res = nrvotest(1, 2);
	nrvo_tester res2 = copy(res);

	cout << endl << "--Print Res2:" << endl;
	res2.print();
	cout << endl;

	return 0;

}