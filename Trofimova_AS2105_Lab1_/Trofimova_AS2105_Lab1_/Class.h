#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Tube
{
public:
    static int max_id;
    string name = "";
    bool maintenance = 0;
    Tube() {
        idtb = max_id++;
    }
    friend istream& operator>> (istream& in, Tube& p);
    friend ostream& operator<< (ostream& out, unordered_set <int>& p);
    friend ostream& operator<< (ostream& out, Tube& p);
    void edit_Pipe();
    void save_tube(ofstream& file);
    void load_tube(ifstream& file);
    int get_id() { return idtb; }

private:
    double lenght = 0, diameter = 0;
    int idtb = 0;

};
class KS
{
public: static int max_idd;
      KS() {
          idks = max_idd++;
      }
      friend istream& operator>> (istream& in, KS& p);
      friend ostream& operator<< (ostream& out, KS& ks);
      void save_ks(ofstream& file);
      void edit_ks();
      void load_ks(ifstream& file);
      int get_idd() { return idks; }
      double get_unused() { return (((double)workshop - (double)working_workshop) / (double)workshop) * 100; }
      string name = "";


private:
    int  workshop, working_workshop, idks;
    double effectiveness;
};
int Tube::max_id = 0;
int KS::max_idd = 0;
unordered_set <int> iddp;
unordered_set <int> iddks;