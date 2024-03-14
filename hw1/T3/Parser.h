#ifndef PARSER_H
#define PARSER_H
#include<map>
#include<string>
#include<vector>
#include<sstream>
class Parser
{
private:
    static const std::string c[10];
    std::vector<std::string> args;
    std::map<std::string, std::string> arg_detail;
    std::map<std::string, int> arg_value;
public:
    void print_usage()
    {
        std::cout << "usage: ./main [--help] ";
        for(int i = 0; i < args.size() ; i++)
        {
            std::cout << "[" << args[i] << " " << c[i] << "] ";
        }
        std::cout << std::endl;
    }
    void print_help()
    {
        print_usage();
        std::cout << std::endl;
        std::cout << "optional arguments:" << std::endl << "--help   show this help message and exit" << std::endl;
        for(int i = 0; i < args.size(); i++)
        {
            std::cout << args[i] << " " << c[i] << "   " << arg_detail[args[i]] << std::endl;
        }
        exit(0);
    }
    void add_argument(std::string name, int dft, std::string detail)
    {
        args.push_back(name);
        arg_value[name] = dft;
        arg_detail[name] = detail;
    }
    void unrecognized_arguments(std::string x)
    {
        print_usage();
        std::cout << "./main: error: unrecognized arguments: " << x << std::endl;
        exit(0);
    }
    void invalid_int_value(std::string arg, std::string val)
    {
        print_usage();
        std::cout << "./main: error: argument " << arg << ": invalid int value: '" << val << "'" << std::endl;
        exit(0);
    }
    void expected_an_argument(std::string arg)
    {
        print_usage();
        std::cout << "./main: error: argument " << arg << ": expected an argument" << std::endl;
        exit(0);
    }
    void init(char * a)
    {
        std::string x = a;
        std::istringstream iss(x);
        std::vector<std::string> v;
        std::string tmp;
        while(iss >> tmp) v.push_back(tmp);
        for(auto & it : v) if(it == "--help") print_help();
        std::string lst = "";
        for(auto & it : v)
        {
            if(arg_detail.find(it) != arg_detail.end() && lst == "")
            {
                lst = it;
                continue;
            }
            else
            {
                if(lst == "")
                {
                    unrecognized_arguments(it); // unrecognized arguments
                    break;
                }
                bool is_int = 1;
                for(auto & j : it) if(!(j >= '0' && j <= '9')) {is_int = 0; break;}
                if(is_int)
                {
                    int n = std::stoi(it);
                    arg_value[lst] = n;
                    lst = "";
                    continue;
                }
                else
                {
                    invalid_int_value(lst, it); // invalid int value
                    break;
                }
            }
        }
        if(lst != "")
        {
            expected_an_argument(lst);// expected an argument
        }
    }
    int get_argument(std::string x)
    {
        x = "--" + x;
        return arg_value[x];
    }

};
const std::string Parser::c[10] = {"FIRST", "SECOND", "THIRD", "FOURTH", "FIFTH", "SIXTH", "SEVENTH", "EIGHTH", "NINTH", "TENTH"};
#endif