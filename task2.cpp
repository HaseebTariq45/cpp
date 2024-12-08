#include<iostream>
#include<fstream>
using namespace std;
int main()
{
     fstream file2;
    file2.open("file2.txt", ios::out);
    file2<<"\"The rose is red.\nThe girl is playing there.\nAn aeroplane is in the sky.\nNumbers are not allowed in the password.\"";

    
}