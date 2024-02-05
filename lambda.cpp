// lambda.cpp : Defines the entry point for the application.
//

#include "lambda.h"

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class dum_mafs
{
public:
	static int add(const int a, const int b)
	{
		return a + b;
	}
	int (*fak)(int, int) = &add;
};

class movable_class
{
public:
	int data[1000];

	movable_class() = default;

	movable_class(movable_class&& to_move) noexcept
	{
		cout << "moving..." << '\n';

		memcpy(data,to_move.data,sizeof(data));
	}

	movable_class& operator=(movable_class&& to_move) noexcept
	{
		cout << "moving...." << '\n';
		swap(data,to_move.data);
		return *this;
	}
};

int mainn()
{
	std::function<void(int, int)> fun = [](const int a, const int b) -> void
	{
		cout << a + b << '\n';
	};
	const auto dm = dum_mafs();
	dm.fak(4, 6);

	std::vector<char> letters = { 'a','b','c' };
	const auto a_letter = find(letters.begin(), letters.end(), 'a');
	if (a_letter != letters.end())
	{
		cout << "We found \'a\'!";
	}
	else
	{
		cout << "We can't find \'a\'!";
	}

	auto copy_vector = vector<char>();
	auto _ = std::copy(letters.begin(), letters.end(), std::back_inserter(copy_vector));
	for (const char& it : copy_vector)
	{
		cout << it;
	}

	auto transform_vector = vector<char>();
	auto p = std::transform(letters.begin(), letters.end(), std::back_inserter(transform_vector), [](const char c)
		{
			if (c == 'a') return c;
			return 's';
		});
	for (const char& it : transform_vector)
	{
		cout << it;
	}

	auto remove_vector = vector<char>();
	letters.erase(std::remove(letters.begin(), letters.end(), 'c'), letters.end());
	for (const char& it : letters)
	{
		cout << it;
	}

	letters.push_back('c');
	const auto r = std::remove_if(letters.begin(), letters.end(), [](const char c)
	{
		return c == 'a';
	});
	letters.erase(r,letters.end());
	for (const char& it : letters)
	{
		cout << it;
	}

	vector<movable_class> movable_classes;
	movable_classes.emplace_back();
	movable_classes.push_back(std::move(movable_classes[0]));

	cout << "done!" << '\n';

	char b;
	cin >> b;
	return 0;
}
