/*
    Copyright 2021 XITRIX

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

#include "borealis/views/cells/cell_input.hpp"

#include <borealis/platforms/switch/swkbd.hpp>

#include "borealis/views/dropdown.hpp"

namespace brls
{

InputCell::InputCell()
{
    detail->setTextColor(Application::getTheme()["brls/list/listItem_value_color"]);

    this->registerClickAction([this](View* view) {
        Swkbd::openForText([&](std::string text) {
            this->setValue(text);
        },
            this->title->getFullText(), this->hint, this->maxInputLength, this->value, this->kbdDisableBitmask);

        return true;
    });
}

void InputCell::init(const std::string& title, const std::string& value, Event<std::string>::Callback callback, const std::string& placeholder, const std::string& hint, int maxInputLength, int kbdDisableBitmask)
{
    this->hint  = hint;
    this->value = value;
    this->title->setText(title);
    this->placeholder       = placeholder;
    this->maxInputLength    = maxInputLength;
    this->kbdDisableBitmask = kbdDisableBitmask;
    this->event.subscribe(callback);
    updateUI();
}

void InputCell::setValue(const std::string& value)
{
    this->event.fire(value);
    this->value = value;
    updateUI();
}

void InputCell::setPlaceholder(const std::string& placeholder)
{
    this->placeholder = placeholder;
    updateUI();
}

void InputCell::updateUI()
{
    Theme theme = Application::getTheme();
    if (this->value.empty())
    {
        this->detail->setText(placeholder);
        this->detail->setTextColor(theme["brls/text_disabled"]);
    }
    else
    {
        this->detail->setText(value);
        this->detail->setTextColor(theme["brls/list/listItem_value_color"]);
    }
}

View* InputCell::create()
{
    return new InputCell();
}

InputNumericCell::InputNumericCell()
{
    detail->setTextColor(Application::getTheme()["brls/list/listItem_value_color"]);

    this->registerClickAction([this](View* view) {
        Swkbd::openForNumber([&](long number) {
            this->setValue(number);
        },
            this->title->getFullText(), this->hint, this->maxInputLength, std::to_string(this->value), "", "", this->kbdDisableBitmask);

        return true;
    });
}

void InputNumericCell::init(const std::string& title, long value, Event<long>::Callback callback, const std::string& hint, int maxInputLength, int kbdDisableBitmask)
{
    this->hint  = hint;
    this->value = value;
    this->title->setText(title);
    this->maxInputLength    = maxInputLength;
    this->kbdDisableBitmask = kbdDisableBitmask;
    this->event.subscribe(callback);
    updateUI();
}

void InputNumericCell::setValue(long value)
{
    this->event.fire(value);
    this->value = value;
    updateUI();
}

void InputNumericCell::updateUI()
{
    Theme theme = Application::getTheme();
    this->detail->setText(std::to_string(value));
    this->detail->setTextColor(theme["brls/list/listItem_value_color"]);
}

View* InputNumericCell::create()
{
    return new InputNumericCell();
}

} // namespace brls
