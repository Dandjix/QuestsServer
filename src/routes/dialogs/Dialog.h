#pragma once
//
// Created by timon on 3/10/26.
//


namespace httplib {
    class Server;
}

namespace Dialog {
    void createRoutes(httplib::Server & server);
};