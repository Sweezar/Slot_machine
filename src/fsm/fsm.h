#ifndef _FSM_H_
#define _FSM_H_

#include <memory>

#include "../input.h"
#include "../slotMachine.h"

class FSM;

/**
 * @brief Интерфейс циклического состояния
 */
class State {
 public:
  virtual ~State() = default;
  virtual void handleInput(FSM& fsm, SlotMachine& slotMachine, Input input) = 0;
};  // class State

/**
 * @brief Состояний кручения барабанов слот машины
 */
class RotatingState : public State {
 public:
  void handleInput(FSM& fsm, SlotMachine& slotMachine, Input input);
};  // class RotatingState

/**
 * @brief Состояний остановки барабанов слот машины
 * (когда нажата кнопка стоп, либо вышел таймер, до момента полной остановки
 * барабанов)
 */
class StopState : public State {
 public:
  void handleInput(FSM& fsm, SlotMachine& slotMachine, Input input);
};  // class StopState

/**
 * @brief Состояние ожидания
 */
class WaitingState : public State {
 public:
  void handleInput(FSM& fsm, SlotMachine& slotMachine, Input input);
};  // class WaitingState

/**
 * @brief Конечный автомат, хранит в себе текущее состояние
 */
class FSM {
 public:
  FSM() : currentState_(std::make_unique<WaitingState>()) {}

  void setState(std::unique_ptr<State> newState);

  void handleInput(SlotMachine& slotMachine, Input input, float dt);

 private:
  std::unique_ptr<State> currentState_;
};  // class FSM

#endif  // _FSM_H_