#include <iostream>
#include <ctime>
#include <mysql.h>


class Crud{
    public:
        char *user;
        char *host;
        int port;
        char *database;
        Crud(std::string user,
             std::string password,
             int port,
             std::string database
             );

        //setters
        void setPassword(std::string password);

        // methods
        void connectMySQL();
        void selectAll(std::string query, std::string parameters = "");

    private:
        const char *password;

        // methods

};


Crud::Crud(std::string user, std::string password, int port, std::string database) {
    // default constructor
}

bool Crud::connectMySQL()
{
    std::cout << "OI";
    static unsigned int opt_flag = 0; // status da conexao
    static char* opt_socket_name = NULL;
    MYSQL     *conn;                  // ponteiro para conexao
    MYSQL_RES *response;              // ponteiro para response
    MYSQL_ROW row;                    // linhas
    setlocale(LC_ALL, "English");
    conn = mysql_init(NULL);

    // conectando
    auto retorno = mysql_real_connect(conn,
                       this->host,
                       this->user,
                       this->password,
                       this->database,
                       this->port,
                       opt_socket_name,
                       opt_flag);
    if(retorno){
        std::cout << "retorno";
        return true;
    }else{
        std::cout << "not retorno";
        return false;
    }

}

void Crud::selectAll(std::string query, std::string parameters)
{
    std::cout << 0;
}


auto getLocalTime_()
{
    auto now = reinterpret_cast<time_t>(time(0));
    time_t tm = reinterpret_cast<time_t>(localtime(&now));
    return ctime( &tm);
}


int main()
{
    std::string host = "127.0.0.1";
    std::string user = "root";
    std::string password = "";
    std::string database = "users_cpp";
    int port = 3306;

    std::cout << "OI";
    //Crud *crud = new Crud(user,password, port,host);
    std::cout << "OI";
    //crud->connect_with_database();
    //crud->selectAll("SELECT * FROM Users;");
    getLocalTime_();
    return 0 ;
}

