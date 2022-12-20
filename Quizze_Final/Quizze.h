#pragma once

class Quizze {
public:
    vector<Question> questions;
    string _name;

    Quizze() : questions(), _name() {}

    Quizze(string name, vector<Question> question)
    {
        questions = question;
        _name = name;
    }
};

ostream& operator << (ostream& out, const Quizze& q)
{
    out << "Name : " << q._name << endl;
    out << "Question : \n\n";
    for (size_t i = 0; i < q.questions.size(); i++)
    {
        cout << q.questions[i] << endl;
    }
    return out;
}