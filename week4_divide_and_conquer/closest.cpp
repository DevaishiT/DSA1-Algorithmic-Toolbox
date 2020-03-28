#include <bits/stdc++.h>

using namespace std;

double distance(vector<pair<int,int>> &p, int a, int b)
{
  double t1 = pow(double(p[a].first - p[b].first),2);
  double t2 = pow(double(p[a].second - p[b].second),2);
  return sqrt(t1 + t2);
}

bool comparison( pair<int,int> a, pair<int,int> b)
{
	return (a.second < b.second);
}

double merge(vector<pair<int,int>> p, int left, int mid, int right, double d1, double d2)
{
	double d = min(d1, d2);
	
	vector<pair<int,int>> v;
	for(int i = left; i <= right; i++)
	{
		if (abs(p[mid].first - p[i].first) < d)  v.push_back(p[i]);
	}

	sort(v.begin(), v.end(), comparison);
	double num = DBL_MAX;

	for(int i = 0; i < v.size(); i++) 
		for(int j= i+1; j < v.size() && j <= i+7/*((v[j].second - v[i].second) < d)*/; j++)
	{
		/*if (left==0 && right==8)
		{
			cout<<endl;
			cout<<v[i].first<<" , "<<v[i].second<<endl;
			cout<<v[j].first<<" , "<<v[j].second<<endl;
			cout<<distance(v,j,i)<<endl;
			cout<<endl;
		}*/
		num = min(distance(v,j,i),num);
	}
			
	//if (left==0 && right==8) cout<<d1<<"  "<<d2<<" "<<num<<endl;
	return min(d,num);
}

double rec_minimal_distance(vector<pair<int,int>> p, int left, int right)
{

  double d = DBL_MAX;
  int i=1;
  if (left < right)
  {
  	
  	int mid = left + (right-left)/2;
  	double d1 = rec_minimal_distance(p,left,mid);
  	double d2 = rec_minimal_distance(p,mid+1,right);
  	d = merge(p, left, mid, right,d1,d2);

  }
  return d;
}

double minimal_distance(vector<pair<int,int>> p) 
{
  /*for(int i = 0; i< p.size(); i++) 
  	cout<<p[i].first<<", "<<p[i].second<<endl;*/
  if(p.size() == 0) return 0;
  sort(p.begin(),p.end());
  double ans = rec_minimal_distance(p, 0, p.size()-1);
  return ans;
}

double test_minimal_distance(vector<pair<int,int>> p)
{
	if(p.size() == 0) return 0;
	double num = DBL_MAX;
	for(int i=0; i<p.size();i++)
	{
		for(int j = i+1; j<p.size();j++)
			num = min(distance(p,j,i),num);
	}
	return num;
}

void test_solution()
{
	int i = 0;
	while(i++ < 100)
	{
		int n = rand()%100;
		vector<pair<int,int>> v(n);
		for(int i=0; i<n; i++) 
		{
			v[i].first = rand()%100;
			v[i].second = rand()%100;
		}
		double a = test_minimal_distance(v);
		double b = minimal_distance(v);
		if (a != b)
		{
			cout<<n<<endl;
			for(int i=0; i<n;i++) cout<<v[i].first<<" , "<<v[i].second<<endl;
			cout<<endl;
			cout<<"test = "<<a<<"  our = "<<b<<endl;
			return;
		}
	}
	return;	
}

int main() {

  // srand(time(NULL));
  // test_solution();

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  size_t n;
  std::cin >> n;
  vector<pair<int,int>> p(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> p[i].first >> p[i].second;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(p) << "\n";
  return 0;
}
