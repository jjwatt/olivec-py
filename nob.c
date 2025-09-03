/* -*- mode: c; c-basic-offset: 4 -*- */
#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX

#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER "src/"
#define TESTS_FOLDER "tests/"

bool build_olivec_lib(Cmd *cmd) {
  const char *bin_path = BUILD_FOLDER"olivec.o";
  const char *src_path = SRC_FOLDER"olivec.c";
  const char *lib_path = BUILD_FOLDER"libolivec.so";

  cmd_append(cmd,
	     "cc",
	     "-g",
	     "-fPIC",
	     "-c",
	     src_path,
	     "-o",
	     bin_path);
  if (!cmd_run_sync_and_reset(cmd)) return false;
  nob_cmd_append(cmd,
		 "cc",
		 "-shared",
		 "-o",
		 lib_path,
		 bin_path);
  if (!cmd_run_sync_and_reset(cmd)) return false;
		 
  return true;
}

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);

  Cmd cmd = {0};

  const char *program_name = nob_shift(argv, argc);

  if (!mkdir_if_not_exists(BUILD_FOLDER)) return 1;

  if (!build_olivec_lib(&cmd)) return 1;
}
