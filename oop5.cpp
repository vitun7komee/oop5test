#include "Choice.h"
#include "Bubble.h"
#include <iostream>

enum actions {
    BubbleSort, ChoiceSort, createB, createC, printB, printC, foreachB,foreachC, endsession
};

int main()
{
    bool stop = false;
    int choice;
    std::cout << "enter size :";
    size_t size;
    std::cin >> size;
    Container* mainb;
    Container* mainc;
    mainb = new Bubble(size);
    mainc = new Choice(size);
    double* arrb = new double[size];
    double* arrc = new double[size];
    int z;
    std::cout << " 0 - BubbleSort  1 - ChoiceSort  2 - createB  3 -  createC  " << std::endl;
    std::cout << " 4 - printB  5 - printC  6 - foreachB 7 - foreachC  8 - endsession  " << std::endl;
    while (!stop) {
        std::cout << " Select action : ";
        std::cin >> choice;
        switch (choice) {
        case actions::foreachB:
            std::cout << "foreach b\n";
            for (int i = 0; i < size; i++) { std::cout << mainb->foreach()[i] << "  "; }
            std::cout << std::endl;
            break;
        case actions::foreachC:
            std::cout << "foreach c\n";
            for (int i = 0; i < size; i++) { std::cout << mainc->foreach()[i] << "  "; }
            std::cout << std::endl;
            break;
        case actions::createB:
            std::cout << "random fill(1) or fill in console(2) ?\n";
            int z;
            std::cin >> z;
            if (z == 1) { mainb->randomfill(); }
            else if (z == 2) { 
                std::cout << "enter array elements :\n";
                for (int c = 0;c < size; c++) {
                    std::cin >> arrb[c];
                }
                Bubble b(size, arrb);
                *mainb = b;
            }
            break;
        case actions::createC:
            std::cout << "random fill(1) or fill in console(2) ?\n";
            std::cin >> z;
            if (z == 1) { mainc->randomfill(); }
            else if (z == 2) { 
                std::cout << "enter array elements :\n";
                for (int x = 0; x < size; x++) {
                    std::cin >> arrc[x];
                }
                Choice c(size, arrb);
                *mainb = c;
            }
            break;
        case actions::printB:
            std::cout << "Bubble \n ";
            mainb->print();
            std::cout << std::endl;
            break;
        case actions::printC:
            std::cout << "Choice \n ";
            mainc->print();
            std::cout << std::endl;
            break;
        case actions::BubbleSort:
            mainb->sort();
            std::cout << "bubble sort done\n";
            break;
        case actions::ChoiceSort:
            mainc->sort();
            std::cout << "selection sort done\n";
            break;
        case actions::endsession:
            std::cout << "cya!";
            stop = true;
            break;
        }

    }

}
