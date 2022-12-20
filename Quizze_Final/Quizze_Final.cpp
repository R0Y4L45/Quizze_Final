#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<random>



using namespace std;


#include "color.h"
#include "Answer.h"
#include "Question.h"
#include "Quizze.h"
#include "Admin.h"
#include "User.h"
#include "DataBase.h"
#include "Guest.h"








int main()
{

	int getch, up_down = 0;
	cout << "[1] Sing up  <<" << endl
		<< "[2] Sing in" << endl
		<< "[3] Play as guest" << endl
		<< "[4] Show leader board" << endl
		<< "[5] Exit" << endl;

	while (true)
	{
		try
		{
			getch = _getch();

			if (getch == 72)
			{
				if (up_down - 1 < 0)
				{
					cout << '\a';
				}
				else
				{
					system("cls");
					--up_down;

					if (up_down == 0)
					{
						cout << "[1] Sing up  <<" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 1)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in  <<" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 2)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest  <<" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 3)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board  <<" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 4)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit  <<" << endl;
					}
				}
			}
			else if (getch == 80)
			{
				if (up_down + 1 == 5)
				{
					cout << '\a';
				}
				else
				{
					system("cls");
					++up_down;

					if (up_down == 0)
					{
						cout << "[1] Sing up  <<" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 1)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in  <<" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 2)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest  <<" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 3)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board  <<" << endl
							<< "[5] Exit" << endl;
					}
					else if (up_down == 4)
					{
						cout << "[1] Sing up" << endl
							<< "[2] Sing in" << endl
							<< "[3] Play as guest" << endl
							<< "[4] Show leader board" << endl
							<< "[5] Exit  <<" << endl;
					}
				}
			}
			else if (getch == 13)
			{
				system("cls");
				if (up_down == 0)
				{
					string username, password;
					cout << dye::black_on_green("Enter Username : ");
					cin >> username;
					cout << dye::black_on_green("Enter Password : ");
					cin >> password;
					User user(username, password);
					Base.userNameChecker(username);
					Base.singUp(user);

					cout << dye::on_yellow("\nSuccesfully was registered :<)") << endl;
					cout << dye::on_yellow("(Press < or > or ^ or v)");
				}
				if (up_down == 1)
				{
					string name, password;
					char checker;
					cout << "Enter username : \n";
					cin >> name;
					cout << "Enter password : \n";
					cin >> password;
					checker = Base.singIn(name, password);

					if (checker == 'a')
					{
						cout << dye::light_blue("Admin ") + dye::red(name) << dye::green(" Welcome to your account ;)\n");
						Sleep(2000);
						Admin admin(name, password);
						system("cls");
						cout << "[1] Create questions  <<\n"
							<< "[2] Add one question to created quizze \n"
							<< "[3] Play\n"
							<< "[4] Exit account\n";
						int upDown = 0;
						bool exit = true;
						while (exit)
						{
							switch (_getch())
							{
							case 224:
								break;
							case 72:
							{
								if (upDown - 1 == -1)
								{
									cout << '\a';
								}
								else
								{
									system("cls");
									upDown--;
									if (upDown == 0)
									{
										cout << "[1] Create questions  <<\n"
											<< "[2] Add one question to created quizze \n"
											<< "[3] Play\n"
											<< "[4] Exit account\n";
									}
									else if (upDown == 1)
									{
										cout << "[1] Create questions\n"
											<< "[2] Add one question to created quizze  <<\n"
											<< "[3] Play\n"
											<< "[4] Exit account\n";
									}
									else if (upDown == 2)
									{
										cout << "[1] Create questions\n"
											<< "[2] Add one question to created quizze \n"
											<< "[3] Play  <<\n"
											<< "[4] Exit account\n";
									}
									else if (upDown == 3)
									{
										cout << "[1] Create questions\n"
											<< "[2] Add one question to created quizze \n"
											<< "[3] Play\n"
											<< "[4] Exit account  <<\n";
									}
								}
								break;
							}
							case 80:
							{
								if (upDown + 1 == 4)
								{
									cout << '\a';
								}
								else
								{
									system("cls");
									upDown++;
									if (upDown == 0)
									{
										cout << "[1] Create questions  <<\n"
											<< "[2] Add one question to created quizze \n"
											<< "[3] Play\n"
											<< "[4] Exit account\n";
									}
									else if (upDown == 1)
									{
										cout << "[1] Create questions\n"
											<< "[2] Add one question to created quizze  <<\n"
											<< "[3] Play\n"
											<< "[4] Exit account\n";
									}
									else if (upDown == 2)
									{
										cout << "[1] Create questions\n"
											<< "[2] Add one question to created quizze \n"
											<< "[3] Play  <<\n"
											<< "[4] Exit account\n";
									}
									else if (upDown == 3)
									{
										cout << "[1] Create questions\n"
											<< "[2] Add one question to created quizze \n"
											<< "[3] Play\n"
											<< "[4] Exit account  <<\n";
									}
								}
								break;
							}
							case 13:
							{
								if (upDown == 0)
								{
									Quizze q;
									system("cls");
									admin.createQuestions(q);
									string name;
									cout << "Enter quizze name to save : ";
									cin >> name;
									admin.saveQuestions(name, q);
								}

								if (upDown == 1)
								{
									Quizze quizze;
									string nameFile = admin.choiceFileName();
									admin.readQuizze(nameFile, quizze);
									admin.addQuestion(quizze);
									admin.saveQuestions(nameFile, quizze);
								}

								if (upDown == 2)
								{
									Quizze quizze;
									admin.readQuizze(admin.choiceFileName(), quizze);
									admin.startQuizze(quizze);
								}

								if (upDown == 3)
								{
									cout << dye::light_yellow("Good bye ;-) \n");
									cout << dye::on_yellow("(Press < or > or ^ or v)");

									exit = false;
								}

							}
							default:
								break;
							}

						}
					}
					else if (checker == 'u')
					{
						cout << dye::light_blue("User ") + dye::red(name) << dye::green(" Welcome to your account ;)\n");
						Sleep(2000);
						User user(name, password);

						system("cls");
						cout << "[1] Play  <<\n"
							<< "[2] Show leader board\n"
							<< "[3] Exit account\n";

						int upDown = 0;
						bool exit = true;
						while (exit)
						{
							switch (_getch())
							{
							case 224:
								break;
							case 72:
							{
								if (upDown - 1 == -1)
								{
									cout << '\a';
								}
								else
								{
									upDown--;
									system("cls");
									if (upDown == 0)
									{
										cout << "[1] Play  <<\n"
											<< "[2] Show leader board\n"
											<< "[3] Exit account\n";
									}
									else if (upDown == 1)
									{
										cout << "[1] Play\n"
											<< "[2] Show leader board  <<\n"
											<< "[3] Exit account\n";
									}
									else if (upDown == 2)
									{
										cout << "[1] Play\n"
											<< "[2] Show leader board\n"
											<< "[3] Exit account  <<\n";
									}
								}
								break;
							}
							case 80:
							{
								if (upDown + 1 == 3)
								{
									cout << '\a';
								}
								else
								{
									upDown++;
									system("cls");
									if (upDown == 0)
									{
										cout << "[1] Play  <<\n"
											<< "[2] Show leader board\n"
											<< "[3] Exit account\n";
									}
									else if (upDown == 1)
									{
										cout << "[1] Play\n"
											<< "[2] Show leader board  <<\n"
											<< "[3] Exit account\n";
									}
									else if (upDown == 2)
									{
										cout << "[1] Play\n"
											<< "[2] Show leader board\n"
											<< "[3] Exit account  <<\n";
									}
								}
								break;
							}
							case 13:
							{
								if (upDown == 0)
								{
									User::resultSaver result;
									Quizze quizze;
									user.readQuizze(user.choiceFileName(), quizze);
									result = user.startQuizze(quizze);
									user.writeToleaderBoard(name, result);
								}

								if (upDown == 1)
								{
									user.showLeaderBoard();
									cout << dye::on_yellow("(Press < or > or ^ or v)");
								}

								if (upDown == 2)
								{
									cout << dye::light_yellow("Good bye ;-) \n");
									cout << dye::on_yellow("(Press < or > or ^ or v)");

									exit = false;
								}
							}
							default:
								break;
							}

						}

					}
				}
				else if (up_down == 2)
				{
					Guest guest;
					Quizze quizze;
					guest.readQuizze(guest.choiceFileName(), quizze);
					guest.startQuizze(quizze);
				}
				else if (up_down == 3)
				{
					User user;
					user.showLeaderBoard();
					cout << dye::on_yellow("(Press < or > or ^ or v)");
				}
				else if (up_down == 4)
				{
					cout << dye::black_on_green("GOOD BYE ..)") << endl;
					exit(0);
				}

			}

		}
		catch (const exception& ex)
		{
			cout << dye::red(ex.what()) << endl;
			cout << dye::on_yellow("(Press < or > or ^ or v)") << endl;
		}
	}
}
