///files inclusion
#include<iostream>
#include<string>
#include "nlohmann/json.hpp"
#include <fstream>
//describing namespace
using Json=nlohmann::json;
//defing class for reading json
class Read{
//used in case of get req.
Json data;
public:
 Read(){
    std::ifstream data_file("data.json");
    data_file >> data;
    std::cout<<"reading from file is done\n";
}
std::string display(int a){
    if(a==1)
    {//for student
    std::string s,name="student";
    for(int i=0;i<(int)data["qunatity"];i++){
        name=name+std::to_string(i);
        s=data[name].dump();
    }

    return(s);
    
    }
    else if(a==2){
        //reading for farmer
        std::string s,name="farmer";
    for(int i=0;i<(int)data["qunatity"];i++){
        name=name+std::to_string(i);
        s=data[name].dump();
    }
        return(s);
    }
    else{
        std::string s=data.dump();
        return(s);
    }
}
};
class Write{
//used in case of post req.

};