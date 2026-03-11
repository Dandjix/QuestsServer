#include "httplib.h"
#include "routes/dialogs/Dialog.h"

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

int main(int argc, char *argv[]) {
    //two optional arguments : address and port number
    std::string address;
    int port;

    if (argc == 1) {
        address = "localhost";
        port = 8080;
    } else if (argc == 3) {
        address = argv[1];
        port = std::stoi(argv[2]);
    } else {
        throw std::invalid_argument(
            std::format(
                "invalid number of arguments : {} (should be 0 or 2 [address port_number]",
                argc - 1
            ));
    }

    //mongo
    std::cout << "Connecting to MongoDB at mongodb://localhost:27017/ ..." <<std::endl;
    mongocxx::instance instance;
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    std::cout << "Mongo client created" << std::endl;

    // HTTP
    httplib::Server svr;
    Dialog::createRoutes(svr);

    std::cout << std::format("Server is starting at address {}, port {} ...", address, port) << std::endl;
    if (!svr.listen(address, port)) {
        std::cerr << "Failed to start server on address :[" << address << "], port : [" << port <<"]" << std::endl;
        return 1;
    }
}
