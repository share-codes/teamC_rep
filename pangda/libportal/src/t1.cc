#include<portal/crypt.h>
#include<portal/socket.h>
//#include<portal/multiplexing.h>
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
using namespace libportal;
int main() {
    TCPSocket sock("127.0.0.1", 14001);

    sock.Connect();
    string a;
    cin >> a;
    sock.Write(a);
    string res1;
    sock.Read(res1);
    cout << "[Echo Sever]" << res1 << endl;


    return 0;
}