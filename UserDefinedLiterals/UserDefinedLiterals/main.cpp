//
//  main.cpp
//  UserDefinedLiterals
//
//  Created by PinguMac on 2018/9/11.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include <iostream>

using namespace std;

// User Defined Literals
constexpr long double operator "" _mm (long double x) { return x; }
constexpr long double operator "" _cm (long double x) { return x * 10; }
constexpr long double operator "" _m (long double x) { return x * 1000; }

int operator "" _bin (const char* str, size_t l) {
  int ret = 0;
  for (int i = 0; i < l; i++) {
    ret = ret << 1;
    if (str[i] == '1') {
      ret += 1;
    }
  }
  
  return ret;
}

int main(int argc, const char * argv[]) {

  long double height = 5.5_m;
  cout << "height = " << height << " mm" << endl;
  cout << "height + 13 cm = " << (height + 13.0_cm) << " mm" << endl;
  cout << "10 m + 15 mm = " << (10.0_m + 15.0_mm) << " mm" << endl;
  
  cout << "111_bin: " << "111"_bin << endl;
  cout << "10100101_bin: " << "10100101"_bin << endl;
  
  return 0;
}
