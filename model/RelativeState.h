#ifndef RELATIVESTATE_H
#define RELATIVESTATE_H

#include <string>
#include <stdexcept>

enum class RelativeState {
    Started,
    Finished
};

inline std::string relativeStateToString(RelativeState state) {
    switch (state) {
    case RelativeState::Started: return "Started";
    case RelativeState::Finished: return "Finished";
    default: return "Unknown";
    }
}

inline RelativeState relativeStateFromString(const std::string& state) {
    if (state == "Started") return RelativeState::Started;
    if (state == "Finished") return RelativeState::Finished;

    throw std::invalid_argument("Unrecognized RelativeState string: " + state);
}


#endif // RELATIVESTATE_H
