#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#define WINDOW_TITLE "Game"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400
#define WINDOW_FPS 60

#define FONT_FILE "font/arial/arial.ttf"

#define GAME_MAX_TIME 10  // время до остановки (в секундах)

#define SLOT_MACHINE_X 50
#define SLOT_MACHINE_Y 50
#define SLOT_MACHINE_WIDTH 550
#define SLOT_MACHINE_HEIGHT 300

#define ROLL_SPEED 500.0f
#define ROLL_SPEED_MIN 70.0f
#define ROLL_SPEED_STEP 0.01f
#define ROLL_WIDTH 100
#define ROLL_HEIGHT 300
#define ROLL_SEGMENT_COUNT 4
#define ROLL_SEGMENT_VIEW 3
#define ROLL_SEGMENT_SIZE (ROLL_HEIGHT / ROLL_SEGMENT_VIEW)
#define ROLLS_COUNT 5
#define ROLL_SPEED_DECAY 0.95f
#define ROLL_GAP 10
#define ROLL_PADDING 5

#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 50

#define START_BUTTON_X 650
#define START_BUTTON_Y 50
#define STOP_BUTTON_X 650
#define STOP_BUTTON_Y 300

#define SCORE_X 650
#define SCORE_Y 170

#define SHADOW_WIDTH SLOT_MACHINE_WIDTH
#define SHADOW_HEIGHT ROLL_SEGMENT_SIZE + 10
#define SHADOW_TOP_X SLOT_MACHINE_X
#define SHADOW_TOP_Y (SLOT_MACHINE_Y - ROLL_SEGMENT_SIZE - 10)
#define SHADOW_BOTTOM_X SLOT_MACHINE_X
#define SHADOW_BOTTOM_Y (SLOT_MACHINE_Y + SLOT_MACHINE_HEIGHT)

#endif /* CONFIG_HPP_ */