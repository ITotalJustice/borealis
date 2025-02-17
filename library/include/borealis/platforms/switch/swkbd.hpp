/*
    Copyright 2019 WerWolv
    Copyright 2019 p-sam

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#pragma once

#include <functional>
#include <string>

namespace brls
{

enum KeyboardKeyDisableBitmask
{
    KEYBOARD_DISABLE_NONE         = 0,
    KEYBOARD_DISABLE_SPACE        = 1,
    KEYBOARD_DISABLE_AT           = 1 << 1,
    KEYBOARD_DISABLE_PERCENT      = 1 << 2,
    KEYBOARD_DISABLE_FORWSLASH    = 1 << 3,
    KEYBOARD_DISABLE_BACKSLASH    = 1 << 4,
    KEYBOARD_DISABLE_NUMBERS      = 1 << 5,
    KEYBOARD_DISABLE_DOWNLOADCODE = 1 << 6,
    KEYBOARD_DISABLE_USERNAME     = 1 << 7,
};

class Swkbd
{
  public:
    static bool openForText(std::function<void(std::string)> f, const std::string& headerText = "", const std::string& subText = "", int maxStringLength = 32, const std::string& initialText = "", int kbdDisableBitmask = KeyboardKeyDisableBitmask::KEYBOARD_DISABLE_NONE);
    static bool openForNumber(std::function<void(long)> f, const std::string& headerText = "", const std::string& subText = "", int maxStringLength = 18, const std::string& initialText = "", const std::string& leftButton = "", const std::string& rightButton = "", int kbdDisableBitmask = KeyboardKeyDisableBitmask::KEYBOARD_DISABLE_NONE);
};

} // namespace brls
