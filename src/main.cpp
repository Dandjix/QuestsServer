#include "httplib.h"
#include "routes/dialogs/Dialog.h"

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

    // HTTP
    httplib::Server svr;

    Dialog::createRoutes(svr);

    std::cout << std::format("Server is starting at address {}, port {} ...", address, port) << std::endl;
    if (!svr.listen(address, port)) {
        std::cerr << "Failed to start server on address :[" << address << "], port : [" << port <<"]" << std::endl;
        return 1;
    }
}
