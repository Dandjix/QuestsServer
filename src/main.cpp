#include "imported/httplib.h"

int main(int argc, char *argv[]) {
  // HTTP
  httplib::Server svr;

  svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
    res.set_content("Hello World!", "text/plain");
  });

  if (!svr.listen("127.0.0.1", 8080)) {
    std::cerr << "Failed to start server on port 8080" << std::endl;
    return 1;
  }
}
