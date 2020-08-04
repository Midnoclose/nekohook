
/*
 * Nekohook: Free, fast and modular cheat software
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <vector>

#include "../framework/game.hpp"
#include "../util/catvars.hpp"
#include "../util/chrono.hpp"
#include "../util/iohelper.hpp"
#include "../util/logging.hpp"

#include "spam.hpp"

namespace features::spam {

const static CatEnum spam_menu({"Spam"});
static CatEnum spam_type_enum({"OFF", "NEKOHOOK", "CATHOOK", "LMAOBOX",
                               "LITHIUM", "NULLCORE", "BLANK", "CUSTOM"});
static CatVarEnum spam_type(spam_menu, spam_type_enum, "spam", 0, "Spam",
                            "Choose your type of spam!");
static CatVarBool spam_random(spam_menu, "spam_random", true, "Spam Random",
                              "Randomly use a line to spam!");
static CatVarString spam_file(spam_menu, "spam_file", "default.txt",
                              "Spam File",
                              "Put in a file to use with custom spam");
static CatVarFloat spam_time(spam_menu, "spam_time", 1.2, "Spam Time",
                             "Time to wait between each spam!");
static CatVarInt spam_newline(spam_menu, "spam_newlines", 0, "Spam Time",
                              "Time to wait between each spam!");

const static std::vector<std::string> nekohook_spam({
    // Onee-chan's
    "Nekohook - Did I mention that I run arch!",
    "Nekohook - Only real gamers use linux!",
    "Nekohook - the only true multi-hack!",
    "Nekohook - supporting over 3 games!",  // Team Fortress 2, Fistful of
                                            // frags, and CSGO!
    "Nekohook - did I say cheat, I meant *cough* Training software.",
    "Nekohook - using boost to BOOST your gaming skills!",  // Added during
                                                            // boost update :D
    "Nekohook - Get it at https://github.com/oneechanhax/nekohook",  // Why not
                                                                     // advertise
                                                                     // while
                                                                     // were at
                                                                     // it!
    "Nekohook - Get it at https://github.com/oneechanhax/nekohook",
    // Credits to Nopey Nopey
    "Nekohook - Minecraft W10 Edition Support coming soon!",
    "Nekohook - The father is not the son",
    "Nekohook - I crashed GDB. Do I get a cookie?", "Nekohook - my cheat works",
    "Nekohook - :thk:"

    // More?
});
const static std::vector<std::string> cathook_spam(
    {"cathook - more fun than a ball of yarn!", "GNU/Linux is the best OS!",
     "visit youtube.com/c/nullifiedcat for more information!",
     "cathook - free tf2 cheat!", "cathook - ca(n)t stop me meow!"});
const static std::vector<std::string> lmaobox_spam(
    {"GET GOOD, GET LMAOBOX!", "LMAOBOX - WAY TO THE TOP",
     "WWW.LMAOBOX.NET - BEST FREE TF2 HACK!"});
const static std::vector<std::string> lithium_spam(
    {"CHECK OUT www.YouTube.com/c/DurRud FOR MORE INFORMATION!",
     "PWNING AIMBOTS WITH OP ANTI-AIMS SINCE 2015 - LITHIUMCHEAT",
     "STOP GETTING MAD AND STABILIZE YOUR MOOD WITH LITHIUMCHEAT!",
     "SAVE YOUR MONEY AND GET LITHIUMCHEAT! IT IS FREE!",
     "GOT ROLLED BY LITHIUM? HEY, THAT MEANS IT'S TIME TO GET LITHIUMCHEAT!!"});
const static std::vector<std::string> nullcrap_spam(
    {"NULL CORE - REDUCE YOUR RISK OF BEING OWNED!",
     "NULL CORE - WAY TO THE TOP!", "NULL CORE - BEST TF2 CHEAT!",
     "NULL CORE - NOW WITH BLACKJACK AND HOOKERS!",
     "NULL CORE - BUTTHURT IN 10 SECONDS FLAT!",
     "NULL CORE - WHOLE SERVER OBSERVING!", "NULL CORE - GET BACK TO PWNING!",
     "NULL CORE - WHEN PVP IS TOO HARDCORE!",
     "NULL CORE - CAN CAUSE KIDS TO RAGE!",
     "NULL CORE - F2P NOOBS WILL BE 100% NERFED!"});
const static std::vector<std::string> blank_spam({"\x0F"});

static std::vector<std::string> custom_spam;

// This is a cat command so you can forcibly reload it
static CatCommand spam_reload("spam_reload",
                              [](const std::vector<std::string_view>&) {
                                  custom_spam = io::ReadFile(
                                      io::GetSaveLocation() / "spam" /
                                      (std::string)spam_file);
                                  debug_log.Puts("Reloaded Custom Spam!");
                              });

static CatCommand spam_add("spam_add",
                           [](const std::vector<std::string_view>& args) {
                               if (args.empty()) {
                                   debug_log.Puts(
                                       "Nothing to add to custom spam!");
                                   return;
                               }
                               custom_spam.push_back(std::string(args[0]));
                               debug_log.Fmt("Added \"%.*s\" to custom spam!",
                                             args[0].size(), args[0].data());
                           });

static CatCommand spam_remove(
    "spam_remove", [](const std::vector<std::string_view>& args) {
        if (args.empty()) {
            debug_log.Puts("Nothing to remove from custom spam!");
            return;
        }

        auto find = std::find(custom_spam.begin(), custom_spam.end(), args[0]);
        if (find != custom_spam.end()) {
            custom_spam.erase(find);
            debug_log.Fmt("Removed 1 instance of \"%.*s\" from custom spam!",
                          args[0].size(), args[0].data());
        } else {
            debug_log.Fmt("Couldnt find \"%s\" in custom spam!", args[0].size(),
                          args[0].data());
        }
    });

static std::string GetSpamString() {
    // First we need to get the type of spam
    const std::vector<std::string>* spam_group = nullptr;
    switch (spam_type) {
        case 1:
            spam_group = &nekohook_spam;
            break;
        case 2:
            spam_group = &cathook_spam;
            break;
        case 3:
            spam_group = &lmaobox_spam;
            break;
        case 4:
            spam_group = &lithium_spam;
            break;
        case 5:
            spam_group = &nullcrap_spam;
            break;
        case 6:
            spam_group = &blank_spam;
            break;
        case 7: {  //  Custom
            spam_group = &custom_spam;
            // Here we make sure the custom spam is updated and that we have
            // something
            static std::string last_string = spam_file;
            if (last_string != (std::string)spam_file || custom_spam.empty()) {
                spam_reload({});
                last_string = spam_file;
            }
            if (custom_spam.empty()) return std::string();
        }
    }

    // Spam number
    static size_t last_spam = 0;  // last line spammed
    last_spam++;
    if (last_spam >= spam_group->size())  // clamp around
        last_spam = 0;

    // Get our string
    auto spam_string =
        spam_group->at(spam_random ? (rand() % spam_group->size()) : last_spam);

    // Add newlines if needed
    if (spam_newline) {
        std::string tmp;
        tmp.append(spam_newline, '\n');
        spam_string = tmp + spam_string;
    }

    return spam_string;
}

// Externed, please set in your module to enable chat spam features
cat::Function<void(const std::string&)> SayChat;

// TODO, thread
static void SpamLoop() {
    if (!spam_type || !spam_time || !game::GetInGame()) return;

    // Check if its time to spam
    static CatTimer last_spam;
    if (last_spam.ResetAfter(std::chrono::seconds(spam_time))) {
        auto spam_string = GetSpamString();
        if (spam_string.empty()) return;

        SayChat(spam_string.c_str());
    }
}

void Init() { events::world.Listen(SpamLoop); }

}  // namespace features::spam
