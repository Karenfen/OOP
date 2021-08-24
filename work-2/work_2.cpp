// Author - Kiselev Ilia

#include <iostream>
#include <cstring>

using namespace std;


void devide(){
    static int task = 0;
    cout << "\n|| Task - " << ++task << " ==============================================\n" << endl; 
}

int main (const int argc, const char**argv){
    devide();
{

}
    devide();
{

}
    devide();
{

}
system("pause");
return 0;
}