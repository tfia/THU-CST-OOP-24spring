#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <map>
#include <set>

template<class T>
class Data
{
protected:
public:
    Data<T>* data;
    int length, cnt, type;
    // type 1 := pushback, type 2 := set
    Data(int _length, Data<T>* data = nullptr, int cnt = 0, int type = 0) 
        : length(_length), data(data), cnt(cnt), type(type) {}
    virtual const T& get(int index) = 0;
    virtual Data<T>* undo() = 0;
    virtual ~Data() {}
};

template<class T>
class DataEmpty : public Data<T>
{
public:
    DataEmpty<T>(): Data<T>(0)
    {
        this->data = this;
    }
    const T& get(int index) {
        assert(0); // No data in DataEmpty
    }
    Data<T>* undo() override
    {
        std::cout << "cannot undo" << std::endl;
        return this;
    }
    ~DataEmpty<T>() {}
};

template<class T>
class DataPushBackDecorator : public Data<T>
{
public:
    T value;
    DataPushBackDecorator<T>(Data<T>* data, T value) 
        : value(value), Data<T>(data->length + 1, data, 0, 1) {}
    const T & get(int index)
    {
        if(index == this->length - 1) return value;
        return this->data->get(index);
    }
    Data<T>* undo() override
    {
        return this->data;
    }
    ~DataPushBackDecorator() {}
    // Implement a Decorator for push_back operation
};

template<class T>
class DataSetDecorator : public Data<T>
{
public:
    T value;
    int index;
    DataSetDecorator<T>(Data<T>* data, int index, T value)
        : index(index), value(value), Data<T>(data->length, data, 0, 2) {}
    const T & get(int _index)
    {
        if(_index == this->index) return value;
        return this->data->get(_index);
    }
    Data<T>* undo() override
    {
        return this->data;
    }
    ~DataSetDecorator() {}
    // Implement a Decorator for set operation
};

template<typename T>
class DataUpdateDecorator : public Data<T>
{
public:

};

template<class T>
class PVector
{
public:
    Data<T>* data;
    PVector<T>() {
        data = new DataEmpty<T>();
        data->cnt++;
        // when to delete??
    }
    PVector<T>(Data<T>* _data): data(_data)
    {
        data->cnt++;
    }
    PVector<T> push_back(const T &value) const{
        return PVector<T>(new DataPushBackDecorator<T>(data, value));
    }
    PVector<T> set(int index, const T &value) const{
        return PVector<T>(new DataSetDecorator<T>(data, index, value));
    }
    PVector<T> undo()
    {
        return PVector<T>(data->undo());
    }
    const T& operator[](int index){
        return data->get(index);
    }
    friend std::ostream& operator<<(std::ostream & os, PVector<T> & p) {
        os << '[';
        for (int i = 0; i < p.data->length - 1; i++) os << p.data->get(i) << ", ";
        if (p.data->length) os << p.data->get(p.data->length - 1);
        os << ']';
        return os;
    }
    ~PVector<T>()
    {
        if(!--data->cnt) delete data;
    }
};
