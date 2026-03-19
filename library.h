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
            std::cout << "Библиотека пуста." << std::endl;
            return;
        }

        std::cout << "\n--- Список книг  ---\n";
        std::cout << "№п/п\tАвтор\t\tНазвание\t\tГод\n";
        std::cout << "-------------------------------------------------------------\n";

        for (const auto& book : books)
            book->Print();
    }

    void DeleteIndex(int index) 
    {
        index--;
        if (index < 0)
        {
            std::cout << "Неверно введен номер книги\n";
            return;
        }

        delete books[index];
        books.erase(books.begin() + index);
        std::cout << "Книга удалена!\n";
    }
};

