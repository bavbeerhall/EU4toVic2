/*Copyright (c) 2019 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include "gtest/gtest.h"
#include "../EU4toV2/Source/EU4World/Modifiers/Modifiers.h"
#include <sstream>



TEST(EU4World_ModifiersTests, nonExistentModifierReturnsNullopt)
{
	std::stringstream input;
	EU4::Modifiers theModifiers(input);

	ASSERT_FALSE(theModifiers.getModifier("nonModifier"));
}


TEST(EU4World_ModifiersTests, modifierIsReturned)
{
	std::stringstream input;
	input << "testModifier = {\n";
	input << "\teffect = 100\n";
	input << "}";
	input << "testModifier2 = {\n";
	input << "\teffect = 200\n";
	input << "}";
	EU4::Modifiers theModifiers(input);

	ASSERT_EQ(theModifiers.getModifier("testModifier")->getEffectAmount("effect"), 100);
	ASSERT_EQ(theModifiers.getModifier("testModifier2")->getEffectAmount("effect"), 200);
}