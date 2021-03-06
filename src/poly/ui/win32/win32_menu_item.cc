/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2014 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "poly/ui/win32/win32_menu_item.h"

namespace poly {
namespace ui {
namespace win32 {

Win32MenuItem::Win32MenuItem(Type type)
    : MenuItem(type), handle_(CreateMenu()) {}

Win32MenuItem::~Win32MenuItem() {
  if (handle_) {
    DestroyMenu(handle_);
  }
}

void Win32MenuItem::OnChildAdded(MenuItem* generic_child_item) {
  auto child_item = static_cast<Win32MenuItem*>(generic_child_item);
  //
}

void Win32MenuItem::OnChildRemoved(MenuItem* generic_child_item) {
  auto child_item = static_cast<Win32MenuItem*>(generic_child_item);
  //
}

}  // namespace win32
}  // namespace ui
}  // namespace poly
