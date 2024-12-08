#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file1;
    file1.open("file1.txt", ios::out);
    file1<<"Abdullah ibn Mas'ud reported: The messanger of Allah, peace and blessings be upon him, said,\n "<<endl;

    file1<<"Most of the sins of the children of Adam are on their toungue."<<endl;
    file1<<"Ibn Mas'ud said, ''O tongue! Speak godness and be rewarded, or remain silent and be safe, lest\n you become regretful''.\n"<<endl;
    file1<<"Source: al-Mu'jam al-Kabir-10300";
    file1.close();


}