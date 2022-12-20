#pragma once


class Admin
{
	string username;
	string password;
	friend class DataBase;
public:

	Admin() : username(), password() {}

	Admin(string _username, string _password)
	{
		setUsername(_username);
		setPassword(_password);
	}


	void setUsername(string _username)
	{
		if (_username.size() <= 3 || _username.size() > 10)
			throw exception("Username lenght must be upper than 3 and lower than 10\n");
		username = _username;
	}

	void setPassword(string _password)
	{
		if (_password.size() <= 3 || _password.size() > 13)
			throw exception("Username lenght must be upper than 3 and lower than 13\n");
		password = _password;
	}


	int yes_no(const string& question)
	{
		int getch, up_down = 0;

		while (true)
		{
			getch = _getch();
			if (getch == 72)
			{
				if (up_down - 1 == -1)
					cout << '\a';
				else
				{
					up_down--;
					system("CLS");
					cout << question;
					cout << dye::green("YES  << \n");
					cout << dye::red("NO\n");
				}
			}
			else if (getch == 80)
			{
				if (up_down + 1 == 2)
					cout << '\a';
				else
				{
					up_down++;
					system("CLS");
					cout << question;
					cout << dye::green("YES\n");
					cout << dye::red("NO  << \n");
				}
			}
			else if (getch == 13)
			{
				system("cls");
				return up_down;

			}
		}

	}


	int createQuestionsMenu()
	{
		short up_down = 0;
		int getch;
		cout << dye::grey("Create question  <<\n");
		cout << dye::grey("Exit\n");
		while (true)
		{
			getch = _getch();
			if (getch == 72)
			{
				if (up_down - 1 == -1)
					cout << '\a';
				else
				{
					--up_down;
					system("CLS");
					cout << dye::grey("Create question  <<\n");
					cout << dye::grey("Exit\n");
				}
			}
			else if (getch == 80)
			{
				if (up_down + 1 == 2)
					cout << '\a';
				else
				{
					++up_down;
					system("CLS");
					cout << dye::grey("Create question\n");
					cout << dye::grey("Exit  <<\n");
				}
			}
			else if (getch == 13)
			{
				system("cls");
				return up_down;

			}
		}
	}

	int addQuestionMenu()
	{
		short up_down = 0;
		int getch;
		cout << dye::grey("Add one question to quizze  <<\n");
		cout << dye::grey("Exit\n");
		while (true)
		{
			getch = _getch();
			if (getch == 72)
			{
				if (up_down - 1 == -1)
					cout << '\a';
				else
				{
					--up_down;
					system("CLS");
					cout << dye::grey("Add one question to quizze  <<\n");
					cout << dye::grey("Exit\n");
				}
			}
			else if (getch == 80)
			{
				if (up_down + 1 == 2)
					cout << '\a';
				else
				{
					++up_down;
					system("CLS");
					cout << dye::grey("Add one question to quizze\n");
					cout << dye::grey("Exit  <<\n");
				}
			}
			else if (getch == 13)
			{
				system("cls");
				return up_down;

			}
		}
	}


	void addQuestion(Quizze& quizze)
	{
		bool isTrue = false;
		int yn, countQuestions = 0;
		yn = addQuestionMenu();
		if (yn == 1)
			return;
		while (true)
		{
			string quest;

			cout << "Enter " << countQuestions + 1 << ". question\n";
			cin.ignore(0, EOF);
			getline(cin, quest);
			if (!isTrue)
			{
				isTrue = true;
				system("cls");
				continue;
			}
			cout << "Are you sure to add question? \n";
			cout << dye::green("YES  << \n");
			cout << dye::red("NO\n");
			yn = yes_no("Are you sure to add question? \n");
			if (yn == 1)
				continue;

			Question question;
			short count = 0, trueAnsCount = 0;
			do
			{
				string answer;

				cout << "Enter " << (count + 1) << ". answer\n";
				getline(cin, answer);

				cout << "Are you sure to add question? \n";
				cout << dye::green("YES  << \n");
				cout << dye::red("NO\n");
				yn = yes_no("Are you sure to add answer ?\n");

				if (yn == 1)
					continue;

				Answer ans;
				bool isTrue = false;
				if (trueAnsCount == 0)
				{
					cout << "Is answer true?\n";
					cout << dye::green("YES  << \n");
					cout << dye::red("NO\n");
					yn = yes_no("Is answer true?\n");

					if (yn == 0)
					{
						trueAnsCount++;
						isTrue = true;
					}
				}

				ans.answer = answer;
				ans.isTrue = isTrue;
				question.question_text = quest;
				question.answers.push_back(ans);
				count++;

				if (count >= 2)
				{
					cout << "Is that enough answers?\n";
					cout << dye::green("YES  << \n");
					cout << dye::red("NO\n");
					yn = yes_no("Is that enough answers?\n");
					if (yn == 0)
						break;
				}

			} while (true);
			quizze.questions.push_back(question);
			countQuestions++;
			yn = addQuestionMenu();
			if (yn == 1)
				break;
		}

	}


	void createQuestions(Quizze& quizze)
	{
		bool isTrue = false;
		int yn, countQuestions = 0;
		yn = createQuestionsMenu();
		if (yn == 1)
			return;
		while (true)
		{
			string quest;

			cout << "Enter " << countQuestions + 1 << ". question\n";
			cin.ignore(0, EOF);
			getline(cin, quest);
			if (!isTrue)
			{
				isTrue = true;
				system("cls");
				continue;
			}
			cout << "Are you sure to add question? \n";
			cout << dye::green("YES  << \n");
			cout << dye::red("NO\n");
			yn = yes_no("Are you sure to add question? \n");
			if (yn == 1)
				continue;

			Question question;
			short count = 0, trueAnsCount = 0;
			do
			{
				string answer;

				cout << "Enter " << (count + 1) << ". answer\n";
				getline(cin, answer);

				cout << "Are you sure to add question? \n";
				cout << dye::green("YES  << \n");
				cout << dye::red("NO\n");
				yn = yes_no("Are you sure to add answer ?\n");

				if (yn == 1)
					continue;

				Answer ans;
				bool isTrue = false;
				if (trueAnsCount == 0)
				{
					cout << "Is answer true?\n";
					cout << dye::green("YES  << \n");
					cout << dye::red("NO\n");
					yn = yes_no("Is answer true?\n");

					if (yn == 0)
					{
						trueAnsCount++;
						isTrue = true;
					}
				}

				ans.answer = answer;
				ans.isTrue = isTrue;
				question.question_text = quest;
				question.answers.push_back(ans);
				count++;

				if (count >= 2)
				{
					cout << "Is that enough answers?\n";
					cout << dye::green("YES  << \n");
					cout << dye::red("NO\n");
					yn = yes_no("Is that enough answers?\n");
					if (yn == 0)
						break;
				}

			} while (true);
			quizze.questions.push_back(question);
			countQuestions++;
			yn = createQuestionsMenu();
			if (yn == 1)
				break;
		}

	}



	bool fileNameChecker(string nameFile)
	{
		vector<string> files;
		string file;
		ifstream fileName("files.txt");

		if (!fileName)
			throw exception("file is not found");
		if (!fileName.is_open())
			throw exception("file can't open");

		while (!fileName.eof())
		{
			fileName >> file;
			files.push_back(file);
		}

		files.pop_back();

		for (size_t i = 0; i < files.size(); i++)
			if (nameFile == files[i])
			{
				fileName.close();
				return false;
			}

		fileName.close();
		return true;
	}



	void saveQuestions(string fileName, Quizze& quizze) {

		ofstream fileNames("files.txt", ios::app);

		if (!fileNames)
			throw exception("file is not found");
		if (!fileNames.is_open())
			throw exception("file can't open");


		if (fileNameChecker(fileName))
			fileNames << fileName << endl;

		ofstream fout(fileName, ios::out);

		if (!fout)
			throw exception("file is not found");
		if (!fout.is_open())
			throw exception("file can't open");


		fout << "...";
		for (size_t i = 0; i < quizze.questions.size(); i++)
		{
			fout << endl << quizze.questions[i].question_text << endl << "///" << endl;
			for (size_t k = 0; k < quizze.questions[i].answers.size(); k++)
				fout << quizze.questions[i].answers[k].answer << '\n' << quizze.questions[i].answers[k].isTrue << endl;
			fout << "...";
		}

		fileNames.close();
		fout.close();
	}


	string choiceFileName()
	{
		int getch, up_down = 0, count = 0;
		vector<string> files;
		string file;
		ifstream fileName("files.txt");

		if (!fileName)
			throw exception("file is not found");
		if (!fileName.is_open())
			throw exception("file can't open");


		while (!fileName.eof())
		{
			fileName >> file;
			files.push_back(file);
		}

		files.pop_back();

		cout << dye::on_yellow("Choice quizzes. (Press < or > or ^ or v)");

		while (true)
		{
			getch = _getch();
			if (getch == 72)
			{
				if (up_down - 1 == -1)
					cout << '\a';
				else
				{
					up_down--;
					system("CLS");
					for (size_t i = 0; i < files.size(); i++)
					{
						if (up_down == i)
						{
							cout << dye::aqua(files[i] + " <<") << endl;
							continue;
						}
						cout << files[i] + " <<" << endl;
					}
				}
			}
			else if (getch == 80)
			{
				if (up_down + 1 == files.size())
					cout << '\a';
				else
				{
					up_down++;
					system("CLS");
					for (size_t i = 0; i < files.size(); i++)
					{
						if (up_down == i)
						{
							cout << dye::aqua(files[i] + " <<") << endl;
							continue;
						}
						cout << files[i] + " <<" << endl;
					}
				}
			}
			else if (getch == 13)
			{
				system("cls");
				fileName.close();
				return files[up_down];
			}
		}

	}


	void readQuizze(string fileName, Quizze& q)
	{
		ifstream fin(fileName, ios::in);

		if (!fin)
			throw exception("file is not found");
		if (!fin.is_open())
			throw exception("file can't open");

		string data1;
		string data3;
		bool data2;

		getline(fin, data1);
		while (!fin.eof())
		{
			if (data1 == "...")
			{
				getline(fin, data1);
				data3 = data1;
			}
			else
			{
				getline(fin, data1);
				if (data1 == "///")
				{
					Question ques;
					getline(fin, data1);
					while (data1 != "...")
					{
						Answer ans;
						ans.answer = data1;
						fin >> data2;
						ans.isTrue = data2;
						ques.answers.push_back(ans);
						fin.ignore();
						getline(fin, data1);
					}
					ques.question_text = data3;
					q.questions.push_back(ques);
				}
			}
		}
		fin.close();
	}

	int randN(int num, int num1)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(num, num1);
		int b = dist6(rng);
		return b;
	}

	vector<size_t> randomQuestions(const Quizze& quizze)
	{
		bool equal = true;
		vector<size_t> randNums;
		size_t r = quizze.questions.size(), a = quizze.questions.size();
		while (r != 0)
		{
			int b = randN(0, a - 1);

			for (size_t i = 0; i < randNums.size(); i++)
				if (b == randNums[i])
				{
					equal = false;
					break;
				}

			if (equal)
			{
				randNums.push_back(b);
				--r;
			}
			equal = true;
		}

		return randNums;
	}


	vector<size_t> randAnswers(const Question& question)
	{
		bool equal = true;
		vector<size_t> randNums;
		size_t r = question.answers.size(), a = question.answers.size();
		while (r != 0)
		{
			int b = randN(0, a - 1);

			for (size_t i = 0; i < randNums.size(); i++)
				if (b == randNums[i])
				{
					equal = false;
					break;
				}

			if (equal)
			{
				randNums.push_back(b);
				--r;
			}
			equal = true;
		}
		return randNums;
	}

	void startQuizze(const Quizze& quizze)
	{
		bool color = false;
		map<int, int> colorIndexQuestAnswer;
		vector<size_t> randQuest = randomQuestions(quizze);
		short num = 0, a = 0;
		vector<size_t> rand = randAnswers(quizze.questions[randQuest[num]]);

		cout << num + 1 << '.' << quizze.questions[randQuest[num]];
		for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
			cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;

		while (true)
		{
			switch (_getch())
			{
			case 224:
				break;
			case 77:
				if ((num + 1) == randQuest.size())
					cout << '\a';
				else
				{
					bool isSame = false;
					short indexAns;
					rand = randAnswers(quizze.questions[randQuest[++num]]);

					if (a >= rand.size())
						a = 0;

					system("cls");
					cout << num + 1 << '.' << quizze.questions[randQuest[num]];
					for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
					{
						for (auto& k : colorIndexQuestAnswer)
						{
							if (k.first == randQuest[num])
							{
								indexAns = k.second;
								isSame = true;
							}
						}
						if (isSame && indexAns == rand[i])
							cout << dye::green(quizze.questions[randQuest[num]].answers[indexAns].answer) << endl;
						else
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;
					}
				}
				break;
			case 75:
				if ((num - 1) == -1)
					cout << '\a';
				else
				{
					bool isSame = false;
					short indexAns;
					rand = randAnswers(quizze.questions[randQuest[--num]]);

					if (a >= rand.size())
						a = 0;

					system("cls");
					cout << num + 1 << '.' << quizze.questions[randQuest[num]];
					for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
					{
						for (auto& k : colorIndexQuestAnswer)
						{
							if (k.first == randQuest[num])
							{
								indexAns = k.second;
								isSame = true;
							}
						}
						if (isSame && indexAns == rand[i])
							cout << dye::green(quizze.questions[randQuest[num]].answers[indexAns].answer) << endl;
						else
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;
					}
				}
				break;
			case 13:
			{
				bool numChecker = false;
				system("cls");

				cout << num + 1 << '.' << quizze.questions[randQuest[num]];
				for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
				{
					if (i == a)
					{
						cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer + " <") << endl;

						for (auto& k : colorIndexQuestAnswer)
						{
							if (k.first == randQuest[num])
							{
								numChecker = true;
								k.second = rand[i];
							}
						}

						if (!numChecker)
							colorIndexQuestAnswer.insert({ randQuest[num] , rand[i] });

						continue;
					}

					cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;
				}
				break;
			}
			case 72:
			{
				bool isSame = false;
				short indexAns;
				if ((a - 1) == -1)
				{
					system("cls");
					cout << num + 1 << '.' << quizze.questions[randQuest[num]];

					for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
					{
						for (auto& k : colorIndexQuestAnswer)
						{
							if (k.first == randQuest[num])
							{
								indexAns = k.second;
								isSame = true;
							}
						}
						if (i == a && isSame && indexAns == rand[i])
						{
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer + " <") << endl;
							continue;
						}
						else if (i == a)
						{
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer + " <" << endl;
							continue;
						}
						if (isSame && indexAns == rand[i])
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer) << endl;
						else
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;
					}
					cout << '\a';
				}
				else
				{
					system("cls");
					cout << num + 1 << '.' << quizze.questions[randQuest[num]];
					--a;
					for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
					{
						for (auto& k : colorIndexQuestAnswer)
						{
							if (k.first == randQuest[num])
							{
								indexAns = k.second;
								isSame = true;
							}
						}
						if (i == a && isSame && indexAns == rand[i])
						{
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer + " <") << endl;
							continue;
						}
						else if (i == a)
						{
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer + " <" << endl;
							continue;
						}
						if (isSame && indexAns == rand[i])
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer) << endl;
						else
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;
					}
				}
				break;
			}
			case 80:
			{
				bool isSame = false;
				short indexAns;
				if ((a + 1) == quizze.questions[randQuest[num]].answers.size())
				{
					system("cls");
					cout << num + 1 << '.' << quizze.questions[randQuest[num]];

					for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
					{
						for (auto& k : colorIndexQuestAnswer)
						{
							if (k.first == randQuest[num])
							{
								indexAns = k.second;
								isSame = true;
							}
						}
						if (i == a && isSame && indexAns == rand[i])
						{
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer + " <") << endl;
							continue;
						}
						else if (i == a)
						{
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer + " <" << endl;
							continue;
						}
						if (isSame && indexAns == rand[i])
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer) << endl;
						else
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;
					}
					cout << '\a';
				}
				else
				{
					system("cls");
					cout << num + 1 << '.' << quizze.questions[randQuest[num]];
					++a;
					for (size_t i = 0; i < quizze.questions[randQuest[num]].answers.size(); i++)
					{
						for (auto& k : colorIndexQuestAnswer)
						{
							if (k.first == randQuest[num])
							{
								indexAns = k.second;
								isSame = true;
							}
						}
						if (i == a && isSame && indexAns == rand[i])
						{
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer + " <") << endl;
							continue;
						}
						else if (i == a)
						{
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer + " <" << endl;
							continue;
						}
						if (isSame && indexAns == rand[i])
							cout << dye::green(quizze.questions[randQuest[num]].answers[rand[i]].answer) << endl;
						else
							cout << quizze.questions[randQuest[num]].answers[rand[i]].answer << endl;
					}
				}
				break;
			}
			case 27:
			{
				short up_down = 0;
				int getch;
				system("cls");
				cout << "	Are you sure to leave quizze ?\n\n";
				cout << "YES  << \n";
				cout << "NO\n";
				while (true)
				{
					getch = _getch();
					if (getch == 72)
					{
						if (up_down - 1 == -1)
							cout << '\a';
						else
						{
							up_down--;
							system("CLS");
							cout << "	Are you sure to leave quizze ?\n\n";
							cout << "YES  << \n";
							cout << "NO\n";
						}
					}
					else if (getch == 80)
					{
						if (up_down + 1 == 2)
							cout << '\a';
						else
						{
							up_down++;
							system("CLS");
							cout << "	Are you sure to leave quizze ?\n\n";
							cout << "YES\n";
							cout << "NO  << \n";
						}
					}
					else if (getch == 13)
					{
						if (up_down == 0)
						{
							float trueAnsCount = 0, falseAnsCount = 0;

							for (auto& c : colorIndexQuestAnswer)
							{
								if (quizze.questions[c.first].answers[c.second].isTrue)
									++trueAnsCount;
								else
									++falseAnsCount;
							}

							system("cls");
							float countQuest = quizze.questions.size();
							cout << dye::black_on_light_yellow("\nUsername : ") << dye::black_on_light_yellow(username);
							cout << dye::black_on_bright_white("\nCount of questions : ") << dye::black_on_bright_white(countQuest);
							cout << dye::black_on_light_yellow("\nCount of true answers result : ") << dye::black_on_light_yellow(trueAnsCount);
							cout << dye::black_on_bright_white("\nCount of false answers result : ") << dye::black_on_bright_white(falseAnsCount);
							cout << dye::black_on_light_yellow("\nCount of empty answers result : ") << dye::black_on_light_yellow((countQuest - (trueAnsCount + falseAnsCount))) << endl << endl;

							return;
						}
						else
						{
							system("cls");
							break;
						}
					}

				}
				cout << dye::black_on_light_green("To Continue press any arrow < > ^ v");
				break;
			}
			default:
				break;
			}
		}
	}
};

