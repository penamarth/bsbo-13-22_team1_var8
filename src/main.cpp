#include "App.h"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "No cmd arg found. Use one of these: [ p, f, r, c ]\n";
        return 1;
    }

    App *app = new App();
    char c = argv[1][0];

    switch (c) {
        case 'c':
            app->open_chat();
            for (int i = 0; i < 2; i++) {
                app->send_message();
                app->get_new_messages();
            }
            break;
        case 'p':
            app->create_advert();
            app->set_advert_info(4, "Bashnya Goyda, Strominka 20");
            app->make_advert_do_smth();
            break;
        case 'f':
        case 'r':
            std::cout << "Not implemented!\n";
            break;
        default:
            std::cerr << "Incorrect cmd arg. Use one of these: [ p, f, r, c ]\n";
            return 1;
    }

    delete app;

    return 0;
}
