#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
using namespace std;

class Tube
{
public:
	float length = 0;
	float diametr = 0;
	bool maintenance = 2;

	void add_tube();
	void print_tube();
};

class KS
{
public:
	string name = "";
	int workshops = 0;
	int workingWork = 0;
	float efficiency = 0;

	void add_ks();
	void print_ks();

};
/*class Tube
{
public:
	void set_length(float tube_length)
	{
		length = tube_length;
	}
	float get_length()
	{
		return length;
	}

	void set_diametr(float tube_diametr)
	{
		diametr = tube_diametr;
	}
	float get_diametr()
	{
		return diametr;
	}

	void set_maintenance(float tube_maintenance)
	{
		maintenance = tube_maintenance;
	}
	float get_maintenance()
	{
		return maintenance;
	}

private:
	float length = 0, diametr = 0;
	bool maintenance = 2;
};

*/
/*class Tube
{
public:
	void set_length(float); 
	float get_length(); 

	void set_diametr(float);
	float get_diametr();

	void set_maintenance(bool);
	bool get_maintenance();

private:
	float length = 0;
	float diametr = 0;
	bool maintenance = 2;
};

class KS
{
public:
	void set_name(string);
	string get_name();

	void set_workshops(int);
	int get_workshops();

	void set_workingWork(int);
	int get_workingWork();

	void set_efficiency(float);
	float get_efficiency();

private:
	string name = "";
	int workshops = 0;
	int workingWork = 0;
	float efficiency = 0;
};
*/