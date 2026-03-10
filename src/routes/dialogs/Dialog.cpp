//
// Created by timon on 3/10/26.
//

#include "Dialog.h"
#include "httplib.h"

void Dialog::createRoutes(httplib::Server &server) {
    server.Get("/dialog/number",[](const httplib::Request & req, httplib::Response &res) {
        res.set_content("0","text/plain");
    });
}
