#pragma once


class Answer
{
public:
	string answer;
	bool isTrue;


	Answer() : answer(), isTrue() {}

	Answer(string _answer, bool _isTrue)
	{
		answer = _answer;
		isTrue = _isTrue;
	}

	void show()
	{
		cout << answer;
	}

};
