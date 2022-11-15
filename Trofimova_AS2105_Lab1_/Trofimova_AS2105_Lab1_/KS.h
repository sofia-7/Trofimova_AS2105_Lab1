#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class KS
{
public: static int max_id_ks;
      KS() {
          id = max_id_ks++;
      }
      friend istream& operator>> (istream& in, KS& tb);
      friend ostream& operator<< (ostream& out, KS& ks);
      void save_ks(ofstream& file);
      void edit_ks();
      void load_ks(ifstream& file);
      int get_id_ks() { return id; }
      double get_unused_ws() { return (((double)workshop - (double)working_workshop) / (double)workshop) * 100; }
      string name = "";
      

private:
    int id;
    int  workshop, working_workshop;
    double effectiveness;
};
//static unordered_set <int> id_ks;