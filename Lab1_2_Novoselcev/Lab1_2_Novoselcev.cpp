// Новосельцев 22ВП3 Лабораторная работа №1
//

#include <iostream>
#include "SetLab1_2_Novoselcev.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    NodeSet* A = new NodeSet();
    A->f5(getNum(9, 6, 1), 10, 99, 3);
    NodeSet* B = new NodeSet();
    B->f5(getNum(9, 6, 1), 10, 99, 9);
    std::cout << "Было создано множество А:  " << NodeSet::f7(A->head, "|") << "\n";
    std::cout << "мощность А:  " << A->f6() << "\n";
    std::cout << "Было создано множество B:  " << NodeSet::f7(B->head, "|") << "\n";
    std::cout << "мощность B:  " << B->f6() << "\n";
    std::cout << "А подмножество B:  " << A->f9(B) << "\n";
    std::cout << "А подмножество A:  " << A->f9(A) << "\n";
    std::cout << "А = B:  " << A->f10(B) << "\n";
    std::cout << "А = A:  " << A->f10(A) << "\n";
    std::cout << "А + B:  " << NodeSet::f7(NodeSet::f11(A, B)->head, "|") << "\n";
    std::cout << "мощность А+B:  " << NodeSet::f11(A, B)->f6() << "\n";
    std::cout << "пересечение А и B:  " << NodeSet::f7(NodeSet::f12(A, B)->head, "|") << "\n";
    std::cout << "мощность пересечения А и B:  " << NodeSet::f12(A, B)->f6() << "\n";
    std::cout << "А - B:  " << NodeSet::f7(NodeSet::f13(A, B)->head, "|") << "\n";
    std::cout << "мощность А-B:  " <<NodeSet::f13(A, B)->f6() << "\n";
    std::cout << "B - A:  " << NodeSet::f7(NodeSet::f13(B, A)->head, "|") << "\n";
    std::cout << "мощность  B-A:  " << NodeSet::f13(B, A)->f6() << "\n";
    std::cout << "симметричная разность А и B:  " << NodeSet::f7(NodeSet::f14(A, B)->head, "|") << "\n";
    std::cout << "мощность симметричной разности А+B:  " <<NodeSet::f14(A, B)->f6() << "\n";
}