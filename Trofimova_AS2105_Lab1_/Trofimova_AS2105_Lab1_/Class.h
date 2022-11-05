#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
# include <iostream>
#include <fstream>
using namespace std;

class Tube
{
	int id;

public:
	static int MaxIdTb;
	string tb_name;
	float length;
	float diametr;
	bool maintenance;


	int get_id() const;
	void set_id();

	friend istream& operator >> (istream& in, Tube tb);
	friend ostream& operator << (ostream& out, const Tube& tb);
	static void edit_tube(Tube& tb);
	friend ifstream& operator >> (ifstream& in, Tube& p);
	friend ofstream& operator << (ofstream& out, const Tube& p);
};

class KS
{
	int id;
	int workshops;
	int workingWork;

public:

	string ks_name;
	int efficiency;
	static int MaxIdKs;

	int get_id() const;
	void set_id();
	int get_workshops() const;
	void set_workshops();
	int get_workingWork() const;
	void set_workingWork();

	friend istream& operator >> (istream& in, KS& ks);
	friend ostream& operator << (ostream& out, const KS& ks);
	static void edit_ks(KS& ks);
	friend ifstream& operator >> (ifstream& in, KS& ks);
	friend ofstream& operator << (ofstream& out, const KS& ks);
};