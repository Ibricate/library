#pragma once
#include "book.h"
#include <vector>
class library
{
private:
	std::vector<Book*> books;
public:
    ~library()
    {
        for (auto& book : books)
            delete book;
    }

    void Add(Book* book)
    {
        books.push_back(book);
    }

    void AddFromConsole()
    {
        Book* book = new Book();
        try
        {
            book->SetFromConsole();
            books.push_back(book);
        }
        catch (const std::exception& e)
        {
            delete book; 
            std::cout << "Ошибка при добавлении книги: " << e.what() << std::endl;
        }
    }

    void PrintAll() const
    {
        if (books.empty())
        {
            std::cout << "Áèáëèîòåêà ïóñòà." << std::endl;
            return;
        }

        std::cout << "\n--- Ñïèñîê êíèã  ---\n";
        std::cout << "Àâòîð\t\tÍàçâàíèå\t\tÃîä\n";
        std::cout << "----------------------------------------\n";

        for (const auto& book : books)
            book->Print();
    }
};

