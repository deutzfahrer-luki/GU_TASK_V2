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

class RelativeStateManager {
public:
    // Zugriff auf die Singleton-Instanz
    static RelativeStateManager& getInstance() {
        static RelativeStateManager instance;
        return instance;
    }

    std::string relativeStateToString(RelativeState state) const {
        switch (state) {
        case RelativeState::Started: return "Started";
        case RelativeState::Working: return "Working";
        case RelativeState::Staying: return "Staying";
        case RelativeState::Finished: return "Finished";
        default: return "Unknown";
        }
    }

    RelativeState relativeStateFromString(const std::string& state) const {
        if (state == "Started") return RelativeState::Started;
        if (state == "Working") return RelativeState::Working;
        if (state == "Staying") return RelativeState::Staying;
        if (state == "Finished") return RelativeState::Finished;

        throw std::invalid_argument("Unrecognized RelativeState string: " + state);
    }

private:
    RelativeStateManager() = default;

    RelativeStateManager(const RelativeStateManager&) = delete;
    RelativeStateManager& operator=(const RelativeStateManager&) = delete;
};

#endif // RELATIVESTATE_H
