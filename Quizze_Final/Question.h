#pragma once

class Question {

public:

	string question_text;
	vector<Answer> answers;
	size_t question_score;

	Question() : question_text(), answers(), question_score() {}

	Question(string question_text, size_t score, vector<Answer> _answers)
		:Question()
	{
		set_text(question_text);
		set_answers(_answers);
		set_score(score);
	}

	void set_score(size_t score = 0) {
		if (score <= 0)
			throw "Score is empty";
		else
			question_score = score;
	}


	void set_text(string question_text = "") {
		if (question_text.length() <= 0)
			throw "text is empty";
		else
			this->question_text = question_text;
	}

	void set_answers(vector<Answer> _answers) {
		if (_answers.size() == 0)
			throw "text is empty";
		else
			answers = _answers;
	}

};

ostream& operator << (ostream& out, const Question& q)
{
	out << q.question_text << endl << endl;
	return out;
}