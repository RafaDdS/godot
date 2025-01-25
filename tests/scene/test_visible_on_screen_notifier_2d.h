/**************************************************************************/
/*  test_visible_on_screen_notifier_2d.h                                  */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_VISIBLE_ON_SCREEN_NOTIFIER_2D_H
#define TEST_VISIBLE_ON_SCREEN_NOTIFIER_2D_H

#include "scene/2d/visible_on_screen_notifier_2d.h"
#include "tests/test_macros.h"

namespace TestVisibleOnScreenNotifier2D {

	TEST_CASE("[SceneTree][VisibleOnScreenNotifier2D] Getters and Setters") {
		VisibleOnScreenNotifier2D *test_notifier = memnew(VisibleOnScreenNotifier2D);
		VisibleOnScreenEnabler2D *test_enabler = memnew(VisibleOnScreenEnabler2D);

		SUBCASE("Rect") {
			test_notifier->set_rect(Rect2(5, 10, 15, 20));
			CHECK(test_notifier->get_rect() == Rect2(5, 10, 15, 20));
			test_notifier->set_rect(Rect2(0, 1, 2, 3));
			CHECK(test_notifier->get_rect() == Rect2(0, 1, 2, 3));
		}

		SUBCASE("EnableMode") {
			test_enabler->set_enable_mode(VisibleOnScreenEnabler2D::EnableMode::ENABLE_MODE_ALWAYS);
			CHECK(test_enabler->get_enable_mode() == VisibleOnScreenEnabler2D::EnableMode::ENABLE_MODE_ALWAYS);
			test_enabler->set_enable_mode(VisibleOnScreenEnabler2D::EnableMode::ENABLE_MODE_WHEN_PAUSED);
			CHECK(test_enabler->get_enable_mode() == VisibleOnScreenEnabler2D::EnableMode::ENABLE_MODE_WHEN_PAUSED);
		}

		memdelete(test_notifier);
		memdelete(test_enabler);
	}

} // namespace TestVisibleOnScreenNotifier2D

#endif // TEST_VISIBLE_ON_SCREEN_NOTIFIER_2D_H
