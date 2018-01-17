#include <iostream>
#include <vector>
#include <algorithm> 
using std::vector;
using std::min;

void sort_alg(vector<int> &w, vector<int> &v){
  int n = w.size();
  int temp = 0;
  for (int i = 0; i < n; ++i){
    for (int j = i+1; j< n;++j){
      if ( v[i]/(double)w[i] < v[j]/(double)w[j]){
          temp = w[i];
          w[i] = w[j];
          w[j] = temp;

          temp = v[i];
          v[i] = v[j];
          v[j] = temp;

      }
    }

  }
  
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  
  int n = weights.size();
  int items=0;;

  for (int i =0; i < n; ++i) {
       if (capacity == 0) {
          return value;
       }   
       items = min(weights[i], capacity);
       value = value + items* (values[i]/(double) weights[i]);
       weights[i] = weights[i] - items;
       capacity = capacity - items;

  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  sort_alg(weights, values);
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
