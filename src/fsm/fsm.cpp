#include "fsm.h"

void WaitingState::handleInput(FSM &fsm, SlotMachine &slotMachine,
                               Input input) {
  if (input == Input::START_INPUT) {
    slotMachine.start();

    fsm.setState(std::make_unique<RotatingState>());
  }
}

void RotatingState::handleInput(FSM &fsm, SlotMachine &slotMachine,
                                Input input) {
  if (input == Input::STOP_INPUT) {
    slotMachine.stop();

    fsm.setState(std::make_unique<StopState>());
  }
}

void StopState::handleInput(FSM &fsm, SlotMachine &slotMachine,
                            [[maybe_unused]] Input input) {
  if (slotMachine.isStopped()) {
    fsm.setState(std::make_unique<WaitingState>());
  } else {
    slotMachine.stop();
  }
}

void FSM::setState(std::unique_ptr<State> newState) {
  currentState_ = std::move(newState);
}

void FSM::handleInput(SlotMachine &slotMachine, Input input, float dt) {
  currentState_->handleInput(*this, slotMachine, input);
  slotMachine.update(dt);
}
