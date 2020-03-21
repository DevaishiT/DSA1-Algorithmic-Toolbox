#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // vect contains A B and all the stops in between
    vector<int> vect;
    vect.push_back(0);
    for(int i = 0; i < stops.size(); i++)
    	vect.push_back(stops[i]);
    vect.push_back(dist);
    // for(int i=0; i < vect.size(); i++)
    // 	cout<<vect[i]<<endl;
    int n = vect.size();
    int current = 0;
    int numstops = 0;

    while(current < n)
    {
    	//cout<<"HERE  "<<current<<endl;
    	if(current == n-1) return numstops - 1;
    	int temp = current;
    	while (temp < n && vect[temp] - vect[current] <= tank)
    		temp++;
    	temp--;
    	if (temp == current && temp != n-1) return -1;
    	current = temp;
    	numstops++;
    }
    //cout<<current<<endl;
    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}



