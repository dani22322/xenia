/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "kernel/fs/devices/local_directory_device.h"


using namespace xe;
using namespace xe::kernel;
using namespace xe::kernel::fs;


LocalDirectoryDevice::LocalDirectoryDevice(xe_pal_ref pal,
                                           const xechar_t* local_path) :
    Device(pal) {
  local_path_ = xestrdup(local_path);
}

LocalDirectoryDevice::~LocalDirectoryDevice() {
  xe_free(local_path_);
}

Entry* LocalDirectoryDevice::ResolvePath(const char* path) {
  return NULL;
}