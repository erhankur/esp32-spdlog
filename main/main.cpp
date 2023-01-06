#include <array>
#include <numeric>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/bin_to_hex.h"

auto main_log = spdlog::stdout_color_mt("main");

extern "C" void app_main(void)
{
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::set_pattern("[%C-%m-%d %H:%M:%S.%e] [%n] [%^%l%$] %v");

    main_log->debug("spdlog on ESP32");

    std::string str{"ESP32"};
    main_log->info("|{:20}|", str);    // |ESP32               |
    main_log->info("|{:<20}|", str);   // |ESP32               |
    main_log->info("|{:_>20}|", str);  // |_______________ESP32|
    main_log->info("|{:_^20}|", str);  // |_______ESP32________|

    std::array<char, 64> a;
    std::iota(a.begin(), a.end(), 1);
    main_log->info("{:s:X}", spdlog::to_hex(a));
}
