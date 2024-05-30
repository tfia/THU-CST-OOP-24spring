#include <iostream>
#include <string>
#include <regex>

using namespace std;

regex get_username("\"username\"\\s*:\\s*\"(.*?)\"");
regex get_password("\"password\"\\s*:\\s*\"(.*?)\"");
regex get_email("\"email\"\\s*:\\s*\"(.*?)\"");
regex check_username("^[a-zA-Z]{1}[a-zA-Z0-9_]{3,14}$");
regex check_password("^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9]{8,20}$");\
regex check_email("^[\\w]+@[\\w.]+$");


int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    string s;
    string username, password, email;
    getline(cin, s);
    smatch m_username, m_password, m_email;
    if(regex_search(s, m_username, get_username)) username = m_username[1];
    if(regex_search(s, m_password, get_password)) password = m_password[1];
    if(regex_search(s, m_email, get_email)) email = m_email[1];
    // cout << regex_match(username, check_username) << regex_match(password, check_password) << regex_match(email, check_email);
    if(regex_match(username, check_username) && regex_match(password, check_password) && regex_match(email, check_email))
    {
        cout << "Successfully registered." << endl;
        cout << "username: ";
        for(int i = 0; i < (int)username.size(); i++)
        {
            if(i >= 0 && i <= 2) cout << username[i];
            else cout << "*";
        }
        cout << endl;
        cout << "password: ";
        for(int i = 0; i < (int)password.size(); i++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "email: ";
        for(int i = 0; i < (int)email.size(); i++)
        {
            if(email[i] != '@' && email[i] != '.') cout << "*";
            else cout << email[i];
        }
        cout << endl;
    }
    else
    {
        cout << "Illegal ";
        bool flag = 0;
        if(!regex_match(username, check_username))
        {
            if(flag) cout << ",";
            flag = 1;
            cout << "username";
        }
        if(!regex_match(password, check_password))
        {
            if(flag) cout << ",";
            flag = 1;
            cout << "password";
        }
        if(!regex_match(email, check_email))
        {
            if(flag) cout << ",";
            flag = 1;
            cout << "email";
        }
    }
    return 0;
}