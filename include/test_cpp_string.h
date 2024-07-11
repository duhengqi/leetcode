#include <iostream>
#include <string>

using namespace std;

void test_cpp_string()
{
    string str1 = "test1";
    string str2(5,'c'); // ccccc
    string str3("test3");
    /*string s(str,stridx) 将字符串str内 始于位置stridx 的部分当作字符串的初值 */
    string str4(str3, 1); // est3
    /* string s(const string& str, size_type pos,strlen) 将字符串str内始于pos且长度顶多strlen的部分作为字符串的初值*/
    string str5(str3,1,3); // est

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
}

