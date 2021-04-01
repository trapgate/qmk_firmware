/* Copyright 2020 Geoff Hickey <trapgate@gmail.com>
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


#pragma once

//#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 200
//#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// Experiment:

// Rolling is: ctrl down, x down, ctrl up, x up.
// Reverse is: ctrl down, x down, x up, ctrl up.


// TAPPING_TERM to 3000

// !PERMISSIVE_HOLD && !IGNORE_MOD_TAP_INTERRUPT
// Rolling: ctrl-x (on release of x)
// Reverse: ctrl-x (on release of x)

// !PERMISSIVE_HOLD && IGNORE_MOD_TAP_INTERRUPT
// Rolling: zx
// Reverse: ctrl-x (on release of x)

// PERMISSIVE_HOLD && !IGNORE_MOD_TAP_INTERRUPT
// Rolling: ctrl-x
// Reverse: ctrl-x (on release of x)

// PERMISSIVE_HOLD && IGNORE_MOD_TAP_INTERRUPT
// Rolling: zx
// Reverse: ctrl-x (on release of x)

