#include<bits/stdc++.h>
#include "solve_dlazaw.hpp"

using namespace std;
using namespace Solve;

const int N = 101, LIMIT = 10000;
using vb = vector<bitset<N> >;

int n, sub;
int sum;
vb dobre;
int x, y;

function<void(int, string)>  end_prog = {};

int points() {
	int q = sum;
    vector<double> pts = {100.0, 100.0, 92.0, 50.0, 15.0};
    vector<int> quer = {0, 305, 400, 1000, LIMIT};

    if (q > quer.back()) 
        return 0;

    for (int i = 0; i < 4; ++i) {
        if (q >= quer[i] && q <= quer[i + 1]) {
            double ratio = double(quer[i + 1] - q) / (quer[i + 1] - quer[i]);
            return round(pts[i + 1] + (pts[i] - pts[i + 1]) * ratio);
        }
    }

    return 0;
}


int count(vb b){
	int res = 0;
	for(auto bb : b){
		res += bb.count();
	}
	return res;
}

bool ask(vector<int> V){
	bool isx = 0, isy = 0;
	for(int i : V){
		isx |= (i == x);
		isy |= (i == y);
	}
	return isx && isy;
}

void ans(int xx, int yy){
	if(xx > yy)swap(xx, yy);
	if(xx != x || yy != y){
		end_prog(0, "Odpowiedź: [" + to_string(xx) + ", "
			+ to_string(yy) + "] nie jest poprawna, n = " + to_string(n));
	}
}


int main(int argc, char** argv) {
    auto& I = Interactor::create(argc, argv);
	
	end_prog = [&] (int score, const std::string& msg) {
        I.end(score, msg);
    };
	
	auto& input = I.test_reader();
    input >> n >> sub;
	input >> x >> y;

	I.writer(0) << n << " " << sub << endl;
	while(true){
       	char c;
        I.reader(0) >> c;
		if(c == '?'){
			int k;
			I.reader(0) >> k;
			sum += k;
			if(k == 0){
        		end_prog(0, "Pytanie o zbiór pusty");
			}
			if(sum > LIMIT){
        		end_prog(0, "Limit " + to_string(LIMIT) + " na sumę rozmiarów zbiorów z zapytań został przekroczony");

			}
			vector<int> V(k);
			for(int &i : V){
				I.reader(0) >> i;				
			}
			I.writer(0) << (vector{"NIE", "TAK"}[ask(V)]) << endl;
        }
        else if(c == '!'){
			int x, y;
			I.reader(0) >> x >> y;
			ans(x, y);
			end_prog(points(), "OK, suma długości: " + to_string(sum));
        }
        else{
        	end_prog(0, "Oczekiwano ?, ^ lub !, otrzymano " + c);
        }
    }

	return 0;
}