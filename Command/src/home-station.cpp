#include <iostream>
#include <string>
#include <home-remote-controller.hpp>

int main() {
    using namespace HomeStation;

    std::unique_ptr remote_controller = std::make_unique<RemoteController>();
    std::string command_name;
    while (true) {
        std::cout << "Command: ";
        std::getline(std::cin, command_name);
        if (command_name == "quit")
            break;
        else if (command_name == "help") {
            std::cout << "Available commands:\n";
            for (auto& c : remote_controller->commands())
                std::cout << "* " << c << "\n";
            
            std::cout << "\n";
            continue;
        }

        try {
            remote_controller->get_command(command_name)->execute();
        }
        catch(const std::out_of_range& e) {
            std::cerr << "Unknown command: \"" << command_name << "\"\n";
        }
    }

    return 0;
}
