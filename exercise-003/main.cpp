#include <fmt/chrono.h>
#include <fmt/format.h>

#include "linkedlist.h"

void printer(const std::string &name)
{
    fmt::print("Printer: {}\n", name);
}

auto main(int argc, char **argv) -> int
{
    fmt::print("Hello, {}!\n", "World");

    const std::vector<std::string> names{"Hugo", "Franz", "Elisabeth", "Anton", "Gerhard", "Maria", "Hannelore"};
    const std::vector<std::string> names2{"Ulf", "Ole", "Sepp", "Norton", "Kai", "Uschi", "Gert"};

    {
        LinkedList list;

        fmt::print("------------------------------\n");

        // Fügen Sie die Elemente aus 'names' am Ende der Liste hinzu
        for (auto &name : names)
        {
            auto elem = new LinkedListNode(name);
            list.insert_tail(elem);
        }
        
        list.traverse(printer);

        fmt::print("------------------------------\n");

        // Fügen Sie die Elemente aus 'names2' am Anfang der Liste hinzu
        for (auto &name : names2)
        {
            auto elem = new LinkedListNode(name);
            list.insert_head(elem);
        }

        fmt::print("------------------------------\n");

        // Drucken Sie die Liste erneut aus
        list.traverse(printer);

        fmt::print("------------------------------\n");

        // Anzahl der Elemente in der Liste ausgeben
        fmt::print("Elements in the list: {}\n", list.size());

        fmt::print("------------------------------\n");

        // Die Liste wird erneut gedruckt, um zu überprüfen, ob die Elemente korrekt eingefügt wurden
        list.traverse(printer);
    }

    return 0;
}

