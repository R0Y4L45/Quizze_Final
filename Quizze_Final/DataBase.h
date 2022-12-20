#pragma once


class DataBase
{
public:



	void userNameChecker(string username)
	{
		ifstream fout("Admin.txt");
		ifstream fout1("User.txt");

		if (!fout)
			throw exception("file is not found");
		if (!fout.is_open())
			throw exception("file is not opened");
		if (!fout1)
			throw exception("file is not found");
		if (!fout1.is_open())
			throw exception("file is not opened");

		string data;


		while (!fout.eof())
		{
			fout >> data;
			if (data == username)
				throw exception("Username have used...(\n");
			fout >> data;
		}

		while (!fout1.eof())
		{
			fout1 >> data;
			if (data == username)
				throw exception("Username have used...(\n");
			fout1 >> data;
		}

		fout.close();
		fout1.close();
	}


	void singUp(const User& user)
	{
		ofstream fout("User.txt", ios::app);

		if (!fout)
			throw exception("file is not found");
		if (!fout.is_open())
			throw exception("file is not opened");

		fout << user.username << ' ' << user.password << endl;

		fout.close();
	}

	char singIn(string username, string password)
	{
		ifstream fin("Admin.txt");
		ifstream fin1("User.txt");

		if (!fin)
			throw exception("file is not found");
		if (!fin.is_open())
			throw exception("file is not opened");
		if (!fin1)
			throw exception("file is not found");
		if (!fin1.is_open())
			throw exception("file is not opened");

		string name;
		string pass;


		while (!fin.eof())
		{
			fin >> name;
			fin >> pass;
			if (name == username)
				if (pass == password)
				{
					fin.close();
					fin1.close();
					return 'a';
				}
				else
					throw exception("Wrong password...(\n");

		}

		while (!fin1.eof())
		{
			fin1 >> name;
			fin1 >> pass;
			if (name == username)
				if (pass == password)
				{
					fin.close();
					fin1.close();
					return 'u';
				}
				else
					throw exception("Wrong password...(\n");
		}

		throw exception("Wrong Username...(\n");

		fin.close();
		fin1.close();
		return 'c';
	}

	void saveFileNames(string fileName)
	{
		ofstream file("files", ios::app);
		if (!file)
			throw exception("file is not found");
		if (!file.is_open())
			throw exception("file is not opened");

		file << fileName << endl;

		file.close();
	}



}Base;

