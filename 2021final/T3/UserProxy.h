#pragma once
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"
#include "User.h"
#include<iostream>

class UserProxy
{
public:
    RealUser* u;
    EncryptStrategy* e;
    VerificationStrategy* v;
    UserProxy(RealUser* u, EncryptStrategy* e, VerificationStrategy* v) : u(u), e(e), v(v) {}
    void sendMessage(std::string mes)
    {
        std::string s = e->encode(mes);
        u->sendMessage(s);
        std::string vs = v->verify(mes);
        std::cout << vs << std::endl;
    }
};