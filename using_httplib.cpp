//all inclusions
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
//for routing and http get requests
#include "C:\Users\Admin\Downloads\cpp-httplib-master\cpp-httplib-master\httplib.h"
#include<iostream>
#include "nlohmann/json.hpp"//for handeling json data
#include "./reading.hpp"//for read-write of data
int main(){

    httplib::Server svr;
    int port=8080;
//check if server is runing
Read R_data;

std::cout<<"i am running on"<<port<<"\n";
//Routing related for reqiured response
svr.Get("/students", [&](const httplib::Request &, httplib::Response &res) {

  std::cout<<"server is getting a req\n";
  res.set_content(R_data.display(1), "application/json");
  std::cout<<"response is over\n";
});
svr.Get("/farmers", [&](const httplib::Request &, httplib::Response &res) {

  std::cout<<"server is getting a req\n";
  res.set_content(R_data.display(2), "application/json");
  std::cout<<"response is over\n";
});
//listenting statement
svr.listen("localhost",port);

return(0);
}


