#include <iostream>
#include <math.h>
#include <chrono>
#include <ctime>
#include <thread>
#include <fstream>
#include <iomanip>
#include <atomic>
#include <mutex>
#include <time.h>
#include <string>
using namespace std;
std::mutex g_pages_mutex;                                             //WKJ RATHNAYAKA [20780]
                                                //MAC ADDRESS ::3C-F8-62-5A-E0-6F
                                                //HOST NAME :: Desktop-RATHNAYAKA
void my_details(){
 return;
    cout<<"WKJ RATHNAYAKA [20780]\nHOST Name::";
     system("hostname");
    system("getmac");

    ofstream myfile;
    myfile.open("D:/textfile2.txt",ios::in);
    if(myfile.is_open()){
        myfile<<"WKJ RATHNAYAKA [20780]\nHOST Name:: ";
        myfile<<"Desktop-RATHNAYAKA\n";
        myfile<<"MAC ADDRESS :: 3C-F8-62-5A-E0-6F";
        myfile<<"\n\n";
        myfile.close();
    }
}
void text_file(int co,int n){
    return;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    int sqr=n*n;
    ofstream myfile;
    myfile.open("D:/textfile2.txt",ios::app);
    if(myfile.is_open()){
        myfile <<"COUNT: "<<co<<"     INPUT: "<<n<<"     SQUARE VALUE: ";
        myfile<<sqr<<"       TIME:: "<<std::ctime(&end_time)<<"\n" ;
        myfile.close();
    }else{
        cout<<"file is not open";
    }
}
int sqrrt(int x){
    int ans = x*x;
    return ans;
}
void square(int c)
{
    return;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    int n;
    cout<<"\nEnter input :";
    cin>>n;
    cout<<"COUNT:"<<c<<"  Input:"<<n<<"  SQUARE VALUE:";
    cout<<sqrrt(n)<<"    TIME:"<<std::ctime(&end_time) ;
    thread th3(text_file,c,n);
    th3.join();

}
void timeclapese()
{
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout<<std::ctime(&end_time);

}
void text_out()
{


    string line;

    ifstream myfile;
    myfile.open("D:/textfile.txt",ios::out);
    if(myfile.is_open()){
        while(getline(myfile,line))
        {
            if(line!=""){
            cout<<line<<"     ";
            std::lock_guard<std::mutex> guard(g_pages_mutex);
            cout<<" Current System Time: ";
            timeclapese();
            std::this_thread::sleep_for (std::chrono::seconds(3));
            cout<<"\n";
            }
        }}
}

int main()
{


    thread th1(my_details);
    th1.join();
    int count=1;
    for(count;count<=20;count++){
        thread th2(square,count);
        th2.join();
    }
    thread th4(text_out);
    th4.join();

}


