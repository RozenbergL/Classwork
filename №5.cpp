#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    vector <pair<double, double>> more;
    vector <pair<double, double>> less;
    vector <double> degrees;
    for (int i = 0; i < n; i++){
        double m, d;
        fin >> m >> d;
        if (sin(d) > 0){
            pair <double, double> ppp;
            ppp.first = cos(d) * m;
            ppp.second = sin(d) * m;
            more.push_back(ppp);
        }
        if (sin(d) < 0){
            pair <double, double> ppp;
            ppp.first = cos(d) * m;
            ppp.second = sin(d) * m;
            less.push_back(ppp);
        }
        if (sin(d) == 0){
            pair <double, double> ppp;
            ppp.first = cos(d) * m;
            ppp.second = sin(d) * m;
            less.push_back(ppp);
            more.push_back(ppp);
        }
        degrees.push_back(d);
    }
    double x = 0;
    double y = 0;
    for (int i = 0; i < more.size(); i++){
        x += more[i].first;
        y += more[i].second;
    }
    double x1 = 0;
    double y1 = 0;
    for (int i = 0; i < less.size(); i++){
        x1 += less[i].first;
        y1 += less[i].second;
    }
    if (x * x + y * y >= x1 * x1 + y1 * y1){
        fout << more.size() << endl;;
        for (int i = 0; i < n; i++){
            if (sin(degrees[i]) >= 0){
                fout << i + 1 << " ";
            }
        }
    }else{
        fout << less.size() << endl;
        for (int i = 0; i < n; i++){
            if (sin(degrees[i]) <= 0){
                fout << i + 1 << " ";
            }
        }
    }
    return 0;
}
