#include <iostream>
#include <list>
#include <functional>
#include <memory>
#include "window.h"
#include "command.h"
#include "event.h"
using namespace std;

template <typename T>
list<shared_ptr<T>> getLinkedObjects(Window& win) {
    int n;
    cin >> n;
    list<shared_ptr<T>> l;
    while (n--) {
        string s;
        cin >> s;
        l.push_back(dynamic_pointer_cast<T>(win.getPointerByName(s)));
    }
    return l;
}

int main() {
    freopen("test.in", "r", stdin);
    Window win;
    int n;
    cin >> n;
    while (n--) {
        string command;
        cin >> command;

        if (command == "create") {
            string type, name; bool flag;
            cin >> type >> name;

            if (type == "button") flag = win.addElement(make_shared<Button>(name));
            else if (type == "checkbox") flag = win.addElement(make_shared<Checkbox>(name));

            if (flag) cout << name << " has been created successfully.\n";
            else cout << name << " already exists.\n";
        }
        else if (command == "setclick" || command == "setdoubleclick") {
            string name, type;
            cin >> name >> type;

            std::function<void()> fun;
            if (type == "clear")
                fun = ClearAll(getLinkedObjects<Checkbox>(win));
            else if (type == "select")
                fun = SelectAll(getLinkedObjects<Checkbox>(win));
            else if (type == "submit")
                fun = Submit(getLinkedObjects<Checkbox>(win));

            auto& button = dynamic_cast<Button&>(win.getElementByName(name));
            if (command == "setclick")
                button.setClickCommand(fun);
            else
                button.setDoubleClickCommand(fun);
        }
        else if (command == "click") {
            string name;
            cin >> name;
            auto& clickable_widget = dynamic_cast<Click&>(win.getElementByName(name));
            clickable_widget.click();
        }
        else if (command == "doubleclick") {
            string name;
            cin >> name;
            auto& doubleclickable_widget = dynamic_cast<DoubleClick&>(win.getElementByName(name));
            doubleclickable_widget.doubleClick();
        }
        else if (command == "undo") {
            if (!win.undo()) cout << "can't undo\n";
        }
    }

    return 0;
}