#include <dpp/dpp.h>
#include "config.hpp"

#include <iostream>

int main()
{
    const std::string token = aurax::getToken();

    if (token.empty()) {
        std::cerr << "ERROR: DISCORD_TOKEN is missing\n";
        return 1;
    }

    dpp::cluster bot(
        token,
        dpp::i_default_intents
    );

    bot.on_log([](const dpp::log_t& event) {
        if (event.severity >= dpp::ll_warning) {
            std::cout << event.message << '\n';
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_commands>()) {

            bot.global_command_create(
                dpp::slashcommand(
                    "ping",
                    "Check bot latency",
                    bot.me.id
                )
            );

            std::cout << "AuraX Music is online\n";
        }
    });

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {

        const std::string command =
            event.command.get_command_name();

        if (command == "ping") {

            event.reply(
                dpp::message("Pong! AuraX Music is online.")
            );

        }

    });

    bot.start(dpp::st_wait);

    return 0;
}
