#include "State.h"

#include "Param.h"

namespace sim {

State* S() {
    return State::getInstance();
}

// Definition of the variable for linking
State* State::INSTANCE = NULL;
State* State::getInstance() {
    if (NULL == INSTANCE) {
        INSTANCE = new State();
    }
    return INSTANCE;
}

State::State() {
    m_interfaceType = UNDECLARED;
    m_mazeVisible = P()->defaultMazeVisible();
    m_mouseVisible = P()->defaultMouseVisible();
    m_mousePathVisible = P()->defaultMousePathVisible();
    m_paused = false;
    m_resetRequested = false;
    m_undoRequested = false;
}

InterfaceType State::interfaceType() {
    return m_interfaceType;
}

bool State::mazeVisible() {
    return m_mazeVisible;
}

bool State::mouseVisible() {
    return m_mouseVisible;
}

bool State::mousePathVisible() {
    return m_mousePathVisible;
}

bool State::paused() {
    return m_paused;
}

bool State::resetRequested() {
    return m_resetRequested;
}

bool State::undoRequested() {
    return m_undoRequested;
}

void State::setInterfaceType(InterfaceType interfaceType) {
    m_interfaceType = interfaceType;
}

void State::setMazeVisible(bool mazeVisible) {
    m_mazeVisible = mazeVisible;
}

void State::setMouseVisible(bool mouseVisible) {
    m_mouseVisible = mouseVisible;
}

void State::setMousePathVisible(bool mousePathVisible) {
    m_mousePathVisible = mousePathVisible;
}

void State::setPaused(bool paused) {
    m_paused = paused;
}

void State::setResetRequested(bool resetRequested) {
    m_resetRequested = resetRequested;
}

void State::setUndoRequested(bool undoRequested) {
    m_undoRequested = undoRequested;
}

} // namespace sim
