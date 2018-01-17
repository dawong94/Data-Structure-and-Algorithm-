#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::sort;

struct Segment {
  int start, end;
};

struct less_than_key
{
    inline bool operator() (const Segment& struct1, const Segment& struct2)
    {
        return (struct1.end < struct2.end);
    }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  
  int n = segments.size();
  int count = 0;
  int i = 0;
  int point = 0;
  while (i < n) {
      point = segments[i].end;
      count = count+1;
      i = i+1;
      while (point >= segments[i].start && point <= segments[i].end) {
          i = i+1;
          
      }
      points.push_back(point);
      
  }
  //for (size_t i = 0; i < segments.size(); ++i) {
  //  points.push_back(segments[i].start);
  //  points.push_back(segments[i].end);
  //}
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  sort(segments.begin(),segments.end(), less_than_key());
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}



