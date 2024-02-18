#include <rog/action/special/ExamineChapel.h>

#include <rog/ui/textoutput/TextOutput.h>
#include <rog/action/special/LocationEvents.h>
#include <vector>

void ExamineChapel::execute() {
    std::vector<std::string> text;

    text.emplace_back("Dust motes hang lazily in the shafts of colored light stretching across");
    text.emplace_back("the chapel from peaked windows. The pews, pulpit, and everything else");
    text.emplace_back("are covered in a fine mist. There is a very deep stone cistern near the");
    text.emplace_back("entrance. It is full to the brim with blessed water.\n");

    text.emplace_back("There is more than enough water here to fill your tiny flask.");

    text.emplace_back("You step into the empty chapel...");

    TextOutput::writeText(text);
    LocationEvents::changeValueFilledFlask();
}

std::string ExamineChapel::getDescription() const {
    return "Examine chapel";
}
