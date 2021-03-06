/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/kernel/xam_module.h"

#include "poly/math.h"
#include "xenia/export_resolver.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/xam_private.h"

namespace xe {
namespace kernel {

XamModule::XamModule(Emulator* emulator, KernelState* kernel_state)
    : XKernelModule(kernel_state, "xe:\\xam.xex") {
  RegisterExportTable(export_resolver_);

  // Register all exported functions.
  xam::RegisterContentExports(export_resolver_, kernel_state_);
  xam::RegisterInfoExports(export_resolver_, kernel_state_);
  xam::RegisterInputExports(export_resolver_, kernel_state_);
  xam::RegisterMsgExports(export_resolver_, kernel_state_);
  xam::RegisterNetExports(export_resolver_, kernel_state_);
  xam::RegisterNotifyExports(export_resolver_, kernel_state_);
  xam::RegisterUIExports(export_resolver_, kernel_state_);
  xam::RegisterUserExports(export_resolver_, kernel_state_);
  xam::RegisterVideoExports(export_resolver_, kernel_state_);
  xam::RegisterVoiceExports(export_resolver_, kernel_state_);
}

void XamModule::RegisterExportTable(ExportResolver* export_resolver) {
  assert_not_null(export_resolver);

  if (!export_resolver) {
    return;
  }

  // Build the export table used for resolution.
#include "xenia/kernel/util/export_table_pre.inc"
  static KernelExport xam_export_table[] = {
#include "xenia/kernel/xam_table.inc"
  };
#include "xenia/kernel/util/export_table_post.inc"
  export_resolver->RegisterTable("xam.xex", xam_export_table,
    poly::countof(xam_export_table));
}

XamModule::~XamModule() {}

}  // namespace kernel
}  // namespace xe
