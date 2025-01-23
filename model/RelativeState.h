#ifndef RELATIVESTATE_H
#define RELATIVESTATE_H

#include <string>
#include <stdexcept>

enum class RelativeState {
    Started,
    Working,
    Staying,
    Finished
};

// Konvertiert einen RelativeState in einen String
inline std::string relativeStateToString(RelativeState state) {
    switch (state) {
    case RelativeState::Started: return "Started";
    case RelativeState::Working: return "Working";
    case RelativeState::Staying: return "Staying";
    case RelativeState::Finished: return "Finished";
    default: return "Unknown"; // Für unvorhergesehene Fälle
    }
}

// Konvertiert einen String in einen RelativeState
inline RelativeState relativeStateFromString(const std::string& state) {
    if (state == "Started") return RelativeState::Started;
    if (state == "Working") return RelativeState::Working;
    if (state == "Staying") return RelativeState::Staying;
    if (state == "Finished") return RelativeState::Finished;

    // Ausnahme für unbekannte Strings
    throw std::invalid_argument("Unrecognized RelativeState string: " + state);
}

//inline RelativeState relativeStateIndex(const std::)

#endif // RELATIVESTATE_H
