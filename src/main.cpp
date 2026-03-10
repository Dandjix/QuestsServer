#include "httplib.h"
#include "routes/dialogs/Dialog.h"

int main(int argc, char *argv[]) {
  // HTTP
  httplib::Server svr;

  Dialog::createRoutes(svr);

  if (!svr.listen("127.0.0.1", 8080)) {
    std::cerr << "Failed to start server on port 8080" << std::endl;
    return 1;
  }
}
