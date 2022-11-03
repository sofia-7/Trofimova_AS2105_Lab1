#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
# include <iostream>
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

	friend std::istream& operator >> (istream& in, KS& ks);
	friend std::ostream& operator << (ostream& out, const KS& ks);

};