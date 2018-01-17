#include <iostream>
#include <vector>

using std::vector;

int get_num(vector<int> &a, vector<int> &b, int left, int ave, int right) {
    
    
    int i = left;
    int j= ave+1;
    int k = left;
    int count = 0;
    
    while ( (i <= ave ) && (j <= right)) {
     if (a[i] <= a[j]) {
         k++;
         i++;
         b[k] = a[i];
     
     } else {
         k++;
         j++;
         b[k] = a[j];
     count = count + (ave - i);
     }
     
     
     }
     
     while (i <= ave  ) {
     k++;
     i++;
     b[k] = a[i];
     
     }
     while (j<= right) {
     k++;
     j++;
     b[k] = a[j];
     
     }
     for (i = left; i <= right; i++) {
     a[i] = b[i];
     }
    return count;
}

int get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  int number_of_inversions = 0;
    if (right > left ){
        int ave =  (left + right) / 2;
        number_of_inversions += get_number_of_inversions(a, b, left, ave);
        number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
        //write your code here
        number_of_inversions +=   get_num(a,b,left,ave, right);
    }
  return number_of_inversions;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
