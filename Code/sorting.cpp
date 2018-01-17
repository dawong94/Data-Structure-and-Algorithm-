#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>
using std::vector;
using std::swap;

std::pair<int,int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int lt = l;
  int gt = r;
  int i = l+1;
    while (i <= gt){
      if(a[i] < x){
          lt++;
          i++;
          swap(a[i],a[lt]);
      } else if (a[i] > x) {
          gt = gt - 1;
          swap(a[i],gt);
      } else {
          i++;
      }
  }
      
    /*if (a[i] < x && turn == 1) {
      j1++;
      j2++;
      swap(a[i], a[j2]);
      swap(a[j2], a[j1]);
    }
    if (a[i] < x && turn == 0) {
        j1++;
        
        swap(a[i], a[j1]);
        j2++;
    }
    if (a[i] == x){
         j2++;
         swap(a[i],a[j2]);
         turn = 1;
    }
      
  }
  swap(a[l], a[j1]);*/
  //return j1,j2;

      
  return std::make_pair(lt, gt);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m1,m2 = partition2(a, l, r);
  std::pair<int, int> p = partition2(a,l,r);
  randomized_quick_sort(a, l, p.first- 1);
  randomized_quick_sort(a, p.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
    
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
