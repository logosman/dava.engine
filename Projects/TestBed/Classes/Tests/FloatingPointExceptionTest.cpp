/*==================================================================================
Copyright (c) 2008, binaryzebra
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the binaryzebra nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE binaryzebra AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL binaryzebra BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=====================================================================================*/


#include "Tests/FloatingPointExceptionTest.h"

#include <numeric>

FloatingPointExceptionTest::FloatingPointExceptionTest ()
    : BaseScreen("FloatingPointExceptionTest")
{
}

void DoFloatingPointException(DAVA::BaseObject*, void*, void*)
{
    DAVA::Logger::Debug("start floating point test");
    
    DAVA::float32 max_value = std::numeric_limits<float>::max();
    DAVA::float32 min_value = std::numeric_limits<float>::min();
    DAVA::float32 inf = std::numeric_limits<float>::infinity();
    try
    {
        DAVA::float32 value = max_value / 0.f;
        DAVA::Logger::Debug("value: max_value / 0.f == %f", value);
    } catch (std::exception& ex)
    {
        DAVA::Logger::Debug("catch floating point exception: %s", ex.what());
    }

    try
    {
        DAVA::float32 value = max_value * max_value;
        DAVA::Logger::Debug("value: max_value * max_value == %f", value);
    }
    catch (std::exception& ex)
    {
        DAVA::Logger::Debug("catch floating point exception: %s", ex.what());
    }

    try
    {
        DAVA::float32 value = min_value / max_value;
        DAVA::Logger::Debug("value: min_value / max_value == %f", value);
    }
    catch (std::exception& ex)
    {
        DAVA::Logger::Debug("catch floating point exception: %s", ex.what());
    }

    try
    {
        DAVA::float32 value = inf * 0.f;
        DAVA::Logger::Debug("value: inf * 0.f == %f", value);
    }
    catch (std::exception& ex)
    {
        DAVA::Logger::Debug("catch floating point exception: %s", ex.what());
    }

    DAVA::Logger::Debug("finish floating point test");
}

void FloatingPointExceptionTest::LoadResources()
{
    BaseScreen::LoadResources();
    
    DAVA::ScopedPtr<DAVA::FTFont> font(DAVA::FTFont::Create("~res:/Fonts/korinna.ttf"));

    DAVA::UIButton* resetButton = new DAVA::UIButton(DAVA::Rect(420, 30, 200, 30));
    resetButton->SetDebugDraw(true);
    resetButton->SetStateFont(0xFF, font);
    resetButton->SetStateFontColor(0xFF, DAVA::Color::White);
    resetButton->SetStateText(0xFF, L"Generate Floating point exception");
    resetButton->AddEvent(DAVA::UIButton::EVENT_TOUCH_DOWN, DAVA::Message(&DoFloatingPointException));
    AddControl(resetButton);

}

void FloatingPointExceptionTest::UnloadResources()
{
    BaseScreen::UnloadResources();
    //TODO: Release resources here
}

