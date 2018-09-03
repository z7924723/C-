//
//  main.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/24.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include <iostream>
#include <thread>

#include "ThreadExample.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
  
  cout << "Thread ID: " << this_thread::get_id()<< endl;
  
  createThread();
  
  passValueToThread();
  
  threadUsingLambda();
  
  threadsWithTemplates();
  
  threadsWithSTL();
  
  futurePromiseAndAsync();
  
  mutexControl1();
  
//  mutexControl2();
  
  return 0;
}
