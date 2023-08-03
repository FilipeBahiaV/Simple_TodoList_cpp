#include <iostream>
#include <list>
#include <cstring> 
#include <memory>
#include <typeinfo>
#include "TodoItem.hpp"






int main() {
    std::list<std::shared_ptr<TodoItem>>TodoList;
    int op = 0;
    std::string phrase;
    std::cout << "------------------------------------" << "\n" << "          TO DO LIST" << "\n" << "YOU CAN VIEW, ADD OR REMOVE TASKS" << "\n" << "------------------------------------" << "\n\n";

    while (op != 5) {
        std::cout << "1             2             3             4            5" << "\n" << "view         add         remove        clear        quit" << "\n""\n""\n";

        std::cin >> op;
        std::cin.ignore();
        std::cout << "\n""\n";

        if (op == 1) {
            for (const auto& it : TodoList) {
                std::cout << it->getId() << " ---- " << it->getText() << std::endl;
            }
            std::cout << "\n""\n";
        }
        else if (op == 2) {
            std::cout << "Enter your task to add:" << "\n";
            std::getline(std::cin, phrase);
            std::cout << "\n""\n";

            auto item = std::make_shared<TodoItem>();
            item->setText(phrase);
            TodoList.push_back(item);
        }
        else if (op == 3) {
            int idx;
            for (const auto& it : TodoList) {
                std::cout << it->getId() << " ---- " << it->getText() << std::endl;
            }
            std::cout << "Choose the id item to remove" << "\n";

            std::cin >> idx;
            std::cout << "\n""\n";

            auto itToRemove = TodoList.end();
            for (auto it = TodoList.begin(); it != TodoList.end(); it++) {
                if ((*it)->getId() == idx) {
                    itToRemove = it;
                    break;
                }

            }
            if (itToRemove != TodoList.end()) {
                TodoList.erase(itToRemove);
            }
            else {
                std::cout << "This item does not exist" << "\n";

            }
        }
        else if (op == 4) {
            TodoList.clear();
            std::cout << "DELETED LIST" << "\n""\n";
        }
        else if (op > 5 || op < 0) {
            std::cout << "This option does not exist" << "\n";
            op = 0;
        }


    }


    return 0;
}