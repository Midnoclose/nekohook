
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

#include "ui/settings/enum.hpp"
#include "ui/settings/bool.hpp"
#include "util/chrono.hpp"

#include "spam.hpp"

namespace nekohook::features::spam {

namespace stng {
using namespace setting;
const static TreeMap menu({"Spam"});

static StrEnum type_enum({
    "OFF", "NEKOHOOK", "CATHOOK", "LMAOBOX", "LITHIUM", "NULLCORE", "BLANK", "CUSTOM"
});
static Enum type(menu, type_enum, "Spam", 0);
static Bool random(menu, "Random", true);
static Path spam_file(menu, "File", "default.txt");
static Float spam_time(menu, "Speed", 1.2, "Spam Time");
static Int spam_newline(menu, "Newlines", 0);
}

namespace texts {

using StrEnum = std::initializer_list<std::string_view>;
const static StrEnum nekohook = {
    // Onee-chan's
    "Nekohook - Did I mention that I run arch!",
    "Nekohook - Only real gamers use linux!",
    "Nekohook - the only true multi-hack!",
    "Nekohook - did I say cheat, I meant *cough* Training software.",
    "Nekohook - Get it at https://github.com/oneechanhax/nekohook",  
    "Nekohook - Get it at https://github.com/oneechanhax/nekohook",
    // Credits to Nopey Nopey
    "Nekohook - Minecraft W10 Edition Support coming soon!",
    "Nekohook - The father is not the son",
    "Nekohook - I crashed GDB. Do I get a cookie?", "Nekohook - my cheat works",
    "Nekohook - :thk:"
    // More?
};
const static StrEnum cathook = {
    "cathook - more fun than a ball of yarn!", "GNU/Linux is the best OS!",
    "visit youtube.com/c/nullifiedcat for more information!",
    "cathook - free tf2 cheat!", "cathook - ca(n)t stop me meow!"
};
const static StrEnum lmaobox_spam = {
    "GET GOOD, GET LMAOBOX!", 
    "LMAOBOX - WAY TO THE TOP",
    "WWW.LMAOBOX.NET - BEST FREE TF2 HACK!"
};
const static StrEnum lithium_spam = {
    "CHECK OUT www.YouTube.com/c/DurRud FOR MORE INFORMATION!",
    "PWNING AIMBOTS WITH OP ANTI-AIMS SINCE 2015 - LITHIUMCHEAT",
    "STOP GETTING MAD AND STABILIZE YOUR MOOD WITH LITHIUMCHEAT!",
    "SAVE YOUR MONEY AND GET LITHIUMCHEAT! IT IS FREE!",
    "GOT ROLLED BY LITHIUM? HEY, THAT MEANS IT'S TIME TO GET LITHIUMCHEAT!!"
};
const static StrEnum nullcrap_spam = {
    "NULL CORE - REDUCE YOUR RISK OF BEING OWNED!",
    "NULL CORE - WAY TO THE TOP!", "NULL CORE - BEST TF2 CHEAT!",
    "NULL CORE - NOW WITH BLACKJACK AND HOOKERS!",
    "NULL CORE - BUTTHURT IN 10 SECONDS FLAT!",
    "NULL CORE - WHOLE SERVER OBSERVING!", "NULL CORE - GET BACK TO PWNING!",
    "NULL CORE - WHEN PVP IS TOO HARDCORE!",
    "NULL CORE - CAN CAUSE KIDS TO RAGE!",
    "NULL CORE - F2P NOOBS WILL BE 100% NERFED!"
};
const static StrEnum blank_spam({"\x0F"});
static std::vector<std::string> custom_spam;

// This is a cat command so you can forcibly reload it
/*static Command spam_reload("spam_reload", [](const Command::Args&) {
    custom_spam = io::ReadFile(nfs::GetSaveLocation() / "spam" / (std::string)spam_file);
    debug_log.Puts("Reloaded Custom Spam!");
});
static CatCommand spam_add("spam_add",[](const Command::Args& args) {
    if (args.empty()) {
        debug_log.Puts("Nothing to add to custom spam!");
        return;
    }
    custom_spam.push_back(std::string(args[0]));
    debug_log.Fmt("Added \"%.*s\" to custom spam!",
    args[0].size(), args[0].data());
});

static CatCommand spam_remove("spam_remove", [](const Command::Args& args) {
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
});*/

static std::size_t last_string = 0;
template<class T>
std::string_view ExtractString(T arr) {
    
    last_string++;
    if (last_string >= arr.size())  // clamp around
        last_string = 0;

    return *(arr.begin() + stng::spam_random ? (rand() % arr.size()) : last_string)
}

static std::string GetSpamString() {
    // First we need to get the type of spam
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
    }
    }

    
    // Get our string
    auto spam_string =
        spam_group->at();

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
