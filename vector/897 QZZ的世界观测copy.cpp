#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct square
{
	int length;
	int width;
	int area;
	square()
	{
		length = 0;
		width = 0;
		area = 0;
	}
	square(int a, int b)
	{
		if (a >= b)
		{
			length = a;
			width = b;
		}
		else
		{
			length = b;
			width = a;
		}
		area = a * b;
	}
};

bool compare_area(const square& a, const square& b)
{
	return a.area > b.area;
}

int max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	square s[3] =
	{
		square(a, b),
		square(c, d),
		square(e, f)
	};
	vector<square> squares(3);
	copy(s, s + 3, squares.begin());
	sort(squares.begin(), squares.end(), compare_area);
	//sorting and printing by iterator successfully
	bool result = false;
	if (squares.at(1).length + squares.at(2).width <= squares.at(0).length
	        && max(squares.at(1).width, squares.at(2).length) <= squares.at(0).width)
	{
		result = true;
	}
	if (squares.at(1).length + squares.at(2).width <= squares.at(0).width
	        && max(squares.at(1).width, squares.at(2).length) <= squares.at(0).length)
	{
		result = true;
	}
	if (squares.at(1).length + squares.at(2).length <= squares.at(0).length
	        && max(squares.at(1).width, squares.at(2).width) <= squares.at(0).width)
	{
		result = true;
	}
	if (squares.at(1).length + squares.at(2).length <= squares.at(0).width
	        && max(squares.at(1).width, squares.at(2).width) <= squares.at(0).length)
	{
		result = true;
	}
	if (squares.at(1).width + squares.at(2).length <= squares.at(0).length
	        && max(squares.at(1).length, squares.at(2).width) <= squares.at(0).width)
	{
		result = true;
	}
	if (squares.at(1).width + squares.at(2).length <= squares.at(0).width
	        && max(squares.at(1).length, squares.at(2).width) <= squares.at(0).length)
	{
		result = true;
	}
	if (squares.at(1).width + squares.at(2).width <= squares.at(0).length
	        && max(squares.at(1).length, squares.at(2).length) <= squares.at(0).width)
	{
		result = true;
	}
	if (squares.at(1).width + squares.at(2).width <= squares.at(0).width
	        && max(squares.at(1).length, squares.at(2).length) <= squares.at(0).length)
	{
		result = true;
	}
	if (result)
	{
		cout << "SIXSIXSIX!" << endl;
	}
	else
	{
		cout << "GG!" << endl;
	}
	return 0;
}
