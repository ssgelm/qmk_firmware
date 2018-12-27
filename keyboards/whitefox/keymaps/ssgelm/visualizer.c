/* Copyright 2017 Fred Sundvik
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEYBOARDS_WHITEFOX_SIMPLE_VISUALIZER_H_
#define KEYBOARDS_WHITEFOX_SIMPLE_VISUALIZER_H_

#include "visualizer.h"
#include "visualizer_keyframes.h"
#include "led.h"
#include "default_animations.h"



void initialize_user_visualizer(visualizer_state_t* state) {
    start_keyframe_animation(&default_startup_animation);
}


void update_user_visualizer_state(visualizer_state_t* state, visualizer_keyboard_status_t* prev_status) {
}


void user_visualizer_suspend(visualizer_state_t* state) {
    start_keyframe_animation(&default_suspend_animation);
}

void user_visualizer_resume(visualizer_state_t* state) {
    start_keyframe_animation(&default_startup_animation);
}

#endif /* KEYBOARDS_WHITEFOX_SIMPLE_VISUALIZER_H_ */
