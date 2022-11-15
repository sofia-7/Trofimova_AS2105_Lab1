#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "tube.h"
#include "KS.h"

using namespace std;

template <typename T>
T numberCheck(T min = 0, T max = 10000000)
{
	T x;
	while (!(cin >> x)||(cin.peek()!='\n')|| x<min || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, type number (" << min << "-" << max << "): ";
	}
	return x;
}

template <typename T>
using tube_filter = bool (*) (Tube& tb, T param);
template <typename T>
using ks_filter = bool(*) (KS& ks, T param);
template <typename T>
vector <int> search_tb_by_parametr(unordered_map <int, Tube>& tubeMap, tube_filter<T> f, T param) {
    vector <int> search;
    for (auto& tube : tubeMap) {
        if (f(tube.second, param))
            search.push_back(tube.second.get_id_tb());
    }
    return search;
}
template <typename T>
vector <int> search_ks_by_parametr(unordered_map <int, KS>& KSMap, ks_filter<T> f, T param) {
    vector <int> search;
    for (auto& ks : KSMap) {
        if (f(ks.second, param))
            search.push_back(ks.second.get_id_ks());
    }
    return search;
}