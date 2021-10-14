// [2017-06-27] Challenge #321 [Easy] Talking Clock
// https://www.reddit.com/r/dailyprogrammer/comments/6jr76h/20170627_challenge_321_easy_talking_clock/
// Suggested language: C++
// Your First C++ Program

#include <iostream>
#include <regex>

std::string hour_to_english(int hour) {
    switch (hour) {
        case 0:
            return "twelve";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        default:
            return "error";
    }
}

std::string minute_to_english(int minute, bool prepend_oh) {
    if (0 < minute && minute < 13) {
        return (prepend_oh ? "oh ": "") + hour_to_english(minute);
    }

    switch (minute) {
        case 0:
            return "";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eightteen";
        case 19:
            return "nineteen";
        case 20:
            return "twenty";
        case 30:
            return "thirty";
        case 40:
            return "forty";
        case 50:
            return "fifty";
        default:
            int mod = minute % 10;
            return minute_to_english(minute - mod, false) + (mod == 0 ? "" : " ") + minute_to_english(mod, false);
    }

}

void say_time(std::string time) {
    std::regex regex("^([0-9]{2}):([0-9]{2})$");
    std::smatch matches;

    if (std::regex_search(time, matches, regex)) {
        std::string hour_string = matches[1].str();
        std::string minute_string = matches[2].str();

        int hour = std::stoi(hour_string);
        int minute = std::stoi(minute_string);

        std::string twelve_hour_suffix = hour < 12 ? "am" : "pm";

        hour = hour % 12;

        std::string minute_english_string = minute_to_english(minute, true);

        std::cout 
            << "It's " 
            << hour_to_english(hour) 
            << ((minute == 0) ? "" : " ")
            << minute_english_string
            << " "
            << twelve_hour_suffix
            << std::endl;

    } else {
        std::cout << "Unexpected input: " << time << std::endl;
    }
}



int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "Usage: ./outDebug.exe (HH:MM) ..." << std::endl;
        return 1;
    }

    for (int i=1; i < argc; i++) {
        say_time(argv[i]);
    }

    return 0;
}
