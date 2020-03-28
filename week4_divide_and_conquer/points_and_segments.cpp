#include <bits/stdc++.h>

using namespace std;

void rec_binary_search(const vector<pair<int,int>> &a, int *count, int x, int left, int right) 
{
  //cout<<"y"<<endl;
  if(right >= left)
  {
  	int mid = left + (right - left)/2;

  	while(mid + 1 <= right && (a[mid + 1].first == a[mid].first)) mid++;

  	if (x < a[mid].first) rec_binary_search(a, count, x, left, mid - 1);
  	else if (x == a[mid].first)
  	{
  		(*count)++;
  		rec_binary_search(a, count, x, left, mid - 1);
  	}
  	else
  	{
  		if (x <= a[mid].second) (*count)++;
  		rec_binary_search(a, count, x, left, mid - 1);
  		rec_binary_search(a, count, x, mid + 1, right);
  	}
  }
  return;
}

bool comparator(pair<int,int> a, pair<int,int> b)
{
  return ((a.first < b.first)||(a.first == b.first && a.second < b.second));
}

vector<int> fast_count_segments(vector<pair<int,int>> segments, vector<int> points) {
  vector<int> cnt(points.size());
  sort(segments.begin(), segments.end(),comparator);
  
  for(int i = 0; i< points.size(); i++)
  {
    int k = 0;
    for(int j = 0; j < segments.size(); j++)
    {
      if (points[i]>=segments[j].first && points[i]<=segments[j].second) k++;
      else if (points[i] < segments[j].first) j = segments.size();
    }
    cnt[i] = k;
  }

  /*for(int i = 0; i < points.size(); i++)
  {
    int left = 0, right = (int)segments.size() - 1;
    rec_binary_search(segments, &cnt[i], points[i], left, right);
  }*/
  return cnt;
}

vector<int> naive_count_segments(vector<pair<int,int>> segments, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < segments.size(); j++) {
      cnt[i] += segments[j].first <= points[i] && points[i] <= segments[j].second;
    }
  }
  return cnt;
}

void test_solution()
{
	int i = 0;
	while(i++ < 100)
	{
		int n = rand()%10;
		int m = rand()%5;
		vector<pair<int,int>> v(n);
		vector<int> p(m);
		for(int i=0; i<n; i++) 
		{
			v[i].first = rand()%20 - 10;
			v[i].second = rand()%20 - 10;
			if (v[i].first > v[i].second) swap(v[i].first, v[i].second);
		}
		for(int i=0; i<m; i++)  p[i] = rand()%20 - 10;
		vector<int> a = naive_count_segments(v,p);
		vector<int> b = fast_count_segments(v,p);
		
		for(int i=0; i<m; i++)
		{
			if (a[i] != b[i])
			{
				cout<<n<<"  "<<m<<endl;
				for(int i=0; i<n;i++) cout<<v[i].first<<" , "<<v[i].second<<endl;
				for(int i=0; i<m;i++) cout<<p[i]<<"  ";
				cout<<endl;
				cout<<"test = "<<endl;
				for(int i=0; i<m; i++) cout<<a[i]<<"  ";
				cout<<endl;
				cout<<"our = "<<endl;
				for(int i=0; i<m; i++) cout<<b[i]<<"  ";
				cout<<endl;
				
				return;
			}
		}
	}
	return;	
}

int main() {

  // srand(time(NULL));
  // test_solution();

  int n, m;
  std::cin >> n >> m;
  vector<pair<int,int>> segments(n);
  for (size_t i = 0; i < segments.size(); i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(segments, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  return 0;
}
