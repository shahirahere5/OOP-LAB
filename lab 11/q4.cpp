#include <iostream>
#include <string>
#include <exception>
using namespace std;

class DatabaseException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException{};

template <typename T>
class DatabaseConnector
{
    T db_name;

public:
    DatabaseConnector(T name) : db_name(name) {}

    void connect()
    {
        if (db_name == "invalid_db")
        {
            throw ConnectionFailedException();
        }
        else if (db_name == "slow_db")
        {
            throw DatabaseException();
        }
        else
        {
            cout << "Connected to " << db_name << " successfully." << endl;
        }
    }

    void runQuery(string query)
    {
        if (query == "slow_query")
        {
            throw QueryTimeoutException();
        }
        else
        {
            cout << "Query executed: " << query << endl;
        }
    }
};

int main()
{
    try
    {
        cout << "Attempting to connect to invalid_db..." << endl;
        DatabaseConnector<string> connector1("invalid_db");
        connector1.connect();
    }
    catch (const ConnectionFailedException &e)
    {
        cout << "Caught ConnectionFailedException -  what(): " << e.what() << endl;
    }

    try
    {
        cout << "Attempting to connect to slow_db..." << endl;
        DatabaseConnector<string> connector2("slow_db");
        connector2.connect();
    }
    catch (const DatabaseException &e)
    {
        cout << "Caught a general DatabaseException -  what(): " << e.what() << endl;
    }

    return 0;
}