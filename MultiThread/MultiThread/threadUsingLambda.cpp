//
//  threadUsingLambda.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/24.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"

void threadUsingLambda() {
  cout << "---threadUsingLambda()---" << endl;
  
  int localVal = 500;
  
  thread t1{[&](){
    cout << "In thread function, thread ID: " << this_thread::get_id() << endl;
    cout << "localVal = " << localVal << endl;
    cout << "localVal = " << ++localVal << endl;
  }};
  
  t1.join();
}
